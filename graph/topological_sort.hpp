#pragma once
#include <functional>
#include <optional>
#include <queue>
#include <vector>
template <class Compare>
std::optional<std::vector<int>> topological_sort(const std::vector<std::vector<int>>& g, Compare comp) {
    int n = int(g.size());
    std::vector<int> deg(n);
    for (int u = 0; u < n; u++) {
        for (int v : g[u]) deg[v]++;
    }
    auto rev = [&](int a, int b) { return comp(b, a); };
    std::priority_queue<int, std::vector<int>, decltype(rev)> q(rev);
    for (int v = 0; v < n; v++) {
        if (deg[v] == 0) q.push(v);
    }
    std::vector<int> order;
    order.reserve(n);
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            if (--deg[v] == 0) q.push(v);
        }
    }
    if (int(order.size()) != n) return std::nullopt;
    return order;
}
std::optional<std::vector<int>> topological_sort(const std::vector<std::vector<int>>& g) {
    int n = int(g.size());
    std::vector<int> deg(n);
    for (int u = 0; u < n; u++) {
        for (int v : g[u]) deg[v]++;
    }
    std::queue<int> q;
    for (int v = 0; v < n; v++) {
        if (deg[v] == 0) q.push(v);
    }
    std::vector<int> order;
    order.reserve(n);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            if (--deg[v] == 0) q.push(v);
        }
    }
    if (int(order.size()) != n) return std::nullopt;
    return order;
}
