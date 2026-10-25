---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
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
    \ <atcoder/modint>\n#include <iostream>\n#include <vector>\n\n#line 2 \"datastructure/dual_segtree.hpp\"\
    \n#include <algorithm>\n#include <bit>\n#include <cassert>\n#line 6 \"datastructure/dual_segtree.hpp\"\
    \n\n#line 2 \"algebra/concept.hpp\"\n#include <concepts>\ntemplate <class M>\n\
    concept semigroup = requires(typename M::S a, typename M::S b) {\n    { M::op(a,\
    \ b) } -> std::same_as<typename M::S>;\n};\ntemplate <class M>\nconcept monoid\
    \ = semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename M::S>;\n\
    };\ntemplate <class G>\nconcept group = monoid<G> && requires(typename G::S a)\
    \ {\n    { G::inv(a) } -> std::same_as<typename G::S>;\n};\ntemplate <class A>\n\
    concept action = requires(typename A::F f, typename A::F g) {\n    { A::composition(f,\
    \ g) } -> std::same_as<typename A::F>;\n    { A::id() } -> std::same_as<typename\
    \ A::F>;\n    { A::composition_commutative } -> std::convertible_to<bool>;\n};\n\
    template <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
    \ A::S x, typename A::F f) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n};\ntemplate <class R>\nconcept semiring = requires(typename R::S a,\
    \ typename R::S b) {\n    { R::add(a, b) } -> std::same_as<typename R::S>;\n \
    \   { R::zero() } -> std::same_as<typename R::S>;\n    { R::mul(a, b) } -> std::same_as<typename\
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\n#line 8 \"datastructure/dual_segtree.hpp\"\
    \ntemplate <action A>\nstruct dual_segtree {\n    using F = typename A::F;\n \
    \   dual_segtree() : dual_segtree(0) {}\n    explicit dual_segtree(int n) : dual_segtree(std::vector<F>(n,\
    \ A::id())) {}\n    explicit dual_segtree(const std::vector<F>& v) : n(int(v.size()))\
    \ {\n        log = std::bit_width(unsigned(std::max(n - 1, 0)));\n        size\
    \ = 1 << log;\n        d.assign(2 * size, A::id());\n        for (int i = 0; i\
    \ < n; i++) d[size + i] = v[i];\n    }\n    void set(int p, F x) {\n        assert(0\
    \ <= p && p < n);\n        p += size;\n        thrust(p);\n        d[p] = x;\n\
    \    }\n    F get(int p) {\n        assert(0 <= p && p < n);\n        p += size;\n\
    \        if constexpr (A::composition_commutative) {\n            F ret = d[p];\n\
    \            while (p >>= 1) ret = A::composition(d[p], ret);\n            return\
    \ ret;\n        } else {\n            thrust(p);\n            return d[p];\n \
    \       }\n    }\n    void apply(int l, int r, F f) {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        if (l == r) return;\n        l += size;\n      \
    \  r += size;\n        if constexpr (!A::composition_commutative) {\n        \
    \    thrust(l);\n            thrust(r - 1);\n        }\n        while (l < r)\
    \ {\n            if (l & 1) d[l] = A::composition(f, d[l]), l++;\n           \
    \ if (r & 1) --r, d[r] = A::composition(f, d[r]);\n            l >>= 1, r >>=\
    \ 1;\n        }\n    }\n\nprivate:\n    int n, size, log;\n    std::vector<F>\
    \ d;\n    void propagate(int k) {\n        d[2 * k] = A::composition(d[k], d[2\
    \ * k]);\n        d[2 * k + 1] = A::composition(d[k], d[2 * k + 1]);\n       \
    \ d[k] = A::id();\n    }\n    void thrust(int k) {\n        for (int i = log;\
    \ i >= 1; i--) propagate(k >> i);\n    }\n};\n#line 7 \"test/library-checker/range_affine_point_get.test.cpp\"\
    \nusing mint = atcoder::modint998244353;\nstruct range_affine {\n    struct F\
    \ {\n        mint b, c;\n    };\n    static F composition(F f, F g) { return {f.b\
    \ * g.b, f.b * g.c + f.c}; }\n    static F id() { return {1, 0}; }\n    static\
    \ constexpr bool composition_commutative = false;\n};\nint main() {\n    int n,\
    \ q;\n    std::cin >> n >> q;\n    std::vector<mint> a(n);\n    for (int i = 0;\
    \ i < n; i++) {\n        int x;\n        std::cin >> x;\n        a[i] = mint::raw(x);\n\
    \    }\n    dual_segtree<range_affine> seg(n);\n    while (q--) {\n        int\
    \ t;\n        std::cin >> t;\n        if (t == 0) {\n            int l, r, b,\
    \ c;\n            std::cin >> l >> r >> b >> c;\n            seg.apply(l, r, {mint::raw(b),\
    \ mint::raw(c)});\n        } else {\n            int i;\n            std::cin\
    \ >> i;\n            auto f = seg.get(i);\n            std::cout << (f.b * a[i]\
    \ + f.c).val() << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n#include <atcoder/modint>\n#include <iostream>\n#include <vector>\n\n#include\
    \ \"datastructure/dual_segtree.hpp\"\nusing mint = atcoder::modint998244353;\n\
    struct range_affine {\n    struct F {\n        mint b, c;\n    };\n    static\
    \ F composition(F f, F g) { return {f.b * g.b, f.b * g.c + f.c}; }\n    static\
    \ F id() { return {1, 0}; }\n    static constexpr bool composition_commutative\
    \ = false;\n};\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<mint>\
    \ a(n);\n    for (int i = 0; i < n; i++) {\n        int x;\n        std::cin >>\
    \ x;\n        a[i] = mint::raw(x);\n    }\n    dual_segtree<range_affine> seg(n);\n\
    \    while (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int l, r, b, c;\n            std::cin >> l >> r >> b >> c;\n\
    \            seg.apply(l, r, {mint::raw(b), mint::raw(c)});\n        } else {\n\
    \            int i;\n            std::cin >> i;\n            auto f = seg.get(i);\n\
    \            std::cout << (f.b * a[i] + f.c).val() << '\\n';\n        }\n    }\n\
    }\n"
  dependsOn:
  - datastructure/dual_segtree.hpp
  - algebra/concept.hpp
  isVerificationFile: true
  path: test/library-checker/range_affine_point_get.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 01:30:50+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/range_affine_point_get.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/range_affine_point_get.test.cpp
- /verify/test/library-checker/range_affine_point_get.test.cpp.html
title: test/library-checker/range_affine_point_get.test.cpp
---
