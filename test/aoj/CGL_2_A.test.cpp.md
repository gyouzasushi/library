---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: 'Geometry: Line'
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: 'Geometry: Point'
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A
  bundledCode: "#line 1 \"test/aoj/CGL_2_A.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A\"\n#include\
    \ <iomanip>\n#include <iostream>\n#include <vector>\n\n#line 2 \"geometry/line.hpp\"\
    \n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <concepts>\n\
    #line 7 \"geometry/line.hpp\"\n\n#line 5 \"geometry/point.hpp\"\n#include <type_traits>\n\
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
    \ b.x) == 0 && sgn(a.y - b.y) == 0;\n    }\n    friend bool operator!=(const point&\
    \ a, const point& b) {\n        return !(a == b);\n    }\n    friend bool operator<(const\
    \ point& a, const point& b) {\n        if (sgn(a.x - b.x) != 0) return a.x < b.x;\n\
    \        return sgn(a.y - b.y) < 0;\n    }\n    friend bool operator>(const point&\
    \ a, const point& b) {\n        return b < a;\n    }\n    friend std::istream&\
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
    #line 8 \"test/aoj/CGL_2_A.test.cpp\"\nusing namespace std;\nusing namespace geo;\n\
    using P = point<double>;\nint main() {\n    int q;\n    cin >> q;\n    while (q--)\
    \ {\n        line<double> l, m;\n        cin >> l >> m;\n        if (parallel(l,\
    \ m)) cout << 2 << '\\n';\n        else if (orthogonal(l, m)) cout << 1 << '\\\
    n';\n        else cout << 0 << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A\"\
    \n#include <iomanip>\n#include <iostream>\n#include <vector>\n\n#include \"geometry/line.hpp\"\
    \nusing namespace std;\nusing namespace geo;\nusing P = point<double>;\nint main()\
    \ {\n    int q;\n    cin >> q;\n    while (q--) {\n        line<double> l, m;\n\
    \        cin >> l >> m;\n        if (parallel(l, m)) cout << 2 << '\\n';\n   \
    \     else if (orthogonal(l, m)) cout << 1 << '\\n';\n        else cout << 0 <<\
    \ '\\n';\n    }\n}\n"
  dependsOn:
  - geometry/line.hpp
  - geometry/point.hpp
  isVerificationFile: true
  path: test/aoj/CGL_2_A.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 22:57:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_2_A.test.cpp
- /verify/test/aoj/CGL_2_A.test.cpp.html
title: test/aoj/CGL_2_A.test.cpp
---
