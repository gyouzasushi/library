#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
#include <iostream>

#include "atcoder/modint"
#include "math/binomial_coefficient.hpp"
using mint = atcoder::modint;
using binom = binomial_coefficient<mint>;
mint lucas(int n, int k) {
    if (n < 0 || n < k || k < 0) return 0;
    int m = mint::mod();
    mint ret = 1;
    while (n > 0) {
        ret *= binom::C(n % m, k % m);
        n /= m, k /= m;
    }
    return ret;
}
int main() {
    int T, m;
    std::cin >> T >> m;
    mint::set_mod(m);
    while (T--) {
        int n, k;
        std::cin >> n >> k;
        std::cout << lucas(n, k).val() << '\n';
    }
}