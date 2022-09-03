#pragma once
#include <limits>
#include <queue>
#include <vector>
template <typename T>
std::pair<std::vector<T>, std::vector<int>> dijkstra(
    int s, const std::vector<std::vector<std::pair<int, T>>> &g) {
    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,
                        std::greater<std::pair<T, int>>>
        que;
    int n = int(g.size());
    std::vector<T> d(n, std::numeric_limits<T>::max());
    std::vector<int> from(n, -1);
    d[s] = 0;
    que.emplace(0, s);
    while (!que.empty()) {
        auto [dist, pos] = que.top();
        que.pop();
        if (d[pos] < dist) continue;
        for (auto [to, cost] : g[pos]) {
            if (d[pos] + cost < d[to]) {
                d[to] = d[pos] + cost;
                from[to] = pos;
                que.emplace(d[to], to);
            }
        }
    }
    return {d, from};
}