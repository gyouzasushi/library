---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/quotient_blocks.test.cpp
    title: test/unit/quotient_blocks.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/quotient_blocks.hpp\"\n#include <cassert>\n#include\
    \ <vector>\nstruct quotient_block {\n    long long l, r, q;\n};\nstd::vector<quotient_block>\
    \ quotient_blocks(long long n) {\n    assert(n >= 0);\n    std::vector<quotient_block>\
    \ ret;\n    for (long long l = 1; l <= n;) {\n        long long q = n / l, r =\
    \ n / q + 1;\n        ret.push_back({l, r, q});\n        l = r;\n    }\n    return\
    \ ret;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nstruct quotient_block\
    \ {\n    long long l, r, q;\n};\nstd::vector<quotient_block> quotient_blocks(long\
    \ long n) {\n    assert(n >= 0);\n    std::vector<quotient_block> ret;\n    for\
    \ (long long l = 1; l <= n;) {\n        long long q = n / l, r = n / q + 1;\n\
    \        ret.push_back({l, r, q});\n        l = r;\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/quotient_blocks.hpp
  requiredBy: []
  timestamp: '2026-10-27 12:15:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/quotient_blocks.test.cpp
documentation_of: math/quotient_blocks.hpp
layout: document
title: Quotient Blocks
---

### 概要
- $\lfloor n / i \rfloor$ が等しい $i$ の区間に $[1, n]$ を分ける。

### 使い方
- `quotient_blocks(n)`: $i \in [l, r)$ で $\lfloor n / i \rfloor = q$ となる `{l, r, q}` の列を `l` の昇順で返す。

### 制約
- $0 \le n$

### 計算量
- $\mathcal{O}(\sqrt{n})$
