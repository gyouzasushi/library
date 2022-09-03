#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include <algorithm>
#include <iostream>

#include "../../graph/dijkstra.hpp"
int main() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    std::vector<std::vector<std::pair<int, long long>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }

    auto [dist, from] = dijkstra(s, g);
    if (dist[t] == std::numeric_limits<long long>::max()) {
        std::cout << -1 << '\n';
        return 0;
    }

    int pos = t;
    std::vector<int> path;
    while (pos != -1) {
        path.push_back(pos);
        pos = from[pos];
    };
    std::reverse(path.begin(), path.end());

    std::cout << dist[t] << ' ' << path.size() - 1 << '\n';
    for (int i = 0; i + 1 < int(path.size()); i++) {
        std::cout << path[i] << ' ' << path[i + 1] << '\n';
    }
}