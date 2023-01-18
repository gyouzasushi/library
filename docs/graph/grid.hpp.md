---
title: グリッド
documentation_of: graph/grid.hpp
---

### 概要
- グリッドを扱うのに便利な構造体。
  
### 使い方
- `grid::set_bound(height, width)`: `[0, height)` $\times$ `[0, width)` で初期化する。
- `grid::set_bound(min_y, min_x, max_y, max_x)`: `[min_y, max_y]` $\times$ `[min_x, max_x]` で初期化する。 
- `grid::grids()`: すべてのグリッドを辞書順で列挙する。
- `grid::from(i)`: 辞書順で `i` 番目のグリッドを求める。
- `operator int()`: グリッドが辞書順で何番目かを求める。
- `neighbors()`: グリッドの4近傍であって、範囲内のものを列挙する。
- `neighbors_8()`: グリッドの8近傍であって、範囲内のものを列挙する。