#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include <iostream>

#include "graph/lowlink.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    lowlink g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        g.add_edge(a, b);
    }
    g.build();
    auto groups = g.two_edge_connected_components();
    std::cout << groups.size() << '\n';
    for (auto& c : groups) {
        std::cout << c.size();
        for (int v : c) std::cout << ' ' << v;
        std::cout << '\n';
    }
}
