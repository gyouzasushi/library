---
title: Range Update Range Hash
documentation_of: string/range_update_range_hash.hpp
---

### 概要
- 区間更新に対応した Rolling-Hash。
  
### 使い方
- `range_update_range_hash<base_num, mint>::from(s)`: 文字列 `s` を初期値として構築する。`base_num` 個の基数を用いて、`mint` でハッシュを計算する。デフォルトは、`base_num = 1, mint = modint2305843009213693951`。
- `prod(l, r)`: `s[l..r]` のハッシュ値を求める。
- `all_prod()`: `s` のハッシュ値を求める。
- `apply(l, r, x)`: `s[l..r]` を `x` で置き換える。
- `set(p, x)`: `s[p]` を `x` で置き換える。
- `get(p)`: `s[p]` のハッシュ値を求める。
- `lcp(l1, r1, l2, r2)`: `s[l1..r1]` と `s[l2..r2]` の LCP の長さを求める。
- `cmp(l1, r1, l2, r2)`: `s1 = s[l1..r1]` と `s2 = s[l2..r2]` を辞書順で比較する。返り値は、`s1 < s2 ? -1 : s1 == s2 ? 0 : 1`。

### 計算量
- 構築: $\mathcal{O}(N)$
- `prod`: $\mathcal{O}(\log N)$
- `all_prod`: $\mathcal{O}(1)$
- `apply`: $\mathcal{O}(\log N)$
- `set`: $\mathcal{O}(\log N)$
- `get`: $\mathcal{O}(\log N)$
- `lcp`: $\mathcal{O}((\log N)^2)$
- `cmp`: $\mathcal{O}((\log N)^2)$