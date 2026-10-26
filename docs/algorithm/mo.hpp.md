---
title: Mo's Algorithm
documentation_of: algorithm/mo.hpp
---

### 概要
- 区間クエリをオフラインで処理する。

### 使い方
- `mo()`: クエリの無い状態で作る。
- `add(l, r)`: 区間 $[l, r)$ のクエリを追加し、クエリ番号を返す。番号は追加順。
- `run(add_left, add_right, erase_left, erase_right, out)`: 区間 $[0, 0)$ から始めて、区間を 1 要素ずつ動かしながら全クエリに答える。`add_left(i)`, `add_right(i)` は要素 $i$ を区間の左端, 右端に加え、`erase_left(i)`, `erase_right(i)` は要素 $i$ を区間の左端, 右端から除き、`out(q)` はクエリ $q$ に答える。区間は伸ばしてから縮める。
- `run(add, erase, out)`: 左右で同じ関数を使う。

### 制約
- $0 \le l \le r$

### 計算量
- `add`: $\mathcal{O}(1)$
- `run`: $\mathcal{O}(q \log q)$ に加えて `add_left` などを合計 $\mathcal{O}(n \sqrt{q})$ 回呼ぶ。$n$ は $r$ の最大値。
