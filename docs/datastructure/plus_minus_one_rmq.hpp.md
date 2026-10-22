---
title: Plus Minus One RMQ
documentation_of: datastructure/plus_minus_one_rmq.hpp
---

### 概要
- 隣接要素の差が $\pm 1$ の配列の区間最小値の位置を求める。

### 使い方
- `plus_minus_one_rmq(a)`: 配列 `a` で構築する。
- `prod(l, r)`: `a[l], ..., a[r - 1]` の最小値の添字を返す。複数あれば最小の添字。

### 制約
- $|a_i - a_{i+1}| = 1$
- $0 \le l < r \le n$

### 計算量
- 構築: $\mathcal{O}(N)$
- `prod`: $\mathcal{O}(1)$
