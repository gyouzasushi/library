---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.hpp
    title: "Bellman\u2013Ford \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
  bundledCode: "#line 1 \"test/aoj/GRL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B\"\
    \n#include <iostream>\n\n#line 2 \"graph/bellman_ford.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <tuple>\n#include <vector>\ntemplate\
    \ <class T> struct bellman_ford {\npublic:\n    bellman_ford() : bellman_ford(0)\
    \ {\n    }\n    explicit bellman_ford(int n) : _n(n), _dist(n, inf), _prev(n,\
    \ -1) {\n    }\n    void add_edge(int from, int to, T w) {\n        assert(0 <=\
    \ from && from < _n);\n        assert(0 <= to && to < _n);\n        edges.emplace_back(from,\
    \ to, w);\n    }\n    void solve(int s) {\n        assert(0 <= s && s < _n);\n\
    \        _dist.assign(_n, inf);\n        _prev.assign(_n, -1);\n        _dist[s]\
    \ = 0;\n        for (int i = 0; i < _n - 1; i++) {\n            bool updated =\
    \ false;\n            for (auto [u, v, w] : edges) {\n                if (_dist[u]\
    \ == inf) continue;\n                if (_dist[u] + w < _dist[v]) {\n        \
    \            _dist[v] = _dist[u] + w;\n                    _prev[v] = u;\n   \
    \                 updated = true;\n                }\n            }\n        \
    \    if (!updated) return;\n        }\n        for (int i = 0; i < _n; i++) {\n\
    \            bool updated = false;\n            for (auto [u, v, w] : edges) {\n\
    \                if (_dist[u] == inf || _dist[v] == ninf) continue;\n        \
    \        if (_dist[u] == ninf || _dist[u] + w < _dist[v]) {\n                \
    \    _dist[v] = ninf;\n                    updated = true;\n                }\n\
    \            }\n            if (!updated) return;\n        }\n    }\n    T dist(int\
    \ v) const {\n        assert(0 <= v && v < _n);\n        return _dist[v];\n  \
    \  }\n    int prev(int v) const {\n        assert(0 <= v && v < _n);\n       \
    \ return _prev[v];\n    }\n    bool reachable(int v) const {\n        assert(0\
    \ <= v && v < _n);\n        return _dist[v] != inf;\n    }\n    bool unbounded(int\
    \ v) const {\n        assert(0 <= v && v < _n);\n        return _dist[v] == ninf;\n\
    \    }\n    bool has_negative_cycle() const {\n        return std::ranges::find(_dist,\
    \ ninf) != _dist.end();\n    }\n    std::vector<int> path(int t) const {\n   \
    \     assert(0 <= t && t < _n);\n        if (_dist[t] == inf || _dist[t] == ninf)\
    \ return {};\n        std::vector<int> res;\n        for (int v = t; v != -1;\
    \ v = _prev[v]) res.push_back(v);\n        std::ranges::reverse(res);\n      \
    \  return res;\n    }\n\nprivate:\n    static constexpr T inf = std::numeric_limits<T>::max();\n\
    \    static constexpr T ninf = std::numeric_limits<T>::lowest();\n    int _n;\n\
    \    std::vector<std::tuple<int, int, T>> edges;\n    std::vector<T> _dist;\n\
    \    std::vector<int> _prev;\n};\n#line 5 \"test/aoj/GRL_1_B.test.cpp\"\nint main()\
    \ {\n    int n, m, r;\n    std::cin >> n >> m >> r;\n    bellman_ford<long long>\
    \ bf(n);\n    for (int i = 0; i < m; i++) {\n        int s, t;\n        long long\
    \ d;\n        std::cin >> s >> t >> d;\n        bf.add_edge(s, t, d);\n    }\n\
    \    bf.solve(r);\n    if (bf.has_negative_cycle()) {\n        std::cout << \"\
    NEGATIVE CYCLE\\n\";\n        return 0;\n    }\n    for (int v = 0; v < n; v++)\
    \ {\n        if (bf.reachable(v)) {\n            std::cout << bf.dist(v) << '\\\
    n';\n        } else {\n            std::cout << \"INF\\n\";\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B\"\n#include\
    \ <iostream>\n\n#include \"graph/bellman_ford.hpp\"\nint main() {\n    int n,\
    \ m, r;\n    std::cin >> n >> m >> r;\n    bellman_ford<long long> bf(n);\n  \
    \  for (int i = 0; i < m; i++) {\n        int s, t;\n        long long d;\n  \
    \      std::cin >> s >> t >> d;\n        bf.add_edge(s, t, d);\n    }\n    bf.solve(r);\n\
    \    if (bf.has_negative_cycle()) {\n        std::cout << \"NEGATIVE CYCLE\\n\"\
    ;\n        return 0;\n    }\n    for (int v = 0; v < n; v++) {\n        if (bf.reachable(v))\
    \ {\n            std::cout << bf.dist(v) << '\\n';\n        } else {\n       \
    \     std::cout << \"INF\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - graph/bellman_ford.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2026-10-29 08:50:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_B.test.cpp
- /verify/test/aoj/GRL_1_B.test.cpp.html
title: test/aoj/GRL_1_B.test.cpp
---
