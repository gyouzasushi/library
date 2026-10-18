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
  bundledCode: "#line 2 \"monoid/gcd.hpp\"\n#include <numeric>\ntemplate <class T>\n\
    struct monoid_gcd {\n    using S = T;\n    static S op(S a, S b) {\n        return\
    \ std::gcd(a, b);\n    }\n    static S e() {\n        return T(0);\n    }\n  \
    \  static constexpr bool commutative = true;\n};\n"
  code: "#pragma once\n#include <numeric>\ntemplate <class T>\nstruct monoid_gcd {\n\
    \    using S = T;\n    static S op(S a, S b) {\n        return std::gcd(a, b);\n\
    \    }\n    static S e() {\n        return T(0);\n    }\n    static constexpr\
    \ bool commutative = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: monoid/gcd.hpp
  requiredBy: []
  timestamp: '2026-10-19 02:48:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/monoid.test.cpp
documentation_of: monoid/gcd.hpp
layout: document
title: 'Monoid: GCD'
---

### 概要
- 最大公約数モノイド。

### 使い方
- `S = T`, `op(a, b) = gcd(a, b)`, `e() = 0`
- `commutative = true`
