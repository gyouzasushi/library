#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"
#include <iostream>
#include <vector>

#include "graph/chromatic_number.hpp"
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::cout << chromatic_number(g) << '\n';
}
