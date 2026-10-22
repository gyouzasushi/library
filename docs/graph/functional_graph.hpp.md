---
title: Functional Graph
documentation_of: graph/functional_graph.hpp
---

### 概要
- 各頂点 $v$ から $f(v)$ へ辺を張った有向グラフ。

### 使い方
- `functional_graph(f)`: `f[v]` を頂点 `v` の行き先として構築する。
- `jump(v, k)`: 頂点 `v` から `k` 回進んだ頂点を返す。
- `on_cycle(v)`: 頂点 `v` がサイクル上にあるかを返す。
- `root(v)`: 頂点 `v` から進んで最初に着くサイクル上の頂点を返す。
- `depth(v)`: 頂点 `v` から `root(v)` までの歩数を返す。
- `component(v)`: 頂点 `v` が属する連結成分の番号を返す。`cycles()` の添字と一致する。
- `cycle(v)`: 頂点 `v` が属する連結成分のサイクルを $f$ の向きに並べた列を返す。
- `cycles()`: 全てのサイクルを返す。
- `children(v)`: `f[u] = v` かつ `u` がサイクル上にない頂点 `u` の列を返す。

### 制約
- $0 \le f[v] < n$
- $0 \le k \le 10^{18}$

### 計算量
- 構築: $\mathcal{O}(n \log n)$
- `jump`: $\mathcal{O}(\log n)$
- その他: $\mathcal{O}(1)$
