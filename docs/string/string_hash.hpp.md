---
title: String Hash
documentation_of: string/string_hash.hpp
---

### 概要
- 文字列のハッシュ値。`rolling_hash` と `range_update_range_hash` が返す。

### 使い方
- `string_hash<k = 1, mint = modint2305843009213693951>`: 基数 $k$ 個でのハッシュ値。`val[i]` が $i$ 番目の基数での値、`len` が文字列の長さ。
- `string_hash()`: 空文字列のハッシュ値を作る。
- `string_hash(c)`: 1 文字 `c` のハッシュ値を作る。
- `string_hash::repeat(c, n)`: 文字 `c` を $n$ 個並べた文字列のハッシュ値を返す。
- `a + b`: 連結した文字列のハッシュ値を返す。
- `a == b`: 長さと `val` がすべて等しいかを返す。
- `a < b`: `set` や `map` のキーにするための全順序。
- `lcp(a, l1, r1, b, l2, r2)`: `a` の `[l1, r1)` と `b` の `[l2, r2)` の最長共通接頭辞の長さを返す。`a`, `b` は `rolling_hash` か `range_update_range_hash`。
- `cmp(a, l1, r1, b, l2, r2)`: `a` の `[l1, r1)` と `b` の `[l2, r2)` を辞書順で比較し、$-1, 0, 1$ のいずれかを返す。

### 制約
- 文字は $0 \le c <$ `mint::mod()`

### 計算量
- `a + b`, `repeat`: $\mathcal{O}(k)$
- `lcp`, `cmp`: `prod` を $\mathcal{O}(\log N)$ 回
