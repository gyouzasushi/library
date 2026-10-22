#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <set>
#include <vector>

#include "graph/functional_graph.hpp"
int main() {
    std::mt19937 rng(12345);
    for (int it = 0; it < 3000; it++) {
        int n = 1 + rng() % 12;
        std::vector<int> f(n);
        for (int& x : f) x = rng() % n;
        if (rng() % 3 == 0) {
            // permutation
            for (int i = 0; i < n; i++) f[i] = i;
            std::shuffle(f.begin(), f.end(), rng);
        }
        functional_graph g(f);

        // naive: walk from v, find depth (first repeated vertex) and cycle
        std::vector<int> naive_root(n), naive_depth(n);
        std::vector<std::vector<int>> naive_cycle(n);
        for (int v = 0; v < n; v++) {
            std::vector<int> seen(n, -1), path;
            int u = v, step = 0;
            while (seen[u] == -1) {
                seen[u] = step++;
                path.push_back(u);
                u = f[u];
            }
            naive_depth[v] = seen[u];
            naive_root[v] = u;
            naive_cycle[v] = std::vector<int>(path.begin() + seen[u], path.end());
        }
        int total_cycle_vertices = 0;
        for (int v = 0; v < n; v++) {
            assert(g.root(v) == naive_root[v]);
            assert(g.depth(v) == naive_depth[v]);
            assert(g.on_cycle(v) == (naive_depth[v] == 0));
            total_cycle_vertices += g.on_cycle(v);
            // cycle(v) is a rotation of naive_cycle[v]
            const std::vector<int>& c = g.cycle(v);
            assert(c.size() == naive_cycle[v].size());
            int k = int(c.size());
            int off = int(std::find(c.begin(), c.end(), naive_cycle[v][0]) - c.begin());
            assert(off < k);
            for (int i = 0; i < k; i++) assert(c[(off + i) % k] == naive_cycle[v][i]);
            for (int i = 0; i < k; i++) assert(f[c[i]] == c[(i + 1) % k]);
            // component ids agree with root's cycle
            assert(g.component(v) == g.component(g.root(v)));
            assert(&g.cycles()[g.component(v)] == &g.cycle(v));
            // jump
            for (long long step : {0LL, 1LL, 2LL, 3LL, 5LL, 7LL, 12LL, 13LL, 1000000000000000000LL}) {
                int u = v;
                long long s = step;
                if (s > 50) {
                    // reduce using cycle length after reaching cycle
                    int d = naive_depth[v];
                    for (int i = 0; i < d; i++) u = f[u];
                    long long rem = (s - d) % (long long)naive_cycle[v].size();
                    for (int i = 0; i < rem; i++) u = f[u];
                } else {
                    for (int i = 0; i < s; i++) u = f[u];
                }
                assert(g.jump(v, step) == u);
            }
        }
        int cyc_sum = 0;
        for (const std::vector<int>& c : g.cycles()) cyc_sum += int(c.size());
        assert(cyc_sum == total_cycle_vertices);
        // children: reverse edges excluding cycle edges
        std::vector<std::set<int>> ch(n);
        for (int v = 0; v < n; v++) {
            if (!g.on_cycle(v)) ch[f[v]].insert(v);
        }
        for (int v = 0; v < n; v++) {
            std::set<int> got(g.children(v).begin(), g.children(v).end());
            assert(got == ch[v]);
            assert(got.size() == g.children(v).size());
        }
    }
    std::cout << "Hello World" << std::endl;
}
