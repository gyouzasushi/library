---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/unit/monoid.test.cpp
    title: test/unit/monoid.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_argmax.hpp\"\n#include <limits>\ntemplate\
    \ <class T>\nstruct monoid_argmax {\n    struct S {\n        T val;\n        int\
    \ id;\n    };\n    static S op(S a, S b) {\n        if (a.val != b.val) return\
    \ a.val > b.val ? a : b;\n        return a.id < b.id ? a : b;\n    }\n    static\
    \ S e() {\n        return {std::numeric_limits<T>::lowest(), -1};\n    }\n};\n"
  code: "#pragma once\n#include <limits>\ntemplate <class T>\nstruct monoid_argmax\
    \ {\n    struct S {\n        T val;\n        int id;\n    };\n    static S op(S\
    \ a, S b) {\n        if (a.val != b.val) return a.val > b.val ? a : b;\n     \
    \   return a.id < b.id ? a : b;\n    }\n    static S e() {\n        return {std::numeric_limits<T>::lowest(),\
    \ -1};\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_argmax.hpp
  requiredBy: []
  timestamp: '2026-10-23 22:06:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unit/monoid.test.cpp
documentation_of: algebra/monoid_argmax.hpp
layout: document
title: 'Monoid: Argmax'
---
