#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <iostream>

#include "graph/heavy_light_decomposition.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    heavy_light_decomposition hld(n);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        hld.add_edge(i, p);
    }
    hld.build();
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << hld.lca(u, v) << '\n';
    }
}
