---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/binomial_coefficient_arbitrary_mod.hpp
    title: Binomial Coefficient (Arbitrary Mod)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/binomial_coefficient.test.cpp
    title: test/library-checker/binomial_coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/factorize.test.cpp
    title: test/library-checker/factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/factorize.hpp\"\n#include <cassert>\n#include <cstdlib>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n\nnamespace internal {\n\
    \nlong long modmul(long long x, long long y, long long mod) {\n    return (long\
    \ long)((__int128_t)x * y % mod);\n}\n\nlong long modpow(long long a, long long\
    \ n, long long mod) {\n    long long ret = 1;\n    while (n > 0) {\n        if\
    \ (n & 1) ret = modmul(ret, a, mod);\n        a = modmul(a, a, mod);\n       \
    \ n >>= 1;\n    }\n    return ret;\n}\n\nlong long rho(long long n) {\n    long\
    \ long z = 0;\n    auto f = [&](long long x) {\n        long long ret = modmul(x,\
    \ x, n) + z;\n        return ret >= n ? ret - n : ret;\n    };\n    while (true)\
    \ {\n        long long x = ++z;\n        long long y = f(x);\n        while (true)\
    \ {\n            long long d = std::gcd(std::abs(x - y), n);\n            if (d\
    \ == n) break;\n            if (d > 1) return d;\n            x = f(x);\n    \
    \        y = f(f(y));\n        }\n    }\n}\n\n}  // namespace internal\n\nbool\
    \ is_prime(long long n) {\n    assert(n >= 1);\n    if (n == 1) return false;\n\
    \    if (n % 2 == 0) return n == 2;\n    long long d = n - 1, s = 0;\n    while\
    \ (~d & 1) d >>= 1, s++;\n    for (long long a : {2, 3, 5, 7, 11, 13, 17, 19,\
    \ 23, 29, 31, 37}) {\n        if (a >= n) break;\n        long long x = internal::modpow(a,\
    \ d, n);\n        if (x == 1) continue;\n        bool ok = false;\n        for\
    \ (int i = 0; i < s; i++) {\n            if (x == n - 1) {\n                ok\
    \ = true;\n                break;\n            }\n            x = internal::modmul(x,\
    \ x, n);\n        }\n        if (!ok) return false;\n    }\n    return true;\n\
    }\n\nstd::map<long long, int> factorize(long long n) {\n    assert(n >= 1);\n\
    \    std::map<long long, int> ret;\n    while (~n & 1) n >>= 1, ret[2]++;\n  \
    \  std::queue<long long> q;\n    q.push(n);\n    while (!q.empty()) {\n      \
    \  long long p = q.front();\n        q.pop();\n        if (p == 1) continue;\n\
    \        if (is_prime(p)) {\n            ret[p]++;\n            continue;\n  \
    \      }\n        long long d = internal::rho(p);\n        q.push(d);\n      \
    \  q.push(p / d);\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdlib>\n#include <map>\n#include\
    \ <numeric>\n#include <queue>\n\nnamespace internal {\n\nlong long modmul(long\
    \ long x, long long y, long long mod) {\n    return (long long)((__int128_t)x\
    \ * y % mod);\n}\n\nlong long modpow(long long a, long long n, long long mod)\
    \ {\n    long long ret = 1;\n    while (n > 0) {\n        if (n & 1) ret = modmul(ret,\
    \ a, mod);\n        a = modmul(a, a, mod);\n        n >>= 1;\n    }\n    return\
    \ ret;\n}\n\nlong long rho(long long n) {\n    long long z = 0;\n    auto f =\
    \ [&](long long x) {\n        long long ret = modmul(x, x, n) + z;\n        return\
    \ ret >= n ? ret - n : ret;\n    };\n    while (true) {\n        long long x =\
    \ ++z;\n        long long y = f(x);\n        while (true) {\n            long\
    \ long d = std::gcd(std::abs(x - y), n);\n            if (d == n) break;\n   \
    \         if (d > 1) return d;\n            x = f(x);\n            y = f(f(y));\n\
    \        }\n    }\n}\n\n}  // namespace internal\n\nbool is_prime(long long n)\
    \ {\n    assert(n >= 1);\n    if (n == 1) return false;\n    if (n % 2 == 0) return\
    \ n == 2;\n    long long d = n - 1, s = 0;\n    while (~d & 1) d >>= 1, s++;\n\
    \    for (long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {\n    \
    \    if (a >= n) break;\n        long long x = internal::modpow(a, d, n);\n  \
    \      if (x == 1) continue;\n        bool ok = false;\n        for (int i = 0;\
    \ i < s; i++) {\n            if (x == n - 1) {\n                ok = true;\n \
    \               break;\n            }\n            x = internal::modmul(x, x,\
    \ n);\n        }\n        if (!ok) return false;\n    }\n    return true;\n}\n\
    \nstd::map<long long, int> factorize(long long n) {\n    assert(n >= 1);\n   \
    \ std::map<long long, int> ret;\n    while (~n & 1) n >>= 1, ret[2]++;\n    std::queue<long\
    \ long> q;\n    q.push(n);\n    while (!q.empty()) {\n        long long p = q.front();\n\
    \        q.pop();\n        if (p == 1) continue;\n        if (is_prime(p)) {\n\
    \            ret[p]++;\n            continue;\n        }\n        long long d\
    \ = internal::rho(p);\n        q.push(d);\n        q.push(p / d);\n    }\n   \
    \ return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/factorize.hpp
  requiredBy:
  - math/binomial_coefficient_arbitrary_mod.hpp
  timestamp: '2026-10-25 13:51:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/binomial_coefficient.test.cpp
  - test/library-checker/factorize.test.cpp
documentation_of: math/factorize.hpp
layout: document
title: Factorize
---

### 概要
- 整数を素因数分解する。

### 使い方
- `is_prime(n)`: $n$ が素数かを返す。
- `factorize(n)`: $n$ の素因数分解を返す。素因数をキー、その指数を値とする map。

### 制約
- $1 \le n < 2^{63}$

### 計算量
- `is_prime`: $\mathcal{O}(\log n)$
- `factorize`: 期待 $\mathcal{O}(n^{1/4} \log n)$
