---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/combinatorics.hpp
    title: Combinatorics
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/lagrange_interpolation.test.cpp
    title: test/unit/lagrange_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/lagrange_interpolation.hpp\"\n#include <cassert>\n\
    #include <vector>\n\n#line 4 \"math/combinatorics.hpp\"\ntemplate <typename mint>\n\
    struct combinatorics {\n    static mint fact(int n) {\n        ensure(n);\n  \
    \      return facts[n];\n    }\n    static mint fact_inv(int n) {\n        ensure(n);\n\
    \        return ifacts[n];\n    }\n    static mint inv(int n) {\n        assert(1\
    \ <= n);\n        ensure(n);\n        return ifacts[n] * facts[n - 1];\n    }\n\
    \    static mint C(int n, int k) {\n        if (n < 0 || n < k || k < 0) return\
    \ 0;\n        return fact(n) * fact_inv(n - k) * fact_inv(k);\n    }\n    static\
    \ mint P(int n, int k) {\n        if (n < 0 || n < k || k < 0) return 0;\n   \
    \     return fact(n) * fact_inv(n - k);\n    }\n    static mint H(int n, int k)\
    \ {\n        if (n < 0 || k < 0) return 0;\n        if (k == 0) return 1;\n  \
    \      return C(n + k - 1, k);\n    }\n    static void ensure(int n) {\n     \
    \   assert(n < mint::mod());\n        int sz = facts.size();\n        if (sz >\
    \ n) return;\n        if (n < sz << 1) n = std::min(mint::mod() - 1, sz << 1);\n\
    \        facts.resize(n + 1);\n        ifacts.resize(n + 1);\n        for (int\
    \ i = sz; i <= n; i++) facts[i] = facts[i - 1] * i;\n        ifacts[n] = facts[n].inv();\n\
    \        for (int i = n; i >= sz; i--) ifacts[i - 1] = ifacts[i] * i;\n    }\n\
    \nprivate:\n    static inline std::vector<mint> facts{1};\n    static inline std::vector<mint>\
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
    \    ret += y[i] * num / den;\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\n#include \"math/combinatorics.hpp\"\
    \ntemplate <class mint> mint lagrange_interpolation(const std::vector<mint>& y,\
    \ mint c) {\n    int n = int(y.size());\n    assert(n >= 1);\n    long long cv\
    \ = c.val();\n    if (cv < n) return y[cv];\n    std::vector<mint> pre(n + 1,\
    \ 1), suf(n + 1, 1);\n    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] * (c\
    \ - i);\n    for (int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] * (c - i);\n\
    \    using comb = combinatorics<mint>;\n    mint ret = 0;\n    for (int i = 0;\
    \ i < n; i++) {\n        mint t = y[i] * pre[i] * suf[i + 1] * comb::fact_inv(i)\
    \ * comb::fact_inv(n - 1 - i);\n        ret += (n - 1 - i) & 1 ? -t : t;\n   \
    \ }\n    return ret;\n}\ntemplate <class mint>\nmint lagrange_interpolation(const\
    \ std::vector<mint>& x, const std::vector<mint>& y, mint c) {\n    int n = int(x.size());\n\
    \    assert(n >= 1 && int(y.size()) == n);\n    mint ret = 0;\n    for (int i\
    \ = 0; i < n; i++) {\n        mint num = 1, den = 1;\n        for (int j = 0;\
    \ j < n; j++) {\n            if (j == i) continue;\n            assert(x[i] !=\
    \ x[j]);\n            num *= c - x[j];\n            den *= x[i] - x[j];\n    \
    \    }\n        ret += y[i] * num / den;\n    }\n    return ret;\n}\n"
  dependsOn:
  - math/combinatorics.hpp
  isVerificationFile: false
  path: math/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2026-10-27 12:32:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/lagrange_interpolation.test.cpp
  - test/yukicoder/665.test.cpp
documentation_of: math/lagrange_interpolation.hpp
layout: document
title: Lagrange Interpolation
---

### 概要
- 標本点を通る多項式の値を求める。

### 使い方
- `lagrange_interpolation(y, c)`: $f(i) = $ `y[i]` ($0 \le i < n$) となる次数 $n - 1$ 以下の多項式 $f$ について $f(c)$ を返す。
- `lagrange_interpolation(x, y, c)`: $f($ `x[i]` $) = $ `y[i]` ($0 \le i < n$) となる次数 $n - 1$ 以下の多項式 $f$ について $f(c)$ を返す。

### 制約
- `mint` は `atcoder::static_modint<m>` または `atcoder::dynamic_modint<id>`
- $m$ は素数
- $1 \le n < m$
- `lagrange_interpolation(x, y, c)`: `x` の要素は相異なる

### 計算量
- `lagrange_interpolation(y, c)`: $\mathcal{O}(n)$
- `lagrange_interpolation(x, y, c)`: $\mathcal{O}(n^2)$
