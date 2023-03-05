---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/zeta_mobius_transform.hpp
    title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB\u30FB\u9AD8\u901F\u30E1\u30D3\
      \u30A6\u30B9\u5909\u63DB"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \                f[j | i] -= f[j];\n            }\n        }\n    }\n}\n#line\
    \ 3 \"math/bitwise_or_convolution.hpp\"\ntemplate <typename mint>\nstd::vector<mint>\
    \ bitwise_or_convolution(std::vector<mint> a,\n                              \
    \           std::vector<mint> b) {\n    subset_zeta(a);\n    subset_zeta(b);\n\
    \    for (int i = 0; i < int(a.size()); i++) {\n        a[i] *= b[i];\n    }\n\
    \    subset_mobius(a);\n    return a;\n}\n"
  code: "#pragma once\n#include \"zeta_mobius_transform.hpp\"\ntemplate <typename\
    \ mint>\nstd::vector<mint> bitwise_or_convolution(std::vector<mint> a,\n     \
    \                                    std::vector<mint> b) {\n    subset_zeta(a);\n\
    \    subset_zeta(b);\n    for (int i = 0; i < int(a.size()); i++) {\n        a[i]\
    \ *= b[i];\n    }\n    subset_mobius(a);\n    return a;\n}\n"
  dependsOn:
  - math/zeta_mobius_transform.hpp
  isVerificationFile: false
  path: math/bitwise_or_convolution.hpp
  requiredBy: []
  timestamp: '2022-09-17 18:19:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/bitwise_or_convolution.hpp
layout: document
title: Bitwise Or Convolution
---

### 使い方
- `bitwise_or_convolution(a, b)`: $c_k = \displaystyle \sum_{i\|j=k}a_ib_j$ となる数列 `c` を求める。

### 制約
- ある非負整数 $n$ が存在して $\|a\|=\|b\|=2^n$ 。