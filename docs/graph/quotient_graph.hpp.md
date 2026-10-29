---
title: Quotient Graph
documentation_of: graph/quotient_graph.hpp
---

### 概要
- 頂点の分割から、頂点の成分番号と成分を縮約したグラフを作る。

### 使い方
- `component_id(n, groups)`: 頂点 `v` の成分番号を `id[v]` とする長さ `n` の列を返す。`groups` が `atcoder::scc_graph::scc()` の結果なら辺 $(u, v)$ について `id[u] <= id[v]`。
- `quotient_graph(g, groups)`: 隣接リスト `g` の辺を成分間に写したグラフの隣接リストを返す。`q[i]` は成分 `i` から出る辺の先の成分番号で、重複がなく昇順。

### 制約
- `groups` は $0, \ldots, n - 1$ の分割。`atcoder::scc_graph::scc()`、`lowlink::two_edge_connected_components()`、`atcoder::dsu::groups()` の結果はこれを満たす。

### 計算量
- `component_id`: $\mathcal{O}(N)$
- `quotient_graph`: $\mathcal{O}(N + M \log M)$
