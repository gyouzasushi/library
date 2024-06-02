#pragma once

#include <algorithm>
#include <vector>
struct functional_graph {
public:
    functional_graph(int n) : _n(n), graph(n) {
    }
    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    void add_directed_edge(int from, int to) {
        graph[from].push_back(to);
    }
    std::vector<int> loop() {
        std::vector<int> path;
        std::vector<int> check(_n, 0);
        auto dfs = [&](auto dfs, int u, int p) -> int {
            check[u]++;
            path.push_back(u);
            for (int v : graph[u]) {
                if (v == p) continue;
                if (check[v] == 0) {
                    int ret = dfs(dfs, v, u);
                    if (ret != -1) return ret;
                } else if (check[v] == 1) {
                    return v;
                }
            }
            path.pop_back();
            check[u]++;
            return -1;
        };
        std::vector<int>::iterator it =
            std::find(path.begin(), path.end(), dfs(dfs, 0, -1));
        return std::vector(it, path.end());
    }
    std::vector<std::vector<std::pair<int, int>>> tree() {
        std::vector<int> _loop = loop();
        std::vector<std::vector<std::pair<int, int>>> ret(_loop.size());
        int k = _loop.size();
        for (int i = 0; i < k; i++) {
            auto dfs = [&](auto dfs, int u, int p) -> void {
                for (int v : graph[u]) {
                    if (v == p) continue;
                    if (v == _loop[i + 1 == k ? 0 : i + 1]) continue;
                    if (v == _loop[i == 0 ? k - 1 : i - 1]) continue;
                    ret[i].emplace_back(u, v);
                    dfs(dfs, v, u);
                }
            };
            dfs(dfs, _loop[i], -1);
        }
        return ret;
    }

private:
    int _n;
    std::vector<std::vector<int>> graph;
};