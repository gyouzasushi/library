#pragma once
#include <algorithm>
#include <cassert>
#include <map>
#include <vector>
std::vector<int> subtree_classify(const std::vector<std::vector<int>>& g, int root = 0) {
    int n = int(g.size());
    assert(0 <= root && root < n);
    std::vector<int> par(n, -1), order;
    order.reserve(n);
    order.push_back(root);
    par[root] = root;
    for (int i = 0; i < int(order.size()); i++) {
        int u = order[i];
        for (int v : g[u]) {
            if (v == par[u]) continue;
            assert(par[v] == -1);
            par[v] = u;
            order.push_back(v);
        }
    }
    assert(int(order.size()) == n);
    std::vector<int> ret(n);
    std::map<std::vector<int>, int> id;
    std::vector<int> key;
    for (int i = n - 1; i >= 0; i--) {
        int u = order[i];
        key.clear();
        for (int v : g[u]) {
            if (v != par[u]) key.push_back(ret[v]);
        }
        std::sort(key.begin(), key.end());
        ret[u] = id.try_emplace(key, int(id.size())).first->second;
    }
    return ret;
}
