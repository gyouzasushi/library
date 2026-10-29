---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: datastructure/dual_segtree.hpp
    title: Dual Segment Tree
  - icon: ':heavy_check_mark:'
    path: datastructure/dynamic_segtree.hpp
    title: Dynamic Segment Tree
  - icon: ':heavy_check_mark:'
    path: datastructure/lazy_segtree.hpp
    title: Lazy Segment Tree (acted monoid wrapper)
  - icon: ':heavy_check_mark:'
    path: datastructure/persistent_segtree.hpp
    title: Persistent Segment Tree
  - icon: ':heavy_check_mark:'
    path: datastructure/plus_minus_one_rmq.hpp
    title: Plus Minus One RMQ
  - icon: ':heavy_check_mark:'
    path: datastructure/segtree.hpp
    title: Segment Tree (monoid wrapper)
  - icon: ':heavy_check_mark:'
    path: datastructure/segtree_beats.hpp
    title: Segment Tree Beats
  - icon: ':heavy_check_mark:'
    path: datastructure/sparse_table.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: datastructure/sqrt_tree.hpp
    title: Sqrt Tree
  - icon: ':heavy_check_mark:'
    path: datastructure/weighted_dsu.hpp
    title: Weighted DSU
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148(LCA)"
  - icon: ':heavy_check_mark:'
    path: graph/manhattan_mst.hpp
    title: Manhattan MST
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: Matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0355.test.cpp
    title: test/aoj/0355.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: test/aoj/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/inverse_matrix.test.cpp
    title: test/library-checker/inverse_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/lca.test.cpp
    title: test/library-checker/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/manhattanmst.test.cpp
    title: test/library-checker/manhattanmst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/matrix_det.test.cpp
    title: test/library-checker/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/matrix_product.test.cpp
    title: test/library-checker/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/matrix_rank.test.cpp
    title: test/library-checker/matrix_rank.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/point_add_range_sum_dynamic_segtree.test.cpp
    title: test/library-checker/point_add_range_sum_dynamic_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/point_set_range_composite.test.cpp
    title: test/library-checker/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/pow_of_matrix.test.cpp
    title: test/library-checker/pow_of_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/range_affine_point_get.test.cpp
    title: test/library-checker/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/range_chmin_chmax_add_range_sum.test.cpp
    title: test/library-checker/range_chmin_chmax_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/staticrmq.test.cpp
    title: test/library-checker/staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/staticrmq_sqrt_tree.test.cpp
    title: test/library-checker/staticrmq_sqrt_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/system_of_linear_equations.test.cpp
    title: test/library-checker/system_of_linear_equations.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/unionfind_with_potential.test.cpp
    title: test/library-checker/unionfind_with_potential.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/unionfind_with_potential_non_commutative_group.test.cpp
    title: test/library-checker/unionfind_with_potential_non_commutative_group.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/dual_segtree.test.cpp
    title: test/unit/dual_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/dynamic_segtree.test.cpp
    title: test/unit/dynamic_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/linear_algebra.test.cpp
    title: test/unit/linear_algebra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/matrix.test.cpp
    title: test/unit/matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/monoid.test.cpp
    title: test/unit/monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/persistent_segtree.test.cpp
    title: test/unit/persistent_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/segtree_beats.test.cpp
    title: test/unit/segtree_beats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/sparse_table.test.cpp
    title: test/unit/sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/sqrt_tree.test.cpp
    title: test/unit/sqrt_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/string_hash.test.cpp
    title: test/unit/string_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/weighted_dsu.test.cpp
    title: test/unit/weighted_dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/concept.hpp\"\n#include <concepts>\ntemplate <class\
    \ M>\nconcept semigroup = requires(typename M::S a, typename M::S b) {\n    {\
    \ M::op(a, b) } -> std::same_as<typename M::S>;\n};\ntemplate <class M>\nconcept\
    \ monoid = semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename\
    \ M::S>;\n};\ntemplate <class G>\nconcept group = monoid<G> && requires(typename\
    \ G::S a) {\n    { G::inv(a) } -> std::same_as<typename G::S>;\n};\ntemplate <class\
    \ A>\nconcept action = requires(typename A::F f, typename A::F g) {\n    { A::composition(f,\
    \ g) } -> std::same_as<typename A::F>;\n    { A::id() } -> std::same_as<typename\
    \ A::F>;\n    { A::composition_commutative } -> std::convertible_to<bool>;\n};\n\
    template <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
    \ A::S x, typename A::F f) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n};\ntemplate <class R>\nconcept semiring = requires(typename R::S a,\
    \ typename R::S b) {\n    { R::add(a, b) } -> std::same_as<typename R::S>;\n \
    \   { R::zero() } -> std::same_as<typename R::S>;\n    { R::mul(a, b) } -> std::same_as<typename\
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\ntemplate <class\
    \ A>\nconcept beats_acted_monoid = acted_monoid<A> && requires(typename A::S x)\
    \ {\n    { x.fail } -> std::convertible_to<bool>;\n};\n"
  code: "#pragma once\n#include <concepts>\ntemplate <class M>\nconcept semigroup\
    \ = requires(typename M::S a, typename M::S b) {\n    { M::op(a, b) } -> std::same_as<typename\
    \ M::S>;\n};\ntemplate <class M>\nconcept monoid = semigroup<M> && requires {\n\
    \    { M::e() } -> std::same_as<typename M::S>;\n};\ntemplate <class G>\nconcept\
    \ group = monoid<G> && requires(typename G::S a) {\n    { G::inv(a) } -> std::same_as<typename\
    \ G::S>;\n};\ntemplate <class A>\nconcept action = requires(typename A::F f, typename\
    \ A::F g) {\n    { A::composition(f, g) } -> std::same_as<typename A::F>;\n  \
    \  { A::id() } -> std::same_as<typename A::F>;\n    { A::composition_commutative\
    \ } -> std::convertible_to<bool>;\n};\ntemplate <class A>\nconcept acted_monoid\
    \ = monoid<A> && action<A> && requires(typename A::S x, typename A::F f) {\n \
    \   { A::mapping(f, x) } -> std::same_as<typename A::S>;\n};\ntemplate <class\
    \ R>\nconcept semiring = requires(typename R::S a, typename R::S b) {\n    { R::add(a,\
    \ b) } -> std::same_as<typename R::S>;\n    { R::zero() } -> std::same_as<typename\
    \ R::S>;\n    { R::mul(a, b) } -> std::same_as<typename R::S>;\n    { R::one()\
    \ } -> std::same_as<typename R::S>;\n};\ntemplate <class A>\nconcept beats_acted_monoid\
    \ = acted_monoid<A> && requires(typename A::S x) {\n    { x.fail } -> std::convertible_to<bool>;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/concept.hpp
  requiredBy:
  - graph/lowest_common_ancestor.hpp
  - graph/manhattan_mst.hpp
  - math/matrix.hpp
  - datastructure/segtree.hpp
  - datastructure/segtree_beats.hpp
  - datastructure/sqrt_tree.hpp
  - datastructure/persistent_segtree.hpp
  - datastructure/dual_segtree.hpp
  - datastructure/sparse_table.hpp
  - datastructure/lazy_segtree.hpp
  - datastructure/plus_minus_one_rmq.hpp
  - datastructure/dynamic_segtree.hpp
  - datastructure/weighted_dsu.hpp
  timestamp: '2026-10-29 12:09:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/dynamic_segtree.test.cpp
  - test/unit/sqrt_tree.test.cpp
  - test/unit/segtree_beats.test.cpp
  - test/unit/weighted_dsu.test.cpp
  - test/unit/string_hash.test.cpp
  - test/unit/matrix.test.cpp
  - test/unit/sparse_table.test.cpp
  - test/unit/dual_segtree.test.cpp
  - test/unit/monoid.test.cpp
  - test/unit/persistent_segtree.test.cpp
  - test/unit/linear_algebra.test.cpp
  - test/library-checker/staticrmq_sqrt_tree.test.cpp
  - test/library-checker/range_affine_point_get.test.cpp
  - test/library-checker/staticrmq.test.cpp
  - test/library-checker/inverse_matrix.test.cpp
  - test/library-checker/point_add_range_sum_dynamic_segtree.test.cpp
  - test/library-checker/system_of_linear_equations.test.cpp
  - test/library-checker/pow_of_matrix.test.cpp
  - test/library-checker/lca.test.cpp
  - test/library-checker/manhattanmst.test.cpp
  - test/library-checker/matrix_det.test.cpp
  - test/library-checker/range_chmin_chmax_add_range_sum.test.cpp
  - test/library-checker/unionfind_with_potential_non_commutative_group.test.cpp
  - test/library-checker/unionfind_with_potential.test.cpp
  - test/library-checker/matrix_product.test.cpp
  - test/library-checker/point_set_range_composite.test.cpp
  - test/library-checker/matrix_rank.test.cpp
  - test/aoj/0355.test.cpp
  - test/aoj/DSL_2_G.test.cpp
  - test/aoj/DSL_2_A.test.cpp
documentation_of: algebra/concept.hpp
layout: document
title: 'Algebra: Concept'
---

### 概要
- `segtree`, `lazy_segtree`, `dual_segtree`, `sparse_table`, `semiring_matrix`, `weighted_dsu` に渡す構造体の要件。

### 使い方
- `semigroup<M>`: `M::S` と `M::op(S, S) -> S` を持つ。
- `monoid<M>`: `semigroup<M>` に加えて `M::e() -> S` を持つ。
- `group<G>`: `monoid<G>` に加えて `G::inv(S) -> S` を持つ。
- `action<A>`: `A::F`, `A::composition(F, F) -> F`, `A::id() -> F`, `bool A::composition_commutative` を持つ。
- `acted_monoid<A>`: `monoid<A>` と `action<A>` に加えて `A::mapping(F, S) -> S` を持つ。
- `semiring<R>`: `R::S`, `R::add(S, S) -> S`, `R::zero() -> S`, `R::mul(S, S) -> S`, `R::one() -> S` を持つ。
