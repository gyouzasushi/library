---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/point_set_range_composite.test.cpp
    title: test/library-checker/point_set_range_composite.test.cpp
  - icon: ':x:'
    path: test/unit/monoid.test.cpp
    title: test/unit/monoid.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid_affine.hpp\"\ntemplate <class T>\nstruct\
    \ monoid_affine {\n    struct S {\n        T a, b;\n    };\n    static S op(S\
    \ f, S g) {\n        return {g.a * f.a, g.a * f.b + g.b};\n    }\n    static S\
    \ e() {\n        return {T(1), T(0)};\n    }\n    static T eval(S f, T x) {\n\
    \        return f.a * x + f.b;\n    }\n};\n"
  code: "#pragma once\ntemplate <class T>\nstruct monoid_affine {\n    struct S {\n\
    \        T a, b;\n    };\n    static S op(S f, S g) {\n        return {g.a * f.a,\
    \ g.a * f.b + g.b};\n    }\n    static S e() {\n        return {T(1), T(0)};\n\
    \    }\n    static T eval(S f, T x) {\n        return f.a * x + f.b;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_affine.hpp
  requiredBy: []
  timestamp: '2026-10-23 22:06:19+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/unit/monoid.test.cpp
  - test/library-checker/point_set_range_composite.test.cpp
documentation_of: algebra/monoid_affine.hpp
layout: document
title: 'Monoid: Affine'
---
