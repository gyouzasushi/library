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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/zeta_mobius_transform.hpp\"\n#include <cassert>\n#include\
    \ <vector>\ntemplate <typename mint>\nvoid superset_zeta(std::vector<mint>& f)\
    \ {\n    int n = f.size();\n    assert((n & -n) == n);\n    for (int i = 1; i\
    \ < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j &\
    \ i) == 0) {\n                f[j] += f[j | i];\n            }\n        }\n  \
    \  }\n}\ntemplate <typename mint>\nvoid superset_mobius(std::vector<mint>& f)\
    \ {\n    int n = f.size();\n    assert((n & -n) == n);\n    for (int i = 1; i\
    \ < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j &\
    \ i) == 0) {\n                f[j] -= f[j | i];\n            }\n        }\n  \
    \  }\n}\ntemplate <typename mint>\nvoid subset_zeta(std::vector<mint>& f) {\n\
    \    int n = f.size();\n    assert((n & -n) == n);\n    for (int i = 1; i < n;\
    \ i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j & i) ==\
    \ 0) {\n                f[j | i] += f[j];\n            }\n        }\n    }\n}\n\
    template <typename mint>\nvoid subset_mobius(std::vector<mint>& f) {\n    int\
    \ n = f.size();\n    assert((n & -n) == n);\n    for (int i = 1; i < n; i <<=\
    \ 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j & i) == 0) {\n\
    \                f[j | i] -= f[j];\n            }\n        }\n    }\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\ntemplate <typename mint>\n\
    void superset_zeta(std::vector<mint>& f) {\n    int n = f.size();\n    assert((n\
    \ & -n) == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0;\
    \ j < n; j++) {\n            if ((j & i) == 0) {\n                f[j] += f[j\
    \ | i];\n            }\n        }\n    }\n}\ntemplate <typename mint>\nvoid superset_mobius(std::vector<mint>&\
    \ f) {\n    int n = f.size();\n    assert((n & -n) == n);\n    for (int i = 1;\
    \ i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j\
    \ & i) == 0) {\n                f[j] -= f[j | i];\n            }\n        }\n\
    \    }\n}\ntemplate <typename mint>\nvoid subset_zeta(std::vector<mint>& f) {\n\
    \    int n = f.size();\n    assert((n & -n) == n);\n    for (int i = 1; i < n;\
    \ i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j & i) ==\
    \ 0) {\n                f[j | i] += f[j];\n            }\n        }\n    }\n}\n\
    template <typename mint>\nvoid subset_mobius(std::vector<mint>& f) {\n    int\
    \ n = f.size();\n    assert((n & -n) == n);\n    for (int i = 1; i < n; i <<=\
    \ 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j & i) == 0) {\n\
    \                f[j | i] -= f[j];\n            }\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/zeta_mobius_transform.hpp
  requiredBy:
  - math/bitwise_or_convolution.hpp
  - math/bitwise_and_convolution.hpp
  timestamp: '2022-09-17 18:19:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/bitwise_and_convolution.test.cpp
  - test/library-checker/bitwise_or_convolution.test.cpp
documentation_of: math/zeta_mobius_transform.hpp
layout: document
title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB\u30FB\u9AD8\u901F\u30E1\u30D3\u30A6\
  \u30B9\u5909\u63DB"
---

### 使い方
- `superset_zeta(f)`: `f` を $g(S) = \displaystyle \sum_{S\subset T}f(T)$ となる `g` に置き換える。
- `superset_mobius(f)`: `f` を $f(S) = \displaystyle \sum_{S \subset T}g(T)$ となる `g` に置き換える。
- `subset_zeta(f)`: `f` を $g(S) = \displaystyle \sum_{S \supset T}f(T)$ となる `g` に置き換える。
- `subset_mobius(f)`: `f` を $f(S) = \displaystyle \sum_{S \supset T}g(T)$ となる `g` に置き換える。
  
### 制約
- ある非負整数 $n$ が存在して $\|f\|=2^n$ 。