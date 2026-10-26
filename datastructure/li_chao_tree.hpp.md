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
  - icon: ':heavy_check_mark:'
    path: test/unit/li_chao_tree.test.cpp
    title: test/unit/li_chao_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/li_chao_tree.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <optional>\n#include <utility>\n#include <vector>\n\
    \ntemplate <class T> struct li_chao_tree {\n    li_chao_tree(long long lo, long\
    \ long hi) : lo(lo), hi(hi) {\n        assert(lo < hi);\n        make_node();\n\
    \    }\n    void add_line(T a, T b) { add_line(0, lo, hi, a, b); }\n    void add_segment(T\
    \ a, T b, long long l, long long r) {\n        assert(lo <= l && l <= r && r <=\
    \ hi);\n        add_segment(0, lo, hi, l, r, a, b);\n    }\n    std::optional<T>\
    \ min(long long x) const {\n        assert(lo <= x && x < hi);\n        std::optional<T>\
    \ res;\n        long long l = lo, r = hi;\n        for (int t = 0; t != -1;) {\n\
    \            const node& v = get(t);\n            if (v.has) {\n             \
    \   T y = v.a * x + v.b;\n                if (!res || y < *res) res = y;\n   \
    \         }\n            long long m = l + (r - l) / 2;\n            if (x < m)\
    \ {\n                r = m;\n                t = v.left;\n            } else {\n\
    \                l = m;\n                t = v.right;\n            }\n       \
    \ }\n        return res;\n    }\n\n  private:\n    struct node {\n        T a\
    \ = 0, b = 0;\n        bool has = false;\n        int left = -1, right = -1;\n\
    \    };\n    static constexpr int chunk_log = 16;\n    long long lo, hi;\n   \
    \ int num_nodes = 0;\n    std::vector<std::vector<node>> chunks;\n    node& get(int\
    \ t) { return chunks[t >> chunk_log][t & ((1 << chunk_log) - 1)]; }\n    const\
    \ node& get(int t) const {\n        return chunks[t >> chunk_log][t & ((1 << chunk_log)\
    \ - 1)];\n    }\n    int make_node() {\n        if ((num_nodes & ((1 << chunk_log)\
    \ - 1)) == 0) {\n            chunks.emplace_back();\n            chunks.back().reserve(1\
    \ << chunk_log);\n        }\n        chunks.back().push_back({});\n        return\
    \ num_nodes++;\n    }\n    void add_line(int t, long long l, long long r, T a,\
    \ T b) {\n        while (true) {\n            node& v = get(t);\n            if\
    \ (!v.has) {\n                v.a = a, v.b = b, v.has = true;\n              \
    \  return;\n            }\n            bool left_better = a * l + b < v.a * l\
    \ + v.b;\n            bool right_better = a * (r - 1) + b < v.a * (r - 1) + v.b;\n\
    \            if (left_better && right_better) {\n                v.a = a, v.b\
    \ = b;\n                return;\n            }\n            if (!left_better &&\
    \ !right_better) return;\n            long long m = l + (r - l) / 2;\n       \
    \     bool mid_better = a * m + b < v.a * m + v.b;\n            if (mid_better)\
    \ std::swap(v.a, a), std::swap(v.b, b);\n            if (left_better != mid_better)\
    \ {\n                if (get(t).left == -1) get(t).left = make_node();\n     \
    \           t = get(t).left, r = m;\n            } else {\n                if\
    \ (get(t).right == -1) get(t).right = make_node();\n                t = get(t).right,\
    \ l = m;\n            }\n        }\n    }\n    void add_segment(int t, long long\
    \ l, long long r, long long ql, long long qr,\n                     T a, T b)\
    \ {\n        if (qr <= l || r <= ql) return;\n        if (ql <= l && r <= qr)\
    \ {\n            add_line(t, l, r, a, b);\n            return;\n        }\n  \
    \      long long m = l + (r - l) / 2;\n        if (ql < m) {\n            if (get(t).left\
    \ == -1) get(t).left = make_node();\n            add_segment(get(t).left, l, m,\
    \ ql, qr, a, b);\n        }\n        if (m < qr) {\n            if (get(t).right\
    \ == -1) get(t).right = make_node();\n            add_segment(get(t).right, m,\
    \ r, ql, qr, a, b);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <optional>\n\
    #include <utility>\n#include <vector>\n\ntemplate <class T> struct li_chao_tree\
    \ {\n    li_chao_tree(long long lo, long long hi) : lo(lo), hi(hi) {\n       \
    \ assert(lo < hi);\n        make_node();\n    }\n    void add_line(T a, T b) {\
    \ add_line(0, lo, hi, a, b); }\n    void add_segment(T a, T b, long long l, long\
    \ long r) {\n        assert(lo <= l && l <= r && r <= hi);\n        add_segment(0,\
    \ lo, hi, l, r, a, b);\n    }\n    std::optional<T> min(long long x) const {\n\
    \        assert(lo <= x && x < hi);\n        std::optional<T> res;\n        long\
    \ long l = lo, r = hi;\n        for (int t = 0; t != -1;) {\n            const\
    \ node& v = get(t);\n            if (v.has) {\n                T y = v.a * x +\
    \ v.b;\n                if (!res || y < *res) res = y;\n            }\n      \
    \      long long m = l + (r - l) / 2;\n            if (x < m) {\n            \
    \    r = m;\n                t = v.left;\n            } else {\n             \
    \   l = m;\n                t = v.right;\n            }\n        }\n        return\
    \ res;\n    }\n\n  private:\n    struct node {\n        T a = 0, b = 0;\n    \
    \    bool has = false;\n        int left = -1, right = -1;\n    };\n    static\
    \ constexpr int chunk_log = 16;\n    long long lo, hi;\n    int num_nodes = 0;\n\
    \    std::vector<std::vector<node>> chunks;\n    node& get(int t) { return chunks[t\
    \ >> chunk_log][t & ((1 << chunk_log) - 1)]; }\n    const node& get(int t) const\
    \ {\n        return chunks[t >> chunk_log][t & ((1 << chunk_log) - 1)];\n    }\n\
    \    int make_node() {\n        if ((num_nodes & ((1 << chunk_log) - 1)) == 0)\
    \ {\n            chunks.emplace_back();\n            chunks.back().reserve(1 <<\
    \ chunk_log);\n        }\n        chunks.back().push_back({});\n        return\
    \ num_nodes++;\n    }\n    void add_line(int t, long long l, long long r, T a,\
    \ T b) {\n        while (true) {\n            node& v = get(t);\n            if\
    \ (!v.has) {\n                v.a = a, v.b = b, v.has = true;\n              \
    \  return;\n            }\n            bool left_better = a * l + b < v.a * l\
    \ + v.b;\n            bool right_better = a * (r - 1) + b < v.a * (r - 1) + v.b;\n\
    \            if (left_better && right_better) {\n                v.a = a, v.b\
    \ = b;\n                return;\n            }\n            if (!left_better &&\
    \ !right_better) return;\n            long long m = l + (r - l) / 2;\n       \
    \     bool mid_better = a * m + b < v.a * m + v.b;\n            if (mid_better)\
    \ std::swap(v.a, a), std::swap(v.b, b);\n            if (left_better != mid_better)\
    \ {\n                if (get(t).left == -1) get(t).left = make_node();\n     \
    \           t = get(t).left, r = m;\n            } else {\n                if\
    \ (get(t).right == -1) get(t).right = make_node();\n                t = get(t).right,\
    \ l = m;\n            }\n        }\n    }\n    void add_segment(int t, long long\
    \ l, long long r, long long ql, long long qr,\n                     T a, T b)\
    \ {\n        if (qr <= l || r <= ql) return;\n        if (ql <= l && r <= qr)\
    \ {\n            add_line(t, l, r, a, b);\n            return;\n        }\n  \
    \      long long m = l + (r - l) / 2;\n        if (ql < m) {\n            if (get(t).left\
    \ == -1) get(t).left = make_node();\n            add_segment(get(t).left, l, m,\
    \ ql, qr, a, b);\n        }\n        if (m < qr) {\n            if (get(t).right\
    \ == -1) get(t).right = make_node();\n            add_segment(get(t).right, m,\
    \ r, ql, qr, a, b);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2026-10-26 22:16:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/li_chao_tree.test.cpp
  - test/library-checker/line_add_get_min.test.cpp
  - test/library-checker/segment_add_get_min.test.cpp
documentation_of: datastructure/li_chao_tree.hpp
layout: document
title: Li Chao Tree
---

### 概要
- 直線と線分を追加し、ある $x$ での $y$ の最小値を答える。

### 使い方
- `li_chao_tree<T>(lo, hi)`: $x$ の範囲を $[\text{lo}, \text{hi})$ として作る。`T` は $y$ の型。
- `add_line(a, b)`: 直線 $y = ax + b$ を追加する。
- `add_segment(a, b, l, r)`: 線分 $y = ax + b$ ($l \le x < r$) を追加する。
- `min(x)`: $x$ での $y$ の最小値を返す。$x$ を通る直線も線分も無ければ `std::nullopt`。

### 制約
- $\text{lo} < \text{hi}$
- `add_segment`: $\text{lo} \le l \le r \le \text{hi}$
- `min`: $\text{lo} \le x < \text{hi}$

### 計算量
- $N = \text{hi} - \text{lo}$ として
- `add_line`, `min`: $\mathcal{O}(\log N)$
- `add_segment`: $\mathcal{O}(\log^2 N)$
