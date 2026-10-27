---
title: "Acted Monoid: Range Add Range Sum of Squares"
documentation_of: algebra/range_add_range_sum_of_squares.hpp
---

### 概要
- 区間加算・区間の和と二乗和。`lazy_segtree<range_add_range_sum_of_squares<T>>` のように使う。

### 使い方
- `S = {T sum; T sum_of_squares; int len}`, `F = T`
- `from(v)`: 値 `v` 1 個分の要素 `{v, v * v, 1}` を返す。初期化や一点更新ではこれで `S` を作る。
- `prod(l, r).sum` が区間和、`prod(l, r).sum_of_squares` が区間の二乗和。
