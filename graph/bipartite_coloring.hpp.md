---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/bipartite_coloring.test.cpp
    title: test/unit/bipartite_coloring.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/bipartite_coloring.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\nstruct bipartite_coloring\
    \ {\npublic:\n    bipartite_coloring() : bipartite_coloring(0) {\n    }\n    explicit\
    \ bipartite_coloring(int n) : _n(n), g(n), _color(n, -1) {\n    }\n    void add_edge(int\
    \ u, int v) {\n        assert(0 <= u && u < _n);\n        assert(0 <= v && v <\
    \ _n);\n        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n    void\
    \ build() {\n        _color.assign(_n, -1);\n        _cycle.clear();\n       \
    \ std::vector<int> par(_n, -1), it(_n, 0), st;\n        for (int s = 0; s < _n;\
    \ s++) {\n            if (_color[s] != -1) continue;\n            _color[s] =\
    \ 0;\n            st.assign(1, s);\n            while (!st.empty()) {\n      \
    \          int u = st.back();\n                if (it[u] == int(g[u].size()))\
    \ {\n                    st.pop_back();\n                    continue;\n     \
    \           }\n                int v = g[u][it[u]++];\n                if (_color[v]\
    \ == -1) {\n                    _color[v] = _color[u] ^ 1;\n                 \
    \   par[v] = u;\n                    st.push_back(v);\n                } else\
    \ if (_color[v] == _color[u] && _cycle.empty()) {\n                    for (int\
    \ x = u; x != v; x = par[x]) _cycle.push_back(x);\n                    _cycle.push_back(v);\n\
    \                    std::ranges::reverse(_cycle);\n                }\n      \
    \      }\n        }\n    }\n    bool is_bipartite() const {\n        return _cycle.empty();\n\
    \    }\n    int color(int v) const {\n        assert(0 <= v && v < _n);\n    \
    \    return _color[v];\n    }\n    const std::vector<int>& odd_cycle() const {\n\
    \        return _cycle;\n    }\n\nprivate:\n    int _n;\n    std::vector<std::vector<int>>\
    \ g;\n    std::vector<int> _color, _cycle;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\nstruct bipartite_coloring {\npublic:\n    bipartite_coloring()\
    \ : bipartite_coloring(0) {\n    }\n    explicit bipartite_coloring(int n) : _n(n),\
    \ g(n), _color(n, -1) {\n    }\n    void add_edge(int u, int v) {\n        assert(0\
    \ <= u && u < _n);\n        assert(0 <= v && v < _n);\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n    void build() {\n        _color.assign(_n,\
    \ -1);\n        _cycle.clear();\n        std::vector<int> par(_n, -1), it(_n,\
    \ 0), st;\n        for (int s = 0; s < _n; s++) {\n            if (_color[s] !=\
    \ -1) continue;\n            _color[s] = 0;\n            st.assign(1, s);\n  \
    \          while (!st.empty()) {\n                int u = st.back();\n       \
    \         if (it[u] == int(g[u].size())) {\n                    st.pop_back();\n\
    \                    continue;\n                }\n                int v = g[u][it[u]++];\n\
    \                if (_color[v] == -1) {\n                    _color[v] = _color[u]\
    \ ^ 1;\n                    par[v] = u;\n                    st.push_back(v);\n\
    \                } else if (_color[v] == _color[u] && _cycle.empty()) {\n    \
    \                for (int x = u; x != v; x = par[x]) _cycle.push_back(x);\n  \
    \                  _cycle.push_back(v);\n                    std::ranges::reverse(_cycle);\n\
    \                }\n            }\n        }\n    }\n    bool is_bipartite() const\
    \ {\n        return _cycle.empty();\n    }\n    int color(int v) const {\n   \
    \     assert(0 <= v && v < _n);\n        return _color[v];\n    }\n    const std::vector<int>&\
    \ odd_cycle() const {\n        return _cycle;\n    }\n\nprivate:\n    int _n;\n\
    \    std::vector<std::vector<int>> g;\n    std::vector<int> _color, _cycle;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/bipartite_coloring.hpp
  requiredBy: []
  timestamp: '2026-10-29 13:31:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/bipartite_coloring.test.cpp
documentation_of: graph/bipartite_coloring.hpp
layout: document
title: Bipartite Coloring
---

### 概要
- 無向グラフの 2 彩色と、二部グラフでないときの奇閉路を求める。

### 使い方
- `bipartite_coloring g(n)`: 頂点数 `n`。
- `add_edge(u, v)`: 辺 $(u, v)$ を追加する。
- `build()`: 構築する。
- `is_bipartite()`: 二部グラフかを返す。
- `color(v)`: 頂点 `v` の色 (0 / 1) を返す。二部グラフなら隣接する頂点は色が異なる。
- `odd_cycle()`: 奇閉路の頂点列を閉路順に返す。二部グラフなら空。

### 計算量
- `build`: $\mathcal{O}(N + M)$
- その他: $\mathcal{O}(1)$
