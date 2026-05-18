#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

#include "datastructure/dual_segtree.hpp"
using F = std::pair<long long, long long>;
F composition(F f, F g) {
    return {f.first * g.first, f.first * g.second + f.second};
}
F id() {
    return {1, 0};
}
void stress(bool is_commutative, std::mt19937 &rng) {
    const int N = 30;
    const int Q = 2000;
    dual_segtree<F, composition, id> seg(N, is_commutative);
    std::vector<F> naive(N, id());
    auto gen = [&]() -> F {
        if (is_commutative) {
            return {1, (long long)(rng() % 10)};
        } else {
            return {(long long)(rng() % 5), (long long)(rng() % 5)};
        }
    };
    for (int q = 0; q < Q; q++) {
        int t = rng() % 3;
        if (t == 0) {
            int l = rng() % N;
            int r = l + 1 + rng() % (N - l);
            F f = gen();
            seg.apply(l, r, f);
            for (int i = l; i < r; i++) naive[i] = composition(f, naive[i]);
        } else if (t == 1) {
            int p = rng() % N;
            F v = gen();
            seg.set(p, v);
            naive[p] = v;
        } else {
            int p = rng() % N;
            assert(seg.get(p) == naive[p]);
        }
    }
}
int main() {
    std::mt19937 rng(7959);
    for (int trial = 0; trial < 20; trial++) {
        stress(false, rng);
        stress(true, rng);
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
