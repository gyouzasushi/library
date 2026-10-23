---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: monoid/concept.hpp
    title: 'Monoid: Concept'
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
  bundledCode: "#line 2 \"datastructure/lazy_segtree.hpp\"\n#include <atcoder/lazysegtree>\n\
    \n#line 2 \"monoid/concept.hpp\"\n#include <concepts>\ntemplate <class M>\nconcept\
    \ semigroup = requires(typename M::S a, typename M::S b) {\n    { M::op(a, b)\
    \ } -> std::same_as<typename M::S>;\n};\ntemplate <class M>\nconcept monoid =\
    \ semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename M::S>;\n\
    };\ntemplate <class A>\nconcept action = requires(typename A::F f, typename A::F\
    \ g) {\n    { A::composition(f, g) } -> std::same_as<typename A::F>;\n    { A::id()\
    \ } -> std::same_as<typename A::F>;\n    { A::composition_commutative } -> std::convertible_to<bool>;\n\
    };\ntemplate <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
    \ A::S x, typename A::F f) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n};\n#line 5 \"datastructure/lazy_segtree.hpp\"\ntemplate <acted_monoid\
    \ A>\nusing lazy_segtree = atcoder::lazy_segtree<typename A::S, A::op, A::e, typename\
    \ A::F, A::mapping, A::composition, A::id>;\n"
  code: '#pragma once

    #include <atcoder/lazysegtree>


    #include "monoid/concept.hpp"

    template <acted_monoid A>

    using lazy_segtree = atcoder::lazy_segtree<typename A::S, A::op, A::e, typename
    A::F, A::mapping, A::composition, A::id>;

    '
  dependsOn:
  - monoid/concept.hpp
  isVerificationFile: false
  path: datastructure/lazy_segtree.hpp
  requiredBy: []
  timestamp: '2026-10-23 12:18:24+09:00'
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
