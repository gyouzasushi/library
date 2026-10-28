---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/bitwise_and_convolution.hpp
    title: Bitwise And Convolution
  - icon: ':heavy_check_mark:'
    path: math/bitwise_or_convolution.hpp
    title: Bitwise Or Convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/bitwise_and_convolution.test.cpp
    title: test/library-checker/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/bitwise_or_convolution.test.cpp
    title: test/library-checker/bitwise_or_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/zeta_mobius_transform.test.cpp
    title: test/unit/zeta_mobius_transform.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/zeta_mobius_transform.hpp\"\n#include <cassert>\n#include\
    \ <vector>\ntemplate <class T>\nvoid superset_zeta(std::vector<T>& f) {\n    int\
    \ n = int(f.size());\n    assert((n & -n) == n);\n    for (int i = 1; i < n; i\
    \ <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j & i) ==\
    \ 0) {\n                f[j] += f[j | i];\n            }\n        }\n    }\n}\n\
    template <class T>\nvoid superset_mobius(std::vector<T>& f) {\n    int n = int(f.size());\n\
    \    assert((n & -n) == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; j++) {\n            if ((j & i) == 0) {\n               \
    \ f[j] -= f[j | i];\n            }\n        }\n    }\n}\ntemplate <class T>\n\
    void subset_zeta(std::vector<T>& f) {\n    int n = int(f.size());\n    assert((n\
    \ & -n) == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0;\
    \ j < n; j++) {\n            if ((j & i) == 0) {\n                f[j | i] +=\
    \ f[j];\n            }\n        }\n    }\n}\ntemplate <class T>\nvoid subset_mobius(std::vector<T>&\
    \ f) {\n    int n = int(f.size());\n    assert((n & -n) == n);\n    for (int i\
    \ = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if\
    \ ((j & i) == 0) {\n                f[j | i] -= f[j];\n            }\n       \
    \ }\n    }\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\ntemplate <class T>\n\
    void superset_zeta(std::vector<T>& f) {\n    int n = int(f.size());\n    assert((n\
    \ & -n) == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0;\
    \ j < n; j++) {\n            if ((j & i) == 0) {\n                f[j] += f[j\
    \ | i];\n            }\n        }\n    }\n}\ntemplate <class T>\nvoid superset_mobius(std::vector<T>&\
    \ f) {\n    int n = int(f.size());\n    assert((n & -n) == n);\n    for (int i\
    \ = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if\
    \ ((j & i) == 0) {\n                f[j] -= f[j | i];\n            }\n       \
    \ }\n    }\n}\ntemplate <class T>\nvoid subset_zeta(std::vector<T>& f) {\n   \
    \ int n = int(f.size());\n    assert((n & -n) == n);\n    for (int i = 1; i <\
    \ n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j & i)\
    \ == 0) {\n                f[j | i] += f[j];\n            }\n        }\n    }\n\
    }\ntemplate <class T>\nvoid subset_mobius(std::vector<T>& f) {\n    int n = int(f.size());\n\
    \    assert((n & -n) == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; j++) {\n            if ((j & i) == 0) {\n               \
    \ f[j | i] -= f[j];\n            }\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/zeta_mobius_transform.hpp
  requiredBy:
  - math/bitwise_and_convolution.hpp
  - math/bitwise_or_convolution.hpp
  timestamp: '2026-10-27 06:53:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/zeta_mobius_transform.test.cpp
  - test/library-checker/bitwise_and_convolution.test.cpp
  - test/library-checker/bitwise_or_convolution.test.cpp
documentation_of: math/zeta_mobius_transform.hpp
layout: document
title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB\u30FB\u9AD8\u901F\u30E1\u30D3\u30A6\
  \u30B9\u5909\u63DB"
---

### 概要
- 集合を添字とする数列について、上位集合・下位集合にわたる和とその逆変換を求める。

### 使い方
- `superset_zeta(f)`: `f` を $g(S) = \displaystyle \sum_{S \subseteq T} f(T)$ で置き換える。
- `superset_mobius(f)`: `f` を $f(S) = \displaystyle \sum_{S \subseteq T} g(T)$ となる `g` で置き換える。
- `subset_zeta(f)`: `f` を $g(S) = \displaystyle \sum_{T \subseteq S} f(T)$ で置き換える。
- `subset_mobius(f)`: `f` を $f(S) = \displaystyle \sum_{T \subseteq S} g(T)$ となる `g` で置き換える。

### 制約
- $\lvert f \rvert = 2^n$ ($0 \le n$)

### 計算量
- $\mathcal{O}(2^n n)$
