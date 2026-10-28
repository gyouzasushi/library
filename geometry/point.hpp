#pragma once
#include <cmath>
#include <compare>
#include <concepts>
#include <iostream>
#include <type_traits>
namespace geo {
inline long double eps = 1e-9;
template <class T> int sgn(T a) {
    if constexpr (std::is_integral_v<T>) {
        return (a > 0) - (a < 0);
    } else {
        return a < -eps ? -1 : a > eps ? 1 : 0;
    }
}
template <class T> struct point {
    T x, y;
    point() : x(0), y(0) {
    }
    point(T x, T y) : x(x), y(y) {
    }
    point& operator+=(const point& p) {
        x += p.x, y += p.y;
        return *this;
    }
    point& operator-=(const point& p) {
        x -= p.x, y -= p.y;
        return *this;
    }
    point& operator*=(T k) {
        x *= k, y *= k;
        return *this;
    }
    point& operator/=(T k) requires std::floating_point<T> {
        x /= k, y /= k;
        return *this;
    }
    point operator-() const {
        return point(-x, -y);
    }
    friend point operator+(point a, const point& b) {
        return a += b;
    }
    friend point operator-(point a, const point& b) {
        return a -= b;
    }
    friend point operator*(point a, T k) {
        return a *= k;
    }
    friend point operator*(T k, point a) {
        return a *= k;
    }
    friend point operator/(point a, T k) requires std::floating_point<T> {
        return a /= k;
    }
    friend bool operator==(const point& a, const point& b) {
        return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;
    }
    friend std::weak_ordering operator<=>(const point& a, const point& b) {
        if (int s = sgn(a.x - b.x); s != 0) return s <=> 0;
        return sgn(a.y - b.y) <=> 0;
    }
    friend std::istream& operator>>(std::istream& is, point& p) {
        return is >> p.x >> p.y;
    }
    friend std::ostream& operator<<(std::ostream& os, const point& p) {
        return os << p.x << ' ' << p.y;
    }
};
template <class T> T dot(const point<T>& a, const point<T>& b) {
    return a.x * b.x + a.y * b.y;
}
template <class T> T cross(const point<T>& a, const point<T>& b) {
    return a.x * b.y - a.y * b.x;
}
template <class T> T norm(const point<T>& p) {
    return p.x * p.x + p.y * p.y;
}
template <std::floating_point T> T abs(const point<T>& p) {
    return std::sqrt(norm(p));
}
template <std::floating_point T> T arg(const point<T>& p) {
    return std::atan2(p.y, p.x);
}
template <class T> point<T> normal(const point<T>& p) {
    return point<T>(-p.y, p.x);
}
template <std::floating_point T> point<T> unit(const point<T>& p) {
    return p / abs(p);
}
template <std::floating_point T> point<T> rotate(const point<T>& p, T theta) {
    T c = std::cos(theta), s = std::sin(theta);
    return point<T>(p.x * c - p.y * s, p.x * s + p.y * c);
}
template <class T> int ccw(const point<T>& a, const point<T>& b, const point<T>& c) {
    return sgn(cross(b - a, c - a));
}
struct arg_less {
    template <class T> static int group(const point<T>& p) {
        if (sgn(p.y) < 0) return 0;
        if (sgn(p.y) == 0 && sgn(p.x) >= 0) return 1;
        return 2;
    }
    template <class T> bool operator()(const point<T>& a, const point<T>& b) const {
        if (group(a) != group(b)) return group(a) < group(b);
        return sgn(cross(a, b)) > 0;
    }
};
}  // namespace geo
