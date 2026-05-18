---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/dual_segtree.hpp
    title: Dual Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unit/dual_segtree.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <random>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"datastructure/dual_segtree.hpp\"\ntemplate <class\
    \ F, F (*composition)(F, F), F (*id)()>\nstruct dual_segtree {\npublic:\n    dual_segtree()\
    \ {\n    }\n    dual_segtree(int n, bool is_commutative = false)\n        : is_commutative(is_commutative)\
    \ {\n        size = 1;\n        height = 0;\n        while (size < n) size <<=\
    \ 1, height++;\n        lz.assign(2 * size, id());\n    }\n    void set(int p,\
    \ const F &x) {\n        p += size;\n        thrust(p);\n        lz[p] = x;\n\
    \    }\n    void apply(int l, int r, const F &f) {\n        l += size;\n     \
    \   r += size - 1;\n        if (!is_commutative) thrust(l);\n        if (!is_commutative)\
    \ thrust(r);\n        r++;\n        while (l < r) {\n            if (l & 1) lz[l]\
    \ = composition(f, lz[l]), ++l;\n            if (r & 1) --r, lz[r] = composition(f,\
    \ lz[r]);\n            l >>= 1, r >>= 1;\n        }\n    }\n    F get(int p) {\n\
    \        if (is_commutative) {\n            F ret = id();\n            p += size;\n\
    \            while (p > 0) {\n                ret = composition(lz[p], ret);\n\
    \                p >>= 1;\n            }\n            return ret;\n        } else\
    \ {\n            thrust(p += size);\n            return lz[p];\n        }\n  \
    \  }\n\nprivate:\n    int size, height;\n    std::vector<F> lz;\n    bool is_commutative;\n\
    \    inline void propagate(int k) {\n        lz[2 * k + 0] = composition(lz[k],\
    \ lz[2 * k + 0]);\n        lz[2 * k + 1] = composition(lz[k], lz[2 * k + 1]);\n\
    \        lz[k] = id();\n    }\n    inline void thrust(int k) {\n        for (int\
    \ i = height; i > 0; i--) propagate(k >> i);\n    }\n};\n#line 9 \"test/unit/dual_segtree.test.cpp\"\
    \nusing F = std::pair<long long, long long>;\nF composition(F f, F g) {\n    return\
    \ {f.first * g.first, f.first * g.second + f.second};\n}\nF id() {\n    return\
    \ {1, 0};\n}\nvoid stress(bool is_commutative, std::mt19937 &rng) {\n    const\
    \ int N = 30;\n    const int Q = 2000;\n    dual_segtree<F, composition, id> seg(N,\
    \ is_commutative);\n    std::vector<F> naive(N, id());\n    auto gen = [&]() ->\
    \ F {\n        if (is_commutative) {\n            return {1, (long long)(rng()\
    \ % 10)};\n        } else {\n            return {(long long)(rng() % 5), (long\
    \ long)(rng() % 5)};\n        }\n    };\n    for (int q = 0; q < Q; q++) {\n \
    \       int t = rng() % 3;\n        if (t == 0) {\n            int l = rng() %\
    \ N;\n            int r = l + 1 + rng() % (N - l);\n            F f = gen();\n\
    \            seg.apply(l, r, f);\n            for (int i = l; i < r; i++) naive[i]\
    \ = composition(f, naive[i]);\n        } else if (t == 1) {\n            int p\
    \ = rng() % N;\n            F v = gen();\n            seg.set(p, v);\n       \
    \     naive[p] = v;\n        } else {\n            int p = rng() % N;\n      \
    \      assert(seg.get(p) == naive[p]);\n        }\n    }\n}\nint main() {\n  \
    \  std::mt19937 rng(7959);\n    for (int trial = 0; trial < 20; trial++) {\n \
    \       stress(false, rng);\n        stress(true, rng);\n    }\n    std::cout\
    \ << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <random>\n#include <utility>\n\
    #include <vector>\n\n#include \"datastructure/dual_segtree.hpp\"\nusing F = std::pair<long\
    \ long, long long>;\nF composition(F f, F g) {\n    return {f.first * g.first,\
    \ f.first * g.second + f.second};\n}\nF id() {\n    return {1, 0};\n}\nvoid stress(bool\
    \ is_commutative, std::mt19937 &rng) {\n    const int N = 30;\n    const int Q\
    \ = 2000;\n    dual_segtree<F, composition, id> seg(N, is_commutative);\n    std::vector<F>\
    \ naive(N, id());\n    auto gen = [&]() -> F {\n        if (is_commutative) {\n\
    \            return {1, (long long)(rng() % 10)};\n        } else {\n        \
    \    return {(long long)(rng() % 5), (long long)(rng() % 5)};\n        }\n   \
    \ };\n    for (int q = 0; q < Q; q++) {\n        int t = rng() % 3;\n        if\
    \ (t == 0) {\n            int l = rng() % N;\n            int r = l + 1 + rng()\
    \ % (N - l);\n            F f = gen();\n            seg.apply(l, r, f);\n    \
    \        for (int i = l; i < r; i++) naive[i] = composition(f, naive[i]);\n  \
    \      } else if (t == 1) {\n            int p = rng() % N;\n            F v =\
    \ gen();\n            seg.set(p, v);\n            naive[p] = v;\n        } else\
    \ {\n            int p = rng() % N;\n            assert(seg.get(p) == naive[p]);\n\
    \        }\n    }\n}\nint main() {\n    std::mt19937 rng(7959);\n    for (int\
    \ trial = 0; trial < 20; trial++) {\n        stress(false, rng);\n        stress(true,\
    \ rng);\n    }\n    std::cout << \"Hello World\" << std::endl;\n    return 0;\n\
    }\n"
  dependsOn:
  - datastructure/dual_segtree.hpp
  isVerificationFile: true
  path: test/unit/dual_segtree.test.cpp
  requiredBy: []
  timestamp: '2026-05-18 09:49:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/dual_segtree.test.cpp
layout: document
redirect_from:
- /verify/test/unit/dual_segtree.test.cpp
- /verify/test/unit/dual_segtree.test.cpp.html
title: test/unit/dual_segtree.test.cpp
---
