---
title: Dijkstra 法
documentation_of: graph/dijkstra.hpp
---

### 概要
- Dijkstra 法で単一始点最短路を求める。
  
### 使い方
- `dijkstra(s, g)`: 重み付きグラフ `g` における、頂点 `s` から全点間の最短距離を求める。`g` は `(to, cost)` のペアを持つ隣接リスト。`(dist, from)` を返す。