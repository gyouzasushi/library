---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/staticrmq_sqrt_tree.test.cpp
    title: test/library-checker/staticrmq_sqrt_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/sqrt_tree.test.cpp
    title: test/unit/sqrt_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/sqrt_tree.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\n#line 2 \"algebra/concept.hpp\"\n#include <concepts>\n\
    template <class M>\nconcept semigroup = requires(typename M::S a, typename M::S\
    \ b) {\n    { M::op(a, b) } -> std::same_as<typename M::S>;\n};\ntemplate <class\
    \ M>\nconcept monoid = semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename\
    \ M::S>;\n};\ntemplate <class G>\nconcept group = monoid<G> && requires(typename\
    \ G::S a) {\n    { G::inv(a) } -> std::same_as<typename G::S>;\n};\ntemplate <class\
    \ A>\nconcept action = requires(typename A::F f, typename A::F g) {\n    { A::composition(f,\
    \ g) } -> std::same_as<typename A::F>;\n    { A::id() } -> std::same_as<typename\
    \ A::F>;\n    { A::composition_commutative } -> std::convertible_to<bool>;\n};\n\
    template <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
    \ A::S x, typename A::F f) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n};\ntemplate <class R>\nconcept semiring = requires(typename R::S a,\
    \ typename R::S b) {\n    { R::add(a, b) } -> std::same_as<typename R::S>;\n \
    \   { R::zero() } -> std::same_as<typename R::S>;\n    { R::mul(a, b) } -> std::same_as<typename\
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\n#line 7 \"datastructure/sqrt_tree.hpp\"\
    \ntemplate <semigroup M> struct sqrt_tree {\n    using S = typename M::S;\n  \
    \  sqrt_tree() {\n    }\n    explicit sqrt_tree(const std::vector<S>& a) : _n(int(a.size()))\
    \ {\n        if (_n == 0) return;\n        _lg = 0;\n        while ((1 << _lg)\
    \ < _n) _lg++;\n        v = a;\n\n        clz.assign(1 << _lg, 0);\n        for\
    \ (int i = 1; i < (1 << _lg); i++) {\n            clz[i] = clz[i >> 1] + 1;\n\
    \        }\n\n        on_layer.assign(_lg + 1, 0);\n        int tlg = _lg;\n \
    \       while (tlg > 1) {\n            on_layer[tlg] = int(layers.size());\n \
    \           layers.push_back(tlg);\n            tlg = (tlg + 1) >> 1;\n      \
    \  }\n        for (int i = _lg - 1; i >= 0; i--) {\n            on_layer[i] =\
    \ std::max(on_layer[i], on_layer[i + 1]);\n        }\n\n        if (layers.empty())\
    \ return;\n\n        int between_layers = std::max(0, int(layers.size()) - 1);\n\
    \        int b_sz_log = (_lg + 1) >> 1;\n        int b_sz = 1 << b_sz_log;\n \
    \       index_sz = (_n + b_sz - 1) >> b_sz_log;\n        v.resize(_n + index_sz);\n\
    \        pref.assign(layers.size(), std::vector<S>(_n + index_sz));\n        suf.assign(layers.size(),\
    \ std::vector<S>(_n + index_sz));\n        between.assign(between_layers, std::vector<S>((1\
    \ << _lg) + b_sz));\n        build(0, 0, _n, 0);\n    }\n\n    S prod(int l, int\
    \ r) const {\n        assert(0 <= l && l < r && r <= _n);\n        return query(l,\
    \ r - 1, 0, 0);\n    }\n\n  private:\n    int _n = 0, _lg = 0, index_sz = 0;\n\
    \    std::vector<S> v;\n    std::vector<int> clz, layers, on_layer;\n    std::vector<std::vector<S>>\
    \ pref, suf, between;\n\n    void build_block(int layer, int l, int r) {\n   \
    \     pref[layer][l] = v[l];\n        for (int i = l + 1; i < r; i++) {\n    \
    \        pref[layer][i] = M::op(pref[layer][i - 1], v[i]);\n        }\n      \
    \  suf[layer][r - 1] = v[r - 1];\n        for (int i = r - 2; i >= l; i--) {\n\
    \            suf[layer][i] = M::op(v[i], suf[layer][i + 1]);\n        }\n    }\n\
    \n    void build_between(int layer, int l_bound, int r_bound, int between_offs)\
    \ {\n        int b_sz_log = (layers[layer] + 1) >> 1;\n        int b_cnt_log =\
    \ layers[layer] >> 1;\n        int b_sz = 1 << b_sz_log;\n        int b_cnt =\
    \ (r_bound - l_bound + b_sz - 1) >> b_sz_log;\n        for (int i = 0; i < b_cnt;\
    \ i++) {\n            S ans = suf[layer][l_bound + (i << b_sz_log)];\n       \
    \     between[layer - 1][between_offs + l_bound + (i << b_cnt_log) + i] = ans;\n\
    \            for (int j = i + 1; j < b_cnt; j++) {\n                S add = suf[layer][l_bound\
    \ + (j << b_sz_log)];\n                ans = M::op(ans, add);\n              \
    \  between[layer - 1][between_offs + l_bound + (i << b_cnt_log) + j] = ans;\n\
    \            }\n        }\n    }\n\n    void build_between_zero() {\n        int\
    \ b_sz_log = (_lg + 1) >> 1;\n        for (int i = 0; i < index_sz; i++) {\n \
    \           v[_n + i] = suf[0][i << b_sz_log];\n        }\n        build(1, _n,\
    \ _n + index_sz, (1 << _lg) - _n);\n    }\n\n    void build(int layer, int l_bound,\
    \ int r_bound, int between_offs) {\n        if (layer >= int(layers.size())) return;\n\
    \        int b_sz = 1 << ((layers[layer] + 1) >> 1);\n        for (int l = l_bound;\
    \ l < r_bound; l += b_sz) {\n            int r = std::min(l + b_sz, r_bound);\n\
    \            build_block(layer, l, r);\n            build(layer + 1, l, r, between_offs);\n\
    \        }\n        if (layer == 0) {\n            build_between_zero();\n   \
    \     } else {\n            build_between(layer, l_bound, r_bound, between_offs);\n\
    \        }\n    }\n\n    S query(int l, int r, int between_offs, int base) const\
    \ {\n        if (l == r) return v[l];\n        if (l + 1 == r) return M::op(v[l],\
    \ v[r]);\n        int layer = on_layer[clz[(l - base) ^ (r - base)]];\n      \
    \  int b_sz_log = (layers[layer] + 1) >> 1;\n        int b_cnt_log = layers[layer]\
    \ >> 1;\n        int l_bound = (((l - base) >> layers[layer]) << layers[layer])\
    \ + base;\n        int l_block = ((l - l_bound) >> b_sz_log) + 1;\n        int\
    \ r_block = ((r - l_bound) >> b_sz_log) - 1;\n        S ans = suf[layer][l];\n\
    \        if (l_block <= r_block) {\n            S add = (layer == 0)\n       \
    \                 ? query(_n + l_block, _n + r_block, (1 << _lg) - _n, _n)\n \
    \                       : between[layer - 1][between_offs + l_bound + (l_block\
    \ << b_cnt_log) + r_block];\n            ans = M::op(ans, add);\n        }\n \
    \       ans = M::op(ans, pref[layer][r]);\n        return ans;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \n#include \"algebra/concept.hpp\"\ntemplate <semigroup M> struct sqrt_tree {\n\
    \    using S = typename M::S;\n    sqrt_tree() {\n    }\n    explicit sqrt_tree(const\
    \ std::vector<S>& a) : _n(int(a.size())) {\n        if (_n == 0) return;\n   \
    \     _lg = 0;\n        while ((1 << _lg) < _n) _lg++;\n        v = a;\n\n   \
    \     clz.assign(1 << _lg, 0);\n        for (int i = 1; i < (1 << _lg); i++) {\n\
    \            clz[i] = clz[i >> 1] + 1;\n        }\n\n        on_layer.assign(_lg\
    \ + 1, 0);\n        int tlg = _lg;\n        while (tlg > 1) {\n            on_layer[tlg]\
    \ = int(layers.size());\n            layers.push_back(tlg);\n            tlg =\
    \ (tlg + 1) >> 1;\n        }\n        for (int i = _lg - 1; i >= 0; i--) {\n \
    \           on_layer[i] = std::max(on_layer[i], on_layer[i + 1]);\n        }\n\
    \n        if (layers.empty()) return;\n\n        int between_layers = std::max(0,\
    \ int(layers.size()) - 1);\n        int b_sz_log = (_lg + 1) >> 1;\n        int\
    \ b_sz = 1 << b_sz_log;\n        index_sz = (_n + b_sz - 1) >> b_sz_log;\n   \
    \     v.resize(_n + index_sz);\n        pref.assign(layers.size(), std::vector<S>(_n\
    \ + index_sz));\n        suf.assign(layers.size(), std::vector<S>(_n + index_sz));\n\
    \        between.assign(between_layers, std::vector<S>((1 << _lg) + b_sz));\n\
    \        build(0, 0, _n, 0);\n    }\n\n    S prod(int l, int r) const {\n    \
    \    assert(0 <= l && l < r && r <= _n);\n        return query(l, r - 1, 0, 0);\n\
    \    }\n\n  private:\n    int _n = 0, _lg = 0, index_sz = 0;\n    std::vector<S>\
    \ v;\n    std::vector<int> clz, layers, on_layer;\n    std::vector<std::vector<S>>\
    \ pref, suf, between;\n\n    void build_block(int layer, int l, int r) {\n   \
    \     pref[layer][l] = v[l];\n        for (int i = l + 1; i < r; i++) {\n    \
    \        pref[layer][i] = M::op(pref[layer][i - 1], v[i]);\n        }\n      \
    \  suf[layer][r - 1] = v[r - 1];\n        for (int i = r - 2; i >= l; i--) {\n\
    \            suf[layer][i] = M::op(v[i], suf[layer][i + 1]);\n        }\n    }\n\
    \n    void build_between(int layer, int l_bound, int r_bound, int between_offs)\
    \ {\n        int b_sz_log = (layers[layer] + 1) >> 1;\n        int b_cnt_log =\
    \ layers[layer] >> 1;\n        int b_sz = 1 << b_sz_log;\n        int b_cnt =\
    \ (r_bound - l_bound + b_sz - 1) >> b_sz_log;\n        for (int i = 0; i < b_cnt;\
    \ i++) {\n            S ans = suf[layer][l_bound + (i << b_sz_log)];\n       \
    \     between[layer - 1][between_offs + l_bound + (i << b_cnt_log) + i] = ans;\n\
    \            for (int j = i + 1; j < b_cnt; j++) {\n                S add = suf[layer][l_bound\
    \ + (j << b_sz_log)];\n                ans = M::op(ans, add);\n              \
    \  between[layer - 1][between_offs + l_bound + (i << b_cnt_log) + j] = ans;\n\
    \            }\n        }\n    }\n\n    void build_between_zero() {\n        int\
    \ b_sz_log = (_lg + 1) >> 1;\n        for (int i = 0; i < index_sz; i++) {\n \
    \           v[_n + i] = suf[0][i << b_sz_log];\n        }\n        build(1, _n,\
    \ _n + index_sz, (1 << _lg) - _n);\n    }\n\n    void build(int layer, int l_bound,\
    \ int r_bound, int between_offs) {\n        if (layer >= int(layers.size())) return;\n\
    \        int b_sz = 1 << ((layers[layer] + 1) >> 1);\n        for (int l = l_bound;\
    \ l < r_bound; l += b_sz) {\n            int r = std::min(l + b_sz, r_bound);\n\
    \            build_block(layer, l, r);\n            build(layer + 1, l, r, between_offs);\n\
    \        }\n        if (layer == 0) {\n            build_between_zero();\n   \
    \     } else {\n            build_between(layer, l_bound, r_bound, between_offs);\n\
    \        }\n    }\n\n    S query(int l, int r, int between_offs, int base) const\
    \ {\n        if (l == r) return v[l];\n        if (l + 1 == r) return M::op(v[l],\
    \ v[r]);\n        int layer = on_layer[clz[(l - base) ^ (r - base)]];\n      \
    \  int b_sz_log = (layers[layer] + 1) >> 1;\n        int b_cnt_log = layers[layer]\
    \ >> 1;\n        int l_bound = (((l - base) >> layers[layer]) << layers[layer])\
    \ + base;\n        int l_block = ((l - l_bound) >> b_sz_log) + 1;\n        int\
    \ r_block = ((r - l_bound) >> b_sz_log) - 1;\n        S ans = suf[layer][l];\n\
    \        if (l_block <= r_block) {\n            S add = (layer == 0)\n       \
    \                 ? query(_n + l_block, _n + r_block, (1 << _lg) - _n, _n)\n \
    \                       : between[layer - 1][between_offs + l_bound + (l_block\
    \ << b_cnt_log) + r_block];\n            ans = M::op(ans, add);\n        }\n \
    \       ans = M::op(ans, pref[layer][r]);\n        return ans;\n    }\n};\n"
  dependsOn:
  - algebra/concept.hpp
  isVerificationFile: false
  path: datastructure/sqrt_tree.hpp
  requiredBy: []
  timestamp: '2026-10-26 23:44:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/sqrt_tree.test.cpp
  - test/library-checker/staticrmq_sqrt_tree.test.cpp
documentation_of: datastructure/sqrt_tree.hpp
layout: document
title: Sqrt Tree
---

### 概要
- 静的な配列の区間積を求める。

### 使い方
- `sqrt_tree<M>(a)`: 配列 `a` で構築する。`M` は `S` と `op` を static メンバとして持つ構造体。`e` は不要。
- `prod(l, r)`: `op(a[l], ..., a[r - 1])` を返す。

### 制約
- `op` は結合的
- $0 \le l < r \le n$

### 計算量
- 構築: $\mathcal{O}(N \log \log N)$
- `prod`: $\mathcal{O}(1)$
