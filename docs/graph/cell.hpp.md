---
title: グリッドのマス
documentation_of: graph/cell.hpp
---

### 概要
- グリッドのマスを表す構造体。

### 使い方
- `cell::set_bound(height, width)`: 範囲を `[0, height)` $\times$ `[0, width)` にする。
- `cell::set_bound(min_y, min_x, max_y, max_x)`: 範囲を `[min_y, max_y]` $\times$ `[min_x, max_x]` にする。
- `cell::height()`, `cell::width()`, `cell::size()`: 範囲の高さ・幅・マス数。
- `cell(y, x)`: 座標からマスを作る。
- `cell(i)`: 辞書順で `i` 番目のマスを作る。
- `operator int()`: マスが辞書順で何番目かを返す。`d[v]` のように配列の添字にそのまま使える。
- `cell::cells()`: 全マスを辞書順で列挙する。
- `is_valid()`: 範囲内か判定する。
- `neighbors()`, `neighbors_8()`: 範囲内の 4 近傍・8 近傍。range-for で回す。
- `cell::delta`, `cell::delta_8`: 近傍への変位 `(dy, dx)` の `std::pair`。
- `u + d`, `u - d`: `(dy, dx)` だけ移動したマス。範囲外のマスも作れるので、必要なら `is_valid()` で確かめる。
- `==`, `!=`

```cpp
cell::set_bound(h, w);
std::vector<int> d(cell::size(), -1);
for (cell v : u.neighbors()) { ... }
for (auto [dy, dx] : cell::delta) {
    cell v = cell(u.y + dy * k, u.x + dx * k);
    if (!v.is_valid()) continue;
}
```
