---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/manhattan_mst.hpp
    title: Manhattan MST
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':x:'
    path: test/library-checker/manhattanmst.test.cpp
    title: test/library-checker/manhattanmst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/point_set_range_composite.test.cpp
    title: test/library-checker/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/monoid.test.cpp
    title: test/unit/monoid.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/segtree.hpp\"\n#include <atcoder/segtree>\n\
    \n#line 2 \"algebra/concept.hpp\"\n#include <concepts>\ntemplate <class M>\nconcept\
    \ semigroup = requires(typename M::S a, typename M::S b) {\n    { M::op(a, b)\
    \ } -> std::same_as<typename M::S>;\n};\ntemplate <class M>\nconcept monoid =\
    \ semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename M::S>;\n\
    };\ntemplate <class G>\nconcept group = monoid<G> && requires(typename G::S a)\
    \ {\n    { G::inv(a) } -> std::same_as<typename G::S>;\n};\ntemplate <class A>\n\
    concept action = requires(typename A::F f, typename A::F g) {\n    { A::composition(f,\
    \ g) } -> std::same_as<typename A::F>;\n    { A::id() } -> std::same_as<typename\
    \ A::F>;\n    { A::composition_commutative } -> std::convertible_to<bool>;\n};\n\
    template <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
    \ A::S x, typename A::F f) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n};\ntemplate <class R>\nconcept semiring = requires(typename R::S a,\
    \ typename R::S b) {\n    { R::add(a, b) } -> std::same_as<typename R::S>;\n \
    \   { R::zero() } -> std::same_as<typename R::S>;\n    { R::mul(a, b) } -> std::same_as<typename\
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\n#line 5 \"datastructure/segtree.hpp\"\
    \ntemplate <monoid M>\nusing segtree = atcoder::segtree<typename M::S, M::op,\
    \ M::e>;\n"
  code: '#pragma once

    #include <atcoder/segtree>


    #include "algebra/concept.hpp"

    template <monoid M>

    using segtree = atcoder::segtree<typename M::S, M::op, M::e>;

    '
  dependsOn:
  - algebra/concept.hpp
  isVerificationFile: false
  path: datastructure/segtree.hpp
  requiredBy:
  - graph/manhattan_mst.hpp
  timestamp: '2026-10-26 01:30:50+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/unit/monoid.test.cpp
  - test/library-checker/manhattanmst.test.cpp
  - test/library-checker/point_set_range_composite.test.cpp
  - test/aoj/DSL_2_A.test.cpp
documentation_of: datastructure/segtree.hpp
layout: document
title: Segment Tree (monoid wrapper)
---

### 概要
- `atcoder::segtree` を monoid 構造体 1 つで指定するためのエイリアス。

### 使い方
- `segtree<M>`: `M` は `S`, `op`, `e` を static メンバとして持つ構造体。`algebra/` 以下のものか、同じ形で自作したもの。
- 以降は `atcoder::segtree` と同じ。
