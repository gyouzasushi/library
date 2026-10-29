#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <random>
#include <set>
#include <vector>

#include "graph/bipartite_coloring.hpp"
int main() {
    std::mt19937 rng(20261029);
    for (int trial = 0; trial < 2000; trial++) {
        int n = 1 + rng() % 10;
        int m = rng() % 14;
        std::vector<std::pair<int, int>> edges;
        std::set<std::pair<int, int>> es;
        bipartite_coloring g(n);
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % n;
            if (trial % 4 == 0 && u == v) continue;
            edges.emplace_back(u, v);
            es.emplace(u, v);
            es.emplace(v, u);
            g.add_edge(u, v);
        }
        g.build();
        bool expect = false;
        for (int mask = 0; mask < (1 << n) && !expect; mask++) {
            bool ok = true;
            for (auto [u, v] : edges) ok &= ((mask >> u & 1) != (mask >> v & 1));
            expect |= ok;
        }
        assert(g.is_bipartite() == expect);
        assert(g.odd_cycle().empty() == expect);
        for (int v = 0; v < n; v++) assert(g.color(v) == 0 || g.color(v) == 1);
        if (expect) {
            for (auto [u, v] : edges) assert(g.color(u) != g.color(v));
        } else {
            const std::vector<int>& c = g.odd_cycle();
            int k = int(c.size());
            assert(k % 2 == 1);
            std::set<int> seen(c.begin(), c.end());
            assert(int(seen.size()) == k);
            for (int i = 0; i < k; i++) assert(es.count({c[i], c[(i + 1) % k]}));
        }
    }
    std::cout << "Hello World\n";
}
