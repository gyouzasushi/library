---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: 'Geometry: Circle'
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: 'Geometry: Line'
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: 'Geometry: Point'
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: 'Geometry: Polygon'
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_B
  bundledCode: "#line 1 \"test/aoj/CGL_7_B.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_B\"\n#define\
    \ ERROR 0.000001\n#include <iomanip>\n#include <iostream>\n#include <vector>\n\
    \n#line 2 \"geometry/circle.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n#include <concepts>\n#include <numbers>\n#include <random>\n\
    #line 9 \"geometry/circle.hpp\"\n\n#line 7 \"geometry/line.hpp\"\n\n#line 5 \"\
    geometry/point.hpp\"\n#include <type_traits>\nnamespace geo {\ninline long double\
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
    \        return sgn(cross(a, b)) > 0;\n    }\n};\n}  // namespace geo\n#line 9\
    \ \"geometry/line.hpp\"\nnamespace geo {\ntemplate <class T> struct line {\n \
    \   point<T> a, b;\n    line() {\n    }\n    line(const point<T>& a, const point<T>&\
    \ b) : a(a), b(b) {\n    }\n    friend std::istream& operator>>(std::istream&\
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
    #line 6 \"geometry/polygon.hpp\"\n#include <utility>\n#line 8 \"geometry/polygon.hpp\"\
    \n\n#line 11 \"geometry/polygon.hpp\"\nnamespace geo {\ntemplate <class T> using\
    \ polygon = std::vector<point<T>>;\ntemplate <class T> T area2(const polygon<T>&\
    \ poly) {\n    int n = int(poly.size());\n    if constexpr (std::is_integral_v<T>)\
    \ {\n        __int128 ret = 0;\n        for (int i = 0; i < n; i++) ret += (__int128)cross(poly[i],\
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
    \ ps, bool strict = true) {\n    int n = int(ps.size());\n    std::sort(ps.begin(),\
    \ ps.end());\n    ps.erase(std::unique(ps.begin(), ps.end()), ps.end());\n   \
    \ n = int(ps.size());\n    if (n <= 2) return ps;\n    polygon<T> ret(2 * n);\n\
    \    int k = 0;\n    for (int i = 0; i < n; ret[k++] = ps[i++]) {\n        while\
    \ (k >= 2 && ccw(ret[k - 2], ret[k - 1], ps[i]) < (strict ? 1 : 0)) k--;\n   \
    \ }\n    for (int i = n - 2, t = k + 1; i >= 0; ret[k++] = ps[i--]) {\n      \
    \  while (k >= t && ccw(ret[k - 2], ret[k - 1], ps[i]) < (strict ? 1 : 0)) k--;\n\
    \    }\n    ret.resize(k - 1);\n    return ret;\n}\ntemplate <class T> std::pair<int,\
    \ int> farthest_pair(const std::vector<point<T>>& ps) {\n    int n = int(ps.size());\n\
    \    assert(n >= 2);\n    polygon<T> ch = convex_hull(ps);\n    int m = int(ch.size());\n\
    \    auto index_of = [&](const point<T>& p) {\n        return int(std::find(ps.begin(),\
    \ ps.end(), p) - ps.begin());\n    };\n    if (m == 1) return {0, 1};\n    if\
    \ (m == 2) return {index_of(ch[0]), index_of(ch[1])};\n    std::pair<int, int>\
    \ ret = {0, 1};\n    T best = norm(ch[0] - ch[1]);\n    for (int i = 0, j = 1;\
    \ i < m; i++) {\n        while (norm(ch[i] - ch[(j + 1) % m]) > norm(ch[i] - ch[j]))\
    \ j = (j + 1) % m;\n        if (norm(ch[i] - ch[j]) > best) {\n            best\
    \ = norm(ch[i] - ch[j]);\n            ret = {i, j};\n        }\n    }\n    return\
    \ {index_of(ch[ret.first]), index_of(ch[ret.second])};\n}\ntemplate <class T>\
    \ std::pair<int, int> closest_pair(const std::vector<point<T>>& ps) {\n    int\
    \ n = int(ps.size());\n    assert(n >= 2);\n    std::vector<int> id(n);\n    for\
    \ (int i = 0; i < n; i++) id[i] = i;\n    std::sort(id.begin(), id.end(), [&](int\
    \ i, int j) { return ps[i] < ps[j]; });\n    std::pair<int, int> ret = {id[0],\
    \ id[1]};\n    T best = norm(ps[id[0]] - ps[id[1]]);\n    std::vector<int> buf(n);\n\
    \    auto rec = [&](auto rec, int l, int r) -> void {\n        if (r - l <= 1)\
    \ return;\n        int m = (l + r) / 2;\n        T x = ps[id[m]].x;\n        rec(rec,\
    \ l, m);\n        rec(rec, m, r);\n        std::inplace_merge(id.begin() + l,\
    \ id.begin() + m, id.begin() + r,\n                           [&](int i, int j)\
    \ { return ps[i].y < ps[j].y; });\n        int k = 0;\n        for (int t = l;\
    \ t < r; t++) {\n            int i = id[t];\n            T dx = ps[i].x - x;\n\
    \            if (dx * dx >= best) continue;\n            for (int u = k - 1; u\
    \ >= 0; u--) {\n                int j = buf[u];\n                T dy = ps[i].y\
    \ - ps[j].y;\n                if (dy * dy >= best) break;\n                T d\
    \ = norm(ps[i] - ps[j]);\n                if (d < best) {\n                  \
    \  best = d;\n                    ret = {j, i};\n                }\n         \
    \   }\n            buf[k++] = i;\n        }\n    };\n    rec(rec, 0, n);\n   \
    \ return ret;\n}\ntemplate <std::floating_point T> polygon<T> convex_cut(const\
    \ polygon<T>& poly, const line<T>& l) {\n    int n = int(poly.size());\n    polygon<T>\
    \ ret;\n    for (int i = 0; i < n; i++) {\n        const point<T>& p = poly[i];\n\
    \        const point<T>& q = poly[(i + 1) % n];\n        int cp = ccw(l.a, l.b,\
    \ p), cq = ccw(l.a, l.b, q);\n        if (cp >= 0) ret.push_back(p);\n       \
    \ if (cp * cq < 0) ret.push_back(cross_point(l, line<T>(p, q)));\n    }\n    return\
    \ ret;\n}\n}  // namespace geo\n#line 13 \"geometry/circle.hpp\"\nnamespace geo\
    \ {\ntemplate <std::floating_point T> struct circle {\n    point<T> c;\n    T\
    \ r;\n    circle() : r(0) {\n    }\n    circle(const point<T>& c, T r) : c(c),\
    \ r(r) {\n    }\n    friend std::istream& operator>>(std::istream& is, circle&\
    \ o) {\n        return is >> o.c >> o.r;\n    }\n};\ntemplate <std::floating_point\
    \ T> T area(const circle<T>& o) {\n    return std::numbers::pi_v<T> * o.r * o.r;\n\
    }\ntemplate <std::floating_point T> int contains(const circle<T>& o, const point<T>&\
    \ p) {\n    int s = sgn(abs(p - o.c) - o.r);\n    return s > 0 ? 0 : s == 0 ?\
    \ 1 : 2;\n}\ntemplate <std::floating_point T> bool intersect(const line<T>& l,\
    \ const circle<T>& o) {\n    return sgn(dist(l, o.c) - o.r) <= 0;\n}\ntemplate\
    \ <std::floating_point T> bool intersect(const circle<T>& o, const line<T>& l)\
    \ {\n    return intersect(l, o);\n}\ntemplate <std::floating_point T> bool intersect(const\
    \ segment<T>& s, const circle<T>& o) {\n    if (sgn(dist(s, o.c) - o.r) > 0) return\
    \ false;\n    return sgn(abs(s.a - o.c) - o.r) >= 0 || sgn(abs(s.b - o.c) - o.r)\
    \ >= 0;\n}\ntemplate <std::floating_point T> bool intersect(const circle<T>& o,\
    \ const segment<T>& s) {\n    return intersect(s, o);\n}\ntemplate <std::floating_point\
    \ T> int count_common_tangents(const circle<T>& a, const circle<T>& b) {\n   \
    \ T d = abs(a.c - b.c);\n    if (sgn(d - (a.r + b.r)) > 0) return 4;\n    if (sgn(d\
    \ - (a.r + b.r)) == 0) return 3;\n    if (sgn(d - std::abs(a.r - b.r)) > 0) return\
    \ 2;\n    if (sgn(d - std::abs(a.r - b.r)) == 0) return 1;\n    return 0;\n}\n\
    template <std::floating_point T> bool intersect(const circle<T>& a, const circle<T>&\
    \ b) {\n    int k = count_common_tangents(a, b);\n    return 1 <= k && k <= 3;\n\
    }\ntemplate <std::floating_point T> std::vector<point<T>> cross_points(const line<T>&\
    \ l, const circle<T>& o) {\n    if (!intersect(l, o)) return {};\n    point<T>\
    \ p = projection(l, o.c);\n    T h = std::sqrt(std::max<T>(0, o.r * o.r - norm(p\
    \ - o.c)));\n    point<T> v = unit(l.b - l.a) * h;\n    std::vector<point<T>>\
    \ ret = {p - v, p + v};\n    if (ret[1] < ret[0]) std::swap(ret[0], ret[1]);\n\
    \    return ret;\n}\ntemplate <std::floating_point T> std::vector<point<T>> cross_points(const\
    \ circle<T>& o, const line<T>& l) {\n    return cross_points(l, o);\n}\ntemplate\
    \ <std::floating_point T> std::vector<point<T>> cross_points(const segment<T>&\
    \ s, const circle<T>& o) {\n    std::vector<point<T>> ret = cross_points(to_line(s),\
    \ o);\n    ret.erase(std::remove_if(ret.begin(), ret.end(), [&](const point<T>&\
    \ p) { return !on_segment(s, p); }),\n              ret.end());\n    return ret;\n\
    }\ntemplate <std::floating_point T> std::vector<point<T>> cross_points(const circle<T>&\
    \ o, const segment<T>& s) {\n    return cross_points(s, o);\n}\ntemplate <std::floating_point\
    \ T> std::vector<point<T>> cross_points(const circle<T>& a, const circle<T>& b)\
    \ {\n    if (!intersect(a, b)) return {};\n    T d = abs(a.c - b.c);\n    T x\
    \ = (d * d + a.r * a.r - b.r * b.r) / (2 * d);\n    T h = std::sqrt(std::max<T>(0,\
    \ a.r * a.r - x * x));\n    point<T> e = unit(b.c - a.c);\n    point<T> m = a.c\
    \ + e * x, v = normal(e) * h;\n    std::vector<point<T>> ret = {m - v, m + v};\n\
    \    if (ret[1] < ret[0]) std::swap(ret[0], ret[1]);\n    return ret;\n}\ntemplate\
    \ <std::floating_point T> std::vector<point<T>> tangent_points(const circle<T>&\
    \ o, const point<T>& p) {\n    assert(sgn(abs(p - o.c) - o.r) >= 0);\n    T r\
    \ = std::sqrt(std::max<T>(0, norm(p - o.c) - o.r * o.r));\n    return cross_points(o,\
    \ circle<T>(p, r));\n}\ntemplate <std::floating_point T> std::vector<point<T>>\
    \ common_tangents(const circle<T>& a, const circle<T>& b) {\n    std::vector<point<T>>\
    \ ret;\n    T d = abs(a.c - b.c);\n    if (sgn(d - std::abs(a.r - b.r)) >= 0)\
    \ {\n        T r = std::sqrt(std::max<T>(0, d * d - (a.r - b.r) * (a.r - b.r)\
    \ + b.r * b.r));\n        std::vector<point<T>> ps = cross_points(a, circle<T>(b.c,\
    \ r));\n        ret.insert(ret.end(), ps.begin(), ps.end());\n    }\n    if (sgn(d\
    \ - (a.r + b.r)) >= 0) {\n        point<T> p = a.c + (b.c - a.c) * (a.r / (a.r\
    \ + b.r));\n        std::vector<point<T>> ps = tangent_points(a, p);\n       \
    \ ret.insert(ret.end(), ps.begin(), ps.end());\n    }\n    std::sort(ret.begin(),\
    \ ret.end());\n    ret.erase(std::unique(ret.begin(), ret.end()), ret.end());\n\
    \    return ret;\n}\ntemplate <std::floating_point T> circle<T> incircle(const\
    \ point<T>& a, const point<T>& b, const point<T>& c) {\n    T x = abs(b - c),\
    \ y = abs(c - a), z = abs(a - b);\n    point<T> p = (a * x + b * y + c * z) /\
    \ (x + y + z);\n    return circle<T>(p, dist(line<T>(a, b), p));\n}\ntemplate\
    \ <std::floating_point T> circle<T> circumcircle(const point<T>& a, const point<T>&\
    \ b, const point<T>& c) {\n    point<T> p = cross_point(perpendicular_bisector(a,\
    \ b), perpendicular_bisector(a, c));\n    return circle<T>(p, abs(a - p));\n}\n\
    template <std::floating_point T> circle<T> smallest_enclosing_circle(std::vector<point<T>>\
    \ ps) {\n    int n = int(ps.size());\n    assert(n >= 1);\n    std::shuffle(ps.begin(),\
    \ ps.end(), std::mt19937(123456789));\n    circle<T> ret(ps[0], 0);\n    for (int\
    \ i = 1; i < n; i++) {\n        if (contains(ret, ps[i])) continue;\n        ret\
    \ = circle<T>(ps[i], 0);\n        for (int j = 0; j < i; j++) {\n            if\
    \ (contains(ret, ps[j])) continue;\n            ret = circle<T>((ps[i] + ps[j])\
    \ / T(2), abs(ps[i] - ps[j]) / T(2));\n            for (int k = 0; k < j; k++)\
    \ {\n                if (contains(ret, ps[k])) continue;\n                ret\
    \ = circumcircle(ps[i], ps[j], ps[k]);\n            }\n        }\n    }\n    return\
    \ ret;\n}\ntemplate <std::floating_point T> T area_of_intersection(const circle<T>&\
    \ o, const polygon<T>& poly) {\n    int n = int(poly.size());\n    auto tri =\
    \ [](const point<T>& a, const point<T>& b) { return cross(a, b); };\n    auto\
    \ sector = [&](const point<T>& a, const point<T>& b) { return o.r * o.r * arg(rotate(b,\
    \ -arg(a))); };\n    auto inside = [&](const point<T>& a) { return sgn(abs(a)\
    \ - o.r) < 0; };\n    T ret = 0;\n    for (int i = 0; i < n; i++) {\n        point<T>\
    \ a = poly[i] - o.c, b = poly[(i + 1) % n] - o.c;\n        segment<T> s(a, b);\n\
    \        circle<T> c(point<T>(), o.r);\n        if (!intersect(s, c)) {\n    \
    \        ret += inside(a) ? tri(a, b) : sector(a, b);\n            continue;\n\
    \        }\n        std::vector<point<T>> ps = cross_points(s, c);\n        point<T>\
    \ p = ps[0], q = ps[ps.size() - 1];\n        if (sgn(dot(b - a, q - p)) < 0) std::swap(p,\
    \ q);\n        ret += inside(a) ? tri(a, p) : sector(a, p);\n        ret += tri(p,\
    \ q);\n        ret += inside(b) ? tri(q, b) : sector(q, b);\n    }\n    return\
    \ ret / 2;\n}\ntemplate <std::floating_point T> T area_of_intersection(const polygon<T>&\
    \ poly, const circle<T>& o) {\n    return area_of_intersection(o, poly);\n}\n\
    template <std::floating_point T> T area_of_intersection(const circle<T>& a, const\
    \ circle<T>& b) {\n    T d = abs(a.c - b.c);\n    if (sgn(a.r + b.r - d) <= 0)\
    \ return 0;\n    if (sgn(std::abs(a.r - b.r) - d) >= 0) return std::min(area(a),\
    \ area(b));\n    auto part = [&](const circle<T>& x, const circle<T>& y) {\n \
    \       T cs = (d * d + x.r * x.r - y.r * y.r) / (2 * d * x.r);\n        T theta\
    \ = std::acos(std::clamp<T>(cs, -1, 1));\n        return x.r * x.r * (theta -\
    \ std::sin(2 * theta) / 2);\n    };\n    return part(a, b) + part(b, a);\n}\n\
    template <std::floating_point T> circle<T> circle_of_apollonius(const point<T>&\
    \ a, const point<T>& b, T n, T m) {\n    assert(sgn(n - m) != 0);\n    point<T>\
    \ c = (a * (-m * m) + b * (n * n)) / (n * n - m * m);\n    return circle<T>(c,\
    \ std::sqrt(abs(a - c) * abs(b - c)));\n}\n}  // namespace geo\n#line 9 \"test/aoj/CGL_7_B.test.cpp\"\
    \nusing namespace std;\nusing namespace geo;\nusing P = point<double>;\nint main()\
    \ {\n    cout << fixed << setprecision(20);\n    P a, b, c;\n    cin >> a >> b\
    \ >> c;\n    circle<double> o = incircle(a, b, c);\n    cout << o.c << ' ' <<\
    \ o.r << '\\n';\n}\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_B\"\
    \n#define ERROR 0.000001\n#include <iomanip>\n#include <iostream>\n#include <vector>\n\
    \n#include \"geometry/circle.hpp\"\nusing namespace std;\nusing namespace geo;\n\
    using P = point<double>;\nint main() {\n    cout << fixed << setprecision(20);\n\
    \    P a, b, c;\n    cin >> a >> b >> c;\n    circle<double> o = incircle(a, b,\
    \ c);\n    cout << o.c << ' ' << o.r << '\\n';\n}\n"
  dependsOn:
  - geometry/circle.hpp
  - geometry/line.hpp
  - geometry/point.hpp
  - geometry/polygon.hpp
  isVerificationFile: true
  path: test/aoj/CGL_7_B.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 23:24:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_7_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_7_B.test.cpp
- /verify/test/aoj/CGL_7_B.test.cpp.html
title: test/aoj/CGL_7_B.test.cpp
---
