---
title: Rectangle Sum
documentation_of: datastructure/rectangle_sum.hpp
---

### 概要
- 静的な点集合に対し、長方形に含まれる点の個数・重み和を求める。

### 使い方
- `rectangle_sum<T>(points)`: 点 `(x, y)` の列で構築する。
- `rectangle_sum<T, S>(points)`: 重み付きの点 `(x, y, w)` の列で構築する。
- `size()`: 点の個数を返す。
- `count(x1, x2, y1, y2)`: `x1 <= x < x2` かつ `y1 <= y < y2` を満たす点の個数を返す。
- `sum(x1, x2, y1, y2)`: `x1 <= x < x2` かつ `y1 <= y < y2` を満たす点の重みの和を返す。`S` を指定したときのみ。

### 制約
- `T` は `<` で比較できる
- `S` は `+`, `-` ができる

### 計算量
- 構築: $\mathcal{O}(N \log N)$
- `count`, `sum`: $\mathcal{O}(\log N)$
