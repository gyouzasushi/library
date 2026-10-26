#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <atcoder/modint>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "math/bitwise_and_convolution.hpp"
#include "math/bitwise_or_convolution.hpp"
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
    // long long: convolutions against brute force, including n = 1
    for (int k = 0; k <= 6; k++) {
        int n = 1 << k;
        for (int trial = 0; trial < 5; trial++) {
            std::vector<long long> a(n), b(n), ca(n), co(n);
            for (auto& x : a) x = int(rng() % 2001) - 1000;
            for (auto& x : b) x = int(rng() % 2001) - 1000;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    ca[i & j] += a[i] * b[j];
                    co[i | j] += a[i] * b[j];
                }
            }
            assert(bitwise_and_convolution(a, b) == ca);
            assert(bitwise_or_convolution(a, b) == co);
        }
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
