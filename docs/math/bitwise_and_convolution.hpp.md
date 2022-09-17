---
title: Bitwise And Convolution
documentation_of: math/bitwise_and_convolution.hpp
---

### 使い方
- `bitwise_and_convolution(a, b)`: $c_k = \displaystyle \sum_{i\&j=k}a_ib_j$ となる数列 `c` を求める。

### 制約
- ある非負整数 $n$ が存在して $\|a\|=\|b\|=2^n$ 。