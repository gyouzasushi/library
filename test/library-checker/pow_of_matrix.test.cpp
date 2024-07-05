#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"
#include <atcoder/modint>
#include <iostream>

#include "math/matrix.hpp"

using mint = atcoder::modint998244353;
int main() {
    int n;
    long long k;
    std::cin >> n >> k;
    matrix<mint> a(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            std::cin >> x;
            a[i][j] = mint::raw(x);
        }
    }
    matrix b = a.pow(k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << b[i][j].val() << " \n"[j == n - 1];
        }
    }
}