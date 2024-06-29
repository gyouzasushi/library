#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include <atcoder/modint>
#include <iostream>

#include "math/matrix.hpp"
using mint = atcoder::modint998244353;
int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    matrix<mint> a(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            std::cin >> x;
            a[i][j] = mint::raw(x);
        }
    }
    matrix<mint> b(m, k);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            int x;
            std::cin >> x;
            b[i][j] = mint::raw(x);
        }
    }
    matrix c = a * b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            std::cout << c[i][j].val() << " \n"[j == k - 1];
        }
    }
}