---
title: Trie
documentation_of: string/trie.hpp
---

### 概要
- 文字列の多重集合を木で持つ。ノードは根を $0$ とする作成順の番号で扱う。

### 使い方
- `trie<sigma, base>()`: 文字が `base, ..., base + sigma - 1` の空の trie を作る。
- `size()`: ノード数を返す。
- `insert(s)`: `s` を 1 個追加し、`s` の終端ノードを返す。
- `erase(s)`: `s` を 1 個削除する。
- `find(s)`: `s` の終端ノードを返す。`s` を接頭辞に持つ文字列が無ければ `-1`。
- `next(v, c)`: ノード `v` から文字 `c` で進んだノードを返す。無ければ `-1`。
- `parent(v)`: ノード `v` の親を返す。根なら `-1`。
- `depth(v)`: ノード `v` の深さを返す。
- `count(v)`: ノード `v` で終わる文字列の個数を返す。
- `count_prefix(v)`: ノード `v` を通る文字列の個数を返す。

### 制約
- `s` の各文字 `c` は $\text{base} \le c < \text{base} + \sigma$
- `erase`: `count(find(s))` $\ge 1$
- $0 \le v <$ `size()`

### 計算量
- `insert`, `erase`, `find`: $\mathcal{O}(\lvert s \rvert)$
- その他: $\mathcal{O}(1)$
