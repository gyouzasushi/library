#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
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
    std::cout << determinant(a).val() << '\n';
}
