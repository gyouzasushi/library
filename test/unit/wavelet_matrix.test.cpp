#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "datastructure/wavelet_matrix.hpp"

template <class T, class S>
void check(const std::vector<T>& a, const std::vector<S>& w, std::mt19937& rng, T lo_v, T hi_v) {
    int n = int(a.size());
    wavelet_matrix<T, S> wm(a, w);
    wavelet_matrix<T> wc(a);
    assert(wm.size() == n && wc.size() == n);
    auto rnd_v = [&](T lo, T hi) { return T(lo + (long long)(rng() % (unsigned long long)(hi - lo + 1))); };
    for (int it = 0; it < 300; it++) {
        int l = rng() % (n + 1), r = rng() % (n + 1);
        if (l > r) std::swap(l, r);
        T x = rnd_v(lo_v - 2, hi_v + 2), y = rnd_v(lo_v - 2, hi_v + 2);
        // count / sum
        int c1 = 0, c2 = 0;
        S s1 = S(), s2 = S();
        for (int i = l; i < r; i++) {
            if (a[i] < x) c1++, s1 += w[i];
            if (x <= a[i] && a[i] < y) c2++, s2 += w[i];
        }
        assert(wm.count(l, r, x) == c1 && wc.count(l, r, x) == c1);
        assert(wm.count(l, r, x, y) == c2 && wc.count(l, r, x, y) == c2);
        assert(wm.sum(l, r, x) == s1);
        assert(wm.sum(l, r, x, y) == s2);
        // prev / next
        std::optional<T> pv, nv;
        for (int i = l; i < r; i++) {
            if (a[i] < x && (!pv || *pv < a[i])) pv = a[i];
            if (x <= a[i] && (!nv || a[i] < *nv)) nv = a[i];
        }
        assert(wm.prev_value(l, r, x) == pv && wc.prev_value(l, r, x) == pv);
        assert(wm.next_value(l, r, x) == nv && wc.next_value(l, r, x) == nv);
        // kth / sum_smallest
        std::vector<int> idx(r - l);
        for (int i = l; i < r; i++) idx[i - l] = i;
        std::sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] != a[j] ? a[i] < a[j] : i < j; });
        S acc = S();
        assert(wm.sum_smallest(l, r, 0) == acc);
        for (int k = 0; k < r - l; k++) {
            assert(wm.kth_smallest(l, r, k) == a[idx[k]]);
            assert(wc.kth_smallest(l, r, k) == a[idx[k]]);
            assert(wm.kth_largest(l, r, k) == a[idx[r - l - 1 - k]]);
            acc += w[idx[k]];
            assert(wm.sum_smallest(l, r, k + 1) == acc);
        }
    }
}

int main() {
    std::mt19937 rng(12345);
    for (int it = 0; it < 200; it++) {
        int n = rng() % 30;
        int range = 1 + rng() % 20;
        std::vector<int> a(n);
        std::vector<long long> w(n);
        for (int i = 0; i < n; i++) {
            a[i] = int(rng() % range) - range / 2;
            w[i] = (long long)(rng() % 1000) - 500;
        }
        check<int, long long>(a, w, rng, -range / 2, range - range / 2);
    }
    // long long keys with large magnitude, few distinct values
    for (int it = 0; it < 50; it++) {
        int n = 1 + rng() % 40;
        std::vector<long long> a(n), w(n);
        std::vector<long long> pool = {-(1LL << 60), -7, 0, 3, 1LL << 62};
        int k = 1 + rng() % 5;
        for (int i = 0; i < n; i++) {
            a[i] = pool[rng() % k];
            w[i] = (long long)(rng() % 100);
        }
        wavelet_matrix<long long, long long> wm(a, w);
        for (int q = 0; q < 100; q++) {
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            long long x = pool[rng() % 5] + (long long)(rng() % 3) - 1;
            int c = 0;
            long long s = 0;
            for (int i = l; i < r; i++) if (a[i] < x) c++, s += w[i];
            assert(wm.count(l, r, x) == c && wm.sum(l, r, x) == s);
            if (r > l) {
                std::vector<long long> b(a.begin() + l, a.begin() + r);
                std::sort(b.begin(), b.end());
                int kk = rng() % (r - l);
                assert(wm.kth_smallest(l, r, kk) == b[kk]);
            }
        }
    }
    // weights equal to the values
    {
        std::vector<int> a = {5, 1, 4, 1, 3};
        wavelet_matrix<int, long long> wm(a, std::vector<long long>(a.begin(), a.end()));
        assert(wm.sum_smallest(0, 5, 3) == 5);
        assert(wm.sum(0, 5, 1, 4) == 5);
        assert(wm.kth_smallest(0, 5, 2) == 3);
        assert(wm.kth_largest(0, 5, 0) == 5);
        assert(!wm.prev_value(0, 5, 1));
        assert(*wm.next_value(0, 5, 4) == 4);
        assert(!wm.next_value(0, 5, 6));
    }
    // empty
    {
        wavelet_matrix<int, long long> wm({}, {});
        assert(wm.size() == 0);
        assert(wm.count(0, 0, 10) == 0);
        assert(wm.sum(0, 0, 10) == 0);
        assert(wm.sum_smallest(0, 0, 0) == 0);
        assert(!wm.prev_value(0, 0, 10));
        wavelet_matrix<int> e;
        assert(e.size() == 0);
        wavelet_matrix<int, long long> ew;
        assert(ew.size() == 0 && ew.sum(0, 0, 0) == 0);
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
