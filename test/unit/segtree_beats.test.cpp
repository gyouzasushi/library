#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "algebra/range_chmin_chmax_add_range_sum.hpp"
#include "datastructure/segtree_beats.hpp"
int main() {
    using A = range_chmin_chmax_add_range_sum<long long>;
    std::mt19937 rng(20261029);
    for (int trial = 0; trial < 300; trial++) {
        int n = 1 + rng() % 40;
        std::vector<long long> a(n);
        std::vector<A::S> init(n);
        for (int i = 0; i < n; i++) {
            a[i] = (long long)(rng() % 41) - 20;
            init[i] = A::from(a[i]);
        }
        segtree_beats<A> seg(init);
        for (int step = 0; step < 300; step++) {
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            long long x = (long long)(rng() % 41) - 20;
            int t = rng() % 9;
            if (t == 0) {
                seg.apply(l, r, A::chmin(x));
                for (int i = l; i < r; i++) a[i] = std::min(a[i], x);
            } else if (t == 1) {
                seg.apply(l, r, A::chmax(x));
                for (int i = l; i < r; i++) a[i] = std::max(a[i], x);
            } else if (t == 2) {
                seg.apply(l, r, A::add(x));
                for (int i = l; i < r; i++) a[i] += x;
            } else if (t == 3) {
                seg.apply(l, r, A::assign(x));
                for (int i = l; i < r; i++) a[i] = x;
            } else if (t == 4) {
                int p = rng() % n;
                seg.set(p, A::from(x));
                a[p] = x;
            } else if (t == 5) {
                int p = rng() % n;
                assert(seg.get(p).sum == a[p]);
            } else if (t == 6) {
                int p = rng() % n;
                seg.apply(p, A::add(x));
                a[p] += x;
            } else if (t == 7) {
                long long lim = a[rng() % n];
                int want = l;
                while (want < n && a[want] <= lim) want++;
                int got = seg.max_right(l, [&](A::S v) { return v.max <= lim; });
                assert(got == want);
                int want_l = r;
                while (want_l > 0 && a[want_l - 1] <= lim) want_l--;
                int got_l = seg.min_left(r, [&](A::S v) { return v.max <= lim; });
                assert(got_l == want_l);
            }
            A::S p = seg.prod(l, r);
            long long sum = 0, mn = std::numeric_limits<long long>::max(), mx = std::numeric_limits<long long>::lowest();
            for (int i = l; i < r; i++) {
                sum += a[i];
                mn = std::min(mn, a[i]);
                mx = std::max(mx, a[i]);
            }
            assert(p.sum == sum && p.min == mn && p.max == mx && !p.fail);
            A::S all = seg.all_prod();
            long long total = 0;
            for (long long v : a) total += v;
            assert(all.sum == total);
        }
    }
    std::cout << "Hello World\n";
}
