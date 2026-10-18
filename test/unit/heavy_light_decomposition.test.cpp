#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

#include "graph/heavy_light_decomposition.hpp"
constexpr long long MOD = 998244353;
void stress(std::mt19937 &rng) {
    const int N = 1 + rng() % 40;
    const int root = rng() % N;
    heavy_light_decomposition hld(N, root);
    std::vector<std::vector<int>> g(N);
    for (int v = 1; v < N; v++) {
        int p = rng() % v;
        hld.add_edge(v, p);
        g[v].push_back(p);
        g[p].push_back(v);
    }
    hld.build();
    std::vector<int> par(N, -1), dep(N, 0);
    auto dfs = [&](auto dfs, int v, int p) -> void {
        for (int c : g[v]) {
            if (c == p) continue;
            par[c] = v;
            dep[c] = dep[v] + 1;
            dfs(dfs, c, v);
        }
    };
    dfs(dfs, root, -1);
    for (int i = 0; i + 1 < N; i++) {
        // i 番目の辺は (i + 1, p) で p < i + 1
        int v = i + 1, p = -1;
        for (int x : g[v]) if (x < v) p = x;
        int child = par[v] == p ? v : p;
        assert(hld.edge_index(i) == hld.index(child));
    }
    auto naive_path = [&](int u, int v) {
        std::vector<int> a, b;
        while (u != v) {
            if (dep[u] >= dep[v]) {
                a.push_back(u);
                u = par[u];
            } else {
                b.push_back(v);
                v = par[v];
            }
        }
        a.push_back(u);
        a.insert(a.end(), b.rbegin(), b.rend());
        return a;
    };
    std::vector<long long> w(N), fa(N), fb(N);
    for (int v = 0; v < N; v++) {
        w[v] = rng() % 100;
        fa[v] = rng() % MOD;
        fb[v] = rng() % MOD;
    }
    for (int i = 0; i < N; i++) {
        assert(hld.vertex(hld.index(i)) == i);
        assert(hld.depth(i) == dep[i]);
        assert(hld.parent(i) == par[i]);
    }
    for (int q = 0; q < 300; q++) {
        int u = rng() % N, v = rng() % N;
        std::vector<int> path = naive_path(u, v);
        int l = -1;
        for (int x : path) {
            if (l == -1 || dep[x] < dep[l]) l = x;
        }
        assert(hld.lca(u, v) == l);
        assert(hld.dist(u, v) == (int)path.size() - 1);
        int k = rng() % (path.size() + 2) - 1;
        if (0 <= k && k < (int)path.size()) {
            assert(hld.jump(u, v, k) == path[k]);
        } else {
            assert(hld.jump(u, v, k) == -1);
        }
        {
            int x = rng() % N;
            bool on = false;
            for (int y : path) on |= (y == x);
            assert(hld.on_path(u, v, x) == on);
            bool sub = false;
            for (int y = x; y != -1; y = par[y]) sub |= (y == u);
            assert(hld.in_subtree(u, x) == sub);
            int kk = rng() % (dep[x] + 2) - 1;
            int y = x;
            for (int i = 0; i < kk && y != -1; i++) y = par[y];
            assert(hld.la(x, kk) == (kk < 0 ? -1 : y));
        }
        {
            long long sv = 0, se = 0;
            for (int x : path) sv += w[x];
            for (int x : path) {
                if (x != l) se += w[x];
            }
            long long hv = 0, he = 0;
            hld.for_each_vertex(u, v, [&](int a, int b) {
                assert(a < b);
                for (int i = a; i < b; i++) hv += w[hld.vertex(i)];
            });
            hld.for_each_edge(u, v, [&](int a, int b) {
                assert(a < b);
                for (int i = a; i < b; i++) he += w[hld.vertex(i)];
            });
            assert(hv == sv);
            assert(he == se);
        }
        {
            long long na = 1, nb = 0;
            for (int x : path) {
                nb = (fa[x] * nb + fb[x]) % MOD;
                na = fa[x] * na % MOD;
            }
            long long nea = 1, neb = 0;
            for (int x : path) {
                if (x == l) continue;
                neb = (fa[x] * neb + fb[x]) % MOD;
                nea = fa[x] * nea % MOD;
            }
            auto apply = [&](long long &ca, long long &cb, int a, int b) {
                if (a < b) {
                    for (int i = a; i < b; i++) {
                        int x = hld.vertex(i);
                        cb = (fa[x] * cb + fb[x]) % MOD;
                        ca = fa[x] * ca % MOD;
                    }
                } else {
                    for (int i = a - 1; i >= b; i--) {
                        int x = hld.vertex(i);
                        cb = (fa[x] * cb + fb[x]) % MOD;
                        ca = fa[x] * ca % MOD;
                    }
                }
            };
            long long ha = 1, hb = 0;
            hld.for_each_vertex_noncommutative(
                u, v, [&](int a, int b) { apply(ha, hb, a, b); });
            assert(ha == na && hb == nb);
            long long hea = 1, heb = 0;
            hld.for_each_edge_noncommutative(
                u, v, [&](int a, int b) { apply(hea, heb, a, b); });
            assert(hea == nea && heb == neb);
        }
        {
            long long sv = 0, se = 0;
            for (int x = 0; x < N; x++) {
                bool sub = false;
                for (int y = x; y != -1; y = par[y]) sub |= (y == u);
                if (!sub) continue;
                sv += w[x];
                if (x != u) se += w[x];
            }
            long long hv = 0, he = 0;
            hld.for_each_vertex_in_subtree(u, [&](int a, int b) {
                for (int i = a; i < b; i++) hv += w[hld.vertex(i)];
            });
            hld.for_each_edge_in_subtree(u, [&](int a, int b) {
                assert(a < b);
                for (int i = a; i < b; i++) he += w[hld.vertex(i)];
            });
            assert(hv == sv);
            assert(he == se);
            auto [a, b] = hld.subtree(u);
            assert(a == hld.index(u) && b - a == 1 + [&] {
                int c = 0;
                for (int x = 0; x < N; x++) {
                    bool sub = false;
                    for (int y = par[x]; y != -1; y = par[y]) sub |= (y == u);
                    c += sub;
                }
                return c;
            }());
        }
    }
}
int main() {
    std::mt19937 rng(7959);
    for (int trial = 0; trial < 100; trial++) stress(rng);
    std::cout << "Hello World" << std::endl;
    return 0;
}
