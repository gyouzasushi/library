---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/monoid.test.cpp
    title: test/unit/monoid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/range_assign_range_min.hpp\"\n#include <limits>\n\
    #include <optional>\ntemplate <class T>\nstruct range_assign_range_min {\n   \
    \ using S = T;\n    using F = std::optional<T>;\n    static S op(S a, S b) {\n\
    \        return a < b ? a : b;\n    }\n    static S e() {\n        return std::numeric_limits<T>::max();\n\
    \    }\n    static S mapping(F f, S x) {\n        return f ? *f : x;\n    }\n\
    \    static F composition(F f, F g) {\n        return f ? f : g;\n    }\n    static\
    \ F id() {\n        return std::nullopt;\n    }\n    static constexpr bool composition_commutative\
    \ = false;\n};\n"
  code: "#pragma once\n#include <limits>\n#include <optional>\ntemplate <class T>\n\
    struct range_assign_range_min {\n    using S = T;\n    using F = std::optional<T>;\n\
    \    static S op(S a, S b) {\n        return a < b ? a : b;\n    }\n    static\
    \ S e() {\n        return std::numeric_limits<T>::max();\n    }\n    static S\
    \ mapping(F f, S x) {\n        return f ? *f : x;\n    }\n    static F composition(F\
    \ f, F g) {\n        return f ? f : g;\n    }\n    static F id() {\n        return\
    \ std::nullopt;\n    }\n    static constexpr bool composition_commutative = false;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/range_assign_range_min.hpp
  requiredBy: []
  timestamp: '2026-10-28 19:31:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/monoid.test.cpp
documentation_of: algebra/range_assign_range_min.hpp
layout: document
title: 'Acted Monoid: Range Assign Range Min'
---

### 概要
- 区間代入・区間最小値。`lazy_segtree<range_assign_range_min<T>>` のように使う。

### 使い方
- `S = T`, `F = std::optional<T>`
- `e()` は `std::numeric_limits<T>::max()`。
- `apply(l, r, v)` で `a[l], ..., a[r - 1]` を `v` にする。
