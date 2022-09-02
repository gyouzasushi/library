---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_D.test.cpp
    title: test/aoj/DPL_1_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/longest_increasing_subsequence.hpp\"\n#include\
    \ <vector>\ntemplate <typename T, class Compare>\nstd::vector<T> longest_increasing_subsequence(const\
    \ std::vector<T> &a,\n                                              Compare comp)\
    \ {\n    const int n = a.size();\n    std::vector<T> dp;\n    std::vector<int>\
    \ id(n);\n    for (int i = 0; i < n; i++) {\n        typename std::vector<T>::iterator\
    \ it =\n            std::lower_bound(dp.begin(), dp.end(), a[i], comp);\n    \
    \    id[i] = std::distance(dp.begin(), it);\n        if (it == dp.end()) {\n \
    \           dp.push_back(a[i]);\n        } else {\n            *it = a[i];\n \
    \       }\n    }\n    std::vector<T> lis(dp.size());\n    for (int i = n - 1,\
    \ j = lis.size() - 1; i >= 0; i--) {\n        if (id[i] == j) {\n            lis[j--]\
    \ = i;\n        }\n    }\n    return lis;\n}\ntemplate <typename T>\nstd::vector<T>\
    \ longest_increasing_subsequence(const std::vector<T> &a) {\n    return longest_increasing_subsequence(a,\
    \ std::less<T>());\n}\n"
  code: "#pragma once\n#include <vector>\ntemplate <typename T, class Compare>\nstd::vector<T>\
    \ longest_increasing_subsequence(const std::vector<T> &a,\n                  \
    \                            Compare comp) {\n    const int n = a.size();\n  \
    \  std::vector<T> dp;\n    std::vector<int> id(n);\n    for (int i = 0; i < n;\
    \ i++) {\n        typename std::vector<T>::iterator it =\n            std::lower_bound(dp.begin(),\
    \ dp.end(), a[i], comp);\n        id[i] = std::distance(dp.begin(), it);\n   \
    \     if (it == dp.end()) {\n            dp.push_back(a[i]);\n        } else {\n\
    \            *it = a[i];\n        }\n    }\n    std::vector<T> lis(dp.size());\n\
    \    for (int i = n - 1, j = lis.size() - 1; i >= 0; i--) {\n        if (id[i]\
    \ == j) {\n            lis[j--] = i;\n        }\n    }\n    return lis;\n}\ntemplate\
    \ <typename T>\nstd::vector<T> longest_increasing_subsequence(const std::vector<T>\
    \ &a) {\n    return longest_increasing_subsequence(a, std::less<T>());\n}"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2022-09-02 13:25:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_1_D.test.cpp
documentation_of: algorithm/longest_increasing_subsequence.hpp
layout: document
title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217(LIS)"
---

### 概要
最長増加部分列(LIS)をひとつ求める。
### 使い方
- `longeset_incresing_subsequence(a)`: 数列 $\mathrm a$ の(狭義)最長増加部分列のうち辞書順最小であるものの**添字**を求める。
- `longeset_incresing_subsequence(a, comp)`: 比較関数を `comp` としたときの最長増加部分列のうち辞書順最小であるものの**添字**を求める。

    (例) 広義の最長増加部分列を求めるには、`comp = [](T x,T y) { return x <= y;}` (または `comp = std::less_equal<T>()` )のようにする。
### 計算量
- $\mathcal O(N\log N)$