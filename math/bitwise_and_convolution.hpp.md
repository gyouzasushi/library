---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/zeta_mobius_transform.hpp
    title: math/zeta_mobius_transform.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/bitwise_and_convolution.test.cpp
    title: test/library-checker/bitwise_and_convolution.test.cpp
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
    \                f[j | i] -= f[j];\n            }\n        }\n    }\n}\n#line\
    \ 3 \"math/bitwise_and_convolution.hpp\"\ntemplate <typename mint>\nstd::vector<mint>\
    \ bitwise_and_convolution(std::vector<mint> a,\n                             \
    \             std::vector<mint> b) {\n    superset_zeta(a);\n    superset_zeta(b);\n\
    \    for (int i = 0; i < int(a.size()); i++) {\n        a[i] *= b[i];\n    }\n\
    \    superset_mobius(a);\n    return a;\n}\n"
  code: "#pragma once\n#include \"zeta_mobius_transform.hpp\"\ntemplate <typename\
    \ mint>\nstd::vector<mint> bitwise_and_convolution(std::vector<mint> a,\n    \
    \                                      std::vector<mint> b) {\n    superset_zeta(a);\n\
    \    superset_zeta(b);\n    for (int i = 0; i < int(a.size()); i++) {\n      \
    \  a[i] *= b[i];\n    }\n    superset_mobius(a);\n    return a;\n}\n"
  dependsOn:
  - math/zeta_mobius_transform.hpp
  isVerificationFile: false
  path: math/bitwise_and_convolution.hpp
  requiredBy: []
  timestamp: '2022-09-17 18:19:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/bitwise_and_convolution.test.cpp
documentation_of: math/bitwise_and_convolution.hpp
layout: document
redirect_from:
- /library/math/bitwise_and_convolution.hpp
- /library/math/bitwise_and_convolution.hpp.html
title: math/bitwise_and_convolution.hpp
---
