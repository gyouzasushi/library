#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <concepts>
#include <iostream>

#include "geometry/point.hpp"
namespace geo {
template <class T> struct line {
    point<T> a, b;
    line() {
    }
    line(const point<T>& a, const point<T>& b) : a(a), b(b) {
    }
    friend std::istream& operator>>(std::istream& is, line& l) {
        return is >> l.a >> l.b;
    }
};
template <class T> struct segment {
    point<T> a, b;
    segment() {
    }
    segment(const point<T>& a, const point<T>& b) : a(a), b(b) {
    }
    friend std::istream& operator>>(std::istream& is, segment& s) {
        return is >> s.a >> s.b;
    }
};
template <class T> line<T> to_line(const segment<T>& s) {
    return line<T>(s.a, s.b);
}
template <class T> bool parallel(const line<T>& l, const line<T>& m) {
    return sgn(cross(l.b - l.a, m.b - m.a)) == 0;
}
template <class T> bool orthogonal(const line<T>& l, const line<T>& m) {
    return sgn(dot(l.b - l.a, m.b - m.a)) == 0;
}
template <class T> bool on_line(const line<T>& l, const point<T>& p) {
    return ccw(l.a, l.b, p) == 0;
}
template <class T> bool on_segment(const segment<T>& s, const point<T>& p) {
    return ccw(s.a, s.b, p) == 0 && sgn(dot(s.a - p, s.b - p)) <= 0;
}
template <class T> bool intersect(const line<T>& l, const line<T>& m) {
    return !parallel(l, m) || on_line(l, m.a);
}
template <class T> bool intersect(const line<T>& l, const segment<T>& s) {
    return ccw(l.a, l.b, s.a) * ccw(l.a, l.b, s.b) <= 0;
}
template <class T> bool intersect(const segment<T>& s, const line<T>& l) {
    return intersect(l, s);
}
template <class T> bool intersect(const segment<T>& s, const segment<T>& t) {
    if (ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) > 0) return false;
    if (ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) > 0) return false;
    if (ccw(s.a, s.b, t.a) != 0 || ccw(s.a, s.b, t.b) != 0) return true;
    return on_segment(s, t.a) || on_segment(s, t.b) || on_segment(t, s.a) || on_segment(t, s.b);
}
template <std::floating_point T> point<T> projection(const line<T>& l, const point<T>& p) {
    point<T> d = l.b - l.a;
    return l.a + d * (dot(d, p - l.a) / norm(d));
}
template <std::floating_point T> point<T> reflection(const line<T>& l, const point<T>& p) {
    return projection(l, p) * T(2) - p;
}
template <std::floating_point T> line<T> perpendicular_bisector(const point<T>& a, const point<T>& b) {
    point<T> m = (a + b) / T(2);
    return line<T>(m, m + normal(b - a));
}
template <std::floating_point T> T dist(const point<T>& a, const point<T>& b) {
    return abs(a - b);
}
template <std::floating_point T> T dist(const line<T>& l, const point<T>& p) {
    return std::abs(cross(l.b - l.a, p - l.a)) / abs(l.b - l.a);
}
template <std::floating_point T> T dist(const point<T>& p, const line<T>& l) {
    return dist(l, p);
}
template <std::floating_point T> T dist(const segment<T>& s, const point<T>& p) {
    if (sgn(dot(s.b - s.a, p - s.a)) < 0) return abs(p - s.a);
    if (sgn(dot(s.a - s.b, p - s.b)) < 0) return abs(p - s.b);
    return dist(to_line(s), p);
}
template <std::floating_point T> T dist(const point<T>& p, const segment<T>& s) {
    return dist(s, p);
}
template <std::floating_point T> T dist(const line<T>& l, const line<T>& m) {
    if (intersect(l, m)) return 0;
    return dist(l, m.a);
}
template <std::floating_point T> T dist(const line<T>& l, const segment<T>& s) {
    if (intersect(l, s)) return 0;
    return std::min(dist(l, s.a), dist(l, s.b));
}
template <std::floating_point T> T dist(const segment<T>& s, const line<T>& l) {
    return dist(l, s);
}
template <std::floating_point T> T dist(const segment<T>& s, const segment<T>& t) {
    if (intersect(s, t)) return 0;
    return std::min({dist(s, t.a), dist(s, t.b), dist(t, s.a), dist(t, s.b)});
}
template <std::floating_point T> point<T> cross_point(const line<T>& l, const line<T>& m) {
    assert(!parallel(l, m));
    point<T> d = l.b - l.a;
    return l.a + d * (cross(m.b - m.a, m.a - l.a) / cross(m.b - m.a, d));
}
template <std::floating_point T> point<T> cross_point(const line<T>& l, const segment<T>& s) {
    assert(intersect(l, s));
    return cross_point(l, to_line(s));
}
template <std::floating_point T> point<T> cross_point(const segment<T>& s, const line<T>& l) {
    return cross_point(l, s);
}
template <std::floating_point T> point<T> cross_point(const segment<T>& s, const segment<T>& t) {
    assert(intersect(s, t));
    return cross_point(to_line(s), to_line(t));
}
}  // namespace geo
