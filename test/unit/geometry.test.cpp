#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <random>
#include <set>
#include <vector>

#include "geometry/circle.hpp"
#include "geometry/line.hpp"
#include "geometry/point.hpp"
#include "geometry/polygon.hpp"
using P = geo::point<long long>;
using D = geo::point<double>;
using i128 = __int128;
// independent segment intersection via exact parametric solve
bool brute_intersect(P a, P b, P c, P d) {
    auto cr = [](P p, P q) { return (i128)p.x * q.y - (i128)p.y * q.x; };
    auto on = [&](P p, P q, P x) {
        return cr(q - p, x - p) == 0 && std::min(p.x, q.x) <= x.x && x.x <= std::max(p.x, q.x) &&
               std::min(p.y, q.y) <= x.y && x.y <= std::max(p.y, q.y);
    };
    if (a == b) return on(c, d, a);
    if (c == d) return on(a, b, c);
    P r = b - a, s = d - c;
    i128 den = cr(r, s);
    if (den != 0) {
        i128 tn = cr(c - a, s), un = cr(c - a, r);
        if (den < 0) den = -den, tn = -tn, un = -un;
        return 0 <= tn && tn <= den && 0 <= un && un <= den;
    }
    if (cr(c - a, r) != 0) return false;  // parallel, not collinear
    return on(a, b, c) || on(a, b, d) || on(c, d, a) || on(c, d, b);
}
bool in_triangle_closed(P a, P b, P c, P p) {
    int s1 = geo::ccw(a, b, p), s2 = geo::ccw(b, c, p), s3 = geo::ccw(c, a, p);
    if (geo::ccw(a, b, c) == 0) return false;
    return (s1 >= 0 && s2 >= 0 && s3 >= 0) || (s1 <= 0 && s2 <= 0 && s3 <= 0);
}
int main() {
    std::mt19937 rng(2024);
    auto rp = [&](int w) { return P(int(rng() % (2 * w + 1)) - w, int(rng() % (2 * w + 1)) - w); };
    for (int it = 0; it < 3000; it++) {
        // ccw sign == sign of cross, and matches double version
        P a = rp(5), b = rp(5), c = rp(5);
        D da(a.x, a.y), db(b.x, b.y), dc(c.x, c.y);
        assert(geo::ccw(a, b, c) == geo::sgn(geo::cross(b - a, c - a)));
        assert(geo::ccw(a, b, c) == geo::ccw(da, db, dc));
        // segment intersection vs independent implementation
        P d = rp(5);
        geo::segment<long long> s(a, b), t(c, d);
        assert(geo::intersect(s, t) == brute_intersect(a, b, c, d));
        assert(geo::intersect(s, t) == geo::intersect(geo::segment<double>(da, db), geo::segment<double>(dc, D(d.x, d.y))));
        // on_segment
        assert(geo::on_segment(s, c) == brute_intersect(a, b, c, c));
    }
    for (int it = 0; it < 2000; it++) {
        int n = 1 + rng() % 9;
        std::vector<P> ps(n);
        for (auto& p : ps) p = rp(4);
        // strict hull: vertices are exactly the points not inside/on any triangle or segment of others
        geo::polygon<long long> ch = geo::convex_hull(ps);
        std::set<std::pair<long long, long long>> hull_set;
        for (auto& p : ch) hull_set.insert({p.x, p.y});
        std::set<std::pair<long long, long long>> uniq;
        for (auto& p : ps) uniq.insert({p.x, p.y});
        std::vector<P> us;
        for (auto [x, y] : uniq) us.emplace_back(x, y);
        int m = int(us.size());
        for (int i = 0; i < m; i++) {
            bool vertex = true;
            for (int j = 0; j < m && vertex; j++) {
                if (j == i) continue;
                for (int k = j + 1; k < m && vertex; k++) {
                    if (k == i) continue;
                    if (geo::on_segment(geo::segment<long long>(us[j], us[k]), us[i])) vertex = false;
                    for (int l = k + 1; l < m && vertex; l++) {
                        if (l == i) continue;
                        if (in_triangle_closed(us[j], us[k], us[l], us[i])) vertex = false;
                    }
                }
            }
            assert(vertex == hull_set.count({us[i].x, us[i].y}));
        }
        // ccw order and convexity
        int h = int(ch.size());
        if (h >= 3) {
            assert(geo::is_convex(ch));
            for (int i = 0; i < h; i++) assert(geo::ccw(ch[i], ch[(i + 1) % h], ch[(i + 2) % h]) > 0);
            assert(geo::area2(ch) > 0);
            // contains on convex polygon vs brute
            for (int q = 0; q < 20; q++) {
                P p = rp(5);
                int expect = 2;
                for (int i = 0; i < h; i++) {
                    int s = geo::ccw(ch[i], ch[(i + 1) % h], p);
                    if (s < 0) expect = 0;
                    if (s == 0 && expect != 0 && geo::on_segment(geo::segment<long long>(ch[i], ch[(i + 1) % h]), p)) expect = 1;
                }
                assert(geo::contains(ch, p) == expect);
            }
            // area2 vs double shoelace
            geo::polygon<double> dch;
            for (auto& p : ch) dch.emplace_back(p.x, p.y);
            assert(std::abs(geo::area(dch) * 2 - (double)geo::area2(ch)) < 1e-9);
        }
        // non-strict hull: superset of strict, all on boundary, contains everything
        geo::polygon<long long> ch2 = geo::convex_hull(ps, false);
        assert(ch2.size() >= ch.size());
        if (h >= 3) {
            for (auto& p : ch2) assert(geo::contains(ch, p) == 1);
            for (auto& p : ps) assert(geo::contains(ch2, p) >= 1);
            int h2 = int(ch2.size());
            for (int i = 0; i < h2; i++) assert(geo::ccw(ch2[i], ch2[(i + 1) % h2], ch2[(i + 2) % h2]) >= 0);
        }
        // closest / farthest pair vs brute
        if (n >= 2) {
            auto [i, j] = geo::closest_pair(ps);
            auto [k, l] = geo::farthest_pair(ps);
            assert(i != j && k != l);
            long long best = geo::norm(ps[i] - ps[j]), worst = geo::norm(ps[k] - ps[l]);
            for (int x = 0; x < n; x++) {
                for (int y = x + 1; y < n; y++) {
                    assert(geo::norm(ps[x] - ps[y]) >= best);
                    assert(geo::norm(ps[x] - ps[y]) <= worst);
                }
            }
        }
        // arg sort vs atan2 (-pi, pi], origin treated as 0
        std::vector<P> qs = ps;
        std::sort(qs.begin(), qs.end(), geo::arg_less{});
        auto ang = [](P p) { return p.x == 0 && p.y == 0 ? 0.0L : atan2l((long double)p.y, (long double)p.x); };
        for (int i = 0; i + 1 < n; i++) assert(ang(qs[i]) <= ang(qs[i + 1]) + 1e-15L);
    }
    // non-convex polygon containment (handmade)
    geo::polygon<long long> u = {{0, 0}, {4, 0}, {4, 4}, {3, 4}, {3, 1}, {1, 1}, {1, 4}, {0, 4}};
    assert(geo::contains(u, {2, 2}) == 0);
    assert(geo::contains(u, {2, 0}) == 1);
    assert(geo::contains(u, {3, 2}) == 1);
    assert(geo::contains(u, {2, 1}) == 1);
    assert(geo::contains(u, {3, 1}) == 1);
    assert(geo::contains(u, {1, 2}) == 1);
    assert(geo::contains(u, {0, 2}) == 1);
    assert(geo::contains(u, {2, 3}) == 0);
    assert(geo::contains(u, {3, 5}) == 0);
    for (long long x = -1; x <= 5; x++) {
        for (long long y = -1; y <= 5; y++) {
            P p(x, y);
            bool inside = (0 < x && x < 4 && 0 < y && y < 4) && !(1 <= x && x <= 3 && 1 <= y);
            bool boundary = !inside && ((0 <= x && x <= 4 && (y == 0 || y == 4) && !(y == 4 && 1 < x && x < 3)) ||
                                        ((x == 0 || x == 4) && 0 <= y && y <= 4) ||
                                        ((x == 1 || x == 3) && 1 <= y && y <= 4) || (y == 1 && 1 <= x && x <= 3));
            assert(geo::contains(u, p) == (inside ? 2 : boundary ? 1 : 0));
        }
    }
    // double-only: circle sanity
    geo::circle<double> o(D(0, 0), 1);
    assert(geo::contains(o, D(0.5, 0)) == 2 && geo::contains(o, D(1, 0)) == 1 && geo::contains(o, D(2, 0)) == 0);
    auto cp = geo::cross_points(o, geo::line<double>(D(-2, 0), D(2, 0)));
    assert(cp.size() == 2 && cp[0] == D(-1, 0) && cp[1] == D(1, 0));
    assert(std::abs(geo::area_of_intersection(o, geo::circle<double>(D(0, 0), 1)) - M_PI) < 1e-9);
    assert(std::abs(geo::area_of_intersection(o, geo::circle<double>(D(2, 0), 1))) < 1e-9);
    std::cout << "Hello World" << std::endl;
}
