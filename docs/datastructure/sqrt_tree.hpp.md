---
title: Sqrt Tree
documentation_of: datastructure/sqrt_tree.hpp
---

### 概要
- 静的な配列の区間積を求める。

### 使い方
- `sqrt_tree<M>(a)`: 配列 `a` で構築する。`M` は `S` と `op` を static メンバとして持つ構造体。`e` は不要。
- `prod(l, r)`: `op(a[l], ..., a[r - 1])` を返す。

### 制約
- `op` は結合的
- $0 \le l < r \le n$

### 計算量
- 構築: $\mathcal{O}(N \log \log N)$
- `prod`: $\mathcal{O}(1)$
