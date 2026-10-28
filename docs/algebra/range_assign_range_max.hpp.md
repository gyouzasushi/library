---
title: "Acted Monoid: Range Assign Range Max"
documentation_of: algebra/range_assign_range_max.hpp
---

### 概要
- 区間代入・区間最大値。`lazy_segtree<range_assign_range_max<T>>` のように使う。

### 使い方
- `S = T`, `F = std::optional<T>`
- `e()` は `std::numeric_limits<T>::lowest()`。
- `apply(l, r, v)` で `a[l], ..., a[r - 1]` を `v` にする。
