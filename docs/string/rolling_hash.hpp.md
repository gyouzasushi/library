---
title: Rolling Hash
documentation_of: string/rolling_hash.hpp
---

### 概要
- 静的な文字列の部分文字列のハッシュ値を求める。

### 使い方
- `rolling_hash<k = 1, mint = modint2305843009213693951>(s)`: 文字列 `s` で構築する。`s` は `std::string` か `std::vector<int>`。
- `size()`: `s` の長さを返す。
- `prod(l, r)`: `s[l, r)` のハッシュ値を返す。
- `get(p)`: `s[p]` のハッシュ値を返す。
- `all_prod()`: `s` のハッシュ値を返す。

### 制約
- $0 \le l \le r \le n$
- $0 \le p < n$

### 計算量
- 構築: $\mathcal{O}(kN)$
- `prod`, `get`, `all_prod`: $\mathcal{O}(k)$
