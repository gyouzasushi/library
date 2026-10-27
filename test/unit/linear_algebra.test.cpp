#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <atcoder/modint>
#include <cassert>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "math/matrix.hpp"
using mint = atcoder::modint998244353;
mint det_brute(const matrix<mint>& a) {
    int n = a.height();
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    mint ret = 0;
    do {
        mint term = 1;
        for (int i = 0; i < n; i++) term *= a[i][p[i]];
        int inv = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) inv += p[i] > p[j];
        ret += inv & 1 ? -term : term;
    } while (std::next_permutation(p.begin(), p.end()));
    return ret;
}
// rank = largest k with a nonsingular k x k minor
int rank_brute(const matrix<mint>& a) {
    int h = a.height(), w = a.width();
    for (int k = std::min(h, w); k >= 1; k--) {
        for (int rs = 0; rs < (1 << h); rs++) {
            if (__builtin_popcount(rs) != k) continue;
            for (int cs = 0; cs < (1 << w); cs++) {
                if (__builtin_popcount(cs) != k) continue;
                matrix<mint> m(k, k);
                int i = 0;
                for (int r = 0; r < h; r++) {
                    if (!(rs >> r & 1)) continue;
                    int j = 0;
                    for (int c = 0; c < w; c++) {
                        if (cs >> c & 1) m[i][j++] = a[r][c];
                    }
                    i++;
                }
                if (det_brute(m) != 0) return k;
            }
        }
    }
    return 0;
}
std::vector<mint> mul(const matrix<mint>& a, const std::vector<mint>& x) {
    std::vector<mint> y(a.height());
    for (int i = 0; i < a.height(); i++)
        for (int j = 0; j < a.width(); j++) y[i] += a[i][j] * x[j];
    return y;
}
int main() {
    std::mt19937 rng(2026);
    auto rnd = [&](int h, int w, int small) {
        matrix<mint> a(h, w);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++) a[i][j] = small ? int(rng() % 3) : int(rng());
        return a;
    };
    for (int it = 0; it < 300; it++) {
        int n = rng() % 6;
        matrix<mint> a = rnd(n, n, rng() % 2);
        mint d = determinant(a);
        assert(d == det_brute(a));
        auto inv = inverse(a);
        assert(inv.has_value() == (d != 0));
        if (inv) {
            assert(a * *inv == matrix<mint>::e(n));
            assert(*inv * a == matrix<mint>::e(n));
            assert(determinant(*inv) * d == 1);
        }
        assert(matrix_rank(a) == rank_brute(a));
    }
    for (int it = 0; it < 300; it++) {
        int h = rng() % 5, w = rng() % 5;
        matrix<mint> a = rnd(h, w, rng() % 2);
        assert(matrix_rank(a) == rank_brute(a));
        std::vector<mint> b(h);
        bool consistent = rng() % 2;
        if (consistent) {
            std::vector<mint> x0(w);
            for (auto& v : x0) v = int(rng() % 5);
            b = mul(a, x0);
        } else {
            for (auto& v : b) v = int(rng() % 3);
        }
        auto s = solve_linear_system(a, b);
        if (consistent) assert(s.has_value());
        if (!s) {
            // b not in column space: rank of [a | b] exceeds rank of a
            matrix<mint> ab(h, w + 1);
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) ab[i][j] = a[i][j];
                ab[i][w] = b[i];
            }
            assert(matrix_rank(ab) == matrix_rank(a) + 1);
            continue;
        }
        int r = matrix_rank(a);
        assert(int(s->kernel.size()) == w - r);
        assert(mul(a, s->x) == b);
        matrix<mint> k(int(s->kernel.size()), w);
        for (int i = 0; i < int(s->kernel.size()); i++) {
            assert(mul(a, s->kernel[i]) == std::vector<mint>(h));
            k[i] = s->kernel[i];
        }
        assert(matrix_rank(k) == int(s->kernel.size()));
    }
    {
        // 0 x 0
        matrix<mint> z(0, 0);
        assert(determinant(z) == 1 && inverse(z).has_value() && matrix_rank(z) == 0);
        auto s = solve_linear_system(z, {});
        assert(s && s->x.empty() && s->kernel.empty());
        // 500 x 500 timing
        matrix<mint> a = rnd(500, 500, 0);
        determinant(a);
        inverse(a);
        matrix_rank(a);
        solve_linear_system(a, std::vector<mint>(500, 1));
    }
    std::cout << "Hello World" << std::endl;
}
