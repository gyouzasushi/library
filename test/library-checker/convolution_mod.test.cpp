#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include <iostream>

#include "../../math/convolution.hpp"
using mint = modint998244353;
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<mint> a(n), b(m);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < m; i++) std::cin >> b[i];
    std::vector<mint> c = convolution(a, b);
    for (int i = 0; i <= (n - 1) + (m - 1); i++) {
        std::cout << c[i] << " \n"[i == (n - 1) + (m - 1)];
    }
}