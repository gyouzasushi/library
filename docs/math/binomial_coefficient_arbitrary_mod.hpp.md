---
title: Binomial Coefficient (Arbitrary Mod)
documentation_of: math/binomial_coefficient_arbitrary_mod.hpp
---

### 概要
- 任意 mod（合成数 OK）に対する二項係数 $\binom{n}{k} \bmod m$ を計算する。
- mod を素因数分解し、各素数べきに対して Lucas の定理（の一般化）で計算したものを CRT で合成する。

### 使い方
- `binomial_coefficient_arbitrary_mod<id = -1>`: mod を実行時に切り替える。`id` を変えれば独立した静的状態を持てる（`atcoder::dynamic_modint` と同じ流儀）。
- `set_mod(mod)`: mod を設定する。キャッシュもリセットされる。
- `C(n, k)`: $\binom{n}{k} \bmod m$ を `long long` で返す。

### 注意
- 同じ `id` に対して `set_mod` を呼び直すと過去のキャッシュは無効化される。複数 mod を同時に扱いたい場合は `id` を分けてインスタンス化する。
