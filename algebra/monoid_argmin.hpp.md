---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: datastructure/plus_minus_one_rmq.hpp
    title: Plus Minus One RMQ
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148(LCA)"
  - icon: ':heavy_check_mark:'
    path: graph/manhattan_mst.hpp
    title: Manhattan MST
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/lca.test.cpp
    title: test/library-checker/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/manhattanmst.test.cpp
    title: test/library-checker/manhattanmst.test.cpp
  - icon: ':x:'
    path: test/unit/monoid.test.cpp
    title: test/unit/monoid.test.cpp
  - icon: ':x:'
    path: test/unit/sparse_table.test.cpp
    title: test/unit/sparse_table.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_argmin.hpp\"\n#include <limits>\ntemplate\
    \ <class T>\nstruct monoid_argmin {\n    struct S {\n        T val;\n        int\
    \ id;\n    };\n    static S op(S a, S b) {\n        if (a.val != b.val) return\
    \ a.val < b.val ? a : b;\n        return a.id < b.id ? a : b;\n    }\n    static\
    \ S e() {\n        return {std::numeric_limits<T>::max(), -1};\n    }\n};\n"
  code: "#pragma once\n#include <limits>\ntemplate <class T>\nstruct monoid_argmin\
    \ {\n    struct S {\n        T val;\n        int id;\n    };\n    static S op(S\
    \ a, S b) {\n        if (a.val != b.val) return a.val < b.val ? a : b;\n     \
    \   return a.id < b.id ? a : b;\n    }\n    static S e() {\n        return {std::numeric_limits<T>::max(),\
    \ -1};\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_argmin.hpp
  requiredBy:
  - datastructure/plus_minus_one_rmq.hpp
  - graph/manhattan_mst.hpp
  - graph/lowest_common_ancestor.hpp
  timestamp: '2026-10-23 22:06:19+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/unit/sparse_table.test.cpp
  - test/unit/monoid.test.cpp
  - test/library-checker/lca.test.cpp
  - test/library-checker/manhattanmst.test.cpp
documentation_of: algebra/monoid_argmin.hpp
layout: document
title: 'Monoid: Argmin'
---
