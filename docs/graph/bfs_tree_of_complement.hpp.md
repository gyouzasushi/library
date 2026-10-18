---
title: 補グラフの BFS 森
documentation_of: graph/bfs_tree_of_complement.hpp
---

### 概要
- 補グラフ上の BFS 森を返す。

### 使い方
- `bfs_tree_of_complement(g)`: `g` は $G$ の隣接リスト。長さ $N$ の `ret` を返す。
  - `ret[u]`: $\bar G$ の BFS 森において `u` の子である頂点のリスト。BFS で訪れた順に並ぶ。
  - 各連結成分の根は、その成分に含まれる頂点のうち番号が最小のもの。頂点 $0, 1, \ldots$ の順に未訪問なら根として BFS を始める。
  - `ret[u]` を子リストとして根から辿れば連結成分、深さを数えれば $\bar G$ 上の根からの最短距離になる。

### 計算量
- $\mathcal{O}(N + M)$
