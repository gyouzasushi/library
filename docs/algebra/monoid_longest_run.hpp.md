---
title: "Monoid: Longest Run"
documentation_of: algebra/monoid_longest_run.hpp
---

### 概要
- 同じ値が連続する最長の長さ。`segtree<monoid_longest_run<T>>` のように使う。

### 使い方
- `S = {int len; T left, right; int left_run, right_run, longest}`
- `from(c)`: 値 `c` 1 個分の要素を返す。初期化や一点更新ではこれで `S` を作る。
- `prod(l, r).longest` が `a[l], ..., a[r - 1]` で同じ値が連続する最長の長さ。
