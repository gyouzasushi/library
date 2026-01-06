---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/shortest_path.test.cpp
    title: test/library-checker/shortest_path.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n#include <limits>\n#include <queue>\n\
    #include <vector>\ntemplate <typename T>\nstd::pair<std::vector<T>, std::vector<int>>\
    \ dijkstra(\n    int s, const std::vector<std::vector<std::pair<int, T>>> &g)\
    \ {\n    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,\n\
    \                        std::greater<std::pair<T, int>>>\n        que;\n    int\
    \ n = int(g.size());\n    std::vector<T> d(n, std::numeric_limits<T>::max());\n\
    \    std::vector<int> from(n, -1);\n    d[s] = 0;\n    que.emplace(0, s);\n  \
    \  while (!que.empty()) {\n        auto [dist, pos] = que.top();\n        que.pop();\n\
    \        if (d[pos] < dist) continue;\n        for (auto [to, cost] : g[pos])\
    \ {\n            if (d[pos] + cost < d[to]) {\n                d[to] = d[pos]\
    \ + cost;\n                from[to] = pos;\n                que.emplace(d[to],\
    \ to);\n            }\n        }\n    }\n    return {d, from};\n}\n"
  code: "#pragma once\n#include <limits>\n#include <queue>\n#include <vector>\ntemplate\
    \ <typename T>\nstd::pair<std::vector<T>, std::vector<int>> dijkstra(\n    int\
    \ s, const std::vector<std::vector<std::pair<int, T>>> &g) {\n    std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>,\n                        std::greater<std::pair<T,\
    \ int>>>\n        que;\n    int n = int(g.size());\n    std::vector<T> d(n, std::numeric_limits<T>::max());\n\
    \    std::vector<int> from(n, -1);\n    d[s] = 0;\n    que.emplace(0, s);\n  \
    \  while (!que.empty()) {\n        auto [dist, pos] = que.top();\n        que.pop();\n\
    \        if (d[pos] < dist) continue;\n        for (auto [to, cost] : g[pos])\
    \ {\n            if (d[pos] + cost < d[to]) {\n                d[to] = d[pos]\
    \ + cost;\n                from[to] = pos;\n                que.emplace(d[to],\
    \ to);\n            }\n        }\n    }\n    return {d, from};\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-09-03 17:27:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/shortest_path.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
title: "Dijkstra \u6CD5"
---

### 概要
- Dijkstra 法で単一始点最短路を求める。
  
### 使い方
- `dijkstra(s, g)`: 重み付きグラフ `g` における、頂点 `s` から全点間の最短距離を求める。`g` は `(to, cost)` のペアを持つ隣接リスト。`(dist, from)` を返す。