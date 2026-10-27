---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/persistent_unionfind.test.cpp
    title: test/library-checker/persistent_unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/persistent_array.test.cpp
    title: test/unit/persistent_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/persistent_array.hpp\"\n#include <cassert>\n\
    #include <vector>\ntemplate <class T> struct persistent_array {\npublic:\n   \
    \ explicit persistent_array(int n) : persistent_array(std::vector<T>(n)) {\n \
    \   }\n    explicit persistent_array(const std::vector<T>& v) : _n(int(v.size()))\
    \ {\n        nodes.reserve(2 * _n);\n        if (_n > 0) build(v, 0, _n);\n  \
    \  }\n    int size() const {\n        return _n;\n    }\n    T get(int root, int\
    \ p) const {\n        assert(0 <= p && p < _n);\n        int cur = root, l = 0,\
    \ r = _n;\n        while (r - l > 1) {\n            int mid = (l + r) / 2;\n \
    \           if (p < mid) {\n                cur = nodes[cur].l, r = mid;\n   \
    \         } else {\n                cur = nodes[cur].r, l = mid;\n           \
    \ }\n        }\n        return nodes[cur].val;\n    }\n    int set(int root, int\
    \ p, const T& x) {\n        assert(0 <= p && p < _n);\n        int res = copy(root);\n\
    \        int cur = res, l = 0, r = _n;\n        while (r - l > 1) {\n        \
    \    int mid = (l + r) / 2;\n            if (p < mid) {\n                int nxt\
    \ = copy(nodes[cur].l);\n                nodes[cur].l = nxt;\n               \
    \ cur = nxt, r = mid;\n            } else {\n                int nxt = copy(nodes[cur].r);\n\
    \                nodes[cur].r = nxt;\n                cur = nxt, l = mid;\n  \
    \          }\n        }\n        nodes[cur].val = x;\n        return res;\n  \
    \  }\n\nprivate:\n    struct node {\n        int l, r;\n        T val;\n    };\n\
    \    int _n;\n    std::vector<node> nodes;\n    int copy(int v) {\n        nodes.push_back(nodes[v]);\n\
    \        return int(nodes.size()) - 1;\n    }\n    int build(const std::vector<T>&\
    \ v, int l, int r) {\n        if (r - l == 1) {\n            nodes.push_back({-1,\
    \ -1, v[l]});\n            return int(nodes.size()) - 1;\n        }\n        int\
    \ mid = (l + r) / 2;\n        int res = int(nodes.size());\n        nodes.push_back({-1,\
    \ -1, T()});\n        int lc = build(v, l, mid);\n        int rc = build(v, mid,\
    \ r);\n        nodes[res].l = lc, nodes[res].r = rc;\n        return res;\n  \
    \  }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\ntemplate <class T> struct\
    \ persistent_array {\npublic:\n    explicit persistent_array(int n) : persistent_array(std::vector<T>(n))\
    \ {\n    }\n    explicit persistent_array(const std::vector<T>& v) : _n(int(v.size()))\
    \ {\n        nodes.reserve(2 * _n);\n        if (_n > 0) build(v, 0, _n);\n  \
    \  }\n    int size() const {\n        return _n;\n    }\n    T get(int root, int\
    \ p) const {\n        assert(0 <= p && p < _n);\n        int cur = root, l = 0,\
    \ r = _n;\n        while (r - l > 1) {\n            int mid = (l + r) / 2;\n \
    \           if (p < mid) {\n                cur = nodes[cur].l, r = mid;\n   \
    \         } else {\n                cur = nodes[cur].r, l = mid;\n           \
    \ }\n        }\n        return nodes[cur].val;\n    }\n    int set(int root, int\
    \ p, const T& x) {\n        assert(0 <= p && p < _n);\n        int res = copy(root);\n\
    \        int cur = res, l = 0, r = _n;\n        while (r - l > 1) {\n        \
    \    int mid = (l + r) / 2;\n            if (p < mid) {\n                int nxt\
    \ = copy(nodes[cur].l);\n                nodes[cur].l = nxt;\n               \
    \ cur = nxt, r = mid;\n            } else {\n                int nxt = copy(nodes[cur].r);\n\
    \                nodes[cur].r = nxt;\n                cur = nxt, l = mid;\n  \
    \          }\n        }\n        nodes[cur].val = x;\n        return res;\n  \
    \  }\n\nprivate:\n    struct node {\n        int l, r;\n        T val;\n    };\n\
    \    int _n;\n    std::vector<node> nodes;\n    int copy(int v) {\n        nodes.push_back(nodes[v]);\n\
    \        return int(nodes.size()) - 1;\n    }\n    int build(const std::vector<T>&\
    \ v, int l, int r) {\n        if (r - l == 1) {\n            nodes.push_back({-1,\
    \ -1, v[l]});\n            return int(nodes.size()) - 1;\n        }\n        int\
    \ mid = (l + r) / 2;\n        int res = int(nodes.size());\n        nodes.push_back({-1,\
    \ -1, T()});\n        int lc = build(v, l, mid);\n        int rc = build(v, mid,\
    \ r);\n        nodes[res].l = lc, nodes[res].r = rc;\n        return res;\n  \
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/persistent_array.hpp
  requiredBy: []
  timestamp: '2026-10-27 20:36:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/persistent_array.test.cpp
  - test/library-checker/persistent_unionfind.test.cpp
documentation_of: datastructure/persistent_array.hpp
layout: document
title: Persistent Array
---

### 概要
- 1 点更新のたびに新しい版を作り、過去の版も参照できる配列。版は `int` の番号で扱う。

### 使い方
- `persistent_array<T>(n)`: 全要素 `T()` の長さ $n$ の配列を版 $0$ として作る。
- `persistent_array<T>(v)`: 配列 `v` を版 $0$ として作る。
- `size()`: 配列の長さを返す。
- `get(root, p)`: 版 `root` の `a[p]` を返す。
- `set(root, p, x)`: 版 `root` の `a[p]` を `x` に変えた新しい版を作り、その番号を返す。版 `root` は変わらない。

### 制約
- $0 \le p < n$

### 計算量
- 構築: $\mathcal{O}(n)$
- `get`, `set`: $\mathcal{O}(\log n)$。`set` 1 回でメモリが $\mathcal{O}(\log n)$ 増える。
