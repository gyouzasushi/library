#pragma once
#include <algorithm>
#include <cassert>
#include <limits>
#include <tuple>
#include <vector>
template <class T> struct bellman_ford {
public:
    bellman_ford() : bellman_ford(0) {
    }
    explicit bellman_ford(int n) : _n(n), _dist(n, inf), _prev(n, -1) {
    }
    void add_edge(int from, int to, T w) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        edges.emplace_back(from, to, w);
    }
    void solve(int s) {
        assert(0 <= s && s < _n);
        _dist.assign(_n, inf);
        _prev.assign(_n, -1);
        _dist[s] = 0;
        for (int i = 0; i < _n - 1; i++) {
            bool updated = false;
            for (auto [u, v, w] : edges) {
                if (_dist[u] == inf) continue;
                if (_dist[u] + w < _dist[v]) {
                    _dist[v] = _dist[u] + w;
                    _prev[v] = u;
                    updated = true;
                }
            }
            if (!updated) return;
        }
        for (int i = 0; i < _n; i++) {
            bool updated = false;
            for (auto [u, v, w] : edges) {
                if (_dist[u] == inf || _dist[v] == ninf) continue;
                if (_dist[u] == ninf || _dist[u] + w < _dist[v]) {
                    _dist[v] = ninf;
                    updated = true;
                }
            }
            if (!updated) return;
        }
    }
    T dist(int v) const {
        assert(0 <= v && v < _n);
        return _dist[v];
    }
    int prev(int v) const {
        assert(0 <= v && v < _n);
        return _prev[v];
    }
    bool reachable(int v) const {
        assert(0 <= v && v < _n);
        return _dist[v] != inf;
    }
    bool unbounded(int v) const {
        assert(0 <= v && v < _n);
        return _dist[v] == ninf;
    }
    bool has_negative_cycle() const {
        return std::ranges::find(_dist, ninf) != _dist.end();
    }
    std::vector<int> path(int t) const {
        assert(0 <= t && t < _n);
        if (_dist[t] == inf || _dist[t] == ninf) return {};
        std::vector<int> res;
        for (int v = t; v != -1; v = _prev[v]) res.push_back(v);
        std::ranges::reverse(res);
        return res;
    }

private:
    static constexpr T inf = std::numeric_limits<T>::max();
    static constexpr T ninf = std::numeric_limits<T>::lowest();
    int _n;
    std::vector<std::tuple<int, int, T>> edges;
    std::vector<T> _dist;
    std::vector<int> _prev;
};
