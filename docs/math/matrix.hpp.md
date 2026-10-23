---
title: Matrix
documentation_of: math/matrix.hpp
---

### 概要
- 半環上の行列。

### 使い方
- `semiring_matrix<R>(h, w)`: 全要素が `zero()` の $h \times w$ 行列を作る。`R` は `S`, `add`, `zero`, `mul`, `one` を static メンバとして持つ構造体。
- `semiring_matrix<R>(v)`: `vector<vector<S>>` の `v` から行列を作る。
- `matrix<T>`: `semiring_matrix<semiring_plus_times<T>>` の別名。
- `e(n)`: $n \times n$ の単位行列を返す。
- `height()`, `width()`: 行数、列数を返す。
- `a[i][j]`: $(i, j)$ 成分。
- `a + b`, `a * b`, `a += b`, `a *= b`: 行列の和と積。
- `a.pow(k)`: $a^k$ を返す。
- `a == b`: 全成分が等しいかを返す。

### 制約
- `pow`: `a` は正方行列、$0 \le k$

### 計算量
- `a + b`: $\mathcal{O}(hw)$
- `a * b`: $\mathcal{O}(h w_a w_b)$
- `pow`: $\mathcal{O}(n^3 \log k)$
