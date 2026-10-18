---
title: HL分解 (Heavy-Light Decomposition)
documentation_of: graph/heavy_light_decomposition.hpp
---

### 概要
- 木をパスに分解し、パスや部分木に対するクエリを区間クエリに帰着させる。
- 各頂点 `v` には番号 `index(v)` が振られ、部分木は番号の連続区間、任意のパスは $\mathcal O(\log N)$ 個の連続区間になる。

### 使い方
- `heavy_light_decomposition(n, root = 0)`: $\mathrm n$ 頂点で初期化する。頂点 `root` が根になる。
- `add_edge(u, v)`: 頂点 `u` と頂点 `v` とを結ぶ辺を追加する。
- `build()`: 構築する。
- `index(v)`: 頂点 `v` の番号を返す。
- `vertex(i)`: 番号 `i` の頂点を返す。
- `subtree(v)`: 頂点 `v` の部分木に対応する番号の区間 $[l, r)$ を返す。
- `edge_index(i)`: `i` 番目に `add_edge` した辺の番号を返す。辺の番号は子側の頂点の番号で、辺に値を持たせるときの格納位置になる。
- `depth(v)`: 頂点 `v` の深さを返す。
- `parent(v)`: 頂点 `v` の親を返す。根なら `-1`。
- `head_of(v)`: 頂点 `v` を含む heavy path の最も浅い頂点を返す。
- `lca(u, v)`: 頂点 `u` と頂点 `v` のLCAを返す。
- `lca(u, v, r)`: 頂点 `r` を根とみたときの、頂点 `u` と頂点 `v` のLCAを返す。
- `dist(u, v)`: 頂点 `u` と頂点 `v` との距離を返す。
- `la(v, k)`: 頂点 `v` の `k` 個上の祖先を返す。存在しなければ `-1`。
- `jump(s, t, k)`: 頂点 `s` から頂点 `t` へ向かって `k` 回進んだ頂点を返す。存在しなければ `-1`。
- `in_subtree(u, v)`: 頂点 `v` が頂点 `u` の部分木に含まれるか判定する。
- `on_path(s, t, x)`: 頂点 `x` が `s`-`t` パス上にあるか判定する。
- `for_each_vertex(u, v, f)`: `u`-`v` パス上の頂点を番号の区間に分解し、各区間について `f(l, r)` を呼ぶ。
- `for_each_edge(u, v, f)`: `u`-`v` パス上の辺を番号の区間に分解し、各区間について `f(l, r)` を呼ぶ。辺は子側の頂点の番号で表す。
- `for_each_vertex_noncommutative(u, v, f)`: `u` から `v` へ向かう順に区間を `f(a, b)` で呼ぶ。`a < b` なら区間 $[a, b)$ を昇順に、`a > b` なら区間 $[b, a)$ を降順に辿る。
- `for_each_edge_noncommutative(u, v, f)`: 辺版。
- `for_each_vertex_in_subtree(v, f)`: 頂点 `v` の部分木に含まれる頂点の区間について `f(l, r)` を呼ぶ。
- `for_each_edge_in_subtree(v, f)`: 頂点 `v` の部分木に含まれる辺の区間について `f(l, r)` を呼ぶ。

### 計算量
- 構築 $\mathcal O(N)$
- `lca`, `dist`, `la`, `jump`: $\mathcal O(\log N)$
- `for_each_*`: 区間の個数は $\mathcal O(\log N)$ 個
