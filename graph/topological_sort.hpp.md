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
  bundledCode: "#line 2 \"graph/topological_sort.hpp\"\n#include <queue>\nstd::vector<int>\
    \ topological_sort(const std::vector<std::vector<int>> &g) {\n    int n = g.size();\n\
    \    std::vector<int> deg(n);\n    for (int i = 0; i < n; i++) {\n        for\
    \ (int j : g[i]) {\n            deg[j]++;\n        }\n    }\n    std::vector<int>\
    \ ret;\n    std::queue<int> q;\n    for (int i = 0; i < n; i++) {\n        if\
    \ (deg[i] == 0) {\n            q.push(i);\n        }\n    }\n    while (!q.empty())\
    \ {\n        int u = q.front();\n        q.pop();\n        ret.push_back(u);\n\
    \        for (int v : g[u]) {\n            if (--deg[v] == 0) {\n            \
    \    q.push(v);\n            }\n        }\n    }\n    if (int(ret.size()) != n)\
    \ {\n        return {};\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <queue>\nstd::vector<int> topological_sort(const std::vector<std::vector<int>>\
    \ &g) {\n    int n = g.size();\n    std::vector<int> deg(n);\n    for (int i =\
    \ 0; i < n; i++) {\n        for (int j : g[i]) {\n            deg[j]++;\n    \
    \    }\n    }\n    std::vector<int> ret;\n    std::queue<int> q;\n    for (int\
    \ i = 0; i < n; i++) {\n        if (deg[i] == 0) {\n            q.push(i);\n \
    \       }\n    }\n    while (!q.empty()) {\n        int u = q.front();\n     \
    \   q.pop();\n        ret.push_back(u);\n        for (int v : g[u]) {\n      \
    \      if (--deg[v] == 0) {\n                q.push(v);\n            }\n     \
    \   }\n    }\n    if (int(ret.size()) != n) {\n        return {};\n    }\n   \
    \ return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2024-06-04 13:53:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topological_sort.hpp
layout: document
redirect_from:
- /library/graph/topological_sort.hpp
- /library/graph/topological_sort.hpp.html
title: graph/topological_sort.hpp
---
