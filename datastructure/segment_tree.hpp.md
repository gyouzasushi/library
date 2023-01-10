---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/manhattan_mst.hpp
    title: Manhattan MST
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/manhattanmst.test.cpp
    title: test/library-checker/manhattanmst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/point_set_range_composite.test.cpp
    title: test/library-checker/point_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/segment_tree.hpp\"\n#include <cassert>\n#include\
    \ <vector>\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct SegmentTree {\n\
    public:\n    SegmentTree() : SegmentTree(0) {\n    }\n    SegmentTree(int n) :\
    \ SegmentTree(std::vector<S>(n, e())) {\n    }\n    SegmentTree(const std::vector<S>&\
    \ v) : _n(int(v.size())) {\n        log = ceil_pow2(_n);\n        size = 1 <<\
    \ log;\n        d = std::vector<S>(2 * size, e());\n        for (int i = 0; i\
    \ < _n; i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1; i--)\
    \ {\n            update(i);\n        }\n    }\n\n    void set(int p, S x) {\n\
    \        assert(0 <= p && p < _n);\n        p += size;\n        d[p] = x;\n  \
    \      for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int\
    \ p) {\n        assert(0 <= p && p < _n);\n        return d[p + size];\n    }\n\
    \n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n \
    \       S sml = e(), smr = e();\n        l += size;\n        r += size;\n\n  \
    \      while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n      \
    \      if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n            r\
    \ >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S all_prod() {\n\
    \        return d[1];\n    }\n\n    template <bool (*f)(S)>\n    int max_right(int\
    \ l) {\n        return max_right(l, [](S x) { return f(x); });\n    }\n    template\
    \ <class F>\n    int max_right(int l, F f) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(f(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n\
    \            if (!f(op(sm, d[l]))) {\n                while (l < size) {\n   \
    \                 l = (2 * l);\n                    if (f(op(sm, d[l]))) {\n \
    \                       sm = op(sm, d[l]);\n                        l++;\n   \
    \                 }\n                }\n                return l - size;\n   \
    \         }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*f)(S)>\n\
    \    int min_left(int r) {\n        return min_left(r, [](S x) { return f(x);\
    \ });\n    }\n    template <class F>\n    int min_left(int r, F f) {\n       \
    \ assert(0 <= r && r <= _n);\n        assert(f(e()));\n        if (r == 0) return\
    \ 0;\n        r += size;\n        S sm = e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm)))\
    \ {\n                while (r < size) {\n                    r = (2 * r + 1);\n\
    \                    if (f(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\nprivate:\n\
    \    int _n, size, log;\n    std::vector<S> d;\n    int ceil_pow2(int n) {\n \
    \       int x = 0;\n        while ((1U << x) < (unsigned int)(n)) x++;\n     \
    \   return x;\n    }\n    void update(int k) {\n        d[k] = op(d[2 * k], d[2\
    \ * k + 1]);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\ntemplate <class S, S\
    \ (*op)(S, S), S (*e)()>\nstruct SegmentTree {\npublic:\n    SegmentTree() : SegmentTree(0)\
    \ {\n    }\n    SegmentTree(int n) : SegmentTree(std::vector<S>(n, e())) {\n \
    \   }\n    SegmentTree(const std::vector<S>& v) : _n(int(v.size())) {\n      \
    \  log = ceil_pow2(_n);\n        size = 1 << log;\n        d = std::vector<S>(2\
    \ * size, e());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n  \
    \      for (int i = size - 1; i >= 1; i--) {\n            update(i);\n       \
    \ }\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n\
    \        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n\
    \        return d[p + size];\n    }\n\n    S prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n\
    \        r += size;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S\
    \ all_prod() {\n        return d[1];\n    }\n\n    template <bool (*f)(S)>\n \
    \   int max_right(int l) {\n        return max_right(l, [](S x) { return f(x);\
    \ });\n    }\n    template <class F>\n    int max_right(int l, F f) {\n      \
    \  assert(0 <= l && l <= _n);\n        assert(f(e()));\n        if (l == _n) return\
    \ _n;\n        l += size;\n        S sm = e();\n        do {\n            while\
    \ (l % 2 == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n               \
    \ while (l < size) {\n                    l = (2 * l);\n                    if\
    \ (f(op(sm, d[l]))) {\n                        sm = op(sm, d[l]);\n          \
    \              l++;\n                    }\n                }\n              \
    \  return l - size;\n            }\n            sm = op(sm, d[l]);\n         \
    \   l++;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\n    template\
    \ <bool (*f)(S)>\n    int min_left(int r) {\n        return min_left(r, [](S x)\
    \ { return f(x); });\n    }\n    template <class F>\n    int min_left(int r, F\
    \ f) {\n        assert(0 <= r && r <= _n);\n        assert(f(e()));\n        if\
    \ (r == 0) return 0;\n        r += size;\n        S sm = e();\n        do {\n\
    \            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n           \
    \ if (!f(op(d[r], sm))) {\n                while (r < size) {\n              \
    \      r = (2 * r + 1);\n                    if (f(op(d[r], sm))) {\n        \
    \                sm = op(d[r], sm);\n                        r--;\n          \
    \          }\n                }\n                return r + 1 - size;\n      \
    \      }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n \
    \       return 0;\n    }\n\nprivate:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    int ceil_pow2(int n) {\n        int x = 0;\n        while ((1U << x)\
    \ < (unsigned int)(n)) x++;\n        return x;\n    }\n    void update(int k)\
    \ {\n        d[k] = op(d[2 * k], d[2 * k + 1]);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/segment_tree.hpp
  requiredBy:
  - graph/manhattan_mst.hpp
  timestamp: '2022-09-10 18:25:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_A.test.cpp
  - test/aoj/DSL_2_B.test.cpp
  - test/library-checker/point_set_range_composite.test.cpp
  - test/library-checker/manhattanmst.test.cpp
documentation_of: datastructure/segment_tree.hpp
layout: document
title: Segment Tree
---

### 概要
- ACL の Segtree。
  
### 使い方
- [ACL のドキュメント](https://atcoder.github.io/ac-library/production/document_ja/segtree.html)を参照。