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
  bundledCode: "#line 2 \"algebra/monoid_max_subarray_sum.hpp\"\n#include <algorithm>\n\
    #include <limits>\ntemplate <class T>\nstruct monoid_max_subarray_sum {\n    struct\
    \ S {\n        T sum, max_prefix, max_suffix, max_subarray;\n    };\n    static\
    \ S op(S a, S b) {\n        if (a.max_subarray == ninf) return b;\n        if\
    \ (b.max_subarray == ninf) return a;\n        return {a.sum + b.sum, std::max(a.max_prefix,\
    \ a.sum + b.max_prefix), std::max(b.max_suffix, a.max_suffix + b.sum),\n     \
    \           std::max({a.max_subarray, b.max_subarray, a.max_suffix + b.max_prefix})};\n\
    \    }\n    static S e() {\n        return {T(0), ninf, ninf, ninf};\n    }\n\
    \    static S from(T v) {\n        return {v, v, v, v};\n    }\n\nprivate:\n \
    \   static constexpr T ninf = std::numeric_limits<T>::lowest();\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\ntemplate <class T>\n\
    struct monoid_max_subarray_sum {\n    struct S {\n        T sum, max_prefix, max_suffix,\
    \ max_subarray;\n    };\n    static S op(S a, S b) {\n        if (a.max_subarray\
    \ == ninf) return b;\n        if (b.max_subarray == ninf) return a;\n        return\
    \ {a.sum + b.sum, std::max(a.max_prefix, a.sum + b.max_prefix), std::max(b.max_suffix,\
    \ a.max_suffix + b.sum),\n                std::max({a.max_subarray, b.max_subarray,\
    \ a.max_suffix + b.max_prefix})};\n    }\n    static S e() {\n        return {T(0),\
    \ ninf, ninf, ninf};\n    }\n    static S from(T v) {\n        return {v, v, v,\
    \ v};\n    }\n\nprivate:\n    static constexpr T ninf = std::numeric_limits<T>::lowest();\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_max_subarray_sum.hpp
  requiredBy: []
  timestamp: '2026-10-29 12:41:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/monoid.test.cpp
documentation_of: algebra/monoid_max_subarray_sum.hpp
layout: document
title: 'Monoid: Max Subarray Sum'
---

### 概要
- 空でない連続部分列の和の最大値。`segtree<monoid_max_subarray_sum<T>>` のように使う。

### 使い方
- `S = {T sum, max_prefix, max_suffix, max_subarray}`
- `from(v)`: 値 `v` 1 個分の要素を返す。初期化や一点更新ではこれで `S` を作る。
- `prod(l, r).max_subarray` が `a[l], ..., a[r - 1]` の空でない連続部分列の和の最大値。$l = r$ なら `std::numeric_limits<T>::lowest()`。
