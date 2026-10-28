---
title: "Acted Monoid: Range Assign Range Sum"
documentation_of: algebra/range_assign_range_sum.hpp
---

### 概要
- 区間代入・区間和。`lazy_segtree<range_assign_range_sum<T>>` のように使う。

### 使い方
- `S = {T sum; int len}`, `F = std::optional<T>`
- `from(v)`: 値 `v` 1 個分の要素 `{v, 1}` を返す。初期化や一点更新ではこれで `S` を作る。
- `apply(l, r, v)` で `a[l], ..., a[r - 1]` を `v` にする。
- `prod(l, r).sum` が区間和。
