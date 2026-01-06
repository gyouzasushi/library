---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/matrix_product.test.cpp
    title: test/library-checker/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/pow_of_matrix.test.cpp
    title: test/library-checker/pow_of_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix.hpp\"\n#include <vector>\ntemplate <typename\
    \ T>\nstruct matrix {\npublic:\n    matrix() {\n    }\n    matrix(size_t n, size_t\
    \ m) : a(n, std::vector<T>(m, 0)) {\n    }\n    matrix(std::vector<std::vector<T>>\
    \ _a) {\n        for (size_t i = 1; i < _a.size(); i++) {\n            assert(_a[0].size()\
    \ == _a[i].size());\n        }\n        a = std::move(_a);\n    }\n    matrix(std::vector<T>\
    \ _a) {\n        a.resize(_a.size());\n        for (size_t i = 0; i < a.size();\
    \ i++) {\n            a[i].resize(1);\n            a[i][0] = _a[i];\n        }\n\
    \    }\n    static matrix e(size_t n) {\n        matrix ret(n, n);\n        for\
    \ (size_t i = 0; i < n; i++) ret[i][i] = 1;\n        return ret;\n    }\n    inline\
    \ const std::vector<T>& operator[](int i) const {\n        return a[i];\n    }\n\
    \    inline std::vector<T>& operator[](int i) {\n        return a[i];\n    }\n\
    \    matrix& operator*=(const matrix& rhs) {\n        assert(a[0].size() == rhs.a.size());\n\
    \        std::vector ret(a.size(), std::vector<T>(rhs[0].size(), 0));\n      \
    \  for (size_t i = 0; i < a.size(); i++) {\n            for (size_t j = 0; j <\
    \ rhs[0].size(); j++) {\n                for (size_t k = 0; k < a[0].size(); k++)\
    \ {\n                    ret[i][j] += a[i][k] * rhs[k][j];\n                }\n\
    \            }\n        }\n        a = std::move(ret);\n        return *this;\n\
    \    }\n    matrix operator*(const matrix& rhs) const {\n        return matrix(*this)\
    \ *= rhs;\n    }\n    matrix pow(long long k) const {\n        assert(0 <= k);\n\
    \        matrix x = *this, ret = matrix::e(a.size());\n        while (k > 0) {\n\
    \            if (k & 1) ret *= x;\n            x *= x;\n            k >>= 1;\n\
    \        }\n        return ret;\n    }\n\nprivate:\n    std::vector<std::vector<T>>\
    \ a;\n};\n"
  code: "#pragma once\n#include <vector>\ntemplate <typename T>\nstruct matrix {\n\
    public:\n    matrix() {\n    }\n    matrix(size_t n, size_t m) : a(n, std::vector<T>(m,\
    \ 0)) {\n    }\n    matrix(std::vector<std::vector<T>> _a) {\n        for (size_t\
    \ i = 1; i < _a.size(); i++) {\n            assert(_a[0].size() == _a[i].size());\n\
    \        }\n        a = std::move(_a);\n    }\n    matrix(std::vector<T> _a) {\n\
    \        a.resize(_a.size());\n        for (size_t i = 0; i < a.size(); i++) {\n\
    \            a[i].resize(1);\n            a[i][0] = _a[i];\n        }\n    }\n\
    \    static matrix e(size_t n) {\n        matrix ret(n, n);\n        for (size_t\
    \ i = 0; i < n; i++) ret[i][i] = 1;\n        return ret;\n    }\n    inline const\
    \ std::vector<T>& operator[](int i) const {\n        return a[i];\n    }\n   \
    \ inline std::vector<T>& operator[](int i) {\n        return a[i];\n    }\n  \
    \  matrix& operator*=(const matrix& rhs) {\n        assert(a[0].size() == rhs.a.size());\n\
    \        std::vector ret(a.size(), std::vector<T>(rhs[0].size(), 0));\n      \
    \  for (size_t i = 0; i < a.size(); i++) {\n            for (size_t j = 0; j <\
    \ rhs[0].size(); j++) {\n                for (size_t k = 0; k < a[0].size(); k++)\
    \ {\n                    ret[i][j] += a[i][k] * rhs[k][j];\n                }\n\
    \            }\n        }\n        a = std::move(ret);\n        return *this;\n\
    \    }\n    matrix operator*(const matrix& rhs) const {\n        return matrix(*this)\
    \ *= rhs;\n    }\n    matrix pow(long long k) const {\n        assert(0 <= k);\n\
    \        matrix x = *this, ret = matrix::e(a.size());\n        while (k > 0) {\n\
    \            if (k & 1) ret *= x;\n            x *= x;\n            k >>= 1;\n\
    \        }\n        return ret;\n    }\n\nprivate:\n    std::vector<std::vector<T>>\
    \ a;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2024-06-29 11:24:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/pow_of_matrix.test.cpp
  - test/library-checker/matrix_product.test.cpp
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: math/matrix.hpp
---
