---
title: "Acted Monoid: Range Affine Range Sum"
documentation_of: algebra/range_affine_range_sum.hpp
---

### 概要
- 区間アフィン変換・区間和。`lazy_segtree<range_affine_range_sum<T>>` のように使う。

### 使い方
- `S = {T sum; int len}`, `F = monoid_affine<T>::S`
- `from(v)`: 値 `v` 1 個分の要素 `{v, 1}` を返す。初期化や一点更新ではこれで `S` を作る。
- `apply(l, r, {a, b})` で `a[l], ..., a[r - 1]` の各要素 `x` を `a x + b` にする。
- `prod(l, r).sum` が区間和。
