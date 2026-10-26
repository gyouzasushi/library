---
title: Aho-Corasick
documentation_of: string/aho_corasick.hpp
---

### 概要
- trie の文字列集合を pattern とするオートマトン。状態は trie のノード番号。

### 使い方
- `aho_corasick<sigma, base>(t)`: trie `t` の現在の中身から構築する。
- `size()`: 状態数を返す。
- `next(v, c)`: 状態 `v` で文字 `c` を読んだ次の状態を返す。
- `fail(v)`: 状態 `v` の文字列の真の接尾辞のうち trie のノードである最長のものを返す。根なら `-1`。
- `count(v)`: 状態 `v` の文字列を接尾辞に持つ pattern の個数を返す。
- `order()`: 状態を深さの昇順に並べた列を返す。

### 制約
- `c` は $\text{base} \le c < \text{base} + \sigma$
- $0 \le v <$ `size()`

### 計算量
- 構築: $\mathcal{O}(\sigma \cdot \text{size}())$
- その他: $\mathcal{O}(1)$
