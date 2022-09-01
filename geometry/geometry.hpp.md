---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/geometry.hpp\"\nnamespace geometry {\nusing coordinate_t\
    \ = double;\nconst coordinate_t PI = std::acos(-1);\nconst coordinate_t EPS =\
    \ 1e-9;\nint sgn(coordinate_t a) {\n    return (a < -EPS) ? -1 : (a > EPS) ? 1\
    \ : 0;\n};\n\nstruct Point {\n    coordinate_t x, y;\n    Point() {\n    }\n \
    \   Point(coordinate_t _x, coordinate_t _y) : x(_x), y(_y) {\n    }\n    Point\
    \ operator+(const Point &rhs) const {\n        Point res(*this);\n        return\
    \ res += rhs;\n    }\n    Point operator-(const Point &rhs) const {\n        Point\
    \ res(*this);\n        return res -= rhs;\n    }\n    Point operator*(const coordinate_t\
    \ &rhs) const {\n        Point res(*this);\n        return res *= rhs;\n    }\n\
    \    Point operator/(const coordinate_t &rhs) const {\n        Point res(*this);\n\
    \        return res /= rhs;\n    }\n    inline bool operator<(const Point &b)\
    \ {\n        if (sgn(x - b.x)) return sgn(x - b.x) < 0;\n        return sgn(y\
    \ - b.y) < 0;\n    }\n    Point operator+=(const Point &rhs) {\n        x += rhs.x,\
    \ y += rhs.y;\n        return *this;\n    }\n    Point operator-=(const Point\
    \ &rhs) {\n        x -= rhs.x, y -= rhs.y;\n        return *this;\n    }\n   \
    \ Point operator*=(const coordinate_t &rhs) {\n        x *= rhs, y *= rhs;\n \
    \       return *this;\n    }\n    Point operator/=(const coordinate_t &rhs) {\n\
    \        x /= rhs, y /= rhs;\n        return *this;\n    }\n    coordinate_t abs()\
    \ const {\n        return std::sqrt(x * x + y * y);\n    }\n    coordinate_t arg()\
    \ const {\n        return std::atan2(y, x);\n    }\n    Point normal() const {\n\
    \        return Point(-y, x);\n    }\n    Point unit() const {\n        return\
    \ *this / abs();\n    }\n};\ninline bool operator<(const Point &a, const Point\
    \ &b) {\n    if (sgn(a.x - b.x)) return sgn(a.x - b.x) < 0;\n    return sgn(a.y\
    \ - b.y) < 0;\n}\ninline bool operator==(const Point &a, const Point &b) {\n \
    \   return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;\n}\ninline bool operator>(const\
    \ Point &a, const Point &b) {\n    if (sgn(a.x - b.x)) return sgn(a.x - b.x) >\
    \ 0;\n    return sgn(a.y - b.y) > 0;\n}\nstd::istream &operator>>(std::istream\
    \ &is, Point &p) {\n    coordinate_t x, y;\n    is >> x >> y;\n    p = {x, y};\n\
    \    return is;\n}\nstd::ostream &operator<<(std::ostream &os, const Point &p)\
    \ {\n    return os << p.x << ' ' << p.y;\n}\nPoint rotate(const Point &p, const\
    \ coordinate_t &theta) {\n    Point ret;\n    ret.x = p.x * cos(theta) - p.y *\
    \ sin(theta);\n    ret.y = p.x * sin(theta) + p.y * cos(theta);\n    return ret;\n\
    }\ncoordinate_t dot(const Point &a, const Point &b) {\n    return a.x * b.x +\
    \ a.y * b.y;\n}\ncoordinate_t det(const Point &a, const Point &b) {\n    return\
    \ a.x * b.y - a.y * b.x;\n}\n\nconst int COUNTER_CLOCKWISE = 1;\nconst int CLOCKWISE\
    \ = -1;\nconst int ONLINE_BACK = -2;\nconst int ONLINE_FRONT = 2;\nconst int ON_SEGMENT\
    \ = 0;\nint ccw(Point a, Point b, Point c) {\n    if (sgn(det(b - a, c - a)) >\
    \ 0) {\n        return COUNTER_CLOCKWISE;  // counter clockwise\n    }\n    if\
    \ (sgn(det(b - a, c - a)) < 0) {\n        return CLOCKWISE;  // clockwise\n  \
    \  }\n    if (sgn(dot(b - a, c - a)) < 0) {\n        return ONLINE_BACK;  // c\
    \ - a - b\n    }\n    if (sgn(dot(a - b, c - b)) < 0) {\n        return ONLINE_FRONT;\
    \  // a - b - c\n    }\n    return ON_SEGMENT;  // a - c - b\n}\n\nstruct Line\
    \ {\n    Point a, b;\n    Line() {\n    }\n    Line(Point _a, Point _b) : a(_a),\
    \ b(_b) {\n    }\n    Point projection(const Point &p) const {\n        return\
    \ a +\n               (b - a) * (dot(b - a, p - a) / ((b - a).abs() * (b - a).abs()));\n\
    \    }\n    Point reflection(const Point &p) const {\n        return projection(p)\
    \ * 2 - p;\n    }\n};\nstd::istream &operator>>(std::istream &is, Line &l) {\n\
    \    Point a, b;\n    is >> a >> b;\n    l = {a, b};\n    return is;\n};\n\nstruct\
    \ Segment {\n    Point a, b;\n    Segment() {\n    }\n    Segment(Point _a, Point\
    \ _b) : a(_a), b(_b) {\n    }\n    Line vertical_bisector() {\n        Point c\
    \ = (a + b) / 2;\n        Point v = (a - b).normal();\n        return {c + v,\
    \ c - v};\n    }\n};\nstd::istream &operator>>(std::istream &is, Segment &s) {\n\
    \    Point a, b;\n    is >> a >> b;\n    s = {a, b};\n    return is;\n};\n\nLine\
    \ from_segment(const Segment &s) {\n    return Line(s.a, s.b);\n}\n\nstruct Polygon\
    \ : std::vector<Point> {\n    Polygon(int n = 0) : std::vector<Point>(n) {\n \
    \   }\n    coordinate_t area() const {\n        coordinate_t ret = 0;\n      \
    \  for (int i = 0; i < (int)size(); i++) {\n            ret += det((*this)[i],\
    \ (*this)[(i + 1) % (int)size()]);\n        }\n        ret /= 2.0;\n        ret\
    \ = std::fabs(ret);\n        return ret;\n    }\n    bool is_convex() const {\n\
    \        for (int i = 0; i < (int)size(); i++) {\n            if (ccw((*this)[i],\
    \ (*this)[(i + 1) % (int)size()],\n                    (*this)[(i + 2) % (int)size()])\
    \ == CLOCKWISE) {\n                return false;\n            }\n        }\n \
    \       return true;\n    }\n    coordinate_t diameter() const {\n        assert(is_convex());\n\
    \        coordinate_t ret = 0;\n        int r = 0;\n        for (int l = 0; l\
    \ < (int)size(); l++) {\n            while (sgn(((*this)[l] - (*this)[r]).abs()\
    \ -\n                       ((*this)[l] - (*this)[(r + 1) % (int)size()]).abs())\
    \ <\n                   0) {\n                r++;\n                if (r == (int)size())\
    \ r = 0;\n            }\n            ret = std::max(ret, ((*this)[l] - (*this)[r]).abs());\n\
    \        }\n        return ret;\n    }\n    int contain(const Point &p) const\
    \ {\n        bool is_in = false;\n        for (int i = 0; i < (int)size(); i++)\
    \ {\n            int ccw_ = ccw((*this)[i], (*this)[(i + 1) % (int)size()], p);\n\
    \            if (ccw_ == ON_SEGMENT) {\n                return 1;  // p is on\
    \ a segment of polygon\n            }\n            Point a = (*this)[i] - p, b\
    \ = (*this)[(i + 1) % (int)size()] - p;\n            if (b < a) std::swap(a, b);\n\
    \            if (sgn(a.x) <= 0 && sgn(b.x) > 0 && sgn(det(a, b)) < 0)\n      \
    \          is_in ^= true;\n        }\n        return is_in ? 2 /* polygon contains\
    \ p */ : 0;\n    }\n};\n\nstruct Circle {\n    Point c;\n    coordinate_t r;\n\
    \    Circle() {\n    }\n    Circle(Point _c, coordinate_t _r) : c(_c), r(_r) {\n\
    \        assert(sgn(r) >= 0);\n    }\n    coordinate_t area() const {\n      \
    \  return r * r * PI;\n    }\n    int contain(const Point &p) const {\n      \
    \  return sgn((c - p).abs() - r) > 0    ? 0\n               : sgn((c - p).abs()\
    \ - r) == 0 ? 1\n                                             : 2;\n    }\n};\n\
    \nbool intersect(const Segment &s1, const Segment &s2);\nbool intersect(const\
    \ Line &l1, const Line &l2);\nbool intersect(const Segment &s, const Line &l);\n\
    bool intersect(const Segment &s, const Circle &c);\nbool intersect(const Line\
    \ &s, const Circle &c);\n\nPoint cross_point(const Segment &s1, const Segment\
    \ &s2);\nPoint cross_point(const Line &l1, const Line &l2);\nPoint cross_point(const\
    \ Segment &s, const Line &l);\nstd::vector<Point> cross_points(const Segment &s,\
    \ const Circle &c);\nstd::vector<Point> cross_points(const Line &l, const Circle\
    \ &c);\n\ncoordinate_t dist(const Point &p1, const Point &p2) {\n    return (p1\
    \ - p2).abs();\n}\ncoordinate_t dist(const Segment &s, const Point &p) {\n   \
    \ if (sgn(dot(s.b - s.a, p - s.a)) < 0) {\n        return (p - s.a).abs();\n \
    \   }\n    if (sgn(dot(s.a - s.b, p - s.b)) < 0) {\n        return (p - s.b).abs();\n\
    \    }\n    return std::fabs(det(p - s.a, s.b - s.a)) / (s.b - s.a).abs();\n}\n\
    coordinate_t dist(const Point &p, const Segment &s) {\n    return dist(s, p);\n\
    }\ncoordinate_t dist(const Segment &s1, const Segment &s2) {\n    if (intersect(s1,\
    \ s2)) return 0;\n    return std::min(\n        {dist(s1, s2.a), dist(s1, s2.b),\
    \ dist(s2, s1.a), dist(s2, s1.b)});\n}\ncoordinate_t dist(const Line &l, const\
    \ Point &p) {\n    return std::fabs(det(p - l.a, l.b - l.a)) / (l.b - l.a).abs();\n\
    }\ncoordinate_t dist(const Point &p, const Line &l) {\n    return dist(l, p);\n\
    }\ncoordinate_t dist(const Line &l1, const Line &l2) {\n    if (intersect(l1,\
    \ l2)) return 0;\n    return dist(l1.a, l2);\n}\ncoordinate_t dist(const Segment\
    \ &s, const Line &l) {\n    if (intersect(s, l)) return 0;\n    return std::min(dist(s.a,\
    \ l), dist(s.b, l));\n}\ncoordinate_t dist(const Line &l, const Segment &s) {\n\
    \    return dist(s, l);\n}\n\nbool intersect(const Segment &s1, const Segment\
    \ &s2) {\n    return sgn(ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b)) <= 0 &&\n\
    \           sgn(ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b)) <= 0;\n}\nbool\
    \ intersect(const Line &l1, const Line &l2) {\n    return sgn(det(l1.b - l1.a,\
    \ l2.b - l2.a)) != 0;\n}\nbool intersect(const Segment &s, const Line &l) {\n\
    \    return ccw(l.a, l.b, s.a) * ccw(l.a, l.b, s.b) == -1;\n}\nbool intersect(const\
    \ Line &l, const Segment &s) {\n    return intersect(s, l);\n}\nbool intersect(const\
    \ Segment &s, const Circle &c) {\n    if (sgn(dist(s, c.c) - c.r) > 0) return\
    \ false;\n    return !(sgn((c.c - s.a).abs() - c.r) < 0 &&\n             sgn((c.c\
    \ - s.b).abs() - c.r) < 0);\n}\nbool intersect(const Circle &c, const Segment\
    \ &s) {\n    return intersect(s, c);\n}\nbool intersect(const Line &l, const Circle\
    \ &c) {\n    return sgn(dist(l, c.c) - c.r) <= 0;\n}\nbool intersect(const Circle\
    \ &c, const Line &l) {\n    return intersect(l, c);\n}\nbool intersect(Circle\
    \ c1, Circle c2) {\n    return sgn((c1.c - c2.c).abs() - (c1.r + c2.r)) <= 0 &&\n\
    \           sgn((c1.c - c2.c).abs() - std::fabs(c1.r - c2.r)) >= 0;\n}\n\nPoint\
    \ cross_point(const Segment &s1, const Segment &s2) {\n    assert(intersect(s1,\
    \ s2));\n    return cross_point(from_segment(s1), from_segment(s2));\n}\nPoint\
    \ cross_point(const Segment &s, const Line &l) {\n    assert(intersect(s, l));\n\
    \    return s.a + (s.b - s.a) *\n                     (det(l.a - s.a, l.b - l.a)\
    \ / det(s.b - s.a, l.b - l.a));\n}\nPoint cross_point(const Line &l, const Segment\
    \ &s) {\n    return cross_point(s, l);\n}\nPoint cross_point(const Line &l1, const\
    \ Line &l2) {\n    assert(intersect(l1, l2));\n    return l1.a + (l1.b - l1.a)\
    \ * (det(l2.a - l1.a, l2.b - l2.a) /\n                                   det(l1.b\
    \ - l1.a, l2.b - l2.a));\n}\nstd::vector<Point> cross_points(const Segment &s,\
    \ const Circle &c) {\n    if (!intersect(s, c)) return {};\n    std::vector<Point>\
    \ ret = cross_points(from_segment(s), c);\n    ret.erase(std::remove_if(ret.begin(),\
    \ ret.end(),\n                             [&](Point p) {\n                  \
    \               return !(p == s.a) && !(p == s.b) &&\n                       \
    \                 (p < s.a) == (p < s.b);\n                             }),\n\
    \              ret.end());\n    return ret;\n}\nstd::vector<Point> cross_points(const\
    \ Circle &c, const Segment &s) {\n    return cross_points(s, c);\n}\nstd::vector<Point>\
    \ cross_points(const Line &l, const Circle &c) {\n    if (!intersect(l, c)) return\
    \ {};\n    Point p = l.projection(c.c);\n    Point v = (l.b - l.a) *\n       \
    \       std::sqrt(c.r * c.r - (p - c.c).abs() * (p - c.c).abs()) /\n         \
    \     (l.b - l.a).abs();\n    v = std::max(v, v * -1);\n    return {p - v, p +\
    \ v};\n}\nstd::vector<Point> cross_points(const Circle &c, const Line &l) {\n\
    \    return cross_points(l, c);\n}\nstd::vector<Point> cross_points(Circle c1,\
    \ Circle c2) {\n    if (!intersect(c1, c2)) return {};\n    coordinate_t d = (c1.c\
    \ - c2.c).abs();\n    coordinate_t d1 = (d + (c1.r * c1.r - c2.r * c2.r) / d)\
    \ / 2;\n    coordinate_t h = std::sqrt(c1.r * c1.r - d1 * d1);\n    Point v =\
    \ (c2.c - c1.c).normal();\n    v *= h / v.abs();\n    std::vector<Point> ret =\
    \ {c1.c + (c2.c - c1.c) * (d1 / d) + v,\n                              c1.c +\
    \ (c2.c - c1.c) * (d1 / d) - v};\n    if (ret[0] > ret[1]) std::swap(ret[0], ret[1]);\n\
    \    return ret;\n}\n\n// \u4E09\u89D2\u5F62\u306E\u5185\u63A5\u5186\nCircle incircle_of_triangle(const\
    \ Point &pa, const Point &pb, const Point &pc) {\n    coordinate_t a = (pb - pc).abs(),\
    \ b = (pc - pa).abs(), c = (pa - pb).abs();\n    Point p = (pa * a + pb * b +\
    \ pc * c) / (a + b + c);\n    coordinate_t r = dist(Line(pa, pb), p);\n    return\
    \ Circle(p, r);\n}\n// \u4E09\u89D2\u5F62\u306E\u5185\u63A5\u5186\nCircle incircle_of_triangle(const\
    \ Polygon &poly) {\n    assert((int)poly.size() == 3);\n    const Point &pa =\
    \ poly[0], &pb = poly[1], &pc = poly[2];\n    return incircle_of_triangle(pa,\
    \ pb, pc);\n}\n// \u4E09\u89D2\u5F62\u306E\u5916\u63A5\u5186\nCircle circumscribed_circle_of_triangle(const\
    \ Point &pa, const Point &pb,\n                                        const Point\
    \ &pc) {\n    Line l1 = Segment(pa, pb).vertical_bisector();\n    Line l2 = Segment(pa,\
    \ pc).vertical_bisector();\n    Point p = cross_point(l1, l2);\n    coordinate_t\
    \ r = (pa - p).abs();\n    return Circle(p, r);\n}\n// \u4E09\u89D2\u5F62\u306E\
    \u5916\u63A5\u5186\nCircle circumscribed_circle_of_triangle(const Polygon &poly)\
    \ {\n    assert((int)poly.size() == 3);\n    const Point &pa = poly[0], &pb =\
    \ poly[1], &pc = poly[2];\n    return circumscribed_circle_of_triangle(pa, pb,\
    \ pc);\n}\n\n// \u51F8\u5305\nPolygon convex_hull(std::vector<Point> ps) {\n \
    \   int n = int(ps.size());\n    std::sort(ps.begin(), ps.end());\n    Polygon\
    \ ret(2 * n);\n    int k = 0;\n    for (int i = 0; i < n; ret[k++] = ps[i++])\
    \ {\n        while (k >= 2 &&\n               sgn(det(ret[k - 1] - ret[k - 2],\
    \ ps[i] - ret[k - 2])) < 0) {\n            k--;\n        }\n    }\n    for (int\
    \ i = n - 2, t = k + 1; i >= 0; ret[k++] = ps[i--]) {\n        while (k >= t &&\n\
    \               sgn(det(ret[k - 1] - ret[k - 2], ps[i] - ret[k - 2])) < 0) {\n\
    \            k--;\n        }\n    }\n    ret.resize(k - 1);\n    return ret;\n\
    }\n// \u6700\u5C0F\u5305\u542B\u5186\nCircle smallest_enclosing_circle(std::vector<Point>\
    \ ps) {\n    assert((int)ps.size() >= 2);\n    std::random_device seed_gen;\n\
    \    std::mt19937_64 rnd(seed_gen());\n    std::shuffle(ps.begin(), ps.end(),\
    \ rnd);\n    Circle ret((ps[0] + ps[1]) / 2, (ps[0] - ps[1]).abs() / 2);\n   \
    \ for (int i = 2; i < (int)ps.size(); i++) {\n        if (ret.contain(ps[i]))\
    \ continue;\n        ret = Circle((ps[0] + ps[i]) / 2, (ps[0] - ps[i]).abs() /\
    \ 2);\n        for (int j = 1; j < i; j++) {\n            if (ret.contain(ps[j]))\
    \ continue;\n            ret = Circle((ps[i] + ps[j]) / 2, (ps[i] - ps[j]).abs()\
    \ / 2);\n            for (int k = 0; k < j; k++) {\n                if (ret.contain(ps[k]))\
    \ continue;\n                ret = circumscribed_circle_of_triangle(ps[i], ps[j],\
    \ ps[k]);\n            }\n        }\n    }\n    return ret;\n}\n\n// \u5186c\u3068\
    \u591A\u89D2\u5F62p\u306E\u5171\u901A\u90E8\u5206\u306E\u9762\u7A4D\u3092\u8FD4\
    \u3059\u3002\ncoordinate_t area_of_intersection(Circle c, Polygon p) {\n    auto\
    \ signed_area_of_triangle = [](Point a, Point b) -> coordinate_t {\n        return\
    \ det(a, b);\n    };\n    auto signed_area_of_sector = [&c](Point a, Point b)\
    \ -> coordinate_t {\n        return c.r * c.r * (rotate(b, -a.arg()).arg());\n\
    \    };\n    auto is_in_circle = [&c](Point a) -> bool {\n        return sgn(a.abs()\
    \ - c.r) < 0;\n    };\n    coordinate_t ret = 0;\n    for (int i = 0; i < int(p.size());\
    \ i++) p[i] -= c.c;\n    for (int i = 0; i < int(p.size()); i++) {\n        const\
    \ Point &a = p[i], &b = p[(i + 1) % int(p.size())];\n        if (!intersect(Segment(a,\
    \ b), c)) {\n            ret += is_in_circle(a) ? signed_area_of_triangle(a, b)\n\
    \                                   : signed_area_of_sector(a, b);\n        }\
    \ else {\n            std::vector<Point> ps = cross_points(Segment(a, b), c);\n\
    \            Point s = ps[0], t = ps[1 % int(ps.size())];\n            if ((a\
    \ < b) != (s < t)) std::swap(s, t);\n            ret += is_in_circle(a) ? signed_area_of_triangle(a,\
    \ s)\n                                   : signed_area_of_sector(a, s);\n    \
    \        ret += signed_area_of_triangle(s, t);\n            ret += is_in_circle(b)\
    \ ? signed_area_of_triangle(t, b)\n                                   : signed_area_of_sector(t,\
    \ b);\n        }\n    }\n    ret = std::fabs(ret);\n    ret /= 2;\n    return\
    \ ret;\n}\n// \u5186c\u3068\u591A\u89D2\u5F62p\u306E\u5171\u901A\u90E8\u5206\u306E\
    \u9762\u7A4D\u3092\u8FD4\u3059\u3002\ncoordinate_t area_of_intersection(Polygon\
    \ p, Circle c) {\n    return area_of_intersection(c, p);\n}\n\n// \u5186c1\u3068\
    \u5186c2\u306E\u5171\u901A\u90E8\u5206\u306E\u9762\u7A4D\u3092\u8FD4\u3059\u3002\
    \ncoordinate_t area_of_intersection(const Circle &c1, const Circle &c2) {\n  \
    \  if (sgn(c1.r + c2.r - (c1.c - c2.c).abs()) <= 0) {\n        return 0;\n   \
    \ }\n    if (sgn(std::fabs(c1.r - c2.r) - (c1.c - c2.c).abs()) >= 0) {\n     \
    \   return std::min(c1.area(), c2.area());\n    }\n    auto unsigned_area_of_triangle\
    \ = [](Circle c1, Circle c2,\n                                        Point p)\
    \ -> coordinate_t {\n        return std::fabs(det(c2.c - c1.c, p - c1.c));\n \
    \   };\n    auto unsigned_area_of_sector = [](Circle c1, Circle c2,\n        \
    \                              Point p) -> coordinate_t {\n        return std::fabs(c1.r\
    \ * c1.r *\n                         rotate(c2.c - c1.c, -(p - c1.c).arg()).arg());\n\
    \    };\n    Point p = cross_points(c1, c2)[0];\n    coordinate_t ret = 0;\n \
    \   ret += unsigned_area_of_sector(c1, c2, p);\n    ret += unsigned_area_of_sector(c2,\
    \ c1, p);\n    ret -= unsigned_area_of_triangle(c1, c2, p);\n    return ret;\n\
    }\n\n// \u51F8\u591A\u89D2\u5F62poly\u3092\u76F4\u7DDAl\u3067\u5207\u65AD\u3057\
    \u305F\u3068\u304D\u306B\u3001\u305D\u306E\u5DE6\u5074\u306B\u3067\u304D\u308B\
    \u51F8\u591A\u89D2\u5F62\u3002\nPolygon convex_cut_left(const Polygon &poly, const\
    \ Line &l) {\n    assert(poly.is_convex());\n    Polygon ret;\n    for (int i\
    \ = 0; i < (int)poly.size(); i++) {\n        if (ccw(l.a, l.b, poly[i]) != CLOCKWISE)\
    \ {\n            ret.push_back(poly[i]);\n        }\n        Segment s(poly[i],\
    \ poly[(i + 1) % (int)poly.size()]);\n        if (intersect(s, l)) {\n       \
    \     ret.push_back(cross_point(s, l));\n        }\n    }\n    return ret;\n}\n\
    // \u51F8\u591A\u89D2\u5F62poly\u3092\u76F4\u7DDAl\u3067\u5207\u65AD\u3057\u305F\
    \u3068\u304D\u306B\u3001\u305D\u306E\u53F3\u5074\u306B\u3067\u304D\u308B\u51F8\
    \u591A\u89D2\u5F62\u3002\nPolygon convex_cut_right(const Polygon &poly, const\
    \ Line &l) {\n    assert(poly.is_convex());\n    Polygon ret;\n    for (int i\
    \ = 0; i < (int)poly.size(); i++) {\n        if (ccw(l.a, l.b, poly[i]) != COUNTER_CLOCKWISE)\
    \ {\n            ret.push_back(poly[i]);\n        }\n        Segment s(poly[i],\
    \ poly[(i + 1) % (int)poly.size()]);\n        if (intersect(s, l)) {\n       \
    \     ret.push_back(cross_point(s, l));\n        }\n    }\n    return ret;\n}\n\
    \n// \u70B9p\u3092\u901A\u308B\u5186c\u306E\u63A5\u7DDA\u3002\u63A5\u70B9\u3092\
    \u8FD4\u3059\u3002\nstd::vector<Point> tangent_points(const Circle &c, const Point\
    \ &p) {\n    assert(sgn((p - c.c).abs() - c.r) >= 0);\n    coordinate_t r = std::sqrt((c.c\
    \ - p).abs() * (c.c - p).abs() - c.r * c.r);\n    return cross_points(c, Circle(p,\
    \ r));\n}\n\n// \u5186c1\u3068\u5186c2\u306E\u5171\u901A\u63A5\u7DDA\u306E\u672C\
    \u6570\u3002\nint count_common_tangent(const Circle &c1, const Circle &c2) {\n\
    \    if (sgn((c1.c - c2.c).abs() - (c1.r + c2.r)) > 0) {\n        return 4;  //\
    \ do not cross\n    }\n    if (sgn((c1.c - c2.c).abs() - (c1.r + c2.r)) == 0)\
    \ {\n        return 3;  // circumscribed\n    }\n    if (sgn((c1.c - c2.c).abs()\
    \ - std::fabs(c1.r - c2.r)) > 0) {\n        return 2;  // intersects\n    }\n\
    \    if (sgn((c1.c - c2.c).abs() - std::fabs(c1.r - c2.r)) == 0) {\n        return\
    \ 1;  // inscribed\n    }\n    return 0;\n}\n\n// \u5186c1\u3068\u5186c2\u306E\
    \u5171\u901A\u63A5\u7DDA\u3002\u5186c1\u306B\u304A\u3051\u308B\u63A5\u70B9\u3092\
    \u8FD4\u3059\u3002\nstd::vector<Point> common_tangents(const Circle &c1, const\
    \ Circle &c2) {\n    std::vector<Point> ret, ret1, ret2;\n    if (sgn((c1.c -\
    \ c2.c).abs() - std::fabs(c1.r - c2.r)) >= 0) {\n        coordinate_t d = (c1.c\
    \ - c2.c).abs();\n        coordinate_t r =\n            std::sqrt(d * d - (c1.r\
    \ - c2.r) * (c1.r - c2.r) + c2.r * c2.r);\n        ret1 = cross_points(c1, Circle(c2.c,\
    \ r));\n    }\n    if (sgn((c1.c - c2.c).abs() - (c1.r + c2.r)) >= 0) {\n    \
    \    Point p = c1.c + (c2.c - c1.c) * c1.r / (c1.r + c2.r);\n        ret2 = tangent_points(c1,\
    \ p);\n    }\n    std::merge(ret1.begin(), ret1.end(), ret2.begin(), ret2.end(),\n\
    \               std::back_inserter(ret));\n    ret.erase(std::unique(ret.begin(),\
    \ ret.end()), ret.end());\n    return ret;\n}\n// (\u8DDD\u96E2, \u70B9\u306E\u30DA\
    \u30A2) \u3092\u8FD4\u3059\nstd::pair<coordinate_t, std::pair<Point, Point>> closest_pair(\n\
    \    std::vector<Point> ps) {\n    std::sort(ps.begin(), ps.end(),\n         \
    \     [](Point a, Point b) { return sgn(a.x - b.x) < 0; });\n    std::vector<Point>\
    \ memo(ps.size());\n    auto dfs = [&](auto dfs, int l,\n                   int\
    \ r) -> std::pair<coordinate_t, std::pair<Point, Point>> {\n        if (r - l\
    \ < 2) return {1e18, {Point(), Point()}};\n        int m = (r + l) / 2;\n    \
    \    coordinate_t x = ps[m].x;\n        auto l_res = dfs(dfs, l, m), r_res = dfs(dfs,\
    \ m, r);\n        auto [d, p] = (l_res.first < r_res.first ? l_res : r_res);\n\
    \        std::inplace_merge(ps.begin() + l, ps.begin() + m, ps.begin() + r,\n\
    \                           [](Point a, Point b) { return sgn(a.y - b.y) < 0;\
    \ });\n\n        int cur = 0;\n        for (int i = l; i < r; i++) {\n       \
    \     if (std::fabs(ps[i].x - x) >= d) continue;\n            for (int j = cur\
    \ - 1; j >= 0; j--) {\n                if (ps[i].y - memo[j].y >= d) break;\n\
    \                coordinate_t new_d = (ps[i] - memo[j]).abs();\n             \
    \   if (new_d < d) {\n                    d = new_d;\n                    p =\
    \ {ps[i], memo[j]};\n                }\n            }\n            memo[cur++]\
    \ = ps[i];\n        }\n        return {d, p};\n    };\n    return dfs(dfs, 0,\
    \ (int)ps.size());\n}\n// (\u8DDD\u96E2, \u70B9\u306E\u30DA\u30A2) \u3092\u8FD4\
    \u3059\nstd::pair<coordinate_t, std::pair<Point, Point>> farthest_pair(\n    std::vector<Point>\
    \ ps) {\n    ps = convex_hull(ps);\n    std::pair<coordinate_t, std::pair<Point,\
    \ Point>> ret = {\n        0, std::make_pair(ps[0], ps[0])};\n    int r = 0;\n\
    \    for (int l = 0; l < (int)ps.size(); l++) {\n        while (sgn((ps[l] - ps[r]).abs()\
    \ -\n                   (ps[l] - ps[(r + 1) % (int)ps.size()]).abs()) < 0) {\n\
    \            r++;\n            if (r == (int)ps.size()) r = 0;\n        }\n  \
    \      if (sgn(ret.first - (ps[l] - ps[r]).abs()) < 0) {\n            ret.first\
    \ = (ps[l] - ps[r]).abs();\n            ret.second = {ps[l], ps[r]};\n       \
    \ }\n    }\n    return ret;\n}\n\n// \u70B9a,\u70B9b\u304B\u3089\u306E\u8DDD\u96E2\
    \u306E\u6BD4\u304Cn:m\u306B\u306A\u308B\u70B9\u306E\u8ECC\u8DE1\nCircle circle_of_apollonius(Point\
    \ a, Point b, coordinate_t n, coordinate_t m) {\n    assert(sgn(n - m) != 0);\n\
    \    Point c = (a * (-m * m) + b * (n * n)) / (n * n - m * m);\n    coordinate_t\
    \ r = std::sqrt(dist(a, c) * dist(b, c));\n    return {c, r};\n}\n}  // namespace\
    \ geometry\n"
  code: "#pragma once\nnamespace geometry {\nusing coordinate_t = double;\nconst coordinate_t\
    \ PI = std::acos(-1);\nconst coordinate_t EPS = 1e-9;\nint sgn(coordinate_t a)\
    \ {\n    return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0;\n};\n\nstruct Point {\n \
    \   coordinate_t x, y;\n    Point() {\n    }\n    Point(coordinate_t _x, coordinate_t\
    \ _y) : x(_x), y(_y) {\n    }\n    Point operator+(const Point &rhs) const {\n\
    \        Point res(*this);\n        return res += rhs;\n    }\n    Point operator-(const\
    \ Point &rhs) const {\n        Point res(*this);\n        return res -= rhs;\n\
    \    }\n    Point operator*(const coordinate_t &rhs) const {\n        Point res(*this);\n\
    \        return res *= rhs;\n    }\n    Point operator/(const coordinate_t &rhs)\
    \ const {\n        Point res(*this);\n        return res /= rhs;\n    }\n    inline\
    \ bool operator<(const Point &b) {\n        if (sgn(x - b.x)) return sgn(x - b.x)\
    \ < 0;\n        return sgn(y - b.y) < 0;\n    }\n    Point operator+=(const Point\
    \ &rhs) {\n        x += rhs.x, y += rhs.y;\n        return *this;\n    }\n   \
    \ Point operator-=(const Point &rhs) {\n        x -= rhs.x, y -= rhs.y;\n    \
    \    return *this;\n    }\n    Point operator*=(const coordinate_t &rhs) {\n \
    \       x *= rhs, y *= rhs;\n        return *this;\n    }\n    Point operator/=(const\
    \ coordinate_t &rhs) {\n        x /= rhs, y /= rhs;\n        return *this;\n \
    \   }\n    coordinate_t abs() const {\n        return std::sqrt(x * x + y * y);\n\
    \    }\n    coordinate_t arg() const {\n        return std::atan2(y, x);\n   \
    \ }\n    Point normal() const {\n        return Point(-y, x);\n    }\n    Point\
    \ unit() const {\n        return *this / abs();\n    }\n};\ninline bool operator<(const\
    \ Point &a, const Point &b) {\n    if (sgn(a.x - b.x)) return sgn(a.x - b.x) <\
    \ 0;\n    return sgn(a.y - b.y) < 0;\n}\ninline bool operator==(const Point &a,\
    \ const Point &b) {\n    return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;\n\
    }\ninline bool operator>(const Point &a, const Point &b) {\n    if (sgn(a.x -\
    \ b.x)) return sgn(a.x - b.x) > 0;\n    return sgn(a.y - b.y) > 0;\n}\nstd::istream\
    \ &operator>>(std::istream &is, Point &p) {\n    coordinate_t x, y;\n    is >>\
    \ x >> y;\n    p = {x, y};\n    return is;\n}\nstd::ostream &operator<<(std::ostream\
    \ &os, const Point &p) {\n    return os << p.x << ' ' << p.y;\n}\nPoint rotate(const\
    \ Point &p, const coordinate_t &theta) {\n    Point ret;\n    ret.x = p.x * cos(theta)\
    \ - p.y * sin(theta);\n    ret.y = p.x * sin(theta) + p.y * cos(theta);\n    return\
    \ ret;\n}\ncoordinate_t dot(const Point &a, const Point &b) {\n    return a.x\
    \ * b.x + a.y * b.y;\n}\ncoordinate_t det(const Point &a, const Point &b) {\n\
    \    return a.x * b.y - a.y * b.x;\n}\n\nconst int COUNTER_CLOCKWISE = 1;\nconst\
    \ int CLOCKWISE = -1;\nconst int ONLINE_BACK = -2;\nconst int ONLINE_FRONT = 2;\n\
    const int ON_SEGMENT = 0;\nint ccw(Point a, Point b, Point c) {\n    if (sgn(det(b\
    \ - a, c - a)) > 0) {\n        return COUNTER_CLOCKWISE;  // counter clockwise\n\
    \    }\n    if (sgn(det(b - a, c - a)) < 0) {\n        return CLOCKWISE;  // clockwise\n\
    \    }\n    if (sgn(dot(b - a, c - a)) < 0) {\n        return ONLINE_BACK;  //\
    \ c - a - b\n    }\n    if (sgn(dot(a - b, c - b)) < 0) {\n        return ONLINE_FRONT;\
    \  // a - b - c\n    }\n    return ON_SEGMENT;  // a - c - b\n}\n\nstruct Line\
    \ {\n    Point a, b;\n    Line() {\n    }\n    Line(Point _a, Point _b) : a(_a),\
    \ b(_b) {\n    }\n    Point projection(const Point &p) const {\n        return\
    \ a +\n               (b - a) * (dot(b - a, p - a) / ((b - a).abs() * (b - a).abs()));\n\
    \    }\n    Point reflection(const Point &p) const {\n        return projection(p)\
    \ * 2 - p;\n    }\n};\nstd::istream &operator>>(std::istream &is, Line &l) {\n\
    \    Point a, b;\n    is >> a >> b;\n    l = {a, b};\n    return is;\n};\n\nstruct\
    \ Segment {\n    Point a, b;\n    Segment() {\n    }\n    Segment(Point _a, Point\
    \ _b) : a(_a), b(_b) {\n    }\n    Line vertical_bisector() {\n        Point c\
    \ = (a + b) / 2;\n        Point v = (a - b).normal();\n        return {c + v,\
    \ c - v};\n    }\n};\nstd::istream &operator>>(std::istream &is, Segment &s) {\n\
    \    Point a, b;\n    is >> a >> b;\n    s = {a, b};\n    return is;\n};\n\nLine\
    \ from_segment(const Segment &s) {\n    return Line(s.a, s.b);\n}\n\nstruct Polygon\
    \ : std::vector<Point> {\n    Polygon(int n = 0) : std::vector<Point>(n) {\n \
    \   }\n    coordinate_t area() const {\n        coordinate_t ret = 0;\n      \
    \  for (int i = 0; i < (int)size(); i++) {\n            ret += det((*this)[i],\
    \ (*this)[(i + 1) % (int)size()]);\n        }\n        ret /= 2.0;\n        ret\
    \ = std::fabs(ret);\n        return ret;\n    }\n    bool is_convex() const {\n\
    \        for (int i = 0; i < (int)size(); i++) {\n            if (ccw((*this)[i],\
    \ (*this)[(i + 1) % (int)size()],\n                    (*this)[(i + 2) % (int)size()])\
    \ == CLOCKWISE) {\n                return false;\n            }\n        }\n \
    \       return true;\n    }\n    coordinate_t diameter() const {\n        assert(is_convex());\n\
    \        coordinate_t ret = 0;\n        int r = 0;\n        for (int l = 0; l\
    \ < (int)size(); l++) {\n            while (sgn(((*this)[l] - (*this)[r]).abs()\
    \ -\n                       ((*this)[l] - (*this)[(r + 1) % (int)size()]).abs())\
    \ <\n                   0) {\n                r++;\n                if (r == (int)size())\
    \ r = 0;\n            }\n            ret = std::max(ret, ((*this)[l] - (*this)[r]).abs());\n\
    \        }\n        return ret;\n    }\n    int contain(const Point &p) const\
    \ {\n        bool is_in = false;\n        for (int i = 0; i < (int)size(); i++)\
    \ {\n            int ccw_ = ccw((*this)[i], (*this)[(i + 1) % (int)size()], p);\n\
    \            if (ccw_ == ON_SEGMENT) {\n                return 1;  // p is on\
    \ a segment of polygon\n            }\n            Point a = (*this)[i] - p, b\
    \ = (*this)[(i + 1) % (int)size()] - p;\n            if (b < a) std::swap(a, b);\n\
    \            if (sgn(a.x) <= 0 && sgn(b.x) > 0 && sgn(det(a, b)) < 0)\n      \
    \          is_in ^= true;\n        }\n        return is_in ? 2 /* polygon contains\
    \ p */ : 0;\n    }\n};\n\nstruct Circle {\n    Point c;\n    coordinate_t r;\n\
    \    Circle() {\n    }\n    Circle(Point _c, coordinate_t _r) : c(_c), r(_r) {\n\
    \        assert(sgn(r) >= 0);\n    }\n    coordinate_t area() const {\n      \
    \  return r * r * PI;\n    }\n    int contain(const Point &p) const {\n      \
    \  return sgn((c - p).abs() - r) > 0    ? 0\n               : sgn((c - p).abs()\
    \ - r) == 0 ? 1\n                                             : 2;\n    }\n};\n\
    \nbool intersect(const Segment &s1, const Segment &s2);\nbool intersect(const\
    \ Line &l1, const Line &l2);\nbool intersect(const Segment &s, const Line &l);\n\
    bool intersect(const Segment &s, const Circle &c);\nbool intersect(const Line\
    \ &s, const Circle &c);\n\nPoint cross_point(const Segment &s1, const Segment\
    \ &s2);\nPoint cross_point(const Line &l1, const Line &l2);\nPoint cross_point(const\
    \ Segment &s, const Line &l);\nstd::vector<Point> cross_points(const Segment &s,\
    \ const Circle &c);\nstd::vector<Point> cross_points(const Line &l, const Circle\
    \ &c);\n\ncoordinate_t dist(const Point &p1, const Point &p2) {\n    return (p1\
    \ - p2).abs();\n}\ncoordinate_t dist(const Segment &s, const Point &p) {\n   \
    \ if (sgn(dot(s.b - s.a, p - s.a)) < 0) {\n        return (p - s.a).abs();\n \
    \   }\n    if (sgn(dot(s.a - s.b, p - s.b)) < 0) {\n        return (p - s.b).abs();\n\
    \    }\n    return std::fabs(det(p - s.a, s.b - s.a)) / (s.b - s.a).abs();\n}\n\
    coordinate_t dist(const Point &p, const Segment &s) {\n    return dist(s, p);\n\
    }\ncoordinate_t dist(const Segment &s1, const Segment &s2) {\n    if (intersect(s1,\
    \ s2)) return 0;\n    return std::min(\n        {dist(s1, s2.a), dist(s1, s2.b),\
    \ dist(s2, s1.a), dist(s2, s1.b)});\n}\ncoordinate_t dist(const Line &l, const\
    \ Point &p) {\n    return std::fabs(det(p - l.a, l.b - l.a)) / (l.b - l.a).abs();\n\
    }\ncoordinate_t dist(const Point &p, const Line &l) {\n    return dist(l, p);\n\
    }\ncoordinate_t dist(const Line &l1, const Line &l2) {\n    if (intersect(l1,\
    \ l2)) return 0;\n    return dist(l1.a, l2);\n}\ncoordinate_t dist(const Segment\
    \ &s, const Line &l) {\n    if (intersect(s, l)) return 0;\n    return std::min(dist(s.a,\
    \ l), dist(s.b, l));\n}\ncoordinate_t dist(const Line &l, const Segment &s) {\n\
    \    return dist(s, l);\n}\n\nbool intersect(const Segment &s1, const Segment\
    \ &s2) {\n    return sgn(ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b)) <= 0 &&\n\
    \           sgn(ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b)) <= 0;\n}\nbool\
    \ intersect(const Line &l1, const Line &l2) {\n    return sgn(det(l1.b - l1.a,\
    \ l2.b - l2.a)) != 0;\n}\nbool intersect(const Segment &s, const Line &l) {\n\
    \    return ccw(l.a, l.b, s.a) * ccw(l.a, l.b, s.b) == -1;\n}\nbool intersect(const\
    \ Line &l, const Segment &s) {\n    return intersect(s, l);\n}\nbool intersect(const\
    \ Segment &s, const Circle &c) {\n    if (sgn(dist(s, c.c) - c.r) > 0) return\
    \ false;\n    return !(sgn((c.c - s.a).abs() - c.r) < 0 &&\n             sgn((c.c\
    \ - s.b).abs() - c.r) < 0);\n}\nbool intersect(const Circle &c, const Segment\
    \ &s) {\n    return intersect(s, c);\n}\nbool intersect(const Line &l, const Circle\
    \ &c) {\n    return sgn(dist(l, c.c) - c.r) <= 0;\n}\nbool intersect(const Circle\
    \ &c, const Line &l) {\n    return intersect(l, c);\n}\nbool intersect(Circle\
    \ c1, Circle c2) {\n    return sgn((c1.c - c2.c).abs() - (c1.r + c2.r)) <= 0 &&\n\
    \           sgn((c1.c - c2.c).abs() - std::fabs(c1.r - c2.r)) >= 0;\n}\n\nPoint\
    \ cross_point(const Segment &s1, const Segment &s2) {\n    assert(intersect(s1,\
    \ s2));\n    return cross_point(from_segment(s1), from_segment(s2));\n}\nPoint\
    \ cross_point(const Segment &s, const Line &l) {\n    assert(intersect(s, l));\n\
    \    return s.a + (s.b - s.a) *\n                     (det(l.a - s.a, l.b - l.a)\
    \ / det(s.b - s.a, l.b - l.a));\n}\nPoint cross_point(const Line &l, const Segment\
    \ &s) {\n    return cross_point(s, l);\n}\nPoint cross_point(const Line &l1, const\
    \ Line &l2) {\n    assert(intersect(l1, l2));\n    return l1.a + (l1.b - l1.a)\
    \ * (det(l2.a - l1.a, l2.b - l2.a) /\n                                   det(l1.b\
    \ - l1.a, l2.b - l2.a));\n}\nstd::vector<Point> cross_points(const Segment &s,\
    \ const Circle &c) {\n    if (!intersect(s, c)) return {};\n    std::vector<Point>\
    \ ret = cross_points(from_segment(s), c);\n    ret.erase(std::remove_if(ret.begin(),\
    \ ret.end(),\n                             [&](Point p) {\n                  \
    \               return !(p == s.a) && !(p == s.b) &&\n                       \
    \                 (p < s.a) == (p < s.b);\n                             }),\n\
    \              ret.end());\n    return ret;\n}\nstd::vector<Point> cross_points(const\
    \ Circle &c, const Segment &s) {\n    return cross_points(s, c);\n}\nstd::vector<Point>\
    \ cross_points(const Line &l, const Circle &c) {\n    if (!intersect(l, c)) return\
    \ {};\n    Point p = l.projection(c.c);\n    Point v = (l.b - l.a) *\n       \
    \       std::sqrt(c.r * c.r - (p - c.c).abs() * (p - c.c).abs()) /\n         \
    \     (l.b - l.a).abs();\n    v = std::max(v, v * -1);\n    return {p - v, p +\
    \ v};\n}\nstd::vector<Point> cross_points(const Circle &c, const Line &l) {\n\
    \    return cross_points(l, c);\n}\nstd::vector<Point> cross_points(Circle c1,\
    \ Circle c2) {\n    if (!intersect(c1, c2)) return {};\n    coordinate_t d = (c1.c\
    \ - c2.c).abs();\n    coordinate_t d1 = (d + (c1.r * c1.r - c2.r * c2.r) / d)\
    \ / 2;\n    coordinate_t h = std::sqrt(c1.r * c1.r - d1 * d1);\n    Point v =\
    \ (c2.c - c1.c).normal();\n    v *= h / v.abs();\n    std::vector<Point> ret =\
    \ {c1.c + (c2.c - c1.c) * (d1 / d) + v,\n                              c1.c +\
    \ (c2.c - c1.c) * (d1 / d) - v};\n    if (ret[0] > ret[1]) std::swap(ret[0], ret[1]);\n\
    \    return ret;\n}\n\n// \u4E09\u89D2\u5F62\u306E\u5185\u63A5\u5186\nCircle incircle_of_triangle(const\
    \ Point &pa, const Point &pb, const Point &pc) {\n    coordinate_t a = (pb - pc).abs(),\
    \ b = (pc - pa).abs(), c = (pa - pb).abs();\n    Point p = (pa * a + pb * b +\
    \ pc * c) / (a + b + c);\n    coordinate_t r = dist(Line(pa, pb), p);\n    return\
    \ Circle(p, r);\n}\n// \u4E09\u89D2\u5F62\u306E\u5185\u63A5\u5186\nCircle incircle_of_triangle(const\
    \ Polygon &poly) {\n    assert((int)poly.size() == 3);\n    const Point &pa =\
    \ poly[0], &pb = poly[1], &pc = poly[2];\n    return incircle_of_triangle(pa,\
    \ pb, pc);\n}\n// \u4E09\u89D2\u5F62\u306E\u5916\u63A5\u5186\nCircle circumscribed_circle_of_triangle(const\
    \ Point &pa, const Point &pb,\n                                        const Point\
    \ &pc) {\n    Line l1 = Segment(pa, pb).vertical_bisector();\n    Line l2 = Segment(pa,\
    \ pc).vertical_bisector();\n    Point p = cross_point(l1, l2);\n    coordinate_t\
    \ r = (pa - p).abs();\n    return Circle(p, r);\n}\n// \u4E09\u89D2\u5F62\u306E\
    \u5916\u63A5\u5186\nCircle circumscribed_circle_of_triangle(const Polygon &poly)\
    \ {\n    assert((int)poly.size() == 3);\n    const Point &pa = poly[0], &pb =\
    \ poly[1], &pc = poly[2];\n    return circumscribed_circle_of_triangle(pa, pb,\
    \ pc);\n}\n\n// \u51F8\u5305\nPolygon convex_hull(std::vector<Point> ps) {\n \
    \   int n = int(ps.size());\n    std::sort(ps.begin(), ps.end());\n    Polygon\
    \ ret(2 * n);\n    int k = 0;\n    for (int i = 0; i < n; ret[k++] = ps[i++])\
    \ {\n        while (k >= 2 &&\n               sgn(det(ret[k - 1] - ret[k - 2],\
    \ ps[i] - ret[k - 2])) < 0) {\n            k--;\n        }\n    }\n    for (int\
    \ i = n - 2, t = k + 1; i >= 0; ret[k++] = ps[i--]) {\n        while (k >= t &&\n\
    \               sgn(det(ret[k - 1] - ret[k - 2], ps[i] - ret[k - 2])) < 0) {\n\
    \            k--;\n        }\n    }\n    ret.resize(k - 1);\n    return ret;\n\
    }\n// \u6700\u5C0F\u5305\u542B\u5186\nCircle smallest_enclosing_circle(std::vector<Point>\
    \ ps) {\n    assert((int)ps.size() >= 2);\n    std::random_device seed_gen;\n\
    \    std::mt19937_64 rnd(seed_gen());\n    std::shuffle(ps.begin(), ps.end(),\
    \ rnd);\n    Circle ret((ps[0] + ps[1]) / 2, (ps[0] - ps[1]).abs() / 2);\n   \
    \ for (int i = 2; i < (int)ps.size(); i++) {\n        if (ret.contain(ps[i]))\
    \ continue;\n        ret = Circle((ps[0] + ps[i]) / 2, (ps[0] - ps[i]).abs() /\
    \ 2);\n        for (int j = 1; j < i; j++) {\n            if (ret.contain(ps[j]))\
    \ continue;\n            ret = Circle((ps[i] + ps[j]) / 2, (ps[i] - ps[j]).abs()\
    \ / 2);\n            for (int k = 0; k < j; k++) {\n                if (ret.contain(ps[k]))\
    \ continue;\n                ret = circumscribed_circle_of_triangle(ps[i], ps[j],\
    \ ps[k]);\n            }\n        }\n    }\n    return ret;\n}\n\n// \u5186c\u3068\
    \u591A\u89D2\u5F62p\u306E\u5171\u901A\u90E8\u5206\u306E\u9762\u7A4D\u3092\u8FD4\
    \u3059\u3002\ncoordinate_t area_of_intersection(Circle c, Polygon p) {\n    auto\
    \ signed_area_of_triangle = [](Point a, Point b) -> coordinate_t {\n        return\
    \ det(a, b);\n    };\n    auto signed_area_of_sector = [&c](Point a, Point b)\
    \ -> coordinate_t {\n        return c.r * c.r * (rotate(b, -a.arg()).arg());\n\
    \    };\n    auto is_in_circle = [&c](Point a) -> bool {\n        return sgn(a.abs()\
    \ - c.r) < 0;\n    };\n    coordinate_t ret = 0;\n    for (int i = 0; i < int(p.size());\
    \ i++) p[i] -= c.c;\n    for (int i = 0; i < int(p.size()); i++) {\n        const\
    \ Point &a = p[i], &b = p[(i + 1) % int(p.size())];\n        if (!intersect(Segment(a,\
    \ b), c)) {\n            ret += is_in_circle(a) ? signed_area_of_triangle(a, b)\n\
    \                                   : signed_area_of_sector(a, b);\n        }\
    \ else {\n            std::vector<Point> ps = cross_points(Segment(a, b), c);\n\
    \            Point s = ps[0], t = ps[1 % int(ps.size())];\n            if ((a\
    \ < b) != (s < t)) std::swap(s, t);\n            ret += is_in_circle(a) ? signed_area_of_triangle(a,\
    \ s)\n                                   : signed_area_of_sector(a, s);\n    \
    \        ret += signed_area_of_triangle(s, t);\n            ret += is_in_circle(b)\
    \ ? signed_area_of_triangle(t, b)\n                                   : signed_area_of_sector(t,\
    \ b);\n        }\n    }\n    ret = std::fabs(ret);\n    ret /= 2;\n    return\
    \ ret;\n}\n// \u5186c\u3068\u591A\u89D2\u5F62p\u306E\u5171\u901A\u90E8\u5206\u306E\
    \u9762\u7A4D\u3092\u8FD4\u3059\u3002\ncoordinate_t area_of_intersection(Polygon\
    \ p, Circle c) {\n    return area_of_intersection(c, p);\n}\n\n// \u5186c1\u3068\
    \u5186c2\u306E\u5171\u901A\u90E8\u5206\u306E\u9762\u7A4D\u3092\u8FD4\u3059\u3002\
    \ncoordinate_t area_of_intersection(const Circle &c1, const Circle &c2) {\n  \
    \  if (sgn(c1.r + c2.r - (c1.c - c2.c).abs()) <= 0) {\n        return 0;\n   \
    \ }\n    if (sgn(std::fabs(c1.r - c2.r) - (c1.c - c2.c).abs()) >= 0) {\n     \
    \   return std::min(c1.area(), c2.area());\n    }\n    auto unsigned_area_of_triangle\
    \ = [](Circle c1, Circle c2,\n                                        Point p)\
    \ -> coordinate_t {\n        return std::fabs(det(c2.c - c1.c, p - c1.c));\n \
    \   };\n    auto unsigned_area_of_sector = [](Circle c1, Circle c2,\n        \
    \                              Point p) -> coordinate_t {\n        return std::fabs(c1.r\
    \ * c1.r *\n                         rotate(c2.c - c1.c, -(p - c1.c).arg()).arg());\n\
    \    };\n    Point p = cross_points(c1, c2)[0];\n    coordinate_t ret = 0;\n \
    \   ret += unsigned_area_of_sector(c1, c2, p);\n    ret += unsigned_area_of_sector(c2,\
    \ c1, p);\n    ret -= unsigned_area_of_triangle(c1, c2, p);\n    return ret;\n\
    }\n\n// \u51F8\u591A\u89D2\u5F62poly\u3092\u76F4\u7DDAl\u3067\u5207\u65AD\u3057\
    \u305F\u3068\u304D\u306B\u3001\u305D\u306E\u5DE6\u5074\u306B\u3067\u304D\u308B\
    \u51F8\u591A\u89D2\u5F62\u3002\nPolygon convex_cut_left(const Polygon &poly, const\
    \ Line &l) {\n    assert(poly.is_convex());\n    Polygon ret;\n    for (int i\
    \ = 0; i < (int)poly.size(); i++) {\n        if (ccw(l.a, l.b, poly[i]) != CLOCKWISE)\
    \ {\n            ret.push_back(poly[i]);\n        }\n        Segment s(poly[i],\
    \ poly[(i + 1) % (int)poly.size()]);\n        if (intersect(s, l)) {\n       \
    \     ret.push_back(cross_point(s, l));\n        }\n    }\n    return ret;\n}\n\
    // \u51F8\u591A\u89D2\u5F62poly\u3092\u76F4\u7DDAl\u3067\u5207\u65AD\u3057\u305F\
    \u3068\u304D\u306B\u3001\u305D\u306E\u53F3\u5074\u306B\u3067\u304D\u308B\u51F8\
    \u591A\u89D2\u5F62\u3002\nPolygon convex_cut_right(const Polygon &poly, const\
    \ Line &l) {\n    assert(poly.is_convex());\n    Polygon ret;\n    for (int i\
    \ = 0; i < (int)poly.size(); i++) {\n        if (ccw(l.a, l.b, poly[i]) != COUNTER_CLOCKWISE)\
    \ {\n            ret.push_back(poly[i]);\n        }\n        Segment s(poly[i],\
    \ poly[(i + 1) % (int)poly.size()]);\n        if (intersect(s, l)) {\n       \
    \     ret.push_back(cross_point(s, l));\n        }\n    }\n    return ret;\n}\n\
    \n// \u70B9p\u3092\u901A\u308B\u5186c\u306E\u63A5\u7DDA\u3002\u63A5\u70B9\u3092\
    \u8FD4\u3059\u3002\nstd::vector<Point> tangent_points(const Circle &c, const Point\
    \ &p) {\n    assert(sgn((p - c.c).abs() - c.r) >= 0);\n    coordinate_t r = std::sqrt((c.c\
    \ - p).abs() * (c.c - p).abs() - c.r * c.r);\n    return cross_points(c, Circle(p,\
    \ r));\n}\n\n// \u5186c1\u3068\u5186c2\u306E\u5171\u901A\u63A5\u7DDA\u306E\u672C\
    \u6570\u3002\nint count_common_tangent(const Circle &c1, const Circle &c2) {\n\
    \    if (sgn((c1.c - c2.c).abs() - (c1.r + c2.r)) > 0) {\n        return 4;  //\
    \ do not cross\n    }\n    if (sgn((c1.c - c2.c).abs() - (c1.r + c2.r)) == 0)\
    \ {\n        return 3;  // circumscribed\n    }\n    if (sgn((c1.c - c2.c).abs()\
    \ - std::fabs(c1.r - c2.r)) > 0) {\n        return 2;  // intersects\n    }\n\
    \    if (sgn((c1.c - c2.c).abs() - std::fabs(c1.r - c2.r)) == 0) {\n        return\
    \ 1;  // inscribed\n    }\n    return 0;\n}\n\n// \u5186c1\u3068\u5186c2\u306E\
    \u5171\u901A\u63A5\u7DDA\u3002\u5186c1\u306B\u304A\u3051\u308B\u63A5\u70B9\u3092\
    \u8FD4\u3059\u3002\nstd::vector<Point> common_tangents(const Circle &c1, const\
    \ Circle &c2) {\n    std::vector<Point> ret, ret1, ret2;\n    if (sgn((c1.c -\
    \ c2.c).abs() - std::fabs(c1.r - c2.r)) >= 0) {\n        coordinate_t d = (c1.c\
    \ - c2.c).abs();\n        coordinate_t r =\n            std::sqrt(d * d - (c1.r\
    \ - c2.r) * (c1.r - c2.r) + c2.r * c2.r);\n        ret1 = cross_points(c1, Circle(c2.c,\
    \ r));\n    }\n    if (sgn((c1.c - c2.c).abs() - (c1.r + c2.r)) >= 0) {\n    \
    \    Point p = c1.c + (c2.c - c1.c) * c1.r / (c1.r + c2.r);\n        ret2 = tangent_points(c1,\
    \ p);\n    }\n    std::merge(ret1.begin(), ret1.end(), ret2.begin(), ret2.end(),\n\
    \               std::back_inserter(ret));\n    ret.erase(std::unique(ret.begin(),\
    \ ret.end()), ret.end());\n    return ret;\n}\n// (\u8DDD\u96E2, \u70B9\u306E\u30DA\
    \u30A2) \u3092\u8FD4\u3059\nstd::pair<coordinate_t, std::pair<Point, Point>> closest_pair(\n\
    \    std::vector<Point> ps) {\n    std::sort(ps.begin(), ps.end(),\n         \
    \     [](Point a, Point b) { return sgn(a.x - b.x) < 0; });\n    std::vector<Point>\
    \ memo(ps.size());\n    auto dfs = [&](auto dfs, int l,\n                   int\
    \ r) -> std::pair<coordinate_t, std::pair<Point, Point>> {\n        if (r - l\
    \ < 2) return {1e18, {Point(), Point()}};\n        int m = (r + l) / 2;\n    \
    \    coordinate_t x = ps[m].x;\n        auto l_res = dfs(dfs, l, m), r_res = dfs(dfs,\
    \ m, r);\n        auto [d, p] = (l_res.first < r_res.first ? l_res : r_res);\n\
    \        std::inplace_merge(ps.begin() + l, ps.begin() + m, ps.begin() + r,\n\
    \                           [](Point a, Point b) { return sgn(a.y - b.y) < 0;\
    \ });\n\n        int cur = 0;\n        for (int i = l; i < r; i++) {\n       \
    \     if (std::fabs(ps[i].x - x) >= d) continue;\n            for (int j = cur\
    \ - 1; j >= 0; j--) {\n                if (ps[i].y - memo[j].y >= d) break;\n\
    \                coordinate_t new_d = (ps[i] - memo[j]).abs();\n             \
    \   if (new_d < d) {\n                    d = new_d;\n                    p =\
    \ {ps[i], memo[j]};\n                }\n            }\n            memo[cur++]\
    \ = ps[i];\n        }\n        return {d, p};\n    };\n    return dfs(dfs, 0,\
    \ (int)ps.size());\n}\n// (\u8DDD\u96E2, \u70B9\u306E\u30DA\u30A2) \u3092\u8FD4\
    \u3059\nstd::pair<coordinate_t, std::pair<Point, Point>> farthest_pair(\n    std::vector<Point>\
    \ ps) {\n    ps = convex_hull(ps);\n    std::pair<coordinate_t, std::pair<Point,\
    \ Point>> ret = {\n        0, std::make_pair(ps[0], ps[0])};\n    int r = 0;\n\
    \    for (int l = 0; l < (int)ps.size(); l++) {\n        while (sgn((ps[l] - ps[r]).abs()\
    \ -\n                   (ps[l] - ps[(r + 1) % (int)ps.size()]).abs()) < 0) {\n\
    \            r++;\n            if (r == (int)ps.size()) r = 0;\n        }\n  \
    \      if (sgn(ret.first - (ps[l] - ps[r]).abs()) < 0) {\n            ret.first\
    \ = (ps[l] - ps[r]).abs();\n            ret.second = {ps[l], ps[r]};\n       \
    \ }\n    }\n    return ret;\n}\n\n// \u70B9a,\u70B9b\u304B\u3089\u306E\u8DDD\u96E2\
    \u306E\u6BD4\u304Cn:m\u306B\u306A\u308B\u70B9\u306E\u8ECC\u8DE1\nCircle circle_of_apollonius(Point\
    \ a, Point b, coordinate_t n, coordinate_t m) {\n    assert(sgn(n - m) != 0);\n\
    \    Point c = (a * (-m * m) + b * (n * n)) / (n * n - m * m);\n    coordinate_t\
    \ r = std::sqrt(dist(a, c) * dist(b, c));\n    return {c, r};\n}\n}  // namespace\
    \ geometry"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry.hpp
  requiredBy: []
  timestamp: '2022-09-01 22:39:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_3_B.test.cpp
  - test/aoj/CGL_7_B.test.cpp
  - test/aoj/CGL_1_A.test.cpp
  - test/aoj/CGL_5_A.test.cpp
  - test/aoj/CGL_7_G.test.cpp
  - test/aoj/CGL_7_F.test.cpp
  - test/aoj/CGL_2_B.test.cpp
  - test/aoj/CGL_2_D.test.cpp
  - test/aoj/CGL_4_B.test.cpp
  - test/aoj/CGL_7_D.test.cpp
  - test/aoj/CGL_1_B.test.cpp
  - test/aoj/CGL_7_H.test.cpp
  - test/aoj/CGL_3_A.test.cpp
  - test/aoj/CGL_2_C.test.cpp
  - test/aoj/CGL_3_C.test.cpp
  - test/aoj/CGL_7_E.test.cpp
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/CGL_2_A.test.cpp
  - test/aoj/CGL_4_C.test.cpp
  - test/aoj/CGL_7_A.test.cpp
  - test/aoj/CGL_4_A.test.cpp
  - test/aoj/CGL_7_I.test.cpp
  - test/aoj/CGL_1_C.test.cpp
documentation_of: geometry/geometry.hpp
layout: document
title: geomerty
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