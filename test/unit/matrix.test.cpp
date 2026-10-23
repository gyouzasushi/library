#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <atcoder/modint>
#include <cassert>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

#include "algebra/semiring_max_plus.hpp"
#include "algebra/semiring_min_plus.hpp"
#include "math/matrix.hpp"
using mint = atcoder::modint998244353;
int main() {
    std::mt19937 rng(7959);
    for (int trial = 0; trial < 50; trial++) {
        int n = 1 + rng() % 5, m = 1 + rng() % 5, k = 1 + rng() % 5;
        matrix<mint> a(n, m), b(m, k), c(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) a[i][j] = rng(), c[i][j] = rng();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < k; j++) b[i][j] = rng();
        auto ab = a * b;
        assert(ab.height() == n && ab.width() == k);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                mint s = 0;
                for (int l = 0; l < m; l++) s += a[i][l] * b[l][j];
                assert(ab[i][j] == s);
            }
        }
        auto ac = a + c;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) assert(ac[i][j] == a[i][j] + c[i][j]);
        auto d = a;
        d += c;
        assert(d == ac);
        matrix<mint> sq(n, n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) sq[i][j] = rng() % 3;
        int e = rng() % 6;
        auto naive = matrix<mint>::e(n);
        for (int t = 0; t < e; t++) naive *= sq;
        assert(sq.pow(e) == naive);
        assert(sq * matrix<mint>::e(n) == sq);
    }
    for (int trial = 0; trial < 50; trial++) {
        using R = semiring_min_plus<long long>;
        const long long inf = R::zero();
        int n = 1 + rng() % 5;
        semiring_matrix<R> g(n, n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (rng() % 2) g[i][j] = rng() % 10;
        int k = rng() % 6;
        std::vector<std::vector<long long>> dp(n, std::vector<long long>(n, inf));
        for (int i = 0; i < n; i++) dp[i][i] = 0;
        for (int t = 0; t < k; t++) {
            std::vector<std::vector<long long>> nx(n, std::vector<long long>(n, inf));
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (dp[i][j] != inf)
                        for (int l = 0; l < n; l++)
                            if (g[j][l] != inf) nx[i][l] = std::min(nx[i][l], dp[i][j] + g[j][l]);
            dp = nx;
        }
        assert(g.pow(k) == semiring_matrix<R>(dp));
    }
    {
        using R = semiring_max_plus<long long>;
        semiring_matrix<R> g(std::vector<std::vector<long long>>{{R::zero(), 3}, {5, R::zero()}});
        auto g2 = g * g;
        assert(g2[0][0] == 8 && g2[1][1] == 8 && g2[0][1] == R::zero());
        assert(semiring_matrix<R>::e(2)[0][1] == R::zero() && semiring_matrix<R>::e(2)[0][0] == 0);
    }
    {
        matrix<int> z;
        assert(z.height() == 0 && z.width() == 0);
        assert(matrix<int>(0, 0).pow(5) == matrix<int>());
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
