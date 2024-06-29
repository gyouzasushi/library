---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/connected_components_of_complement_graph.test.cpp
    title: test/library-checker/connected_components_of_complement_graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/bfs_tree_of_complement.hpp\"\n#include <algorithm>\n\
    #include <numeric>\n#include <queue>\n#include <vector>\nstd::vector<std::vector<int>>\
    \ bfs_tree_of_complement(\n    const std::vector<std::vector<int>>& g) {\n   \
    \ int n = int(g.size());\n    std::vector<std::vector<int>> ret(n);\n    std::vector<bool>\
    \ seen(n);\n    std::vector<bool> banned(n);\n    std::queue<int> q;\n    std::vector<int>\
    \ s(n), t;\n    std::iota(s.begin(), s.end(), 0);\n    for (int i = 0; i < n;\
    \ i++) {\n        if (seen[i]) continue;\n        seen[i] = true;\n        q.push(i);\n\
    \        while (!q.empty()) {\n            int u = q.front();\n            q.pop();\n\
    \            seen[u] = true;\n            for (int v : g[u]) {\n             \
    \   banned[v] = true;\n            }\n            for (int v : s) {\n        \
    \        if (banned[v]) {\n                    t.push_back(v);\n             \
    \   } else if (!seen[v]) {\n                    ret[u].push_back(v);\n       \
    \             q.push(v);\n                }\n            }\n            s = std::move(t);\n\
    \            for (int v : g[u]) {\n                banned[v] = false;\n      \
    \      }\n        }\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <queue>\n\
    #include <vector>\nstd::vector<std::vector<int>> bfs_tree_of_complement(\n   \
    \ const std::vector<std::vector<int>>& g) {\n    int n = int(g.size());\n    std::vector<std::vector<int>>\
    \ ret(n);\n    std::vector<bool> seen(n);\n    std::vector<bool> banned(n);\n\
    \    std::queue<int> q;\n    std::vector<int> s(n), t;\n    std::iota(s.begin(),\
    \ s.end(), 0);\n    for (int i = 0; i < n; i++) {\n        if (seen[i]) continue;\n\
    \        seen[i] = true;\n        q.push(i);\n        while (!q.empty()) {\n \
    \           int u = q.front();\n            q.pop();\n            seen[u] = true;\n\
    \            for (int v : g[u]) {\n                banned[v] = true;\n       \
    \     }\n            for (int v : s) {\n                if (banned[v]) {\n   \
    \                 t.push_back(v);\n                } else if (!seen[v]) {\n  \
    \                  ret[u].push_back(v);\n                    q.push(v);\n    \
    \            }\n            }\n            s = std::move(t);\n            for\
    \ (int v : g[u]) {\n                banned[v] = false;\n            }\n      \
    \  }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/bfs_tree_of_complement.hpp
  requiredBy: []
  timestamp: '2024-06-29 13:06:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/connected_components_of_complement_graph.test.cpp
documentation_of: graph/bfs_tree_of_complement.hpp
layout: document
redirect_from:
- /library/graph/bfs_tree_of_complement.hpp
- /library/graph/bfs_tree_of_complement.hpp.html
title: graph/bfs_tree_of_complement.hpp
---
