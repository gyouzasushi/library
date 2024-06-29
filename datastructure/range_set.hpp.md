---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2880.test.cpp
    title: test/aoj/2880.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1601.test.cpp
    title: test/yukicoder/1601.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/range_set.hpp\"\n\n#include <map>\ntemplate\
    \ <typename T>\nstruct range_set {\npublic:\n    range_set(bool merge_adjacent\
    \ = true) : _merge_adjacent(merge_adjacent) {\n    }\n    typename std::map<T,\
    \ T>::const_iterator get(T p) const {\n        auto it = ranges.upper_bound(p);\n\
    \        if (it == ranges.begin()) return ranges.end();\n        if (std::prev(it)->second\
    \ < p) return ranges.end();\n        return std::prev(it);\n    }\n    typename\
    \ std::map<T, T>::const_iterator get(T l, T r) const {\n        auto it = get(l);\n\
    \        if (it == ranges.end()) return ranges.end();\n        if (it->second\
    \ < r) return ranges.end();\n        return it;\n    }\n    void insert(T l, T\
    \ r) {\n        insert(l, r, [](T, T) {}, [](T, T) {});\n    }\n    template <class\
    \ op_insert, class op_erase>\n    void insert(T l, T r, const op_insert &f, const\
    \ op_erase &g) {\n        auto it_l = ranges.upper_bound(l);\n        auto it_r\
    \ = ranges.upper_bound(r + T(_merge_adjacent));\n        if (it_l != ranges.begin()\
    \ &&\n            l - T(_merge_adjacent) <= std::prev(it_l)->second) {\n     \
    \       it_l--;\n        }\n        for (auto it = it_l; it != it_r; it = ranges.erase(it))\
    \ {\n            l = std::min(l, it->first);\n            r = std::max(r, it->second);\n\
    \            g(it->first, it->second);\n        }\n        ranges[l] = r;\n  \
    \      f(l, r);\n    }\n    void erase(T l, T r) {\n        erase(l, r, [](T,\
    \ T) {}, [](T, T) {});\n    }\n    template <class op_insert, class op_erase>\n\
    \    void erase(T l, T r, const op_insert &f, const op_erase &g) {\n        auto\
    \ it_l = ranges.upper_bound(l);\n        auto it_r = ranges.upper_bound(r);\n\
    \        if (it_l != ranges.begin() && l <= std::prev(it_l)->second) {\n     \
    \       it_l--;\n        }\n        T nl = std::min(l, it_l->first);\n       \
    \ T nr = std::max(r, std::prev(it_r)->second);\n        for (auto it = it_l; it\
    \ != it_r; it = ranges.erase(it)) {\n            g(it->first, it->second);\n \
    \       }\n        if (nl < l) {\n            ranges[nl] = l - 1;\n          \
    \  f(nl, l - 1);\n        }\n        if (r < nr) {\n            ranges[r + 1]\
    \ = nr;\n            f(r + 1, nr);\n        }\n    }\n    typename std::map<T,\
    \ T>::const_iterator begin() const {\n        return ranges.begin();\n    }\n\
    \    typename std::map<T, T>::const_iterator end() const {\n        return ranges.end();\n\
    \    }\n\nprivate:\n    std::map<T, T> ranges;\n    bool _merge_adjacent;\n};\n"
  code: "#pragma once\n\n#include <map>\ntemplate <typename T>\nstruct range_set {\n\
    public:\n    range_set(bool merge_adjacent = true) : _merge_adjacent(merge_adjacent)\
    \ {\n    }\n    typename std::map<T, T>::const_iterator get(T p) const {\n   \
    \     auto it = ranges.upper_bound(p);\n        if (it == ranges.begin()) return\
    \ ranges.end();\n        if (std::prev(it)->second < p) return ranges.end();\n\
    \        return std::prev(it);\n    }\n    typename std::map<T, T>::const_iterator\
    \ get(T l, T r) const {\n        auto it = get(l);\n        if (it == ranges.end())\
    \ return ranges.end();\n        if (it->second < r) return ranges.end();\n   \
    \     return it;\n    }\n    void insert(T l, T r) {\n        insert(l, r, [](T,\
    \ T) {}, [](T, T) {});\n    }\n    template <class op_insert, class op_erase>\n\
    \    void insert(T l, T r, const op_insert &f, const op_erase &g) {\n        auto\
    \ it_l = ranges.upper_bound(l);\n        auto it_r = ranges.upper_bound(r + T(_merge_adjacent));\n\
    \        if (it_l != ranges.begin() &&\n            l - T(_merge_adjacent) <=\
    \ std::prev(it_l)->second) {\n            it_l--;\n        }\n        for (auto\
    \ it = it_l; it != it_r; it = ranges.erase(it)) {\n            l = std::min(l,\
    \ it->first);\n            r = std::max(r, it->second);\n            g(it->first,\
    \ it->second);\n        }\n        ranges[l] = r;\n        f(l, r);\n    }\n \
    \   void erase(T l, T r) {\n        erase(l, r, [](T, T) {}, [](T, T) {});\n \
    \   }\n    template <class op_insert, class op_erase>\n    void erase(T l, T r,\
    \ const op_insert &f, const op_erase &g) {\n        auto it_l = ranges.upper_bound(l);\n\
    \        auto it_r = ranges.upper_bound(r);\n        if (it_l != ranges.begin()\
    \ && l <= std::prev(it_l)->second) {\n            it_l--;\n        }\n       \
    \ T nl = std::min(l, it_l->first);\n        T nr = std::max(r, std::prev(it_r)->second);\n\
    \        for (auto it = it_l; it != it_r; it = ranges.erase(it)) {\n         \
    \   g(it->first, it->second);\n        }\n        if (nl < l) {\n            ranges[nl]\
    \ = l - 1;\n            f(nl, l - 1);\n        }\n        if (r < nr) {\n    \
    \        ranges[r + 1] = nr;\n            f(r + 1, nr);\n        }\n    }\n  \
    \  typename std::map<T, T>::const_iterator begin() const {\n        return ranges.begin();\n\
    \    }\n    typename std::map<T, T>::const_iterator end() const {\n        return\
    \ ranges.end();\n    }\n\nprivate:\n    std::map<T, T> ranges;\n    bool _merge_adjacent;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/range_set.hpp
  requiredBy: []
  timestamp: '2024-06-06 13:54:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1601.test.cpp
  - test/aoj/2880.test.cpp
documentation_of: datastructure/range_set.hpp
layout: document
title: Range Set
---

### 概要
- 区間を set で管理するテクニック。
- `range_map<T, bool>` と同じことです。
- すべて閉区間。
  
### 使い方
- `range_set(merge_adjacent_segment = true)`: コンストラクタ。区間 `[l, m]` と `[m + 1, r]` を `[l, r]` にマージしない場合は、`merge_adjacent_segment` を `false` にする。
- `insert(l, r)`: 区間 `[l, r]` を挿入。
- `insert(l, r, f, g)`: 区間 `[l, r]` を挿入。そのとき、区間が削除されるたびに `f` を、区間が追加されるたびに `g` を実行する。`f`, `g` はともに `(T l, T r) -> void`。
- `erase(l, r)`: 区間 `[l, r]` を削除。
- `erase(l, r, f, g)`: 区間 `[l, r]` を削除。そのとき、区間が削除されるたびに `f` を、区間が追加されるたびに `g` を実行する。`f`, `g` はともに `(T l, T r) -> void`。
- `contains(l, r)`: `[l, r]` を完全に覆う区間がある場合、それを返す。
- `ranges()`: すべての区間 `[l, r]` を列挙する。