#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include <iostream>

#include "graph/strongly_connected_components.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    scc_graph g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        g.add_edge(u, v);
    }
    auto scc = g.scc();
    std::cout << scc.size() << '\n';
    for (auto &v : scc) {
        int k = v.size();
        std::cout << k << ' ';
        for (int i = 0; i < k; i++) {
            std::cout << v[i] << " \n"[i == k - 1];
        }
    }
}