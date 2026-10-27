#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include "algebra/monoid_add.hpp"
#include "algebra/monoid_min.hpp"
#include "datastructure/persistent_segtree.hpp"
template <class M, class Naive>
void stress(std::mt19937_64& rng, const Naive& naive) {
    using S = typename M::S;
    for (int iter = 0; iter < 200; iter++) {
        int n = 1 + rng() % 20;
        std::vector<S> init(n);
        for (auto& x : init) x = S(rng() % 100);
        persistent_segtree<M> seg(init);
        std::vector<std::vector<S>> versions{init};
        std::vector<int> roots{0};
        assert(seg.size() == n);
        for (int t = 0; t < 60; t++) {
            int k = rng() % roots.size();
            int p = rng() % n;
            S x = S(rng() % 100);
            roots.push_back(seg.set(roots[k], p, x));
            std::vector<S> v = versions[k];
            v[p] = x;
            versions.push_back(v);
            int c = rng() % roots.size();
            for (int i = 0; i < n; i++) assert(seg.get(roots[c], i) == versions[c][i]);
            for (int l = 0; l <= n; l++) {
                for (int r = l; r <= n; r++) {
                    S expect = M::e();
                    for (int i = l; i < r; i++) expect = naive(expect, versions[c][i]);
                    assert(seg.prod(roots[c], l, r) == expect);
                }
            }
            assert(seg.all_prod(roots[c]) == seg.prod(roots[c], 0, n));
        }
    }
}
int main() {
    std::mt19937_64 rng(20261027);
    stress<monoid_add<long long>>(rng, [](long long a, long long b) { return a + b; });
    stress<monoid_min<int>>(rng, [](int a, int b) { return std::min(a, b); });
    {
        persistent_segtree<monoid_add<int>> seg(0);
        assert(seg.all_prod(0) == 0 && seg.prod(0, 0, 0) == 0);
        persistent_segtree<monoid_add<int>> seg1(3);
        int r = seg1.set(0, 1, 5);
        assert(seg1.all_prod(0) == 0 && seg1.all_prod(r) == 5 && seg1.prod(r, 1, 2) == 5);
    }
    {
        int n = 200000, q = 200000;
        auto start = std::chrono::steady_clock::now();
        persistent_segtree<monoid_add<long long>> seg(n);
        std::vector<int> roots{0};
        long long acc = 0;
        for (int i = 0; i < q; i++) {
            int k = rng() % roots.size();
            roots.push_back(seg.set(roots[k], rng() % n, rng() % 1000));
            int l = rng() % n, r = rng() % n;
            if (l > r) std::swap(l, r);
            acc += seg.prod(roots[rng() % roots.size()], l, r + 1);
        }
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
        std::cerr << "perf n=q=" << n << ": " << ms << " ms (" << acc % 1000 << ")\n";
    }
    std::cout << "Hello World\n";
}
