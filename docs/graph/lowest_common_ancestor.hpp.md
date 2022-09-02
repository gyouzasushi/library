---
title: 最小共通祖先(LCA)
documentation_of: agraph/lowest_common_ancestor.hpp
---

### 概要
最小共通祖先(LCA)他を求める。
### 使い方
- `LowestCommonAncestor(n, root = 0)`: $\mathrm n$ 頂点で初期化する。頂点 `root` が根になる。
- `add_edge(u, v)`: 頂点 `u` と 頂点 `v` とを結ぶ辺を追加する。
- `build()`: 構築する。
- `get(u, v)`: 頂点 `u` と頂点 `v` のLCAを求める。
- `get(u, v, r)`: 頂点 `r` を根とみたときの、頂点 `u` と頂点 `v` のLCAを求める。
- `depth(u)`: 根と頂点 `u` との距離を求める。
- `dist(u, v)`: 頂点 `u` と頂点 `v` との距離を求める。
### 計算量
- 構築 $\mathcal O(N)$
- クエリ $\mathcal O(1)$