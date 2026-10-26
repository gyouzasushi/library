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
  bundledCode: "#line 2 \"datastructure/cumulative_sum.hpp\"\n#include <cassert>\n\
    #include <vector>\n\ntemplate <class T> struct cumulative_sum {\n    cumulative_sum()\
    \ = default;\n    explicit cumulative_sum(const std::vector<T>& a) : n(a.size()),\
    \ s(n + 1) {\n        for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];\n  \
    \  }\n    T sum(int l, int r) const {\n        assert(0 <= l && l <= r && r <=\
    \ n);\n        return s[r] - s[l];\n    }\n\n  private:\n    int n = 0;\n    std::vector<T>\
    \ s;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <class T>\
    \ struct cumulative_sum {\n    cumulative_sum() = default;\n    explicit cumulative_sum(const\
    \ std::vector<T>& a) : n(a.size()), s(n + 1) {\n        for (int i = 0; i < n;\
    \ i++) s[i + 1] = s[i] + a[i];\n    }\n    T sum(int l, int r) const {\n     \
    \   assert(0 <= l && l <= r && r <= n);\n        return s[r] - s[l];\n    }\n\n\
    \  private:\n    int n = 0;\n    std::vector<T> s;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/cumulative_sum.hpp
  requiredBy: []
  timestamp: '2026-10-26 22:21:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/static_range_sum.test.cpp
documentation_of: datastructure/cumulative_sum.hpp
layout: document
title: Cumulative Sum
---

### 概要
- 数列の区間和を答える。

### 使い方
- `cumulative_sum<T>(a)`: 数列 `a` で構築する。
- `sum(l, r)`: $a_l + a_{l+1} + \cdots + a_{r-1}$ を返す。

### 制約
- $0 \le l \le r \le n$

### 計算量
- 構築: $\mathcal{O}(n)$
- `sum`: $\mathcal{O}(1)$
