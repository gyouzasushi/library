---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: "Dijkstra \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/library-checker/shortest_path.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/shortest_path\"\n#include <algorithm>\n#include\
    \ <iostream>\n\n#line 2 \"graph/dijkstra.hpp\"\n#include <limits>\n#include <queue>\n\
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
    \ to);\n            }\n        }\n    }\n    return {d, from};\n}\n#line 6 \"\
    test/library-checker/shortest_path.test.cpp\"\nint main() {\n    int n, m, s,\
    \ t;\n    std::cin >> n >> m >> s >> t;\n    std::vector<std::vector<std::pair<int,\
    \ long long>>> g(n);\n    for (int i = 0; i < m; i++) {\n        int a, b;\n \
    \       long long c;\n        std::cin >> a >> b >> c;\n        g[a].emplace_back(b,\
    \ c);\n    }\n\n    auto [dist, from] = dijkstra(s, g);\n    if (dist[t] == std::numeric_limits<long\
    \ long>::max()) {\n        std::cout << -1 << '\\n';\n        return 0;\n    }\n\
    \n    int pos = t;\n    std::vector<int> path;\n    while (pos != -1) {\n    \
    \    path.push_back(pos);\n        pos = from[pos];\n    };\n    std::reverse(path.begin(),\
    \ path.end());\n\n    std::cout << dist[t] << ' ' << path.size() - 1 << '\\n';\n\
    \    for (int i = 0; i + 1 < int(path.size()); i++) {\n        std::cout << path[i]\
    \ << ' ' << path[i + 1] << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ <algorithm>\n#include <iostream>\n\n#include \"../../graph/dijkstra.hpp\"\n\
    int main() {\n    int n, m, s, t;\n    std::cin >> n >> m >> s >> t;\n    std::vector<std::vector<std::pair<int,\
    \ long long>>> g(n);\n    for (int i = 0; i < m; i++) {\n        int a, b;\n \
    \       long long c;\n        std::cin >> a >> b >> c;\n        g[a].emplace_back(b,\
    \ c);\n    }\n\n    auto [dist, from] = dijkstra(s, g);\n    if (dist[t] == std::numeric_limits<long\
    \ long>::max()) {\n        std::cout << -1 << '\\n';\n        return 0;\n    }\n\
    \n    int pos = t;\n    std::vector<int> path;\n    while (pos != -1) {\n    \
    \    path.push_back(pos);\n        pos = from[pos];\n    };\n    std::reverse(path.begin(),\
    \ path.end());\n\n    std::cout << dist[t] << ' ' << path.size() - 1 << '\\n';\n\
    \    for (int i = 0; i + 1 < int(path.size()); i++) {\n        std::cout << path[i]\
    \ << ' ' << path[i + 1] << '\\n';\n    }\n}"
  dependsOn:
  - graph/dijkstra.hpp
  isVerificationFile: true
  path: test/library-checker/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2022-09-03 17:27:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/shortest_path.test.cpp
- /verify/test/library-checker/shortest_path.test.cpp.html
title: test/library-checker/shortest_path.test.cpp
---
