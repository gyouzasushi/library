---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/bitwise_and_convolution.hpp
    title: Bitwise And Convolution
  - icon: ':heavy_check_mark:'
    path: math/zeta_mobius_transform.hpp
    title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB\u30FB\u9AD8\u901F\u30E1\u30D3\
      \u30A6\u30B9\u5909\u63DB"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"test/library-checker/bitwise_and_convolution.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n\
    #line 2 \"math/zeta_mobius_transform.hpp\"\n#include <cassert>\n#include <vector>\n\
    template <class T>\nvoid superset_zeta(std::vector<T>& f) {\n    int n = int(f.size());\n\
    \    assert((n & -n) == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; j++) {\n            if ((j & i) == 0) {\n               \
    \ f[j] += f[j | i];\n            }\n        }\n    }\n}\ntemplate <class T>\n\
    void superset_mobius(std::vector<T>& f) {\n    int n = int(f.size());\n    assert((n\
    \ & -n) == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0;\
    \ j < n; j++) {\n            if ((j & i) == 0) {\n                f[j] -= f[j\
    \ | i];\n            }\n        }\n    }\n}\ntemplate <class T>\nvoid subset_zeta(std::vector<T>&\
    \ f) {\n    int n = int(f.size());\n    assert((n & -n) == n);\n    for (int i\
    \ = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if\
    \ ((j & i) == 0) {\n                f[j | i] += f[j];\n            }\n       \
    \ }\n    }\n}\ntemplate <class T>\nvoid subset_mobius(std::vector<T>& f) {\n \
    \   int n = int(f.size());\n    assert((n & -n) == n);\n    for (int i = 1; i\
    \ < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j &\
    \ i) == 0) {\n                f[j | i] -= f[j];\n            }\n        }\n  \
    \  }\n}\n#line 3 \"math/bitwise_and_convolution.hpp\"\ntemplate <class T>\nstd::vector<T>\
    \ bitwise_and_convolution(std::vector<T> a,\n                                \
    \          std::vector<T> b) {\n    superset_zeta(a);\n    superset_zeta(b);\n\
    \    for (int i = 0; i < int(a.size()); i++) {\n        a[i] *= b[i];\n    }\n\
    \    superset_mobius(a);\n    return a;\n}\n#line 3 \"test/library-checker/bitwise_and_convolution.test.cpp\"\
    \n\n#include <atcoder/modint>\n#include <iostream>\n\nusing mint = atcoder::modint998244353;\n\
    int main() {\n    int n;\n    std::cin >> n;\n    std::vector<mint> a(1 << n),\
    \ b(1 << n);\n    for (int i = 0; i < (1 << n); i++) {\n        int x;\n     \
    \   std::cin >> x;\n        a[i] = mint::raw(x);\n    }\n    for (int i = 0; i\
    \ < (1 << n); i++) {\n        int x;\n        std::cin >> x;\n        b[i] = mint::raw(x);\n\
    \    }\n\n    std::vector<mint> c = bitwise_and_convolution(a, b);\n    for (int\
    \ i = 0; i < (1 << n); i++) {\n        std::cout << c[i].val() << \" \\n\"[i ==\
    \ (1 << n) - 1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n#include \"math/bitwise_and_convolution.hpp\"\n\n#include <atcoder/modint>\n\
    #include <iostream>\n\nusing mint = atcoder::modint998244353;\nint main() {\n\
    \    int n;\n    std::cin >> n;\n    std::vector<mint> a(1 << n), b(1 << n);\n\
    \    for (int i = 0; i < (1 << n); i++) {\n        int x;\n        std::cin >>\
    \ x;\n        a[i] = mint::raw(x);\n    }\n    for (int i = 0; i < (1 << n); i++)\
    \ {\n        int x;\n        std::cin >> x;\n        b[i] = mint::raw(x);\n  \
    \  }\n\n    std::vector<mint> c = bitwise_and_convolution(a, b);\n    for (int\
    \ i = 0; i < (1 << n); i++) {\n        std::cout << c[i].val() << \" \\n\"[i ==\
    \ (1 << n) - 1];\n    }\n}"
  dependsOn:
  - math/bitwise_and_convolution.hpp
  - math/zeta_mobius_transform.hpp
  isVerificationFile: true
  path: test/library-checker/bitwise_and_convolution.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 06:53:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/bitwise_and_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/bitwise_and_convolution.test.cpp
- /verify/test/library-checker/bitwise_and_convolution.test.cpp.html
title: test/library-checker/bitwise_and_convolution.test.cpp
---
