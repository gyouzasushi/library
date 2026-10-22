---
title: "Geometry: Polygon"
documentation_of: geometry/polygon.hpp
---

### 概要
- 多角形と点集合のアルゴリズム。

### 使い方
- `geo::polygon<T>`: `std::vector<geo::point<T>>`。頂点を順に並べる。
- `area2(poly)`: 符号付き面積の 2 倍を返す。反時計回りで正。
- `area(poly)`: 符号付き面積を返す。浮動小数点型のみ。
- `is_convex(poly)`: 反時計回りの凸多角形かを返す。$180^\circ$ の角を許す。
- `contains(poly, p)`: 点 `p` が多角形の内部なら $2$、辺上なら $1$、外部なら $0$ を返す。
- `convex_hull(ps, strict = true)`: 点集合 `ps` の凸包を反時計回りで返す。`strict` なら辺上の点を含まない。
- `farthest_pair(ps)`: 最遠点対の添字を返す。
- `closest_pair(ps)`: 最近点対の添字を返す。
- `convex_cut(poly, l)`: 凸多角形 `poly` を直線 `l` で切った左側を返す。浮動小数点型のみ。

### 制約
- `farthest_pair`, `closest_pair` では $\lvert \mathrm{ps} \rvert \ge 2$
- `convex_cut` では `poly` は反時計回りの凸多角形

### 計算量
- `area2`, `area`, `is_convex`, `contains`, `convex_cut`: $\mathcal{O}(N)$
- `convex_hull`, `farthest_pair`, `closest_pair`: $\mathcal{O}(N \log N)$

### 問題例
Library Checker - Static Convex Hull（[問題](https://judge.yosupo.jp/problem/static_convex_hull)）

```cpp
std::vector<geo::point<long long>> ps(n);
for (auto& p : ps) std::cin >> p;
geo::polygon<long long> ch = geo::convex_hull(ps);
```
