---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_matrix
    links:
    - https://judge.yosupo.jp/problem/pow_of_matrix
  bundledCode: "#line 1 \"test/library-checker/pow_of_matrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/pow_of_matrix\"\n#include <atcoder/modint>\n\
    #include <iostream>\n\n#line 2 \"math/matrix.hpp\"\n#include <vector>\ntemplate\
    \ <typename T>\nstruct matrix {\npublic:\n    matrix() {\n    }\n    matrix(size_t\
    \ n, size_t m) : a(n, std::vector<T>(m, 0)) {\n    }\n    matrix(std::vector<std::vector<T>>\
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
    \ a;\n};\n#line 6 \"test/library-checker/pow_of_matrix.test.cpp\"\n\nusing mint\
    \ = atcoder::modint998244353;\nint main() {\n    int n;\n    long long k;\n  \
    \  std::cin >> n >> k;\n    matrix<mint> a(n, n);\n    for (int i = 0; i < n;\
    \ i++) {\n        for (int j = 0; j < n; j++) {\n            int x;\n        \
    \    std::cin >> x;\n            a[i][j] = mint::raw(x);\n        }\n    }\n \
    \   matrix b = a.pow(k);\n    for (int i = 0; i < n; i++) {\n        for (int\
    \ j = 0; j < n; j++) {\n            std::cout << b[i][j].val() << \" \\n\"[j ==\
    \ n - 1];\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_matrix\"\n#include\
    \ <atcoder/modint>\n#include <iostream>\n\n#include \"math/matrix.hpp\"\n\nusing\
    \ mint = atcoder::modint998244353;\nint main() {\n    int n;\n    long long k;\n\
    \    std::cin >> n >> k;\n    matrix<mint> a(n, n);\n    for (int i = 0; i < n;\
    \ i++) {\n        for (int j = 0; j < n; j++) {\n            int x;\n        \
    \    std::cin >> x;\n            a[i][j] = mint::raw(x);\n        }\n    }\n \
    \   matrix b = a.pow(k);\n    for (int i = 0; i < n; i++) {\n        for (int\
    \ j = 0; j < n; j++) {\n            std::cout << b[i][j].val() << \" \\n\"[j ==\
    \ n - 1];\n        }\n    }\n}"
  dependsOn:
  - math/matrix.hpp
  isVerificationFile: true
  path: test/library-checker/pow_of_matrix.test.cpp
  requiredBy: []
  timestamp: '2024-07-05 09:34:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/pow_of_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/pow_of_matrix.test.cpp
- /verify/test/library-checker/pow_of_matrix.test.cpp.html
title: test/library-checker/pow_of_matrix.test.cpp
---
