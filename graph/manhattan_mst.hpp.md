---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/manhattanmst.test.cpp
    title: test/library-checker/manhattanmst.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/manhattan_mst.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <map>\n#include <numeric>\n#include <vector>\ntemplate <typename\
    \ T>\nstd::vector<std::tuple<int, int, T>> manhattan_mst(std::vector<T> x,\n \
    \                                                  std::vector<T> y) {\n    int\
    \ n = x.size();\n    assert(int(x.size()) == n && int(y.size()) == n);\n    std::vector<int>\
    \ id(n);\n    std::iota(id.begin(), id.end(), 0);\n\n    std::vector<std::tuple<int,\
    \ int, T>> ret;\n    for (int gyouza = 0; gyouza < 2; gyouza++) {\n        for\
    \ (int sushi = 0; sushi < 2; sushi++) {\n            std::sort(id.begin(), id.end(),\
    \ [&](int i, int j) {\n                if (y[i] == y[j]) {\n                 \
    \   return x[i] < x[j];\n                }\n                return y[i] < y[j];\n\
    \            });\n            std::map<T, int> mp;\n            for (int i : id)\
    \ {\n                if (auto it = mp.upper_bound(x[i]); it != mp.begin()) {\n\
    \                    int j = prev(it)->second;\n                    ret.emplace_back(i,\
    \ j, abs(x[i] - x[j]) + abs(y[i] - y[j]));\n                }\n              \
    \  for (auto it = mp.lower_bound(x[i]); it != mp.end();\n                    \
    \ it = mp.erase(it)) {\n                    int j = it->second;\n            \
    \        if (x[i] + y[i] <= x[j] + y[j]) break;\n                }\n         \
    \       mp[x[i]] = i;\n            }\n            for (T &x : x) x = -x;\n   \
    \     }\n        for (T &y : y) y = -y;\n    }\n    sort(ret.begin(), ret.end(),\n\
    \         [](auto a, auto b) { return std::get<2>(a) < std::get<2>(b); });\n \
    \   return ret;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <map>\n\
    #include <numeric>\n#include <vector>\ntemplate <typename T>\nstd::vector<std::tuple<int,\
    \ int, T>> manhattan_mst(std::vector<T> x,\n                                 \
    \                  std::vector<T> y) {\n    int n = x.size();\n    assert(int(x.size())\
    \ == n && int(y.size()) == n);\n    std::vector<int> id(n);\n    std::iota(id.begin(),\
    \ id.end(), 0);\n\n    std::vector<std::tuple<int, int, T>> ret;\n    for (int\
    \ gyouza = 0; gyouza < 2; gyouza++) {\n        for (int sushi = 0; sushi < 2;\
    \ sushi++) {\n            std::sort(id.begin(), id.end(), [&](int i, int j) {\n\
    \                if (y[i] == y[j]) {\n                    return x[i] < x[j];\n\
    \                }\n                return y[i] < y[j];\n            });\n   \
    \         std::map<T, int> mp;\n            for (int i : id) {\n             \
    \   if (auto it = mp.upper_bound(x[i]); it != mp.begin()) {\n                \
    \    int j = prev(it)->second;\n                    ret.emplace_back(i, j, abs(x[i]\
    \ - x[j]) + abs(y[i] - y[j]));\n                }\n                for (auto it\
    \ = mp.lower_bound(x[i]); it != mp.end();\n                     it = mp.erase(it))\
    \ {\n                    int j = it->second;\n                    if (x[i] + y[i]\
    \ <= x[j] + y[j]) break;\n                }\n                mp[x[i]] = i;\n \
    \           }\n            for (T &x : x) x = -x;\n        }\n        for (T &y\
    \ : y) y = -y;\n    }\n    sort(ret.begin(), ret.end(),\n         [](auto a, auto\
    \ b) { return std::get<2>(a) < std::get<2>(b); });\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/manhattan_mst.hpp
  requiredBy: []
  timestamp: '2023-01-09 23:28:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/manhattanmst.test.cpp
documentation_of: graph/manhattan_mst.hpp
layout: document
title: Manhattan MST
---

### 概要
- 2次元平面上にある $N$ 個の点に対して、2点間の距離をマンハッタン距離で定義したときの最小全域木を求める。
- まだ嘘です
  
### 使い方
- `manhattan_mst(x, y)`: 最小全域木に含まれ得る $O(N)$ 本の辺 `(u, v, w)` を、重みの昇順で返す。 