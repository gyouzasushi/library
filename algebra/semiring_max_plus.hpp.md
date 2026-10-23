---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/matrix.test.cpp
    title: test/unit/matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/semiring_max_plus.hpp\"\n#include <algorithm>\n\
    #include <limits>\ntemplate <class T>\nstruct semiring_max_plus {\n    using S\
    \ = T;\n    static S add(S a, S b) {\n        return std::max(a, b);\n    }\n\
    \    static S zero() {\n        return std::numeric_limits<T>::lowest();\n   \
    \ }\n    static S mul(S a, S b) {\n        if (a == zero() || b == zero()) return\
    \ zero();\n        return a + b;\n    }\n    static S one() {\n        return\
    \ T(0);\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\ntemplate <class T>\n\
    struct semiring_max_plus {\n    using S = T;\n    static S add(S a, S b) {\n \
    \       return std::max(a, b);\n    }\n    static S zero() {\n        return std::numeric_limits<T>::lowest();\n\
    \    }\n    static S mul(S a, S b) {\n        if (a == zero() || b == zero())\
    \ return zero();\n        return a + b;\n    }\n    static S one() {\n       \
    \ return T(0);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/semiring_max_plus.hpp
  requiredBy: []
  timestamp: '2026-10-23 22:22:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/matrix.test.cpp
documentation_of: algebra/semiring_max_plus.hpp
layout: document
title: 'Semiring: Max Plus'
---
