---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/range_affine_point_get.test.cpp
    title: test/library-checker/range_affine_point_get.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/dual_segtree.hpp\"\n#include <vector>\ntemplate\
    \ <class F, F (*composition)(F, F), F (*id)()>\nstruct dual_segtree {\npublic:\n\
    \    dual_segtree() {\n    }\n    dual_segtree(int n, bool is_commutative = false)\n\
    \        : is_commutative(is_commutative) {\n        size = 1;\n        height\
    \ = 0;\n        while (size < n) size <<= 1, height++;\n        lz.assign(2 *\
    \ size, id());\n    }\n    void apply(int l, int r, const F &f) {\n        l +=\
    \ size;\n        r += size - 1;\n        if (!is_commutative) thrust(l);\n   \
    \     if (!is_commutative) thrust(r);\n        r++;\n        while (l < r) {\n\
    \            if (l & 1) lz[l] = composition(f, lz[l]), ++l;\n            if (r\
    \ & 1) --r, lz[r] = composition(f, lz[r]);\n            l >>= 1, r >>= 1;\n  \
    \      }\n    }\n    F get(int p) {\n        if (is_commutative) {\n         \
    \   F ret = id();\n            p += size;\n            while (p > 0) {\n     \
    \           ret = composition(lz[p], ret);\n                p >>= 1;\n       \
    \     }\n            return ret;\n        } else {\n            thrust(p += size);\n\
    \            return lz[p];\n        }\n    }\n\nprivate:\n    int size, height;\n\
    \    std::vector<F> lz;\n    bool is_commutative;\n    inline void propagate(int\
    \ k) {\n        lz[2 * k + 0] = composition(lz[k], lz[2 * k + 0]);\n        lz[2\
    \ * k + 1] = composition(lz[k], lz[2 * k + 1]);\n        lz[k] = id();\n    }\n\
    \    inline void thrust(int k) {\n        for (int i = height; i > 0; i--) propagate(k\
    \ >> i);\n    }\n};\n"
  code: "#include <vector>\ntemplate <class F, F (*composition)(F, F), F (*id)()>\n\
    struct dual_segtree {\npublic:\n    dual_segtree() {\n    }\n    dual_segtree(int\
    \ n, bool is_commutative = false)\n        : is_commutative(is_commutative) {\n\
    \        size = 1;\n        height = 0;\n        while (size < n) size <<= 1,\
    \ height++;\n        lz.assign(2 * size, id());\n    }\n    void apply(int l,\
    \ int r, const F &f) {\n        l += size;\n        r += size - 1;\n        if\
    \ (!is_commutative) thrust(l);\n        if (!is_commutative) thrust(r);\n    \
    \    r++;\n        while (l < r) {\n            if (l & 1) lz[l] = composition(f,\
    \ lz[l]), ++l;\n            if (r & 1) --r, lz[r] = composition(f, lz[r]);\n \
    \           l >>= 1, r >>= 1;\n        }\n    }\n    F get(int p) {\n        if\
    \ (is_commutative) {\n            F ret = id();\n            p += size;\n    \
    \        while (p > 0) {\n                ret = composition(lz[p], ret);\n   \
    \             p >>= 1;\n            }\n            return ret;\n        } else\
    \ {\n            thrust(p += size);\n            return lz[p];\n        }\n  \
    \  }\n\nprivate:\n    int size, height;\n    std::vector<F> lz;\n    bool is_commutative;\n\
    \    inline void propagate(int k) {\n        lz[2 * k + 0] = composition(lz[k],\
    \ lz[2 * k + 0]);\n        lz[2 * k + 1] = composition(lz[k], lz[2 * k + 1]);\n\
    \        lz[k] = id();\n    }\n    inline void thrust(int k) {\n        for (int\
    \ i = height; i > 0; i--) propagate(k >> i);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/dual_segtree.hpp
  requiredBy: []
  timestamp: '2023-03-05 19:05:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/range_affine_point_get.test.cpp
documentation_of: datastructure/dual_segtree.hpp
layout: document
redirect_from:
- /library/datastructure/dual_segtree.hpp
- /library/datastructure/dual_segtree.hpp.html
title: datastructure/dual_segtree.hpp
---
