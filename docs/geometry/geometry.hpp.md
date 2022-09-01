---
title: geomerty
documentation_of: geometry/geometry.hpp
---

- `using coordinate_t = double` しています。
- 全部 `namespace geometry` に入っているので、`using namespace geometry` するか `geometry::Point p;` みたいに書きます。 

*** 

## 定数

### PI
```
coordinate_t PI;
```
$\pi$ 。`std::acos(-1)` が入っています。
### EPS
```
coordinate_t EPS;
```
EPS。`1e-9` が入っています。

***

## Point
点。
### コンストラクタ
```
Point p(coordinate_t x, coordinate_t y);
```
### abs
```
coordinate_t p.abs()
```
ベクトル `p` の絶対値を返します。

### arg
```
coordinate_t p.arg()
```
点 `p` の偏角？`std::atan2(y, x)`を返します。

### normal
```
coordinate_t p.normal()
```
ベクトル `p` の法線ベクトル `(-y,x)` を返します。

### unit
```
coordinate_t p.unit()
```
ベクトル `p` と同じ向きの単位ベクトルを返します。

***

## Segment
線分。
### コンストラクタ
```
Segment s(Point a,Point b);
```
### vertical_bisector
```
Line s.vertical_bisector()
```
線分 `s` の垂直二等分線を返します。

***

## Line
直線。
### コンストラクタ
```
Line l(Point a,Point b);
```

### projection
```
Point l.projection(Point p)
```
点 `p` から直線 `l` に下ろした垂線の足を返します。

### reflection
```
Point l.reflection(Point p)
```
直線 `l` に関して点 `p` と対称な点を返します。

*** 

## Polygon
多角形。`std::vector<Point>` を継承しています。
### コンストラクタ
```
Polygon poly(n);
```
`std::vector` と同じ感じ。

### area
```
coordinate_t poly.area()
```
`poly` の面積を返します。

### is_convex
```
bool poly.is_convex()
```
`poly` が凸多角形かどうかを返します。

### diameter
```
coordinate_t poly.diameter()
```
`poly` の直径（＝最遠頂点対間距離）を返します。

<b>制約</b>
- `poly` は凸多角形。

### contain
```
int poly.contain(Point p)
```
点 `p` が多角形 `poly` の
- 外部にあるなら `0`
- 周上にあるなら `1`
- 内部にあるなら `2`

を返します。
「周上または内部にあるなら〜」は `if (poly.contain(p))` みたいに書けます。

***

## Circle
円。
### コンストラクタ
```
Circle cir(Point c, coordinate_t r);
```

### area
```
coordinate_t cir.area()
```
`cir` の面積を返します。

### contain
```
int cir.contain(Point p)
```
点 `p` が円 `cir` の
- 外部にあるなら `0`
- 周上にあるなら `1`
- 内部にあるなら `2`

を返します。
「周上または内部にあるなら〜」は `if (cir.contain(p))` みたいに書けます。

***

## 便利関数たち
### sgn
```
int sgn(coordinate_t x)
```
`x` の（誤差を見越した）符号を返します。

### ccw
```
int ccw(Point a, Point b, Point c)
```
点 `a`, `b` と点 `c` の位置関係を計算します。
- `a`→`b`→`c` が左に曲がるなら `1` （定数 `COUNTER_CLOCKWISE` ）
- `a`→`b`→`c` が右に曲がるなら `-1` （定数 `CLOCKWISE` ）
- `c`-`a`-`b` の順にまっすぐなら `-2` （定数 `ONLINE_BACK`）
- `a`-`c`-`b` の順にまっすぐなら `0` （定数 `ON_SEGMENT`）
- `a`-`b`-`c` の順にまっすぐなら `2` （定数 `ONLINE_FRONT`）

を返します。

### from_segment
```
Line from_segment(Segment s)
```
線分 `S` を延長した直線を返します。

### dist
```
coordinate_t dist(T t, U u)
```
二つの図形の距離を返します。

<b>制約</b>
- `T` `U` は `Point` `Segment` `Line` のどれか。

### intersect
```
bool intersect(T t, U u)
```
二つの図形が交点を持つかどうかを返します。

<b>制約</b>
- `T` `U` は `Segment` `Line` `Circle` のどれか。 

### cross_point 
```
Point cross_point(T t, U u)
```
線分・直線の交点を返します。

<b>制約</b>
- `T` `U` は `Segment` または `Line` 。

### cross_points 
```
(1) std::vector<Point> cross_points(T t, Circle c)
(2) std::vector<Point> cross_points(Circle c, T t)
```
円と線分・直線・円の交点たちを返します。
接している場合は、同じ点二つからなる `vector` を返します。

<b>制約</b>
- `T` は `Segment`  `Line`  `Circle` のどれか。

### incircle_of_triangle
```
(1) Circle incircle_of_triangle(Polygon poly)
(2) Circle incircle_of_triangle(Point a,Point b, Point c)
```
三角形の内接円を返します。

<b>制約</b>
- (1) のとき $|$ `poly` $| = 3$ 

### circumscribed_circle_of_triangle
```
(1) Circle circumscribed_circle_of_triangle(Polygon poly)
(2) Circle circumscribed_circle_of_triangle(Point a,Point b, Point c)
```
三角形の外接円を返します。

<b>制約</b>
- (1) のとき $|$ `poly` $| = 3$ 


### convex_hull
```
Polygon convex_hull(std::vector<Point> ps)
```
`Point` の集合 `ps` の凸包を返します。

<b>計算量</b>

- $O(n \log n)$

### smallest_enclosing_circle
```
Circle smallest_enclosing_circle(std::vector<Point> ps)
```
`Point` の集合 `ps` の最小包含円を返します。

[参考](https://tubo28.me/compprog/algorithm/minball/)

<b>計算量</b>

- 期待値 $O(n)$

### area_of_intersection
```
coordinate_t area_of_intersection(Circle c, Polygon p)
coordinate_t area_of_intersection(Polygon p, Circle c)
coordinate_t area_of_intersection(Circle c1, Circle c2)
```

二つの図形の共通部分の面積を返します。

### convex_cut_left / convex_cut_right
```
Polygon convex_cut_left(Polygon poly, Line l)
Polygon convex_cut_right(Polygon poly, Line l)
```
凸多角形を直線で切断したときに、左側（右側）にできる凸多角形を返します。

<b>制約</b>

- `Poly` は凸多角形。

### tangent_points
```
std::vector<Point> tangent_points(Circle c, Point p)
```
点 `p` を通る円 `c` の接線を求めます。接点たちを返します。
`p` が周上にある場合は`{p, p}` を返します。

<b>制約</b>
- 点 `p` は 円 `c` の周上または外部の点。

### count_common_tangent / common_tangents
```
(1) int count_common_tangent(Circle c1, Circle c2)
(2) std::vector<Point> common_tangents(Circle c1, Circle c2)
```
$(1)$ 二つの円の共通接線の本数を返します。
$(2)$ 二つの円の共通接線を求めます。円 `c1` における接点たちを返します。

### closest_pair
```
std::pair<coordinate_t, std::pair<Point, Point>> closest_pair(
    std::vector<Point> ps) 
```
`Point` の集合 `ps` の最近点対を求めます。
最小距離と最近点対のペアを返します。

<b>計算量</b>
- $O(n \log n)$