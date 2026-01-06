---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: datastructure/dual_segtree.hpp
    title: Dual Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"test/library-checker/range_affine_point_get.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n#include\
    \ <atcoder/modint>\n#include <iostream>\n\n#line 1 \"datastructure/dual_segtree.hpp\"\
    \n#include <vector>\ntemplate <class F, F (*composition)(F, F), F (*id)()>\nstruct\
    \ dual_segtree {\npublic:\n    dual_segtree() {\n    }\n    dual_segtree(int n,\
    \ bool is_commutative = false)\n        : is_commutative(is_commutative) {\n \
    \       size = 1;\n        height = 0;\n        while (size < n) size <<= 1, height++;\n\
    \        lz.assign(2 * size, id());\n    }\n    void apply(int l, int r, const\
    \ F &f) {\n        l += size;\n        r += size - 1;\n        if (!is_commutative)\
    \ thrust(l);\n        if (!is_commutative) thrust(r);\n        r++;\n        while\
    \ (l < r) {\n            if (l & 1) lz[l] = composition(f, lz[l]), ++l;\n    \
    \        if (r & 1) --r, lz[r] = composition(f, lz[r]);\n            l >>= 1,\
    \ r >>= 1;\n        }\n    }\n    F get(int p) {\n        if (is_commutative)\
    \ {\n            F ret = id();\n            p += size;\n            while (p >\
    \ 0) {\n                ret = composition(lz[p], ret);\n                p >>=\
    \ 1;\n            }\n            return ret;\n        } else {\n            thrust(p\
    \ += size);\n            return lz[p];\n        }\n    }\n\nprivate:\n    int\
    \ size, height;\n    std::vector<F> lz;\n    bool is_commutative;\n    inline\
    \ void propagate(int k) {\n        lz[2 * k + 0] = composition(lz[k], lz[2 * k\
    \ + 0]);\n        lz[2 * k + 1] = composition(lz[k], lz[2 * k + 1]);\n       \
    \ lz[k] = id();\n    }\n    inline void thrust(int k) {\n        for (int i =\
    \ height; i > 0; i--) propagate(k >> i);\n    }\n};\n#line 6 \"test/library-checker/range_affine_point_get.test.cpp\"\
    \nusing mint = atcoder::modint998244353;\nstruct F {\n    mint b, c;\n    mint\
    \ val(mint x) {\n        return b * x + c;\n    }\n};\nF compostition(F f, F g)\
    \ {\n    return {f.b * g.b, f.b * g.c + f.c};\n}\nF id() {\n    return {1, 0};\n\
    }\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<mint>\
    \ a(n);\n    for (int i = 0; i < n; i++) {\n        int x;\n        std::cin >>\
    \ x;\n        a[i] = mint::raw(x);\n    }\n    dual_segtree<F, compostition, id>\
    \ segt(n);\n    while (q--) {\n        int t;\n        std::cin >> t;\n      \
    \  if (t == 0) {\n            int l, r;\n            int b, c;\n            std::cin\
    \ >> l >> r >> b >> c;\n            segt.apply(l, r, {mint::raw(b), mint::raw(c)});\n\
    \        }\n        if (t == 1) {\n            int i;\n            std::cin >>\
    \ i;\n            std::cout << segt.get(i).val(a[i]).val() << '\\n';\n       \
    \ }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n#include <atcoder/modint>\n#include <iostream>\n\n#include \"datastructure/dual_segtree.hpp\"\
    \nusing mint = atcoder::modint998244353;\nstruct F {\n    mint b, c;\n    mint\
    \ val(mint x) {\n        return b * x + c;\n    }\n};\nF compostition(F f, F g)\
    \ {\n    return {f.b * g.b, f.b * g.c + f.c};\n}\nF id() {\n    return {1, 0};\n\
    }\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<mint>\
    \ a(n);\n    for (int i = 0; i < n; i++) {\n        int x;\n        std::cin >>\
    \ x;\n        a[i] = mint::raw(x);\n    }\n    dual_segtree<F, compostition, id>\
    \ segt(n);\n    while (q--) {\n        int t;\n        std::cin >> t;\n      \
    \  if (t == 0) {\n            int l, r;\n            int b, c;\n            std::cin\
    \ >> l >> r >> b >> c;\n            segt.apply(l, r, {mint::raw(b), mint::raw(c)});\n\
    \        }\n        if (t == 1) {\n            int i;\n            std::cin >>\
    \ i;\n            std::cout << segt.get(i).val(a[i]).val() << '\\n';\n       \
    \ }\n    }\n}"
  dependsOn:
  - datastructure/dual_segtree.hpp
  isVerificationFile: true
  path: test/library-checker/range_affine_point_get.test.cpp
  requiredBy: []
  timestamp: '2024-06-04 14:30:20+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/range_affine_point_get.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/range_affine_point_get.test.cpp
- /verify/test/library-checker/range_affine_point_get.test.cpp.html
title: test/library-checker/range_affine_point_get.test.cpp
---
