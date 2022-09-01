---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/semiring_matrix.hpp\"\ntemplate <class S, S (*add)(S,\
    \ S), S (*zero)(), S (*mul)(S, S), S (*one)()>\nstruct Matrix {\n    std::vector<std::vector<S>>\
    \ a;\n    Matrix() {\n    }\n    Matrix(size_t n, size_t m) : a(n, std::vector<S>(m,\
    \ zero())) {\n    }\n    Matrix(std::vector<std::vector<S>> _a) {\n        for\
    \ (size_t i = 1; i < _a.size(); i++) {\n            assert(_a[0].size() == _a[i].size());\n\
    \        }\n        a = std::move(_a);\n    }\n    static Matrix e(size_t n) {\n\
    \        Matrix ret(n, n);\n        for (size_t i = 0; i < n; i++) ret[i][i] =\
    \ one();\n        return ret;\n    }\n    inline const std::vector<S>& operator[](int\
    \ i) const {\n        return a[i];\n    }\n    inline std::vector<S>& operator[](int\
    \ i) {\n        return a[i];\n    }\n    Matrix& operator*=(const Matrix& rhs)\
    \ {\n        assert(a[0].size() == rhs.a.size());\n        std::vector ret(a.size(),\
    \ std::vector<S>(rhs[0].size(), zero()));\n        for (size_t i = 0; i < a.size();\
    \ i++) {\n            for (size_t j = 0; j < rhs[0].size(); j++) {\n         \
    \       for (size_t k = 0; k < a[0].size(); k++) {\n                    ret[i][j]\
    \ = add(ret[i][j], mul(a[i][k], rhs[k][j]));\n                }\n            }\n\
    \        }\n        a = std::move(ret);\n        return *this;\n    }\n    Matrix\
    \ operator*(const Matrix& rhs) const {\n        return Matrix(*this) *= rhs;\n\
    \    }\n    Matrix pow(long long k) const {\n        assert(0 <= k);\n       \
    \ Matrix x = *this, ret = Matrix::e(a.size());\n        while (k > 0) {\n    \
    \        if (k & 1) ret *= x;\n            x *= x;\n            k >>= 1;\n   \
    \     }\n        return ret;\n    }\n};\n"
  code: "#pragma once\ntemplate <class S, S (*add)(S, S), S (*zero)(), S (*mul)(S,\
    \ S), S (*one)()>\nstruct Matrix {\n    std::vector<std::vector<S>> a;\n    Matrix()\
    \ {\n    }\n    Matrix(size_t n, size_t m) : a(n, std::vector<S>(m, zero())) {\n\
    \    }\n    Matrix(std::vector<std::vector<S>> _a) {\n        for (size_t i =\
    \ 1; i < _a.size(); i++) {\n            assert(_a[0].size() == _a[i].size());\n\
    \        }\n        a = std::move(_a);\n    }\n    static Matrix e(size_t n) {\n\
    \        Matrix ret(n, n);\n        for (size_t i = 0; i < n; i++) ret[i][i] =\
    \ one();\n        return ret;\n    }\n    inline const std::vector<S>& operator[](int\
    \ i) const {\n        return a[i];\n    }\n    inline std::vector<S>& operator[](int\
    \ i) {\n        return a[i];\n    }\n    Matrix& operator*=(const Matrix& rhs)\
    \ {\n        assert(a[0].size() == rhs.a.size());\n        std::vector ret(a.size(),\
    \ std::vector<S>(rhs[0].size(), zero()));\n        for (size_t i = 0; i < a.size();\
    \ i++) {\n            for (size_t j = 0; j < rhs[0].size(); j++) {\n         \
    \       for (size_t k = 0; k < a[0].size(); k++) {\n                    ret[i][j]\
    \ = add(ret[i][j], mul(a[i][k], rhs[k][j]));\n                }\n            }\n\
    \        }\n        a = std::move(ret);\n        return *this;\n    }\n    Matrix\
    \ operator*(const Matrix& rhs) const {\n        return Matrix(*this) *= rhs;\n\
    \    }\n    Matrix pow(long long k) const {\n        assert(0 <= k);\n       \
    \ Matrix x = *this, ret = Matrix::e(a.size());\n        while (k > 0) {\n    \
    \        if (k & 1) ret *= x;\n            x *= x;\n            k >>= 1;\n   \
    \     }\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/semiring_matrix.hpp
  requiredBy: []
  timestamp: '2022-09-01 13:39:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/semiring_matrix.hpp
layout: document
redirect_from:
- /library/math/semiring_matrix.hpp
- /library/math/semiring_matrix.hpp.html
title: math/semiring_matrix.hpp
---
