---
title: Dynamic Li Chao Tree
documentation_of: datastructure/dynamic_li_chao_tree.hpp
---

### 概要
- 直線・線分の追加と最小値取得ができるデータ構造。

### 使い方
- `dynamic_li_chao_tree(min_index = -1e9, max_index = 1e9)`: `min-index`$\le x \le$ `max_index` として初期化する。
- `add_line(a, b)`: 直線 `a`$x+$`b` を追加する。
- `add_segment(a, b, l, r)`: 線分 `a`$x+$`b`（ただし $x\in[$`l`$,$`r`$)$）を追加する。
- `get(x)`: $x =$ `x` での $y$ 座標の最小を求める。