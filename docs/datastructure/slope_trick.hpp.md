---
title: Slope Trick
documentation_of: datastructure/slope_trick.hpp
---

### 概要
- 傾きが整数ずつ変わる凸な区分線形関数 $f(x)$ を折れ点の集合で持ち、関数への演算と最小値の取得を行う。

### 使い方
- `slope_trick<T>()`: $f(x) = 0$ を作る。`T` は $x$ と $f(x)$ の型。
- `min()`: $\min_x f(x)$ を返す。
- `argmin()`: $f(x)$ が最小になる $x$ の区間 $[l, r]$ を `pair<optional<T>, optional<T>>` で返す。区間が左右に有界でない側は `std::nullopt`。
- `add(a)`: $f(x) \gets f(x) + a$ とする。
- `add_x_minus_a(a)`: $f(x) \gets f(x) + \max(0, x - a)$ とする。
- `add_a_minus_x(a)`: $f(x) \gets f(x) + \max(0, a - x)$ とする。
- `add_abs(a)`: $f(x) \gets f(x) + \lvert x - a \rvert$ とする。
- `prefix_min()`: $f(x) \gets \min_{y \le x} f(y)$ とする。
- `suffix_min()`: $f(x) \gets \min_{y \ge x} f(y)$ とする。
- `shift(a)`: $f(x) \gets f(x - a)$ とする。
- `shift(a, b)`: $f(x) \gets \min_{x - b \le y \le x - a} f(y)$ とする。
- `merge(g)`: $f(x) \gets f(x) + g(x)$ とし、`g` を $g(x) = 0$ にする。
- `operator()(x)`: $f(x)$ を返す。

### 制約
- `shift(a, b)`: $a \le b$

### 計算量
- 折れ点の総数を $N$ として
- `add_x_minus_a`, `add_a_minus_x`, `add_abs`: $\mathcal{O}(\log N)$
- `merge`: 全体で償却 $\mathcal{O}(N \log^2 N)$
- `operator()`: $\mathcal{O}(N)$
- その他: $\mathcal{O}(1)$
