---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n#include <limits>\n#include <queue>\n\
    #include <vector>\ntemplate <typename T>\nstd::vector<T> dijkstra(int s,\n   \
    \                     const std::vector<std::vector<std::pair<int, T>>> &g) {\n\
    \    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,\n\
    \                        std::greater<std::pair<T, int>>>\n        que;\n    int\
    \ n = int(g.size());\n    std::vector<T> d(n, std::numeric_limits<T>::max());\n\
    \    d[s] = 0;\n    que.emplace(0, s);\n    while (!que.empty()) {\n        auto\
    \ [dist, pos] = que.top();\n        que.pop();\n        if (d[pos] < dist) continue;\n\
    \        for (auto [to, cost] : g[pos]) {\n            if (d[pos] + cost < d[to])\
    \ {\n                d[to] = d[pos] + cost;\n                que.emplace(d[to],\
    \ to);\n            }\n        }\n    }\n    return d;\n}\n"
  code: "#pragma once\n#include <limits>\n#include <queue>\n#include <vector>\ntemplate\
    \ <typename T>\nstd::vector<T> dijkstra(int s,\n                        const\
    \ std::vector<std::vector<std::pair<int, T>>> &g) {\n    std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>,\n                        std::greater<std::pair<T,\
    \ int>>>\n        que;\n    int n = int(g.size());\n    std::vector<T> d(n, std::numeric_limits<T>::max());\n\
    \    d[s] = 0;\n    que.emplace(0, s);\n    while (!que.empty()) {\n        auto\
    \ [dist, pos] = que.top();\n        que.pop();\n        if (d[pos] < dist) continue;\n\
    \        for (auto [to, cost] : g[pos]) {\n            if (d[pos] + cost < d[to])\
    \ {\n                d[to] = d[pos] + cost;\n                que.emplace(d[to],\
    \ to);\n            }\n        }\n    }\n    return d;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-09-01 13:39:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
