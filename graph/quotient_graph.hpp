#pragma once
#include <algorithm>
#include <vector>
inline std::vector<int> component_id(int n, const std::vector<std::vector<int>>& groups) {
    std::vector<int> id(n);
    for (int i = 0; i < int(groups.size()); i++) {
        for (int v : groups[i]) id[v] = i;
    }
    return id;
}
inline std::vector<std::vector<int>> quotient_graph(const std::vector<std::vector<int>>& g, const std::vector<std::vector<int>>& groups) {
    std::vector<int> id = component_id(int(g.size()), groups);
    std::vector<std::vector<int>> q(groups.size());
    for (int u = 0; u < int(g.size()); u++) {
        for (int v : g[u]) {
            if (id[u] != id[v]) q[id[u]].push_back(id[v]);
        }
    }
    for (auto& es : q) {
        std::ranges::sort(es);
        es.erase(std::ranges::unique(es).begin(), es.end());
    }
    return q;
}
