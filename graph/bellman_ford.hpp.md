---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_B.test.cpp
    title: test/aoj/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/bellman_ford.test.cpp
    title: test/unit/bellman_ford.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/bellman_ford.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <limits>\n#include <tuple>\n#include <vector>\ntemplate\
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
    \    std::vector<int> _prev;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <tuple>\n#include <vector>\ntemplate <class T> struct bellman_ford {\n\
    public:\n    bellman_ford() : bellman_ford(0) {\n    }\n    explicit bellman_ford(int\
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
    \ int, T>> edges;\n    std::vector<T> _dist;\n    std::vector<int> _prev;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2026-10-29 08:50:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/bellman_ford.test.cpp
  - test/aoj/GRL_1_B.test.cpp
documentation_of: graph/bellman_ford.hpp
layout: document
title: "Bellman\u2013Ford \u6CD5"
---

### 概要
- Bellman–Ford 法で負辺を含むグラフの単一始点最短路を求める。

### 使い方
- `bellman_ford<T> bf(n)`: 頂点数 `n`、辺の重みの型 `T`。
- `add_edge(from, to, w)`: 重み `w` の有向辺を追加する。
- `solve(s)`: 頂点 `s` を始点として最短路を求める。
- `dist(v)`: `s` から `v` への最短距離。到達不能なら `std::numeric_limits<T>::max()`、下に有界でなければ `std::numeric_limits<T>::lowest()`。
- `prev(v)`: 最短路における `v` の直前の頂点。`s` と到達不能な頂点では `-1`。
- `reachable(v)`: `s` から `v` に到達可能か。
- `unbounded(v)`: `s` から負閉路を通って `v` に到達可能か。
- `has_negative_cycle()`: `s` から到達可能な負閉路があるか。
- `path(t)`: `s` から `t` への最短路の頂点列。到達不能か下に有界でなければ空。

### 制約
- $N \cdot \max |w|$ が `T` の範囲に収まる

### 計算量
- `solve`: $\mathcal{O}(NM)$
- `has_negative_cycle`, `path`: $\mathcal{O}(N)$
- その他: $\mathcal{O}(1)$

### 問題例
AOJ GRL_1_B - Single Source Shortest Path (Negative Edges)（[問題](https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B)）

```cpp
#include <iostream>

#include "graph/bellman_ford.hpp"
int main() {
    int n, m, r;
    std::cin >> n >> m >> r;
    bellman_ford<long long> bf(n);
    for (int i = 0; i < m; i++) {
        int s, t;
        long long d;
        std::cin >> s >> t >> d;
        bf.add_edge(s, t, d);
    }
    bf.solve(r);
    if (bf.has_negative_cycle()) {
        std::cout << "NEGATIVE CYCLE\n";
        return 0;
    }
    for (int v = 0; v < n; v++) {
        if (bf.reachable(v)) {
            std::cout << bf.dist(v) << '\n';
        } else {
            std::cout << "INF\n";
        }
    }
}
```
