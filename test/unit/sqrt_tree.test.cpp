#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <random>
#include <numeric>
#include <utility>
#include <vector>

#include "algebra/monoid_add.hpp"
#include "datastructure/sqrt_tree.hpp"

// non-commutative, non-idempotent: composition of x -> a x + b mod 1e9+7
struct affine {
    using S = std::pair<long long, long long>;
    static constexpr long long mod = 1000000007;
    static S op(S f, S g) {  // g after f
        return {g.first * f.first % mod, (g.first * f.second + g.second) % mod};
    }
};

int main() {
    std::mt19937 rng(31);
    for (int it = 0; it < 200; it++) {
        int n = 1 + rng() % 70;
        std::vector<long long> a(n);
        for (auto& x : a) x = rng() % 1000;
        std::vector<affine::S> f(n);
        for (auto& [p, q] : f) p = 1 + rng() % 1000, q = rng() % 1000;
        sqrt_tree<monoid_add<long long>> sa(a);
        sqrt_tree<affine> sf(f);
        for (int l = 0; l < n; l++) {
            long long sum = 0;
            affine::S comp = {1, 0};
            for (int r = l + 1; r <= n; r++) {
                sum += a[r - 1];
                comp = affine::op(comp, f[r - 1]);
                assert(sa.prod(l, r) == sum);
                assert(sf.prod(l, r) == comp);
            }
        }
    }
    {
        int n = 500000;
        std::vector<long long> a(n);
        for (auto& x : a) x = rng() % 1000;
        sqrt_tree<monoid_add<long long>> s(a);
        assert(s.prod(0, n) == std::accumulate(a.begin(), a.end(), 0LL));
    }
    std::cout << "Hello World" << std::endl;
}
