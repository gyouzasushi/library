#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B"

#include <iostream>

#include "graph/topological_sort.hpp"
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int s, t;
        std::cin >> s >> t;
        g[s].push_back(t);
    }
    std::vector ans = topological_sort(g);
    for (int u : ans) std::cout << u << '\n';
}