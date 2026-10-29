---
title: Bipartite Coloring
documentation_of: graph/bipartite_coloring.hpp
---

### 概要
- 無向グラフの 2 彩色と、二部グラフでないときの奇閉路を求める。

### 使い方
- `bipartite_coloring g(n)`: 頂点数 `n`。
- `add_edge(u, v)`: 辺 $(u, v)$ を追加する。
- `build()`: 構築する。
- `is_bipartite()`: 二部グラフかを返す。
- `color(v)`: 頂点 `v` の色 (0 / 1) を返す。二部グラフなら隣接する頂点は色が異なる。
- `odd_cycle()`: 奇閉路の頂点列を閉路順に返す。二部グラフなら空。

### 計算量
- `build`: $\mathcal{O}(N + M)$
- その他: $\mathcal{O}(1)$
