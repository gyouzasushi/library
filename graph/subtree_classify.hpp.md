---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/rooted_tree_isomorphism_classification.test.cpp
    title: test/library-checker/rooted_tree_isomorphism_classification.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/subtree_classify.test.cpp
    title: test/unit/subtree_classify.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/subtree_classify.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <map>\n#include <vector>\nstd::vector<int> subtree_classify(const\
    \ std::vector<std::vector<int>>& g, int root = 0) {\n    int n = int(g.size());\n\
    \    assert(0 <= root && root < n);\n    std::vector<int> par(n, -1), order;\n\
    \    order.reserve(n);\n    order.push_back(root);\n    par[root] = root;\n  \
    \  for (int i = 0; i < int(order.size()); i++) {\n        int u = order[i];\n\
    \        for (int v : g[u]) {\n            if (v == par[u]) continue;\n      \
    \      assert(par[v] == -1);\n            par[v] = u;\n            order.push_back(v);\n\
    \        }\n    }\n    assert(int(order.size()) == n);\n    std::vector<int> ret(n);\n\
    \    std::map<std::vector<int>, int> id;\n    std::vector<int> key;\n    for (int\
    \ i = n - 1; i >= 0; i--) {\n        int u = order[i];\n        key.clear();\n\
    \        for (int v : g[u]) {\n            if (v != par[u]) key.push_back(ret[v]);\n\
    \        }\n        std::ranges::sort(key);\n        ret[u] = id.try_emplace(key,\
    \ int(id.size())).first->second;\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <map>\n\
    #include <vector>\nstd::vector<int> subtree_classify(const std::vector<std::vector<int>>&\
    \ g, int root = 0) {\n    int n = int(g.size());\n    assert(0 <= root && root\
    \ < n);\n    std::vector<int> par(n, -1), order;\n    order.reserve(n);\n    order.push_back(root);\n\
    \    par[root] = root;\n    for (int i = 0; i < int(order.size()); i++) {\n  \
    \      int u = order[i];\n        for (int v : g[u]) {\n            if (v == par[u])\
    \ continue;\n            assert(par[v] == -1);\n            par[v] = u;\n    \
    \        order.push_back(v);\n        }\n    }\n    assert(int(order.size()) ==\
    \ n);\n    std::vector<int> ret(n);\n    std::map<std::vector<int>, int> id;\n\
    \    std::vector<int> key;\n    for (int i = n - 1; i >= 0; i--) {\n        int\
    \ u = order[i];\n        key.clear();\n        for (int v : g[u]) {\n        \
    \    if (v != par[u]) key.push_back(ret[v]);\n        }\n        std::ranges::sort(key);\n\
    \        ret[u] = id.try_emplace(key, int(id.size())).first->second;\n    }\n\
    \    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/subtree_classify.hpp
  requiredBy: []
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/subtree_classify.test.cpp
  - test/library-checker/rooted_tree_isomorphism_classification.test.cpp
documentation_of: graph/subtree_classify.hpp
layout: document
title: "\u6839\u4ED8\u304D\u6728\u306E\u540C\u578B\u6027\u306B\u3088\u308B\u90E8\u5206\
  \u6728\u306E\u5206\u985E"
---

### 概要
- 根付き木の各頂点を根とする部分木を、根付き木としての同型性で分類する。

### 使い方
- `subtree_classify(g, root = 0)`: 木の隣接リスト `g` について、頂点 `i` を根とする部分木の種類番号 `a[i]` を返す。頂点 `i`, `j` を根とする部分木が同型であることと `a[i] = a[j]` は同値で、番号は $0$ から種類数 $- 1$ まで詰めて振る。`g` は親から子への辺だけでもよい。

### 制約
- `g` は木
- $0 \le \mathrm{root} < n$

### 計算量
- $\mathcal{O}(N \log N)$
