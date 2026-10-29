---
title: "Acted Monoid: Range Assign Range Hash"
documentation_of: algebra/range_assign_range_hash.hpp
---

### 概要
- 区間を 1 文字で埋める更新・区間のハッシュ値。`lazy_segtree<range_assign_range_hash<k, mint>>` のように使う。

### 使い方
- `S = string_hash<k, mint>`, `F = std::optional<int>`
- `from(c)`: 1 文字 `c` のハッシュ値を返す。初期化や一点更新ではこれで `S` を作る。
- `apply(l, r, c)` で `s[l], ..., s[r - 1]` を `c` にする。
- `prod(l, r)` が `s[l, r)` のハッシュ値。`lcp`, `cmp` にそのまま渡せる。

### 制約
- $0 \le c <$ `mint::mod()`
