---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/topological_sort.test.cpp
    title: test/unit/topological_sort.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/topological_sort.hpp\"\n#include <functional>\n#include\
    \ <optional>\n#include <queue>\n#include <vector>\ntemplate <class Compare>\n\
    std::optional<std::vector<int>> topological_sort(const std::vector<std::vector<int>>&\
    \ g, Compare comp) {\n    int n = int(g.size());\n    std::vector<int> deg(n);\n\
    \    for (int u = 0; u < n; u++) {\n        for (int v : g[u]) deg[v]++;\n   \
    \ }\n    auto rev = [&](int a, int b) { return comp(b, a); };\n    std::priority_queue<int,\
    \ std::vector<int>, decltype(rev)> q(rev);\n    for (int v = 0; v < n; v++) {\n\
    \        if (deg[v] == 0) q.push(v);\n    }\n    std::vector<int> order;\n   \
    \ order.reserve(n);\n    while (!q.empty()) {\n        int u = q.top();\n    \
    \    q.pop();\n        order.push_back(u);\n        for (int v : g[u]) {\n   \
    \         if (--deg[v] == 0) q.push(v);\n        }\n    }\n    if (int(order.size())\
    \ != n) return std::nullopt;\n    return order;\n}\nstd::optional<std::vector<int>>\
    \ topological_sort(const std::vector<std::vector<int>>& g) {\n    int n = int(g.size());\n\
    \    std::vector<int> deg(n);\n    for (int u = 0; u < n; u++) {\n        for\
    \ (int v : g[u]) deg[v]++;\n    }\n    std::queue<int> q;\n    for (int v = 0;\
    \ v < n; v++) {\n        if (deg[v] == 0) q.push(v);\n    }\n    std::vector<int>\
    \ order;\n    order.reserve(n);\n    while (!q.empty()) {\n        int u = q.front();\n\
    \        q.pop();\n        order.push_back(u);\n        for (int v : g[u]) {\n\
    \            if (--deg[v] == 0) q.push(v);\n        }\n    }\n    if (int(order.size())\
    \ != n) return std::nullopt;\n    return order;\n}\n"
  code: "#pragma once\n#include <functional>\n#include <optional>\n#include <queue>\n\
    #include <vector>\ntemplate <class Compare>\nstd::optional<std::vector<int>> topological_sort(const\
    \ std::vector<std::vector<int>>& g, Compare comp) {\n    int n = int(g.size());\n\
    \    std::vector<int> deg(n);\n    for (int u = 0; u < n; u++) {\n        for\
    \ (int v : g[u]) deg[v]++;\n    }\n    auto rev = [&](int a, int b) { return comp(b,\
    \ a); };\n    std::priority_queue<int, std::vector<int>, decltype(rev)> q(rev);\n\
    \    for (int v = 0; v < n; v++) {\n        if (deg[v] == 0) q.push(v);\n    }\n\
    \    std::vector<int> order;\n    order.reserve(n);\n    while (!q.empty()) {\n\
    \        int u = q.top();\n        q.pop();\n        order.push_back(u);\n   \
    \     for (int v : g[u]) {\n            if (--deg[v] == 0) q.push(v);\n      \
    \  }\n    }\n    if (int(order.size()) != n) return std::nullopt;\n    return\
    \ order;\n}\nstd::optional<std::vector<int>> topological_sort(const std::vector<std::vector<int>>&\
    \ g) {\n    int n = int(g.size());\n    std::vector<int> deg(n);\n    for (int\
    \ u = 0; u < n; u++) {\n        for (int v : g[u]) deg[v]++;\n    }\n    std::queue<int>\
    \ q;\n    for (int v = 0; v < n; v++) {\n        if (deg[v] == 0) q.push(v);\n\
    \    }\n    std::vector<int> order;\n    order.reserve(n);\n    while (!q.empty())\
    \ {\n        int u = q.front();\n        q.pop();\n        order.push_back(u);\n\
    \        for (int v : g[u]) {\n            if (--deg[v] == 0) q.push(v);\n   \
    \     }\n    }\n    if (int(order.size()) != n) return std::nullopt;\n    return\
    \ order;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:58:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/topological_sort.test.cpp
documentation_of: graph/topological_sort.hpp
layout: document
title: Topological Sort
---

### 概要
- 有向グラフの頂点を、すべての辺 $(u, v)$ について $u$ が $v$ より前に来るように並べる。

### 使い方
- `topological_sort(g)`: 隣接リスト `g` の頂点のトポロジカル順序を返す。サイクルがあれば `std::nullopt` を返す。
- `topological_sort(g, comp)`: 各時点で `comp` の意味で最小の頂点を先に出す順序を返す。`comp(a, b)` が真なら `a` が先。辞書順最小は `std::less<int>()`。

### 計算量
- `topological_sort(g)`: $\mathcal{O}(N + M)$
- `topological_sort(g, comp)`: $\mathcal{O}((N + M) \log N)$
