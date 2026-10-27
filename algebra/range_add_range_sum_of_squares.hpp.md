---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/monoid.test.cpp
    title: test/unit/monoid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/range_add_range_sum_of_squares.hpp\"\ntemplate <class\
    \ T>\nstruct range_add_range_sum_of_squares {\n    struct S {\n        T sum,\
    \ sum_of_squares;\n        int len;\n    };\n    using F = T;\n    static S op(S\
    \ a, S b) {\n        return {a.sum + b.sum, a.sum_of_squares + b.sum_of_squares,\
    \ a.len + b.len};\n    }\n    static S e() {\n        return {T(0), T(0), 0};\n\
    \    }\n    static S mapping(F f, S x) {\n        return {x.sum + f * x.len, x.sum_of_squares\
    \ + f * x.sum * 2 + f * f * x.len, x.len};\n    }\n    static F composition(F\
    \ f, F g) {\n        return f + g;\n    }\n    static F id() {\n        return\
    \ T(0);\n    }\n    static constexpr bool composition_commutative = true;\n  \
    \  static S from(T v) {\n        return {v, v * v, 1};\n    }\n};\n"
  code: "#pragma once\ntemplate <class T>\nstruct range_add_range_sum_of_squares {\n\
    \    struct S {\n        T sum, sum_of_squares;\n        int len;\n    };\n  \
    \  using F = T;\n    static S op(S a, S b) {\n        return {a.sum + b.sum, a.sum_of_squares\
    \ + b.sum_of_squares, a.len + b.len};\n    }\n    static S e() {\n        return\
    \ {T(0), T(0), 0};\n    }\n    static S mapping(F f, S x) {\n        return {x.sum\
    \ + f * x.len, x.sum_of_squares + f * x.sum * 2 + f * f * x.len, x.len};\n   \
    \ }\n    static F composition(F f, F g) {\n        return f + g;\n    }\n    static\
    \ F id() {\n        return T(0);\n    }\n    static constexpr bool composition_commutative\
    \ = true;\n    static S from(T v) {\n        return {v, v * v, 1};\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/range_add_range_sum_of_squares.hpp
  requiredBy: []
  timestamp: '2026-10-27 20:36:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/monoid.test.cpp
documentation_of: algebra/range_add_range_sum_of_squares.hpp
layout: document
title: 'Acted Monoid: Range Add Range Sum of Squares'
---

### 概要
- 区間加算・区間の和と二乗和。`lazy_segtree<range_add_range_sum_of_squares<T>>` のように使う。

### 使い方
- `S = {T sum; T sum_of_squares; int len}`, `F = T`
- `from(v)`: 値 `v` 1 個分の要素 `{v, v * v, 1}` を返す。初期化や一点更新ではこれで `S` を作る。
- `prod(l, r).sum` が区間和、`prod(l, r).sum_of_squares` が区間の二乗和。
