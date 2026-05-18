---
title: Combinatorics
documentation_of: math/combinatorics.hpp
---

### 概要
- 階乗・逆階乗をキャッシュしながら二項係数・順列・重複組合せを計算するデータ構造。
- 素数 mod の `mint` に対応。

### 使い方
- `combinatorics<mint>`: 型 `mint` 上で動く。全 static。
- `val(i)`: $i!$ を返す。
- `inv(i)`: $1 / i!$ を返す。
- `C(n, k)`: $\binom{n}{k}$ を返す。
- `P(n, k)`: ${}_nP_k = n! / (n-k)!$ を返す。
- `H(n, k)`: ${}_nH_k = \binom{n+k-1}{k}$（重複組合せ）を返す。
- `ensure(n)`: 階乗テーブルを少なくとも $n$ まで構築する。

### 呼び出しを短縮するイディオム
`combinatorics<mint>::C(n, k)` が長いと感じる場合、関数参照に束ねると call site が短くなる。

```cpp
using mint = atcoder::modint998244353;
using combi = combinatorics<mint>;
constexpr auto& C = combi::C;
constexpr auto& P = combi::P;
constexpr auto& H = combi::H;

// 以降は単に
mint x = C(n, k);
```
