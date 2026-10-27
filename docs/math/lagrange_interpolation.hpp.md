---
title: Lagrange Interpolation
documentation_of: math/lagrange_interpolation.hpp
---

### 概要
- 標本点を通る多項式の値を求める。

### 使い方
- `lagrange_interpolation(y, c)`: $f(i) = $ `y[i]` ($0 \le i < n$) となる次数 $n - 1$ 以下の多項式 $f$ について $f(c)$ を返す。
- `lagrange_interpolation(x, y, c)`: $f($ `x[i]` $) = $ `y[i]` ($0 \le i < n$) となる次数 $n - 1$ 以下の多項式 $f$ について $f(c)$ を返す。

### 制約
- `mint` は `atcoder::static_modint<m>` または `atcoder::dynamic_modint<id>`
- $m$ は素数
- $1 \le n < m$
- `lagrange_interpolation(x, y, c)`: `x` の要素は相異なる

### 計算量
- `lagrange_interpolation(y, c)`: $\mathcal{O}(n)$
- `lagrange_interpolation(x, y, c)`: $\mathcal{O}(n^2)$
