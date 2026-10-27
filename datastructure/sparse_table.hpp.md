---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: datastructure/plus_minus_one_rmq.hpp
    title: Plus Minus One RMQ
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148(LCA)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/lca.test.cpp
    title: test/library-checker/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/staticrmq.test.cpp
    title: test/library-checker/staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/sparse_table.test.cpp
    title: test/unit/sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/sparse_table.hpp\"\n#include <algorithm>\n\
    #include <bit>\n#include <cassert>\n#include <vector>\n\n#line 2 \"algebra/concept.hpp\"\
    \n#include <concepts>\ntemplate <class M>\nconcept semigroup = requires(typename\
    \ M::S a, typename M::S b) {\n    { M::op(a, b) } -> std::same_as<typename M::S>;\n\
    };\ntemplate <class M>\nconcept monoid = semigroup<M> && requires {\n    { M::e()\
    \ } -> std::same_as<typename M::S>;\n};\ntemplate <class G>\nconcept group = monoid<G>\
    \ && requires(typename G::S a) {\n    { G::inv(a) } -> std::same_as<typename G::S>;\n\
    };\ntemplate <class A>\nconcept action = requires(typename A::F f, typename A::F\
    \ g) {\n    { A::composition(f, g) } -> std::same_as<typename A::F>;\n    { A::id()\
    \ } -> std::same_as<typename A::F>;\n    { A::composition_commutative } -> std::convertible_to<bool>;\n\
    };\ntemplate <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
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
    \ t;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <bit>\n#include <cassert>\n\
    #include <vector>\n\n#include \"algebra/concept.hpp\"\ntemplate <semigroup M>\
    \ struct sparse_table {\n    using S = typename M::S;\n    sparse_table() : _n(0)\
    \ {\n    }\n    explicit sparse_table(const std::vector<S>& a) : _n(int(a.size()))\
    \ {\n        int log = std::max(1, std::bit_width((unsigned)_n));\n        t.resize(log);\n\
    \        t[0] = a;\n        for (int k = 1; k < log; k++) {\n            t[k].resize(_n\
    \ - (1 << k) + 1);\n            for (int i = 0; i + (1 << k) <= _n; i++) {\n \
    \               t[k][i] = M::op(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);\n\
    \            }\n        }\n    }\n    S prod(int l, int r) const {\n        assert(0\
    \ <= l && l < r && r <= _n);\n        int k = std::bit_width((unsigned)(r - l))\
    \ - 1;\n        return M::op(t[k][l], t[k][r - (1 << k)]);\n    }\n\nprivate:\n\
    \    int _n;\n    std::vector<std::vector<S>> t;\n};\n"
  dependsOn:
  - algebra/concept.hpp
  isVerificationFile: false
  path: datastructure/sparse_table.hpp
  requiredBy:
  - graph/lowest_common_ancestor.hpp
  - datastructure/plus_minus_one_rmq.hpp
  timestamp: '2026-10-26 01:30:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/sparse_table.test.cpp
  - test/library-checker/lca.test.cpp
  - test/library-checker/staticrmq.test.cpp
documentation_of: datastructure/sparse_table.hpp
layout: document
title: Sparse Table
---

### 概要
- 静的な配列の区間積を求める。

### 使い方
- `sparse_table<M>(a)`: 配列 `a` で構築する。`M` は `S` と `op` を static メンバとして持つ構造体。`e` は不要。
- `prod(l, r)`: `op(a[l], ..., a[r - 1])` を返す。

### 制約
- `op` は結合的かつ冪等
- $0 \le l < r \le n$

### 計算量
- 構築: $\mathcal{O}(N \log N)$
- `prod`: $\mathcal{O}(1)$
