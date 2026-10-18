---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/point_set_range_composite.test.cpp
    title: test/library-checker/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/monoid.test.cpp
    title: test/unit/monoid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "datastructure/segtree.hpp"

    #include <atcoder/segtree>

    template <class M>

    using segtree = atcoder::segtree<typename M::S, M::op, M::e>;

    '
  code: '#pragma once

    #include <atcoder/segtree>

    template <class M>

    using segtree = atcoder::segtree<typename M::S, M::op, M::e>;

    '
  dependsOn: []
  isVerificationFile: false
  path: datastructure/segtree.hpp
  requiredBy: []
  timestamp: '2026-10-19 02:48:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_A.test.cpp
  - test/unit/monoid.test.cpp
  - test/library-checker/point_set_range_composite.test.cpp
documentation_of: datastructure/segtree.hpp
layout: document
title: Segment Tree (monoid wrapper)
---

### 概要
- `atcoder::segtree` を monoid 構造体 1 つで指定するためのエイリアス。

### 使い方
- `segtree<M>`: `M` は `S`, `op`, `e` を static メンバとして持つ構造体。`monoid/` 以下のものか、同じ形で自作したもの。
- 以降は `atcoder::segtree` と同じ。
