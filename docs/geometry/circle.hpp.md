---
title: "Geometry: Circle"
documentation_of: geometry/circle.hpp
---

### 概要
- 円。浮動小数点型のみ。

### 使い方
- `geo::circle<T>(c, r)`: 中心 `c`、半径 `r` の円。
- `area(o)`: 面積を返す。
- `contains(o, p)`: 点 `p` が円の内部なら $2$、円周上なら $1$、外部なら $0$ を返す。
- `intersect(o, l)`, `intersect(o, s)`, `intersect(a, b)`: 直線、線分、円と共有点があるかを返す。
- `count_common_tangents(a, b)`: 円 `a`, `b` の共通接線の本数を返す。
- `cross_points(o, l)`, `cross_points(o, s)`, `cross_points(a, b)`: 直線、線分、円との交点を `x`, `y` の辞書順で返す。接するときは同じ点を 2 つ返す。
- `tangent_points(o, p)`: 点 `p` から円 `o` に引いた接線の接点を返す。
- `common_tangents(a, b)`: 円 `a`, `b` の共通接線の、円 `a` 上の接点を返す。
- `incircle(a, b, c)`, `circumcircle(a, b, c)`: 三角形 `abc` の内接円、外接円を返す。
- `smallest_enclosing_circle(ps)`: 点集合 `ps` を含む最小の円を返す。
- `area_of_intersection(o, poly)`, `area_of_intersection(a, b)`: 円と多角形、円と円の共通部分の面積を返す。
- `circle_of_apollonius(a, b, n, m)`: 点 `a`, `b` からの距離の比が $n : m$ である点の軌跡を返す。

### 制約
- `tangent_points(o, p)` では `p` は円の外部または円周上
- `circle_of_apollonius` では $n \ne m$

### 計算量
- `smallest_enclosing_circle`: 期待 $\mathcal{O}(N)$
- `area_of_intersection(o, poly)`: $\mathcal{O}(N)$
- その他: $\mathcal{O}(1)$
