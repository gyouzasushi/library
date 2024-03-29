#pragma once
namespace geometry {
using coordinate_t = double;
const coordinate_t PI = std::acos(-1);
const coordinate_t EPS = 1e-9;
int sgn(coordinate_t a) {
    return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0;
};

struct Point {
    coordinate_t x, y;
    Point() {
    }
    Point(coordinate_t _x, coordinate_t _y) : x(_x), y(_y) {
    }
    Point operator+(const Point &rhs) const {
        Point res(*this);
        return res += rhs;
    }
    Point operator-(const Point &rhs) const {
        Point res(*this);
        return res -= rhs;
    }
    Point operator*(const coordinate_t &rhs) const {
        Point res(*this);
        return res *= rhs;
    }
    Point operator/(const coordinate_t &rhs) const {
        Point res(*this);
        return res /= rhs;
    }
    inline bool operator<(const Point &b) {
        if (sgn(x - b.x)) return sgn(x - b.x) < 0;
        return sgn(y - b.y) < 0;
    }
    Point operator+=(const Point &rhs) {
        x += rhs.x, y += rhs.y;
        return *this;
    }
    Point operator-=(const Point &rhs) {
        x -= rhs.x, y -= rhs.y;
        return *this;
    }
    Point operator*=(const coordinate_t &rhs) {
        x *= rhs, y *= rhs;
        return *this;
    }
    Point operator/=(const coordinate_t &rhs) {
        x /= rhs, y /= rhs;
        return *this;
    }
    coordinate_t abs() const {
        return std::sqrt(x * x + y * y);
    }
    coordinate_t arg() const {
        return std::atan2(y, x);
    }
    Point normal() const {
        return Point(-y, x);
    }
    Point unit() const {
        return *this / abs();
    }
};
inline bool operator<(const Point &a, const Point &b) {
    if (sgn(a.x - b.x)) return sgn(a.x - b.x) < 0;
    return sgn(a.y - b.y) < 0;
}
inline bool operator==(const Point &a, const Point &b) {
    return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;
}
inline bool operator>(const Point &a, const Point &b) {
    if (sgn(a.x - b.x)) return sgn(a.x - b.x) > 0;
    return sgn(a.y - b.y) > 0;
}
std::istream &operator>>(std::istream &is, Point &p) {
    coordinate_t x, y;
    is >> x >> y;
    p = {x, y};
    return is;
}
std::ostream &operator<<(std::ostream &os, const Point &p) {
    return os << p.x << ' ' << p.y;
}
Point rotate(const Point &p, const coordinate_t &theta) {
    Point ret;
    ret.x = p.x * cos(theta) - p.y * sin(theta);
    ret.y = p.x * sin(theta) + p.y * cos(theta);
    return ret;
}
coordinate_t dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
coordinate_t det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

const int COUNTER_CLOCKWISE = 1;
const int CLOCKWISE = -1;
const int ONLINE_BACK = -2;
const int ONLINE_FRONT = 2;
const int ON_SEGMENT = 0;
int ccw(Point a, Point b, Point c) {
    if (sgn(det(b - a, c - a)) > 0) {
        return COUNTER_CLOCKWISE;  // counter clockwise
    }
    if (sgn(det(b - a, c - a)) < 0) {
        return CLOCKWISE;  // clockwise
    }
    if (sgn(dot(b - a, c - a)) < 0) {
        return ONLINE_BACK;  // c - a - b
    }
    if (sgn(dot(a - b, c - b)) < 0) {
        return ONLINE_FRONT;  // a - b - c
    }
    return ON_SEGMENT;  // a - c - b
}

struct Line {
    Point a, b;
    Line() {
    }
    Line(Point _a, Point _b) : a(_a), b(_b) {
    }
    Point projection(const Point &p) const {
        return a +
               (b - a) * (dot(b - a, p - a) / ((b - a).abs() * (b - a).abs()));
    }
    Point reflection(const Point &p) const {
        return projection(p) * 2 - p;
    }
};
std::istream &operator>>(std::istream &is, Line &l) {
    Point a, b;
    is >> a >> b;
    l = {a, b};
    return is;
};

struct Segment {
    Point a, b;
    Segment() {
    }
    Segment(Point _a, Point _b) : a(_a), b(_b) {
    }
    Line vertical_bisector() {
        Point c = (a + b) / 2;
        Point v = (a - b).normal();
        return {c + v, c - v};
    }
};
std::istream &operator>>(std::istream &is, Segment &s) {
    Point a, b;
    is >> a >> b;
    s = {a, b};
    return is;
};

Line from_segment(const Segment &s) {
    return Line(s.a, s.b);
}

struct Polygon : std::vector<Point> {
    Polygon(int n = 0) : std::vector<Point>(n) {
    }
    coordinate_t area() const {
        coordinate_t ret = 0;
        for (int i = 0; i < (int)size(); i++) {
            ret += det((*this)[i], (*this)[(i + 1) % (int)size()]);
        }
        ret /= 2.0;
        ret = std::fabs(ret);
        return ret;
    }
    bool is_convex() const {
        for (int i = 0; i < (int)size(); i++) {
            if (ccw((*this)[i], (*this)[(i + 1) % (int)size()],
                    (*this)[(i + 2) % (int)size()]) == CLOCKWISE) {
                return false;
            }
        }
        return true;
    }
    coordinate_t diameter() const {
        assert(is_convex());
        coordinate_t ret = 0;
        int r = 0;
        for (int l = 0; l < (int)size(); l++) {
            while (sgn(((*this)[l] - (*this)[r]).abs() -
                       ((*this)[l] - (*this)[(r + 1) % (int)size()]).abs()) <
                   0) {
                r++;
                if (r == (int)size()) r = 0;
            }
            ret = std::max(ret, ((*this)[l] - (*this)[r]).abs());
        }
        return ret;
    }
    int contain(const Point &p) const {
        bool is_in = false;
        for (int i = 0; i < (int)size(); i++) {
            int ccw_ = ccw((*this)[i], (*this)[(i + 1) % (int)size()], p);
            if (ccw_ == ON_SEGMENT) {
                return 1;  // p is on a segment of polygon
            }
            Point a = (*this)[i] - p, b = (*this)[(i + 1) % (int)size()] - p;
            if (b < a) std::swap(a, b);
            if (sgn(a.x) <= 0 && sgn(b.x) > 0 && sgn(det(a, b)) < 0)
                is_in ^= true;
        }
        return is_in ? 2 /* polygon contains p */ : 0;
    }
};

struct Circle {
    Point c;
    coordinate_t r;
    Circle() {
    }
    Circle(Point _c, coordinate_t _r) : c(_c), r(_r) {
        assert(sgn(r) >= 0);
    }
    coordinate_t area() const {
        return r * r * PI;
    }
    int contain(const Point &p) const {
        return sgn((c - p).abs() - r) > 0    ? 0
               : sgn((c - p).abs() - r) == 0 ? 1
                                             : 2;
    }
};

bool intersect(const Segment &s1, const Segment &s2);
bool intersect(const Line &l1, const Line &l2);
bool intersect(const Segment &s, const Line &l);
bool intersect(const Segment &s, const Circle &c);
bool intersect(const Line &s, const Circle &c);

Point cross_point(const Segment &s1, const Segment &s2);
Point cross_point(const Line &l1, const Line &l2);
Point cross_point(const Segment &s, const Line &l);
std::vector<Point> cross_points(const Segment &s, const Circle &c);
std::vector<Point> cross_points(const Line &l, const Circle &c);

coordinate_t dist(const Point &p1, const Point &p2) {
    return (p1 - p2).abs();
}
coordinate_t dist(const Segment &s, const Point &p) {
    if (sgn(dot(s.b - s.a, p - s.a)) < 0) {
        return (p - s.a).abs();
    }
    if (sgn(dot(s.a - s.b, p - s.b)) < 0) {
        return (p - s.b).abs();
    }
    return std::fabs(det(p - s.a, s.b - s.a)) / (s.b - s.a).abs();
}
coordinate_t dist(const Point &p, const Segment &s) {
    return dist(s, p);
}
coordinate_t dist(const Segment &s1, const Segment &s2) {
    if (intersect(s1, s2)) return 0;
    return std::min(
        {dist(s1, s2.a), dist(s1, s2.b), dist(s2, s1.a), dist(s2, s1.b)});
}
coordinate_t dist(const Line &l, const Point &p) {
    return std::fabs(det(p - l.a, l.b - l.a)) / (l.b - l.a).abs();
}
coordinate_t dist(const Point &p, const Line &l) {
    return dist(l, p);
}
coordinate_t dist(const Line &l1, const Line &l2) {
    if (intersect(l1, l2)) return 0;
    return dist(l1.a, l2);
}
coordinate_t dist(const Segment &s, const Line &l) {
    if (intersect(s, l)) return 0;
    return std::min(dist(s.a, l), dist(s.b, l));
}
coordinate_t dist(const Line &l, const Segment &s) {
    return dist(s, l);
}

bool intersect(const Segment &s1, const Segment &s2) {
    return sgn(ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b)) <= 0 &&
           sgn(ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b)) <= 0;
}
bool intersect(const Line &l1, const Line &l2) {
    return sgn(det(l1.b - l1.a, l2.b - l2.a)) != 0;
}
bool intersect(const Segment &s, const Line &l) {
    return ccw(l.a, l.b, s.a) * ccw(l.a, l.b, s.b) == -1;
}
bool intersect(const Line &l, const Segment &s) {
    return intersect(s, l);
}
bool intersect(const Segment &s, const Circle &c) {
    if (sgn(dist(s, c.c) - c.r) > 0) return false;
    return !(sgn((c.c - s.a).abs() - c.r) < 0 &&
             sgn((c.c - s.b).abs() - c.r) < 0);
}
bool intersect(const Circle &c, const Segment &s) {
    return intersect(s, c);
}
bool intersect(const Line &l, const Circle &c) {
    return sgn(dist(l, c.c) - c.r) <= 0;
}
bool intersect(const Circle &c, const Line &l) {
    return intersect(l, c);
}
bool intersect(Circle c1, Circle c2) {
    return sgn((c1.c - c2.c).abs() - (c1.r + c2.r)) <= 0 &&
           sgn((c1.c - c2.c).abs() - std::fabs(c1.r - c2.r)) >= 0;
}

Point cross_point(const Segment &s1, const Segment &s2) {
    assert(intersect(s1, s2));
    return cross_point(from_segment(s1), from_segment(s2));
}
Point cross_point(const Segment &s, const Line &l) {
    assert(intersect(s, l));
    return s.a + (s.b - s.a) *
                     (det(l.a - s.a, l.b - l.a) / det(s.b - s.a, l.b - l.a));
}
Point cross_point(const Line &l, const Segment &s) {
    return cross_point(s, l);
}
Point cross_point(const Line &l1, const Line &l2) {
    assert(intersect(l1, l2));
    return l1.a + (l1.b - l1.a) * (det(l2.a - l1.a, l2.b - l2.a) /
                                   det(l1.b - l1.a, l2.b - l2.a));
}
std::vector<Point> cross_points(const Segment &s, const Circle &c) {
    if (!intersect(s, c)) return {};
    std::vector<Point> ret = cross_points(from_segment(s), c);
    ret.erase(std::remove_if(ret.begin(), ret.end(),
                             [&](Point p) {
                                 return !(p == s.a) && !(p == s.b) &&
                                        (p < s.a) == (p < s.b);
                             }),
              ret.end());
    return ret;
}
std::vector<Point> cross_points(const Circle &c, const Segment &s) {
    return cross_points(s, c);
}
std::vector<Point> cross_points(const Line &l, const Circle &c) {
    if (!intersect(l, c)) return {};
    Point p = l.projection(c.c);
    Point v = (l.b - l.a) *
              std::sqrt(c.r * c.r - (p - c.c).abs() * (p - c.c).abs()) /
              (l.b - l.a).abs();
    v = std::max(v, v * -1);
    return {p - v, p + v};
}
std::vector<Point> cross_points(const Circle &c, const Line &l) {
    return cross_points(l, c);
}
std::vector<Point> cross_points(Circle c1, Circle c2) {
    if (!intersect(c1, c2)) return {};
    coordinate_t d = (c1.c - c2.c).abs();
    coordinate_t d1 = (d + (c1.r * c1.r - c2.r * c2.r) / d) / 2;
    coordinate_t h = std::sqrt(c1.r * c1.r - d1 * d1);
    Point v = (c2.c - c1.c).normal();
    v *= h / v.abs();
    std::vector<Point> ret = {c1.c + (c2.c - c1.c) * (d1 / d) + v,
                              c1.c + (c2.c - c1.c) * (d1 / d) - v};
    if (ret[0] > ret[1]) std::swap(ret[0], ret[1]);
    return ret;
}

// 三角形の内接円
Circle incircle_of_triangle(const Point &pa, const Point &pb, const Point &pc) {
    coordinate_t a = (pb - pc).abs(), b = (pc - pa).abs(), c = (pa - pb).abs();
    Point p = (pa * a + pb * b + pc * c) / (a + b + c);
    coordinate_t r = dist(Line(pa, pb), p);
    return Circle(p, r);
}
// 三角形の内接円
Circle incircle_of_triangle(const Polygon &poly) {
    assert((int)poly.size() == 3);
    const Point &pa = poly[0], &pb = poly[1], &pc = poly[2];
    return incircle_of_triangle(pa, pb, pc);
}
// 三角形の外接円
Circle circumscribed_circle_of_triangle(const Point &pa, const Point &pb,
                                        const Point &pc) {
    Line l1 = Segment(pa, pb).vertical_bisector();
    Line l2 = Segment(pa, pc).vertical_bisector();
    Point p = cross_point(l1, l2);
    coordinate_t r = (pa - p).abs();
    return Circle(p, r);
}
// 三角形の外接円
Circle circumscribed_circle_of_triangle(const Polygon &poly) {
    assert((int)poly.size() == 3);
    const Point &pa = poly[0], &pb = poly[1], &pc = poly[2];
    return circumscribed_circle_of_triangle(pa, pb, pc);
}

// 凸包
Polygon convex_hull(std::vector<Point> ps) {
    int n = int(ps.size());
    std::sort(ps.begin(), ps.end());
    Polygon ret(2 * n);
    int k = 0;
    for (int i = 0; i < n; ret[k++] = ps[i++]) {
        while (k >= 2 &&
               sgn(det(ret[k - 1] - ret[k - 2], ps[i] - ret[k - 2])) < 0) {
            k--;
        }
    }
    for (int i = n - 2, t = k + 1; i >= 0; ret[k++] = ps[i--]) {
        while (k >= t &&
               sgn(det(ret[k - 1] - ret[k - 2], ps[i] - ret[k - 2])) < 0) {
            k--;
        }
    }
    ret.resize(k - 1);
    return ret;
}
// 最小包含円
Circle smallest_enclosing_circle(std::vector<Point> ps) {
    assert((int)ps.size() >= 2);
    std::random_device seed_gen;
    std::mt19937_64 rnd(seed_gen());
    std::shuffle(ps.begin(), ps.end(), rnd);
    Circle ret((ps[0] + ps[1]) / 2, (ps[0] - ps[1]).abs() / 2);
    for (int i = 2; i < (int)ps.size(); i++) {
        if (ret.contain(ps[i])) continue;
        ret = Circle((ps[0] + ps[i]) / 2, (ps[0] - ps[i]).abs() / 2);
        for (int j = 1; j < i; j++) {
            if (ret.contain(ps[j])) continue;
            ret = Circle((ps[i] + ps[j]) / 2, (ps[i] - ps[j]).abs() / 2);
            for (int k = 0; k < j; k++) {
                if (ret.contain(ps[k])) continue;
                ret = circumscribed_circle_of_triangle(ps[i], ps[j], ps[k]);
            }
        }
    }
    return ret;
}

// 円cと多角形pの共通部分の面積を返す。
coordinate_t area_of_intersection(Circle c, Polygon p) {
    auto signed_area_of_triangle = [](Point a, Point b) -> coordinate_t {
        return det(a, b);
    };
    auto signed_area_of_sector = [&c](Point a, Point b) -> coordinate_t {
        return c.r * c.r * (rotate(b, -a.arg()).arg());
    };
    auto is_in_circle = [&c](Point a) -> bool {
        return sgn(a.abs() - c.r) < 0;
    };
    coordinate_t ret = 0;
    for (int i = 0; i < int(p.size()); i++) p[i] -= c.c;
    for (int i = 0; i < int(p.size()); i++) {
        const Point &a = p[i], &b = p[(i + 1) % int(p.size())];
        if (!intersect(Segment(a, b), c)) {
            ret += is_in_circle(a) ? signed_area_of_triangle(a, b)
                                   : signed_area_of_sector(a, b);
        } else {
            std::vector<Point> ps = cross_points(Segment(a, b), c);
            Point s = ps[0], t = ps[1 % int(ps.size())];
            if ((a < b) != (s < t)) std::swap(s, t);
            ret += is_in_circle(a) ? signed_area_of_triangle(a, s)
                                   : signed_area_of_sector(a, s);
            ret += signed_area_of_triangle(s, t);
            ret += is_in_circle(b) ? signed_area_of_triangle(t, b)
                                   : signed_area_of_sector(t, b);
        }
    }
    ret = std::fabs(ret);
    ret /= 2;
    return ret;
}
// 円cと多角形pの共通部分の面積を返す。
coordinate_t area_of_intersection(Polygon p, Circle c) {
    return area_of_intersection(c, p);
}

// 円c1と円c2の共通部分の面積を返す。
coordinate_t area_of_intersection(const Circle &c1, const Circle &c2) {
    if (sgn(c1.r + c2.r - (c1.c - c2.c).abs()) <= 0) {
        return 0;
    }
    if (sgn(std::fabs(c1.r - c2.r) - (c1.c - c2.c).abs()) >= 0) {
        return std::min(c1.area(), c2.area());
    }
    auto unsigned_area_of_triangle = [](Circle c1, Circle c2,
                                        Point p) -> coordinate_t {
        return std::fabs(det(c2.c - c1.c, p - c1.c));
    };
    auto unsigned_area_of_sector = [](Circle c1, Circle c2,
                                      Point p) -> coordinate_t {
        return std::fabs(c1.r * c1.r *
                         rotate(c2.c - c1.c, -(p - c1.c).arg()).arg());
    };
    Point p = cross_points(c1, c2)[0];
    coordinate_t ret = 0;
    ret += unsigned_area_of_sector(c1, c2, p);
    ret += unsigned_area_of_sector(c2, c1, p);
    ret -= unsigned_area_of_triangle(c1, c2, p);
    return ret;
}

// 凸多角形polyを直線lで切断したときに、その左側にできる凸多角形。
Polygon convex_cut_left(const Polygon &poly, const Line &l) {
    assert(poly.is_convex());
    Polygon ret;
    for (int i = 0; i < (int)poly.size(); i++) {
        if (ccw(l.a, l.b, poly[i]) != CLOCKWISE) {
            ret.push_back(poly[i]);
        }
        Segment s(poly[i], poly[(i + 1) % (int)poly.size()]);
        if (intersect(s, l)) {
            ret.push_back(cross_point(s, l));
        }
    }
    return ret;
}
// 凸多角形polyを直線lで切断したときに、その右側にできる凸多角形。
Polygon convex_cut_right(const Polygon &poly, const Line &l) {
    assert(poly.is_convex());
    Polygon ret;
    for (int i = 0; i < (int)poly.size(); i++) {
        if (ccw(l.a, l.b, poly[i]) != COUNTER_CLOCKWISE) {
            ret.push_back(poly[i]);
        }
        Segment s(poly[i], poly[(i + 1) % (int)poly.size()]);
        if (intersect(s, l)) {
            ret.push_back(cross_point(s, l));
        }
    }
    return ret;
}

// 点pを通る円cの接線。接点を返す。
std::vector<Point> tangent_points(const Circle &c, const Point &p) {
    assert(sgn((p - c.c).abs() - c.r) >= 0);
    coordinate_t r = std::sqrt((c.c - p).abs() * (c.c - p).abs() - c.r * c.r);
    return cross_points(c, Circle(p, r));
}

// 円c1と円c2の共通接線の本数。
int count_common_tangent(const Circle &c1, const Circle &c2) {
    if (sgn((c1.c - c2.c).abs() - (c1.r + c2.r)) > 0) {
        return 4;  // do not cross
    }
    if (sgn((c1.c - c2.c).abs() - (c1.r + c2.r)) == 0) {
        return 3;  // circumscribed
    }
    if (sgn((c1.c - c2.c).abs() - std::fabs(c1.r - c2.r)) > 0) {
        return 2;  // intersects
    }
    if (sgn((c1.c - c2.c).abs() - std::fabs(c1.r - c2.r)) == 0) {
        return 1;  // inscribed
    }
    return 0;
}

// 円c1と円c2の共通接線。円c1における接点を返す。
std::vector<Point> common_tangents(const Circle &c1, const Circle &c2) {
    std::vector<Point> ret, ret1, ret2;
    if (sgn((c1.c - c2.c).abs() - std::fabs(c1.r - c2.r)) >= 0) {
        coordinate_t d = (c1.c - c2.c).abs();
        coordinate_t r =
            std::sqrt(d * d - (c1.r - c2.r) * (c1.r - c2.r) + c2.r * c2.r);
        ret1 = cross_points(c1, Circle(c2.c, r));
    }
    if (sgn((c1.c - c2.c).abs() - (c1.r + c2.r)) >= 0) {
        Point p = c1.c + (c2.c - c1.c) * c1.r / (c1.r + c2.r);
        ret2 = tangent_points(c1, p);
    }
    std::merge(ret1.begin(), ret1.end(), ret2.begin(), ret2.end(),
               std::back_inserter(ret));
    ret.erase(std::unique(ret.begin(), ret.end()), ret.end());
    return ret;
}
// (距離, 点のペア) を返す
std::pair<coordinate_t, std::pair<Point, Point>> closest_pair(
    std::vector<Point> ps) {
    std::sort(ps.begin(), ps.end(),
              [](Point a, Point b) { return sgn(a.x - b.x) < 0; });
    std::vector<Point> memo(ps.size());
    auto dfs = [&](auto dfs, int l,
                   int r) -> std::pair<coordinate_t, std::pair<Point, Point>> {
        if (r - l < 2) return {1e18, {Point(), Point()}};
        int m = (r + l) / 2;
        coordinate_t x = ps[m].x;
        auto l_res = dfs(dfs, l, m), r_res = dfs(dfs, m, r);
        auto [d, p] = (l_res.first < r_res.first ? l_res : r_res);
        std::inplace_merge(ps.begin() + l, ps.begin() + m, ps.begin() + r,
                           [](Point a, Point b) { return sgn(a.y - b.y) < 0; });

        int cur = 0;
        for (int i = l; i < r; i++) {
            if (std::fabs(ps[i].x - x) >= d) continue;
            for (int j = cur - 1; j >= 0; j--) {
                if (ps[i].y - memo[j].y >= d) break;
                coordinate_t new_d = (ps[i] - memo[j]).abs();
                if (new_d < d) {
                    d = new_d;
                    p = {ps[i], memo[j]};
                }
            }
            memo[cur++] = ps[i];
        }
        return {d, p};
    };
    return dfs(dfs, 0, (int)ps.size());
}
// (距離, 点のペア) を返す
std::pair<coordinate_t, std::pair<Point, Point>> farthest_pair(
    std::vector<Point> ps) {
    ps = convex_hull(ps);
    std::pair<coordinate_t, std::pair<Point, Point>> ret = {
        0, std::make_pair(ps[0], ps[0])};
    int r = 0;
    for (int l = 0; l < (int)ps.size(); l++) {
        while (sgn((ps[l] - ps[r]).abs() -
                   (ps[l] - ps[(r + 1) % (int)ps.size()]).abs()) < 0) {
            r++;
            if (r == (int)ps.size()) r = 0;
        }
        if (sgn(ret.first - (ps[l] - ps[r]).abs()) < 0) {
            ret.first = (ps[l] - ps[r]).abs();
            ret.second = {ps[l], ps[r]};
        }
    }
    return ret;
}

// 点a,点bからの距離の比がn:mになる点の軌跡
Circle circle_of_apollonius(Point a, Point b, coordinate_t n, coordinate_t m) {
    assert(sgn(n - m) != 0);
    Point c = (a * (-m * m) + b * (n * n)) / (n * n - m * m);
    coordinate_t r = std::sqrt(dist(a, c) * dist(b, c));
    return {c, r};
}
}  // namespace geometry