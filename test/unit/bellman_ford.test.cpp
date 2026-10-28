#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "graph/bellman_ford.hpp"
int main() {
    std::mt19937 rng(20261029);
    const long long inf = 1LL << 50;
    for (int trial = 0; trial < 3000; trial++) {
        int n = 1 + rng() % 7;
        int m = rng() % 13;
        std::vector<std::vector<long long>> w(n, std::vector<long long>(n, inf));
        bellman_ford<long long> bf(n);
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % n;
            long long c = (long long)(rng() % 9) - 3;
            w[u][v] = std::min(w[u][v], c);
            bf.add_edge(u, v, c);
        }
        std::vector<std::vector<bool>> reach(n, std::vector<bool>(n, false));
        std::vector<std::vector<long long>> d(n, std::vector<long long>(n, inf));
        for (int i = 0; i < n; i++) {
            reach[i][i] = true;
            d[i][i] = 0;
            for (int j = 0; j < n; j++) {
                if (w[i][j] != inf) {
                    reach[i][j] = true;
                    d[i][j] = std::min(d[i][j], w[i][j]);
                }
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
                    if (d[i][k] != inf && d[k][j] != inf) d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        int s = rng() % n;
        bf.solve(s);
        bool any_negative = false;
        for (int v = 0; v < n; v++) {
            bool unb = false;
            for (int k = 0; k < n; k++) {
                if (reach[s][k] && d[k][k] < 0 && reach[k][v]) unb = true;
            }
            any_negative = any_negative || unb;
            assert(bf.reachable(v) == reach[s][v]);
            assert(bf.unbounded(v) == unb);
            if (!reach[s][v]) {
                assert(bf.dist(v) == std::numeric_limits<long long>::max());
                assert(bf.prev(v) == -1);
                assert(bf.path(v).empty());
            } else if (unb) {
                assert(bf.dist(v) == std::numeric_limits<long long>::lowest());
                assert(bf.path(v).empty());
            } else {
                assert(bf.dist(v) == d[s][v]);
                std::vector<int> p = bf.path(v);
                assert(!p.empty() && p.front() == s && p.back() == v);
                long long total = 0;
                for (int i = 0; i + 1 < int(p.size()); i++) {
                    assert(w[p[i]][p[i + 1]] != inf);
                    total += w[p[i]][p[i + 1]];
                }
                assert(total == d[s][v]);
                assert(bf.prev(v) == (v == s ? -1 : p[p.size() - 2]));
            }
        }
        assert(bf.has_negative_cycle() == any_negative);
    }
    bellman_ford<double> bd(3);
    bd.add_edge(0, 1, 0.5);
    bd.add_edge(1, 2, -1.5);
    bd.solve(0);
    assert(bd.dist(2) == -1.0);
    assert(!bd.has_negative_cycle());
    std::cout << "Hello World\n";
}
