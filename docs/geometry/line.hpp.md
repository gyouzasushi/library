---
title: "Geometry: Line"
documentation_of: geometry/line.hpp
---

### 概要
- 直線と線分。

### 使い方
- `geo::line<T>(a, b)`: 点 `a`, `b` を通る直線。
- `geo::segment<T>(a, b)`: 点 `a`, `b` を端点とする線分。
- `to_line(s)`: 線分 `s` を含む直線を返す。
- `parallel(l, m)`, `orthogonal(l, m)`: 直線 `l`, `m` が平行か、直交するかを返す。
- `on_line(l, p)`, `on_segment(s, p)`: 点 `p` が直線 `l` 上、線分 `s` 上にあるかを返す。
- `intersect(l, m)`, `intersect(l, s)`, `intersect(s, t)`: 共有点があるかを返す。
- `projection(l, p)`, `reflection(l, p)`: 直線 `l` への点 `p` の射影、`l` に関する `p` の対称点を返す。
- `perpendicular_bisector(a, b)`: 線分 `ab` の垂直二等分線を返す。
- `dist(x, y)`: 点、直線、線分の任意の組の距離を返す。
- `cross_point(l, m)`, `cross_point(l, s)`, `cross_point(s, t)`: 交点を返す。交わらないときの動作は未定義。

### 制約
- `projection`, `reflection`, `perpendicular_bisector`, `dist`, `cross_point` は浮動小数点型のみ
- `cross_point(l, m)` では `l`, `m` が平行でない
- `cross_point(l, s)`, `cross_point(s, t)` では交点がただ 1 つ
