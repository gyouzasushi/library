---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/group_xor.hpp
    title: 'Group: XOR'
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/monoid.test.cpp
    title: test/unit/monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/weighted_dsu.test.cpp
    title: test/unit/weighted_dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_xor.hpp\"\ntemplate <class T>\nstruct monoid_xor\
    \ {\n    using S = T;\n    static S op(S a, S b) {\n        return a ^ b;\n  \
    \  }\n    static S e() {\n        return T(0);\n    }\n};\n"
  code: "#pragma once\ntemplate <class T>\nstruct monoid_xor {\n    using S = T;\n\
    \    static S op(S a, S b) {\n        return a ^ b;\n    }\n    static S e() {\n\
    \        return T(0);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_xor.hpp
  requiredBy:
  - algebra/group_xor.hpp
  timestamp: '2026-10-23 22:06:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/weighted_dsu.test.cpp
  - test/unit/monoid.test.cpp
documentation_of: algebra/monoid_xor.hpp
layout: document
title: 'Monoid: XOR'
---
