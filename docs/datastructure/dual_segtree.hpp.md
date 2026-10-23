---
title: Dual Segment Tree
documentation_of: datastructure/dual_segtree.hpp
---

### 概要
- 区間作用と一点取得ができるデータ構造。

### 使い方
- `dual_segtree<A>(n)`: 長さ $n$ の数列 `a` を `id()` で初期化して作る。`A` は `F`, `composition`, `id`, `composition_commutative` を static メンバとして持つ構造体。
- `dual_segtree<A>(v)`: 数列 `a` を `v` で初期化して作る。
- `apply(l, r, f)`: `a[l], ..., a[r - 1]` のそれぞれを `composition(f, a[i])` に置き換える。
- `set(p, x)`: `a[p]` を `x` に置き換える。
- `get(p)`: `a[p]` を返す。

### 制約
- $0 \le l \le r \le n$
- $0 \le p < n$

### 計算量
- 構築: $\mathcal{O}(n)$
- `apply`, `set`, `get`: $\mathcal{O}(\log n)$
