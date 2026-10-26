---
title: Bitwise And Convolution
documentation_of: math/bitwise_and_convolution.hpp
---

### 概要
- 添字の bitwise AND についての畳み込みを求める。

### 使い方
- `bitwise_and_convolution(a, b)`: $c_k = \displaystyle \sum_{i \mathbin{\&} j = k} a_i b_j$ となる数列 `c` を返す。

### 制約
- $\lvert a \rvert = \lvert b \rvert = 2^n$ ($0 \le n$)

### 計算量
- $\mathcal{O}(2^n n)$
