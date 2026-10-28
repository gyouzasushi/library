#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B"
#include <iostream>

#include "graph/bellman_ford.hpp"
int main() {
    int n, m, r;
    std::cin >> n >> m >> r;
    bellman_ford<long long> bf(n);
    for (int i = 0; i < m; i++) {
        int s, t;
        long long d;
        std::cin >> s >> t >> d;
        bf.add_edge(s, t, d);
    }
    bf.solve(r);
    if (bf.has_negative_cycle()) {
        std::cout << "NEGATIVE CYCLE\n";
        return 0;
    }
    for (int v = 0; v < n; v++) {
        if (bf.reachable(v)) {
            std::cout << bf.dist(v) << '\n';
        } else {
            std::cout << "INF\n";
        }
    }
}
