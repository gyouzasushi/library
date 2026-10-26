---
title: Cumulative Sum
documentation_of: datastructure/cumulative_sum.hpp
---

### 概要
- 数列の区間和を答える。

### 使い方
- `cumulative_sum<T>(a)`: 数列 `a` で構築する。
- `sum(l, r)`: $a_l + a_{l+1} + \cdots + a_{r-1}$ を返す。

### 制約
- $0 \le l \le r \le n$

### 計算量
- 構築: $\mathcal{O}(n)$
- `sum`: $\mathcal{O}(1)$
