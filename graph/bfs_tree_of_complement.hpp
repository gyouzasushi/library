#pragma once
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
std::vector<std::vector<int>> bfs_tree_of_complement(
    const std::vector<std::vector<int>>& g) {
    int n = int(g.size());
    std::vector<std::vector<int>> ret(n);
    std::vector<bool> seen(n);
    std::vector<bool> banned(n);
    std::queue<int> q;
    std::vector<int> s(n), t;
    std::iota(s.begin(), s.end(), 0);
    for (int i = 0; i < n; i++) {
        if (seen[i]) continue;
        seen[i] = true;
        q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            seen[u] = true;
            for (int v : g[u]) {
                banned[v] = true;
            }
            for (int v : s) {
                if (banned[v]) {
                    t.push_back(v);
                } else if (!seen[v]) {
                    ret[u].push_back(v);
                    q.push(v);
                }
            }
            s = std::move(t);
            for (int v : g[u]) {
                banned[v] = false;
            }
        }
    }
    return ret;
}