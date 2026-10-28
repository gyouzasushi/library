---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/tree_diameter.test.cpp
    title: test/unit/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree_diameter.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\ntemplate <class T>\nstruct\
    \ tree_diameter {\npublic:\n    tree_diameter() : tree_diameter(0) {\n    }\n\
    \    explicit tree_diameter(int n) : _n(n), g(n) {\n    }\n    void add_edge(int\
    \ u, int v, T w = 1) {\n        assert(0 <= u && u < _n);\n        assert(0 <=\
    \ v && v < _n);\n        g[u].emplace_back(v, w);\n        g[v].emplace_back(u,\
    \ w);\n    }\n    void build() {\n        assert(_n >= 1);\n        std::vector<int>\
    \ par;\n        std::vector<T> d;\n        search(0, d, par);\n        _u = int(std::max_element(d.begin(),\
    \ d.end()) - d.begin());\n        search(_u, d, par);\n        _v = int(std::max_element(d.begin(),\
    \ d.end()) - d.begin());\n        _length = d[_v];\n        _path.clear();\n \
    \       for (int x = _v; x != -1; x = par[x]) _path.push_back(x);\n        std::reverse(_path.begin(),\
    \ _path.end());\n    }\n    T length() const {\n        return _length;\n    }\n\
    \    std::pair<int, int> ends() const {\n        return {_u, _v};\n    }\n   \
    \ const std::vector<int>& path() const {\n        return _path;\n    }\n\nprivate:\n\
    \    int _n, _u = -1, _v = -1;\n    T _length = T(0);\n    std::vector<std::vector<std::pair<int,\
    \ T>>> g;\n    std::vector<int> _path;\n    void search(int s, std::vector<T>&\
    \ d, std::vector<int>& par) const {\n        d.assign(_n, T(0));\n        par.assign(_n,\
    \ -1);\n        std::vector<int> st = {s};\n        par[s] = s;\n        while\
    \ (!st.empty()) {\n            int x = st.back();\n            st.pop_back();\n\
    \            for (auto [y, w] : g[x]) {\n                if (par[y] != -1) continue;\n\
    \                par[y] = x;\n                d[y] = d[x] + w;\n             \
    \   st.push_back(y);\n            }\n        }\n        par[s] = -1;\n    }\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\ntemplate <class T>\nstruct tree_diameter {\npublic:\n    tree_diameter()\
    \ : tree_diameter(0) {\n    }\n    explicit tree_diameter(int n) : _n(n), g(n)\
    \ {\n    }\n    void add_edge(int u, int v, T w = 1) {\n        assert(0 <= u\
    \ && u < _n);\n        assert(0 <= v && v < _n);\n        g[u].emplace_back(v,\
    \ w);\n        g[v].emplace_back(u, w);\n    }\n    void build() {\n        assert(_n\
    \ >= 1);\n        std::vector<int> par;\n        std::vector<T> d;\n        search(0,\
    \ d, par);\n        _u = int(std::max_element(d.begin(), d.end()) - d.begin());\n\
    \        search(_u, d, par);\n        _v = int(std::max_element(d.begin(), d.end())\
    \ - d.begin());\n        _length = d[_v];\n        _path.clear();\n        for\
    \ (int x = _v; x != -1; x = par[x]) _path.push_back(x);\n        std::reverse(_path.begin(),\
    \ _path.end());\n    }\n    T length() const {\n        return _length;\n    }\n\
    \    std::pair<int, int> ends() const {\n        return {_u, _v};\n    }\n   \
    \ const std::vector<int>& path() const {\n        return _path;\n    }\n\nprivate:\n\
    \    int _n, _u = -1, _v = -1;\n    T _length = T(0);\n    std::vector<std::vector<std::pair<int,\
    \ T>>> g;\n    std::vector<int> _path;\n    void search(int s, std::vector<T>&\
    \ d, std::vector<int>& par) const {\n        d.assign(_n, T(0));\n        par.assign(_n,\
    \ -1);\n        std::vector<int> st = {s};\n        par[s] = s;\n        while\
    \ (!st.empty()) {\n            int x = st.back();\n            st.pop_back();\n\
    \            for (auto [y, w] : g[x]) {\n                if (par[y] != -1) continue;\n\
    \                par[y] = x;\n                d[y] = d[x] + w;\n             \
    \   st.push_back(y);\n            }\n        }\n        par[s] = -1;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2026-10-28 19:58:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/tree_diameter.test.cpp
  - test/aoj/GRL_5_A.test.cpp
documentation_of: graph/tree_diameter.hpp
layout: document
title: Tree Diameter
---

### 概要
- 木の直径を求める。

### 使い方
- `tree_diameter<T> d(n)`: 頂点数 `n`、辺の重みの型 `T`。
- `add_edge(u, v, w = 1)`: 重み `w` の辺 $(u, v)$ を追加する。
- `build()`: 構築する。
- `length()`: 直径の長さを返す。
- `ends()`: 直径の両端 `(u, v)` を返す。
- `path()`: `u` から `v` への直径の頂点列を返す。

### 制約
- $1 \le n$
- $0 \le w$
- 辺は $n - 1$ 本で全体が木

### 計算量
- `build`: $\mathcal{O}(N)$
- その他: $\mathcal{O}(1)$
