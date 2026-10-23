---
title: Topological Sort
documentation_of: graph/topological_sort.hpp
---

### 概要
- 有向グラフの頂点を、すべての辺 $(u, v)$ について $u$ が $v$ より前に来るように並べる。

### 使い方
- `topological_sort(g)`: 隣接リスト `g` の頂点のトポロジカル順序を返す。サイクルがあれば `std::nullopt` を返す。
- `topological_sort(g, comp)`: 各時点で `comp` の意味で最小の頂点を先に出す順序を返す。`comp(a, b)` が真なら `a` が先。辞書順最小は `std::less<int>()`。

### 計算量
- `topological_sort(g)`: $\mathcal{O}(N + M)$
- `topological_sort(g, comp)`: $\mathcal{O}((N + M) \log N)$
