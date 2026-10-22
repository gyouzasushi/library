---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/segtree.hpp
    title: Segment Tree (monoid wrapper)
  - icon: ':heavy_check_mark:'
    path: monoid/argmin.hpp
    title: 'Monoid: Argmin'
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/manhattanmst.test.cpp
    title: test/library-checker/manhattanmst.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/manhattan_mst.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <numeric>\n#include <tuple>\n#include <vector>\n\n#line\
    \ 2 \"datastructure/segtree.hpp\"\n#include <atcoder/segtree>\ntemplate <class\
    \ M>\nusing segtree = atcoder::segtree<typename M::S, M::op, M::e>;\n#line 2 \"\
    monoid/argmin.hpp\"\n#include <limits>\ntemplate <class T>\nstruct monoid_argmin\
    \ {\n    struct S {\n        T val;\n        int id;\n    };\n    static S op(S\
    \ a, S b) {\n        if (a.val != b.val) return a.val < b.val ? a : b;\n     \
    \   return a.id < b.id ? a : b;\n    }\n    static S e() {\n        return {std::numeric_limits<T>::max(),\
    \ -1};\n    }\n    static constexpr bool commutative = true;\n};\n#line 10 \"\
    graph/manhattan_mst.hpp\"\ntemplate <typename T>\nstd::vector<std::tuple<int,\
    \ int, T>> manhattan_mst(std::vector<T> x,\n                                 \
    \                  std::vector<T> y) {\n    int n = x.size();\n    assert(int(y.size())\
    \ == n);\n    std::vector<int> id(n);\n    std::iota(id.begin(), id.end(), 0);\n\
    \    std::vector<int> y_id(n);\n    std::vector<std::tuple<int, int, T>> ret;\n\
    \    for (int a = 0; a < 2; a++) {\n        for (int b = 0; b < 2; b++) {\n  \
    \          for (int c = 0; c < 2; c++) {\n                sort(id.begin(), id.end(),\
    \ [&](int i, int j) {\n                    if (y[i] - x[i] == y[j] - x[j] && y[i]\
    \ == y[j])\n                        return i < j;\n                    if (y[i]\
    \ - x[i] == y[j] - x[j]) return y[i] > y[j];\n                    return y[i]\
    \ - x[i] < y[j] - x[j];\n                });\n                std::vector<T> _y\
    \ = y;\n                std::sort(_y.begin(), _y.end());\n                for\
    \ (int i = 0; i < n; i++) {\n                    y_id[i] = std::lower_bound(_y.begin(),\
    \ _y.end(), y[i]) -\n                              _y.begin();\n             \
    \   }\n                segtree<monoid_argmin<T>> segt(n);\n                for\
    \ (int i : id) {\n                    auto p = segt.prod(y_id[i], n);\n      \
    \              if (p.id != -1) {\n                        ret.emplace_back(i,\
    \ p.id, p.val - (x[i] + y[i]));\n                    }\n                    segt.set(y_id[i],\
    \ {x[i] + y[i], i});\n                }\n                std::swap(x, y);\n  \
    \          }\n            for (T &x : x) x = -x;\n        }\n        for (T &y\
    \ : y) y = -y;\n    }\n    sort(ret.begin(), ret.end(),\n         [](auto a, auto\
    \ b) { return std::get<2>(a) < std::get<2>(b); });\n    return ret;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n\
    #include <tuple>\n#include <vector>\n\n#include \"datastructure/segtree.hpp\"\n\
    #include \"monoid/argmin.hpp\"\ntemplate <typename T>\nstd::vector<std::tuple<int,\
    \ int, T>> manhattan_mst(std::vector<T> x,\n                                 \
    \                  std::vector<T> y) {\n    int n = x.size();\n    assert(int(y.size())\
    \ == n);\n    std::vector<int> id(n);\n    std::iota(id.begin(), id.end(), 0);\n\
    \    std::vector<int> y_id(n);\n    std::vector<std::tuple<int, int, T>> ret;\n\
    \    for (int a = 0; a < 2; a++) {\n        for (int b = 0; b < 2; b++) {\n  \
    \          for (int c = 0; c < 2; c++) {\n                sort(id.begin(), id.end(),\
    \ [&](int i, int j) {\n                    if (y[i] - x[i] == y[j] - x[j] && y[i]\
    \ == y[j])\n                        return i < j;\n                    if (y[i]\
    \ - x[i] == y[j] - x[j]) return y[i] > y[j];\n                    return y[i]\
    \ - x[i] < y[j] - x[j];\n                });\n                std::vector<T> _y\
    \ = y;\n                std::sort(_y.begin(), _y.end());\n                for\
    \ (int i = 0; i < n; i++) {\n                    y_id[i] = std::lower_bound(_y.begin(),\
    \ _y.end(), y[i]) -\n                              _y.begin();\n             \
    \   }\n                segtree<monoid_argmin<T>> segt(n);\n                for\
    \ (int i : id) {\n                    auto p = segt.prod(y_id[i], n);\n      \
    \              if (p.id != -1) {\n                        ret.emplace_back(i,\
    \ p.id, p.val - (x[i] + y[i]));\n                    }\n                    segt.set(y_id[i],\
    \ {x[i] + y[i], i});\n                }\n                std::swap(x, y);\n  \
    \          }\n            for (T &x : x) x = -x;\n        }\n        for (T &y\
    \ : y) y = -y;\n    }\n    sort(ret.begin(), ret.end(),\n         [](auto a, auto\
    \ b) { return std::get<2>(a) < std::get<2>(b); });\n    return ret;\n}"
  dependsOn:
  - datastructure/segtree.hpp
  - monoid/argmin.hpp
  isVerificationFile: false
  path: graph/manhattan_mst.hpp
  requiredBy: []
  timestamp: '2026-10-22 18:09:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/manhattanmst.test.cpp
documentation_of: graph/manhattan_mst.hpp
layout: document
title: Manhattan MST
---

### 概要
- 2次元平面上にある $N$ 個の点に対して、2点間の距離をマンハッタン距離で定義したときの最小全域木を求める。
  
### 使い方
- `manhattan_mst(x, y)`: 最小全域木に含まれ得る $O(N)$ 本の辺 `(u, v, w)` を、重みの昇順で返す。 