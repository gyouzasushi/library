---
title: Factorize
documentation_of: math/factorize.hpp
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
