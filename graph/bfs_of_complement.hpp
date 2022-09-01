#pragma once
#include <algorithm>
#include <queue>
#include <vector>
void bfs_of_complement(const std::vector<std::vector<int>>& g) {
    int n = int(g.size());
    std::queue<int> Q;
    Q.push(0);
    std::vector<int> S;
    for (int i = 1; i < n; i++) S.push_back(i);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        std::vector<int> L;
        for (int u : g[v]) {
            if (std::count(S.begin(), S.end(), u)) {
                S.erase(std::find(S.begin(), S.end(), u));
                L.push_back(u);
            }
        }
    }
    return;
}