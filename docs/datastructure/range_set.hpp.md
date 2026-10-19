---
title: Range Set
documentation_of: datastructure/range_set.hpp
---

### 概要
- 互いに交わらない半開区間の集合。接する区間は 1 つにまとめる。

### 使い方
- `find(p)`: `p` を含む区間のイテレータ。無ければ `end()`。イテレータは `(l, r)` の pair を指す。
- `contains(p)`: `p` を含むか。
- `covers(l, r)`: `[l, r)` が 1 つの区間に含まれるか。
- `mex(x)`: `x` 以上で含まれない最小の値。整数向け。
- `insert(l, r)`: `[l, r)` を追加する。
- `insert(l, r, f, g)`: 追加のとき、新しくできた区間ごとに `f(l, r)` を、消えた区間ごとに `g(l, r)` を呼ぶ。
- `erase(l, r)`: `[l, r)` を削除する。
- `erase(l, r, f, g)`: 削除のとき、新しくできた区間ごとに `f(l, r)` を、消えた区間ごとに `g(l, r)` を呼ぶ。
- `size()`: 区間の個数。
- range-for で区間を昇順に列挙できる。
- 整数の集合として使うときは、整数 `a` 以上 `b` 以下を `[a, b + 1)` で表す。

### 計算量
- `insert`, `erase`: 償却 $\mathcal{O}(\log N)$
- `find`, `contains`, `covers`, `mex`: $\mathcal{O}(\log N)$
