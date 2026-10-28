#pragma once
#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>
template <class T> struct dijkstra {
public:
    dijkstra() : dijkstra(0) {
    }
    explicit dijkstra(int n) : _n(n), g(n), _dist(n, inf), _prev(n, -1) {
    }
    void add_edge(int from, int to, T w) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        g[from].emplace_back(to, w);
    }
    void solve(int s) {
        assert(0 <= s && s < _n);
        _dist.assign(_n, inf);
        _prev.assign(_n, -1);
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,
                            std::greater<std::pair<T, int>>>
            que;
        _dist[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            auto [d, u] = que.top();
            que.pop();
            if (_dist[u] < d) continue;
            for (auto [v, w] : g[u]) {
                if (_dist[u] + w < _dist[v]) {
                    _dist[v] = _dist[u] + w;
                    _prev[v] = u;
                    que.emplace(_dist[v], v);
                }
            }
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
    std::vector<int> path(int t) const {
        assert(0 <= t && t < _n);
        if (_dist[t] == inf) return {};
        std::vector<int> res;
        for (int v = t; v != -1; v = _prev[v]) res.push_back(v);
        std::ranges::reverse(res);
        return res;
    }

private:
    static constexpr T inf = std::numeric_limits<T>::max();
    int _n;
    std::vector<std::vector<std::pair<int, T>>> g;
    std::vector<T> _dist;
    std::vector<int> _prev;
};
