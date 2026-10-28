---
title: Dynamic Segment Tree
documentation_of: datastructure/dynamic_segtree.hpp
---

### 概要
- 添字の範囲が広い列に対する、1 点更新と区間の総積を求めるセグメント木。ノードは `set` した位置の分だけ作る。

### 使い方
- `dynamic_segtree<M>(lo = -2^62, hi = 2^62)`: `M` は `S`, `op`, `e` を static メンバとして持つ構造体。添字 $[\text{lo}, \text{hi})$ の全要素 `M::e()` の列を作る。
- `set(p, x)`: `a[p]` を `x` にする。
- `get(p)`: `a[p]` を返す。
- `prod(l, r)`: `op(a[l], ..., a[r - 1])` を返す。$l = r$ なら `e()`。
- `all_prod()`: `op(a[lo], ..., a[hi - 1])` を返す。
- `max_right(l, f)`: `f(op(a[l], ..., a[r - 1]))` が真となる最大の `r` を返す。全体で真なら `hi`。`f` は `atcoder::segtree` と同じ条件を満たすもの。
- `min_left(r, f)`: `f(op(a[l], ..., a[r - 1]))` が真となる最小の `l` を返す。全体で真なら `lo`。

### 制約
- $\text{lo} < \text{hi}$
- `set`, `get`: $\text{lo} \le p < \text{hi}$
- `prod`: $\text{lo} \le l \le r \le \text{hi}$
- `max_right`, `min_left`: $\text{lo} \le l, r \le \text{hi}$

### 計算量
- $N = \text{hi} - \text{lo}$ として
- `set`, `get`, `prod`, `max_right`, `min_left`: $\mathcal{O}(\log N)$
- `all_prod`: $\mathcal{O}(1)$
- メモリは `set` した位置の個数に比例する。
