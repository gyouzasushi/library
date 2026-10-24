---
title: Range Update Range Hash
documentation_of: string/range_update_range_hash.hpp
---

### 概要
- 区間を 1 文字で埋める更新ができる文字列の、部分文字列のハッシュ値を求める。

### 使い方
- `range_update_range_hash<k = 1, mint = modint2305843009213693951>(s)`: 文字列 `s` で構築する。`s` は `std::string` か `std::vector<int>`。
- `size()`: `s` の長さを返す。
- `set(p, c)`: `s[p]` を `c` に置き換える。
- `apply(l, r, c)`: `s[l, r)` をすべて `c` に置き換える。
- `prod(l, r)`: `s[l, r)` のハッシュ値を返す。
- `get(p)`: `s[p]` のハッシュ値を返す。
- `all_prod()`: `s` のハッシュ値を返す。

### 制約
- $0 \le l \le r \le n$
- $0 \le p < n$
- $0 \le c <$ `mint::mod()`

### 計算量
- 構築: $\mathcal{O}(kN)$
- `set`, `apply`, `prod`, `get`: $\mathcal{O}(k \log N)$
- `all_prod`: $\mathcal{O}(k)$
