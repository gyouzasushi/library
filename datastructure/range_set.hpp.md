---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2880.test.cpp
    title: test/aoj/2880.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/range_set.test.cpp
    title: test/unit/range_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1601.test.cpp
    title: test/yukicoder/1601.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/range_set.hpp\"\n#include <cassert>\n#include\
    \ <map>\ntemplate <class T>\nstruct range_set {\npublic:\n    using iterator =\
    \ typename std::map<T, T>::const_iterator;\n    range_set() {\n    }\n    // p\
    \ \u3092\u542B\u3080\u533A\u9593\u3002\u7121\u3051\u308C\u3070 end()\n    iterator\
    \ find(T p) const {\n        auto it = ranges.upper_bound(p);\n        if (it\
    \ == ranges.begin()) return ranges.end();\n        it--;\n        if (it->second\
    \ <= p) return ranges.end();\n        return it;\n    }\n    bool contains(T p)\
    \ const {\n        return find(p) != ranges.end();\n    }\n    // [l, r) \u304C\
    \ 1 \u3064\u306E\u533A\u9593\u306B\u542B\u307E\u308C\u308B\u304B\n    bool covers(T\
    \ l, T r) const {\n        assert(l < r);\n        auto it = find(l);\n      \
    \  return it != ranges.end() && r <= it->second;\n    }\n    // x \u4EE5\u4E0A\
    \u3067\u542B\u307E\u308C\u306A\u3044\u6700\u5C0F\u306E\u5024\uFF08\u6574\u6570\
    \u5411\u3051\uFF09\n    T mex(T x) const {\n        auto it = find(x);\n     \
    \   return it == ranges.end() ? x : it->second;\n    }\n    void insert(T l, T\
    \ r) {\n        insert(l, r, [](T, T) {}, [](T, T) {});\n    }\n    // f: \u8FFD\
    \u52A0\u3055\u308C\u305F\u533A\u9593\u3054\u3068\u306B\u547C\u3076, g: \u524A\u9664\
    \u3055\u308C\u305F\u533A\u9593\u3054\u3068\u306B\u547C\u3076\n    template <class\
    \ F, class G>\n    void insert(T l, T r, const F& f, const G& g) {\n        assert(l\
    \ < r);\n        auto it = ranges.upper_bound(l);\n        if (it != ranges.begin()\
    \ && l <= std::prev(it)->second) it--;\n        while (it != ranges.end() && it->first\
    \ <= r) {\n            l = std::min(l, it->first);\n            r = std::max(r,\
    \ it->second);\n            g(it->first, it->second);\n            it = ranges.erase(it);\n\
    \        }\n        ranges[l] = r;\n        f(l, r);\n    }\n    void erase(T\
    \ l, T r) {\n        erase(l, r, [](T, T) {}, [](T, T) {});\n    }\n    template\
    \ <class F, class G>\n    void erase(T l, T r, const F& f, const G& g) {\n   \
    \     assert(l < r);\n        auto it = ranges.upper_bound(l);\n        if (it\
    \ != ranges.begin() && l < std::prev(it)->second) it--;\n        while (it !=\
    \ ranges.end() && it->first < r) {\n            T a = it->first, b = it->second;\n\
    \            g(a, b);\n            it = ranges.erase(it);\n            if (a <\
    \ l) {\n                ranges[a] = l;\n                f(a, l);\n           \
    \ }\n            if (r < b) {\n                ranges[r] = b;\n              \
    \  f(r, b);\n            }\n        }\n    }\n    int size() const {\n       \
    \ return int(ranges.size());\n    }\n    iterator begin() const {\n        return\
    \ ranges.begin();\n    }\n    iterator end() const {\n        return ranges.end();\n\
    \    }\n\nprivate:\n    std::map<T, T> ranges;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <map>\ntemplate <class T>\nstruct\
    \ range_set {\npublic:\n    using iterator = typename std::map<T, T>::const_iterator;\n\
    \    range_set() {\n    }\n    // p \u3092\u542B\u3080\u533A\u9593\u3002\u7121\
    \u3051\u308C\u3070 end()\n    iterator find(T p) const {\n        auto it = ranges.upper_bound(p);\n\
    \        if (it == ranges.begin()) return ranges.end();\n        it--;\n     \
    \   if (it->second <= p) return ranges.end();\n        return it;\n    }\n   \
    \ bool contains(T p) const {\n        return find(p) != ranges.end();\n    }\n\
    \    // [l, r) \u304C 1 \u3064\u306E\u533A\u9593\u306B\u542B\u307E\u308C\u308B\
    \u304B\n    bool covers(T l, T r) const {\n        assert(l < r);\n        auto\
    \ it = find(l);\n        return it != ranges.end() && r <= it->second;\n    }\n\
    \    // x \u4EE5\u4E0A\u3067\u542B\u307E\u308C\u306A\u3044\u6700\u5C0F\u306E\u5024\
    \uFF08\u6574\u6570\u5411\u3051\uFF09\n    T mex(T x) const {\n        auto it\
    \ = find(x);\n        return it == ranges.end() ? x : it->second;\n    }\n   \
    \ void insert(T l, T r) {\n        insert(l, r, [](T, T) {}, [](T, T) {});\n \
    \   }\n    // f: \u8FFD\u52A0\u3055\u308C\u305F\u533A\u9593\u3054\u3068\u306B\u547C\
    \u3076, g: \u524A\u9664\u3055\u308C\u305F\u533A\u9593\u3054\u3068\u306B\u547C\u3076\
    \n    template <class F, class G>\n    void insert(T l, T r, const F& f, const\
    \ G& g) {\n        assert(l < r);\n        auto it = ranges.upper_bound(l);\n\
    \        if (it != ranges.begin() && l <= std::prev(it)->second) it--;\n     \
    \   while (it != ranges.end() && it->first <= r) {\n            l = std::min(l,\
    \ it->first);\n            r = std::max(r, it->second);\n            g(it->first,\
    \ it->second);\n            it = ranges.erase(it);\n        }\n        ranges[l]\
    \ = r;\n        f(l, r);\n    }\n    void erase(T l, T r) {\n        erase(l,\
    \ r, [](T, T) {}, [](T, T) {});\n    }\n    template <class F, class G>\n    void\
    \ erase(T l, T r, const F& f, const G& g) {\n        assert(l < r);\n        auto\
    \ it = ranges.upper_bound(l);\n        if (it != ranges.begin() && l < std::prev(it)->second)\
    \ it--;\n        while (it != ranges.end() && it->first < r) {\n            T\
    \ a = it->first, b = it->second;\n            g(a, b);\n            it = ranges.erase(it);\n\
    \            if (a < l) {\n                ranges[a] = l;\n                f(a,\
    \ l);\n            }\n            if (r < b) {\n                ranges[r] = b;\n\
    \                f(r, b);\n            }\n        }\n    }\n    int size() const\
    \ {\n        return int(ranges.size());\n    }\n    iterator begin() const {\n\
    \        return ranges.begin();\n    }\n    iterator end() const {\n        return\
    \ ranges.end();\n    }\n\nprivate:\n    std::map<T, T> ranges;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/range_set.hpp
  requiredBy: []
  timestamp: '2026-10-19 20:56:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1601.test.cpp
  - test/aoj/2880.test.cpp
  - test/unit/range_set.test.cpp
documentation_of: datastructure/range_set.hpp
layout: document
title: Range Set
---

### 概要
- 互いに交わらない半開区間の集合。接する区間は 1 つにまとめる。

### 使い方
- `find(p)`: `p` を含む区間のイテレータ。無ければ `end()`。イテレータは `(l, r)` の pair を指す。
- `contains(p)`: `p` を含むか。
- `covers(l, r)`: `[l, r)` が 1 つの区間に含まれるか。
- `mex(x)`: `x` 以上で含まれない最小の値。整数向け。
- `insert(l, r)`: `[l, r)` を追加する。
- `insert(l, r, f, g)`: 追加のとき、新しくできた区間ごとに `f(l, r)` を、消えた区間ごとに `g(l, r)` を呼ぶ。
- `erase(l, r)`: `[l, r)` を削除する。
- `erase(l, r, f, g)`: 削除のとき、新しくできた区間ごとに `f(l, r)` を、消えた区間ごとに `g(l, r)` を呼ぶ。
- `size()`: 区間の個数。
- range-for で区間を昇順に列挙できる。
- 整数の集合として使うときは、整数 `a` 以上 `b` 以下を `[a, b + 1)` で表す。

### 計算量
- `insert`, `erase`: 償却 $\mathcal{O}(\log N)$
- `find`, `contains`, `covers`, `mex`: $\mathcal{O}(\log N)$
