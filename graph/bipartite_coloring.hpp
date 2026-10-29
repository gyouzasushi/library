#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
struct bipartite_coloring {
public:
    bipartite_coloring() : bipartite_coloring(0) {
    }
    explicit bipartite_coloring(int n) : _n(n), g(n), _color(n, -1) {
    }
    void add_edge(int u, int v) {
        assert(0 <= u && u < _n);
        assert(0 <= v && v < _n);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void build() {
        _color.assign(_n, -1);
        _cycle.clear();
        std::vector<int> par(_n, -1), it(_n, 0), st;
        for (int s = 0; s < _n; s++) {
            if (_color[s] != -1) continue;
            _color[s] = 0;
            st.assign(1, s);
            while (!st.empty()) {
                int u = st.back();
                if (it[u] == int(g[u].size())) {
                    st.pop_back();
                    continue;
                }
                int v = g[u][it[u]++];
                if (_color[v] == -1) {
                    _color[v] = _color[u] ^ 1;
                    par[v] = u;
                    st.push_back(v);
                } else if (_color[v] == _color[u] && _cycle.empty()) {
                    for (int x = u; x != v; x = par[x]) _cycle.push_back(x);
                    _cycle.push_back(v);
                    std::ranges::reverse(_cycle);
                }
            }
        }
    }
    bool is_bipartite() const {
        return _cycle.empty();
    }
    int color(int v) const {
        assert(0 <= v && v < _n);
        return _color[v];
    }
    const std::vector<int>& odd_cycle() const {
        return _cycle;
    }

private:
    int _n;
    std::vector<std::vector<int>> g;
    std::vector<int> _color, _cycle;
};
