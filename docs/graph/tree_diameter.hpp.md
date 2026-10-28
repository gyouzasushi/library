---
title: Tree Diameter
documentation_of: graph/tree_diameter.hpp
---

### 概要
- 木の直径を求める。

### 使い方
- `tree_diameter<T> d(n)`: 頂点数 `n`、辺の重みの型 `T`。
- `add_edge(u, v, w = 1)`: 重み `w` の辺 $(u, v)$ を追加する。
- `build()`: 構築する。
- `length()`: 直径の長さを返す。
- `ends()`: 直径の両端 `(u, v)` を返す。
- `path()`: `u` から `v` への直径の頂点列を返す。

### 制約
- $1 \le n$
- $0 \le w$
- 辺は $n - 1$ 本で全体が木

### 計算量
- `build`: $\mathcal{O}(N)$
- その他: $\mathcal{O}(1)$
