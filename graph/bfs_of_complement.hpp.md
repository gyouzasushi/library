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
  bundledCode: "#line 2 \"graph/bfs_of_complement.hpp\"\n#include <algorithm>\n#include\
    \ <queue>\n#include <vector>\nvoid bfs_of_complement(const std::vector<std::vector<int>>&\
    \ g) {\n    int n = int(g.size());\n    std::queue<int> Q;\n    Q.push(0);\n \
    \   std::vector<int> S;\n    for (int i = 1; i < n; i++) S.push_back(i);\n   \
    \ while (!Q.empty()) {\n        int v = Q.front();\n        Q.pop();\n       \
    \ std::vector<int> L;\n        for (int u : g[v]) {\n            if (std::count(S.begin(),\
    \ S.end(), u)) {\n                S.erase(std::find(S.begin(), S.end(), u));\n\
    \                L.push_back(u);\n            }\n        }\n    }\n    return;\n\
    }\n"
  code: "#pragma once\n#include <algorithm>\n#include <queue>\n#include <vector>\n\
    void bfs_of_complement(const std::vector<std::vector<int>>& g) {\n    int n =\
    \ int(g.size());\n    std::queue<int> Q;\n    Q.push(0);\n    std::vector<int>\
    \ S;\n    for (int i = 1; i < n; i++) S.push_back(i);\n    while (!Q.empty())\
    \ {\n        int v = Q.front();\n        Q.pop();\n        std::vector<int> L;\n\
    \        for (int u : g[v]) {\n            if (std::count(S.begin(), S.end(),\
    \ u)) {\n                S.erase(std::find(S.begin(), S.end(), u));\n        \
    \        L.push_back(u);\n            }\n        }\n    }\n    return;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/bfs_of_complement.hpp
  requiredBy: []
  timestamp: '2022-09-01 13:39:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bfs_of_complement.hpp
layout: document
redirect_from:
- /library/graph/bfs_of_complement.hpp
- /library/graph/bfs_of_complement.hpp.html
title: graph/bfs_of_complement.hpp
---
