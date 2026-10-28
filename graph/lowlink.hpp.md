---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_B.test.cpp
    title: test/aoj/GRL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/two_edge_connected_components.test.cpp
    title: test/library-checker/two_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/lowlink.test.cpp
    title: test/unit/lowlink.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/lowlink.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <utility>\n#include <vector>\nstruct lowlink {\npublic:\n    lowlink()\
    \ : lowlink(0) {\n    }\n    explicit lowlink(int n) : _n(n), g(n), ord(n, -1),\
    \ low(n), comp(n, -1), art(n, false) {\n    }\n    int add_edge(int u, int v)\
    \ {\n        assert(0 <= u && u < _n);\n        assert(0 <= v && v < _n);\n  \
    \      int e = int(edges.size());\n        edges.emplace_back(u, v);\n       \
    \ g[u].emplace_back(v, e);\n        g[v].emplace_back(u, e);\n        return e;\n\
    \    }\n    void build() {\n        int m = int(edges.size());\n        bridge.assign(m,\
    \ false);\n        std::vector<int> it(_n, 0), par_edge(_n, -1), children(_n,\
    \ 0);\n        int t = 0;\n        for (int r = 0; r < _n; r++) {\n          \
    \  if (ord[r] != -1) continue;\n            std::vector<int> st = {r};\n     \
    \       ord[r] = low[r] = t++;\n            while (!st.empty()) {\n          \
    \      int v = st.back();\n                if (it[v] < int(g[v].size())) {\n \
    \                   auto [u, e] = g[v][it[v]++];\n                    if (e ==\
    \ par_edge[v]) continue;\n                    if (ord[u] == -1) {\n          \
    \              ord[u] = low[u] = t++;\n                        par_edge[u] = e;\n\
    \                        children[v]++;\n                        st.push_back(u);\n\
    \                    } else {\n                        low[v] = std::min(low[v],\
    \ ord[u]);\n                    }\n                } else {\n                \
    \    st.pop_back();\n                    if (st.empty()) continue;\n         \
    \           int p = st.back();\n                    low[p] = std::min(low[p],\
    \ low[v]);\n                    if (low[v] > ord[p]) bridge[par_edge[v]] = true;\n\
    \                    if (low[v] >= ord[p] && p != r) art[p] = true;\n        \
    \        }\n            }\n            art[r] = children[r] >= 2;\n        }\n\
    \        _num_components = 0;\n        for (int r = 0; r < _n; r++) {\n      \
    \      if (comp[r] != -1) continue;\n            comp[r] = _num_components;\n\
    \            std::vector<int> st = {r};\n            while (!st.empty()) {\n \
    \               int v = st.back();\n                st.pop_back();\n         \
    \       for (auto [u, e] : g[v]) {\n                    if (bridge[e] || comp[u]\
    \ != -1) continue;\n                    comp[u] = _num_components;\n         \
    \           st.push_back(u);\n                }\n            }\n            _num_components++;\n\
    \        }\n    }\n    bool is_bridge(int e) const {\n        assert(0 <= e &&\
    \ e < int(edges.size()));\n        return bridge[e];\n    }\n    bool is_articulation(int\
    \ v) const {\n        assert(0 <= v && v < _n);\n        return art[v];\n    }\n\
    \    std::vector<int> bridges() const {\n        std::vector<int> res;\n     \
    \   for (int e = 0; e < int(edges.size()); e++) {\n            if (bridge[e])\
    \ res.push_back(e);\n        }\n        return res;\n    }\n    std::vector<int>\
    \ articulation_points() const {\n        std::vector<int> res;\n        for (int\
    \ v = 0; v < _n; v++) {\n            if (art[v]) res.push_back(v);\n        }\n\
    \        return res;\n    }\n    int component(int v) const {\n        assert(0\
    \ <= v && v < _n);\n        return comp[v];\n    }\n    std::vector<std::vector<int>>\
    \ two_edge_connected_components() const {\n        std::vector<std::vector<int>>\
    \ res(_num_components);\n        for (int v = 0; v < _n; v++) res[comp[v]].push_back(v);\n\
    \        return res;\n    }\n\nprivate:\n    int _n, _num_components = 0;\n  \
    \  std::vector<std::vector<std::pair<int, int>>> g;\n    std::vector<std::pair<int,\
    \ int>> edges;\n    std::vector<int> ord, low, comp;\n    std::vector<bool> art,\
    \ bridge;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\nstruct lowlink {\npublic:\n    lowlink() : lowlink(0) {\n \
    \   }\n    explicit lowlink(int n) : _n(n), g(n), ord(n, -1), low(n), comp(n,\
    \ -1), art(n, false) {\n    }\n    int add_edge(int u, int v) {\n        assert(0\
    \ <= u && u < _n);\n        assert(0 <= v && v < _n);\n        int e = int(edges.size());\n\
    \        edges.emplace_back(u, v);\n        g[u].emplace_back(v, e);\n       \
    \ g[v].emplace_back(u, e);\n        return e;\n    }\n    void build() {\n   \
    \     int m = int(edges.size());\n        bridge.assign(m, false);\n        std::vector<int>\
    \ it(_n, 0), par_edge(_n, -1), children(_n, 0);\n        int t = 0;\n        for\
    \ (int r = 0; r < _n; r++) {\n            if (ord[r] != -1) continue;\n      \
    \      std::vector<int> st = {r};\n            ord[r] = low[r] = t++;\n      \
    \      while (!st.empty()) {\n                int v = st.back();\n           \
    \     if (it[v] < int(g[v].size())) {\n                    auto [u, e] = g[v][it[v]++];\n\
    \                    if (e == par_edge[v]) continue;\n                    if (ord[u]\
    \ == -1) {\n                        ord[u] = low[u] = t++;\n                 \
    \       par_edge[u] = e;\n                        children[v]++;\n           \
    \             st.push_back(u);\n                    } else {\n               \
    \         low[v] = std::min(low[v], ord[u]);\n                    }\n        \
    \        } else {\n                    st.pop_back();\n                    if\
    \ (st.empty()) continue;\n                    int p = st.back();\n           \
    \         low[p] = std::min(low[p], low[v]);\n                    if (low[v] >\
    \ ord[p]) bridge[par_edge[v]] = true;\n                    if (low[v] >= ord[p]\
    \ && p != r) art[p] = true;\n                }\n            }\n            art[r]\
    \ = children[r] >= 2;\n        }\n        _num_components = 0;\n        for (int\
    \ r = 0; r < _n; r++) {\n            if (comp[r] != -1) continue;\n          \
    \  comp[r] = _num_components;\n            std::vector<int> st = {r};\n      \
    \      while (!st.empty()) {\n                int v = st.back();\n           \
    \     st.pop_back();\n                for (auto [u, e] : g[v]) {\n           \
    \         if (bridge[e] || comp[u] != -1) continue;\n                    comp[u]\
    \ = _num_components;\n                    st.push_back(u);\n                }\n\
    \            }\n            _num_components++;\n        }\n    }\n    bool is_bridge(int\
    \ e) const {\n        assert(0 <= e && e < int(edges.size()));\n        return\
    \ bridge[e];\n    }\n    bool is_articulation(int v) const {\n        assert(0\
    \ <= v && v < _n);\n        return art[v];\n    }\n    std::vector<int> bridges()\
    \ const {\n        std::vector<int> res;\n        for (int e = 0; e < int(edges.size());\
    \ e++) {\n            if (bridge[e]) res.push_back(e);\n        }\n        return\
    \ res;\n    }\n    std::vector<int> articulation_points() const {\n        std::vector<int>\
    \ res;\n        for (int v = 0; v < _n; v++) {\n            if (art[v]) res.push_back(v);\n\
    \        }\n        return res;\n    }\n    int component(int v) const {\n   \
    \     assert(0 <= v && v < _n);\n        return comp[v];\n    }\n    std::vector<std::vector<int>>\
    \ two_edge_connected_components() const {\n        std::vector<std::vector<int>>\
    \ res(_num_components);\n        for (int v = 0; v < _n; v++) res[comp[v]].push_back(v);\n\
    \        return res;\n    }\n\nprivate:\n    int _n, _num_components = 0;\n  \
    \  std::vector<std::vector<std::pair<int, int>>> g;\n    std::vector<std::pair<int,\
    \ int>> edges;\n    std::vector<int> ord, low, comp;\n    std::vector<bool> art,\
    \ bridge;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowlink.hpp
  requiredBy: []
  timestamp: '2026-10-25 23:38:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_3_A.test.cpp
  - test/aoj/GRL_3_B.test.cpp
  - test/unit/lowlink.test.cpp
  - test/library-checker/two_edge_connected_components.test.cpp
documentation_of: graph/lowlink.hpp
layout: document
title: Lowlink
---

### 概要
- 無向グラフの橋・関節点・二重辺連結成分を求める。

### 使い方
- `lowlink(n)`: $n$ 頂点 $0$ 辺の無向グラフを作る。
- `add_edge(u, v)`: 辺 $(u, v)$ を追加し、辺番号を返す。辺番号は追加順。
- `build()`: 構築する。
- `is_bridge(e)`: 辺 `e` が橋かを返す。
- `is_articulation(v)`: 頂点 `v` が関節点かを返す。
- `bridges()`: 橋の辺番号を昇順に返す。
- `articulation_points()`: 関節点を昇順に返す。
- `component(v)`: 頂点 `v` の属する二重辺連結成分の番号を返す。
- `two_edge_connected_components()`: 二重辺連結成分ごとの頂点のリストを返す。`component(v)` 番目のリストに `v` が入る。

### 制約
- $0 \le u, v < n$
- 多重辺・自己ループを含んでよい

### 計算量
- `build`: $\mathcal{O}(N + M)$
- `bridges`, `articulation_points`: $\mathcal{O}(N + M)$
- その他: $\mathcal{O}(1)$
