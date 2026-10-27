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
  bundledCode: "#line 2 \"algebra/range_add_range_max.hpp\"\n#include <limits>\ntemplate\
    \ <class T>\nstruct range_add_range_max {\n    using S = T;\n    using F = T;\n\
    \    static S op(S a, S b) {\n        return a < b ? b : a;\n    }\n    static\
    \ S e() {\n        return std::numeric_limits<T>::lowest();\n    }\n    static\
    \ S mapping(F f, S x) {\n        return x == e() ? x : x + f;\n    }\n    static\
    \ F composition(F f, F g) {\n        return f + g;\n    }\n    static F id() {\n\
    \        return T(0);\n    }\n    static constexpr bool composition_commutative\
    \ = true;\n};\n"
  code: "#pragma once\n#include <limits>\ntemplate <class T>\nstruct range_add_range_max\
    \ {\n    using S = T;\n    using F = T;\n    static S op(S a, S b) {\n       \
    \ return a < b ? b : a;\n    }\n    static S e() {\n        return std::numeric_limits<T>::lowest();\n\
    \    }\n    static S mapping(F f, S x) {\n        return x == e() ? x : x + f;\n\
    \    }\n    static F composition(F f, F g) {\n        return f + g;\n    }\n \
    \   static F id() {\n        return T(0);\n    }\n    static constexpr bool composition_commutative\
    \ = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/range_add_range_max.hpp
  requiredBy: []
  timestamp: '2026-10-27 20:36:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/monoid.test.cpp
documentation_of: algebra/range_add_range_max.hpp
layout: document
title: 'Acted Monoid: Range Add Range Max'
---

### 概要
- 区間加算・区間最大値。`lazy_segtree<range_add_range_max<T>>` のように使う。

### 使い方
- `S = T`, `F = T`
- `e()` は `std::numeric_limits<T>::lowest()`。
