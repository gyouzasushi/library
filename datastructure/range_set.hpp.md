---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1601.test.cpp
    title: test/yukicoder/1601.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/range_set.hpp\"\n#include <cassert>\n#include\
    \ <map>\ntemplate <typename T>\nstruct range_set {\npublic:\n    range_set(bool\
    \ merge_adjacent_segment = true)\n        : merge_adjacent_segment(merge_adjacent_segment)\
    \ {\n    }\n    void clear() {\n        mp.clear();\n    }\n    size_t size()\
    \ {\n        return mp.size();\n    }\n    bool is_covered(T l, T r) {\n     \
    \   assert(l <= r);\n        auto it = mp.upper_bound(l);\n        return it !=\
    \ mp.begin() && std::prev(it)->first <= l &&\n               r <= std::prev(it)->second;\n\
    \    }\n    bool is_covered(T p) {\n        return is_covered(p, p);\n    }\n\
    \    auto covered_by(T l, T r) {\n        assert(l <= r);\n        assert(is_covered(l,\
    \ r));\n        return std::prev(mp.upper_bound(l));\n    }\n    auto covered_by(T\
    \ p) {\n        return covered_by(p, p);\n    }\n    void insert(T l, T r) {\n\
    \        assert(l <= r);\n        auto it_l = mp.upper_bound(l);\n        auto\
    \ it_r = mp.upper_bound(r + int(merge_adjacent_segment));\n        if (it_l !=\
    \ mp.begin()) {\n            if (std::prev(it_l)->second >= l - int(merge_adjacent_segment))\
    \ {\n                it_l--;\n            }\n        }\n        for (auto it =\
    \ it_l; it != it_r; it = mp.erase(it)) {\n            l = std::min(l, it->first);\n\
    \            r = std::max(r, it->second);\n        }\n        mp[l] = r;\n   \
    \ }\n    void erase(T l, T r) {\n        assert(l <= r);\n        auto it_l =\
    \ mp.upper_bound(l);\n        auto it_r = mp.upper_bound(r + int(merge_adjacent_segment));\n\
    \        if (it_l != mp.begin()) {\n            if (std::prev(it_l)->second >=\
    \ l) {\n                it_l--;\n            }\n        }\n        int nl = std::min(l,\
    \ it_l->first);\n        int nr = std::max(r, std::prev(it_r)->second);\n    \
    \    mp.erase(it_l, it_r);\n        if (nl < l) mp[nl] = l - 1;\n        if (r\
    \ < nr) mp[r + 1] = nr;\n    }\n\nprivate:\n    bool merge_adjacent_segment;\n\
    \    std::map<T, T> mp;\n};\n"
  code: "#include <cassert>\n#include <map>\ntemplate <typename T>\nstruct range_set\
    \ {\npublic:\n    range_set(bool merge_adjacent_segment = true)\n        : merge_adjacent_segment(merge_adjacent_segment)\
    \ {\n    }\n    void clear() {\n        mp.clear();\n    }\n    size_t size()\
    \ {\n        return mp.size();\n    }\n    bool is_covered(T l, T r) {\n     \
    \   assert(l <= r);\n        auto it = mp.upper_bound(l);\n        return it !=\
    \ mp.begin() && std::prev(it)->first <= l &&\n               r <= std::prev(it)->second;\n\
    \    }\n    bool is_covered(T p) {\n        return is_covered(p, p);\n    }\n\
    \    auto covered_by(T l, T r) {\n        assert(l <= r);\n        assert(is_covered(l,\
    \ r));\n        return std::prev(mp.upper_bound(l));\n    }\n    auto covered_by(T\
    \ p) {\n        return covered_by(p, p);\n    }\n    void insert(T l, T r) {\n\
    \        assert(l <= r);\n        auto it_l = mp.upper_bound(l);\n        auto\
    \ it_r = mp.upper_bound(r + int(merge_adjacent_segment));\n        if (it_l !=\
    \ mp.begin()) {\n            if (std::prev(it_l)->second >= l - int(merge_adjacent_segment))\
    \ {\n                it_l--;\n            }\n        }\n        for (auto it =\
    \ it_l; it != it_r; it = mp.erase(it)) {\n            l = std::min(l, it->first);\n\
    \            r = std::max(r, it->second);\n        }\n        mp[l] = r;\n   \
    \ }\n    void erase(T l, T r) {\n        assert(l <= r);\n        auto it_l =\
    \ mp.upper_bound(l);\n        auto it_r = mp.upper_bound(r + int(merge_adjacent_segment));\n\
    \        if (it_l != mp.begin()) {\n            if (std::prev(it_l)->second >=\
    \ l) {\n                it_l--;\n            }\n        }\n        int nl = std::min(l,\
    \ it_l->first);\n        int nr = std::max(r, std::prev(it_r)->second);\n    \
    \    mp.erase(it_l, it_r);\n        if (nl < l) mp[nl] = l - 1;\n        if (r\
    \ < nr) mp[r + 1] = nr;\n    }\n\nprivate:\n    bool merge_adjacent_segment;\n\
    \    std::map<T, T> mp;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/range_set.hpp
  requiredBy: []
  timestamp: '2023-01-18 21:17:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1601.test.cpp
documentation_of: datastructure/range_set.hpp
layout: document
redirect_from:
- /library/datastructure/range_set.hpp
- /library/datastructure/range_set.hpp.html
title: datastructure/range_set.hpp
---
