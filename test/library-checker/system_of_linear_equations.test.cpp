#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"
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
    std::vector<mint> b(n);
    for (auto& x : b) {
        int v;
        std::cin >> v;
        x = v;
    }
    auto s = solve_linear_system(a, b);
    if (!s) {
        std::cout << -1 << '\n';
        return 0;
    }
    std::cout << s->kernel.size() << '\n';
    for (int j = 0; j < m; j++) std::cout << s->x[j].val() << " \n"[j + 1 == m];
    if (m == 0) std::cout << '\n';
    for (auto& v : s->kernel) {
        for (int j = 0; j < m; j++) std::cout << v[j].val() << " \n"[j + 1 == m];
    }
}
