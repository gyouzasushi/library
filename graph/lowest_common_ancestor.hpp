#pragma once
#include <cassert>
#include <vector>

#include "../datastructure/plus_minus_one_range_minimum.hpp"
struct LowestCommonAncestor {
public:
    LowestCommonAncestor() {
    }
    LowestCommonAncestor(int n, int root = 0)
        : _n(n), _root(root), g(n), id(n), vs(2 * n - 1), dep(2 * n - 1) {
    }
    void add_edge(int from, int to) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        g[from].push_back(to);
        g[to].push_back(from);
    }
    void build() {
        int k = 0;
        auto dfs = [&](auto dfs, int pos, int pre, int d) -> void {
            id[pos] = k;
            vs[k] = pos;
            dep[k++] = d;
            for (int nxt : g[pos]) {
                if (nxt == pre) continue;
                dfs(dfs, nxt, pos, d + 1);
                vs[k] = pos;
                dep[k++] = d;
            }
        };
        dfs(dfs, _root, -1, 0);
        rmq.init(dep);
    }

    int get(int u, int v) {
        int l = std::min(id[u], id[v]);
        int r = std::max(id[u], id[v]) + 1;
        return vs[rmq.prod(l, r)];
    }
    int get(int u, int v, int r) {
        return get(r, u) ^ get(u, v) ^ get(v, r);
    }
    int depth(int u) {
        return dep[id[u]];
    }
    int dist(int u, int v) {
        return depth(u) + depth(v) - 2 * depth(get(u, v));
    }

private:
    int _n, _root;
    std::vector<std::vector<int>> g;
    std::vector<int> id, vs, dep;
    PlusMinusOneRMQ rmq;
};