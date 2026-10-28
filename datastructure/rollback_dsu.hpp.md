---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/unit/rollback_dsu.test.cpp
    title: test/unit/rollback_dsu.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/rollback_dsu.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\nstruct rollback_dsu\
    \ {\npublic:\n    rollback_dsu() : rollback_dsu(0) {\n    }\n    explicit rollback_dsu(int\
    \ n) : _n(n), parent_or_size(n, -1) {\n    }\n    int merge(int a, int b) {\n\
    \        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n      \
    \  int x = leader(a), y = leader(b);\n        if (x == y) {\n            history.emplace_back(-1,\
    \ -1);\n            return x;\n        }\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ std::swap(x, y);\n        history.emplace_back(y, parent_or_size[y]);\n    \
    \    parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y] = x;\n\
    \        return x;\n    }\n    void undo() {\n        assert(!history.empty());\n\
    \        auto [y, s] = history.back();\n        history.pop_back();\n        if\
    \ (y == -1) return;\n        parent_or_size[parent_or_size[y]] -= s;\n       \
    \ parent_or_size[y] = s;\n    }\n    int time() const {\n        return int(history.size());\n\
    \    }\n    void rollback(int t) {\n        assert(0 <= t && t <= time());\n \
    \       while (time() > t) undo();\n    }\n    bool same(int a, int b) const {\n\
    \        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n      \
    \  return leader(a) == leader(b);\n    }\n    int leader(int a) const {\n    \
    \    assert(0 <= a && a < _n);\n        while (parent_or_size[a] >= 0) a = parent_or_size[a];\n\
    \        return a;\n    }\n    int size(int a) const {\n        assert(0 <= a\
    \ && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n    std::vector<std::vector<int>>\
    \ groups() const {\n        std::vector<int> leader_buf(_n), group_size(_n);\n\
    \        for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n\
    \            group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) result[i].reserve(group_size[i]);\n\
    \        for (int i = 0; i < _n; i++) result[leader_buf[i]].push_back(i);\n  \
    \      result.erase(std::ranges::remove_if(result, [](const std::vector<int>&\
    \ v) { return v.empty(); }).begin(),\n                     result.end());\n  \
    \      return result;\n    }\n\nprivate:\n    int _n;\n    std::vector<int> parent_or_size;\n\
    \    std::vector<std::pair<int, int>> history;  // (attached leader, its old parent_or_size)\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\nstruct rollback_dsu {\npublic:\n    rollback_dsu() : rollback_dsu(0)\
    \ {\n    }\n    explicit rollback_dsu(int n) : _n(n), parent_or_size(n, -1) {\n\
    \    }\n    int merge(int a, int b) {\n        assert(0 <= a && a < _n);\n   \
    \     assert(0 <= b && b < _n);\n        int x = leader(a), y = leader(b);\n \
    \       if (x == y) {\n            history.emplace_back(-1, -1);\n           \
    \ return x;\n        }\n        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x,\
    \ y);\n        history.emplace_back(y, parent_or_size[y]);\n        parent_or_size[x]\
    \ += parent_or_size[y];\n        parent_or_size[y] = x;\n        return x;\n \
    \   }\n    void undo() {\n        assert(!history.empty());\n        auto [y,\
    \ s] = history.back();\n        history.pop_back();\n        if (y == -1) return;\n\
    \        parent_or_size[parent_or_size[y]] -= s;\n        parent_or_size[y] =\
    \ s;\n    }\n    int time() const {\n        return int(history.size());\n   \
    \ }\n    void rollback(int t) {\n        assert(0 <= t && t <= time());\n    \
    \    while (time() > t) undo();\n    }\n    bool same(int a, int b) const {\n\
    \        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n      \
    \  return leader(a) == leader(b);\n    }\n    int leader(int a) const {\n    \
    \    assert(0 <= a && a < _n);\n        while (parent_or_size[a] >= 0) a = parent_or_size[a];\n\
    \        return a;\n    }\n    int size(int a) const {\n        assert(0 <= a\
    \ && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n    std::vector<std::vector<int>>\
    \ groups() const {\n        std::vector<int> leader_buf(_n), group_size(_n);\n\
    \        for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n\
    \            group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) result[i].reserve(group_size[i]);\n\
    \        for (int i = 0; i < _n; i++) result[leader_buf[i]].push_back(i);\n  \
    \      result.erase(std::ranges::remove_if(result, [](const std::vector<int>&\
    \ v) { return v.empty(); }).begin(),\n                     result.end());\n  \
    \      return result;\n    }\n\nprivate:\n    int _n;\n    std::vector<int> parent_or_size;\n\
    \    std::vector<std::pair<int, int>> history;  // (attached leader, its old parent_or_size)\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/rollback_dsu.hpp
  requiredBy: []
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unit/rollback_dsu.test.cpp
documentation_of: datastructure/rollback_dsu.hpp
layout: document
title: Rollback DSU
---

### 概要
- 結合を取り消せる Union-Find。

### 使い方
- `rollback_dsu(n)`: $n$ 頂点 $0$ 辺の無向グラフを作る。
- `merge(a, b)`: 辺 $(a, b)$ を追加し、代表元を返す。
- `undo()`: 直前の `merge` を取り消す。
- `time()`: これまでの `merge` の回数から `undo` で取り消した分を引いた数を返す。
- `rollback(t)`: `time()` が `t` になるまで `undo` する。
- `same(a, b)`: 頂点 `a`, `b` が連結かを返す。
- `leader(a)`: 頂点 `a` の属する連結成分の代表元を返す。
- `size(a)`: 頂点 `a` の属する連結成分のサイズを返す。
- `groups()`: 連結成分ごとの頂点のリストを返す。

### 制約
- $0 \le a, b < n$
- `undo`: $1 \le$ `time()`
- `rollback`: $0 \le t \le$ `time()`

### 計算量
- `merge`, `same`, `leader`, `size`: $\mathcal{O}(\log n)$
- `undo`: $\mathcal{O}(1)$
- `rollback(t)`: $\mathcal{O}(\text{time}() - t)$
- `groups`: $\mathcal{O}(n \log n)$
