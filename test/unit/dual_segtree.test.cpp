#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "datastructure/dual_segtree.hpp"
struct range_affine {
    struct F {
        long long a, b;
        bool operator==(const F&) const = default;
    };
    static F composition(F f, F g) { return {f.a * g.a, f.a * g.b + f.b}; }
    static F id() { return {1, 0}; }
    static constexpr bool composition_commutative = false;
};
template <bool commutative>
struct range_add {
    using F = long long;
    static F composition(F f, F g) { return f + g; }
    static F id() { return 0; }
    static constexpr bool composition_commutative = commutative;
};
template <class A>
void stress(std::mt19937& rng, auto gen) {
    using F = typename A::F;
    const int N = 1 + rng() % 40;
    const int Q = 2000;
    std::vector<F> init(N);
    for (auto& x : init) x = gen();
    dual_segtree<A> seg(init);
    std::vector<F> naive = init;
    for (int q = 0; q < Q; q++) {
        int t = rng() % 3;
        if (t == 0) {
            int l = rng() % (N + 1);
            int r = rng() % (N + 1);
            if (l > r) std::swap(l, r);
            F f = gen();
            seg.apply(l, r, f);
            for (int i = l; i < r; i++) naive[i] = A::composition(f, naive[i]);
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
    auto gen_aff = [&]() -> range_affine::F { return {(long long)(rng() % 5), (long long)(rng() % 5)}; };
    auto gen_add = [&]() -> long long { return rng() % 10; };
    for (int trial = 0; trial < 30; trial++) {
        stress<range_affine>(rng, gen_aff);
        stress<range_add<true>>(rng, gen_add);
        stress<range_add<false>>(rng, gen_add);
    }
    {
        dual_segtree<range_add<true>> seg;
        dual_segtree<range_add<true>> seg1(1);
        seg1.apply(0, 1, 3);
        assert(seg1.get(0) == 3);
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
