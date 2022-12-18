#pragma once
namespace integer_geometry {
#include <algorithm>
#include <iostream>
#include <vector>
using coordinate_t = long long;
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
    inline bool operator<(const Point &b) {
        if (x != b.x) return x < b.x;
        return y < b.y;
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
    Point normal() const {
        return Point(-y, x);
    }
};
inline bool operator<(const Point &a, const Point &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
inline bool operator==(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}
inline bool operator>(const Point &a, const Point &b) {
    if (a.x > b.x) return a.x > b.x;
    return a.y > b.y;
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
coordinate_t dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
coordinate_t det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
struct Polygon : std::vector<Point> {
    Polygon(int n = 0) : std::vector<Point>(n) {
    }
};
// 凸包

Polygon convex_hull(std::vector<Point> ps) {
    int n = int(ps.size());
    std::sort(ps.begin(), ps.end());
    Polygon ret(2 * n);
    int k = 0;
    for (int i = 0; i < n; ret[k++] = ps[i++]) {
        while (k >= 2 && det(ret[k - 1] - ret[k - 2], ps[i] - ret[k - 1]) < 0) {
            k--;
        }
    }
    for (int i = n - 2, t = k + 1; i >= 0; ret[k++] = ps[i--]) {
        while (k >= t && det(ret[k - 1] - ret[k - 2], ps[i] - ret[k - 1]) < 0) {
            k--;
        }
    }
    ret.resize(k - 1);
    return ret;
}
Polygon lower_convex_hull(std::vector<Point> ps) {
    int n = int(ps.size());
    std::sort(ps.begin(), ps.end());
    Polygon ret(n);
    int k = 0;
    for (int i = 0; i < n; ret[k++] = ps[i++]) {
        while (k >= 2 && det(ret[k - 1] - ret[k - 2], ps[i] - ret[k - 1]) < 0) {
            k--;
        }
    }
    ret.resize(k);
    return ret;
}
}  // namespace integer_geometry