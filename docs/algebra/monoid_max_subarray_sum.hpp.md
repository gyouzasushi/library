---
title: "Monoid: Max Subarray Sum"
documentation_of: algebra/monoid_max_subarray_sum.hpp
---

### 概要
- 空でない連続部分列の和の最大値。`segtree<monoid_max_subarray_sum<T>>` のように使う。

### 使い方
- `S = {T sum, max_prefix, max_suffix, max_subarray}`
- `from(v)`: 値 `v` 1 個分の要素を返す。初期化や一点更新ではこれで `S` を作る。
- `prod(l, r).max_subarray` が `a[l], ..., a[r - 1]` の空でない連続部分列の和の最大値。$l = r$ なら `std::numeric_limits<T>::lowest()`。
