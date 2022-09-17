---
title: 高速ゼータ変換・高速メビウス変換
documentation_of: math/zeta_mobius_transform.hpp
---

### 使い方
- `superset_zeta(f)`: `f` を $g(S) = \displaystyle \sum_{S\subset T}f(T)$ となる `g` に置き換える。
- `superset_mobius(f)`: `f` を $f(S) = \displaystyle \sum_{S \subset T}g(T)$ となる `g` に置き換える。
- `subset_zeta(f)`: `f` を $g(S) = \displaystyle \sum_{S \supset T}f(T)$ となる `g` に置き換える。
- `subset_mobius(f)`: `f` を $f(S) = \displaystyle \sum_{S \supset T}g(T)$ となる `g` に置き換える。
  
### 制約
- ある非負整数 $n$ が存在して $\|f\|=2^n$ 。