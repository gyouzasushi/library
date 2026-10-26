---
title: 高速ゼータ変換・高速メビウス変換
documentation_of: math/zeta_mobius_transform.hpp
---

### 概要
- 集合を添字とする数列について、上位集合・下位集合にわたる和とその逆変換を求める。

### 使い方
- `superset_zeta(f)`: `f` を $g(S) = \displaystyle \sum_{S \subseteq T} f(T)$ で置き換える。
- `superset_mobius(f)`: `f` を $f(S) = \displaystyle \sum_{S \subseteq T} g(T)$ となる `g` で置き換える。
- `subset_zeta(f)`: `f` を $g(S) = \displaystyle \sum_{T \subseteq S} f(T)$ で置き換える。
- `subset_mobius(f)`: `f` を $f(S) = \displaystyle \sum_{T \subseteq S} g(T)$ となる `g` で置き換える。

### 制約
- $\lvert f \rvert = 2^n$ ($0 \le n$)

### 計算量
- $\mathcal{O}(2^n n)$
