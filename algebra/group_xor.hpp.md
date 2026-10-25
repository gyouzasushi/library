---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algebra/monoid_xor.hpp
    title: 'Monoid: XOR'
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/unit/weighted_dsu.test.cpp
    title: test/unit/weighted_dsu.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_xor.hpp\"\ntemplate <class T>\nstruct monoid_xor\
    \ {\n    using S = T;\n    static S op(S a, S b) {\n        return a ^ b;\n  \
    \  }\n    static S e() {\n        return T(0);\n    }\n};\n#line 3 \"algebra/group_xor.hpp\"\
    \ntemplate <class T>\nstruct group_xor : monoid_xor<T> {\n    static T inv(T a)\
    \ {\n        return a;\n    }\n};\n"
  code: "#pragma once\n#include \"algebra/monoid_xor.hpp\"\ntemplate <class T>\nstruct\
    \ group_xor : monoid_xor<T> {\n    static T inv(T a) {\n        return a;\n  \
    \  }\n};\n"
  dependsOn:
  - algebra/monoid_xor.hpp
  isVerificationFile: false
  path: algebra/group_xor.hpp
  requiredBy: []
  timestamp: '2026-10-26 01:30:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unit/weighted_dsu.test.cpp
documentation_of: algebra/group_xor.hpp
layout: document
title: 'Group: XOR'
---
