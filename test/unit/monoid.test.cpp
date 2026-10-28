#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "algebra/range_add_range_max.hpp"
#include "algebra/range_add_range_min.hpp"
#include "algebra/range_add_range_sum.hpp"
#include "algebra/range_add_range_sum_of_squares.hpp"
#include "algebra/range_assign_range_max.hpp"
#include "algebra/range_assign_range_min.hpp"
#include "algebra/range_assign_range_sum.hpp"
#include "datastructure/lazy_segtree.hpp"
#include "datastructure/segtree.hpp"
#include "algebra/monoid_add.hpp"
#include "algebra/monoid_affine.hpp"
#include "algebra/monoid_argmax.hpp"
#include "algebra/monoid_argmin.hpp"
#include "algebra/monoid_gcd.hpp"
#include "algebra/monoid_max.hpp"
#include "algebra/monoid_min.hpp"
#include "algebra/monoid_xor.hpp"
template <class M, class Naive>
void stress_monoid(std::mt19937 &rng, const Naive &naive) {
    using S = typename M::S;
    const int N = 1 + rng() % 30;
    std::vector<S> a(N);
    for (auto &x : a) x = S(rng() % 100);
    segtree<M> seg(a);
    for (int it = 0; it < 200; it++) {
        if (rng() % 2) {
            int p = rng() % N;
            a[p] = S(rng() % 100);
            seg.set(p, a[p]);
        } else {
            int l = rng() % (N + 1), r = rng() % (N + 1);
            if (l > r) std::swap(l, r);
            S expect = M::e();
            for (int i = l; i < r; i++) expect = naive(expect, a[i]);
            assert(seg.prod(l, r) == expect);
        }
    }
}
template <class M, class Naive>
void stress_argmonoid(std::mt19937 &rng, const Naive &better) {
    using S = typename M::S;
    const int N = 1 + rng() % 30;
    std::vector<S> a(N);
    for (int i = 0; i < N; i++) a[i] = {int(rng() % 5), i};
    segtree<M> seg(a);
    for (int it = 0; it < 200; it++) {
        if (rng() % 2) {
            int p = rng() % N;
            a[p] = {int(rng() % 5), p};
            seg.set(p, a[p]);
        } else {
            int l = rng() % (N + 1), r = rng() % (N + 1);
            if (l > r) std::swap(l, r);
            S got = seg.prod(l, r);
            if (l == r) {
                assert(got.id == -1);
                continue;
            }
            int best = l;
            for (int i = l + 1; i < r; i++) {
                if (better(a[i].val, a[best].val)) best = i;
            }
            assert(got.id == best && got.val == a[best].val);
        }
    }
}
void stress_affine(std::mt19937 &rng) {
    using M = monoid_affine<long long>;
    constexpr long long MOD = 998244353;
    const int N = 1 + rng() % 30;
    std::vector<M::S> a(N);
    for (auto &f : a) f = {(long long)(rng() % 5), (long long)(rng() % 5)};
    segtree<M> seg(a);
    for (int it = 0; it < 200; it++) {
        if (rng() % 2) {
            int p = rng() % N;
            a[p] = {(long long)(rng() % 5), (long long)(rng() % 5)};
            seg.set(p, a[p]);
        } else {
            int l = rng() % (N + 1), r = rng() % (N + 1);
            if (l > r) std::swap(l, r);
            long long x = rng() % 10, y = x;
            for (int i = l; i < r; i++) y = M::eval(a[i], y) % MOD;
            assert(M::eval(seg.prod(l, r), x) % MOD == y);
        }
    }
}
void stress_range_add_range_sum(std::mt19937 &rng) {
    using A = range_add_range_sum<long long>;
    const int N = 1 + rng() % 30;
    std::vector<long long> a(N);
    std::vector<A::S> init(N);
    for (int i = 0; i < N; i++) {
        a[i] = rng() % 100;
        init[i] = A::from(a[i]);
    }
    lazy_segtree<A> seg(init);
    for (int it = 0; it < 200; it++) {
        int l = rng() % (N + 1), r = rng() % (N + 1);
        if (l > r) std::swap(l, r);
        if (rng() % 2) {
            long long x = rng() % 100;
            for (int i = l; i < r; i++) a[i] += x;
            seg.apply(l, r, x);
        } else {
            long long expect = 0;
            for (int i = l; i < r; i++) expect += a[i];
            assert(seg.prod(l, r).sum == expect);
            assert(seg.prod(l, r).len == r - l);
        }
    }
}
template <class A, class Naive>
void stress_range_add(std::mt19937 &rng, const Naive &naive) {
    const int N = 1 + rng() % 30;
    std::vector<long long> a(N);
    for (auto &x : a) x = (long long)(rng() % 100) - 50;
    lazy_segtree<A> seg(a);
    for (int it = 0; it < 200; it++) {
        int l = rng() % (N + 1), r = rng() % (N + 1);
        if (l > r) std::swap(l, r);
        if (rng() % 2) {
            long long x = (long long)(rng() % 100) - 50;
            for (int i = l; i < r; i++) a[i] += x;
            seg.apply(l, r, x);
        } else {
            long long expect = A::e();
            for (int i = l; i < r; i++) expect = naive(expect, a[i]);
            assert(seg.prod(l, r) == expect);
        }
    }
}
void stress_range_add_range_sum_of_squares(std::mt19937 &rng) {
    using A = range_add_range_sum_of_squares<long long>;
    const int N = 1 + rng() % 30;
    std::vector<long long> a(N);
    std::vector<A::S> init(N);
    for (int i = 0; i < N; i++) {
        a[i] = (long long)(rng() % 100) - 50;
        init[i] = A::from(a[i]);
    }
    lazy_segtree<A> seg(init);
    for (int it = 0; it < 200; it++) {
        int l = rng() % (N + 1), r = rng() % (N + 1);
        if (l > r) std::swap(l, r);
        if (rng() % 2) {
            long long x = (long long)(rng() % 100) - 50;
            for (int i = l; i < r; i++) a[i] += x;
            seg.apply(l, r, x);
        } else {
            long long sum = 0, sq = 0;
            for (int i = l; i < r; i++) sum += a[i], sq += a[i] * a[i];
            A::S got = seg.prod(l, r);
            assert(got.sum == sum && got.sum_of_squares == sq && got.len == r - l);
        }
    }
}
template <class A, class Naive>
void stress_range_assign(std::mt19937 &rng, const Naive &naive) {
    const int N = 1 + rng() % 30;
    std::vector<long long> a(N);
    for (auto &x : a) x = (long long)(rng() % 100) - 50;
    lazy_segtree<A> seg(a);
    for (int it = 0; it < 200; it++) {
        int l = rng() % (N + 1), r = rng() % (N + 1);
        if (l > r) std::swap(l, r);
        if (rng() % 2) {
            long long x = (long long)(rng() % 100) - 50;
            for (int i = l; i < r; i++) a[i] = x;
            seg.apply(l, r, x);
        } else {
            long long expect = A::e();
            for (int i = l; i < r; i++) expect = naive(expect, a[i]);
            assert(seg.prod(l, r) == expect);
        }
    }
}
void stress_range_assign_range_sum(std::mt19937 &rng) {
    using A = range_assign_range_sum<long long>;
    const int N = 1 + rng() % 30;
    std::vector<long long> a(N);
    std::vector<A::S> init(N);
    for (int i = 0; i < N; i++) {
        a[i] = (long long)(rng() % 100) - 50;
        init[i] = A::from(a[i]);
    }
    lazy_segtree<A> seg(init);
    for (int it = 0; it < 200; it++) {
        int l = rng() % (N + 1), r = rng() % (N + 1);
        if (l > r) std::swap(l, r);
        if (rng() % 2) {
            long long x = (long long)(rng() % 100) - 50;
            for (int i = l; i < r; i++) a[i] = x;
            seg.apply(l, r, x);
        } else {
            long long expect = 0;
            for (int i = l; i < r; i++) expect += a[i];
            assert(seg.prod(l, r).sum == expect);
            assert(seg.prod(l, r).len == r - l);
        }
    }
}
int main() {
    std::mt19937 rng(7959);
    for (int trial = 0; trial < 100; trial++) {
        stress_monoid<monoid_add<long long>>(rng, [](long long a, long long b) { return a + b; });
        stress_monoid<monoid_min<int>>(rng, [](int a, int b) { return std::min(a, b); });
        stress_monoid<monoid_max<int>>(rng, [](int a, int b) { return std::max(a, b); });
        stress_monoid<monoid_gcd<int>>(rng, [](int a, int b) { return std::gcd(a, b); });
        stress_monoid<monoid_xor<unsigned>>(rng, [](unsigned a, unsigned b) { return a ^ b; });
        stress_argmonoid<monoid_argmin<int>>(rng, [](int a, int b) { return a < b; });
        stress_argmonoid<monoid_argmax<int>>(rng, [](int a, int b) { return a > b; });
        stress_affine(rng);
        stress_range_add_range_sum(rng);
        stress_range_add<range_add_range_min<long long>>(rng, [](long long a, long long b) { return std::min(a, b); });
        stress_range_add<range_add_range_max<long long>>(rng, [](long long a, long long b) { return std::max(a, b); });
        stress_range_add_range_sum_of_squares(rng);
        stress_range_assign<range_assign_range_min<long long>>(rng, [](long long a, long long b) { return std::min(a, b); });
        stress_range_assign<range_assign_range_max<long long>>(rng, [](long long a, long long b) { return std::max(a, b); });
        stress_range_assign_range_sum(rng);
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
