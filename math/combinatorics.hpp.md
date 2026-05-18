---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/binomial_coefficient_prime_mod.test.cpp
    title: test/library-checker/binomial_coefficient_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/117.test.cpp
    title: test/yukicoder/117.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/combinatorics.hpp\"\n#include <vector>\ntemplate <typename\
    \ mint>\nstruct combinatorics {\n    static mint val(int i) {\n        ensure(i);\n\
    \        return facts[i];\n    }\n    static mint inv(int i) {\n        ensure(i);\n\
    \        return ifacts[i];\n    }\n    static mint C(int n, int k) {\n       \
    \ if (n < 0 || n < k || k < 0) return 0;\n        return val(n) * inv(n - k) *\
    \ inv(k);\n    }\n    static mint P(int n, int k) {\n        if (n < 0 || n <\
    \ k || k < 0) return 0;\n        return val(n) * inv(n - k);\n    }\n    static\
    \ mint H(int n, int k) {\n        if (n < 0 || k < 0) return 0;\n        if (k\
    \ == 0) return 1;\n        return C(n + k - 1, k);\n    }\n    static void ensure(int\
    \ n) {\n        int sz = facts.size();\n        if (sz > n) return;\n        if\
    \ (n < sz << 1) n = std::min(mint::mod() - 1, sz << 1);\n        facts.resize(n\
    \ + 1);\n        ifacts.resize(n + 1);\n        for (int i = sz; i <= n; i++)\
    \ facts[i] = facts[i - 1] * i;\n        ifacts[n] = facts[n].inv();\n        for\
    \ (int i = n; i >= sz; i--) ifacts[i - 1] = ifacts[i] * i;\n    }\n\nprivate:\n\
    \    static inline std::vector<mint> facts{1};\n    static inline std::vector<mint>\
    \ ifacts{1};\n};\n"
  code: "#pragma once\n#include <vector>\ntemplate <typename mint>\nstruct combinatorics\
    \ {\n    static mint val(int i) {\n        ensure(i);\n        return facts[i];\n\
    \    }\n    static mint inv(int i) {\n        ensure(i);\n        return ifacts[i];\n\
    \    }\n    static mint C(int n, int k) {\n        if (n < 0 || n < k || k < 0)\
    \ return 0;\n        return val(n) * inv(n - k) * inv(k);\n    }\n    static mint\
    \ P(int n, int k) {\n        if (n < 0 || n < k || k < 0) return 0;\n        return\
    \ val(n) * inv(n - k);\n    }\n    static mint H(int n, int k) {\n        if (n\
    \ < 0 || k < 0) return 0;\n        if (k == 0) return 1;\n        return C(n +\
    \ k - 1, k);\n    }\n    static void ensure(int n) {\n        int sz = facts.size();\n\
    \        if (sz > n) return;\n        if (n < sz << 1) n = std::min(mint::mod()\
    \ - 1, sz << 1);\n        facts.resize(n + 1);\n        ifacts.resize(n + 1);\n\
    \        for (int i = sz; i <= n; i++) facts[i] = facts[i - 1] * i;\n        ifacts[n]\
    \ = facts[n].inv();\n        for (int i = n; i >= sz; i--) ifacts[i - 1] = ifacts[i]\
    \ * i;\n    }\n\nprivate:\n    static inline std::vector<mint> facts{1};\n   \
    \ static inline std::vector<mint> ifacts{1};\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/combinatorics.hpp
  requiredBy: []
  timestamp: '2026-05-18 11:49:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/117.test.cpp
  - test/library-checker/binomial_coefficient_prime_mod.test.cpp
documentation_of: math/combinatorics.hpp
layout: document
title: Combinatorics
---

### 概要
- 階乗・逆階乗をキャッシュしながら二項係数・順列・重複組合せを計算するデータ構造。
- 素数 mod の `mint` に対応。

### 使い方
- `combinatorics<mint>`: 型 `mint` 上で動く。全 static。
- `val(i)`: $i!$ を返す。
- `inv(i)`: $1 / i!$ を返す。
- `C(n, k)`: $\binom{n}{k}$ を返す。
- `P(n, k)`: ${}_nP_k = n! / (n-k)!$ を返す。
- `H(n, k)`: ${}_nH_k = \binom{n+k-1}{k}$（重複組合せ）を返す。
- `ensure(n)`: 階乗テーブルを少なくとも $n$ まで構築する。

### 呼び出しを短縮するイディオム
`combinatorics<mint>::C(n, k)` が長いと感じる場合、関数参照に束ねると call site が短くなる。

```cpp
using mint = atcoder::modint998244353;
using combi = combinatorics<mint>;
constexpr auto& C = combi::C;
constexpr auto& P = combi::P;
constexpr auto& H = combi::H;

// 以降は単に
mint x = C(n, k);
```
