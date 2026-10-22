---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: 'Geometry: Circle'
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: 'Geometry: Line'
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: 'Geometry: Polygon'
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_A.test.cpp
    title: test/aoj/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_B.test.cpp
    title: test/aoj/CGL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_C.test.cpp
    title: test/aoj/CGL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_A.test.cpp
    title: test/aoj/CGL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_B.test.cpp
    title: test/aoj/CGL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_C.test.cpp
    title: test/aoj/CGL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_D.test.cpp
    title: test/aoj/CGL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_A.test.cpp
    title: test/aoj/CGL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_B.test.cpp
    title: test/aoj/CGL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_C.test.cpp
    title: test/aoj/CGL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_A.test.cpp
    title: test/aoj/CGL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_B.test.cpp
    title: test/aoj/CGL_4_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_C.test.cpp
    title: test/aoj/CGL_4_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_A.test.cpp
    title: test/aoj/CGL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_B.test.cpp
    title: test/aoj/CGL_7_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_C.test.cpp
    title: test/aoj/CGL_7_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_D.test.cpp
    title: test/aoj/CGL_7_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_E.test.cpp
    title: test/aoj/CGL_7_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_F.test.cpp
    title: test/aoj/CGL_7_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_G.test.cpp
    title: test/aoj/CGL_7_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_H.test.cpp
    title: test/aoj/CGL_7_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_I.test.cpp
    title: test/aoj/CGL_7_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/closest_pair.test.cpp
    title: test/library-checker/closest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/sort_points_by_argument.test.cpp
    title: test/library-checker/sort_points_by_argument.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/static_convex_hull.test.cpp
    title: test/library-checker/static_convex_hull.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/geometry.test.cpp
    title: test/unit/geometry.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/point.hpp\"\n#include <cmath>\n#include <concepts>\n\
    #include <iostream>\n#include <type_traits>\nnamespace geo {\ninline long double\
    \ eps = 1e-9;\ntemplate <class T> int sgn(T a) {\n    if constexpr (std::is_integral_v<T>)\
    \ {\n        return (a > 0) - (a < 0);\n    } else {\n        return a < -eps\
    \ ? -1 : a > eps ? 1 : 0;\n    }\n}\ntemplate <class T> struct point {\n    T\
    \ x, y;\n    point() : x(0), y(0) {\n    }\n    point(T x, T y) : x(x), y(y) {\n\
    \    }\n    point& operator+=(const point& p) {\n        x += p.x, y += p.y;\n\
    \        return *this;\n    }\n    point& operator-=(const point& p) {\n     \
    \   x -= p.x, y -= p.y;\n        return *this;\n    }\n    point& operator*=(T\
    \ k) {\n        x *= k, y *= k;\n        return *this;\n    }\n    point& operator/=(T\
    \ k) requires std::floating_point<T> {\n        x /= k, y /= k;\n        return\
    \ *this;\n    }\n    point operator-() const {\n        return point(-x, -y);\n\
    \    }\n    friend point operator+(point a, const point& b) {\n        return\
    \ a += b;\n    }\n    friend point operator-(point a, const point& b) {\n    \
    \    return a -= b;\n    }\n    friend point operator*(point a, T k) {\n     \
    \   return a *= k;\n    }\n    friend point operator*(T k, point a) {\n      \
    \  return a *= k;\n    }\n    friend point operator/(point a, T k) requires std::floating_point<T>\
    \ {\n        return a /= k;\n    }\n    friend bool operator==(const point& a,\
    \ const point& b) {\n        return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;\n\
    \    }\n    friend bool operator!=(const point& a, const point& b) {\n       \
    \ return !(a == b);\n    }\n    friend bool operator<(const point& a, const point&\
    \ b) {\n        if (sgn(a.x - b.x) != 0) return a.x < b.x;\n        return sgn(a.y\
    \ - b.y) < 0;\n    }\n    friend bool operator>(const point& a, const point& b)\
    \ {\n        return b < a;\n    }\n    friend std::istream& operator>>(std::istream&\
    \ is, point& p) {\n        return is >> p.x >> p.y;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const point& p) {\n        return os << p.x <<\
    \ ' ' << p.y;\n    }\n};\ntemplate <class T> T dot(const point<T>& a, const point<T>&\
    \ b) {\n    return a.x * b.x + a.y * b.y;\n}\ntemplate <class T> T cross(const\
    \ point<T>& a, const point<T>& b) {\n    return a.x * b.y - a.y * b.x;\n}\ntemplate\
    \ <class T> T norm(const point<T>& p) {\n    return p.x * p.x + p.y * p.y;\n}\n\
    template <std::floating_point T> T abs(const point<T>& p) {\n    return std::sqrt(norm(p));\n\
    }\ntemplate <std::floating_point T> T arg(const point<T>& p) {\n    return std::atan2(p.y,\
    \ p.x);\n}\ntemplate <class T> point<T> normal(const point<T>& p) {\n    return\
    \ point<T>(-p.y, p.x);\n}\ntemplate <std::floating_point T> point<T> unit(const\
    \ point<T>& p) {\n    return p / abs(p);\n}\ntemplate <std::floating_point T>\
    \ point<T> rotate(const point<T>& p, T theta) {\n    T c = std::cos(theta), s\
    \ = std::sin(theta);\n    return point<T>(p.x * c - p.y * s, p.x * s + p.y * c);\n\
    }\ntemplate <class T> int ccw(const point<T>& a, const point<T>& b, const point<T>&\
    \ c) {\n    return sgn(cross(b - a, c - a));\n}\nstruct arg_less {\n    template\
    \ <class T> static int group(const point<T>& p) {\n        if (sgn(p.y) < 0) return\
    \ 0;\n        if (sgn(p.y) == 0 && sgn(p.x) >= 0) return 1;\n        return 2;\n\
    \    }\n    template <class T> bool operator()(const point<T>& a, const point<T>&\
    \ b) const {\n        if (group(a) != group(b)) return group(a) < group(b);\n\
    \        return sgn(cross(a, b)) > 0;\n    }\n};\n}  // namespace geo\n"
  code: "#pragma once\n#include <cmath>\n#include <concepts>\n#include <iostream>\n\
    #include <type_traits>\nnamespace geo {\ninline long double eps = 1e-9;\ntemplate\
    \ <class T> int sgn(T a) {\n    if constexpr (std::is_integral_v<T>) {\n     \
    \   return (a > 0) - (a < 0);\n    } else {\n        return a < -eps ? -1 : a\
    \ > eps ? 1 : 0;\n    }\n}\ntemplate <class T> struct point {\n    T x, y;\n \
    \   point() : x(0), y(0) {\n    }\n    point(T x, T y) : x(x), y(y) {\n    }\n\
    \    point& operator+=(const point& p) {\n        x += p.x, y += p.y;\n      \
    \  return *this;\n    }\n    point& operator-=(const point& p) {\n        x -=\
    \ p.x, y -= p.y;\n        return *this;\n    }\n    point& operator*=(T k) {\n\
    \        x *= k, y *= k;\n        return *this;\n    }\n    point& operator/=(T\
    \ k) requires std::floating_point<T> {\n        x /= k, y /= k;\n        return\
    \ *this;\n    }\n    point operator-() const {\n        return point(-x, -y);\n\
    \    }\n    friend point operator+(point a, const point& b) {\n        return\
    \ a += b;\n    }\n    friend point operator-(point a, const point& b) {\n    \
    \    return a -= b;\n    }\n    friend point operator*(point a, T k) {\n     \
    \   return a *= k;\n    }\n    friend point operator*(T k, point a) {\n      \
    \  return a *= k;\n    }\n    friend point operator/(point a, T k) requires std::floating_point<T>\
    \ {\n        return a /= k;\n    }\n    friend bool operator==(const point& a,\
    \ const point& b) {\n        return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;\n\
    \    }\n    friend bool operator!=(const point& a, const point& b) {\n       \
    \ return !(a == b);\n    }\n    friend bool operator<(const point& a, const point&\
    \ b) {\n        if (sgn(a.x - b.x) != 0) return a.x < b.x;\n        return sgn(a.y\
    \ - b.y) < 0;\n    }\n    friend bool operator>(const point& a, const point& b)\
    \ {\n        return b < a;\n    }\n    friend std::istream& operator>>(std::istream&\
    \ is, point& p) {\n        return is >> p.x >> p.y;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const point& p) {\n        return os << p.x <<\
    \ ' ' << p.y;\n    }\n};\ntemplate <class T> T dot(const point<T>& a, const point<T>&\
    \ b) {\n    return a.x * b.x + a.y * b.y;\n}\ntemplate <class T> T cross(const\
    \ point<T>& a, const point<T>& b) {\n    return a.x * b.y - a.y * b.x;\n}\ntemplate\
    \ <class T> T norm(const point<T>& p) {\n    return p.x * p.x + p.y * p.y;\n}\n\
    template <std::floating_point T> T abs(const point<T>& p) {\n    return std::sqrt(norm(p));\n\
    }\ntemplate <std::floating_point T> T arg(const point<T>& p) {\n    return std::atan2(p.y,\
    \ p.x);\n}\ntemplate <class T> point<T> normal(const point<T>& p) {\n    return\
    \ point<T>(-p.y, p.x);\n}\ntemplate <std::floating_point T> point<T> unit(const\
    \ point<T>& p) {\n    return p / abs(p);\n}\ntemplate <std::floating_point T>\
    \ point<T> rotate(const point<T>& p, T theta) {\n    T c = std::cos(theta), s\
    \ = std::sin(theta);\n    return point<T>(p.x * c - p.y * s, p.x * s + p.y * c);\n\
    }\ntemplate <class T> int ccw(const point<T>& a, const point<T>& b, const point<T>&\
    \ c) {\n    return sgn(cross(b - a, c - a));\n}\nstruct arg_less {\n    template\
    \ <class T> static int group(const point<T>& p) {\n        if (sgn(p.y) < 0) return\
    \ 0;\n        if (sgn(p.y) == 0 && sgn(p.x) >= 0) return 1;\n        return 2;\n\
    \    }\n    template <class T> bool operator()(const point<T>& a, const point<T>&\
    \ b) const {\n        if (group(a) != group(b)) return group(a) < group(b);\n\
    \        return sgn(cross(a, b)) > 0;\n    }\n};\n}  // namespace geo\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/point.hpp
  requiredBy:
  - geometry/polygon.hpp
  - geometry/line.hpp
  - geometry/circle.hpp
  timestamp: '2026-10-22 22:57:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_4_C.test.cpp
  - test/aoj/CGL_7_H.test.cpp
  - test/aoj/CGL_2_B.test.cpp
  - test/aoj/CGL_4_A.test.cpp
  - test/aoj/CGL_2_D.test.cpp
  - test/aoj/CGL_1_A.test.cpp
  - test/aoj/CGL_4_B.test.cpp
  - test/aoj/CGL_3_B.test.cpp
  - test/aoj/CGL_2_A.test.cpp
  - test/aoj/CGL_7_D.test.cpp
  - test/aoj/CGL_2_C.test.cpp
  - test/aoj/CGL_5_A.test.cpp
  - test/aoj/CGL_1_C.test.cpp
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/CGL_3_A.test.cpp
  - test/aoj/CGL_7_I.test.cpp
  - test/aoj/CGL_7_B.test.cpp
  - test/aoj/CGL_7_A.test.cpp
  - test/aoj/CGL_7_E.test.cpp
  - test/aoj/CGL_7_G.test.cpp
  - test/aoj/CGL_7_F.test.cpp
  - test/aoj/CGL_1_B.test.cpp
  - test/aoj/CGL_3_C.test.cpp
  - test/unit/geometry.test.cpp
  - test/library-checker/static_convex_hull.test.cpp
  - test/library-checker/sort_points_by_argument.test.cpp
  - test/library-checker/closest_pair.test.cpp
documentation_of: geometry/point.hpp
layout: document
title: 'Geometry: Point'
---

### 概要
- 2 次元の点。

### 使い方
- `geo::point<T>`: 座標の型 `T`。整数型と浮動小数点型を使える。
- `geo::eps`: 浮動小数点型の比較に使う誤差。初期値 $10^{-9}$。
- `sgn(a)`: `a` の符号を返す。浮動小数点型では `eps` 以下を $0$ とみなす。
- `dot(p, q)`: 内積を返す。
- `cross(p, q)`: 外積 $p_x q_y - p_y q_x$ を返す。
- `norm(p)`: $\lvert p \rvert^2$ を返す。
- `abs(p)`: $\lvert p \rvert$ を返す。浮動小数点型のみ。
- `arg(p)`: 偏角 $\mathrm{atan2}(p_y, p_x)$ を返す。浮動小数点型のみ。
- `normal(p)`: `p` を $90^\circ$ 回転したベクトル $(-p_y, p_x)$ を返す。
- `unit(p)`: `p` と同じ向きの単位ベクトルを返す。浮動小数点型のみ。
- `rotate(p, theta)`: `p` を原点中心に `theta` 回転した点を返す。浮動小数点型のみ。
- `ccw(a, b, c)`: `cross(b - a, c - a)` の符号を返す。
- `arg_less`: 偏角 $(-\pi, \pi]$ の昇順に並べる比較関数。原点の偏角は $0$。

### 制約
- 整数型では $\lvert x \rvert, \lvert y \rvert \le 10^9$

### 問題例
Library Checker - Sort Points by Argument（[問題](https://judge.yosupo.jp/problem/sort_points_by_argument)）

```cpp
std::vector<geo::point<long long>> ps(n);
for (auto& p : ps) std::cin >> p;
std::sort(ps.begin(), ps.end(), geo::arg_less{});
```
