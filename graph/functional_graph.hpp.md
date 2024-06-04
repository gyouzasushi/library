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
  bundledCode: "#line 2 \"graph/functional_graph.hpp\"\n\n#include <algorithm>\n#include\
    \ <vector>\nstruct functional_graph {\npublic:\n    functional_graph(int n) :\
    \ _n(n), graph(n) {\n    }\n    void add_edge(int u, int v) {\n        graph[u].push_back(v);\n\
    \        graph[v].push_back(u);\n    }\n    void add_directed_edge(int from, int\
    \ to) {\n        graph[from].push_back(to);\n    }\n    std::vector<int> loop()\
    \ {\n        std::vector<int> path;\n        std::vector<int> check(_n, 0);\n\
    \        auto dfs = [&](auto dfs, int u, int p) -> int {\n            check[u]++;\n\
    \            path.push_back(u);\n            for (int v : graph[u]) {\n      \
    \          // if (v == p) continue;\n                if (check[v] == 0) {\n  \
    \                  int ret = dfs(dfs, v, u);\n                    if (ret != -1)\
    \ return ret;\n                } else if (check[v] == 1) {\n                 \
    \   return v;\n                }\n            }\n            path.pop_back();\n\
    \            check[u]++;\n            return -1;\n        };\n        int p =\
    \ dfs(dfs, 0, -1);\n        std::vector<int>::iterator it = std::find(path.begin(),\
    \ path.end(), p);\n        return std::vector(it, path.end());\n    }\n    std::vector<std::vector<std::pair<int,\
    \ int>>> tree() {\n        std::vector<int> _loop = loop();\n        std::vector<std::vector<std::pair<int,\
    \ int>>> ret(_loop.size());\n        int k = _loop.size();\n        for (int i\
    \ = 0; i < k; i++) {\n            auto dfs = [&](auto dfs, int u, int p) -> void\
    \ {\n                for (int v : graph[u]) {\n                    if (v == p)\
    \ continue;\n                    if (v == _loop[i + 1 == k ? 0 : i + 1]) continue;\n\
    \                    if (v == _loop[i == 0 ? k - 1 : i - 1]) continue;\n     \
    \               ret[i].emplace_back(u, v);\n                    dfs(dfs, v, u);\n\
    \                }\n            };\n            dfs(dfs, _loop[i], -1);\n    \
    \    }\n        return ret;\n    }\n\nprivate:\n    int _n;\n    std::vector<std::vector<int>>\
    \ graph;\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\nstruct functional_graph\
    \ {\npublic:\n    functional_graph(int n) : _n(n), graph(n) {\n    }\n    void\
    \ add_edge(int u, int v) {\n        graph[u].push_back(v);\n        graph[v].push_back(u);\n\
    \    }\n    void add_directed_edge(int from, int to) {\n        graph[from].push_back(to);\n\
    \    }\n    std::vector<int> loop() {\n        std::vector<int> path;\n      \
    \  std::vector<int> check(_n, 0);\n        auto dfs = [&](auto dfs, int u, int\
    \ p) -> int {\n            check[u]++;\n            path.push_back(u);\n     \
    \       for (int v : graph[u]) {\n                // if (v == p) continue;\n \
    \               if (check[v] == 0) {\n                    int ret = dfs(dfs, v,\
    \ u);\n                    if (ret != -1) return ret;\n                } else\
    \ if (check[v] == 1) {\n                    return v;\n                }\n   \
    \         }\n            path.pop_back();\n            check[u]++;\n         \
    \   return -1;\n        };\n        int p = dfs(dfs, 0, -1);\n        std::vector<int>::iterator\
    \ it = std::find(path.begin(), path.end(), p);\n        return std::vector(it,\
    \ path.end());\n    }\n    std::vector<std::vector<std::pair<int, int>>> tree()\
    \ {\n        std::vector<int> _loop = loop();\n        std::vector<std::vector<std::pair<int,\
    \ int>>> ret(_loop.size());\n        int k = _loop.size();\n        for (int i\
    \ = 0; i < k; i++) {\n            auto dfs = [&](auto dfs, int u, int p) -> void\
    \ {\n                for (int v : graph[u]) {\n                    if (v == p)\
    \ continue;\n                    if (v == _loop[i + 1 == k ? 0 : i + 1]) continue;\n\
    \                    if (v == _loop[i == 0 ? k - 1 : i - 1]) continue;\n     \
    \               ret[i].emplace_back(u, v);\n                    dfs(dfs, v, u);\n\
    \                }\n            };\n            dfs(dfs, _loop[i], -1);\n    \
    \    }\n        return ret;\n    }\n\nprivate:\n    int _n;\n    std::vector<std::vector<int>>\
    \ graph;\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/functional_graph.hpp
  requiredBy: []
  timestamp: '2024-06-04 13:53:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/functional_graph.hpp
layout: document
redirect_from:
- /library/graph/functional_graph.hpp
- /library/graph/functional_graph.hpp.html
title: graph/functional_graph.hpp
---
