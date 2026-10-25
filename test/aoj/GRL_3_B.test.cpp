#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B"
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "graph/lowlink.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    lowlink g(n);
    std::vector<std::pair<int, int>> edges(m);
    for (auto& [s, t] : edges) {
        std::cin >> s >> t;
        if (s > t) std::swap(s, t);
        g.add_edge(s, t);
    }
    g.build();
    std::vector<std::pair<int, int>> res;
    for (int e : g.bridges()) res.push_back(edges[e]);
    std::sort(res.begin(), res.end());
    for (auto [s, t] : res) std::cout << s << ' ' << t << '\n';
}
