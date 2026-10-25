---
title: Lowlink
documentation_of: graph/lowlink.hpp
---

### 概要
- 無向グラフの橋・関節点・二重辺連結成分を求める。

### 使い方
- `lowlink(n)`: $n$ 頂点 $0$ 辺の無向グラフを作る。
- `add_edge(u, v)`: 辺 $(u, v)$ を追加し、辺番号を返す。辺番号は追加順。
- `build()`: 構築する。
- `is_bridge(e)`: 辺 `e` が橋かを返す。
- `is_articulation(v)`: 頂点 `v` が関節点かを返す。
- `bridges()`: 橋の辺番号を昇順に返す。
- `articulation_points()`: 関節点を昇順に返す。
- `component(v)`: 頂点 `v` の属する二重辺連結成分の番号を返す。
- `two_edge_connected_components()`: 二重辺連結成分ごとの頂点のリストを返す。`component(v)` 番目のリストに `v` が入る。

### 制約
- $0 \le u, v < n$
- 多重辺・自己ループを含んでよい

### 計算量
- `build`: $\mathcal{O}(N + M)$
- `bridges`, `articulation_points`: $\mathcal{O}(N + M)$
- その他: $\mathcal{O}(1)$
