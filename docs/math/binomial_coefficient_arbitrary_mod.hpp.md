---
title: Binomial Coefficient (Arbitrary Mod)
documentation_of: math/binomial_coefficient_arbitrary_mod.hpp
---

### 概要
- 二項係数 $\binom{n}{k} \bmod m$ を求める。

### 使い方
- `binomial_coefficient_arbitrary_mod<id = -1>`: `id` ごとに mod を持つ。
- `set_mod(m)`: mod を $m$ に設定する。
- `C(n, k)`: $\binom{n}{k} \bmod m$ を返す。

### 制約
- $1 \le m \le 10^9$
- $0 \le n, k \le 10^{18}$

### 計算量
- `set_mod`: $\mathcal{O}(m^{1/4})$
- `C`: 前計算 $\mathcal{O}(\min(n, m))$、クエリ $\mathcal{O}(\log n)$
