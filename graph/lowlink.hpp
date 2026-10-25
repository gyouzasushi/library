#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
struct lowlink {
public:
    lowlink() : lowlink(0) {
    }
    explicit lowlink(int n) : _n(n), g(n), ord(n, -1), low(n), comp(n, -1), art(n, false) {
    }
    int add_edge(int u, int v) {
        assert(0 <= u && u < _n);
        assert(0 <= v && v < _n);
        int e = int(edges.size());
        edges.emplace_back(u, v);
        g[u].emplace_back(v, e);
        g[v].emplace_back(u, e);
        return e;
    }
    void build() {
        int m = int(edges.size());
        bridge.assign(m, false);
        std::vector<int> it(_n, 0), par_edge(_n, -1), children(_n, 0);
        int t = 0;
        for (int r = 0; r < _n; r++) {
            if (ord[r] != -1) continue;
            std::vector<int> st = {r};
            ord[r] = low[r] = t++;
            while (!st.empty()) {
                int v = st.back();
                if (it[v] < int(g[v].size())) {
                    auto [u, e] = g[v][it[v]++];
                    if (e == par_edge[v]) continue;
                    if (ord[u] == -1) {
                        ord[u] = low[u] = t++;
                        par_edge[u] = e;
                        children[v]++;
                        st.push_back(u);
                    } else {
                        low[v] = std::min(low[v], ord[u]);
                    }
                } else {
                    st.pop_back();
                    if (st.empty()) continue;
                    int p = st.back();
                    low[p] = std::min(low[p], low[v]);
                    if (low[v] > ord[p]) bridge[par_edge[v]] = true;
                    if (low[v] >= ord[p] && p != r) art[p] = true;
                }
            }
            art[r] = children[r] >= 2;
        }
        _num_components = 0;
        for (int r = 0; r < _n; r++) {
            if (comp[r] != -1) continue;
            comp[r] = _num_components;
            std::vector<int> st = {r};
            while (!st.empty()) {
                int v = st.back();
                st.pop_back();
                for (auto [u, e] : g[v]) {
                    if (bridge[e] || comp[u] != -1) continue;
                    comp[u] = _num_components;
                    st.push_back(u);
                }
            }
            _num_components++;
        }
    }
    bool is_bridge(int e) const {
        assert(0 <= e && e < int(edges.size()));
        return bridge[e];
    }
    bool is_articulation(int v) const {
        assert(0 <= v && v < _n);
        return art[v];
    }
    std::vector<int> bridges() const {
        std::vector<int> res;
        for (int e = 0; e < int(edges.size()); e++) {
            if (bridge[e]) res.push_back(e);
        }
        return res;
    }
    std::vector<int> articulation_points() const {
        std::vector<int> res;
        for (int v = 0; v < _n; v++) {
            if (art[v]) res.push_back(v);
        }
        return res;
    }
    int component(int v) const {
        assert(0 <= v && v < _n);
        return comp[v];
    }
    std::vector<std::vector<int>> two_edge_connected_components() const {
        std::vector<std::vector<int>> res(_num_components);
        for (int v = 0; v < _n; v++) res[comp[v]].push_back(v);
        return res;
    }

private:
    int _n, _num_components = 0;
    std::vector<std::vector<std::pair<int, int>>> g;
    std::vector<std::pair<int, int>> edges;
    std::vector<int> ord, low, comp;
    std::vector<bool> art, bridge;
};
