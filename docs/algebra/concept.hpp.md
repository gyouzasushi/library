---
title: "Algebra: Concept"
documentation_of: algebra/concept.hpp
---

### 概要
- `segtree`, `lazy_segtree`, `dual_segtree`, `sparse_table`, `semiring_matrix` に渡す構造体の要件。

### 使い方
- `semigroup<M>`: `M::S` と `M::op(S, S) -> S` を持つ。
- `monoid<M>`: `semigroup<M>` に加えて `M::e() -> S` を持つ。
- `action<A>`: `A::F`, `A::composition(F, F) -> F`, `A::id() -> F`, `bool A::composition_commutative` を持つ。
- `acted_monoid<A>`: `monoid<A>` と `action<A>` に加えて `A::mapping(F, S) -> S` を持つ。
- `semiring<R>`: `R::S`, `R::add(S, S) -> S`, `R::zero() -> S`, `R::mul(S, S) -> S`, `R::one() -> S` を持つ。
