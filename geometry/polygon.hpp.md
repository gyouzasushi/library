---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/line.hpp
    title: 'Geometry: Line'
  - icon: ':question:'
    path: geometry/point.hpp
    title: 'Geometry: Point'
  _extendedRequiredBy:
  - icon: ':question:'
    path: geometry/circle.hpp
    title: 'Geometry: Circle'
  _extendedVerifiedWith:
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
  - icon: ':x:'
    path: test/library-checker/static_convex_hull.test.cpp
    title: test/library-checker/static_convex_hull.test.cpp
  - icon: ':x:'
    path: test/unit/geometry.test.cpp
    title: test/unit/geometry.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/polygon.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n#include <concepts>\n#include <utility>\n#include <vector>\n\
    \n#line 6 \"geometry/line.hpp\"\n#include <iostream>\n\n#line 3 \"geometry/point.hpp\"\
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
    \ t));\n    return cross_point(to_line(s), to_line(t));\n}\n}  // namespace geo\n\
    #line 11 \"geometry/polygon.hpp\"\nnamespace geo {\ntemplate <class T> using polygon\
    \ = std::vector<point<T>>;\ntemplate <class T> T area2(const polygon<T>& poly)\
    \ {\n    int n = int(poly.size());\n    if constexpr (std::is_integral_v<T>) {\n\
    \        __int128 ret = 0;\n        for (int i = 0; i < n; i++) ret += (__int128)cross(poly[i],\
    \ poly[(i + 1) % n]);\n        return T(ret);\n    } else {\n        T ret = 0;\n\
    \        for (int i = 0; i < n; i++) ret += cross(poly[i], poly[(i + 1) % n]);\n\
    \        return ret;\n    }\n}\ntemplate <std::floating_point T> T area(const\
    \ polygon<T>& poly) {\n    return area2(poly) / T(2);\n}\ntemplate <class T> bool\
    \ is_convex(const polygon<T>& poly) {\n    int n = int(poly.size());\n    for\
    \ (int i = 0; i < n; i++) {\n        if (ccw(poly[i], poly[(i + 1) % n], poly[(i\
    \ + 2) % n]) < 0) return false;\n    }\n    return true;\n}\ntemplate <class T>\
    \ int contains(const polygon<T>& poly, const point<T>& p) {\n    int n = int(poly.size());\n\
    \    bool in = false;\n    for (int i = 0; i < n; i++) {\n        point<T> a =\
    \ poly[i] - p, b = poly[(i + 1) % n] - p;\n        if (ccw(a, b, point<T>()) ==\
    \ 0 && sgn(dot(a, b)) <= 0) return 1;\n        if (sgn(a.y) > sgn(b.y)) std::swap(a,\
    \ b);\n        if (sgn(a.y) <= 0 && 0 < sgn(b.y) && sgn(cross(a, b)) > 0) in =\
    \ !in;\n    }\n    return in ? 2 : 0;\n}\ntemplate <class T> polygon<T> convex_hull(std::vector<point<T>>\
    \ ps, bool strict = true) {\n    int n = int(ps.size());\n    std::ranges::sort(ps);\n\
    \    ps.erase(std::ranges::unique(ps).begin(), ps.end());\n    n = int(ps.size());\n\
    \    if (n <= 2) return ps;\n    polygon<T> ret(2 * n);\n    int k = 0;\n    for\
    \ (int i = 0; i < n; ret[k++] = ps[i++]) {\n        while (k >= 2 && ccw(ret[k\
    \ - 2], ret[k - 1], ps[i]) < (strict ? 1 : 0)) k--;\n    }\n    for (int i = n\
    \ - 2, t = k + 1; i >= 0; ret[k++] = ps[i--]) {\n        while (k >= t && ccw(ret[k\
    \ - 2], ret[k - 1], ps[i]) < (strict ? 1 : 0)) k--;\n    }\n    ret.resize(k -\
    \ 1);\n    return ret;\n}\ntemplate <class T> std::pair<int, int> farthest_pair(const\
    \ std::vector<point<T>>& ps) {\n    int n = int(ps.size());\n    assert(n >= 2);\n\
    \    polygon<T> ch = convex_hull(ps);\n    int m = int(ch.size());\n    auto index_of\
    \ = [&](const point<T>& p) {\n        return int(std::ranges::find(ps, p) - ps.begin());\n\
    \    };\n    if (m == 1) return {0, 1};\n    if (m == 2) return {index_of(ch[0]),\
    \ index_of(ch[1])};\n    std::pair<int, int> ret = {0, 1};\n    T best = norm(ch[0]\
    \ - ch[1]);\n    for (int i = 0, j = 1; i < m; i++) {\n        while (norm(ch[i]\
    \ - ch[(j + 1) % m]) > norm(ch[i] - ch[j])) j = (j + 1) % m;\n        if (norm(ch[i]\
    \ - ch[j]) > best) {\n            best = norm(ch[i] - ch[j]);\n            ret\
    \ = {i, j};\n        }\n    }\n    return {index_of(ch[ret.first]), index_of(ch[ret.second])};\n\
    }\ntemplate <class T> std::pair<int, int> closest_pair(const std::vector<point<T>>&\
    \ ps) {\n    int n = int(ps.size());\n    assert(n >= 2);\n    std::vector<int>\
    \ id(n);\n    for (int i = 0; i < n; i++) id[i] = i;\n    std::ranges::sort(id,\
    \ [&](int i, int j) { return ps[i] < ps[j]; });\n    std::pair<int, int> ret =\
    \ {id[0], id[1]};\n    T best = norm(ps[id[0]] - ps[id[1]]);\n    std::vector<int>\
    \ buf(n);\n    auto rec = [&](auto rec, int l, int r) -> void {\n        if (r\
    \ - l <= 1) return;\n        int m = (l + r) / 2;\n        T x = ps[id[m]].x;\n\
    \        rec(rec, l, m);\n        rec(rec, m, r);\n        std::inplace_merge(id.begin()\
    \ + l, id.begin() + m, id.begin() + r,\n                           [&](int i,\
    \ int j) { return ps[i].y < ps[j].y; });\n        int k = 0;\n        for (int\
    \ t = l; t < r; t++) {\n            int i = id[t];\n            T dx = ps[i].x\
    \ - x;\n            if (dx * dx >= best) continue;\n            for (int u = k\
    \ - 1; u >= 0; u--) {\n                int j = buf[u];\n                T dy =\
    \ ps[i].y - ps[j].y;\n                if (dy * dy >= best) break;\n          \
    \      T d = norm(ps[i] - ps[j]);\n                if (d < best) {\n         \
    \           best = d;\n                    ret = {j, i};\n                }\n\
    \            }\n            buf[k++] = i;\n        }\n    };\n    rec(rec, 0,\
    \ n);\n    return ret;\n}\ntemplate <std::floating_point T> polygon<T> convex_cut(const\
    \ polygon<T>& poly, const line<T>& l) {\n    int n = int(poly.size());\n    polygon<T>\
    \ ret;\n    for (int i = 0; i < n; i++) {\n        const point<T>& p = poly[i];\n\
    \        const point<T>& q = poly[(i + 1) % n];\n        int cp = ccw(l.a, l.b,\
    \ p), cq = ccw(l.a, l.b, q);\n        if (cp >= 0) ret.push_back(p);\n       \
    \ if (cp * cq < 0) ret.push_back(cross_point(l, line<T>(p, q)));\n    }\n    return\
    \ ret;\n}\n}  // namespace geo\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <concepts>\n#include <utility>\n#include <vector>\n\n#include \"geometry/line.hpp\"\
    \n#include \"geometry/point.hpp\"\nnamespace geo {\ntemplate <class T> using polygon\
    \ = std::vector<point<T>>;\ntemplate <class T> T area2(const polygon<T>& poly)\
    \ {\n    int n = int(poly.size());\n    if constexpr (std::is_integral_v<T>) {\n\
    \        __int128 ret = 0;\n        for (int i = 0; i < n; i++) ret += (__int128)cross(poly[i],\
    \ poly[(i + 1) % n]);\n        return T(ret);\n    } else {\n        T ret = 0;\n\
    \        for (int i = 0; i < n; i++) ret += cross(poly[i], poly[(i + 1) % n]);\n\
    \        return ret;\n    }\n}\ntemplate <std::floating_point T> T area(const\
    \ polygon<T>& poly) {\n    return area2(poly) / T(2);\n}\ntemplate <class T> bool\
    \ is_convex(const polygon<T>& poly) {\n    int n = int(poly.size());\n    for\
    \ (int i = 0; i < n; i++) {\n        if (ccw(poly[i], poly[(i + 1) % n], poly[(i\
    \ + 2) % n]) < 0) return false;\n    }\n    return true;\n}\ntemplate <class T>\
    \ int contains(const polygon<T>& poly, const point<T>& p) {\n    int n = int(poly.size());\n\
    \    bool in = false;\n    for (int i = 0; i < n; i++) {\n        point<T> a =\
    \ poly[i] - p, b = poly[(i + 1) % n] - p;\n        if (ccw(a, b, point<T>()) ==\
    \ 0 && sgn(dot(a, b)) <= 0) return 1;\n        if (sgn(a.y) > sgn(b.y)) std::swap(a,\
    \ b);\n        if (sgn(a.y) <= 0 && 0 < sgn(b.y) && sgn(cross(a, b)) > 0) in =\
    \ !in;\n    }\n    return in ? 2 : 0;\n}\ntemplate <class T> polygon<T> convex_hull(std::vector<point<T>>\
    \ ps, bool strict = true) {\n    int n = int(ps.size());\n    std::ranges::sort(ps);\n\
    \    ps.erase(std::ranges::unique(ps).begin(), ps.end());\n    n = int(ps.size());\n\
    \    if (n <= 2) return ps;\n    polygon<T> ret(2 * n);\n    int k = 0;\n    for\
    \ (int i = 0; i < n; ret[k++] = ps[i++]) {\n        while (k >= 2 && ccw(ret[k\
    \ - 2], ret[k - 1], ps[i]) < (strict ? 1 : 0)) k--;\n    }\n    for (int i = n\
    \ - 2, t = k + 1; i >= 0; ret[k++] = ps[i--]) {\n        while (k >= t && ccw(ret[k\
    \ - 2], ret[k - 1], ps[i]) < (strict ? 1 : 0)) k--;\n    }\n    ret.resize(k -\
    \ 1);\n    return ret;\n}\ntemplate <class T> std::pair<int, int> farthest_pair(const\
    \ std::vector<point<T>>& ps) {\n    int n = int(ps.size());\n    assert(n >= 2);\n\
    \    polygon<T> ch = convex_hull(ps);\n    int m = int(ch.size());\n    auto index_of\
    \ = [&](const point<T>& p) {\n        return int(std::ranges::find(ps, p) - ps.begin());\n\
    \    };\n    if (m == 1) return {0, 1};\n    if (m == 2) return {index_of(ch[0]),\
    \ index_of(ch[1])};\n    std::pair<int, int> ret = {0, 1};\n    T best = norm(ch[0]\
    \ - ch[1]);\n    for (int i = 0, j = 1; i < m; i++) {\n        while (norm(ch[i]\
    \ - ch[(j + 1) % m]) > norm(ch[i] - ch[j])) j = (j + 1) % m;\n        if (norm(ch[i]\
    \ - ch[j]) > best) {\n            best = norm(ch[i] - ch[j]);\n            ret\
    \ = {i, j};\n        }\n    }\n    return {index_of(ch[ret.first]), index_of(ch[ret.second])};\n\
    }\ntemplate <class T> std::pair<int, int> closest_pair(const std::vector<point<T>>&\
    \ ps) {\n    int n = int(ps.size());\n    assert(n >= 2);\n    std::vector<int>\
    \ id(n);\n    for (int i = 0; i < n; i++) id[i] = i;\n    std::ranges::sort(id,\
    \ [&](int i, int j) { return ps[i] < ps[j]; });\n    std::pair<int, int> ret =\
    \ {id[0], id[1]};\n    T best = norm(ps[id[0]] - ps[id[1]]);\n    std::vector<int>\
    \ buf(n);\n    auto rec = [&](auto rec, int l, int r) -> void {\n        if (r\
    \ - l <= 1) return;\n        int m = (l + r) / 2;\n        T x = ps[id[m]].x;\n\
    \        rec(rec, l, m);\n        rec(rec, m, r);\n        std::inplace_merge(id.begin()\
    \ + l, id.begin() + m, id.begin() + r,\n                           [&](int i,\
    \ int j) { return ps[i].y < ps[j].y; });\n        int k = 0;\n        for (int\
    \ t = l; t < r; t++) {\n            int i = id[t];\n            T dx = ps[i].x\
    \ - x;\n            if (dx * dx >= best) continue;\n            for (int u = k\
    \ - 1; u >= 0; u--) {\n                int j = buf[u];\n                T dy =\
    \ ps[i].y - ps[j].y;\n                if (dy * dy >= best) break;\n          \
    \      T d = norm(ps[i] - ps[j]);\n                if (d < best) {\n         \
    \           best = d;\n                    ret = {j, i};\n                }\n\
    \            }\n            buf[k++] = i;\n        }\n    };\n    rec(rec, 0,\
    \ n);\n    return ret;\n}\ntemplate <std::floating_point T> polygon<T> convex_cut(const\
    \ polygon<T>& poly, const line<T>& l) {\n    int n = int(poly.size());\n    polygon<T>\
    \ ret;\n    for (int i = 0; i < n; i++) {\n        const point<T>& p = poly[i];\n\
    \        const point<T>& q = poly[(i + 1) % n];\n        int cp = ccw(l.a, l.b,\
    \ p), cq = ccw(l.a, l.b, q);\n        if (cp >= 0) ret.push_back(p);\n       \
    \ if (cp * cq < 0) ret.push_back(cross_point(l, line<T>(p, q)));\n    }\n    return\
    \ ret;\n}\n}  // namespace geo\n"
  dependsOn:
  - geometry/line.hpp
  - geometry/point.hpp
  isVerificationFile: false
  path: geometry/polygon.hpp
  requiredBy:
  - geometry/circle.hpp
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/unit/geometry.test.cpp
  - test/library-checker/static_convex_hull.test.cpp
  - test/library-checker/closest_pair.test.cpp
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/CGL_7_D.test.cpp
  - test/aoj/CGL_7_F.test.cpp
  - test/aoj/CGL_7_B.test.cpp
  - test/aoj/CGL_3_B.test.cpp
  - test/aoj/CGL_7_E.test.cpp
  - test/aoj/CGL_7_H.test.cpp
  - test/aoj/CGL_3_C.test.cpp
  - test/aoj/CGL_7_G.test.cpp
  - test/aoj/CGL_7_I.test.cpp
  - test/aoj/CGL_7_A.test.cpp
  - test/aoj/CGL_4_C.test.cpp
  - test/aoj/CGL_4_B.test.cpp
  - test/aoj/CGL_5_A.test.cpp
  - test/aoj/CGL_4_A.test.cpp
  - test/aoj/CGL_3_A.test.cpp
documentation_of: geometry/polygon.hpp
layout: document
title: 'Geometry: Polygon'
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
