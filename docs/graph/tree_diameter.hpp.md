---
title: Tree Diameter
documentation_of: graph/tree_diameter.hpp
---

### 概要
- 木の直径と、各頂点から最も遠い頂点を求める。

### 使い方
- `tree_diameter<T> d(n)`: 頂点数 `n`、辺の重みの型 `T`。
- `add_edge(u, v, w = 1)`: 重み `w` の辺 $(u, v)$ を追加する。
- `build()`: 構築する。
- `length()`: 直径の長さを返す。
- `ends()`: 直径の両端 `(u, v)` を返す。
- `path()`: `u` から `v` への直径の頂点列を返す。
- `farthest_dist(x)`: 頂点 `x` から最も遠い頂点までの距離を返す。
- `farthest(x)`: 頂点 `x` から最も遠い頂点を返す。複数あるときは番号が最小のもの。

### 制約
- $1 \le n$
- $0 \le w$
- 辺は $n - 1$ 本で全体が木

### 計算量
- `build`: $\mathcal{O}(N)$
- `path`: $\mathcal{O}(1)$
- その他: $\mathcal{O}(1)$
