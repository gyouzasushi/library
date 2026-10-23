---
title: Segment Tree (monoid wrapper)
documentation_of: datastructure/segtree.hpp
---

### 概要
- `atcoder::segtree` を monoid 構造体 1 つで指定するためのエイリアス。

### 使い方
- `segtree<M>`: `M` は `S`, `op`, `e` を static メンバとして持つ構造体。`algebra/` 以下のものか、同じ形で自作したもの。
- 以降は `atcoder::segtree` と同じ。
