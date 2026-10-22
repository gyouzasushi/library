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
  bundledCode: "#line 2 \"monoid/argmax.hpp\"\n#include <limits>\ntemplate <class\
    \ T>\nstruct monoid_argmax {\n    struct S {\n        T val;\n        int id;\n\
    \    };\n    static S op(S a, S b) {\n        if (a.val != b.val) return a.val\
    \ > b.val ? a : b;\n        return a.id < b.id ? a : b;\n    }\n    static S e()\
    \ {\n        return {std::numeric_limits<T>::lowest(), -1};\n    }\n    static\
    \ constexpr bool commutative = true;\n};\n"
  code: "#pragma once\n#include <limits>\ntemplate <class T>\nstruct monoid_argmax\
    \ {\n    struct S {\n        T val;\n        int id;\n    };\n    static S op(S\
    \ a, S b) {\n        if (a.val != b.val) return a.val > b.val ? a : b;\n     \
    \   return a.id < b.id ? a : b;\n    }\n    static S e() {\n        return {std::numeric_limits<T>::lowest(),\
    \ -1};\n    }\n    static constexpr bool commutative = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: monoid/argmax.hpp
  requiredBy: []
  timestamp: '2026-10-22 18:09:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/monoid.test.cpp
documentation_of: monoid/argmax.hpp
layout: document
title: 'Monoid: Argmax'
---
