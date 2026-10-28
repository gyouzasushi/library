---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/shortest_path.test.cpp
    title: test/library-checker/shortest_path.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <limits>\n#include <queue>\n#include <vector>\ntemplate <class T> struct\
    \ dijkstra {\npublic:\n    dijkstra() : dijkstra(0) {\n    }\n    explicit dijkstra(int\
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
    \ _dist;\n    std::vector<int> _prev;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <queue>\n#include <vector>\ntemplate <class T> struct dijkstra {\npublic:\n\
    \    dijkstra() : dijkstra(0) {\n    }\n    explicit dijkstra(int n) : _n(n),\
    \ g(n), _dist(n, inf), _prev(n, -1) {\n    }\n    void add_edge(int from, int\
    \ to, T w) {\n        assert(0 <= from && from < _n);\n        assert(0 <= to\
    \ && to < _n);\n        g[from].emplace_back(to, w);\n    }\n    void solve(int\
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
    \ _dist;\n    std::vector<int> _prev;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/shortest_path.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
title: "Dijkstra \u6CD5"
---

### 概要
- Dijkstra 法で単一始点最短路を求める。

### 使い方
- `dijkstra<T> d(n)`: 頂点数 `n`、辺の重みの型 `T`。
- `add_edge(from, to, w)`: 重み `w` の有向辺を追加する。
- `solve(s)`: 頂点 `s` を始点として最短路を求める。
- `dist(v)`: `s` から `v` への最短距離。到達不能なら `std::numeric_limits<T>::max()`。
- `prev(v)`: 最短路における `v` の直前の頂点。`s` と到達不能な頂点では `-1`。
- `reachable(v)`: `s` から `v` に到達可能か。
- `path(t)`: `s` から `t` への最短路の頂点列。到達不能なら空。

### 計算量
- `solve`: $\mathcal{O}((N + M) \log N)$
- `path`: $\mathcal{O}(N)$
- その他: $\mathcal{O}(1)$

### 問題例
Library Checker - Shortest Path（[問題](https://judge.yosupo.jp/problem/shortest_path)）

```cpp
#include <iostream>

#include "graph/dijkstra.hpp"
int main() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    dijkstra<long long> d(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        d.add_edge(a, b, c);
    }
    d.solve(s);
    if (!d.reachable(t)) {
        std::cout << -1 << '\n';
        return 0;
    }
    std::vector<int> path = d.path(t);
    std::cout << d.dist(t) << ' ' << path.size() - 1 << '\n';
    for (int i = 0; i + 1 < int(path.size()); i++) {
        std::cout << path[i] << ' ' << path[i + 1] << '\n';
    }
}
```
