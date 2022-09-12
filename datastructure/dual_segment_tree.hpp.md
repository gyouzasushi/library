---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.test.cpp
    title: test/aoj/DSL_2_D.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_E.test.cpp
    title: test/aoj/DSL_2_E.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/dual_segment_tree.hpp\"\n#include <vector>\n\
    template <class F, F (*composition)(F, F), F (*id)()>\nstruct DualSegmentTree\
    \ {\npublic:\n    DualSegmentTree() {\n    }\n    DualSegmentTree(int n, bool\
    \ is_commutative = false)\n        : is_commutative(is_commutative) {\n      \
    \  size = 1;\n        height = 0;\n        while (size < n) size <<= 1, height++;\n\
    \        lz.assign(2 * size, id());\n    }\n    void apply(int l, int r, const\
    \ F &x) {\n        l += size;\n        r += size - 1;\n        if (!is_commutative)\
    \ thrust(l);\n        if (!is_commutative) thrust(r);\n        r++;\n        while\
    \ (l < r) {\n            if (l & 1) lz[l] = composition(lz[l], x), ++l;\n    \
    \        if (r & 1) --r, lz[r] = composition(lz[r], x);\n            l >>= 1,\
    \ r >>= 1;\n        }\n    }\n    F get(int p) {\n        if (is_commutative)\
    \ {\n            F ret = id();\n            p += size;\n            while (p >\
    \ 0) {\n                ret = composition(ret, lz[p]);\n                p >>=\
    \ 1;\n            }\n            return ret;\n        } else {\n            thrust(p\
    \ += size);\n            return lz[p];\n        }\n    }\n\nprivate:\n    int\
    \ size, height;\n    std::vector<F> lz;\n    bool is_commutative;\n    inline\
    \ void propagate(int k) {\n        if (lz[k] != id()) {\n            lz[2 * k\
    \ + 0] = composition(lz[2 * k + 0], lz[k]);\n            lz[2 * k + 1] = composition(lz[2\
    \ * k + 1], lz[k]);\n            lz[k] = id();\n        }\n    }\n    inline void\
    \ thrust(int k) {\n        for (int i = height; i > 0; i--) propagate(k >> i);\n\
    \    }\n};\n"
  code: "#include <vector>\ntemplate <class F, F (*composition)(F, F), F (*id)()>\n\
    struct DualSegmentTree {\npublic:\n    DualSegmentTree() {\n    }\n    DualSegmentTree(int\
    \ n, bool is_commutative = false)\n        : is_commutative(is_commutative) {\n\
    \        size = 1;\n        height = 0;\n        while (size < n) size <<= 1,\
    \ height++;\n        lz.assign(2 * size, id());\n    }\n    void apply(int l,\
    \ int r, const F &x) {\n        l += size;\n        r += size - 1;\n        if\
    \ (!is_commutative) thrust(l);\n        if (!is_commutative) thrust(r);\n    \
    \    r++;\n        while (l < r) {\n            if (l & 1) lz[l] = composition(lz[l],\
    \ x), ++l;\n            if (r & 1) --r, lz[r] = composition(lz[r], x);\n     \
    \       l >>= 1, r >>= 1;\n        }\n    }\n    F get(int p) {\n        if (is_commutative)\
    \ {\n            F ret = id();\n            p += size;\n            while (p >\
    \ 0) {\n                ret = composition(ret, lz[p]);\n                p >>=\
    \ 1;\n            }\n            return ret;\n        } else {\n            thrust(p\
    \ += size);\n            return lz[p];\n        }\n    }\n\nprivate:\n    int\
    \ size, height;\n    std::vector<F> lz;\n    bool is_commutative;\n    inline\
    \ void propagate(int k) {\n        if (lz[k] != id()) {\n            lz[2 * k\
    \ + 0] = composition(lz[2 * k + 0], lz[k]);\n            lz[2 * k + 1] = composition(lz[2\
    \ * k + 1], lz[k]);\n            lz[k] = id();\n        }\n    }\n    inline void\
    \ thrust(int k) {\n        for (int i = height; i > 0; i--) propagate(k >> i);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/dual_segment_tree.hpp
  requiredBy: []
  timestamp: '2022-09-12 16:35:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DSL_2_E.test.cpp
  - test/aoj/DSL_2_D.test.cpp
documentation_of: datastructure/dual_segment_tree.hpp
layout: document
title: Dual Segment Tree
---

### 概要
- 区間更新・一点取得ができるデータ構造。

### 使い方
- `DualSegmentTree<F, composition, id>(n, is_commutative = false)`: 長さ `n` の数列 `a` を作る。`F` は作用の型。`composition` は $\cdot : F \times F \rightarrow F$ を計算する関数。`id` は $id$ を返す関数。$\cdot$ が可換である場合は `commutative = true` にするとよい。
- `apply(l, r, x)`: `a_l, ..., a_r` に `x` を作用させる。
- `get(p)`: `a_p` を求める。