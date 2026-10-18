---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: test/aoj/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/monoid.test.cpp
    title: test/unit/monoid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "datastructure/lazy_segtree.hpp"

    #include <atcoder/lazysegtree>

    template <class A>

    using lazy_segtree = atcoder::lazy_segtree<typename A::S, A::op, A::e, typename
    A::F, A::mapping, A::composition, A::id>;

    '
  code: '#pragma once

    #include <atcoder/lazysegtree>

    template <class A>

    using lazy_segtree = atcoder::lazy_segtree<typename A::S, A::op, A::e, typename
    A::F, A::mapping, A::composition, A::id>;

    '
  dependsOn: []
  isVerificationFile: false
  path: datastructure/lazy_segtree.hpp
  requiredBy: []
  timestamp: '2026-10-19 02:48:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_G.test.cpp
  - test/unit/monoid.test.cpp
documentation_of: datastructure/lazy_segtree.hpp
layout: document
title: Lazy Segment Tree (acted monoid wrapper)
---

### 概要
- `atcoder::lazy_segtree` を acted monoid 構造体 1 つで指定するためのエイリアス。

### 使い方
- `lazy_segtree<A>`: `A` は `S`, `op`, `e`, `F`, `mapping`, `composition`, `id` を static メンバとして持つ構造体。`acted_monoid/` 以下のものか、同じ形で自作したもの。
- `composition(f, g)` は $f \circ g$（`g` が先）で ac-library と同じ。
- 以降は `atcoder::lazy_segtree` と同じ。
