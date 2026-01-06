---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/rooted_tree_isomorphism_classification.test.cpp
    title: test/library-checker/rooted_tree_isomorphism_classification.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/subtree_classify.hpp\"\n\n#include <algorithm>\n#include\
    \ <map>\n#include <vector>\nstd::vector<int> subtree_classify(std::vector<std::vector<int>>\
    \ g,\n                                  int root = 0) {\n    std::vector<int>\
    \ ret(g.size());\n    std::map<std::vector<int>, int> cache;\n    auto dfs = [&](auto\
    \ dfs, int u) -> int {\n        std::vector<int> hash;\n        hash.push_back(-1);\n\
    \        for (int v : g[u]) hash.push_back(dfs(dfs, v));\n        std::sort(hash.begin(),\
    \ hash.end());\n        hash.push_back(-1);\n        if (!cache.count(hash)) cache[hash]\
    \ = int(cache.size());\n        return ret[u] = cache[hash];\n    };\n    dfs(dfs,\
    \ root);\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <map>\n#include <vector>\n\
    std::vector<int> subtree_classify(std::vector<std::vector<int>> g,\n         \
    \                         int root = 0) {\n    std::vector<int> ret(g.size());\n\
    \    std::map<std::vector<int>, int> cache;\n    auto dfs = [&](auto dfs, int\
    \ u) -> int {\n        std::vector<int> hash;\n        hash.push_back(-1);\n \
    \       for (int v : g[u]) hash.push_back(dfs(dfs, v));\n        std::sort(hash.begin(),\
    \ hash.end());\n        hash.push_back(-1);\n        if (!cache.count(hash)) cache[hash]\
    \ = int(cache.size());\n        return ret[u] = cache[hash];\n    };\n    dfs(dfs,\
    \ root);\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/subtree_classify.hpp
  requiredBy: []
  timestamp: '2023-01-11 14:05:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/rooted_tree_isomorphism_classification.test.cpp
documentation_of: graph/subtree_classify.hpp
layout: document
title: "\u6839\u4ED8\u304D\u6728\u306E\u540C\u578B\u6027\u306B\u3088\u308B\u90E8\u5206\
  \u6728\u306E\u5206\u985E"
---

### 概要
- $N$ 頂点の根付き木について、ある頂点を根とする（全部で $N$ 個の）部分木を、根付き木の同型性で分類する。
  
### 使い方
- `subtree_classify(g, root = 0)`: 次の条件を満たす整数列 `a` を求める。
  - 部分木の種類数を $K$ としたとき、$0\leq a_i \lt K$
  - 頂点 `i`、 頂点 `j` を根とする部分木が同型 $\iff$ $a_i = a_j$

### 計算量
- $\mathcal{O}(N \log N)$