---
title: Xor Basis
documentation_of: math/xor_basis.hpp
---

### 概要
- 非負整数の集合が xor で張る空間 $V$ を扱う。

### 使い方
- `xor_basis<T = long long>()`: $V = \{0\}$ で初期化する。
- `insert(x)`: $V$ に `x` を加え、$V$ が広がったかを返す。
- `contains(x)`: `x` が $V$ に入るかを返す。
- `size()`: $V$ の次元を返す。$\lvert V \rvert = 2^{\mathrm{size}()}$。
- `max(xor_val = 0)`: $v \in V$ にわたる `v ^ xor_val` の最大値を返す。
- `min(xor_val = 0)`: $v \in V$ にわたる `v ^ xor_val` の最小値を返す。
- `kth_smallest(k, xor_val = 0)`: `v ^ xor_val` ($v \in V$) を昇順に並べたときの `k` 番目 (0-indexed) を返す。
- `kth_largest(k, xor_val = 0)`: `v ^ xor_val` ($v \in V$) を降順に並べたときの `k` 番目 (0-indexed) を返す。

### 制約
- `T` は整数型
- $0 \le x, \mathrm{xor\_val}$
- `kth_smallest`, `kth_largest`: $0 \le k < 2^{\mathrm{size}()}$

### 計算量
- 各操作: $\mathcal{O}(\mathrm{size}())$
