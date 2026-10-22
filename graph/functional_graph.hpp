#pragma once
#include <bit>
#include <cassert>
#include <vector>
struct functional_graph {
public:
    functional_graph() : functional_graph(std::vector<int>()) {
    }
    explicit functional_graph(std::vector<int> f)
        : _n(int(f.size())),
          _f(std::move(f)),
          _root(_n, -1),
          _depth(_n, 0),
          _component(_n, -1),
          _pos(_n, -1),
          _children(_n) {
        for (int v = 0; v < _n; v++) assert(0 <= _f[v] && _f[v] < _n);
        std::vector<int> state(_n, 0);
        for (int s = 0; s < _n; s++) {
            if (state[s]) continue;
            int v = s;
            while (state[v] == 0) {
                state[v] = 1;
                v = _f[v];
            }
            if (state[v] == 1) {
                int k = int(_cycles.size());
                std::vector<int> cyc;
                int u = v;
                do {
                    cyc.push_back(u);
                    _root[u] = u;
                    _component[u] = k;
                    _pos[u] = int(cyc.size()) - 1;
                    u = _f[u];
                } while (u != v);
                _cycles.push_back(std::move(cyc));
            }
            for (int u = s; state[u] == 1; u = _f[u]) state[u] = 2;
        }
        for (int v = 0; v < _n; v++) {
            if (_root[v] != v) _children[_f[v]].push_back(v);
        }
        std::vector<int> order;
        order.reserve(_n);
        for (const std::vector<int>& cyc : _cycles) {
            for (int v : cyc) order.push_back(v);
        }
        int max_depth = 0;
        for (int i = 0; i < _n; i++) {
            int v = order[i];
            for (int c : _children[v]) {
                _root[c] = _root[v];
                _depth[c] = _depth[v] + 1;
                _component[c] = _component[v];
                order.push_back(c);
                if (max_depth < _depth[c]) max_depth = _depth[c];
            }
        }
        int log = std::bit_width((unsigned)max_depth);
        _up.assign(log, std::vector<int>(_n));
        for (int j = 0; j < log; j++) {
            for (int v = 0; v < _n; v++) {
                _up[j][v] = j == 0 ? _f[v] : _up[j - 1][_up[j - 1][v]];
            }
        }
    }
    int jump(int v, long long k) const {
        assert(0 <= v && v < _n);
        assert(0 <= k);
        if (k < _depth[v]) {
            for (int j = 0; k; j++, k >>= 1) {
                if (k & 1) v = _up[j][v];
            }
            return v;
        }
        k -= _depth[v];
        const std::vector<int>& cyc = _cycles[_component[v]];
        int len = int(cyc.size());
        return cyc[(_pos[_root[v]] + k % len) % len];
    }
    bool on_cycle(int v) const {
        assert(0 <= v && v < _n);
        return _root[v] == v;
    }
    int root(int v) const {
        assert(0 <= v && v < _n);
        return _root[v];
    }
    int depth(int v) const {
        assert(0 <= v && v < _n);
        return _depth[v];
    }
    int component(int v) const {
        assert(0 <= v && v < _n);
        return _component[v];
    }
    const std::vector<int>& cycle(int v) const {
        assert(0 <= v && v < _n);
        return _cycles[_component[v]];
    }
    const std::vector<std::vector<int>>& cycles() const {
        return _cycles;
    }
    const std::vector<int>& children(int v) const {
        assert(0 <= v && v < _n);
        return _children[v];
    }

private:
    int _n;
    std::vector<int> _f, _root, _depth, _component, _pos;
    std::vector<std::vector<int>> _children, _cycles, _up;
};
