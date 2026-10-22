---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: datastructure/lazy_segtree.hpp
    title: Lazy Segment Tree (acted monoid wrapper)
  - icon: ':heavy_check_mark:'
    path: datastructure/plus_minus_one_rmq.hpp
    title: Plus Minus One RMQ
  - icon: ':heavy_check_mark:'
    path: datastructure/segtree.hpp
    title: Segment Tree (monoid wrapper)
  - icon: ':heavy_check_mark:'
    path: datastructure/sparse_table.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148(LCA)"
  - icon: ':heavy_check_mark:'
    path: graph/manhattan_mst.hpp
    title: Manhattan MST
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: test/aoj/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/lca.test.cpp
    title: test/library-checker/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/manhattanmst.test.cpp
    title: test/library-checker/manhattanmst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/point_set_range_composite.test.cpp
    title: test/library-checker/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/staticrmq.test.cpp
    title: test/library-checker/staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/monoid.test.cpp
    title: test/unit/monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/sparse_table.test.cpp
    title: test/unit/sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"monoid/concept.hpp\"\n#include <concepts>\ntemplate <class\
    \ M>\nconcept semigroup = requires(typename M::S a, typename M::S b) {\n    {\
    \ M::op(a, b) } -> std::same_as<typename M::S>;\n};\ntemplate <class M>\nconcept\
    \ monoid = semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename\
    \ M::S>;\n};\ntemplate <class A>\nconcept acted_monoid = monoid<A> && requires(typename\
    \ A::S x, typename A::F f, typename A::F g) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n    { A::composition(f, g) } -> std::same_as<typename A::F>;\n    {\
    \ A::id() } -> std::same_as<typename A::F>;\n};\n"
  code: "#pragma once\n#include <concepts>\ntemplate <class M>\nconcept semigroup\
    \ = requires(typename M::S a, typename M::S b) {\n    { M::op(a, b) } -> std::same_as<typename\
    \ M::S>;\n};\ntemplate <class M>\nconcept monoid = semigroup<M> && requires {\n\
    \    { M::e() } -> std::same_as<typename M::S>;\n};\ntemplate <class A>\nconcept\
    \ acted_monoid = monoid<A> && requires(typename A::S x, typename A::F f, typename\
    \ A::F g) {\n    { A::mapping(f, x) } -> std::same_as<typename A::S>;\n    { A::composition(f,\
    \ g) } -> std::same_as<typename A::F>;\n    { A::id() } -> std::same_as<typename\
    \ A::F>;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: monoid/concept.hpp
  requiredBy:
  - datastructure/sparse_table.hpp
  - datastructure/lazy_segtree.hpp
  - datastructure/plus_minus_one_rmq.hpp
  - datastructure/segtree.hpp
  - graph/manhattan_mst.hpp
  - graph/lowest_common_ancestor.hpp
  timestamp: '2026-10-23 07:09:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_G.test.cpp
  - test/aoj/DSL_2_A.test.cpp
  - test/unit/sparse_table.test.cpp
  - test/unit/monoid.test.cpp
  - test/library-checker/staticrmq.test.cpp
  - test/library-checker/point_set_range_composite.test.cpp
  - test/library-checker/lca.test.cpp
  - test/library-checker/manhattanmst.test.cpp
documentation_of: monoid/concept.hpp
layout: document
title: 'Monoid: Concept'
---

### 概要
- `segtree`, `lazy_segtree`, `sparse_table` に渡す構造体の要件。

### 使い方
- `semigroup<M>`: `M::S` と `M::op(S, S) -> S` を持つ。
- `monoid<M>`: `semigroup<M>` に加えて `M::e() -> S` を持つ。
- `acted_monoid<A>`: `monoid<A>` に加えて `A::F`, `A::mapping(F, S) -> S`, `A::composition(F, F) -> F`, `A::id() -> F` を持つ。
