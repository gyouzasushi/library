---
title: Linear Recurrence
documentation_of: math/linear_recurrence.hpp
---

### 概要
- 数列を満たす最短の線形漸化式を求め、その漸化式の第 $k$ 項を求める。

### 使い方
- `berlekamp_massey(a)`: $a_i = \sum_{j=1}^{d} c_{j} a_{i-j}$ ($d \le i < n$) が成り立つ最短の列 $c_1, \ldots, c_d$ を `{c[0], ..., c[d-1]}` で返す。
- `kth_term_of_linear_recurrence(a, c, k)`: 初項 $a_0, \ldots, a_{d-1}$ と漸化式 $a_i = \sum_{j=1}^{d} c_{j} a_{i-j}$ で定まる数列の $a_k$ を返す。

### 制約
- `mint` は `atcoder::static_modint<m>`
- $m$ は素数
- `berlekamp_massey`: $0 \le n$
- `kth_term_of_linear_recurrence`: $d \le \lvert a \rvert$、$0 \le k$、$2^c \mid (m - 1)$ かつ $2d + 1 \le 2^c$ なる $c$ が存在する

### 計算量
- `berlekamp_massey`: $\mathcal{O}(n^2)$
- `kth_term_of_linear_recurrence`: $\mathcal{O}(d \log d \log k)$
