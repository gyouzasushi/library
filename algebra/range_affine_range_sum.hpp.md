---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_affine.hpp
    title: 'Monoid: Affine'
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/range_affine_range_sum.test.cpp
    title: test/library-checker/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/monoid.test.cpp
    title: test/unit/monoid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_affine.hpp\"\ntemplate <class T>\nstruct\
    \ monoid_affine {\n    struct S {\n        T a, b;\n    };\n    static S op(S\
    \ f, S g) {\n        return {g.a * f.a, g.a * f.b + g.b};\n    }\n    static S\
    \ e() {\n        return {T(1), T(0)};\n    }\n    static T eval(S f, T x) {\n\
    \        return f.a * x + f.b;\n    }\n};\n#line 3 \"algebra/range_affine_range_sum.hpp\"\
    \ntemplate <class T>\nstruct range_affine_range_sum {\n    struct S {\n      \
    \  T sum;\n        int len;\n    };\n    using F = typename monoid_affine<T>::S;\n\
    \    static S op(S a, S b) {\n        return {a.sum + b.sum, a.len + b.len};\n\
    \    }\n    static S e() {\n        return {T(0), 0};\n    }\n    static S mapping(F\
    \ f, S x) {\n        return {f.a * x.sum + f.b * T(x.len), x.len};\n    }\n  \
    \  static F composition(F f, F g) {\n        return monoid_affine<T>::op(g, f);\n\
    \    }\n    static F id() {\n        return monoid_affine<T>::e();\n    }\n  \
    \  static constexpr bool composition_commutative = false;\n    static S from(T\
    \ v) {\n        return {v, 1};\n    }\n};\n"
  code: "#pragma once\n#include \"algebra/monoid_affine.hpp\"\ntemplate <class T>\n\
    struct range_affine_range_sum {\n    struct S {\n        T sum;\n        int len;\n\
    \    };\n    using F = typename monoid_affine<T>::S;\n    static S op(S a, S b)\
    \ {\n        return {a.sum + b.sum, a.len + b.len};\n    }\n    static S e() {\n\
    \        return {T(0), 0};\n    }\n    static S mapping(F f, S x) {\n        return\
    \ {f.a * x.sum + f.b * T(x.len), x.len};\n    }\n    static F composition(F f,\
    \ F g) {\n        return monoid_affine<T>::op(g, f);\n    }\n    static F id()\
    \ {\n        return monoid_affine<T>::e();\n    }\n    static constexpr bool composition_commutative\
    \ = false;\n    static S from(T v) {\n        return {v, 1};\n    }\n};\n"
  dependsOn:
  - algebra/monoid_affine.hpp
  isVerificationFile: false
  path: algebra/range_affine_range_sum.hpp
  requiredBy: []
  timestamp: '2026-11-07 14:02:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/monoid.test.cpp
  - test/library-checker/range_affine_range_sum.test.cpp
documentation_of: algebra/range_affine_range_sum.hpp
layout: document
title: 'Acted Monoid: Range Affine Range Sum'
---

### 概要
- 区間アフィン変換・区間和。`lazy_segtree<range_affine_range_sum<T>>` のように使う。

### 使い方
- `S = {T sum; int len}`, `F = monoid_affine<T>::S`
- `from(v)`: 値 `v` 1 個分の要素 `{v, 1}` を返す。初期化や一点更新ではこれで `S` を作る。
- `apply(l, r, {a, b})` で `a[l], ..., a[r - 1]` の各要素 `x` を `a x + b` にする。
- `prod(l, r).sum` が区間和。
