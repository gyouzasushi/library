---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#line 1 \"test/library-checker/sort_points_by_argument.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\n\
    #include <algorithm>\n#include <iostream>\n#include <vector>\n\n#line 2 \"geometry/point.hpp\"\
    \n#include <cmath>\n#include <concepts>\n#line 5 \"geometry/point.hpp\"\n#include\
    \ <type_traits>\nnamespace geo {\ninline long double eps = 1e-9;\ntemplate <class\
    \ T> int sgn(T a) {\n    if constexpr (std::is_integral_v<T>) {\n        return\
    \ (a > 0) - (a < 0);\n    } else {\n        return a < -eps ? -1 : a > eps ? 1\
    \ : 0;\n    }\n}\ntemplate <class T> struct point {\n    T x, y;\n    point()\
    \ : x(0), y(0) {\n    }\n    point(T x, T y) : x(x), y(y) {\n    }\n    point&\
    \ operator+=(const point& p) {\n        x += p.x, y += p.y;\n        return *this;\n\
    \    }\n    point& operator-=(const point& p) {\n        x -= p.x, y -= p.y;\n\
    \        return *this;\n    }\n    point& operator*=(T k) {\n        x *= k, y\
    \ *= k;\n        return *this;\n    }\n    point& operator/=(T k) requires std::floating_point<T>\
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
    \ namespace geo\n#line 7 \"test/library-checker/sort_points_by_argument.test.cpp\"\
    \nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<geo::point<long\
    \ long>> ps(n);\n    for (auto& p : ps) std::cin >> p;\n    std::sort(ps.begin(),\
    \ ps.end(), geo::arg_less{});\n    for (const auto& p : ps) std::cout << p <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#include \"\
    geometry/point.hpp\"\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<geo::point<long\
    \ long>> ps(n);\n    for (auto& p : ps) std::cin >> p;\n    std::sort(ps.begin(),\
    \ ps.end(), geo::arg_less{});\n    for (const auto& p : ps) std::cout << p <<\
    \ '\\n';\n}\n"
  dependsOn:
  - geometry/point.hpp
  isVerificationFile: true
  path: test/library-checker/sort_points_by_argument.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 22:57:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/sort_points_by_argument.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/sort_points_by_argument.test.cpp
- /verify/test/library-checker/sort_points_by_argument.test.cpp.html
title: test/library-checker/sort_points_by_argument.test.cpp
---
