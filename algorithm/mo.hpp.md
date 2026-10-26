---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/static_range_inversions_query.test.cpp
    title: test/library-checker/static_range_inversions_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/mo.test.cpp
    title: test/unit/mo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/mo.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n#include <cstdlib>\n#include <numeric>\n#include <utility>\n\
    #include <vector>\n\nstruct mo {\n    mo() = default;\n    int add(int l, int\
    \ r) {\n        assert(0 <= l && l <= r);\n        lr.emplace_back(l, r);\n  \
    \      return (int)lr.size() - 1;\n    }\n    void run(auto add_left, auto add_right,\
    \ auto erase_left, auto erase_right,\n             auto query) const {\n     \
    \   int l = 0, r = 0;\n        for (int i : order()) {\n            while (l >\
    \ lr[i].first) add_left(--l);\n            while (r < lr[i].second) add_right(r++);\n\
    \            while (l < lr[i].first) erase_left(l++);\n            while (r >\
    \ lr[i].second) erase_right(--r);\n            query(i);\n        }\n    }\n \
    \   void run(auto add, auto erase, auto query) const {\n        run(add, add,\
    \ erase, erase, query);\n    }\n\n  private:\n    std::vector<std::pair<int, int>>\
    \ lr;\n    std::vector<int> order() const {\n        int q = lr.size();\n    \
    \    if (q == 0) return {};\n        int n = 1;\n        for (auto [l, r] : lr)\
    \ n = std::max(n, r);\n        int w = std::max(1, (int)(std::sqrt(3.0) * n /\
    \ std::sqrt(2.0 * q)));\n        std::vector<int> ord(q);\n        std::iota(ord.begin(),\
    \ ord.end(), 0);\n        std::sort(ord.begin(), ord.end(), [&](int a, int b)\
    \ {\n            int ba = lr[a].first / w, bb = lr[b].first / w;\n           \
    \ if (ba != bb) return ba < bb;\n            return (ba & 1) ? lr[a].second >\
    \ lr[b].second\n                            : lr[a].second < lr[b].second;\n \
    \       });\n        auto cost = [&](int a, int b) {\n            return std::abs(lr[ord[a]].first\
    \ - lr[ord[b]].first) +\n                   std::abs(lr[ord[a]].second - lr[ord[b]].second);\n\
    \        };\n        auto improve = [&](int k) {\n            if (cost(k, k +\
    \ 2) + cost(k + 1, k + 3) <\n                cost(k, k + 1) + cost(k + 2, k +\
    \ 3))\n                std::swap(ord[k + 1], ord[k + 2]);\n            if (cost(k,\
    \ k + 3) + cost(k + 1, k + 4) <\n                cost(k, k + 1) + cost(k + 3,\
    \ k + 4))\n                std::swap(ord[k + 1], ord[k + 3]);\n        };\n  \
    \      for (int k = 0; k + 5 <= q; k++) improve(k);\n        for (int k = q -\
    \ 5; k >= 0; k--) improve(k);\n        return ord;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <cstdlib>\n#include <numeric>\n#include <utility>\n#include <vector>\n\
    \nstruct mo {\n    mo() = default;\n    int add(int l, int r) {\n        assert(0\
    \ <= l && l <= r);\n        lr.emplace_back(l, r);\n        return (int)lr.size()\
    \ - 1;\n    }\n    void run(auto add_left, auto add_right, auto erase_left, auto\
    \ erase_right,\n             auto query) const {\n        int l = 0, r = 0;\n\
    \        for (int i : order()) {\n            while (l > lr[i].first) add_left(--l);\n\
    \            while (r < lr[i].second) add_right(r++);\n            while (l <\
    \ lr[i].first) erase_left(l++);\n            while (r > lr[i].second) erase_right(--r);\n\
    \            query(i);\n        }\n    }\n    void run(auto add, auto erase, auto\
    \ query) const {\n        run(add, add, erase, erase, query);\n    }\n\n  private:\n\
    \    std::vector<std::pair<int, int>> lr;\n    std::vector<int> order() const\
    \ {\n        int q = lr.size();\n        if (q == 0) return {};\n        int n\
    \ = 1;\n        for (auto [l, r] : lr) n = std::max(n, r);\n        int w = std::max(1,\
    \ (int)(std::sqrt(3.0) * n / std::sqrt(2.0 * q)));\n        std::vector<int> ord(q);\n\
    \        std::iota(ord.begin(), ord.end(), 0);\n        std::sort(ord.begin(),\
    \ ord.end(), [&](int a, int b) {\n            int ba = lr[a].first / w, bb = lr[b].first\
    \ / w;\n            if (ba != bb) return ba < bb;\n            return (ba & 1)\
    \ ? lr[a].second > lr[b].second\n                            : lr[a].second <\
    \ lr[b].second;\n        });\n        auto cost = [&](int a, int b) {\n      \
    \      return std::abs(lr[ord[a]].first - lr[ord[b]].first) +\n              \
    \     std::abs(lr[ord[a]].second - lr[ord[b]].second);\n        };\n        auto\
    \ improve = [&](int k) {\n            if (cost(k, k + 2) + cost(k + 1, k + 3)\
    \ <\n                cost(k, k + 1) + cost(k + 2, k + 3))\n                std::swap(ord[k\
    \ + 1], ord[k + 2]);\n            if (cost(k, k + 3) + cost(k + 1, k + 4) <\n\
    \                cost(k, k + 1) + cost(k + 3, k + 4))\n                std::swap(ord[k\
    \ + 1], ord[k + 3]);\n        };\n        for (int k = 0; k + 5 <= q; k++) improve(k);\n\
    \        for (int k = q - 5; k >= 0; k--) improve(k);\n        return ord;\n \
    \   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/mo.hpp
  requiredBy: []
  timestamp: '2026-10-26 21:23:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/mo.test.cpp
  - test/library-checker/static_range_inversions_query.test.cpp
documentation_of: algorithm/mo.hpp
layout: document
title: Mo's Algorithm
---

### 概要
- 区間クエリをオフラインで処理する。

### 使い方
- `mo()`: クエリの無い状態で作る。
- `add(l, r)`: 区間 $[l, r)$ のクエリを追加し、クエリ番号を返す。番号は追加順。
- `run(add_left, add_right, erase_left, erase_right, query)`: 区間 $[0, 0)$ から始めて、区間を 1 要素ずつ動かしながら全クエリに答える。`add_left(i)`, `add_right(i)` は要素 $i$ を区間の左端, 右端に加え、`erase_left(i)`, `erase_right(i)` は要素 $i$ を区間の左端, 右端から除き、`query(k)` はクエリ $k$ に答える。区間は伸ばしてから縮める。
- `run(add, erase, query)`: 左右で同じ関数を使う。

### 制約
- $0 \le l \le r$

### 計算量
- `add`: $\mathcal{O}(1)$
- `run`: $\mathcal{O}(q \log q)$ に加えて `add_left` などを合計 $\mathcal{O}(n \sqrt{q})$ 回呼ぶ。$n$ は $r$ の最大値。
