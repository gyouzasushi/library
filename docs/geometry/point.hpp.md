---
title: "Geometry: Point"
documentation_of: geometry/point.hpp
---

### 概要
- 2 次元の点。

### 使い方
- `geo::point<T>`: 座標の型 `T`。整数型と浮動小数点型を使える。
- `geo::eps`: 浮動小数点型の比較に使う誤差。初期値 $10^{-9}$。
- `sgn(a)`: `a` の符号を返す。浮動小数点型では `eps` 以下を $0$ とみなす。
- `p + q`, `p - q`, `p * k`, `p / k`, `-p`: ベクトルの演算。`p / k` は浮動小数点型のみ。
- `p == q`, `p < q`: 座標の比較。`<` は `x`, `y` の辞書順。
- `dot(p, q)`: 内積を返す。
- `cross(p, q)`: 外積 $p_x q_y - p_y q_x$ を返す。
- `norm(p)`: $|p|^2$ を返す。
- `abs(p)`: $|p|$ を返す。浮動小数点型のみ。
- `arg(p)`: 偏角 $\mathrm{atan2}(p_y, p_x)$ を返す。浮動小数点型のみ。
- `normal(p)`: `p` を $90^\circ$ 回転したベクトル $(-p_y, p_x)$ を返す。
- `unit(p)`: `p` と同じ向きの単位ベクトルを返す。浮動小数点型のみ。
- `rotate(p, theta)`: `p` を原点中心に `theta` 回転した点を返す。浮動小数点型のみ。
- `ccw(a, b, c)`: `cross(b - a, c - a)` の符号を返す。
- `arg_less`: 偏角 $(-\pi, \pi]$ の昇順に並べる比較関数。原点の偏角は $0$。

### 制約
- 整数型では $|x|, |y| \le 10^9$

### 問題例
Library Checker - Sort Points by Argument（[問題](https://judge.yosupo.jp/problem/sort_points_by_argument)）

```cpp
std::vector<geo::point<long long>> ps(n);
for (auto& p : ps) std::cin >> p;
std::sort(ps.begin(), ps.end(), geo::arg_less{});
```
