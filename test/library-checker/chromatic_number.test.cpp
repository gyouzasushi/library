#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

#include "../../graph/chromatic_number.hpp"

#include <iostream>
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector g(n, std::vector(n, false));
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u][v] = g[v][u] = true;
    }
    std::cout << chromatic_number(g) << '\n';
}