#pragma once

#include <algorithm>
#include <map>
#include <vector>
std::vector<int> subtree_classify(std::vector<std::vector<int>> g,
                                  int root = 0) {
    std::vector<int> ret(g.size());
    std::map<std::vector<int>, int> cache;
    auto dfs = [&](auto dfs, int u) -> int {
        std::vector<int> hash;
        hash.push_back(-1);
        for (int v : g[u]) hash.push_back(dfs(dfs, v));
        std::sort(hash.begin(), hash.end());
        hash.push_back(-1);
        if (!cache.count(hash)) cache[hash] = int(cache.size());
        return ret[u] = cache[hash];
    };
    dfs(dfs, root);
    return ret;
}