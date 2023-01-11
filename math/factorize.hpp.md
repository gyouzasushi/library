---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/factorize.test.cpp
    title: test/library-checker/factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/factorize.hpp\"\n#include <random>\n\nlong long modmul(long\
    \ long x, long long y, long long mod) {\n    using i128 = __int128_t;\n    return\
    \ (long long)(i128(x) * i128(y) % i128(mod));\n}\nlong long modpow(long long a,\
    \ long long n, long long mod) {\n    long long ret = 1;\n    while (n > 0) {\n\
    \        if (n & 1) ret = modmul(ret, a, mod);\n        a = modmul(a, a, mod);\n\
    \        n >>= 1;\n    }\n    return ret;\n}\nlong long rho(long long n) {\n \
    \   std::random_device seed_gen;\n    std::mt19937_64 rnd(seed_gen());\n    auto\
    \ f = [&](long long x) -> long long {\n        long long ret = modmul(x, x, n)\
    \ + 1;\n        if (ret == n) return 0;\n        return ret;\n    };\n    while\
    \ (true) {\n        long long x = std::uniform_int_distribution<long long>(0,\
    \ 1000)(rnd);\n        long long y = f(x);\n        while (true) {\n         \
    \   long long d = std::gcd(std::abs(x - y), n);\n            if (d == n) break;\n\
    \            if (d > 1) return d;\n            x = f(x);\n            y = f(f(y));\n\
    \        }\n    }\n}\nbool miller_rabin(long long n) {\n    if (n == 1) return\
    \ 0;\n    long long d = n - 1, s = 0;\n    while (~d & 1) d >>= 1, s++;\n    auto\
    \ check = [&](long long a) -> bool {\n        long long x = modpow(a, d, n);\n\
    \        if (x == 1) return 1;\n        long long y = n - 1;\n        for (int\
    \ i = 0; i < s; i++) {\n            if (x == y) return true;\n            x =\
    \ modmul(x, x, n);\n        }\n        return false;\n    };\n    for (long long\
    \ a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {\n        if (a >= n) break;\n\
    \        if (!check(a)) return false;\n    }\n    return true;\n}\n#include <map>\n\
    #include <queue>\nstd::map<long long, int> factorize(long long n) {\n    std::map<long\
    \ long, int> ret;\n    while (~n & 1) n >>= 1, ret[2]++;\n    std::queue<long\
    \ long> q;\n    q.push(n);\n    while (!q.empty()) {\n        long long p = q.front();\n\
    \        q.pop();\n        if (p == 1) continue;\n        if (miller_rabin(p))\
    \ {\n            ret[p]++;\n            continue;\n        }\n        long long\
    \ d = rho(p);\n        q.push(d);\n        q.push(p / d);\n    }\n    return ret;\n\
    }\n"
  code: "#pragma once\n#include <random>\n\nlong long modmul(long long x, long long\
    \ y, long long mod) {\n    using i128 = __int128_t;\n    return (long long)(i128(x)\
    \ * i128(y) % i128(mod));\n}\nlong long modpow(long long a, long long n, long\
    \ long mod) {\n    long long ret = 1;\n    while (n > 0) {\n        if (n & 1)\
    \ ret = modmul(ret, a, mod);\n        a = modmul(a, a, mod);\n        n >>= 1;\n\
    \    }\n    return ret;\n}\nlong long rho(long long n) {\n    std::random_device\
    \ seed_gen;\n    std::mt19937_64 rnd(seed_gen());\n    auto f = [&](long long\
    \ x) -> long long {\n        long long ret = modmul(x, x, n) + 1;\n        if\
    \ (ret == n) return 0;\n        return ret;\n    };\n    while (true) {\n    \
    \    long long x = std::uniform_int_distribution<long long>(0, 1000)(rnd);\n \
    \       long long y = f(x);\n        while (true) {\n            long long d =\
    \ std::gcd(std::abs(x - y), n);\n            if (d == n) break;\n            if\
    \ (d > 1) return d;\n            x = f(x);\n            y = f(f(y));\n       \
    \ }\n    }\n}\nbool miller_rabin(long long n) {\n    if (n == 1) return 0;\n \
    \   long long d = n - 1, s = 0;\n    while (~d & 1) d >>= 1, s++;\n    auto check\
    \ = [&](long long a) -> bool {\n        long long x = modpow(a, d, n);\n     \
    \   if (x == 1) return 1;\n        long long y = n - 1;\n        for (int i =\
    \ 0; i < s; i++) {\n            if (x == y) return true;\n            x = modmul(x,\
    \ x, n);\n        }\n        return false;\n    };\n    for (long long a : {2,\
    \ 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {\n        if (a >= n) break;\n  \
    \      if (!check(a)) return false;\n    }\n    return true;\n}\n#include <map>\n\
    #include <queue>\nstd::map<long long, int> factorize(long long n) {\n    std::map<long\
    \ long, int> ret;\n    while (~n & 1) n >>= 1, ret[2]++;\n    std::queue<long\
    \ long> q;\n    q.push(n);\n    while (!q.empty()) {\n        long long p = q.front();\n\
    \        q.pop();\n        if (p == 1) continue;\n        if (miller_rabin(p))\
    \ {\n            ret[p]++;\n            continue;\n        }\n        long long\
    \ d = rho(p);\n        q.push(d);\n        q.push(p / d);\n    }\n    return ret;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/factorize.hpp
  requiredBy: []
  timestamp: '2023-01-11 13:15:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/factorize.test.cpp
documentation_of: math/factorize.hpp
layout: document
redirect_from:
- /library/math/factorize.hpp
- /library/math/factorize.hpp.html
title: math/factorize.hpp
---
