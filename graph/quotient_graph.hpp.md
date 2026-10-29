---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/quotient_graph.test.cpp
    title: test/unit/quotient_graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/quotient_graph.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\ninline std::vector<int> component_id(int n, const std::vector<std::vector<int>>&\
    \ groups) {\n    std::vector<int> id(n);\n    for (int i = 0; i < int(groups.size());\
    \ i++) {\n        for (int v : groups[i]) id[v] = i;\n    }\n    return id;\n\
    }\ninline std::vector<std::vector<int>> quotient_graph(const std::vector<std::vector<int>>&\
    \ g, const std::vector<std::vector<int>>& groups) {\n    std::vector<int> id =\
    \ component_id(int(g.size()), groups);\n    std::vector<std::vector<int>> q(groups.size());\n\
    \    for (int u = 0; u < int(g.size()); u++) {\n        for (int v : g[u]) {\n\
    \            if (id[u] != id[v]) q[id[u]].push_back(id[v]);\n        }\n    }\n\
    \    for (auto& es : q) {\n        std::ranges::sort(es);\n        es.erase(std::ranges::unique(es).begin(),\
    \ es.end());\n    }\n    return q;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\ninline std::vector<int>\
    \ component_id(int n, const std::vector<std::vector<int>>& groups) {\n    std::vector<int>\
    \ id(n);\n    for (int i = 0; i < int(groups.size()); i++) {\n        for (int\
    \ v : groups[i]) id[v] = i;\n    }\n    return id;\n}\ninline std::vector<std::vector<int>>\
    \ quotient_graph(const std::vector<std::vector<int>>& g, const std::vector<std::vector<int>>&\
    \ groups) {\n    std::vector<int> id = component_id(int(g.size()), groups);\n\
    \    std::vector<std::vector<int>> q(groups.size());\n    for (int u = 0; u <\
    \ int(g.size()); u++) {\n        for (int v : g[u]) {\n            if (id[u] !=\
    \ id[v]) q[id[u]].push_back(id[v]);\n        }\n    }\n    for (auto& es : q)\
    \ {\n        std::ranges::sort(es);\n        es.erase(std::ranges::unique(es).begin(),\
    \ es.end());\n    }\n    return q;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/quotient_graph.hpp
  requiredBy: []
  timestamp: '2026-10-29 21:49:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/quotient_graph.test.cpp
documentation_of: graph/quotient_graph.hpp
layout: document
title: Quotient Graph
---

### 概要
- 頂点の分割から、頂点の成分番号と成分を縮約したグラフを作る。

### 使い方
- `component_id(n, groups)`: 頂点 `v` の成分番号を `id[v]` とする長さ `n` の列を返す。`groups` が `atcoder::scc_graph::scc()` の結果なら辺 $(u, v)$ について `id[u] <= id[v]`。
- `quotient_graph(g, groups)`: 隣接リスト `g` の辺を成分間に写したグラフの隣接リストを返す。`q[i]` は成分 `i` から出る辺の先の成分番号で、重複がなく昇順。

### 制約
- `groups` は $0, \ldots, n - 1$ の分割。`atcoder::scc_graph::scc()`、`lowlink::two_edge_connected_components()`、`atcoder::dsu::groups()` の結果はこれを満たす。

### 計算量
- `component_id`: $\mathcal{O}(N)$
- `quotient_graph`: $\mathcal{O}(N + M \log M)$
