---
title: Bostan-Mori
documentation_of: math/bostan_mori.hpp
---

### 概要
- 有理関数 $P(x) / Q(x)$ の $x^n$ の係数を求める。

### 使い方
- `bostan_mori<mint>(n, p, q)`: $[x^n] \dfrac{p_0 + p_1 x + \cdots}{q_0 + q_1 x + \cdots}$ を返す。

### 制約
- $0 \le n$
- $q_0 \ne 0$
- `mint` は `atcoder::static_modint<m>`
- $m$ は素数
- $2^c \mid (m - 1)$ かつ $\lvert p \rvert + \lvert q \rvert - 1 \le 2^c$ なる $c$ が存在する

### 計算量
- $d = \lvert p \rvert + \lvert q \rvert$ として $\mathcal{O}(d \log d \log n)$
