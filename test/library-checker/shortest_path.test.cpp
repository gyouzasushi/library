#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include <iostream>

#include "graph/dijkstra.hpp"
int main() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    dijkstra<long long> d(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        d.add_edge(a, b, c);
    }
    d.solve(s);
    if (!d.reachable(t)) {
        std::cout << -1 << '\n';
        return 0;
    }
    std::vector<int> path = d.path(t);
    std::cout << d.dist(t) << ' ' << path.size() - 1 << '\n';
    for (int i = 0; i + 1 < int(path.size()); i++) {
        std::cout << path[i] << ' ' << path[i + 1] << '\n';
    }
}
