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
- `determinant(a)`: `matrix<T>` の `a` の行列式を返す。
- `inverse(a)`: `matrix<T>` の `a` の逆行列を返す。正則でなければ `std::nullopt`。
- `matrix_rank(a)`: `matrix<T>` の `a` の階数を返す。
- `solve_linear_system(a, b)`: $a x = b$ の解を `{x, kernel}` で返す。解全体は `x` $+$ `kernel` の線形結合で、`kernel` は $a x = 0$ の解空間の基底。解がなければ `std::nullopt`。

### 制約
- `pow`, `determinant`, `inverse`: `a` は正方行列
- `pow`: $0 \le k$
- `determinant`, `inverse`, `matrix_rank`, `solve_linear_system`: `T` は体
- `solve_linear_system`: $\lvert b \rvert = h$

### 計算量
- `a + b`: $\mathcal{O}(hw)$
- `a * b`: $\mathcal{O}(h w_a w_b)$
- `pow`: $\mathcal{O}(n^3 \log k)$
- `determinant`, `inverse`: $\mathcal{O}(n^3)$
- `matrix_rank`, `solve_linear_system`: $\mathcal{O}(h w \min(h, w))$
