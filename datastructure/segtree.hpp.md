---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: monoid/concept.hpp
    title: 'Monoid: Concept'
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/manhattan_mst.hpp
    title: Manhattan MST
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/manhattanmst.test.cpp
    title: test/library-checker/manhattanmst.test.cpp
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
  bundledCode: "#line 2 \"datastructure/segtree.hpp\"\n#include <atcoder/segtree>\n\
    \n#line 2 \"monoid/concept.hpp\"\n#include <concepts>\ntemplate <class M>\nconcept\
    \ semigroup = requires(typename M::S a, typename M::S b) {\n    { M::op(a, b)\
    \ } -> std::same_as<typename M::S>;\n};\ntemplate <class M>\nconcept monoid =\
    \ semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename M::S>;\n\
    };\ntemplate <class A>\nconcept acted_monoid = monoid<A> && requires(typename\
    \ A::S x, typename A::F f, typename A::F g) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n    { A::composition(f, g) } -> std::same_as<typename A::F>;\n    {\
    \ A::id() } -> std::same_as<typename A::F>;\n};\n#line 5 \"datastructure/segtree.hpp\"\
    \ntemplate <monoid M>\nusing segtree = atcoder::segtree<typename M::S, M::op,\
    \ M::e>;\n"
  code: '#pragma once

    #include <atcoder/segtree>


    #include "monoid/concept.hpp"

    template <monoid M>

    using segtree = atcoder::segtree<typename M::S, M::op, M::e>;

    '
  dependsOn:
  - monoid/concept.hpp
  isVerificationFile: false
  path: datastructure/segtree.hpp
  requiredBy:
  - graph/manhattan_mst.hpp
  timestamp: '2026-10-23 07:09:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_A.test.cpp
  - test/unit/monoid.test.cpp
  - test/library-checker/point_set_range_composite.test.cpp
  - test/library-checker/manhattanmst.test.cpp
documentation_of: datastructure/segtree.hpp
layout: document
title: Segment Tree (monoid wrapper)
---

### 概要
- `atcoder::segtree` を monoid 構造体 1 つで指定するためのエイリアス。

### 使い方
- `segtree<M>`: `M` は `S`, `op`, `e` を static メンバとして持つ構造体。`monoid/` 以下のものか、同じ形で自作したもの。
- 以降は `atcoder::segtree` と同じ。
