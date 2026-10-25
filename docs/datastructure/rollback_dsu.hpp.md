---
title: Rollback DSU
documentation_of: datastructure/rollback_dsu.hpp
---

### 概要
- 結合を取り消せる Union-Find。

### 使い方
- `rollback_dsu(n)`: $n$ 頂点 $0$ 辺の無向グラフを作る。
- `merge(a, b)`: 辺 $(a, b)$ を追加し、代表元を返す。
- `undo()`: 直前の `merge` を取り消す。
- `time()`: これまでの `merge` の回数から `undo` で取り消した分を引いた数を返す。
- `rollback(t)`: `time()` が `t` になるまで `undo` する。
- `same(a, b)`: 頂点 `a`, `b` が連結かを返す。
- `leader(a)`: 頂点 `a` の属する連結成分の代表元を返す。
- `size(a)`: 頂点 `a` の属する連結成分のサイズを返す。
- `groups()`: 連結成分ごとの頂点のリストを返す。

### 制約
- $0 \le a, b < n$
- `undo`: $1 \le$ `time()`
- `rollback`: $0 \le t \le$ `time()`

### 計算量
- `merge`, `same`, `leader`, `size`: $\mathcal{O}(\log n)$
- `undo`: $\mathcal{O}(1)$
- `rollback(t)`: $\mathcal{O}(\text{time}() - t)$
- `groups`: $\mathcal{O}(n \log n)$
