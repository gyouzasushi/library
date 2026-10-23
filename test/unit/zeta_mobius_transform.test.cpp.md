---
data:
  _extendedDependsOn:
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unit/zeta_mobius_transform.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <atcoder/modint>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\n#line 4 \"math/zeta_mobius_transform.hpp\"\ntemplate <typename\
    \ mint>\nvoid superset_zeta(std::vector<mint>& f) {\n    int n = f.size();\n \
    \   assert((n & -n) == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; j++) {\n            if ((j & i) == 0) {\n               \
    \ f[j] += f[j | i];\n            }\n        }\n    }\n}\ntemplate <typename mint>\n\
    void superset_mobius(std::vector<mint>& f) {\n    int n = f.size();\n    assert((n\
    \ & -n) == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0;\
    \ j < n; j++) {\n            if ((j & i) == 0) {\n                f[j] -= f[j\
    \ | i];\n            }\n        }\n    }\n}\ntemplate <typename mint>\nvoid subset_zeta(std::vector<mint>&\
    \ f) {\n    int n = f.size();\n    assert((n & -n) == n);\n    for (int i = 1;\
    \ i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j\
    \ & i) == 0) {\n                f[j | i] += f[j];\n            }\n        }\n\
    \    }\n}\ntemplate <typename mint>\nvoid subset_mobius(std::vector<mint>& f)\
    \ {\n    int n = f.size();\n    assert((n & -n) == n);\n    for (int i = 1; i\
    \ < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j &\
    \ i) == 0) {\n                f[j | i] -= f[j];\n            }\n        }\n  \
    \  }\n}\n#line 9 \"test/unit/zeta_mobius_transform.test.cpp\"\nusing mint = atcoder::modint998244353;\n\
    int main() {\n    std::mt19937 rng(7959);\n    for (int k = 0; k <= 8; k++) {\n\
    \        int n = 1 << k;\n        for (int trial = 0; trial < 5; trial++) {\n\
    \            std::vector<mint> f(n);\n            for (auto& x : f) x = rng();\n\
    \            std::vector<mint> sup(n), sub(n);\n            for (int s = 0; s\
    \ < n; s++) {\n                for (int t = 0; t < n; t++) {\n               \
    \     if ((s & t) == s) sup[s] += f[t];\n                    if ((s & t) == t)\
    \ sub[s] += f[t];\n                }\n            }\n            auto g = f;\n\
    \            superset_zeta(g);\n            assert(g == sup);\n            superset_mobius(g);\n\
    \            assert(g == f);\n            g = f;\n            subset_zeta(g);\n\
    \            assert(g == sub);\n            subset_mobius(g);\n            assert(g\
    \ == f);\n        }\n    }\n    std::cout << \"Hello World\" << std::endl;\n \
    \   return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <atcoder/modint>\n#include <cassert>\n#include <iostream>\n#include\
    \ <random>\n#include <vector>\n\n#include \"math/zeta_mobius_transform.hpp\"\n\
    using mint = atcoder::modint998244353;\nint main() {\n    std::mt19937 rng(7959);\n\
    \    for (int k = 0; k <= 8; k++) {\n        int n = 1 << k;\n        for (int\
    \ trial = 0; trial < 5; trial++) {\n            std::vector<mint> f(n);\n    \
    \        for (auto& x : f) x = rng();\n            std::vector<mint> sup(n), sub(n);\n\
    \            for (int s = 0; s < n; s++) {\n                for (int t = 0; t\
    \ < n; t++) {\n                    if ((s & t) == s) sup[s] += f[t];\n       \
    \             if ((s & t) == t) sub[s] += f[t];\n                }\n         \
    \   }\n            auto g = f;\n            superset_zeta(g);\n            assert(g\
    \ == sup);\n            superset_mobius(g);\n            assert(g == f);\n   \
    \         g = f;\n            subset_zeta(g);\n            assert(g == sub);\n\
    \            subset_mobius(g);\n            assert(g == f);\n        }\n    }\n\
    \    std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - math/zeta_mobius_transform.hpp
  isVerificationFile: true
  path: test/unit/zeta_mobius_transform.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:43:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/zeta_mobius_transform.test.cpp
layout: document
redirect_from:
- /verify/test/unit/zeta_mobius_transform.test.cpp
- /verify/test/unit/zeta_mobius_transform.test.cpp.html
title: test/unit/zeta_mobius_transform.test.cpp
---
