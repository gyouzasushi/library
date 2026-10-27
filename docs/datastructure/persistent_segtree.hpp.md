---
title: Persistent Segment Tree
documentation_of: datastructure/persistent_segtree.hpp
---

### 概要
- 1 点更新のたびに新しい版を作り、過去の版に対しても区間の総積を求められるセグメント木。版は `int` の番号で扱う。

### 使い方
- `persistent_segtree<M>(n)`: `M` は `S`, `op`, `e` を static メンバとして持つ構造体。全要素 `M::e()` の長さ $n$ の列を版 $0$ として作る。
- `persistent_segtree<M>(v)`: 列 `v` を版 $0$ として作る。
- `size()`: 列の長さを返す。
- `get(root, p)`: 版 `root` の `a[p]` を返す。
- `set(root, p, x)`: 版 `root` の `a[p]` を `x` に変えた新しい版を作り、その番号を返す。版 `root` は変わらない。
- `prod(root, l, r)`: 版 `root` の `op(a[l], ..., a[r - 1])` を返す。$l = r$ なら `e()`。
- `all_prod(root)`: 版 `root` の `op(a[0], ..., a[n - 1])` を返す。

### 制約
- $0 \le p < n$
- $0 \le l \le r \le n$

### 計算量
- 構築: $\mathcal{O}(n)$
- `get`, `set`, `prod`: $\mathcal{O}(\log n)$。`set` 1 回でメモリが $\mathcal{O}(\log n)$ 増える。
- `all_prod`: $\mathcal{O}(1)$
