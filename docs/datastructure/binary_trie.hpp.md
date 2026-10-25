---
title: Binary Trie
documentation_of: datastructure/binary_trie.hpp
---

### 概要
- 非負整数の多重集合。各要素と `xor_val` との xor をとった値の順序で問い合わせる。

### 使い方
- `binary_trie<log>()`: $[0, 2^{\text{log}})$ の整数を入れる空の多重集合を作る。
- `size()`: 要素数を返す。
- `insert(x, k = 1)`: `x` を `k` 個追加する。
- `erase(x, k = 1)`: `x` を `k` 個削除する。
- `count(x)`: `x` の個数を返す。
- `count_less(upper, xor_val = 0)`: `(a ^ xor_val) < upper` となる要素 `a` の個数を返す。
- `kth_smallest(k, xor_val = 0)`: `a ^ xor_val` を昇順に並べたときの `k` 番目 (0-indexed) を返す。
- `kth_largest(k, xor_val = 0)`: `a ^ xor_val` を降順に並べたときの `k` 番目 (0-indexed) を返す。
- `min(xor_val = 0)`: `a ^ xor_val` の最小値を返す。
- `max(xor_val = 0)`: `a ^ xor_val` の最大値を返す。

### 制約
- $1 \le \text{log} \le 62$
- $0 \le x, \text{xor\_val} < 2^{\text{log}}$
- `erase`: $0 \le k \le$ `count(x)`
- `kth_smallest`, `kth_largest`: $0 \le k <$ `size()`
- `min`, `max`: $1 \le$ `size()`

### 計算量
- 各操作: $\mathcal{O}(\text{log})$
