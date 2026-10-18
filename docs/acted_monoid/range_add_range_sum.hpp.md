---
title: "Acted Monoid: Range Add Range Sum"
documentation_of: acted_monoid/range_add_range_sum.hpp
---

### 概要
- 区間加算・区間和。`lazy_segtree<range_add_range_sum<T>>` のように使う。

### 使い方
- `S = {T sum; int len}`, `F = T`
- `from(v)`: 値 `v` 1 個分の要素 `{v, 1}` を返す。初期化や一点更新ではこれで `S` を作る。
- `prod(l, r).sum` が区間和。
