---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
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
    \n#include <cassert>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \n#line 2 \"datastructure/dual_segtree.hpp\"\n#include <algorithm>\n#include <bit>\n\
    #line 6 \"datastructure/dual_segtree.hpp\"\n\n#line 2 \"algebra/concept.hpp\"\n\
    #include <concepts>\ntemplate <class M>\nconcept semigroup = requires(typename\
    \ M::S a, typename M::S b) {\n    { M::op(a, b) } -> std::same_as<typename M::S>;\n\
    };\ntemplate <class M>\nconcept monoid = semigroup<M> && requires {\n    { M::e()\
    \ } -> std::same_as<typename M::S>;\n};\ntemplate <class A>\nconcept action =\
    \ requires(typename A::F f, typename A::F g) {\n    { A::composition(f, g) } ->\
    \ std::same_as<typename A::F>;\n    { A::id() } -> std::same_as<typename A::F>;\n\
    \    { A::composition_commutative } -> std::convertible_to<bool>;\n};\ntemplate\
    \ <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
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
    \ i >= 1; i--) propagate(k >> i);\n    }\n};\n#line 8 \"test/unit/dual_segtree.test.cpp\"\
    \nstruct range_affine {\n    struct F {\n        long long a, b;\n        bool\
    \ operator==(const F&) const = default;\n    };\n    static F composition(F f,\
    \ F g) { return {f.a * g.a, f.a * g.b + f.b}; }\n    static F id() { return {1,\
    \ 0}; }\n    static constexpr bool composition_commutative = false;\n};\ntemplate\
    \ <bool commutative>\nstruct range_add {\n    using F = long long;\n    static\
    \ F composition(F f, F g) { return f + g; }\n    static F id() { return 0; }\n\
    \    static constexpr bool composition_commutative = commutative;\n};\ntemplate\
    \ <class A>\nvoid stress(std::mt19937& rng, auto gen) {\n    using F = typename\
    \ A::F;\n    const int N = 1 + rng() % 40;\n    const int Q = 2000;\n    std::vector<F>\
    \ init(N);\n    for (auto& x : init) x = gen();\n    dual_segtree<A> seg(init);\n\
    \    std::vector<F> naive = init;\n    for (int q = 0; q < Q; q++) {\n       \
    \ int t = rng() % 3;\n        if (t == 0) {\n            int l = rng() % (N +\
    \ 1);\n            int r = rng() % (N + 1);\n            if (l > r) std::swap(l,\
    \ r);\n            F f = gen();\n            seg.apply(l, r, f);\n           \
    \ for (int i = l; i < r; i++) naive[i] = A::composition(f, naive[i]);\n      \
    \  } else if (t == 1) {\n            int p = rng() % N;\n            F v = gen();\n\
    \            seg.set(p, v);\n            naive[p] = v;\n        } else {\n   \
    \         int p = rng() % N;\n            assert(seg.get(p) == naive[p]);\n  \
    \      }\n    }\n}\nint main() {\n    std::mt19937 rng(7959);\n    auto gen_aff\
    \ = [&]() -> range_affine::F { return {(long long)(rng() % 5), (long long)(rng()\
    \ % 5)}; };\n    auto gen_add = [&]() -> long long { return rng() % 10; };\n \
    \   for (int trial = 0; trial < 30; trial++) {\n        stress<range_affine>(rng,\
    \ gen_aff);\n        stress<range_add<true>>(rng, gen_add);\n        stress<range_add<false>>(rng,\
    \ gen_add);\n    }\n    {\n        dual_segtree<range_add<true>> seg;\n      \
    \  dual_segtree<range_add<true>> seg1(1);\n        seg1.apply(0, 1, 3);\n    \
    \    assert(seg1.get(0) == 3);\n    }\n    std::cout << \"Hello World\" << std::endl;\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \n#include \"datastructure/dual_segtree.hpp\"\nstruct range_affine {\n    struct\
    \ F {\n        long long a, b;\n        bool operator==(const F&) const = default;\n\
    \    };\n    static F composition(F f, F g) { return {f.a * g.a, f.a * g.b + f.b};\
    \ }\n    static F id() { return {1, 0}; }\n    static constexpr bool composition_commutative\
    \ = false;\n};\ntemplate <bool commutative>\nstruct range_add {\n    using F =\
    \ long long;\n    static F composition(F f, F g) { return f + g; }\n    static\
    \ F id() { return 0; }\n    static constexpr bool composition_commutative = commutative;\n\
    };\ntemplate <class A>\nvoid stress(std::mt19937& rng, auto gen) {\n    using\
    \ F = typename A::F;\n    const int N = 1 + rng() % 40;\n    const int Q = 2000;\n\
    \    std::vector<F> init(N);\n    for (auto& x : init) x = gen();\n    dual_segtree<A>\
    \ seg(init);\n    std::vector<F> naive = init;\n    for (int q = 0; q < Q; q++)\
    \ {\n        int t = rng() % 3;\n        if (t == 0) {\n            int l = rng()\
    \ % (N + 1);\n            int r = rng() % (N + 1);\n            if (l > r) std::swap(l,\
    \ r);\n            F f = gen();\n            seg.apply(l, r, f);\n           \
    \ for (int i = l; i < r; i++) naive[i] = A::composition(f, naive[i]);\n      \
    \  } else if (t == 1) {\n            int p = rng() % N;\n            F v = gen();\n\
    \            seg.set(p, v);\n            naive[p] = v;\n        } else {\n   \
    \         int p = rng() % N;\n            assert(seg.get(p) == naive[p]);\n  \
    \      }\n    }\n}\nint main() {\n    std::mt19937 rng(7959);\n    auto gen_aff\
    \ = [&]() -> range_affine::F { return {(long long)(rng() % 5), (long long)(rng()\
    \ % 5)}; };\n    auto gen_add = [&]() -> long long { return rng() % 10; };\n \
    \   for (int trial = 0; trial < 30; trial++) {\n        stress<range_affine>(rng,\
    \ gen_aff);\n        stress<range_add<true>>(rng, gen_add);\n        stress<range_add<false>>(rng,\
    \ gen_add);\n    }\n    {\n        dual_segtree<range_add<true>> seg;\n      \
    \  dual_segtree<range_add<true>> seg1(1);\n        seg1.apply(0, 1, 3);\n    \
    \    assert(seg1.get(0) == 3);\n    }\n    std::cout << \"Hello World\" << std::endl;\n\
    \    return 0;\n}\n"
  dependsOn:
  - datastructure/dual_segtree.hpp
  - algebra/concept.hpp
  isVerificationFile: true
  path: test/unit/dual_segtree.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 22:22:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/dual_segtree.test.cpp
layout: document
redirect_from:
- /verify/test/unit/dual_segtree.test.cpp
- /verify/test/unit/dual_segtree.test.cpp.html
title: test/unit/dual_segtree.test.cpp
---
