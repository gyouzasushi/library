---
title: Manhattan MST
documentation_of: graph/manhattan_mst.hpp
---

### 概要
- 2次元平面上にある $N$ 個の点に対して、2点間の距離をマンハッタン距離で定義したときの最小全域木を求める。
  
### 使い方
- `manhattan_mst(x, y)`: 最小全域木に含まれ得る $O(N)$ 本の辺 `(u, v, w)` を、重みの昇順で返す。 