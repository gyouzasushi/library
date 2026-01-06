---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/bfs_tree_of_complement.hpp
    title: graph/bfs_tree_of_complement.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/connected_components_of_complement_graph
    links:
    - https://judge.yosupo.jp/problem/connected_components_of_complement_graph
  bundledCode: "#line 1 \"test/library-checker/connected_components_of_complement_graph.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/connected_components_of_complement_graph\"\
    \n#include <iostream>\n\n#line 2 \"graph/bfs_tree_of_complement.hpp\"\n#include\
    \ <algorithm>\n#include <numeric>\n#include <queue>\n#include <vector>\nstd::vector<std::vector<int>>\
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
    \      }\n        }\n    }\n    return ret;\n}\n#line 6 \"test/library-checker/connected_components_of_complement_graph.test.cpp\"\
    \nint main() {\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<std::vector<int>>\
    \ g(n);\n    for (int i = 0; i < m; i++) {\n        int u, v;\n        std::cin\
    \ >> u >> v;\n        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n\
    \    std::vector adj = bfs_tree_of_complement(g);\n    std::vector<std::vector<int>>\
    \ ans;\n    std::vector used(n, false);\n    auto dfs = [&](auto dfs, int u) ->\
    \ void {\n        used[u] = true;\n        ans.back().push_back(u);\n        for\
    \ (int v : adj[u]) {\n            dfs(dfs, v);\n        }\n    };\n    for (int\
    \ i = 0; i < n; i++) {\n        if (used[i]) continue;\n        ans.push_back({});\n\
    \        dfs(dfs, i);\n    }\n    int k = ans.size();\n    std::cout << k << '\\\
    n';\n    for (const std::vector<int>& v : ans) {\n        int l = v.size();\n\
    \        std::cout << l << ' ';\n        for (int i = 0; i < l; i++) {\n     \
    \       std::cout << v[i] << \" \\n\"[i == l - 1];\n        }\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/connected_components_of_complement_graph\"\
    \n#include <iostream>\n\n#include \"graph/bfs_tree_of_complement.hpp\"\nint main()\
    \ {\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<std::vector<int>>\
    \ g(n);\n    for (int i = 0; i < m; i++) {\n        int u, v;\n        std::cin\
    \ >> u >> v;\n        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n\
    \    std::vector adj = bfs_tree_of_complement(g);\n    std::vector<std::vector<int>>\
    \ ans;\n    std::vector used(n, false);\n    auto dfs = [&](auto dfs, int u) ->\
    \ void {\n        used[u] = true;\n        ans.back().push_back(u);\n        for\
    \ (int v : adj[u]) {\n            dfs(dfs, v);\n        }\n    };\n    for (int\
    \ i = 0; i < n; i++) {\n        if (used[i]) continue;\n        ans.push_back({});\n\
    \        dfs(dfs, i);\n    }\n    int k = ans.size();\n    std::cout << k << '\\\
    n';\n    for (const std::vector<int>& v : ans) {\n        int l = v.size();\n\
    \        std::cout << l << ' ';\n        for (int i = 0; i < l; i++) {\n     \
    \       std::cout << v[i] << \" \\n\"[i == l - 1];\n        }\n    }\n}"
  dependsOn:
  - graph/bfs_tree_of_complement.hpp
  isVerificationFile: true
  path: test/library-checker/connected_components_of_complement_graph.test.cpp
  requiredBy: []
  timestamp: '2024-06-29 13:06:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/connected_components_of_complement_graph.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/connected_components_of_complement_graph.test.cpp
- /verify/test/library-checker/connected_components_of_complement_graph.test.cpp.html
title: test/library-checker/connected_components_of_complement_graph.test.cpp
---
