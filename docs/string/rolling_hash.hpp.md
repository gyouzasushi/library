---
title: Rolling Hash
documentation_of: string/rolling_hash.hpp
---

### 概要
- ハッシュを用いて文字列の一致判定を高速に行う。
  
### 使い方
- `RollingHash<base_num, mint>::from(s)`: 文字列 `s` のローリングハッシュを構築する。`base_num` 個の基数を用いて、`mint` でハッシュを計算する。デフォルトは、`base_num = 1, mint = modint2305843009213693951`。
- `rlh(l, r)`: `s[l..r]` のハッシュ値を求める。
- `lcp(l1, r1, l2, r2)`: `s[l1..r1]` と `s[l2..r2]` の LCP の長さを求める。
- `RollingHash<>::lcp(rh1, l1, r1, rh2, l2, r2)`: `s1[l1..r1]` と `s2[l2..r2]` の LCP の長さを求める。
- `cmp(l1, r1, l2, r2)`: `s1 = s[l1..r1]` と `s2 = s[l2..r2]` を辞書順で比較する。返り値は、`s1 < s2 ? -1 : s1 == s2 ? 0 : 1`。
- `RollingHash<>::cmp(rh1, l1, r1, rh2, l2, r2)`: `s1[l1..r1]` と `s2[l2..r2]` を辞書順で比較する。
- `RollingHash<>::concat(h1, h2, h2_len)`: ハッシュ値が `h1` の文字列と、ハッシュ値が `h2` で長さが `h2_len` の文字列を連結した文字列のハッシュ値を求める。

### 計算量
- 構築: $\mathcal{O}(N)$
- クエリ: $\mathcal{O}(1)$
- `lcp`: $\mathcal{O}(\log N)$
- `cmp`: $\mathcal{O}(\log N)$
- `concat`: $\mathcal{O}(1)$