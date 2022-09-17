---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/bitwise_and_convolution.hpp
    title: math/bitwise_and_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: math/bitwise_or_convolution.hpp
    title: math/bitwise_or_convolution.hpp
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
redirect_from:
- /library/math/zeta_mobius_transform.hpp
- /library/math/zeta_mobius_transform.hpp.html
title: math/zeta_mobius_transform.hpp
---
