#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "graph/topological_sort.hpp"
bool valid(const std::vector<std::vector<int>>& g, const std::vector<int>& order) {
    int n = int(g.size());
    if (int(order.size()) != n) return false;
    std::vector<int> pos(n, -1);
    for (int i = 0; i < n; i++) {
        if (order[i] < 0 || order[i] >= n || pos[order[i]] != -1) return false;
        pos[order[i]] = i;
    }
    for (int u = 0; u < n; u++) {
        for (int v : g[u]) {
            if (pos[u] >= pos[v]) return false;
        }
    }
    return true;
}
int main() {
    std::mt19937 rng(7959);
    for (int trial = 0; trial < 300; trial++) {
        int n = rng() % 9;
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
        assert(order && valid(g, *order));
        auto lex = topological_sort(g, std::less<int>());
        assert(lex && valid(g, *lex));
        std::vector<int> best;
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        do {
            if (valid(g, p) && (best.empty() || p < best)) best = p;
        } while (std::next_permutation(p.begin(), p.end()));
        assert(*lex == best);
        auto lex_rev = topological_sort(g, std::greater<int>());
        assert(lex_rev && valid(g, *lex_rev));
        if (!edges.empty()) {
            auto [u, v] = edges[rng() % edges.size()];
            g[v].push_back(u);
            assert(!topological_sort(g));
            assert(!topological_sort(g, std::less<int>()));
        }
    }
    {
        std::vector<std::vector<int>> g(1);
        g[0].push_back(0);
        assert(!topological_sort(g));
        assert(topological_sort(std::vector<std::vector<int>>{}).has_value());
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
