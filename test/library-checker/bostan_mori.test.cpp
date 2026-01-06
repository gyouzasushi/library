#define PROBLEM \
    "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"
#include "../../math/bostan_mori.hpp"

#include <iostream>

using mint = atcoder::modint998244353;

int main() {
    int d;
    long long k;
    std::cin >> d >> k;
    std::vector<mint> a(d);
    for (int i = 0; i < d; i++) {
        int x;
        std::cin >> x;
        a[i] = mint(x);
    }
    std::vector<mint> c(d + 1, 1);
    for (int i = 1; i <= d; i++) {
        int x;
        std::cin >> x;
        c[i] = mint(-x);
    }
    std::vector b = atcoder::convolution(a, c);
    b.resize(a.size());
    std::cout << bostan_mori(k, b, c).val() << '\n';
}