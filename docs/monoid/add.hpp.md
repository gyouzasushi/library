---
title: "Monoid: Add"
documentation_of: monoid/add.hpp
---

### 概要
- 加算モノイド。`segtree<monoid_add<T>>` のように使う。

### 使い方
- `S = T`, `op(a, b) = a + b`, `e() = 0`
- `commutative = true`
