---
title: Dual Segment Tree
documentation_of: datastructure/dual_segment_tree.hpp
---

### 概要
- 区間更新・一点取得ができるデータ構造。

### 使い方
- `DualSegmentTree<F, composition, id>(n, is_commutative = false)`: 長さ `n` の数列 `a` を作る。`F` は作用の型。`composition` は $\cdot : F \times F \rightarrow F$ を計算する関数。`id` は $id$ を返す関数。$\cdot$ が可換である場合は `commutative = true` にするとよい。
- `apply(l, r, x)`: `a_l, ..., a_r` に `x` を作用させる。
- `get(p)`: `a_p` を求める。