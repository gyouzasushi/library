---
title: "Monoid: Concept"
documentation_of: monoid/concept.hpp
---

### 概要
- `segtree`, `lazy_segtree`, `sparse_table` に渡す構造体の要件。

### 使い方
- `semigroup<M>`: `M::S` と `M::op(S, S) -> S` を持つ。
- `monoid<M>`: `semigroup<M>` に加えて `M::e() -> S` を持つ。
- `acted_monoid<A>`: `monoid<A>` に加えて `A::F`, `A::mapping(F, S) -> S`, `A::composition(F, F) -> F`, `A::id() -> F` を持つ。
