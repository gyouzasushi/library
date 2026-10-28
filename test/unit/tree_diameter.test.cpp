#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "graph/tree_diameter.hpp"
int main() {
    std::mt19937 rng(20261028);
    for (int trial = 0; trial < 300; trial++) {
        int n = 1 + rng() % 12;
        bool weighted = trial % 2;
        std::vector<std::vector<std::pair<int, long long>>> g(n);
        tree_diameter<long long> d(n);
        for (int v = 1; v < n; v++) {
            int p = rng() % v;
            long long w = weighted ? rng() % 5 : 1;
            g[v].emplace_back(p, w);
            g[p].emplace_back(v, w);
            d.add_edge(p, v, w);
        }
        d.build();
        std::vector<std::vector<long long>> dist(n, std::vector<long long>(n, -1));
        for (int s = 0; s < n; s++) {
            std::vector<int> st = {s};
            dist[s][s] = 0;
            while (!st.empty()) {
                int x = st.back();
                st.pop_back();
                for (auto [y, w] : g[x]) {
                    if (dist[s][y] != -1) continue;
                    dist[s][y] = dist[s][x] + w;
                    st.push_back(y);
                }
            }
        }
        long long diam = 0;
        for (int s = 0; s < n; s++) diam = std::max(diam, *std::max_element(dist[s].begin(), dist[s].end()));
        assert(d.length() == diam);
        auto [u, v] = d.ends();
        assert(dist[u][v] == diam);
        const std::vector<int>& path = d.path();
        assert(path.front() == u && path.back() == v);
        long long len = 0;
        for (int i = 0; i + 1 < int(path.size()); i++) {
            bool found = false;
            for (auto [y, w] : g[path[i]]) {
                if (y == path[i + 1]) found = true, len += w;
            }
            assert(found);
        }
        assert(len == diam);
        for (int x = 0; x < n; x++) {
            long long far = *std::max_element(dist[x].begin(), dist[x].end());
            assert(d.farthest_dist(x) == far);
            int f = d.farthest(x);
            assert(dist[x][f] == far);
            assert(f == int(std::max_element(dist[x].begin(), dist[x].end()) - dist[x].begin()));
        }
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
