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
  bundledCode: "#line 2 \"algebra/monoid_add.hpp\"\ntemplate <class T>\nstruct monoid_add\
    \ {\n    using S = T;\n    static S op(S a, S b) {\n        return a + b;\n  \
    \  }\n    static S e() {\n        return T(0);\n    }\n};\n"
  code: "#pragma once\ntemplate <class T>\nstruct monoid_add {\n    using S = T;\n\
    \    static S op(S a, S b) {\n        return a + b;\n    }\n    static S e() {\n\
    \        return T(0);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_add.hpp
  requiredBy: []
  timestamp: '2026-10-23 22:06:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/monoid.test.cpp
documentation_of: algebra/monoid_add.hpp
layout: document
title: 'Monoid: Add'
---
