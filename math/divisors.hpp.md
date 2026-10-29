---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/sieve.test.cpp
    title: test/unit/sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/divisors.hpp\"\n#include <algorithm>\n#include <utility>\n\
    #include <vector>\ntemplate <class T>\nstd::vector<T> divisors(const std::vector<std::pair<T,\
    \ int>>& factors) {\n    std::vector<T> ret = {1};\n    for (auto [p, e] : factors)\
    \ {\n        int sz = int(ret.size());\n        T q = 1;\n        for (int i =\
    \ 0; i < e; i++) {\n            q *= p;\n            for (int j = 0; j < sz; j++)\
    \ ret.push_back(ret[j] * q);\n        }\n    }\n    std::ranges::sort(ret);\n\
    \    return ret;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    template <class T>\nstd::vector<T> divisors(const std::vector<std::pair<T, int>>&\
    \ factors) {\n    std::vector<T> ret = {1};\n    for (auto [p, e] : factors) {\n\
    \        int sz = int(ret.size());\n        T q = 1;\n        for (int i = 0;\
    \ i < e; i++) {\n            q *= p;\n            for (int j = 0; j < sz; j++)\
    \ ret.push_back(ret[j] * q);\n        }\n    }\n    std::ranges::sort(ret);\n\
    \    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/divisors.hpp
  requiredBy: []
  timestamp: '2026-10-29 21:49:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/sieve.test.cpp
documentation_of: math/divisors.hpp
layout: document
title: Divisors
---

### 概要
- 素因数分解から約数を列挙する。

### 使い方
- `divisors(factors)`: 素因数分解 `factors` が表す整数の約数を昇順に返す。`factors` は `factorize(n)` か `sieve::factorize(x)` の結果。

### 計算量
- $\mathcal{O}(d \log d)$、$d$ は約数の個数
