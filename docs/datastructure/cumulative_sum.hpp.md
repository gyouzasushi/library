---
title: 累積和
documentation_of: datastructure/cumulative_sum.hpp
---

### 概要
累積和を前計算することで区間和を高速に計算する。
### 使い方
- `CumulativeSum(d)`: 数列 $\mathrm d$ で初期化する。
- `sum(l, r)`: $\mathrm d_l + \mathrm d_{l+1} + \cdots +\mathrm d_{r-1}$ を求める。
### 計算量
- `CumulativeSum(d)`: $\mathcal O(N)$
- `sum(l, r)`: $\mathcal O(1)$