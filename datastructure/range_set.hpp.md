---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/range_map.hpp
    title: Range Map
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
  bundledCode: "#line 2 \"datastructure/range_map.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <map>\n#include <optional>\n#include <vector>\ntemplate\
    \ <typename T, typename U>\nstruct range_map {\npublic:\n    range_map(bool merge_adjacent_segment\
    \ = true)\n        : merge_adjacent_segment(merge_adjacent_segment) {\n    }\n\
    \    void clear() {\n        mp.clear();\n    }\n    size_t size() {\n       \
    \ return mp.size();\n    }\n    std::optional<std::pair<T, T>> contains(T l, T\
    \ r) {\n        assert(l <= r);\n        auto it = mp.upper_bound(l);\n      \
    \  if (it == mp.begin()) return std::nullopt;\n        it--;\n        if (it->first\
    \ > l) return std::nullopt;\n        if (r > it->second.first) return std::nullopt;\n\
    \        return std::make_pair(it->first, it->second.first);\n    }\n    std::optional<std::pair<T,\
    \ T>> contains(T p) {\n        return is_covered(p, p);\n    }\n    void insert(T\
    \ l, T r, U x) {\n        assert(l <= r);\n        auto it_l = mp.upper_bound(l);\n\
    \        auto it_r = mp.upper_bound(r + int(merge_adjacent_segment));\n      \
    \  if (it_l != mp.begin()) {\n            if (std::prev(it_l)->second.first >=\n\
    \                l - int(merge_adjacent_segment)) {\n                it_l--;\n\
    \            }\n        };\n        bool has_value_0 = false, has_value_1 = false;\n\
    \        T l_0, l_1, r_1, r_2;\n        U x_0, x_1, x_2;\n        if (it_l !=\
    \ mp.end()) {\n            has_value_0 = true;\n            l_0 = it_l->first;\n\
    \            x_0 = it_l->second.second;\n        }\n        {\n            l_1\
    \ = l, r_1 = r;\n            x_1 = x;\n        }\n        if (it_r != mp.begin())\
    \ {\n            has_value_1 = true;\n            r_2 = std::prev(it_r)->second.first;\n\
    \            x_2 = std::prev(it_r)->second.second;\n        }\n        for (auto\
    \ it = it_l; it != it_r; it = mp.erase(it)) {\n        }\n        if (has_value_0\
    \ && x_0 == x_1) {\n            l_1 = std::min(l_0, l_1);\n        } else if (has_value_0\
    \ && l_0 < l_1) {\n            mp[l_0] = {l_1 - 1, x_0};\n        }\n        if\
    \ (has_value_1 && x_1 == x_2) {\n            r_1 = std::max(r_1, r_2);\n     \
    \   } else if (has_value_1 && r_1 < r_2) {\n            mp[r_1 + 1] = {r_2, x_2};\n\
    \        }\n        mp[l_1] = {r_1, x_1};\n    }\n    template <class op_erase,\
    \ class op_insert>\n    void insert(T l, T r, U x, const op_erase &f, const op_insert\
    \ &g) {\n        assert(l <= r);\n        auto it_l = mp.upper_bound(l);\n   \
    \     auto it_r = mp.upper_bound(r + int(merge_adjacent_segment));\n        if\
    \ (it_l != mp.begin()) {\n            if (std::prev(it_l)->second.first >=\n \
    \               l - int(merge_adjacent_segment)) {\n                it_l--;\n\
    \            }\n        };\n        bool has_value_0 = false, has_value_1 = false;\n\
    \        T l_0, l_1, r_1, r_2;\n        U x_0, x_1, x_2;\n        if (it_l !=\
    \ mp.end()) {\n            has_value_0 = true;\n            l_0 = it_l->first;\n\
    \            x_0 = it_l->second.second;\n        }\n        {\n            l_1\
    \ = l, r_1 = r;\n            x_1 = x;\n        }\n        if (it_r != mp.begin())\
    \ {\n            has_value_1 = true;\n            r_2 = std::prev(it_r)->second.first;\n\
    \            x_2 = std::prev(it_r)->second.second;\n        }\n        for (auto\
    \ it = it_l; it != it_r; it = mp.erase(it)) {\n            f(it->first, it->second.first,\
    \ it->second.second);\n        }\n        if (has_value_0 && x_0 == x_1) {\n \
    \           l_1 = std::min(l_0, l_1);\n        } else if (has_value_0 && l_0 <\
    \ l_1) {\n            mp[l_0] = {l_1 - 1, x_0};\n            g(l_0, l_1 - 1, x_0);\n\
    \        }\n        if (has_value_1 && x_1 == x_2) {\n            r_1 = std::max(r_1,\
    \ r_2);\n        } else if (has_value_1 && r_1 < r_2) {\n            mp[r_1 +\
    \ 1] = {r_2, x_2};\n            g(r_1 + 1, r_2, x_2);\n        }\n        mp[l_1]\
    \ = {r_1, x_1};\n        g(l_1, r_1, x_1);\n    }\n    void erase(T l, T r) {\n\
    \        assert(l <= r);\n        auto it_l = mp.upper_bound(l);\n        auto\
    \ it_r = mp.upper_bound(r);\n        if (it_l != mp.begin()) {\n            if\
    \ (std::prev(it_l)->second.first >= l) {\n                it_l--;\n          \
    \  }\n        }\n        bool has_value_0 = false, has_value_1 = false;\n    \
    \    T l_0, l_1, r_1, r_2;\n        U x_0, x_2;\n        if (it_l != mp.end())\
    \ {\n            has_value_0 = true;\n            l_0 = it_l->first;\n       \
    \     x_0 = it_l->second.second;\n        }\n        {\n            l_1 = l;\n\
    \            r_1 = r;\n        }\n        if (it_r != mp.begin()) {\n        \
    \    has_value_1 = true;\n            r_2 = std::prev(it_r)->second.first;\n \
    \           x_2 = std::prev(it_r)->second.second;\n        }\n        for (auto\
    \ it = it_l; it != it_r; it = mp.erase(it)) {\n        }\n        if (has_value_0\
    \ && l_0 < l_1) {\n            mp[l_0] = {l_1 - 1, x_0};\n        }\n        if\
    \ (has_value_1 && r_1 < r_2) {\n            mp[r_1 + 1] = {r_2, x_2};\n      \
    \  }\n    }\n    template <class op_erase, class op_insert>\n    void erase(T\
    \ l, T r, const op_erase &f, const op_insert &g) {\n        assert(l <= r);\n\
    \        auto it_l = mp.upper_bound(l);\n        auto it_r = mp.upper_bound(r);\n\
    \        if (it_l != mp.begin()) {\n            if (std::prev(it_l)->second.first\
    \ >= l) {\n                it_l--;\n            }\n        }\n        bool has_value_0\
    \ = false, has_value_1 = false;\n        T l_0, l_1, r_1, r_2;\n        U x_0,\
    \ x_2;\n        if (it_l != mp.end()) {\n            has_value_0 = true;\n   \
    \         l_0 = it_l->first;\n            x_0 = it_l->second.second;\n       \
    \ }\n        {\n            l_1 = l;\n            r_1 = r;\n        }\n      \
    \  if (it_r != mp.begin()) {\n            has_value_1 = true;\n            r_2\
    \ = std::prev(it_r)->second.first;\n            x_2 = std::prev(it_r)->second.second;\n\
    \        }\n        for (auto it = it_l; it != it_r; it = mp.erase(it)) {\n  \
    \          f(it->first, it->second.first, it->second.second);\n        }\n   \
    \     if (has_value_0 && l_0 < l_1) {\n            mp[l_0] = {l_1 - 1, x_0};\n\
    \            g(l_0, l_1 - 1, x_0);\n        }\n        if (has_value_1 && r_1\
    \ < r_2) {\n            mp[r_1 + 1] = {r_2, x_2};\n            g(r_1 + 1, r_2,\
    \ x_2);\n        }\n    }\n    std::vector<std::tuple<T, T, U>> ranges() {\n \
    \       std::vector<std::tuple<T, T, U>> ret;\n        for (auto it = mp.begin();\
    \ it != mp.end(); it++) {\n            ret.emplace_back(it->first, it->second.first,\
    \ it->second.second);\n        }\n        return ret;\n    }\n\nprotected:\n \
    \   bool merge_adjacent_segment;\n    std::map<T, std::pair<T, U>> mp;\n};\n#line\
    \ 3 \"datastructure/range_set.hpp\"\ntemplate <typename T>\nstruct range_set :\
    \ range_map<T, bool> {\n    using Base = range_map<T, bool>;\n    using Base::range_map;\n\
    \    void insert(T l, T r) {\n        Base::insert(l, r, true);\n    }\n    template\
    \ <class op_erase, class op_insert>\n    void insert(T l, T r, const op_erase\
    \ &f, const op_insert &g) {\n        Base::insert(l, r, true, f, g);\n    }\n\
    \    std::vector<std::pair<T, T>> ranges() {\n        std::vector<std::pair<T,\
    \ T>> ret;\n        for (auto it = Base::mp.begin(); it != Base::mp.end(); it++)\
    \ {\n            ret.emplace_back(it->first, it->second.first);\n        }\n \
    \       return ret;\n    }\n};\n"
  code: "#pragma once\n#include \"range_map.hpp\"\ntemplate <typename T>\nstruct range_set\
    \ : range_map<T, bool> {\n    using Base = range_map<T, bool>;\n    using Base::range_map;\n\
    \    void insert(T l, T r) {\n        Base::insert(l, r, true);\n    }\n    template\
    \ <class op_erase, class op_insert>\n    void insert(T l, T r, const op_erase\
    \ &f, const op_insert &g) {\n        Base::insert(l, r, true, f, g);\n    }\n\
    \    std::vector<std::pair<T, T>> ranges() {\n        std::vector<std::pair<T,\
    \ T>> ret;\n        for (auto it = Base::mp.begin(); it != Base::mp.end(); it++)\
    \ {\n            ret.emplace_back(it->first, it->second.first);\n        }\n \
    \       return ret;\n    }\n};"
  dependsOn:
  - datastructure/range_map.hpp
  isVerificationFile: false
  path: datastructure/range_set.hpp
  requiredBy: []
  timestamp: '2023-01-19 19:46:21+09:00'
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