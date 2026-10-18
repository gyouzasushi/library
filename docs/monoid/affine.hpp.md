---
title: "Monoid: Affine"
documentation_of: monoid/affine.hpp
---

### 概要
- 一次関数 $f(x) = ax + b$ の合成モノイド。`prod(l, r)` は $f_{r-1} \circ \cdots \circ f_l$、すなわち $f_l$ を最初に適用する合成になる。

### 使い方
- `S = {T a, b}`, `op(f, g) = g ∘ f`, `e() = {1, 0}`
- `eval(f, x)`: $f(x)$ を返す。
- `commutative = false`
