#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "../../math/bitwise_or_convolution.hpp"

#include <iostream>

#include "../../math/modint.hpp"

using mint = modint998244353;
int main() {
    int n;
    std::cin >> n;
    int mask = (1 << n) - 1;
    std::vector<mint> a(1 << n), b(1 << n);
    for (int i = 0; i < (1 << n); i++) std::cin >> a[i ^ mask];
    for (int i = 0; i < (1 << n); i++) std::cin >> b[i ^ mask];

    std::vector<mint> c = bitwise_or_convolution(a, b);
    for (int i = 0; i < (1 << n); i++) {
        std::cout << c[i ^ mask] << " \n"[i == (1 << n) - 1];
    }
}