#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

#include "graph/lowlink.hpp"

// number of connected components after removing vertex `skip_v` and edge `skip_e`
int components(int n, const std::vector<std::pair<int, int>>& edges, int skip_v, int skip_e) {
    std::vector<std::vector<int>> g(n);
    for (int e = 0; e < int(edges.size()); e++) {
        if (e == skip_e) continue;
        auto [u, v] = edges[e];
        if (u == skip_v || v == skip_v) continue;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<bool> seen(n, false);
    int res = 0;
    for (int r = 0; r < n; r++) {
        if (r == skip_v || seen[r]) continue;
        res++;
        std::vector<int> st = {r};
        seen[r] = true;
        while (!st.empty()) {
            int v = st.back();
            st.pop_back();
            for (int u : g[v]) {
                if (!seen[u]) seen[u] = true, st.push_back(u);
            }
        }
    }
    return res;
}

int main() {
    std::mt19937 rng(777);
    for (int it = 0; it < 500; it++) {
        int n = 1 + rng() % 9;
        int m = rng() % 14;
        std::vector<std::pair<int, int>> edges(m);
        for (auto& [u, v] : edges) u = rng() % n, v = rng() % n;  // multi-edges and self-loops
        lowlink g(n);
        for (int e = 0; e < m; e++) assert(g.add_edge(edges[e].first, edges[e].second) == e);
        g.build();
        int base = components(n, edges, -1, -1);
        std::vector<int> br, ap;
        for (int e = 0; e < m; e++) {
            bool b = components(n, edges, -1, e) > base;
            assert(g.is_bridge(e) == b);
            if (b) br.push_back(e);
        }
        assert(g.bridges() == br);
        for (int v = 0; v < n; v++) {
            // removing v also removes v itself from the count
            bool a = components(n, edges, v, -1) > base;
            assert(g.is_articulation(v) == a);
            if (a) ap.push_back(v);
        }
        assert(g.articulation_points() == ap);
        // same 2-edge-connected component <=> connected after removing any single edge
        auto groups = g.two_edge_connected_components();
        std::vector<int> cnt(groups.size(), 0);
        for (int c = 0; c < int(groups.size()); c++) {
            for (int v : groups[c]) assert(g.component(v) == c), cnt[c]++;
        }
        int total = 0;
        for (int x : cnt) assert(x > 0), total += x;
        assert(total == n);
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                bool same = true;
                // connected in the graph without bridges?
                std::vector<std::pair<int, int>> nb;
                for (int e = 0; e < m; e++) if (!g.is_bridge(e)) nb.push_back(edges[e]);
                std::vector<std::vector<int>> h(n);
                for (auto [a, b] : nb) h[a].push_back(b), h[b].push_back(a);
                std::vector<bool> seen(n, false);
                std::vector<int> st = {u};
                seen[u] = true;
                while (!st.empty()) {
                    int x = st.back();
                    st.pop_back();
                    for (int y : h[x]) if (!seen[y]) seen[y] = true, st.push_back(y);
                }
                same = seen[v];
                assert((g.component(u) == g.component(v)) == same);
            }
        }
    }
    // long path: no recursion, so n = 200000 must not overflow the stack
    {
        int n = 200000;
        lowlink g(n);
        for (int i = 0; i + 1 < n; i++) g.add_edge(i, i + 1);
        g.build();
        assert(int(g.bridges().size()) == n - 1);
        assert(int(g.articulation_points().size()) == n - 2);
        assert(g.two_edge_connected_components().size() == size_t(n));
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
