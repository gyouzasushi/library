#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include <iostream>

#include "../../graph/maxflow.hpp"

int main() {
    int l, r, m;
    std::cin >> l >> r >> m;
    int n = l + r + 2;
    int s = n - 2, t = n - 1;
    mf_graph<int> g(n);
    for (int a = 0; a < l; a++) g.add_edge(s, a, 1);
    for (int b = l; b < l + r; b++) g.add_edge(b, t, 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        g.add_edge(a, b + l, 1);
    }
    int k = g.flow(s, t);
    std::cout << k << '\n';
    for (auto e : g.edges()) {
        if (e.flow == 1 && e.from != s && e.to != t) {
            std::cout << e.from << ' ' << e.to - l << '\n';
        }
    }
}