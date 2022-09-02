#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <iostream>

#include "../../graph/lowest_common_ancestor.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    LowestCommonAncestor lca(n);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        lca.add_edge(i, p);
    }
    lca.build();
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << lca.get(u, v) << '\n';
    }
}