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
        std::vector<T> d;
        search(0, d, par);
        _u = int(std::max_element(d.begin(), d.end()) - d.begin());
        search(_u, d, par);
        _v = int(std::max_element(d.begin(), d.end()) - d.begin());
        _length = d[_v];
        _path.clear();
        for (int x = _v; x != -1; x = par[x]) _path.push_back(x);
        std::reverse(_path.begin(), _path.end());
    }
    T length() const {
        return _length;
    }
    std::pair<int, int> ends() const {
        return {_u, _v};
    }
    const std::vector<int>& path() const {
        return _path;
    }

private:
    int _n, _u = -1, _v = -1;
    T _length = T(0);
    std::vector<std::vector<std::pair<int, T>>> g;
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
