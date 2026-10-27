#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"
#include <atcoder/modint>
#include <iostream>
#include <vector>

#include "math/matrix.hpp"
using mint = atcoder::modint998244353;
int main() {
    int n, m;
    std::cin >> n >> m;
    matrix<mint> a(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            std::cin >> x;
            a[i][j] = x;
        }
    }
    std::cout << matrix_rank(a) << '\n';
}
