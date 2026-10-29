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
  bundledCode: "#line 2 \"algebra/monoid_longest_run.hpp\"\n#include <algorithm>\n\
    template <class T>\nstruct monoid_longest_run {\n    struct S {\n        int len;\n\
    \        T left, right;\n        int left_run, right_run, longest;\n    };\n \
    \   static S op(S a, S b) {\n        if (a.len == 0) return b;\n        if (b.len\
    \ == 0) return a;\n        S c = {a.len + b.len, a.left, b.right, a.left_run,\
    \ b.right_run, std::max(a.longest, b.longest)};\n        if (a.right == b.left)\
    \ {\n            c.longest = std::max(c.longest, a.right_run + b.left_run);\n\
    \            if (a.left_run == a.len) c.left_run = a.len + b.left_run;\n     \
    \       if (b.right_run == b.len) c.right_run = a.right_run + b.len;\n       \
    \ }\n        return c;\n    }\n    static S e() {\n        return {0, T(), T(),\
    \ 0, 0, 0};\n    }\n    static S from(T c) {\n        return {1, c, c, 1, 1, 1};\n\
    \    }\n};\n"
  code: "#pragma once\n#include <algorithm>\ntemplate <class T>\nstruct monoid_longest_run\
    \ {\n    struct S {\n        int len;\n        T left, right;\n        int left_run,\
    \ right_run, longest;\n    };\n    static S op(S a, S b) {\n        if (a.len\
    \ == 0) return b;\n        if (b.len == 0) return a;\n        S c = {a.len + b.len,\
    \ a.left, b.right, a.left_run, b.right_run, std::max(a.longest, b.longest)};\n\
    \        if (a.right == b.left) {\n            c.longest = std::max(c.longest,\
    \ a.right_run + b.left_run);\n            if (a.left_run == a.len) c.left_run\
    \ = a.len + b.left_run;\n            if (b.right_run == b.len) c.right_run = a.right_run\
    \ + b.len;\n        }\n        return c;\n    }\n    static S e() {\n        return\
    \ {0, T(), T(), 0, 0, 0};\n    }\n    static S from(T c) {\n        return {1,\
    \ c, c, 1, 1, 1};\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_longest_run.hpp
  requiredBy: []
  timestamp: '2026-10-29 12:41:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/monoid.test.cpp
documentation_of: algebra/monoid_longest_run.hpp
layout: document
title: 'Monoid: Longest Run'
---

### 概要
- 同じ値が連続する最長の長さ。`segtree<monoid_longest_run<T>>` のように使う。

### 使い方
- `S = {int len; T left, right; int left_run, right_run, longest}`
- `from(c)`: 値 `c` 1 個分の要素を返す。初期化や一点更新ではこれで `S` を作る。
- `prod(l, r).longest` が `a[l], ..., a[r - 1]` で同じ値が連続する最長の長さ。
