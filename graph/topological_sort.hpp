#pragma once
#include <queue>
std::vector<int> topological_sort(const std::vector<std::vector<int>> &g) {
    int n = g.size();
    std::vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            deg[j]++;
        }
    }
    std::vector<int> ret;
    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ret.push_back(u);
        for (int v : g[u]) {
            if (--deg[v] == 0) {
                q.push(v);
            }
        }
    }
    if (ret.size() != int(n)) {
        return {};
    }
    return ret;
}