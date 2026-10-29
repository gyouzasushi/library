---
title: Segment Tree Beats
documentation_of: datastructure/segtree_beats.hpp
---

### 概要
- `mapping` が失敗を返せる遅延セグメント木。失敗したノードは子に作用を押し下げて計算し直す。

### 使い方
- `segtree_beats<A>`: `A` は `lazy_segtree<A>` と同じ構造体で、`S` が `bool fail` を持つもの。
- `mapping(f, x)` は `x` から結果が計算できないときだけ `fail = true` の `S` を返す。要素 1 個の `S` では必ず計算できる。`op`, `e()` が返す `S` は `fail = false`。
- 以降は `atcoder::lazy_segtree` と同じ。

### 計算量
- `mapping` が失敗する回数の合計を $K$ として、全体で $\mathcal{O}((N + Q + K) \log N)$
- `range_chmin_chmax_add_range_sum`: $K = \mathcal{O}((N + Q) \log N)$
