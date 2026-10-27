#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <atcoder/modint>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "math/linear_recurrence.hpp"
using mint = atcoder::modint998244353;
std::vector<mint> generate(const std::vector<mint>& init, const std::vector<mint>& c, int n) {
    std::vector<mint> a = init;
    a.resize(n);
    int d = int(c.size());
    for (int i = int(init.size()); i < n; i++) {
        a[i] = 0;
        for (int j = 0; j < d; j++) a[i] += c[j] * a[i - 1 - j];
    }
    return a;
}
bool satisfies(const std::vector<mint>& a, const std::vector<mint>& c) {
    int d = int(c.size());
    for (int i = d; i < int(a.size()); i++) {
        mint s = 0;
        for (int j = 0; j < d; j++) s += c[j] * a[i - 1 - j];
        if (s != a[i]) return false;
    }
    return true;
}
int main() {
    std::mt19937 rng(998244353);
    for (int it = 0; it < 500; it++) {
        int d = rng() % 7;
        std::vector<mint> init(d), c(d);
        for (auto& x : init) x = rng();
        for (auto& x : c) x = rng();
        int n = 2 * d + rng() % 6;
        std::vector<mint> a = generate(init, c, n);
        std::vector<mint> got = berlekamp_massey(a);
        assert(int(got.size()) <= d);
        assert(satisfies(a, got));
        // the found recurrence predicts the true sequence far ahead (n >= 2d)
        std::vector<mint> far = generate(init, c, 60);
        for (int k = 0; k < 60; k++) assert(kth_term_of_linear_recurrence(a, got, k) == far[k]);
        for (int k : {100, 12345, 1000000007}) {
            long long kk = k;
            std::vector<mint> seq = generate(init, c, int(std::min<long long>(kk + 1, 20000)));
            if (kk < 20000) assert(kth_term_of_linear_recurrence(init, c, kk) == seq[kk]);
        }
    }
    {
        std::vector<mint> fib{0, 1, 1, 2, 3, 5, 8, 13};
        assert((berlekamp_massey(fib) == std::vector<mint>{1, 1}));
        assert(kth_term_of_linear_recurrence(fib, berlekamp_massey(fib), 90).val() == 2880067194370816120ULL % 998244353);
        assert((berlekamp_massey(std::vector<mint>{3, 3, 3, 3}) == std::vector<mint>{1}));
        assert(berlekamp_massey(std::vector<mint>{0, 0, 0}).empty());
        assert(berlekamp_massey(std::vector<mint>{}).empty());
        assert(kth_term_of_linear_recurrence(std::vector<mint>{0, 0}, {}, 5) == 0);
        assert(kth_term_of_linear_recurrence(std::vector<mint>{7}, {}, 0) == 7);
    }
    {
        // n = 1e4 random: time
        std::vector<mint> a(10000);
        for (auto& x : a) x = rng();
        std::vector<mint> c = berlekamp_massey(a);
        assert(int(c.size()) <= 5000 && satisfies(a, c));
    }
    std::cout << "Hello World" << std::endl;
}
