#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"
#include <atcoder/modint>
#include <iostream>
#include <vector>

#include "math/matrix.hpp"
using mint = atcoder::modint998244353;
int main() {
    int n;
    std::cin >> n;
    matrix<mint> a(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            std::cin >> x;
            a[i][j] = x;
        }
    }
    auto b = inverse(a);
    if (!b) {
        std::cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) std::cout << (*b)[i][j].val() << " \n"[j + 1 == n];
    }
}
