---
title: Weighted DSU
documentation_of: datastructure/weighted_dsu.hpp
---

### 概要
- 各頂点にポテンシャルを持つ Union-Find。頂点間のポテンシャルの差を制約として追加し、差を求める。

### 使い方
- `weighted_dsu<G>(n)`: $n$ 頂点 $0$ 辺の無向グラフを作る。`G` は `S`, `op`, `e`, `inv` を static メンバとして持つ群。
- `merge(a, b, w)`: `diff(a, b) == w` となるように辺 $(a, b)$ を追加し、既存の制約と矛盾しないかを返す。矛盾するときは何もしない。
- `diff(a, b)`: 頂点 `a` から頂点 `b` へのポテンシャルの差 `op(inv(p[a]), p[b])` を返す。
- `same(a, b)`: 頂点 `a`, `b` が連結かを返す。
- `leader(a)`: 頂点 `a` の属する連結成分の代表元を返す。
- `size(a)`: 頂点 `a` の属する連結成分のサイズを返す。
- `groups()`: 連結成分ごとの頂点のリストを返す。

### 制約
- $0 \le a, b < n$
- `diff`: `same(a, b)`
- `S` は `==` で比較できる

### 計算量
- `merge`, `diff`, `same`, `leader`, `size`: 償却 $\mathcal{O}(\alpha(n))$
- `groups`: $\mathcal{O}(n)$
