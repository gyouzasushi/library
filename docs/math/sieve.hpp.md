---
title: Sieve
documentation_of: math/sieve.hpp
---

### 概要
- $n$ 以下の整数の最小素因数表を作り、素数判定と素因数分解をする。

### 使い方
- `sieve(n)`: $n$ 以下の最小素因数表を作る。
- `is_prime(x)`: $x$ が素数かを返す。
- `smallest_prime_factor(x)`: $x$ の最小の素因数を返す。
- `primes()`: $n$ 以下の素数を昇順に返す。
- `factorize(x)`: $x$ の素因数分解を (素因数, 指数) の列で返す。素因数の昇順。

### 制約
- $1 \le n$
- `is_prime`: $0 \le x \le n$
- `smallest_prime_factor`: $2 \le x \le n$
- `factorize`: $1 \le x \le n$

### 計算量
- `sieve(n)`: $\mathcal{O}(n)$
- `is_prime`, `smallest_prime_factor`, `primes`: $\mathcal{O}(1)$
- `factorize`: $\mathcal{O}(\log x)$
