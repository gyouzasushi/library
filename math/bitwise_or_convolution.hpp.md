---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/zeta_mobius_transform.hpp
    title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB\u30FB\u9AD8\u901F\u30E1\u30D3\
      \u30A6\u30B9\u5909\u63DB"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    \ }\n    }\n}\n#line 3 \"math/bitwise_or_convolution.hpp\"\ntemplate <class T>\n\
    std::vector<T> bitwise_or_convolution(std::vector<T> a,\n                    \
    \                     std::vector<T> b) {\n    subset_zeta(a);\n    subset_zeta(b);\n\
    \    for (int i = 0; i < int(a.size()); i++) {\n        a[i] *= b[i];\n    }\n\
    \    subset_mobius(a);\n    return a;\n}\n"
  code: "#pragma once\n#include \"zeta_mobius_transform.hpp\"\ntemplate <class T>\n\
    std::vector<T> bitwise_or_convolution(std::vector<T> a,\n                    \
    \                     std::vector<T> b) {\n    subset_zeta(a);\n    subset_zeta(b);\n\
    \    for (int i = 0; i < int(a.size()); i++) {\n        a[i] *= b[i];\n    }\n\
    \    subset_mobius(a);\n    return a;\n}\n"
  dependsOn:
  - math/zeta_mobius_transform.hpp
  isVerificationFile: false
  path: math/bitwise_or_convolution.hpp
  requiredBy: []
  timestamp: '2026-10-27 06:53:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/zeta_mobius_transform.test.cpp
  - test/library-checker/bitwise_or_convolution.test.cpp
documentation_of: math/bitwise_or_convolution.hpp
layout: document
title: Bitwise Or Convolution
---

### 概要
- 添字の bitwise OR についての畳み込みを求める。

### 使い方
- `bitwise_or_convolution(a, b)`: $c_k = \displaystyle \sum_{i \mathbin{|} j = k} a_i b_j$ となる数列 `c` を返す。

### 制約
- $\lvert a \rvert = \lvert b \rvert = 2^n$ ($0 \le n$)

### 計算量
- $\mathcal{O}(2^n n)$
