---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/static_range_sum.test.cpp
    title: test/library-checker/static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/cumulative_sum.hpp\"\n#include<vector>\ntemplate\
    \ <typename T>\nstruct CumulativeSum {\n    int n;\n    std::vector<T> cumsum;\n\
    \    CumulativeSum() {\n    }\n    CumulativeSum(std::vector<T>& d) : n(d.size()),\
    \ cumsum(n + 1) {\n        for (int i = 0; i < n; i++) {\n            cumsum[i\
    \ + 1] = cumsum[i] + d[i];\n        }\n    }\n    T sum(int l, int r) {\n    \
    \    // 0-indexed\n        // [l, r)\n        return cumsum[r] - cumsum[l];\n\
    \    }\n};\n"
  code: "#pragma once\n#include<vector>\ntemplate <typename T>\nstruct CumulativeSum\
    \ {\n    int n;\n    std::vector<T> cumsum;\n    CumulativeSum() {\n    }\n  \
    \  CumulativeSum(std::vector<T>& d) : n(d.size()), cumsum(n + 1) {\n        for\
    \ (int i = 0; i < n; i++) {\n            cumsum[i + 1] = cumsum[i] + d[i];\n \
    \       }\n    }\n    T sum(int l, int r) {\n        // 0-indexed\n        //\
    \ [l, r)\n        return cumsum[r] - cumsum[l];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/cumulative_sum.hpp
  requiredBy: []
  timestamp: '2022-09-02 13:25:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/static_range_sum.test.cpp
documentation_of: datastructure/cumulative_sum.hpp
layout: document
title: "\u7D2F\u7A4D\u548C"
---

### 概要
累積和を前計算することで区間和を高速に計算する。
### 使い方
- `CumulativeSum(d)`: 数列 $\mathrm d$ で初期化する。
- `sum(l, r)`: $\mathrm d_l + \mathrm d_{l+1} + \cdots +\mathrm d_{r-1}$ を求める。
### 計算量
- `CumulativeSum(d)`: $\mathcal O(N)$
- `sum(l, r)`: $\mathcal O(1)$