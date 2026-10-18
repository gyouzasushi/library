---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/point_set_range_composite.test.cpp
    title: test/library-checker/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/monoid.test.cpp
    title: test/unit/monoid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"monoid/affine.hpp\"\ntemplate <class T>\nstruct monoid_affine\
    \ {\n    struct S {\n        T a, b;\n    };\n    static S op(S f, S g) {\n  \
    \      return {g.a * f.a, g.a * f.b + g.b};\n    }\n    static S e() {\n     \
    \   return {T(1), T(0)};\n    }\n    static T eval(S f, T x) {\n        return\
    \ f.a * x + f.b;\n    }\n    static constexpr bool commutative = false;\n};\n"
  code: "#pragma once\ntemplate <class T>\nstruct monoid_affine {\n    struct S {\n\
    \        T a, b;\n    };\n    static S op(S f, S g) {\n        return {g.a * f.a,\
    \ g.a * f.b + g.b};\n    }\n    static S e() {\n        return {T(1), T(0)};\n\
    \    }\n    static T eval(S f, T x) {\n        return f.a * x + f.b;\n    }\n\
    \    static constexpr bool commutative = false;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: monoid/affine.hpp
  requiredBy: []
  timestamp: '2026-10-19 02:48:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/monoid.test.cpp
  - test/library-checker/point_set_range_composite.test.cpp
documentation_of: monoid/affine.hpp
layout: document
title: 'Monoid: Affine'
---

### 概要
- 一次関数 $f(x) = ax + b$ の合成モノイド。`prod(l, r)` は $f_{r-1} \circ \cdots \circ f_l$、すなわち $f_l$ を最初に適用する合成になる。

### 使い方
- `S = {T a, b}`, `op(f, g) = g ∘ f`, `e() = {1, 0}`
- `eval(f, x)`: $f(x)$ を返す。
- `commutative = false`
