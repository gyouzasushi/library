---
title: Li Chao Tree
documentation_of: datastructure/li_chao_tree.hpp
---

### 概要
- 直線と線分を追加し、ある $x$ での $y$ の最小値を答える。

### 使い方
- `li_chao_tree<T>(lo, hi)`: $x$ の範囲を $[\text{lo}, \text{hi})$ として作る。`T` は $y$ の型。
- `add_line(a, b)`: 直線 $y = ax + b$ を追加する。
- `add_segment(a, b, l, r)`: 線分 $y = ax + b$ ($l \le x < r$) を追加する。
- `min(x)`: $x$ での $y$ の最小値を返す。$x$ を通る直線も線分も無ければ `std::nullopt`。

### 制約
- $\text{lo} < \text{hi}$
- `add_segment`: $\text{lo} \le l \le r \le \text{hi}$
- `min`: $\text{lo} \le x < \text{hi}$

### 計算量
- $N = \text{hi} - \text{lo}$ として
- `add_line`, `min`: $\mathcal{O}(\log N)$
- `add_segment`: $\mathcal{O}(\log^2 N)$
