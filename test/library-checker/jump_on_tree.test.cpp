#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
#include <iostream>

#include "graph/heavy_light_decomposition.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    heavy_light_decomposition hld(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        hld.add_edge(u, v);
    }
    hld.build();
    while (q--) {
        int s, t, k;
        std::cin >> s >> t >> k;
        std::cout << hld.jump(s, t, k) << '\n';
    }
}
