---
title: Combinatorics
documentation_of: math/combinatorics.hpp
---

### 概要
- 階乗・逆階乗をキャッシュしながら二項係数・順列・重複組合せを計算するデータ構造。
- 素数 mod の `mint` に対応。

### 使い方
- `combinatorics<mint>`: 型 `mint` 上で動く。全 static。
- `fact(n)`: $n!$ を返す。
- `fact_inv(n)`: $1 / n!$ を返す。
- `inv(n)`: $1 / n$ を返す。
- `C(n, k)`: $\binom{n}{k}$ を返す。
- `P(n, k)`: ${}_nP_k = n! / (n-k)!$ を返す。
- `H(n, k)`: ${}_nH_k = \binom{n+k-1}{k}$（重複組合せ）を返す。
- `ensure(n)`: 階乗テーブルを少なくとも $n$ まで構築する。$n$ は `mint::mod()` 未満。
