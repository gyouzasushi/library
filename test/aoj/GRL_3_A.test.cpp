#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A"
#include <iostream>

#include "graph/lowlink.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    lowlink g(n);
    for (int i = 0; i < m; i++) {
        int s, t;
        std::cin >> s >> t;
        g.add_edge(s, t);
    }
    g.build();
    for (int v : g.articulation_points()) std::cout << v << '\n';
}
