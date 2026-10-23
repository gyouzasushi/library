---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_add.hpp
    title: 'Monoid: Add'
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_affine.hpp
    title: 'Monoid: Affine'
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_argmax.hpp
    title: 'Monoid: Argmax'
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_argmin.hpp
    title: 'Monoid: Argmin'
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_gcd.hpp
    title: 'Monoid: GCD'
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_max.hpp
    title: 'Monoid: Max'
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_min.hpp
    title: 'Monoid: Min'
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_xor.hpp
    title: 'Monoid: XOR'
  - icon: ':heavy_check_mark:'
    path: algebra/range_add_range_sum.hpp
    title: 'Acted Monoid: Range Add Range Sum'
  - icon: ':heavy_check_mark:'
    path: datastructure/lazy_segtree.hpp
    title: Lazy Segment Tree (acted monoid wrapper)
  - icon: ':heavy_check_mark:'
    path: datastructure/segtree.hpp
    title: Segment Tree (monoid wrapper)
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
  bundledCode: "#line 1 \"test/unit/monoid.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <numeric>\n#include <random>\n\
    #include <vector>\n\n#line 2 \"algebra/range_add_range_sum.hpp\"\ntemplate <class\
    \ T>\nstruct range_add_range_sum {\n    struct S {\n        T sum;\n        int\
    \ len;\n    };\n    using F = T;\n    static S op(S a, S b) {\n        return\
    \ {a.sum + b.sum, a.len + b.len};\n    }\n    static S e() {\n        return {T(0),\
    \ 0};\n    }\n    static S mapping(F f, S x) {\n        return {x.sum + f * x.len,\
    \ x.len};\n    }\n    static F composition(F f, F g) {\n        return f + g;\n\
    \    }\n    static F id() {\n        return T(0);\n    }\n    static constexpr\
    \ bool composition_commutative = true;\n    static S from(T v) {\n        return\
    \ {v, 1};\n    }\n};\n#line 2 \"datastructure/lazy_segtree.hpp\"\n#include <atcoder/lazysegtree>\n\
    \n#line 2 \"algebra/concept.hpp\"\n#include <concepts>\ntemplate <class M>\nconcept\
    \ semigroup = requires(typename M::S a, typename M::S b) {\n    { M::op(a, b)\
    \ } -> std::same_as<typename M::S>;\n};\ntemplate <class M>\nconcept monoid =\
    \ semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename M::S>;\n\
    };\ntemplate <class A>\nconcept action = requires(typename A::F f, typename A::F\
    \ g) {\n    { A::composition(f, g) } -> std::same_as<typename A::F>;\n    { A::id()\
    \ } -> std::same_as<typename A::F>;\n    { A::composition_commutative } -> std::convertible_to<bool>;\n\
    };\ntemplate <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
    \ A::S x, typename A::F f) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n};\n#line 5 \"datastructure/lazy_segtree.hpp\"\ntemplate <acted_monoid\
    \ A>\nusing lazy_segtree = atcoder::lazy_segtree<typename A::S, A::op, A::e, typename\
    \ A::F, A::mapping, A::composition, A::id>;\n#line 2 \"datastructure/segtree.hpp\"\
    \n#include <atcoder/segtree>\n\n#line 5 \"datastructure/segtree.hpp\"\ntemplate\
    \ <monoid M>\nusing segtree = atcoder::segtree<typename M::S, M::op, M::e>;\n\
    #line 2 \"algebra/monoid_add.hpp\"\ntemplate <class T>\nstruct monoid_add {\n\
    \    using S = T;\n    static S op(S a, S b) {\n        return a + b;\n    }\n\
    \    static S e() {\n        return T(0);\n    }\n};\n#line 2 \"algebra/monoid_affine.hpp\"\
    \ntemplate <class T>\nstruct monoid_affine {\n    struct S {\n        T a, b;\n\
    \    };\n    static S op(S f, S g) {\n        return {g.a * f.a, g.a * f.b + g.b};\n\
    \    }\n    static S e() {\n        return {T(1), T(0)};\n    }\n    static T\
    \ eval(S f, T x) {\n        return f.a * x + f.b;\n    }\n};\n#line 2 \"algebra/monoid_argmax.hpp\"\
    \n#include <limits>\ntemplate <class T>\nstruct monoid_argmax {\n    struct S\
    \ {\n        T val;\n        int id;\n    };\n    static S op(S a, S b) {\n  \
    \      if (a.val != b.val) return a.val > b.val ? a : b;\n        return a.id\
    \ < b.id ? a : b;\n    }\n    static S e() {\n        return {std::numeric_limits<T>::lowest(),\
    \ -1};\n    }\n};\n#line 3 \"algebra/monoid_argmin.hpp\"\ntemplate <class T>\n\
    struct monoid_argmin {\n    struct S {\n        T val;\n        int id;\n    };\n\
    \    static S op(S a, S b) {\n        if (a.val != b.val) return a.val < b.val\
    \ ? a : b;\n        return a.id < b.id ? a : b;\n    }\n    static S e() {\n \
    \       return {std::numeric_limits<T>::max(), -1};\n    }\n};\n#line 3 \"algebra/monoid_gcd.hpp\"\
    \ntemplate <class T>\nstruct monoid_gcd {\n    using S = T;\n    static S op(S\
    \ a, S b) {\n        return std::gcd(a, b);\n    }\n    static S e() {\n     \
    \   return T(0);\n    }\n};\n#line 2 \"algebra/monoid_max.hpp\"\n#include <algorithm>\n\
    #line 4 \"algebra/monoid_max.hpp\"\ntemplate <class T>\nstruct monoid_max {\n\
    \    using S = T;\n    static S op(S a, S b) {\n        return std::max(a, b);\n\
    \    }\n    static S e() {\n        return std::numeric_limits<T>::lowest();\n\
    \    }\n};\n#line 4 \"algebra/monoid_min.hpp\"\ntemplate <class T>\nstruct monoid_min\
    \ {\n    using S = T;\n    static S op(S a, S b) {\n        return std::min(a,\
    \ b);\n    }\n    static S e() {\n        return std::numeric_limits<T>::max();\n\
    \    }\n};\n#line 2 \"algebra/monoid_xor.hpp\"\ntemplate <class T>\nstruct monoid_xor\
    \ {\n    using S = T;\n    static S op(S a, S b) {\n        return a ^ b;\n  \
    \  }\n    static S e() {\n        return T(0);\n    }\n};\n#line 19 \"test/unit/monoid.test.cpp\"\
    \ntemplate <class M, class Naive>\nvoid stress_monoid(std::mt19937 &rng, const\
    \ Naive &naive) {\n    using S = typename M::S;\n    const int N = 1 + rng() %\
    \ 30;\n    std::vector<S> a(N);\n    for (auto &x : a) x = S(rng() % 100);\n \
    \   segtree<M> seg(a);\n    for (int it = 0; it < 200; it++) {\n        if (rng()\
    \ % 2) {\n            int p = rng() % N;\n            a[p] = S(rng() % 100);\n\
    \            seg.set(p, a[p]);\n        } else {\n            int l = rng() %\
    \ (N + 1), r = rng() % (N + 1);\n            if (l > r) std::swap(l, r);\n   \
    \         S expect = M::e();\n            for (int i = l; i < r; i++) expect =\
    \ naive(expect, a[i]);\n            assert(seg.prod(l, r) == expect);\n      \
    \  }\n    }\n}\ntemplate <class M, class Naive>\nvoid stress_argmonoid(std::mt19937\
    \ &rng, const Naive &better) {\n    using S = typename M::S;\n    const int N\
    \ = 1 + rng() % 30;\n    std::vector<S> a(N);\n    for (int i = 0; i < N; i++)\
    \ a[i] = {int(rng() % 5), i};\n    segtree<M> seg(a);\n    for (int it = 0; it\
    \ < 200; it++) {\n        if (rng() % 2) {\n            int p = rng() % N;\n \
    \           a[p] = {int(rng() % 5), p};\n            seg.set(p, a[p]);\n     \
    \   } else {\n            int l = rng() % (N + 1), r = rng() % (N + 1);\n    \
    \        if (l > r) std::swap(l, r);\n            S got = seg.prod(l, r);\n  \
    \          if (l == r) {\n                assert(got.id == -1);\n            \
    \    continue;\n            }\n            int best = l;\n            for (int\
    \ i = l + 1; i < r; i++) {\n                if (better(a[i].val, a[best].val))\
    \ best = i;\n            }\n            assert(got.id == best && got.val == a[best].val);\n\
    \        }\n    }\n}\nvoid stress_affine(std::mt19937 &rng) {\n    using M = monoid_affine<long\
    \ long>;\n    constexpr long long MOD = 998244353;\n    const int N = 1 + rng()\
    \ % 30;\n    std::vector<M::S> a(N);\n    for (auto &f : a) f = {(long long)(rng()\
    \ % 5), (long long)(rng() % 5)};\n    segtree<M> seg(a);\n    for (int it = 0;\
    \ it < 200; it++) {\n        if (rng() % 2) {\n            int p = rng() % N;\n\
    \            a[p] = {(long long)(rng() % 5), (long long)(rng() % 5)};\n      \
    \      seg.set(p, a[p]);\n        } else {\n            int l = rng() % (N + 1),\
    \ r = rng() % (N + 1);\n            if (l > r) std::swap(l, r);\n            long\
    \ long x = rng() % 10, y = x;\n            for (int i = l; i < r; i++) y = M::eval(a[i],\
    \ y) % MOD;\n            assert(M::eval(seg.prod(l, r), x) % MOD == y);\n    \
    \    }\n    }\n}\nvoid stress_range_add_range_sum(std::mt19937 &rng) {\n    using\
    \ A = range_add_range_sum<long long>;\n    const int N = 1 + rng() % 30;\n   \
    \ std::vector<long long> a(N);\n    std::vector<A::S> init(N);\n    for (int i\
    \ = 0; i < N; i++) {\n        a[i] = rng() % 100;\n        init[i] = A::from(a[i]);\n\
    \    }\n    lazy_segtree<A> seg(init);\n    for (int it = 0; it < 200; it++) {\n\
    \        int l = rng() % (N + 1), r = rng() % (N + 1);\n        if (l > r) std::swap(l,\
    \ r);\n        if (rng() % 2) {\n            long long x = rng() % 100;\n    \
    \        for (int i = l; i < r; i++) a[i] += x;\n            seg.apply(l, r, x);\n\
    \        } else {\n            long long expect = 0;\n            for (int i =\
    \ l; i < r; i++) expect += a[i];\n            assert(seg.prod(l, r).sum == expect);\n\
    \            assert(seg.prod(l, r).len == r - l);\n        }\n    }\n}\nint main()\
    \ {\n    std::mt19937 rng(7959);\n    for (int trial = 0; trial < 100; trial++)\
    \ {\n        stress_monoid<monoid_add<long long>>(rng, [](long long a, long long\
    \ b) { return a + b; });\n        stress_monoid<monoid_min<int>>(rng, [](int a,\
    \ int b) { return std::min(a, b); });\n        stress_monoid<monoid_max<int>>(rng,\
    \ [](int a, int b) { return std::max(a, b); });\n        stress_monoid<monoid_gcd<int>>(rng,\
    \ [](int a, int b) { return std::gcd(a, b); });\n        stress_monoid<monoid_xor<unsigned>>(rng,\
    \ [](unsigned a, unsigned b) { return a ^ b; });\n        stress_argmonoid<monoid_argmin<int>>(rng,\
    \ [](int a, int b) { return a < b; });\n        stress_argmonoid<monoid_argmax<int>>(rng,\
    \ [](int a, int b) { return a > b; });\n        stress_affine(rng);\n        stress_range_add_range_sum(rng);\n\
    \    }\n    std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <numeric>\n#include <random>\n\
    #include <vector>\n\n#include \"algebra/range_add_range_sum.hpp\"\n#include \"\
    datastructure/lazy_segtree.hpp\"\n#include \"datastructure/segtree.hpp\"\n#include\
    \ \"algebra/monoid_add.hpp\"\n#include \"algebra/monoid_affine.hpp\"\n#include\
    \ \"algebra/monoid_argmax.hpp\"\n#include \"algebra/monoid_argmin.hpp\"\n#include\
    \ \"algebra/monoid_gcd.hpp\"\n#include \"algebra/monoid_max.hpp\"\n#include \"\
    algebra/monoid_min.hpp\"\n#include \"algebra/monoid_xor.hpp\"\ntemplate <class\
    \ M, class Naive>\nvoid stress_monoid(std::mt19937 &rng, const Naive &naive) {\n\
    \    using S = typename M::S;\n    const int N = 1 + rng() % 30;\n    std::vector<S>\
    \ a(N);\n    for (auto &x : a) x = S(rng() % 100);\n    segtree<M> seg(a);\n \
    \   for (int it = 0; it < 200; it++) {\n        if (rng() % 2) {\n           \
    \ int p = rng() % N;\n            a[p] = S(rng() % 100);\n            seg.set(p,\
    \ a[p]);\n        } else {\n            int l = rng() % (N + 1), r = rng() % (N\
    \ + 1);\n            if (l > r) std::swap(l, r);\n            S expect = M::e();\n\
    \            for (int i = l; i < r; i++) expect = naive(expect, a[i]);\n     \
    \       assert(seg.prod(l, r) == expect);\n        }\n    }\n}\ntemplate <class\
    \ M, class Naive>\nvoid stress_argmonoid(std::mt19937 &rng, const Naive &better)\
    \ {\n    using S = typename M::S;\n    const int N = 1 + rng() % 30;\n    std::vector<S>\
    \ a(N);\n    for (int i = 0; i < N; i++) a[i] = {int(rng() % 5), i};\n    segtree<M>\
    \ seg(a);\n    for (int it = 0; it < 200; it++) {\n        if (rng() % 2) {\n\
    \            int p = rng() % N;\n            a[p] = {int(rng() % 5), p};\n   \
    \         seg.set(p, a[p]);\n        } else {\n            int l = rng() % (N\
    \ + 1), r = rng() % (N + 1);\n            if (l > r) std::swap(l, r);\n      \
    \      S got = seg.prod(l, r);\n            if (l == r) {\n                assert(got.id\
    \ == -1);\n                continue;\n            }\n            int best = l;\n\
    \            for (int i = l + 1; i < r; i++) {\n                if (better(a[i].val,\
    \ a[best].val)) best = i;\n            }\n            assert(got.id == best &&\
    \ got.val == a[best].val);\n        }\n    }\n}\nvoid stress_affine(std::mt19937\
    \ &rng) {\n    using M = monoid_affine<long long>;\n    constexpr long long MOD\
    \ = 998244353;\n    const int N = 1 + rng() % 30;\n    std::vector<M::S> a(N);\n\
    \    for (auto &f : a) f = {(long long)(rng() % 5), (long long)(rng() % 5)};\n\
    \    segtree<M> seg(a);\n    for (int it = 0; it < 200; it++) {\n        if (rng()\
    \ % 2) {\n            int p = rng() % N;\n            a[p] = {(long long)(rng()\
    \ % 5), (long long)(rng() % 5)};\n            seg.set(p, a[p]);\n        } else\
    \ {\n            int l = rng() % (N + 1), r = rng() % (N + 1);\n            if\
    \ (l > r) std::swap(l, r);\n            long long x = rng() % 10, y = x;\n   \
    \         for (int i = l; i < r; i++) y = M::eval(a[i], y) % MOD;\n          \
    \  assert(M::eval(seg.prod(l, r), x) % MOD == y);\n        }\n    }\n}\nvoid stress_range_add_range_sum(std::mt19937\
    \ &rng) {\n    using A = range_add_range_sum<long long>;\n    const int N = 1\
    \ + rng() % 30;\n    std::vector<long long> a(N);\n    std::vector<A::S> init(N);\n\
    \    for (int i = 0; i < N; i++) {\n        a[i] = rng() % 100;\n        init[i]\
    \ = A::from(a[i]);\n    }\n    lazy_segtree<A> seg(init);\n    for (int it = 0;\
    \ it < 200; it++) {\n        int l = rng() % (N + 1), r = rng() % (N + 1);\n \
    \       if (l > r) std::swap(l, r);\n        if (rng() % 2) {\n            long\
    \ long x = rng() % 100;\n            for (int i = l; i < r; i++) a[i] += x;\n\
    \            seg.apply(l, r, x);\n        } else {\n            long long expect\
    \ = 0;\n            for (int i = l; i < r; i++) expect += a[i];\n            assert(seg.prod(l,\
    \ r).sum == expect);\n            assert(seg.prod(l, r).len == r - l);\n     \
    \   }\n    }\n}\nint main() {\n    std::mt19937 rng(7959);\n    for (int trial\
    \ = 0; trial < 100; trial++) {\n        stress_monoid<monoid_add<long long>>(rng,\
    \ [](long long a, long long b) { return a + b; });\n        stress_monoid<monoid_min<int>>(rng,\
    \ [](int a, int b) { return std::min(a, b); });\n        stress_monoid<monoid_max<int>>(rng,\
    \ [](int a, int b) { return std::max(a, b); });\n        stress_monoid<monoid_gcd<int>>(rng,\
    \ [](int a, int b) { return std::gcd(a, b); });\n        stress_monoid<monoid_xor<unsigned>>(rng,\
    \ [](unsigned a, unsigned b) { return a ^ b; });\n        stress_argmonoid<monoid_argmin<int>>(rng,\
    \ [](int a, int b) { return a < b; });\n        stress_argmonoid<monoid_argmax<int>>(rng,\
    \ [](int a, int b) { return a > b; });\n        stress_affine(rng);\n        stress_range_add_range_sum(rng);\n\
    \    }\n    std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - algebra/range_add_range_sum.hpp
  - datastructure/lazy_segtree.hpp
  - algebra/concept.hpp
  - datastructure/segtree.hpp
  - algebra/monoid_add.hpp
  - algebra/monoid_affine.hpp
  - algebra/monoid_argmax.hpp
  - algebra/monoid_argmin.hpp
  - algebra/monoid_gcd.hpp
  - algebra/monoid_max.hpp
  - algebra/monoid_min.hpp
  - algebra/monoid_xor.hpp
  isVerificationFile: true
  path: test/unit/monoid.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 22:06:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/monoid.test.cpp
layout: document
redirect_from:
- /verify/test/unit/monoid.test.cpp
- /verify/test/unit/monoid.test.cpp.html
title: test/unit/monoid.test.cpp
---
