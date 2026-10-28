---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_A.test.cpp
    title: test/aoj/NTL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/enumerate_primes.test.cpp
    title: test/library-checker/enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/sieve.test.cpp
    title: test/unit/sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/sieve.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <utility>\n#include <vector>\nstruct sieve {\npublic:\n    sieve() :\
    \ sieve(1) {\n    }\n    explicit sieve(int n) : _n(n), lpf(n + 1, 0) {\n    \
    \    assert(n >= 1);\n        for (int i = 2; i <= n; i++) {\n            if (lpf[i]\
    \ == 0) {\n                lpf[i] = i;\n                _primes.push_back(i);\n\
    \            }\n            for (int p : _primes) {\n                if (p > lpf[i]\
    \ || (long long)p * i > n) break;\n                lpf[p * i] = p;\n         \
    \   }\n        }\n    }\n    bool is_prime(int x) const {\n        assert(0 <=\
    \ x && x <= _n);\n        return x >= 2 && lpf[x] == x;\n    }\n    int smallest_prime_factor(int\
    \ x) const {\n        assert(2 <= x && x <= _n);\n        return lpf[x];\n   \
    \ }\n    const std::vector<int>& primes() const {\n        return _primes;\n \
    \   }\n    std::vector<std::pair<int, int>> factorize(int x) const {\n       \
    \ assert(1 <= x && x <= _n);\n        std::vector<std::pair<int, int>> ret;\n\
    \        while (x > 1) {\n            int p = lpf[x];\n            if (!ret.empty()\
    \ && ret.back().first == p) {\n                ret.back().second++;\n        \
    \    } else {\n                ret.emplace_back(p, 1);\n            }\n      \
    \      x /= p;\n        }\n        return ret;\n    }\n    std::vector<int> divisors(int\
    \ x) const {\n        assert(1 <= x && x <= _n);\n        std::vector<int> ret\
    \ = {1};\n        for (auto [p, e] : factorize(x)) {\n            int sz = int(ret.size());\n\
    \            int q = 1;\n            for (int i = 0; i < e; i++) {\n         \
    \       q *= p;\n                for (int j = 0; j < sz; j++) ret.push_back(ret[j]\
    \ * q);\n            }\n        }\n        std::sort(ret.begin(), ret.end());\n\
    \        return ret;\n    }\n\nprivate:\n    int _n;\n    std::vector<int> lpf,\
    \ _primes;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\nstruct sieve {\npublic:\n    sieve() : sieve(1) {\n    }\n\
    \    explicit sieve(int n) : _n(n), lpf(n + 1, 0) {\n        assert(n >= 1);\n\
    \        for (int i = 2; i <= n; i++) {\n            if (lpf[i] == 0) {\n    \
    \            lpf[i] = i;\n                _primes.push_back(i);\n            }\n\
    \            for (int p : _primes) {\n                if (p > lpf[i] || (long\
    \ long)p * i > n) break;\n                lpf[p * i] = p;\n            }\n   \
    \     }\n    }\n    bool is_prime(int x) const {\n        assert(0 <= x && x <=\
    \ _n);\n        return x >= 2 && lpf[x] == x;\n    }\n    int smallest_prime_factor(int\
    \ x) const {\n        assert(2 <= x && x <= _n);\n        return lpf[x];\n   \
    \ }\n    const std::vector<int>& primes() const {\n        return _primes;\n \
    \   }\n    std::vector<std::pair<int, int>> factorize(int x) const {\n       \
    \ assert(1 <= x && x <= _n);\n        std::vector<std::pair<int, int>> ret;\n\
    \        while (x > 1) {\n            int p = lpf[x];\n            if (!ret.empty()\
    \ && ret.back().first == p) {\n                ret.back().second++;\n        \
    \    } else {\n                ret.emplace_back(p, 1);\n            }\n      \
    \      x /= p;\n        }\n        return ret;\n    }\n    std::vector<int> divisors(int\
    \ x) const {\n        assert(1 <= x && x <= _n);\n        std::vector<int> ret\
    \ = {1};\n        for (auto [p, e] : factorize(x)) {\n            int sz = int(ret.size());\n\
    \            int q = 1;\n            for (int i = 0; i < e; i++) {\n         \
    \       q *= p;\n                for (int j = 0; j < sz; j++) ret.push_back(ret[j]\
    \ * q);\n            }\n        }\n        std::sort(ret.begin(), ret.end());\n\
    \        return ret;\n    }\n\nprivate:\n    int _n;\n    std::vector<int> lpf,\
    \ _primes;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/sieve.hpp
  requiredBy: []
  timestamp: '2026-10-26 01:59:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/sieve.test.cpp
  - test/library-checker/enumerate_primes.test.cpp
  - test/aoj/NTL_1_A.test.cpp
documentation_of: math/sieve.hpp
layout: document
title: Sieve
---

### 概要
- $n$ 以下の整数の最小素因数表を作り、素数判定・素因数分解・約数列挙をする。

### 使い方
- `sieve(n)`: $n$ 以下の最小素因数表を作る。
- `is_prime(x)`: $x$ が素数かを返す。
- `smallest_prime_factor(x)`: $x$ の最小の素因数を返す。
- `primes()`: $n$ 以下の素数を昇順に返す。
- `factorize(x)`: $x$ の素因数分解を (素因数, 指数) の列で返す。素因数の昇順。
- `divisors(x)`: $x$ の約数を昇順に返す。

### 制約
- $1 \le n$
- `is_prime`: $0 \le x \le n$
- `smallest_prime_factor`: $2 \le x \le n$
- `factorize`, `divisors`: $1 \le x \le n$

### 計算量
- `sieve(n)`: $\mathcal{O}(n)$
- `is_prime`, `smallest_prime_factor`, `primes`: $\mathcal{O}(1)$
- `factorize`: $\mathcal{O}(\log x)$
- `divisors`: $\mathcal{O}(d(x) \log d(x))$
