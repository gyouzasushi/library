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
  bundledCode: "#line 2 \"algebra/range_assign_range_sum.hpp\"\n#include <optional>\n\
    template <class T>\nstruct range_assign_range_sum {\n    struct S {\n        T\
    \ sum;\n        int len;\n    };\n    using F = std::optional<T>;\n    static\
    \ S op(S a, S b) {\n        return {a.sum + b.sum, a.len + b.len};\n    }\n  \
    \  static S e() {\n        return {T(0), 0};\n    }\n    static S mapping(F f,\
    \ S x) {\n        return f ? S{*f * x.len, x.len} : x;\n    }\n    static F composition(F\
    \ f, F g) {\n        return f ? f : g;\n    }\n    static F id() {\n        return\
    \ std::nullopt;\n    }\n    static constexpr bool composition_commutative = false;\n\
    \    static S from(T v) {\n        return {v, 1};\n    }\n};\n"
  code: "#pragma once\n#include <optional>\ntemplate <class T>\nstruct range_assign_range_sum\
    \ {\n    struct S {\n        T sum;\n        int len;\n    };\n    using F = std::optional<T>;\n\
    \    static S op(S a, S b) {\n        return {a.sum + b.sum, a.len + b.len};\n\
    \    }\n    static S e() {\n        return {T(0), 0};\n    }\n    static S mapping(F\
    \ f, S x) {\n        return f ? S{*f * x.len, x.len} : x;\n    }\n    static F\
    \ composition(F f, F g) {\n        return f ? f : g;\n    }\n    static F id()\
    \ {\n        return std::nullopt;\n    }\n    static constexpr bool composition_commutative\
    \ = false;\n    static S from(T v) {\n        return {v, 1};\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/range_assign_range_sum.hpp
  requiredBy: []
  timestamp: '2026-10-28 19:31:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/monoid.test.cpp
documentation_of: algebra/range_assign_range_sum.hpp
layout: document
title: 'Acted Monoid: Range Assign Range Sum'
---

### 概要
- 区間代入・区間和。`lazy_segtree<range_assign_range_sum<T>>` のように使う。

### 使い方
- `S = {T sum; int len}`, `F = std::optional<T>`
- `from(v)`: 値 `v` 1 個分の要素 `{v, 1}` を返す。初期化や一点更新ではこれで `S` を作る。
- `apply(l, r, v)` で `a[l], ..., a[r - 1]` を `v` にする。
- `prod(l, r).sum` が区間和。
