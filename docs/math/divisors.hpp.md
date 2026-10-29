---
title: Divisors
documentation_of: math/divisors.hpp
---

### 概要
- 素因数分解から約数を列挙する。

### 使い方
- `divisors(factors)`: 素因数分解 `factors` が表す整数の約数を昇順に返す。`factors` は `factorize(n)` か `sieve::factorize(x)` の結果。

### 計算量
- $\mathcal{O}(d \log d)$、$d$ は約数の個数
