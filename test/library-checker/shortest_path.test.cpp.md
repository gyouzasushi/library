---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/dijkstra.hpp
    title: "Dijkstra \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/library-checker/shortest_path.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/shortest_path\"\n#include <iostream>\n\n#line\
    \ 2 \"graph/dijkstra.hpp\"\n#include <algorithm>\n#include <cassert>\n#include\
    \ <limits>\n#include <queue>\n#include <vector>\ntemplate <class T> struct dijkstra\
    \ {\npublic:\n    dijkstra() : dijkstra(0) {\n    }\n    explicit dijkstra(int\
    \ n) : _n(n), g(n), _dist(n, inf), _prev(n, -1) {\n    }\n    void add_edge(int\
    \ from, int to, T w) {\n        assert(0 <= from && from < _n);\n        assert(0\
    \ <= to && to < _n);\n        g[from].emplace_back(to, w);\n    }\n    void solve(int\
    \ s) {\n        assert(0 <= s && s < _n);\n        _dist.assign(_n, inf);\n  \
    \      _prev.assign(_n, -1);\n        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T,\
    \ int>>,\n                            std::greater<std::pair<T, int>>>\n     \
    \       que;\n        _dist[s] = 0;\n        que.emplace(0, s);\n        while\
    \ (!que.empty()) {\n            auto [d, u] = que.top();\n            que.pop();\n\
    \            if (_dist[u] < d) continue;\n            for (auto [v, w] : g[u])\
    \ {\n                if (_dist[u] + w < _dist[v]) {\n                    _dist[v]\
    \ = _dist[u] + w;\n                    _prev[v] = u;\n                    que.emplace(_dist[v],\
    \ v);\n                }\n            }\n        }\n    }\n    T dist(int v) const\
    \ {\n        assert(0 <= v && v < _n);\n        return _dist[v];\n    }\n    int\
    \ prev(int v) const {\n        assert(0 <= v && v < _n);\n        return _prev[v];\n\
    \    }\n    bool reachable(int v) const {\n        assert(0 <= v && v < _n);\n\
    \        return _dist[v] != inf;\n    }\n    std::vector<int> path(int t) const\
    \ {\n        assert(0 <= t && t < _n);\n        if (_dist[t] == inf) return {};\n\
    \        std::vector<int> res;\n        for (int v = t; v != -1; v = _prev[v])\
    \ res.push_back(v);\n        std::ranges::reverse(res);\n        return res;\n\
    \    }\n\nprivate:\n    static constexpr T inf = std::numeric_limits<T>::max();\n\
    \    int _n;\n    std::vector<std::vector<std::pair<int, T>>> g;\n    std::vector<T>\
    \ _dist;\n    std::vector<int> _prev;\n};\n#line 5 \"test/library-checker/shortest_path.test.cpp\"\
    \nint main() {\n    int n, m, s, t;\n    std::cin >> n >> m >> s >> t;\n    dijkstra<long\
    \ long> d(n);\n    for (int i = 0; i < m; i++) {\n        int a, b;\n        long\
    \ long c;\n        std::cin >> a >> b >> c;\n        d.add_edge(a, b, c);\n  \
    \  }\n    d.solve(s);\n    if (!d.reachable(t)) {\n        std::cout << -1 <<\
    \ '\\n';\n        return 0;\n    }\n    std::vector<int> path = d.path(t);\n \
    \   std::cout << d.dist(t) << ' ' << path.size() - 1 << '\\n';\n    for (int i\
    \ = 0; i + 1 < int(path.size()); i++) {\n        std::cout << path[i] << ' ' <<\
    \ path[i + 1] << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ <iostream>\n\n#include \"graph/dijkstra.hpp\"\nint main() {\n    int n, m, s,\
    \ t;\n    std::cin >> n >> m >> s >> t;\n    dijkstra<long long> d(n);\n    for\
    \ (int i = 0; i < m; i++) {\n        int a, b;\n        long long c;\n       \
    \ std::cin >> a >> b >> c;\n        d.add_edge(a, b, c);\n    }\n    d.solve(s);\n\
    \    if (!d.reachable(t)) {\n        std::cout << -1 << '\\n';\n        return\
    \ 0;\n    }\n    std::vector<int> path = d.path(t);\n    std::cout << d.dist(t)\
    \ << ' ' << path.size() - 1 << '\\n';\n    for (int i = 0; i + 1 < int(path.size());\
    \ i++) {\n        std::cout << path[i] << ' ' << path[i + 1] << '\\n';\n    }\n\
    }\n"
  dependsOn:
  - graph/dijkstra.hpp
  isVerificationFile: true
  path: test/library-checker/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/shortest_path.test.cpp
- /verify/test/library-checker/shortest_path.test.cpp.html
title: test/library-checker/shortest_path.test.cpp
---
