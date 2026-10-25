#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_A"
#include <iostream>

#include "math/sieve.hpp"

int main() {
    int n;
    std::cin >> n;
    sieve s(n);
    std::cout << n << ':';
    for (auto [p, e] : s.factorize(n)) {
        for (int i = 0; i < e; i++) std::cout << ' ' << p;
    }
    std::cout << '\n';
}
