#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
template <class T>
struct tree_diameter {
public:
    tree_diameter() : tree_diameter(0) {
    }
    explicit tree_diameter(int n) : _n(n), g(n) {
    }
    void add_edge(int u, int v, T w = 1) {
        assert(0 <= u && u < _n);
        assert(0 <= v && v < _n);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    void build() {
        assert(_n >= 1);
        std::vector<int> par;
        std::vector<T> d0;
        search(0, d0, par);
        _u = int(std::max_element(d0.begin(), d0.end()) - d0.begin());
        search(_u, du, par);
        _v = int(std::max_element(du.begin(), du.end()) - du.begin());
        _path.clear();
        for (int x = _v; x != -1; x = par[x]) _path.push_back(x);
        std::reverse(_path.begin(), _path.end());
        search(_v, dv, par);
    }
    T length() const {
        return du[_v];
    }
    std::pair<int, int> ends() const {
        return {_u, _v};
    }
    const std::vector<int>& path() const {
        return _path;
    }
    T farthest_dist(int x) const {
        assert(0 <= x && x < _n);
        return std::max(du[x], dv[x]);
    }
    int farthest(int x) const {
        assert(0 <= x && x < _n);
        if (du[x] != dv[x]) return du[x] > dv[x] ? _u : _v;
        return std::min(_u, _v);
    }

private:
    int _n, _u = -1, _v = -1;
    std::vector<std::vector<std::pair<int, T>>> g;
    std::vector<T> du, dv;
    std::vector<int> _path;
    void search(int s, std::vector<T>& d, std::vector<int>& par) const {
        d.assign(_n, T(0));
        par.assign(_n, -1);
        std::vector<int> st = {s};
        par[s] = s;
        while (!st.empty()) {
            int x = st.back();
            st.pop_back();
            for (auto [y, w] : g[x]) {
                if (par[y] != -1) continue;
                par[y] = x;
                d[y] = d[x] + w;
                st.push_back(y);
            }
        }
        par[s] = -1;
    }
};
