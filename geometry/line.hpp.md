---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: 'Geometry: Point'
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: 'Geometry: Circle'
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
  bundledCode: "#line 2 \"geometry/line.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n#include <concepts>\n#include <iostream>\n\n#line 3 \"geometry/point.hpp\"\
    \n#include <compare>\n#line 6 \"geometry/point.hpp\"\n#include <type_traits>\n\
    namespace geo {\ninline long double eps = 1e-9;\ntemplate <class T> int sgn(T\
    \ a) {\n    if constexpr (std::is_integral_v<T>) {\n        return (a > 0) - (a\
    \ < 0);\n    } else {\n        return a < -eps ? -1 : a > eps ? 1 : 0;\n    }\n\
    }\ntemplate <class T> struct point {\n    T x, y;\n    point() : x(0), y(0) {\n\
    \    }\n    point(T x, T y) : x(x), y(y) {\n    }\n    point& operator+=(const\
    \ point& p) {\n        x += p.x, y += p.y;\n        return *this;\n    }\n   \
    \ point& operator-=(const point& p) {\n        x -= p.x, y -= p.y;\n        return\
    \ *this;\n    }\n    point& operator*=(T k) {\n        x *= k, y *= k;\n     \
    \   return *this;\n    }\n    point& operator/=(T k) requires std::floating_point<T>\
    \ {\n        x /= k, y /= k;\n        return *this;\n    }\n    point operator-()\
    \ const {\n        return point(-x, -y);\n    }\n    friend point operator+(point\
    \ a, const point& b) {\n        return a += b;\n    }\n    friend point operator-(point\
    \ a, const point& b) {\n        return a -= b;\n    }\n    friend point operator*(point\
    \ a, T k) {\n        return a *= k;\n    }\n    friend point operator*(T k, point\
    \ a) {\n        return a *= k;\n    }\n    friend point operator/(point a, T k)\
    \ requires std::floating_point<T> {\n        return a /= k;\n    }\n    friend\
    \ bool operator==(const point& a, const point& b) {\n        return sgn(a.x -\
    \ b.x) == 0 && sgn(a.y - b.y) == 0;\n    }\n    friend std::weak_ordering operator<=>(const\
    \ point& a, const point& b) {\n        if (int s = sgn(a.x - b.x); s != 0) return\
    \ s <=> 0;\n        return sgn(a.y - b.y) <=> 0;\n    }\n    friend std::istream&\
    \ operator>>(std::istream& is, point& p) {\n        return is >> p.x >> p.y;\n\
    \    }\n    friend std::ostream& operator<<(std::ostream& os, const point& p)\
    \ {\n        return os << p.x << ' ' << p.y;\n    }\n};\ntemplate <class T> T\
    \ dot(const point<T>& a, const point<T>& b) {\n    return a.x * b.x + a.y * b.y;\n\
    }\ntemplate <class T> T cross(const point<T>& a, const point<T>& b) {\n    return\
    \ a.x * b.y - a.y * b.x;\n}\ntemplate <class T> T norm(const point<T>& p) {\n\
    \    return p.x * p.x + p.y * p.y;\n}\ntemplate <std::floating_point T> T abs(const\
    \ point<T>& p) {\n    return std::sqrt(norm(p));\n}\ntemplate <std::floating_point\
    \ T> T arg(const point<T>& p) {\n    return std::atan2(p.y, p.x);\n}\ntemplate\
    \ <class T> point<T> normal(const point<T>& p) {\n    return point<T>(-p.y, p.x);\n\
    }\ntemplate <std::floating_point T> point<T> unit(const point<T>& p) {\n    return\
    \ p / abs(p);\n}\ntemplate <std::floating_point T> point<T> rotate(const point<T>&\
    \ p, T theta) {\n    T c = std::cos(theta), s = std::sin(theta);\n    return point<T>(p.x\
    \ * c - p.y * s, p.x * s + p.y * c);\n}\ntemplate <class T> int ccw(const point<T>&\
    \ a, const point<T>& b, const point<T>& c) {\n    return sgn(cross(b - a, c -\
    \ a));\n}\nstruct arg_less {\n    template <class T> static int group(const point<T>&\
    \ p) {\n        if (sgn(p.y) < 0) return 0;\n        if (sgn(p.y) == 0 && sgn(p.x)\
    \ >= 0) return 1;\n        return 2;\n    }\n    template <class T> bool operator()(const\
    \ point<T>& a, const point<T>& b) const {\n        if (group(a) != group(b)) return\
    \ group(a) < group(b);\n        return sgn(cross(a, b)) > 0;\n    }\n};\n}  //\
    \ namespace geo\n#line 9 \"geometry/line.hpp\"\nnamespace geo {\ntemplate <class\
    \ T> struct line {\n    point<T> a, b;\n    line() {\n    }\n    line(const point<T>&\
    \ a, const point<T>& b) : a(a), b(b) {\n    }\n    friend std::istream& operator>>(std::istream&\
    \ is, line& l) {\n        return is >> l.a >> l.b;\n    }\n};\ntemplate <class\
    \ T> struct segment {\n    point<T> a, b;\n    segment() {\n    }\n    segment(const\
    \ point<T>& a, const point<T>& b) : a(a), b(b) {\n    }\n    friend std::istream&\
    \ operator>>(std::istream& is, segment& s) {\n        return is >> s.a >> s.b;\n\
    \    }\n};\ntemplate <class T> line<T> to_line(const segment<T>& s) {\n    return\
    \ line<T>(s.a, s.b);\n}\ntemplate <class T> bool parallel(const line<T>& l, const\
    \ line<T>& m) {\n    return sgn(cross(l.b - l.a, m.b - m.a)) == 0;\n}\ntemplate\
    \ <class T> bool orthogonal(const line<T>& l, const line<T>& m) {\n    return\
    \ sgn(dot(l.b - l.a, m.b - m.a)) == 0;\n}\ntemplate <class T> bool on_line(const\
    \ line<T>& l, const point<T>& p) {\n    return ccw(l.a, l.b, p) == 0;\n}\ntemplate\
    \ <class T> bool on_segment(const segment<T>& s, const point<T>& p) {\n    return\
    \ ccw(s.a, s.b, p) == 0 && sgn(dot(s.a - p, s.b - p)) <= 0;\n}\ntemplate <class\
    \ T> bool intersect(const line<T>& l, const line<T>& m) {\n    return !parallel(l,\
    \ m) || on_line(l, m.a);\n}\ntemplate <class T> bool intersect(const line<T>&\
    \ l, const segment<T>& s) {\n    return ccw(l.a, l.b, s.a) * ccw(l.a, l.b, s.b)\
    \ <= 0;\n}\ntemplate <class T> bool intersect(const segment<T>& s, const line<T>&\
    \ l) {\n    return intersect(l, s);\n}\ntemplate <class T> bool intersect(const\
    \ segment<T>& s, const segment<T>& t) {\n    if (ccw(s.a, s.b, t.a) * ccw(s.a,\
    \ s.b, t.b) > 0) return false;\n    if (ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b)\
    \ > 0) return false;\n    if (ccw(s.a, s.b, t.a) != 0 || ccw(s.a, s.b, t.b) !=\
    \ 0) return true;\n    return on_segment(s, t.a) || on_segment(s, t.b) || on_segment(t,\
    \ s.a) || on_segment(t, s.b);\n}\ntemplate <std::floating_point T> point<T> projection(const\
    \ line<T>& l, const point<T>& p) {\n    point<T> d = l.b - l.a;\n    return l.a\
    \ + d * (dot(d, p - l.a) / norm(d));\n}\ntemplate <std::floating_point T> point<T>\
    \ reflection(const line<T>& l, const point<T>& p) {\n    return projection(l,\
    \ p) * T(2) - p;\n}\ntemplate <std::floating_point T> line<T> perpendicular_bisector(const\
    \ point<T>& a, const point<T>& b) {\n    point<T> m = (a + b) / T(2);\n    return\
    \ line<T>(m, m + normal(b - a));\n}\ntemplate <std::floating_point T> T dist(const\
    \ point<T>& a, const point<T>& b) {\n    return abs(a - b);\n}\ntemplate <std::floating_point\
    \ T> T dist(const line<T>& l, const point<T>& p) {\n    return std::abs(cross(l.b\
    \ - l.a, p - l.a)) / abs(l.b - l.a);\n}\ntemplate <std::floating_point T> T dist(const\
    \ point<T>& p, const line<T>& l) {\n    return dist(l, p);\n}\ntemplate <std::floating_point\
    \ T> T dist(const segment<T>& s, const point<T>& p) {\n    if (sgn(dot(s.b - s.a,\
    \ p - s.a)) < 0) return abs(p - s.a);\n    if (sgn(dot(s.a - s.b, p - s.b)) <\
    \ 0) return abs(p - s.b);\n    return dist(to_line(s), p);\n}\ntemplate <std::floating_point\
    \ T> T dist(const point<T>& p, const segment<T>& s) {\n    return dist(s, p);\n\
    }\ntemplate <std::floating_point T> T dist(const line<T>& l, const line<T>& m)\
    \ {\n    if (intersect(l, m)) return 0;\n    return dist(l, m.a);\n}\ntemplate\
    \ <std::floating_point T> T dist(const line<T>& l, const segment<T>& s) {\n  \
    \  if (intersect(l, s)) return 0;\n    return std::min(dist(l, s.a), dist(l, s.b));\n\
    }\ntemplate <std::floating_point T> T dist(const segment<T>& s, const line<T>&\
    \ l) {\n    return dist(l, s);\n}\ntemplate <std::floating_point T> T dist(const\
    \ segment<T>& s, const segment<T>& t) {\n    if (intersect(s, t)) return 0;\n\
    \    return std::min({dist(s, t.a), dist(s, t.b), dist(t, s.a), dist(t, s.b)});\n\
    }\ntemplate <std::floating_point T> point<T> cross_point(const line<T>& l, const\
    \ line<T>& m) {\n    assert(!parallel(l, m));\n    point<T> d = l.b - l.a;\n \
    \   return l.a + d * (cross(m.b - m.a, m.a - l.a) / cross(m.b - m.a, d));\n}\n\
    template <std::floating_point T> point<T> cross_point(const line<T>& l, const\
    \ segment<T>& s) {\n    assert(intersect(l, s));\n    return cross_point(l, to_line(s));\n\
    }\ntemplate <std::floating_point T> point<T> cross_point(const segment<T>& s,\
    \ const line<T>& l) {\n    return cross_point(l, s);\n}\ntemplate <std::floating_point\
    \ T> point<T> cross_point(const segment<T>& s, const segment<T>& t) {\n    assert(intersect(s,\
    \ t));\n    return cross_point(to_line(s), to_line(t));\n}\n}  // namespace geo\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <concepts>\n#include <iostream>\n\n#include \"geometry/point.hpp\"\n\
    namespace geo {\ntemplate <class T> struct line {\n    point<T> a, b;\n    line()\
    \ {\n    }\n    line(const point<T>& a, const point<T>& b) : a(a), b(b) {\n  \
    \  }\n    friend std::istream& operator>>(std::istream& is, line& l) {\n     \
    \   return is >> l.a >> l.b;\n    }\n};\ntemplate <class T> struct segment {\n\
    \    point<T> a, b;\n    segment() {\n    }\n    segment(const point<T>& a, const\
    \ point<T>& b) : a(a), b(b) {\n    }\n    friend std::istream& operator>>(std::istream&\
    \ is, segment& s) {\n        return is >> s.a >> s.b;\n    }\n};\ntemplate <class\
    \ T> line<T> to_line(const segment<T>& s) {\n    return line<T>(s.a, s.b);\n}\n\
    template <class T> bool parallel(const line<T>& l, const line<T>& m) {\n    return\
    \ sgn(cross(l.b - l.a, m.b - m.a)) == 0;\n}\ntemplate <class T> bool orthogonal(const\
    \ line<T>& l, const line<T>& m) {\n    return sgn(dot(l.b - l.a, m.b - m.a)) ==\
    \ 0;\n}\ntemplate <class T> bool on_line(const line<T>& l, const point<T>& p)\
    \ {\n    return ccw(l.a, l.b, p) == 0;\n}\ntemplate <class T> bool on_segment(const\
    \ segment<T>& s, const point<T>& p) {\n    return ccw(s.a, s.b, p) == 0 && sgn(dot(s.a\
    \ - p, s.b - p)) <= 0;\n}\ntemplate <class T> bool intersect(const line<T>& l,\
    \ const line<T>& m) {\n    return !parallel(l, m) || on_line(l, m.a);\n}\ntemplate\
    \ <class T> bool intersect(const line<T>& l, const segment<T>& s) {\n    return\
    \ ccw(l.a, l.b, s.a) * ccw(l.a, l.b, s.b) <= 0;\n}\ntemplate <class T> bool intersect(const\
    \ segment<T>& s, const line<T>& l) {\n    return intersect(l, s);\n}\ntemplate\
    \ <class T> bool intersect(const segment<T>& s, const segment<T>& t) {\n    if\
    \ (ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) > 0) return false;\n    if (ccw(t.a,\
    \ t.b, s.a) * ccw(t.a, t.b, s.b) > 0) return false;\n    if (ccw(s.a, s.b, t.a)\
    \ != 0 || ccw(s.a, s.b, t.b) != 0) return true;\n    return on_segment(s, t.a)\
    \ || on_segment(s, t.b) || on_segment(t, s.a) || on_segment(t, s.b);\n}\ntemplate\
    \ <std::floating_point T> point<T> projection(const line<T>& l, const point<T>&\
    \ p) {\n    point<T> d = l.b - l.a;\n    return l.a + d * (dot(d, p - l.a) / norm(d));\n\
    }\ntemplate <std::floating_point T> point<T> reflection(const line<T>& l, const\
    \ point<T>& p) {\n    return projection(l, p) * T(2) - p;\n}\ntemplate <std::floating_point\
    \ T> line<T> perpendicular_bisector(const point<T>& a, const point<T>& b) {\n\
    \    point<T> m = (a + b) / T(2);\n    return line<T>(m, m + normal(b - a));\n\
    }\ntemplate <std::floating_point T> T dist(const point<T>& a, const point<T>&\
    \ b) {\n    return abs(a - b);\n}\ntemplate <std::floating_point T> T dist(const\
    \ line<T>& l, const point<T>& p) {\n    return std::abs(cross(l.b - l.a, p - l.a))\
    \ / abs(l.b - l.a);\n}\ntemplate <std::floating_point T> T dist(const point<T>&\
    \ p, const line<T>& l) {\n    return dist(l, p);\n}\ntemplate <std::floating_point\
    \ T> T dist(const segment<T>& s, const point<T>& p) {\n    if (sgn(dot(s.b - s.a,\
    \ p - s.a)) < 0) return abs(p - s.a);\n    if (sgn(dot(s.a - s.b, p - s.b)) <\
    \ 0) return abs(p - s.b);\n    return dist(to_line(s), p);\n}\ntemplate <std::floating_point\
    \ T> T dist(const point<T>& p, const segment<T>& s) {\n    return dist(s, p);\n\
    }\ntemplate <std::floating_point T> T dist(const line<T>& l, const line<T>& m)\
    \ {\n    if (intersect(l, m)) return 0;\n    return dist(l, m.a);\n}\ntemplate\
    \ <std::floating_point T> T dist(const line<T>& l, const segment<T>& s) {\n  \
    \  if (intersect(l, s)) return 0;\n    return std::min(dist(l, s.a), dist(l, s.b));\n\
    }\ntemplate <std::floating_point T> T dist(const segment<T>& s, const line<T>&\
    \ l) {\n    return dist(l, s);\n}\ntemplate <std::floating_point T> T dist(const\
    \ segment<T>& s, const segment<T>& t) {\n    if (intersect(s, t)) return 0;\n\
    \    return std::min({dist(s, t.a), dist(s, t.b), dist(t, s.a), dist(t, s.b)});\n\
    }\ntemplate <std::floating_point T> point<T> cross_point(const line<T>& l, const\
    \ line<T>& m) {\n    assert(!parallel(l, m));\n    point<T> d = l.b - l.a;\n \
    \   return l.a + d * (cross(m.b - m.a, m.a - l.a) / cross(m.b - m.a, d));\n}\n\
    template <std::floating_point T> point<T> cross_point(const line<T>& l, const\
    \ segment<T>& s) {\n    assert(intersect(l, s));\n    return cross_point(l, to_line(s));\n\
    }\ntemplate <std::floating_point T> point<T> cross_point(const segment<T>& s,\
    \ const line<T>& l) {\n    return cross_point(l, s);\n}\ntemplate <std::floating_point\
    \ T> point<T> cross_point(const segment<T>& s, const segment<T>& t) {\n    assert(intersect(s,\
    \ t));\n    return cross_point(to_line(s), to_line(t));\n}\n}  // namespace geo\n"
  dependsOn:
  - geometry/point.hpp
  isVerificationFile: false
  path: geometry/line.hpp
  requiredBy:
  - geometry/circle.hpp
  - geometry/polygon.hpp
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/geometry.test.cpp
  - test/library-checker/static_convex_hull.test.cpp
  - test/library-checker/closest_pair.test.cpp
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/CGL_7_D.test.cpp
  - test/aoj/CGL_1_C.test.cpp
  - test/aoj/CGL_7_F.test.cpp
  - test/aoj/CGL_7_B.test.cpp
  - test/aoj/CGL_3_B.test.cpp
  - test/aoj/CGL_2_A.test.cpp
  - test/aoj/CGL_2_C.test.cpp
  - test/aoj/CGL_7_E.test.cpp
  - test/aoj/CGL_7_H.test.cpp
  - test/aoj/CGL_3_C.test.cpp
  - test/aoj/CGL_7_G.test.cpp
  - test/aoj/CGL_1_B.test.cpp
  - test/aoj/CGL_7_I.test.cpp
  - test/aoj/CGL_7_A.test.cpp
  - test/aoj/CGL_2_B.test.cpp
  - test/aoj/CGL_1_A.test.cpp
  - test/aoj/CGL_4_C.test.cpp
  - test/aoj/CGL_4_B.test.cpp
  - test/aoj/CGL_5_A.test.cpp
  - test/aoj/CGL_2_D.test.cpp
  - test/aoj/CGL_4_A.test.cpp
  - test/aoj/CGL_3_A.test.cpp
documentation_of: geometry/line.hpp
layout: document
title: 'Geometry: Line'
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
