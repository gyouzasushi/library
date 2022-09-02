---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/staticrmq.test.cpp
    title: test/library-checker/staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/sparse_table.hpp\"\n#include <cassert>\n#include\
    \ <vector>\ntemplate <class S, S (*op)(S, S)>\nstruct SparseTable {\npublic:\n\
    \    SparseTable() {\n    }\n    SparseTable(const std::vector<S>& v)\n      \
    \  : _n(int(v.size())), d(_n), ceil_log2(_n + 1) {\n        ceil_log2[0] = 0;\n\
    \        ceil_log2[1] = 0;\n        for (int i = 2; i <= _n; i++) ceil_log2[i]\
    \ = ceil_log2[i >> 1] + 1;\n        for (int i = 0; i < _n; i++) {\n         \
    \   d[i].resize(ceil_log2[_n] + 1);\n            d[i][0] = v[i];\n        }\n\
    \        for (int b = 0; b < ceil_log2[_n]; b++) {\n            for (int i = 0;\
    \ i < _n; i++) {\n                if (i + (1 << (b + 1)) > _n) break;\n      \
    \          d[i][b + 1] = op(d[i][b], d[i + (1 << b)][b]);\n            }\n   \
    \     }\n    }\n    S prod(int l, int r) {\n        assert(r - l > 0);\n     \
    \   int b = ceil_log2[r - l];\n        return op(d[l][b], d[r - (1 << b)][b]);\n\
    \    }\n\nprivate:\n    int _n;\n    std::vector<std::vector<S>> d;\n    std::vector<int>\
    \ ceil_log2;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\ntemplate <class S, S\
    \ (*op)(S, S)>\nstruct SparseTable {\npublic:\n    SparseTable() {\n    }\n  \
    \  SparseTable(const std::vector<S>& v)\n        : _n(int(v.size())), d(_n), ceil_log2(_n\
    \ + 1) {\n        ceil_log2[0] = 0;\n        ceil_log2[1] = 0;\n        for (int\
    \ i = 2; i <= _n; i++) ceil_log2[i] = ceil_log2[i >> 1] + 1;\n        for (int\
    \ i = 0; i < _n; i++) {\n            d[i].resize(ceil_log2[_n] + 1);\n       \
    \     d[i][0] = v[i];\n        }\n        for (int b = 0; b < ceil_log2[_n]; b++)\
    \ {\n            for (int i = 0; i < _n; i++) {\n                if (i + (1 <<\
    \ (b + 1)) > _n) break;\n                d[i][b + 1] = op(d[i][b], d[i + (1 <<\
    \ b)][b]);\n            }\n        }\n    }\n    S prod(int l, int r) {\n    \
    \    assert(r - l > 0);\n        int b = ceil_log2[r - l];\n        return op(d[l][b],\
    \ d[r - (1 << b)][b]);\n    }\n\nprivate:\n    int _n;\n    std::vector<std::vector<S>>\
    \ d;\n    std::vector<int> ceil_log2;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/sparse_table.hpp
  requiredBy: []
  timestamp: '2022-09-02 15:22:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/staticrmq.test.cpp
documentation_of: datastructure/sparse_table.hpp
layout: document
title: Sparse Table
---

### 概要
演算が冪等な半群に対する区間クエリを高速に処理する。
### 使い方
- `SparseTable<S, op>(v)`: 半群 `(S, op)`、配列 `v` で初期化する。`op` は冪等な演算である必要がある($\min / \max$, $\gcd / \mathrm{lcm}$, $\mathrm{and} / \mathrm{or}$ など)。
- `prod(l, r)`: $\mathrm{op} (\mathrm{op} (\cdots \mathrm{op} (\mathrm{v}_{l}, \mathrm{v}_{l+1}),\cdots ), \mathrm{v}_{r-1})$ を求める。
  
### 計算量
- 構築: $\mathcal O(N \log N)$
- クエリ: $\mathcal O(1)$