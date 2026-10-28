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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unit/bellman_ford.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\n#line 4 \"graph/bellman_ford.hpp\"\n#include <limits>\n#include\
    \ <tuple>\n#line 7 \"graph/bellman_ford.hpp\"\ntemplate <class T> struct bellman_ford\
    \ {\npublic:\n    bellman_ford() : bellman_ford(0) {\n    }\n    explicit bellman_ford(int\
    \ n) : _n(n), _dist(n, inf), _prev(n, -1) {\n    }\n    void add_edge(int from,\
    \ int to, T w) {\n        assert(0 <= from && from < _n);\n        assert(0 <=\
    \ to && to < _n);\n        edges.emplace_back(from, to, w);\n    }\n    void solve(int\
    \ s) {\n        assert(0 <= s && s < _n);\n        _dist.assign(_n, inf);\n  \
    \      _prev.assign(_n, -1);\n        _dist[s] = 0;\n        for (int i = 0; i\
    \ < _n - 1; i++) {\n            bool updated = false;\n            for (auto [u,\
    \ v, w] : edges) {\n                if (_dist[u] == inf) continue;\n         \
    \       if (_dist[u] + w < _dist[v]) {\n                    _dist[v] = _dist[u]\
    \ + w;\n                    _prev[v] = u;\n                    updated = true;\n\
    \                }\n            }\n            if (!updated) return;\n       \
    \ }\n        for (int i = 0; i < _n; i++) {\n            bool updated = false;\n\
    \            for (auto [u, v, w] : edges) {\n                if (_dist[u] == inf\
    \ || _dist[v] == ninf) continue;\n                if (_dist[u] == ninf || _dist[u]\
    \ + w < _dist[v]) {\n                    _dist[v] = ninf;\n                  \
    \  updated = true;\n                }\n            }\n            if (!updated)\
    \ return;\n        }\n    }\n    T dist(int v) const {\n        assert(0 <= v\
    \ && v < _n);\n        return _dist[v];\n    }\n    int prev(int v) const {\n\
    \        assert(0 <= v && v < _n);\n        return _prev[v];\n    }\n    bool\
    \ reachable(int v) const {\n        assert(0 <= v && v < _n);\n        return\
    \ _dist[v] != inf;\n    }\n    bool unbounded(int v) const {\n        assert(0\
    \ <= v && v < _n);\n        return _dist[v] == ninf;\n    }\n    bool has_negative_cycle()\
    \ const {\n        return std::ranges::find(_dist, ninf) != _dist.end();\n   \
    \ }\n    std::vector<int> path(int t) const {\n        assert(0 <= t && t < _n);\n\
    \        if (_dist[t] == inf || _dist[t] == ninf) return {};\n        std::vector<int>\
    \ res;\n        for (int v = t; v != -1; v = _prev[v]) res.push_back(v);\n   \
    \     std::ranges::reverse(res);\n        return res;\n    }\n\nprivate:\n   \
    \ static constexpr T inf = std::numeric_limits<T>::max();\n    static constexpr\
    \ T ninf = std::numeric_limits<T>::lowest();\n    int _n;\n    std::vector<std::tuple<int,\
    \ int, T>> edges;\n    std::vector<T> _dist;\n    std::vector<int> _prev;\n};\n\
    #line 9 \"test/unit/bellman_ford.test.cpp\"\nint main() {\n    std::mt19937 rng(20261029);\n\
    \    const long long inf = 1LL << 50;\n    for (int trial = 0; trial < 3000; trial++)\
    \ {\n        int n = 1 + rng() % 7;\n        int m = rng() % 13;\n        std::vector<std::vector<long\
    \ long>> w(n, std::vector<long long>(n, inf));\n        bellman_ford<long long>\
    \ bf(n);\n        for (int i = 0; i < m; i++) {\n            int u = rng() % n,\
    \ v = rng() % n;\n            long long c = (long long)(rng() % 9) - 3;\n    \
    \        w[u][v] = std::min(w[u][v], c);\n            bf.add_edge(u, v, c);\n\
    \        }\n        std::vector<std::vector<bool>> reach(n, std::vector<bool>(n,\
    \ false));\n        std::vector<std::vector<long long>> d(n, std::vector<long\
    \ long>(n, inf));\n        for (int i = 0; i < n; i++) {\n            reach[i][i]\
    \ = true;\n            d[i][i] = 0;\n            for (int j = 0; j < n; j++) {\n\
    \                if (w[i][j] != inf) {\n                    reach[i][j] = true;\n\
    \                    d[i][j] = std::min(d[i][j], w[i][j]);\n                }\n\
    \            }\n        }\n        for (int k = 0; k < n; k++) {\n           \
    \ for (int i = 0; i < n; i++) {\n                for (int j = 0; j < n; j++) {\n\
    \                    reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);\n\
    \                    if (d[i][k] != inf && d[k][j] != inf) d[i][j] = std::min(d[i][j],\
    \ d[i][k] + d[k][j]);\n                }\n            }\n        }\n        int\
    \ s = rng() % n;\n        bf.solve(s);\n        bool any_negative = false;\n \
    \       for (int v = 0; v < n; v++) {\n            bool unb = false;\n       \
    \     for (int k = 0; k < n; k++) {\n                if (reach[s][k] && d[k][k]\
    \ < 0 && reach[k][v]) unb = true;\n            }\n            any_negative = any_negative\
    \ || unb;\n            assert(bf.reachable(v) == reach[s][v]);\n            assert(bf.unbounded(v)\
    \ == unb);\n            if (!reach[s][v]) {\n                assert(bf.dist(v)\
    \ == std::numeric_limits<long long>::max());\n                assert(bf.prev(v)\
    \ == -1);\n                assert(bf.path(v).empty());\n            } else if\
    \ (unb) {\n                assert(bf.dist(v) == std::numeric_limits<long long>::lowest());\n\
    \                assert(bf.path(v).empty());\n            } else {\n         \
    \       assert(bf.dist(v) == d[s][v]);\n                std::vector<int> p = bf.path(v);\n\
    \                assert(!p.empty() && p.front() == s && p.back() == v);\n    \
    \            long long total = 0;\n                for (int i = 0; i + 1 < int(p.size());\
    \ i++) {\n                    assert(w[p[i]][p[i + 1]] != inf);\n            \
    \        total += w[p[i]][p[i + 1]];\n                }\n                assert(total\
    \ == d[s][v]);\n                assert(bf.prev(v) == (v == s ? -1 : p[p.size()\
    \ - 2]));\n            }\n        }\n        assert(bf.has_negative_cycle() ==\
    \ any_negative);\n    }\n    bellman_ford<double> bd(3);\n    bd.add_edge(0, 1,\
    \ 0.5);\n    bd.add_edge(1, 2, -1.5);\n    bd.solve(0);\n    assert(bd.dist(2)\
    \ == -1.0);\n    assert(!bd.has_negative_cycle());\n    std::cout << \"Hello World\\\
    n\";\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\n#include \"graph/bellman_ford.hpp\"\nint main() {\n    std::mt19937\
    \ rng(20261029);\n    const long long inf = 1LL << 50;\n    for (int trial = 0;\
    \ trial < 3000; trial++) {\n        int n = 1 + rng() % 7;\n        int m = rng()\
    \ % 13;\n        std::vector<std::vector<long long>> w(n, std::vector<long long>(n,\
    \ inf));\n        bellman_ford<long long> bf(n);\n        for (int i = 0; i <\
    \ m; i++) {\n            int u = rng() % n, v = rng() % n;\n            long long\
    \ c = (long long)(rng() % 9) - 3;\n            w[u][v] = std::min(w[u][v], c);\n\
    \            bf.add_edge(u, v, c);\n        }\n        std::vector<std::vector<bool>>\
    \ reach(n, std::vector<bool>(n, false));\n        std::vector<std::vector<long\
    \ long>> d(n, std::vector<long long>(n, inf));\n        for (int i = 0; i < n;\
    \ i++) {\n            reach[i][i] = true;\n            d[i][i] = 0;\n        \
    \    for (int j = 0; j < n; j++) {\n                if (w[i][j] != inf) {\n  \
    \                  reach[i][j] = true;\n                    d[i][j] = std::min(d[i][j],\
    \ w[i][j]);\n                }\n            }\n        }\n        for (int k =\
    \ 0; k < n; k++) {\n            for (int i = 0; i < n; i++) {\n              \
    \  for (int j = 0; j < n; j++) {\n                    reach[i][j] = reach[i][j]\
    \ || (reach[i][k] && reach[k][j]);\n                    if (d[i][k] != inf &&\
    \ d[k][j] != inf) d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);\n          \
    \      }\n            }\n        }\n        int s = rng() % n;\n        bf.solve(s);\n\
    \        bool any_negative = false;\n        for (int v = 0; v < n; v++) {\n \
    \           bool unb = false;\n            for (int k = 0; k < n; k++) {\n   \
    \             if (reach[s][k] && d[k][k] < 0 && reach[k][v]) unb = true;\n   \
    \         }\n            any_negative = any_negative || unb;\n            assert(bf.reachable(v)\
    \ == reach[s][v]);\n            assert(bf.unbounded(v) == unb);\n            if\
    \ (!reach[s][v]) {\n                assert(bf.dist(v) == std::numeric_limits<long\
    \ long>::max());\n                assert(bf.prev(v) == -1);\n                assert(bf.path(v).empty());\n\
    \            } else if (unb) {\n                assert(bf.dist(v) == std::numeric_limits<long\
    \ long>::lowest());\n                assert(bf.path(v).empty());\n           \
    \ } else {\n                assert(bf.dist(v) == d[s][v]);\n                std::vector<int>\
    \ p = bf.path(v);\n                assert(!p.empty() && p.front() == s && p.back()\
    \ == v);\n                long long total = 0;\n                for (int i = 0;\
    \ i + 1 < int(p.size()); i++) {\n                    assert(w[p[i]][p[i + 1]]\
    \ != inf);\n                    total += w[p[i]][p[i + 1]];\n                }\n\
    \                assert(total == d[s][v]);\n                assert(bf.prev(v)\
    \ == (v == s ? -1 : p[p.size() - 2]));\n            }\n        }\n        assert(bf.has_negative_cycle()\
    \ == any_negative);\n    }\n    bellman_ford<double> bd(3);\n    bd.add_edge(0,\
    \ 1, 0.5);\n    bd.add_edge(1, 2, -1.5);\n    bd.solve(0);\n    assert(bd.dist(2)\
    \ == -1.0);\n    assert(!bd.has_negative_cycle());\n    std::cout << \"Hello World\\\
    n\";\n}\n"
  dependsOn:
  - graph/bellman_ford.hpp
  isVerificationFile: true
  path: test/unit/bellman_ford.test.cpp
  requiredBy: []
  timestamp: '2026-10-29 08:50:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/bellman_ford.test.cpp
layout: document
redirect_from:
- /verify/test/unit/bellman_ford.test.cpp
- /verify/test/unit/bellman_ford.test.cpp.html
title: test/unit/bellman_ford.test.cpp
---
