---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/group_add.hpp
    title: 'Group: Add'
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/point_add_range_sum_dynamic_segtree.test.cpp
    title: test/library-checker/point_add_range_sum_dynamic_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/unionfind_with_potential.test.cpp
    title: test/library-checker/unionfind_with_potential.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/dynamic_segtree.test.cpp
    title: test/unit/dynamic_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/monoid.test.cpp
    title: test/unit/monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/persistent_segtree.test.cpp
    title: test/unit/persistent_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/sqrt_tree.test.cpp
    title: test/unit/sqrt_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/weighted_dsu.test.cpp
    title: test/unit/weighted_dsu.test.cpp
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
  requiredBy:
  - algebra/group_add.hpp
  timestamp: '2026-10-23 22:06:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/dynamic_segtree.test.cpp
  - test/unit/sqrt_tree.test.cpp
  - test/unit/weighted_dsu.test.cpp
  - test/unit/monoid.test.cpp
  - test/unit/persistent_segtree.test.cpp
  - test/library-checker/point_add_range_sum_dynamic_segtree.test.cpp
  - test/library-checker/unionfind_with_potential.test.cpp
documentation_of: algebra/monoid_add.hpp
layout: document
title: 'Monoid: Add'
---
