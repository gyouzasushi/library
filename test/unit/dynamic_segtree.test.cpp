#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <map>
#include <random>
#include <vector>

#include "algebra/monoid_add.hpp"
#include "algebra/monoid_affine.hpp"
#include "algebra/monoid_max.hpp"
#include "datastructure/dynamic_segtree.hpp"
bool at_most_10(long long x) {
    return x <= 10;
}
void stress_small(std::mt19937& rng) {
    const long long lo = -(long long)(rng() % 20), hi = lo + 1 + rng() % 40;
    const long long n = hi - lo;
    std::vector<long long> a(n, 0);
    dynamic_segtree<monoid_add<long long>> seg(lo, hi);
    for (int it = 0; it < 300; it++) {
        int type = rng() % 5;
        if (type == 0) {
            long long p = lo + rng() % n;
            long long x = rng() % 5;
            a[p - lo] = x;
            seg.set(p, x);
        } else if (type == 1) {
            long long p = lo + rng() % n;
            assert(seg.get(p) == a[p - lo]);
        } else if (type == 2) {
            long long l = lo + rng() % (n + 1), r = lo + rng() % (n + 1);
            if (l > r) std::swap(l, r);
            long long expect = 0;
            for (long long i = l; i < r; i++) expect += a[i - lo];
            assert(seg.prod(l, r) == expect);
        } else if (type == 3) {
            long long l = lo + rng() % (n + 1);
            long long k = rng() % 15;
            long long r = l, sum = 0;
            while (r < hi && sum + a[r - lo] <= k) sum += a[r - lo], r++;
            assert(seg.max_right(l, [&](long long x) { return x <= k; }) == r);
            if (k == 10) assert(seg.max_right<at_most_10>(l) == r);
        } else {
            long long r = lo + rng() % (n + 1);
            long long k = rng() % 15;
            long long l = r, sum = 0;
            while (l > lo && sum + a[l - 1 - lo] <= k) sum += a[l - 1 - lo], l--;
            assert(seg.min_left(r, [&](long long x) { return x <= k; }) == l);
        }
    }
    long long total = 0;
    for (long long x : a) total += x;
    assert(seg.all_prod() == total);
}
void stress_wide(std::mt19937& rng) {
    dynamic_segtree<monoid_max<long long>> seg;
    std::map<long long, long long> a;
    const long long lim = 1LL << 62;
    for (int it = 0; it < 300; it++) {
        long long p = (long long)(rng() % (2 * (unsigned long long)lim)) - lim;
        if (rng() % 2) p = (long long)(rng() % 100) - 50;
        if (rng() % 2) {
            long long x = rng() % 1000;
            a[p] = x;
            seg.set(p, x);
        } else {
            long long q = (long long)(rng() % (2 * (unsigned long long)lim)) - lim;
            long long l = std::min(p, q), r = std::max(p, q) + 1;
            long long expect = monoid_max<long long>::e();
            for (auto it2 = a.lower_bound(l); it2 != a.end() && it2->first < r; ++it2) expect = std::max(expect, it2->second);
            assert(seg.prod(l, r) == expect);
        }
    }
}
void stress_noncommutative(std::mt19937& rng) {
    using M = monoid_affine<long long>;
    const long long n = 1 + rng() % 30;
    std::vector<M::S> a(n, M::e());
    dynamic_segtree<M> seg(0, n);
    for (int it = 0; it < 200; it++) {
        if (rng() % 2) {
            long long p = rng() % n;
            a[p] = {(long long)(rng() % 3), (long long)(rng() % 3)};
            seg.set(p, a[p]);
        } else {
            long long l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            M::S expect = M::e();
            for (long long i = l; i < r; i++) expect = M::op(expect, a[i]);
            M::S got = seg.prod(l, r);
            assert(M::eval(got, 7) == M::eval(expect, 7));
        }
    }
}
int main() {
    std::mt19937 rng(20261028);
    for (int trial = 0; trial < 100; trial++) {
        stress_small(rng);
        stress_wide(rng);
        stress_noncommutative(rng);
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
