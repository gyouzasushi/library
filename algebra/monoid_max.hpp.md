---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/dynamic_segtree.test.cpp
    title: test/unit/dynamic_segtree.test.cpp
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
  bundledCode: "#line 2 \"algebra/monoid_max.hpp\"\n#include <algorithm>\n#include\
    \ <limits>\ntemplate <class T>\nstruct monoid_max {\n    using S = T;\n    static\
    \ S op(S a, S b) {\n        return std::max(a, b);\n    }\n    static S e() {\n\
    \        return std::numeric_limits<T>::lowest();\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\ntemplate <class T>\n\
    struct monoid_max {\n    using S = T;\n    static S op(S a, S b) {\n        return\
    \ std::max(a, b);\n    }\n    static S e() {\n        return std::numeric_limits<T>::lowest();\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_max.hpp
  requiredBy: []
  timestamp: '2026-10-23 22:06:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/dynamic_segtree.test.cpp
  - test/unit/sparse_table.test.cpp
  - test/unit/monoid.test.cpp
documentation_of: algebra/monoid_max.hpp
layout: document
title: 'Monoid: Max'
---
