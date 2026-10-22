#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <concepts>
#include <numbers>
#include <random>
#include <vector>

#include "geometry/line.hpp"
#include "geometry/point.hpp"
#include "geometry/polygon.hpp"
namespace geo {
template <std::floating_point T> struct circle {
    point<T> c;
    T r;
    circle() : r(0) {
    }
    circle(const point<T>& c, T r) : c(c), r(r) {
    }
    friend std::istream& operator>>(std::istream& is, circle& o) {
        return is >> o.c >> o.r;
    }
};
template <std::floating_point T> T area(const circle<T>& o) {
    return std::numbers::pi_v<T> * o.r * o.r;
}
template <std::floating_point T> int contains(const circle<T>& o, const point<T>& p) {
    int s = sgn(abs(p - o.c) - o.r);
    return s > 0 ? 0 : s == 0 ? 1 : 2;
}
template <std::floating_point T> bool intersect(const line<T>& l, const circle<T>& o) {
    return sgn(dist(l, o.c) - o.r) <= 0;
}
template <std::floating_point T> bool intersect(const circle<T>& o, const line<T>& l) {
    return intersect(l, o);
}
template <std::floating_point T> bool intersect(const segment<T>& s, const circle<T>& o) {
    if (sgn(dist(s, o.c) - o.r) > 0) return false;
    return sgn(abs(s.a - o.c) - o.r) >= 0 || sgn(abs(s.b - o.c) - o.r) >= 0;
}
template <std::floating_point T> bool intersect(const circle<T>& o, const segment<T>& s) {
    return intersect(s, o);
}
template <std::floating_point T> int count_common_tangents(const circle<T>& a, const circle<T>& b) {
    T d = abs(a.c - b.c);
    if (sgn(d - (a.r + b.r)) > 0) return 4;
    if (sgn(d - (a.r + b.r)) == 0) return 3;
    if (sgn(d - std::abs(a.r - b.r)) > 0) return 2;
    if (sgn(d - std::abs(a.r - b.r)) == 0) return 1;
    return 0;
}
template <std::floating_point T> bool intersect(const circle<T>& a, const circle<T>& b) {
    int k = count_common_tangents(a, b);
    return 1 <= k && k <= 3;
}
template <std::floating_point T> std::vector<point<T>> cross_points(const line<T>& l, const circle<T>& o) {
    if (!intersect(l, o)) return {};
    point<T> p = projection(l, o.c);
    T h = std::sqrt(std::max<T>(0, o.r * o.r - norm(p - o.c)));
    point<T> v = unit(l.b - l.a) * h;
    std::vector<point<T>> ret = {p - v, p + v};
    if (ret[1] < ret[0]) std::swap(ret[0], ret[1]);
    return ret;
}
template <std::floating_point T> std::vector<point<T>> cross_points(const circle<T>& o, const line<T>& l) {
    return cross_points(l, o);
}
template <std::floating_point T> std::vector<point<T>> cross_points(const segment<T>& s, const circle<T>& o) {
    std::vector<point<T>> ret = cross_points(to_line(s), o);
    ret.erase(std::remove_if(ret.begin(), ret.end(), [&](const point<T>& p) { return !on_segment(s, p); }),
              ret.end());
    return ret;
}
template <std::floating_point T> std::vector<point<T>> cross_points(const circle<T>& o, const segment<T>& s) {
    return cross_points(s, o);
}
template <std::floating_point T> std::vector<point<T>> cross_points(const circle<T>& a, const circle<T>& b) {
    if (!intersect(a, b)) return {};
    T d = abs(a.c - b.c);
    T x = (d * d + a.r * a.r - b.r * b.r) / (2 * d);
    T h = std::sqrt(std::max<T>(0, a.r * a.r - x * x));
    point<T> e = unit(b.c - a.c);
    point<T> m = a.c + e * x, v = normal(e) * h;
    std::vector<point<T>> ret = {m - v, m + v};
    if (ret[1] < ret[0]) std::swap(ret[0], ret[1]);
    return ret;
}
template <std::floating_point T> std::vector<point<T>> tangent_points(const circle<T>& o, const point<T>& p) {
    assert(sgn(abs(p - o.c) - o.r) >= 0);
    T r = std::sqrt(std::max<T>(0, norm(p - o.c) - o.r * o.r));
    return cross_points(o, circle<T>(p, r));
}
template <std::floating_point T> std::vector<point<T>> common_tangents(const circle<T>& a, const circle<T>& b) {
    std::vector<point<T>> ret;
    T d = abs(a.c - b.c);
    if (sgn(d - std::abs(a.r - b.r)) >= 0) {
        T r = std::sqrt(std::max<T>(0, d * d - (a.r - b.r) * (a.r - b.r) + b.r * b.r));
        std::vector<point<T>> ps = cross_points(a, circle<T>(b.c, r));
        ret.insert(ret.end(), ps.begin(), ps.end());
    }
    if (sgn(d - (a.r + b.r)) >= 0) {
        point<T> p = a.c + (b.c - a.c) * (a.r / (a.r + b.r));
        std::vector<point<T>> ps = tangent_points(a, p);
        ret.insert(ret.end(), ps.begin(), ps.end());
    }
    std::sort(ret.begin(), ret.end());
    ret.erase(std::unique(ret.begin(), ret.end()), ret.end());
    return ret;
}
template <std::floating_point T> circle<T> incircle(const point<T>& a, const point<T>& b, const point<T>& c) {
    T x = abs(b - c), y = abs(c - a), z = abs(a - b);
    point<T> p = (a * x + b * y + c * z) / (x + y + z);
    return circle<T>(p, dist(line<T>(a, b), p));
}
template <std::floating_point T> circle<T> circumcircle(const point<T>& a, const point<T>& b, const point<T>& c) {
    point<T> p = cross_point(perpendicular_bisector(a, b), perpendicular_bisector(a, c));
    return circle<T>(p, abs(a - p));
}
template <std::floating_point T> circle<T> smallest_enclosing_circle(std::vector<point<T>> ps) {
    int n = int(ps.size());
    assert(n >= 1);
    std::shuffle(ps.begin(), ps.end(), std::mt19937(123456789));
    circle<T> ret(ps[0], 0);
    for (int i = 1; i < n; i++) {
        if (contains(ret, ps[i])) continue;
        ret = circle<T>(ps[i], 0);
        for (int j = 0; j < i; j++) {
            if (contains(ret, ps[j])) continue;
            ret = circle<T>((ps[i] + ps[j]) / T(2), abs(ps[i] - ps[j]) / T(2));
            for (int k = 0; k < j; k++) {
                if (contains(ret, ps[k])) continue;
                ret = circumcircle(ps[i], ps[j], ps[k]);
            }
        }
    }
    return ret;
}
template <std::floating_point T> T area_of_intersection(const circle<T>& o, const polygon<T>& poly) {
    int n = int(poly.size());
    auto tri = [](const point<T>& a, const point<T>& b) { return cross(a, b); };
    auto sector = [&](const point<T>& a, const point<T>& b) { return o.r * o.r * arg(rotate(b, -arg(a))); };
    auto inside = [&](const point<T>& a) { return sgn(abs(a) - o.r) < 0; };
    T ret = 0;
    for (int i = 0; i < n; i++) {
        point<T> a = poly[i] - o.c, b = poly[(i + 1) % n] - o.c;
        segment<T> s(a, b);
        circle<T> c(point<T>(), o.r);
        if (!intersect(s, c)) {
            ret += inside(a) ? tri(a, b) : sector(a, b);
            continue;
        }
        std::vector<point<T>> ps = cross_points(s, c);
        point<T> p = ps[0], q = ps[ps.size() - 1];
        if (sgn(dot(b - a, q - p)) < 0) std::swap(p, q);
        ret += inside(a) ? tri(a, p) : sector(a, p);
        ret += tri(p, q);
        ret += inside(b) ? tri(q, b) : sector(q, b);
    }
    return ret / 2;
}
template <std::floating_point T> T area_of_intersection(const polygon<T>& poly, const circle<T>& o) {
    return area_of_intersection(o, poly);
}
template <std::floating_point T> T area_of_intersection(const circle<T>& a, const circle<T>& b) {
    T d = abs(a.c - b.c);
    if (sgn(a.r + b.r - d) <= 0) return 0;
    if (sgn(std::abs(a.r - b.r) - d) >= 0) return std::min(area(a), area(b));
    auto part = [&](const circle<T>& x, const circle<T>& y) {
        T cs = (d * d + x.r * x.r - y.r * y.r) / (2 * d * x.r);
        T theta = std::acos(std::clamp<T>(cs, -1, 1));
        return x.r * x.r * (theta - std::sin(2 * theta) / 2);
    };
    return part(a, b) + part(b, a);
}
template <std::floating_point T> circle<T> circle_of_apollonius(const point<T>& a, const point<T>& b, T n, T m) {
    assert(sgn(n - m) != 0);
    point<T> c = (a * (-m * m) + b * (n * n)) / (n * n - m * m);
    return circle<T>(c, std::sqrt(abs(a - c) * abs(b - c)));
}
}  // namespace geo
