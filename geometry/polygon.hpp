#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <concepts>
#include <utility>
#include <vector>

#include "geometry/line.hpp"
#include "geometry/point.hpp"
namespace geo {
template <class T> using polygon = std::vector<point<T>>;
template <class T> T area2(const polygon<T>& poly) {
    int n = int(poly.size());
    if constexpr (std::is_integral_v<T>) {
        __int128 ret = 0;
        for (int i = 0; i < n; i++) ret += (__int128)cross(poly[i], poly[(i + 1) % n]);
        return T(ret);
    } else {
        T ret = 0;
        for (int i = 0; i < n; i++) ret += cross(poly[i], poly[(i + 1) % n]);
        return ret;
    }
}
template <std::floating_point T> T area(const polygon<T>& poly) {
    return area2(poly) / T(2);
}
template <class T> bool is_convex(const polygon<T>& poly) {
    int n = int(poly.size());
    for (int i = 0; i < n; i++) {
        if (ccw(poly[i], poly[(i + 1) % n], poly[(i + 2) % n]) < 0) return false;
    }
    return true;
}
template <class T> int contains(const polygon<T>& poly, const point<T>& p) {
    int n = int(poly.size());
    bool in = false;
    for (int i = 0; i < n; i++) {
        point<T> a = poly[i] - p, b = poly[(i + 1) % n] - p;
        if (ccw(a, b, point<T>()) == 0 && sgn(dot(a, b)) <= 0) return 1;
        if (sgn(a.y) > sgn(b.y)) std::swap(a, b);
        if (sgn(a.y) <= 0 && 0 < sgn(b.y) && sgn(cross(a, b)) > 0) in = !in;
    }
    return in ? 2 : 0;
}
template <class T> polygon<T> convex_hull(std::vector<point<T>> ps, bool strict = true) {
    int n = int(ps.size());
    std::sort(ps.begin(), ps.end());
    ps.erase(std::unique(ps.begin(), ps.end()), ps.end());
    n = int(ps.size());
    if (n <= 2) return ps;
    polygon<T> ret(2 * n);
    int k = 0;
    for (int i = 0; i < n; ret[k++] = ps[i++]) {
        while (k >= 2 && ccw(ret[k - 2], ret[k - 1], ps[i]) < (strict ? 1 : 0)) k--;
    }
    for (int i = n - 2, t = k + 1; i >= 0; ret[k++] = ps[i--]) {
        while (k >= t && ccw(ret[k - 2], ret[k - 1], ps[i]) < (strict ? 1 : 0)) k--;
    }
    ret.resize(k - 1);
    return ret;
}
template <class T> std::pair<int, int> farthest_pair(const std::vector<point<T>>& ps) {
    int n = int(ps.size());
    assert(n >= 2);
    polygon<T> ch = convex_hull(ps);
    int m = int(ch.size());
    auto index_of = [&](const point<T>& p) {
        return int(std::find(ps.begin(), ps.end(), p) - ps.begin());
    };
    if (m == 1) return {0, 1};
    if (m == 2) return {index_of(ch[0]), index_of(ch[1])};
    std::pair<int, int> ret = {0, 1};
    T best = norm(ch[0] - ch[1]);
    for (int i = 0, j = 1; i < m; i++) {
        while (sgn(norm(ch[i] - ch[(j + 1) % m]) - norm(ch[i] - ch[j])) > 0) j = (j + 1) % m;
        if (sgn(norm(ch[i] - ch[j]) - best) > 0) {
            best = norm(ch[i] - ch[j]);
            ret = {i, j};
        }
    }
    return {index_of(ch[ret.first]), index_of(ch[ret.second])};
}
template <class T> std::pair<int, int> closest_pair(const std::vector<point<T>>& ps) {
    int n = int(ps.size());
    assert(n >= 2);
    std::vector<int> id(n);
    for (int i = 0; i < n; i++) id[i] = i;
    std::sort(id.begin(), id.end(), [&](int i, int j) { return ps[i] < ps[j]; });
    std::pair<int, int> ret = {id[0], id[1]};
    T best = norm(ps[id[0]] - ps[id[1]]);
    std::vector<int> buf(n);
    auto rec = [&](auto rec, int l, int r) -> void {
        if (r - l <= 1) return;
        int m = (l + r) / 2;
        T x = ps[id[m]].x;
        rec(rec, l, m);
        rec(rec, m, r);
        std::inplace_merge(id.begin() + l, id.begin() + m, id.begin() + r,
                           [&](int i, int j) { return ps[i].y < ps[j].y; });
        int k = 0;
        for (int t = l; t < r; t++) {
            int i = id[t];
            T dx = ps[i].x - x;
            if (sgn(dx * dx - best) >= 0) continue;
            for (int u = k - 1; u >= 0; u--) {
                int j = buf[u];
                T dy = ps[i].y - ps[j].y;
                if (sgn(dy * dy - best) >= 0) break;
                T d = norm(ps[i] - ps[j]);
                if (sgn(d - best) < 0) {
                    best = d;
                    ret = {j, i};
                }
            }
            buf[k++] = i;
        }
    };
    rec(rec, 0, n);
    return ret;
}
template <std::floating_point T> polygon<T> convex_cut(const polygon<T>& poly, const line<T>& l) {
    int n = int(poly.size());
    polygon<T> ret;
    for (int i = 0; i < n; i++) {
        const point<T>& p = poly[i];
        const point<T>& q = poly[(i + 1) % n];
        int cp = ccw(l.a, l.b, p), cq = ccw(l.a, l.b, q);
        if (cp >= 0) ret.push_back(p);
        if (cp * cq < 0) ret.push_back(cross_point(l, line<T>(p, q)));
    }
    return ret;
}
}  // namespace geo
