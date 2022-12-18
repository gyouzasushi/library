---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/line_add_get_min.test.cpp
    title: test/library-checker/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/segment_add_get_min.test.cpp
    title: test/library-checker/segment_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/dynamic_li_chao_tree.hpp\"\n#include <algorithm>\n\
    #include <limits>\nstruct DynamicLiChaoTree {\npublic:\n    DynamicLiChaoTree(long\
    \ long min_index = -1'000'000'000,\n                      long long max_index\
    \ = 1'000'000'000)\n        : min_index(min_index), max_index(max_index + 1),\
    \ root(nullptr) {\n    }\n    void add_line(long long a, long long b) {\n    \
    \    Line line = Line{a, b};\n        add_line(root, min_index, max_index, line);\n\
    \    }\n    void add_segment(long long a, long long b, long long l_lim,\n    \
    \                 long long r_lim) {\n        Line line = Line{a, b};\n      \
    \  add_segment(root, l_lim, r_lim, min_index, max_index, line);\n    }\n    long\
    \ long get(long long x) {\n        node* t = root;\n        long long l = min_index,\
    \ r = max_index;\n        long long ret = std::numeric_limits<long long>::max();\n\
    \        while (r - l > 0 && t != nullptr) {\n            long long m = (l + r)\
    \ >> 1;\n            ret = std::min(ret, t->line.f(x));\n            if (x < m)\
    \ {\n                r = m;\n                t = t->left;\n            } else\
    \ {\n                l = m;\n                t = t->right;\n            }\n  \
    \      }\n        return ret;\n    }\n\nprivate:\n    struct Line {\n        long\
    \ long slope, intercept;\n        Line() : slope(0), intercept(std::numeric_limits<long\
    \ long>::max()) {\n        }\n        Line(long long a, long long b) : slope(a),\
    \ intercept(b) {\n        }\n        long long f(long long x) {\n            return\
    \ slope * x + intercept;\n        }\n    };\n    struct node {\n        Line line;\n\
    \        node *left, *right;\n        node(Line line) : line(line), left(nullptr),\
    \ right(nullptr) {\n        }\n    };\n    const long long min_index, max_index;\n\
    \    node* root;\n    node* add_line(node*& t, long long l, long long r, Line\
    \ line) const {\n        if (l == r) return nullptr;\n        if (!t) {\n    \
    \        t = new node(line);\n            return t;\n        }\n        long long\
    \ m = (l + r) >> 1;\n        bool check_l = (line.f(l) <= t->line.f(l));\n   \
    \     bool check_m = (line.f(m) <= t->line.f(m));\n        bool check_r = (line.f(r)\
    \ <= t->line.f(r));\n        if (check_l && check_r) {\n            t->line =\
    \ line;\n            return t;\n        }\n        if (!check_l && !check_r) {\n\
    \            return t;\n        }\n        if (check_m) {\n            std::swap(t->line,\
    \ line);\n        }\n        if (check_l != check_m) {\n            t->left =\
    \ add_line(t->left, l, m, line);\n        } else {\n            t->right = add_line(t->right,\
    \ m + 1, r, line);\n        }\n        return t;\n    }\n    node* add_segment(node*&\
    \ t, long long l_lim, long long r_lim, long long l,\n                      long\
    \ long r, Line line) {\n        if (r <= l_lim || r_lim <= l) return t;\n    \
    \    if (l_lim <= l && r <= r_lim) return add_line(t, l, r, line);\n        if\
    \ (t == nullptr) t = new node(Line());\n        long long m = (l + r) >> 1;\n\
    \        t->left = add_segment(t->left, l_lim, r_lim, l, m, line);\n        t->right\
    \ = add_segment(t->right, l_lim, r_lim, m, r, line);\n        return t;\n    }\n\
    };\n"
  code: "#include <algorithm>\n#include <limits>\nstruct DynamicLiChaoTree {\npublic:\n\
    \    DynamicLiChaoTree(long long min_index = -1'000'000'000,\n               \
    \       long long max_index = 1'000'000'000)\n        : min_index(min_index),\
    \ max_index(max_index + 1), root(nullptr) {\n    }\n    void add_line(long long\
    \ a, long long b) {\n        Line line = Line{a, b};\n        add_line(root, min_index,\
    \ max_index, line);\n    }\n    void add_segment(long long a, long long b, long\
    \ long l_lim,\n                     long long r_lim) {\n        Line line = Line{a,\
    \ b};\n        add_segment(root, l_lim, r_lim, min_index, max_index, line);\n\
    \    }\n    long long get(long long x) {\n        node* t = root;\n        long\
    \ long l = min_index, r = max_index;\n        long long ret = std::numeric_limits<long\
    \ long>::max();\n        while (r - l > 0 && t != nullptr) {\n            long\
    \ long m = (l + r) >> 1;\n            ret = std::min(ret, t->line.f(x));\n   \
    \         if (x < m) {\n                r = m;\n                t = t->left;\n\
    \            } else {\n                l = m;\n                t = t->right;\n\
    \            }\n        }\n        return ret;\n    }\n\nprivate:\n    struct\
    \ Line {\n        long long slope, intercept;\n        Line() : slope(0), intercept(std::numeric_limits<long\
    \ long>::max()) {\n        }\n        Line(long long a, long long b) : slope(a),\
    \ intercept(b) {\n        }\n        long long f(long long x) {\n            return\
    \ slope * x + intercept;\n        }\n    };\n    struct node {\n        Line line;\n\
    \        node *left, *right;\n        node(Line line) : line(line), left(nullptr),\
    \ right(nullptr) {\n        }\n    };\n    const long long min_index, max_index;\n\
    \    node* root;\n    node* add_line(node*& t, long long l, long long r, Line\
    \ line) const {\n        if (l == r) return nullptr;\n        if (!t) {\n    \
    \        t = new node(line);\n            return t;\n        }\n        long long\
    \ m = (l + r) >> 1;\n        bool check_l = (line.f(l) <= t->line.f(l));\n   \
    \     bool check_m = (line.f(m) <= t->line.f(m));\n        bool check_r = (line.f(r)\
    \ <= t->line.f(r));\n        if (check_l && check_r) {\n            t->line =\
    \ line;\n            return t;\n        }\n        if (!check_l && !check_r) {\n\
    \            return t;\n        }\n        if (check_m) {\n            std::swap(t->line,\
    \ line);\n        }\n        if (check_l != check_m) {\n            t->left =\
    \ add_line(t->left, l, m, line);\n        } else {\n            t->right = add_line(t->right,\
    \ m + 1, r, line);\n        }\n        return t;\n    }\n    node* add_segment(node*&\
    \ t, long long l_lim, long long r_lim, long long l,\n                      long\
    \ long r, Line line) {\n        if (r <= l_lim || r_lim <= l) return t;\n    \
    \    if (l_lim <= l && r <= r_lim) return add_line(t, l, r, line);\n        if\
    \ (t == nullptr) t = new node(Line());\n        long long m = (l + r) >> 1;\n\
    \        t->left = add_segment(t->left, l_lim, r_lim, l, m, line);\n        t->right\
    \ = add_segment(t->right, l_lim, r_lim, m, r, line);\n        return t;\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/dynamic_li_chao_tree.hpp
  requiredBy: []
  timestamp: '2022-09-13 19:30:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/line_add_get_min.test.cpp
  - test/library-checker/segment_add_get_min.test.cpp
documentation_of: datastructure/dynamic_li_chao_tree.hpp
layout: document
title: Dynamic Li Chao Tree
---

### 概要
- 直線・線分の追加と最小値取得ができるデータ構造。

### 使い方
- `DynamicLiChaoTree(min_index = -1e9, max_index = 1e9)`: `min-index`$\le x \le$ `max_index` として初期化する。
- `add_line(a, b)`: 直線 `a`$x+$`b` を追加する。
- `add_segment(a, b, l, r)`: 線分 `a`$x+$`b`（ただし $x\in[$`l`$,$`r`$)$）を追加する。
- `get(x)`: $x =$ `x` での $y$ 座標の最小を求める。