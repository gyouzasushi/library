---
title: Sqrt Tree
documentation_of: datastructure/sqrt_tree.hpp
---

### 概要
- 任意の半群に対する区間クエリを高速に処理する。
- `sparse_table` と違い演算が冪等である必要はないが、構築の定数倍が重く、空間も多い。

### 使い方
- `sqrt_tree<S, op>(v)`: 半群 `(S, op)`、配列 `v` で初期化する。`op` は結合律を満たす必要がある（冪等性は不要）。
- `prod(l, r)`: $\mathrm{op} (\mathrm{op} (\cdots \mathrm{op} (\mathrm{v}_{l}, \mathrm{v}_{l+1}),\cdots ), \mathrm{v}_{r-1})$ を求める。空区間 ($l = r$) は禁止。

### 計算量
- 構築: $\mathcal O(N \log \log N)$
- クエリ: $\mathcal O(1)$
