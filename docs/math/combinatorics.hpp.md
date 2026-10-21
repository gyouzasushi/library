---
title: Combinatorics
documentation_of: math/combinatorics.hpp
---

### 概要
- 階乗と二項係数を $\bmod p$ で求める。

### 使い方
- `combinatorics<mint>`: 全て static メンバ。
- `fact(n)`: $n!$ を返す。
- `fact_inv(n)`: $1 / n!$ を返す。
- `inv(n)`: $1 / n$ を返す。
- `C(n, k)`: $\binom{n}{k}$ を返す。
- `P(n, k)`: ${}_n \mathrm{P}_k$ を返す。
- `H(n, k)`: ${}_n \mathrm{H}_k$ を返す。
- `ensure(n)`: 階乗のテーブルを $n$ まで構築する。

### 制約
- `mint::mod()` は素数
- $0 \le n <$ `mint::mod()`

### 計算量
- 前計算 $\mathcal{O}(n)$、クエリ $\mathcal{O}(1)$
