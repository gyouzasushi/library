#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <atcoder/modint>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "math/zeta_mobius_transform.hpp"
using mint = atcoder::modint998244353;
int main() {
    std::mt19937 rng(7959);
    for (int k = 0; k <= 8; k++) {
        int n = 1 << k;
        for (int trial = 0; trial < 5; trial++) {
            std::vector<mint> f(n);
            for (auto& x : f) x = rng();
            std::vector<mint> sup(n), sub(n);
            for (int s = 0; s < n; s++) {
                for (int t = 0; t < n; t++) {
                    if ((s & t) == s) sup[s] += f[t];
                    if ((s & t) == t) sub[s] += f[t];
                }
            }
            auto g = f;
            superset_zeta(g);
            assert(g == sup);
            superset_mobius(g);
            assert(g == f);
            g = f;
            subset_zeta(g);
            assert(g == sub);
            subset_mobius(g);
            assert(g == f);
        }
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
