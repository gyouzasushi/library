#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <atcoder/modint>
#include <cassert>
#include <iostream>
#include <random>
#include <set>
#include <vector>

#include "math/lagrange_interpolation.hpp"
using mint = atcoder::modint998244353;
mint eval(const std::vector<mint>& coef, mint c) {
    mint r = 0;
    for (int i = int(coef.size()) - 1; i >= 0; i--) r = r * c + coef[i];
    return r;
}
int main() {
    std::mt19937 rng(665);
    for (int it = 0; it < 500; it++) {
        int deg = rng() % 8;
        std::vector<mint> coef(deg + 1);
        for (auto& a : coef) a = rng();
        int n = deg + 1 + rng() % 3;  // extra points are fine
        std::vector<mint> y(n);
        for (int i = 0; i < n; i++) y[i] = eval(coef, i);
        for (int t = 0; t < 5; t++) {
            mint c = rng();
            assert(lagrange_interpolation(y, c) == eval(coef, c));
        }
        for (int i = 0; i < n; i++) assert(lagrange_interpolation(y, mint(i)) == y[i]);
        assert(lagrange_interpolation(y, mint(n)) == eval(coef, n));
        // arbitrary distinct points
        std::set<unsigned> used;
        std::vector<mint> xs, ys;
        while (int(xs.size()) < n) {
            unsigned v = rng();
            if (!used.insert(v).second) continue;
            xs.push_back(v);
            ys.push_back(eval(coef, v));
        }
        for (int t = 0; t < 5; t++) {
            mint c = rng();
            assert(lagrange_interpolation(xs, ys, c) == eval(coef, c));
        }
        for (int i = 0; i < n; i++) assert(lagrange_interpolation(xs, ys, xs[i]) == ys[i]);
    }
    {
        // n = 1: constant
        std::vector<mint> y{7};
        assert(lagrange_interpolation(y, mint(123456789)) == 7);
        assert(lagrange_interpolation(std::vector<mint>{5}, y, mint(3)) == 7);
    }
    {
        // sum of i^k, k = 3: n^2 (n+1)^2 / 4, with 1e5 points for timing
        int k = 3;
        std::vector<mint> y(k + 2);
        for (int i = 1; i <= k + 1; i++) y[i] = y[i - 1] + mint(i).pow(k);
        long long n = 1000000000000000LL;
        mint expect = mint(n) * mint(n) * mint(n + 1) * mint(n + 1) / 4;
        assert(lagrange_interpolation(y, mint(n)) == expect);
        std::vector<mint> big(200000);
        for (int i = 0; i < 200000; i++) big[i] = rng();
        lagrange_interpolation(big, mint(1000000));
    }
    std::cout << "Hello World" << std::endl;
}
