---
title: Bitwise Or Convolution
documentation_of: math/bitwise_or_convolution.hpp
---

### 使い方
- `bitwise_or_convolution(a, b)`: $c_k = \displaystyle \sum_{i\|j=k}a_ib_j$ となる数列 `c` を求める。

### 制約
- ある非負整数 $n$ が存在して $\|a\|=\|b\|=2^n$ 。