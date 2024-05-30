#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient"
#include "math/binomial_coefficient.hpp"

#include <iostream>
int main() {
    int t, m;
    std::cin >> t >> m;
    using binom = binomial_coefficient_arbitrary_mod;
    binom::set_mod(m);
    while (t--) {
        long long n, k;
        std::cin >> n >> k;
        std::cout << binom::C(n, k) << '\n';
    }
}