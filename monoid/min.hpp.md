---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/staticrmq.test.cpp
    title: test/library-checker/staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/monoid.test.cpp
    title: test/unit/monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/sparse_table.test.cpp
    title: test/unit/sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"monoid/min.hpp\"\n#include <algorithm>\n#include <limits>\n\
    template <class T>\nstruct monoid_min {\n    using S = T;\n    static S op(S a,\
    \ S b) {\n        return std::min(a, b);\n    }\n    static S e() {\n        return\
    \ std::numeric_limits<T>::max();\n    }\n    static constexpr bool commutative\
    \ = true;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\ntemplate <class T>\n\
    struct monoid_min {\n    using S = T;\n    static S op(S a, S b) {\n        return\
    \ std::min(a, b);\n    }\n    static S e() {\n        return std::numeric_limits<T>::max();\n\
    \    }\n    static constexpr bool commutative = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: monoid/min.hpp
  requiredBy: []
  timestamp: '2026-10-19 02:48:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_A.test.cpp
  - test/library-checker/staticrmq.test.cpp
  - test/unit/monoid.test.cpp
  - test/unit/sparse_table.test.cpp
documentation_of: monoid/min.hpp
layout: document
title: 'Monoid: Min'
---
