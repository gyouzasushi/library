#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "graph/topological_sort.hpp"
int main() {
    std::mt19937 rng(7959);
    for (int trial = 0; trial < 300; trial++) {
        int n = rng() % 12;
        std::vector<int> perm(n);
        std::iota(perm.begin(), perm.end(), 0);
        std::shuffle(perm.begin(), perm.end(), rng);
        std::vector<std::vector<int>> g(n);
        std::vector<std::pair<int, int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (rng() % 3 == 0) {
                    g[perm[i]].push_back(perm[j]);
                    edges.emplace_back(perm[i], perm[j]);
                }
            }
        }
        auto order = topological_sort(g);
        assert(int(order.size()) == n);
        std::vector<int> pos(n, -1);
        for (int i = 0; i < n; i++) {
            assert(0 <= order[i] && order[i] < n);
            assert(pos[order[i]] == -1);
            pos[order[i]] = i;
        }
        for (auto [u, v] : edges) assert(pos[u] < pos[v]);
        if (!edges.empty()) {
            auto [u, v] = edges[rng() % edges.size()];
            g[v].push_back(u);
            assert(topological_sort(g).empty());
        }
    }
    {
        std::vector<std::vector<int>> g(1);
        g[0].push_back(0);
        assert(topological_sort(g).empty());
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
