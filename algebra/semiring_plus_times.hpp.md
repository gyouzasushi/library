---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: Matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/matrix_product.test.cpp
    title: test/library-checker/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/pow_of_matrix.test.cpp
    title: test/library-checker/pow_of_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/matrix.test.cpp
    title: test/unit/matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/semiring_plus_times.hpp\"\ntemplate <class T>\n\
    struct semiring_plus_times {\n    using S = T;\n    static S add(S a, S b) {\n\
    \        return a + b;\n    }\n    static S zero() {\n        return T(0);\n \
    \   }\n    static S mul(S a, S b) {\n        return a * b;\n    }\n    static\
    \ S one() {\n        return T(1);\n    }\n};\n"
  code: "#pragma once\ntemplate <class T>\nstruct semiring_plus_times {\n    using\
    \ S = T;\n    static S add(S a, S b) {\n        return a + b;\n    }\n    static\
    \ S zero() {\n        return T(0);\n    }\n    static S mul(S a, S b) {\n    \
    \    return a * b;\n    }\n    static S one() {\n        return T(1);\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/semiring_plus_times.hpp
  requiredBy:
  - math/matrix.hpp
  timestamp: '2026-10-23 22:22:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/matrix.test.cpp
  - test/library-checker/pow_of_matrix.test.cpp
  - test/library-checker/matrix_product.test.cpp
documentation_of: algebra/semiring_plus_times.hpp
layout: document
title: 'Semiring: Plus Times'
---
