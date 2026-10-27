---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_argmin.hpp
    title: 'Monoid: Argmin'
  - icon: ':heavy_check_mark:'
    path: datastructure/sparse_table.hpp
    title: Sparse Table
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148(LCA)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/lca.test.cpp
    title: test/library-checker/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/sparse_table.test.cpp
    title: test/unit/sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/plus_minus_one_rmq.hpp\"\n#include <algorithm>\n\
    #include <bit>\n#include <cassert>\n#include <vector>\n\n#line 6 \"datastructure/sparse_table.hpp\"\
    \n\n#line 2 \"algebra/concept.hpp\"\n#include <concepts>\ntemplate <class M>\n\
    concept semigroup = requires(typename M::S a, typename M::S b) {\n    { M::op(a,\
    \ b) } -> std::same_as<typename M::S>;\n};\ntemplate <class M>\nconcept monoid\
    \ = semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename M::S>;\n\
    };\ntemplate <class G>\nconcept group = monoid<G> && requires(typename G::S a)\
    \ {\n    { G::inv(a) } -> std::same_as<typename G::S>;\n};\ntemplate <class A>\n\
    concept action = requires(typename A::F f, typename A::F g) {\n    { A::composition(f,\
    \ g) } -> std::same_as<typename A::F>;\n    { A::id() } -> std::same_as<typename\
    \ A::F>;\n    { A::composition_commutative } -> std::convertible_to<bool>;\n};\n\
    template <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
    \ A::S x, typename A::F f) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n};\ntemplate <class R>\nconcept semiring = requires(typename R::S a,\
    \ typename R::S b) {\n    { R::add(a, b) } -> std::same_as<typename R::S>;\n \
    \   { R::zero() } -> std::same_as<typename R::S>;\n    { R::mul(a, b) } -> std::same_as<typename\
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\n#line 8 \"datastructure/sparse_table.hpp\"\
    \ntemplate <semigroup M> struct sparse_table {\n    using S = typename M::S;\n\
    \    sparse_table() : _n(0) {\n    }\n    explicit sparse_table(const std::vector<S>&\
    \ a) : _n(int(a.size())) {\n        int log = std::max(1, std::bit_width((unsigned)_n));\n\
    \        t.resize(log);\n        t[0] = a;\n        for (int k = 1; k < log; k++)\
    \ {\n            t[k].resize(_n - (1 << k) + 1);\n            for (int i = 0;\
    \ i + (1 << k) <= _n; i++) {\n                t[k][i] = M::op(t[k - 1][i], t[k\
    \ - 1][i + (1 << (k - 1))]);\n            }\n        }\n    }\n    S prod(int\
    \ l, int r) const {\n        assert(0 <= l && l < r && r <= _n);\n        int\
    \ k = std::bit_width((unsigned)(r - l)) - 1;\n        return M::op(t[k][l], t[k][r\
    \ - (1 << k)]);\n    }\n\nprivate:\n    int _n;\n    std::vector<std::vector<S>>\
    \ t;\n};\n#line 2 \"algebra/monoid_argmin.hpp\"\n#include <limits>\ntemplate <class\
    \ T>\nstruct monoid_argmin {\n    struct S {\n        T val;\n        int id;\n\
    \    };\n    static S op(S a, S b) {\n        if (a.val != b.val) return a.val\
    \ < b.val ? a : b;\n        return a.id < b.id ? a : b;\n    }\n    static S e()\
    \ {\n        return {std::numeric_limits<T>::max(), -1};\n    }\n};\n#line 9 \"\
    datastructure/plus_minus_one_rmq.hpp\"\nstruct plus_minus_one_rmq {\npublic:\n\
    \    plus_minus_one_rmq() : _n(0), s(1), B(0) {\n    }\n    explicit plus_minus_one_rmq(const\
    \ std::vector<int>& a) : _n(int(a.size())), v(a) {\n        s = std::max(1, (std::bit_width((unsigned)_n)\
    \ - 1) / 2);\n        B = (_n + s - 1) / s;\n        std::vector<monoid_argmin<int>::S>\
    \ blocks(B);\n        pattern.resize(B);\n        for (int i = 0; i < _n; i +=\
    \ s) {\n            int min_j = i;\n            int bit = 0;\n            int\
    \ end = std::min(_n, i + s);\n            for (int j = i; j < end; j++) {\n  \
    \              if (v[j] < v[min_j]) min_j = j;\n                if (j + 1 < end\
    \ && v[j] < v[j + 1]) bit |= 1 << (j - i);\n            }\n            blocks[i\
    \ / s] = {v[min_j], min_j};\n            pattern[i / s] = bit;\n        }\n  \
    \      table = sparse_table<monoid_argmin<int>>(blocks);\n        lookup.resize(1\
    \ << (s - 1));\n        for (int bit = 0; bit < (1 << (s - 1)); bit++) {\n   \
    \         lookup[bit].resize(s + 1);\n            for (int l = 0; l <= s; l++)\
    \ {\n                lookup[bit][l].assign(s + 1, INF);\n                int min_sum\
    \ = 0, min_i = l, sum = 0;\n                for (int r = l + 1; r <= s; r++) {\n\
    \                    lookup[bit][l][r] = min_i;\n                    sum += bit\
    \ >> (r - 1) & 1 ? 1 : -1;\n                    if (sum < min_sum) {\n       \
    \                 min_sum = sum;\n                        min_i = r;\n       \
    \             }\n                }\n            }\n        }\n    }\n    int prod(int\
    \ l, int r) const {\n        assert(0 <= l && l < r && r <= _n);\n        int\
    \ m1 = (l + s - 1) / s, m2 = r / s;\n        int l1 = s * m1, r1 = s * m2;\n \
    \       if (m2 < m1) return lookup[pattern[m2]][l - r1][r - r1] + r1;\n      \
    \  int ret = INF;\n        if (m1 > 0) ret = argmin(ret, lookup[pattern[m1 - 1]][s\
    \ - (l1 - l)][s] + l1 - s);\n        if (m1 < m2) ret = argmin(ret, table.prod(m1,\
    \ m2).id);\n        if (m2 < B) ret = argmin(ret, lookup[pattern[m2]][0][r - r1]\
    \ + r1);\n        return ret;\n    }\n\nprivate:\n    static constexpr int INF\
    \ = 1 << 30;\n    int _n, s, B;\n    std::vector<int> v, pattern;\n    sparse_table<monoid_argmin<int>>\
    \ table;\n    std::vector<std::vector<std::vector<int>>> lookup;\n    int argmin(int\
    \ i, int j) const {\n        if (i >= INF) return j;\n        if (j >= INF) return\
    \ i;\n        if (v[i] != v[j]) return v[i] < v[j] ? i : j;\n        return std::min(i,\
    \ j);\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <bit>\n#include <cassert>\n\
    #include <vector>\n\n#include \"datastructure/sparse_table.hpp\"\n#include \"\
    algebra/monoid_argmin.hpp\"\nstruct plus_minus_one_rmq {\npublic:\n    plus_minus_one_rmq()\
    \ : _n(0), s(1), B(0) {\n    }\n    explicit plus_minus_one_rmq(const std::vector<int>&\
    \ a) : _n(int(a.size())), v(a) {\n        s = std::max(1, (std::bit_width((unsigned)_n)\
    \ - 1) / 2);\n        B = (_n + s - 1) / s;\n        std::vector<monoid_argmin<int>::S>\
    \ blocks(B);\n        pattern.resize(B);\n        for (int i = 0; i < _n; i +=\
    \ s) {\n            int min_j = i;\n            int bit = 0;\n            int\
    \ end = std::min(_n, i + s);\n            for (int j = i; j < end; j++) {\n  \
    \              if (v[j] < v[min_j]) min_j = j;\n                if (j + 1 < end\
    \ && v[j] < v[j + 1]) bit |= 1 << (j - i);\n            }\n            blocks[i\
    \ / s] = {v[min_j], min_j};\n            pattern[i / s] = bit;\n        }\n  \
    \      table = sparse_table<monoid_argmin<int>>(blocks);\n        lookup.resize(1\
    \ << (s - 1));\n        for (int bit = 0; bit < (1 << (s - 1)); bit++) {\n   \
    \         lookup[bit].resize(s + 1);\n            for (int l = 0; l <= s; l++)\
    \ {\n                lookup[bit][l].assign(s + 1, INF);\n                int min_sum\
    \ = 0, min_i = l, sum = 0;\n                for (int r = l + 1; r <= s; r++) {\n\
    \                    lookup[bit][l][r] = min_i;\n                    sum += bit\
    \ >> (r - 1) & 1 ? 1 : -1;\n                    if (sum < min_sum) {\n       \
    \                 min_sum = sum;\n                        min_i = r;\n       \
    \             }\n                }\n            }\n        }\n    }\n    int prod(int\
    \ l, int r) const {\n        assert(0 <= l && l < r && r <= _n);\n        int\
    \ m1 = (l + s - 1) / s, m2 = r / s;\n        int l1 = s * m1, r1 = s * m2;\n \
    \       if (m2 < m1) return lookup[pattern[m2]][l - r1][r - r1] + r1;\n      \
    \  int ret = INF;\n        if (m1 > 0) ret = argmin(ret, lookup[pattern[m1 - 1]][s\
    \ - (l1 - l)][s] + l1 - s);\n        if (m1 < m2) ret = argmin(ret, table.prod(m1,\
    \ m2).id);\n        if (m2 < B) ret = argmin(ret, lookup[pattern[m2]][0][r - r1]\
    \ + r1);\n        return ret;\n    }\n\nprivate:\n    static constexpr int INF\
    \ = 1 << 30;\n    int _n, s, B;\n    std::vector<int> v, pattern;\n    sparse_table<monoid_argmin<int>>\
    \ table;\n    std::vector<std::vector<std::vector<int>>> lookup;\n    int argmin(int\
    \ i, int j) const {\n        if (i >= INF) return j;\n        if (j >= INF) return\
    \ i;\n        if (v[i] != v[j]) return v[i] < v[j] ? i : j;\n        return std::min(i,\
    \ j);\n    }\n};\n"
  dependsOn:
  - datastructure/sparse_table.hpp
  - algebra/concept.hpp
  - algebra/monoid_argmin.hpp
  isVerificationFile: false
  path: datastructure/plus_minus_one_rmq.hpp
  requiredBy:
  - graph/lowest_common_ancestor.hpp
  timestamp: '2026-10-26 01:30:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/sparse_table.test.cpp
  - test/library-checker/lca.test.cpp
documentation_of: datastructure/plus_minus_one_rmq.hpp
layout: document
title: Plus Minus One RMQ
---

### 概要
- 隣接要素の差が $\pm 1$ の配列の区間最小値の位置を求める。

### 使い方
- `plus_minus_one_rmq(a)`: 配列 `a` で構築する。
- `prod(l, r)`: `a[l], ..., a[r - 1]` の最小値の添字を返す。複数あれば最小の添字。

### 制約
- $\lvert a_i - a_{i+1} \rvert = 1$
- $0 \le l < r \le n$

### 計算量
- 構築: $\mathcal{O}(N)$
- `prod`: $\mathcal{O}(1)$
