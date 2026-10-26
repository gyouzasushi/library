---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_D.test.cpp
    title: test/aoj/DPL_1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/longest_increasing_subsequence.test.cpp
    title: test/library-checker/longest_increasing_subsequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/longest_increasing_subsequence.test.cpp
    title: test/unit/longest_increasing_subsequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/longest_increasing_subsequence.hpp\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <functional>\n#include <vector>\n\n\
    template <class T, class Compare = std::less<T>>\nstruct longest_increasing_subsequence\
    \ {\n    explicit longest_increasing_subsequence(const std::vector<T>& a,\n  \
    \                                          Compare comp = {})\n        : n(a.size()),\
    \ pos(n) {\n        std::vector<T> dp;\n        for (int i = 0; i < n; i++) {\n\
    \            auto it = std::lower_bound(dp.begin(), dp.end(), a[i], comp);\n \
    \           pos[i] = it - dp.begin();\n            if (it == dp.end()) {\n   \
    \             dp.push_back(a[i]);\n            } else {\n                *it =\
    \ a[i];\n            }\n        }\n        len = dp.size();\n        cand.resize(len);\n\
    \        for (int i = n - 1; i >= 0; i--) {\n            int j = pos[i];\n   \
    \         if (j == len - 1 ||\n                (!cand[j + 1].empty() && comp(a[i],\
    \ a[cand[j + 1].back()]))) {\n                cand[j].push_back(i);\n        \
    \    } else {\n                pos[i] = -1;\n            }\n        }\n      \
    \  for (auto& c : cand) std::reverse(c.begin(), c.end());\n    }\n    int length()\
    \ const { return len; }\n    int position(int i) const {\n        assert(0 <=\
    \ i && i < n);\n        return pos[i];\n    }\n    const std::vector<int>& candidates(int\
    \ j) const {\n        assert(0 <= j && j < len);\n        return cand[j];\n  \
    \  }\n    std::vector<int> indices() const {\n        std::vector<int> res(len);\n\
    \        for (int j = 0; j < len; j++) res[j] = cand[j].front();\n        return\
    \ res;\n    }\n\n  private:\n    int n, len;\n    std::vector<int> pos;\n    std::vector<std::vector<int>>\
    \ cand;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <functional>\n\
    #include <vector>\n\ntemplate <class T, class Compare = std::less<T>>\nstruct\
    \ longest_increasing_subsequence {\n    explicit longest_increasing_subsequence(const\
    \ std::vector<T>& a,\n                                            Compare comp\
    \ = {})\n        : n(a.size()), pos(n) {\n        std::vector<T> dp;\n       \
    \ for (int i = 0; i < n; i++) {\n            auto it = std::lower_bound(dp.begin(),\
    \ dp.end(), a[i], comp);\n            pos[i] = it - dp.begin();\n            if\
    \ (it == dp.end()) {\n                dp.push_back(a[i]);\n            } else\
    \ {\n                *it = a[i];\n            }\n        }\n        len = dp.size();\n\
    \        cand.resize(len);\n        for (int i = n - 1; i >= 0; i--) {\n     \
    \       int j = pos[i];\n            if (j == len - 1 ||\n                (!cand[j\
    \ + 1].empty() && comp(a[i], a[cand[j + 1].back()]))) {\n                cand[j].push_back(i);\n\
    \            } else {\n                pos[i] = -1;\n            }\n        }\n\
    \        for (auto& c : cand) std::reverse(c.begin(), c.end());\n    }\n    int\
    \ length() const { return len; }\n    int position(int i) const {\n        assert(0\
    \ <= i && i < n);\n        return pos[i];\n    }\n    const std::vector<int>&\
    \ candidates(int j) const {\n        assert(0 <= j && j < len);\n        return\
    \ cand[j];\n    }\n    std::vector<int> indices() const {\n        std::vector<int>\
    \ res(len);\n        for (int j = 0; j < len; j++) res[j] = cand[j].front();\n\
    \        return res;\n    }\n\n  private:\n    int n, len;\n    std::vector<int>\
    \ pos;\n    std::vector<std::vector<int>> cand;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2026-10-26 21:56:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_1_D.test.cpp
  - test/unit/longest_increasing_subsequence.test.cpp
  - test/library-checker/longest_increasing_subsequence.test.cpp
documentation_of: algorithm/longest_increasing_subsequence.hpp
layout: document
title: Longest Increasing Subsequence
---

### 概要
- 数列の最長増加部分列 (LIS) の長さと、各要素が LIS に使われ得るかを求める。LIS は添字の列として扱う。

### 使い方
- `longest_increasing_subsequence<T, Compare = std::less<T>>(a, comp = {})`: 数列 `a` について構築する。`comp(x, y)` が真のとき `x` の後に `y` を置ける。
- `length()`: LIS の長さを返す。
- `position(i)`: `a[i]` を使う LIS があればその中での `a[i]` の位置 (0-indexed)、なければ $-1$ を返す。
- `candidates(j)`: LIS の `j` 番目になり得る添字を昇順に並べた列を返す。値は降順。
- `indices()`: 添字の辞書順最小の LIS を返す。

### 制約
- `position`: $0 \le i < \lvert a \rvert$
- `candidates`: $0 \le j <$ `length()`

### 計算量
- 構築: $\mathcal{O}(n \log n)$
- `length`, `position`, `candidates`: $\mathcal{O}(1)$
- `indices`: $\mathcal{O}(n)$
