#define PROBLEM \
    "https://judge.yosupo.jp/problem/connected_components_of_complement_graph"
#include <iostream>

#include "graph/bfs_tree_of_complement.hpp"
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector adj = bfs_tree_of_complement(g);
    std::vector<std::vector<int>> ans;
    std::vector used(n, false);
    auto dfs = [&](auto dfs, int u) -> void {
        used[u] = true;
        ans.back().push_back(u);
        for (int v : adj[u]) {
            dfs(dfs, v);
        }
    };
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        ans.push_back({});
        dfs(dfs, i);
    }
    int k = ans.size();
    std::cout << k << '\n';
    for (const std::vector<int>& v : ans) {
        int l = v.size();
        std::cout << l << ' ';
        for (int i = 0; i < l; i++) {
            std::cout << v[i] << " \n"[i == l - 1];
        }
    }
}