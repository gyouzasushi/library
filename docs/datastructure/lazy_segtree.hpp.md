---
title: Lazy Segment Tree (acted monoid wrapper)
documentation_of: datastructure/lazy_segtree.hpp
---

### 概要
- `atcoder::lazy_segtree` を acted monoid 構造体 1 つで指定するためのエイリアス。

### 使い方
- `lazy_segtree<A>`: `A` は `S`, `op`, `e`, `F`, `mapping`, `composition`, `id` を static メンバとして持つ構造体。`acted_monoid/` 以下のものか、同じ形で自作したもの。
- `composition(f, g)` は $f \circ g$（`g` が先）で ac-library と同じ。
- 以降は `atcoder::lazy_segtree` と同じ。
