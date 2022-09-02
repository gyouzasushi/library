---
title: Sparse Table
documentation_of: datastructure/sparse_table.hpp
---

### 概要
- 演算が冪等な半群に対する区間クエリを高速に処理する。
  
### 使い方
- `SparseTable<S, op>(v)`: 半群 `(S, op)`、配列 `v` で初期化する。`op` は冪等な演算である必要がある($\min / \max$, $\gcd / \mathrm{lcm}$, $\mathrm{and} / \mathrm{or}$ など)。
- `prod(l, r)`: $\mathrm{op} (\mathrm{op} (\cdots \mathrm{op} (\mathrm{v}_{l}, \mathrm{v}_{l+1}),\cdots ), \mathrm{v}_{r-1})$ を求める。
  
### 計算量
- 構築: $\mathcal O(N \log N)$
- クエリ: $\mathcal O(1)$