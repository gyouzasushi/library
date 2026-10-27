---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/combinatorics.hpp
    title: Combinatorics
  - icon: ':heavy_check_mark:'
    path: math/lagrange_interpolation.hpp
    title: Lagrange Interpolation
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
  bundledCode: "#line 1 \"test/unit/lagrange_interpolation.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <atcoder/modint>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <set>\n#include <vector>\n\n#line 4 \"math/lagrange_interpolation.hpp\"\
    \n\n#line 4 \"math/combinatorics.hpp\"\ntemplate <typename mint>\nstruct combinatorics\
    \ {\n    static mint fact(int n) {\n        ensure(n);\n        return facts[n];\n\
    \    }\n    static mint fact_inv(int n) {\n        ensure(n);\n        return\
    \ ifacts[n];\n    }\n    static mint inv(int n) {\n        assert(1 <= n);\n \
    \       ensure(n);\n        return ifacts[n] * facts[n - 1];\n    }\n    static\
    \ mint C(int n, int k) {\n        if (n < 0 || n < k || k < 0) return 0;\n   \
    \     return fact(n) * fact_inv(n - k) * fact_inv(k);\n    }\n    static mint\
    \ P(int n, int k) {\n        if (n < 0 || n < k || k < 0) return 0;\n        return\
    \ fact(n) * fact_inv(n - k);\n    }\n    static mint H(int n, int k) {\n     \
    \   if (n < 0 || k < 0) return 0;\n        if (k == 0) return 1;\n        return\
    \ C(n + k - 1, k);\n    }\n    static void ensure(int n) {\n        assert(n <\
    \ mint::mod());\n        int sz = facts.size();\n        if (sz > n) return;\n\
    \        if (n < sz << 1) n = std::min(mint::mod() - 1, sz << 1);\n        facts.resize(n\
    \ + 1);\n        ifacts.resize(n + 1);\n        for (int i = sz; i <= n; i++)\
    \ facts[i] = facts[i - 1] * i;\n        ifacts[n] = facts[n].inv();\n        for\
    \ (int i = n; i >= sz; i--) ifacts[i - 1] = ifacts[i] * i;\n    }\n\nprivate:\n\
    \    static inline std::vector<mint> facts{1};\n    static inline std::vector<mint>\
    \ ifacts{1};\n};\n#line 6 \"math/lagrange_interpolation.hpp\"\ntemplate <class\
    \ mint> mint lagrange_interpolation(const std::vector<mint>& y, mint c) {\n  \
    \  int n = int(y.size());\n    assert(n >= 1);\n    long long cv = c.val();\n\
    \    if (cv < n) return y[cv];\n    std::vector<mint> pre(n + 1, 1), suf(n + 1,\
    \ 1);\n    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] * (c - i);\n    for\
    \ (int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] * (c - i);\n    using comb\
    \ = combinatorics<mint>;\n    mint ret = 0;\n    for (int i = 0; i < n; i++) {\n\
    \        mint t = y[i] * pre[i] * suf[i + 1] * comb::fact_inv(i) * comb::fact_inv(n\
    \ - 1 - i);\n        ret += (n - 1 - i) & 1 ? -t : t;\n    }\n    return ret;\n\
    }\ntemplate <class mint>\nmint lagrange_interpolation(const std::vector<mint>&\
    \ x, const std::vector<mint>& y, mint c) {\n    int n = int(x.size());\n    assert(n\
    \ >= 1 && int(y.size()) == n);\n    mint ret = 0;\n    for (int i = 0; i < n;\
    \ i++) {\n        mint num = 1, den = 1;\n        for (int j = 0; j < n; j++)\
    \ {\n            if (j == i) continue;\n            assert(x[i] != x[j]);\n  \
    \          num *= c - x[j];\n            den *= x[i] - x[j];\n        }\n    \
    \    ret += y[i] * num / den;\n    }\n    return ret;\n}\n#line 10 \"test/unit/lagrange_interpolation.test.cpp\"\
    \nusing mint = atcoder::modint998244353;\nmint eval(const std::vector<mint>& coef,\
    \ mint c) {\n    mint r = 0;\n    for (int i = int(coef.size()) - 1; i >= 0; i--)\
    \ r = r * c + coef[i];\n    return r;\n}\nint main() {\n    std::mt19937 rng(665);\n\
    \    for (int it = 0; it < 500; it++) {\n        int deg = rng() % 8;\n      \
    \  std::vector<mint> coef(deg + 1);\n        for (auto& a : coef) a = rng();\n\
    \        int n = deg + 1 + rng() % 3;  // extra points are fine\n        std::vector<mint>\
    \ y(n);\n        for (int i = 0; i < n; i++) y[i] = eval(coef, i);\n        for\
    \ (int t = 0; t < 5; t++) {\n            mint c = rng();\n            assert(lagrange_interpolation(y,\
    \ c) == eval(coef, c));\n        }\n        for (int i = 0; i < n; i++) assert(lagrange_interpolation(y,\
    \ mint(i)) == y[i]);\n        assert(lagrange_interpolation(y, mint(n)) == eval(coef,\
    \ n));\n        // arbitrary distinct points\n        std::set<unsigned> used;\n\
    \        std::vector<mint> xs, ys;\n        while (int(xs.size()) < n) {\n   \
    \         unsigned v = rng();\n            if (!used.insert(v).second) continue;\n\
    \            xs.push_back(v);\n            ys.push_back(eval(coef, v));\n    \
    \    }\n        for (int t = 0; t < 5; t++) {\n            mint c = rng();\n \
    \           assert(lagrange_interpolation(xs, ys, c) == eval(coef, c));\n    \
    \    }\n        for (int i = 0; i < n; i++) assert(lagrange_interpolation(xs,\
    \ ys, xs[i]) == ys[i]);\n    }\n    {\n        // n = 1: constant\n        std::vector<mint>\
    \ y{7};\n        assert(lagrange_interpolation(y, mint(123456789)) == 7);\n  \
    \      assert(lagrange_interpolation(std::vector<mint>{5}, y, mint(3)) == 7);\n\
    \    }\n    {\n        // sum of i^k, k = 3: n^2 (n+1)^2 / 4, with 1e5 points\
    \ for timing\n        int k = 3;\n        std::vector<mint> y(k + 2);\n      \
    \  for (int i = 1; i <= k + 1; i++) y[i] = y[i - 1] + mint(i).pow(k);\n      \
    \  long long n = 1000000000000000LL;\n        mint expect = mint(n) * mint(n)\
    \ * mint(n + 1) * mint(n + 1) / 4;\n        assert(lagrange_interpolation(y, mint(n))\
    \ == expect);\n        std::vector<mint> big(200000);\n        for (int i = 0;\
    \ i < 200000; i++) big[i] = rng();\n        lagrange_interpolation(big, mint(1000000));\n\
    \    }\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <atcoder/modint>\n#include <cassert>\n#include <iostream>\n#include\
    \ <random>\n#include <set>\n#include <vector>\n\n#include \"math/lagrange_interpolation.hpp\"\
    \nusing mint = atcoder::modint998244353;\nmint eval(const std::vector<mint>& coef,\
    \ mint c) {\n    mint r = 0;\n    for (int i = int(coef.size()) - 1; i >= 0; i--)\
    \ r = r * c + coef[i];\n    return r;\n}\nint main() {\n    std::mt19937 rng(665);\n\
    \    for (int it = 0; it < 500; it++) {\n        int deg = rng() % 8;\n      \
    \  std::vector<mint> coef(deg + 1);\n        for (auto& a : coef) a = rng();\n\
    \        int n = deg + 1 + rng() % 3;  // extra points are fine\n        std::vector<mint>\
    \ y(n);\n        for (int i = 0; i < n; i++) y[i] = eval(coef, i);\n        for\
    \ (int t = 0; t < 5; t++) {\n            mint c = rng();\n            assert(lagrange_interpolation(y,\
    \ c) == eval(coef, c));\n        }\n        for (int i = 0; i < n; i++) assert(lagrange_interpolation(y,\
    \ mint(i)) == y[i]);\n        assert(lagrange_interpolation(y, mint(n)) == eval(coef,\
    \ n));\n        // arbitrary distinct points\n        std::set<unsigned> used;\n\
    \        std::vector<mint> xs, ys;\n        while (int(xs.size()) < n) {\n   \
    \         unsigned v = rng();\n            if (!used.insert(v).second) continue;\n\
    \            xs.push_back(v);\n            ys.push_back(eval(coef, v));\n    \
    \    }\n        for (int t = 0; t < 5; t++) {\n            mint c = rng();\n \
    \           assert(lagrange_interpolation(xs, ys, c) == eval(coef, c));\n    \
    \    }\n        for (int i = 0; i < n; i++) assert(lagrange_interpolation(xs,\
    \ ys, xs[i]) == ys[i]);\n    }\n    {\n        // n = 1: constant\n        std::vector<mint>\
    \ y{7};\n        assert(lagrange_interpolation(y, mint(123456789)) == 7);\n  \
    \      assert(lagrange_interpolation(std::vector<mint>{5}, y, mint(3)) == 7);\n\
    \    }\n    {\n        // sum of i^k, k = 3: n^2 (n+1)^2 / 4, with 1e5 points\
    \ for timing\n        int k = 3;\n        std::vector<mint> y(k + 2);\n      \
    \  for (int i = 1; i <= k + 1; i++) y[i] = y[i - 1] + mint(i).pow(k);\n      \
    \  long long n = 1000000000000000LL;\n        mint expect = mint(n) * mint(n)\
    \ * mint(n + 1) * mint(n + 1) / 4;\n        assert(lagrange_interpolation(y, mint(n))\
    \ == expect);\n        std::vector<mint> big(200000);\n        for (int i = 0;\
    \ i < 200000; i++) big[i] = rng();\n        lagrange_interpolation(big, mint(1000000));\n\
    \    }\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - math/lagrange_interpolation.hpp
  - math/combinatorics.hpp
  isVerificationFile: true
  path: test/unit/lagrange_interpolation.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 12:32:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/lagrange_interpolation.test.cpp
layout: document
redirect_from:
- /verify/test/unit/lagrange_interpolation.test.cpp
- /verify/test/unit/lagrange_interpolation.test.cpp.html
title: test/unit/lagrange_interpolation.test.cpp
---
