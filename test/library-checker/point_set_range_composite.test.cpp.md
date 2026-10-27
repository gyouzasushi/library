---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_affine.hpp
    title: 'Monoid: Affine'
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/library-checker/point_set_range_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <atcoder/modint>\n#include <iostream>\n#include <vector>\n\n#line 2\
    \ \"datastructure/segtree.hpp\"\n#include <atcoder/segtree>\n\n#line 2 \"algebra/concept.hpp\"\
    \n#include <concepts>\ntemplate <class M>\nconcept semigroup = requires(typename\
    \ M::S a, typename M::S b) {\n    { M::op(a, b) } -> std::same_as<typename M::S>;\n\
    };\ntemplate <class M>\nconcept monoid = semigroup<M> && requires {\n    { M::e()\
    \ } -> std::same_as<typename M::S>;\n};\ntemplate <class G>\nconcept group = monoid<G>\
    \ && requires(typename G::S a) {\n    { G::inv(a) } -> std::same_as<typename G::S>;\n\
    };\ntemplate <class A>\nconcept action = requires(typename A::F f, typename A::F\
    \ g) {\n    { A::composition(f, g) } -> std::same_as<typename A::F>;\n    { A::id()\
    \ } -> std::same_as<typename A::F>;\n    { A::composition_commutative } -> std::convertible_to<bool>;\n\
    };\ntemplate <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
    \ A::S x, typename A::F f) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n};\ntemplate <class R>\nconcept semiring = requires(typename R::S a,\
    \ typename R::S b) {\n    { R::add(a, b) } -> std::same_as<typename R::S>;\n \
    \   { R::zero() } -> std::same_as<typename R::S>;\n    { R::mul(a, b) } -> std::same_as<typename\
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\n#line 5 \"datastructure/segtree.hpp\"\
    \ntemplate <monoid M>\nusing segtree = atcoder::segtree<typename M::S, M::op,\
    \ M::e>;\n#line 2 \"algebra/monoid_affine.hpp\"\ntemplate <class T>\nstruct monoid_affine\
    \ {\n    struct S {\n        T a, b;\n    };\n    static S op(S f, S g) {\n  \
    \      return {g.a * f.a, g.a * f.b + g.b};\n    }\n    static S e() {\n     \
    \   return {T(1), T(0)};\n    }\n    static T eval(S f, T x) {\n        return\
    \ f.a * x + f.b;\n    }\n};\n#line 8 \"test/library-checker/point_set_range_composite.test.cpp\"\
    \nusing mint = atcoder::modint998244353;\nusing M = monoid_affine<mint>;\nint\
    \ main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<M::S> f(n);\n\
    \    for (int i = 0; i < n; i++) {\n        int a, b;\n        std::cin >> a >>\
    \ b;\n        f[i] = {mint::raw(a), mint::raw(b)};\n    }\n    segtree<M> seg(f);\n\
    \    while (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int p, c, d;\n            std::cin >> p >> c >> d;\n        \
    \    seg.set(p, {mint::raw(c), mint::raw(d)});\n        }\n        if (t == 1)\
    \ {\n            int l, r, x;\n            std::cin >> l >> r >> x;\n        \
    \    std::cout << M::eval(seg.prod(l, r), mint::raw(x)).val() << '\\n';\n    \
    \    }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <atcoder/modint>\n#include <iostream>\n#include <vector>\n\n#include\
    \ \"datastructure/segtree.hpp\"\n#include \"algebra/monoid_affine.hpp\"\nusing\
    \ mint = atcoder::modint998244353;\nusing M = monoid_affine<mint>;\nint main()\
    \ {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<M::S> f(n);\n   \
    \ for (int i = 0; i < n; i++) {\n        int a, b;\n        std::cin >> a >> b;\n\
    \        f[i] = {mint::raw(a), mint::raw(b)};\n    }\n    segtree<M> seg(f);\n\
    \    while (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int p, c, d;\n            std::cin >> p >> c >> d;\n        \
    \    seg.set(p, {mint::raw(c), mint::raw(d)});\n        }\n        if (t == 1)\
    \ {\n            int l, r, x;\n            std::cin >> l >> r >> x;\n        \
    \    std::cout << M::eval(seg.prod(l, r), mint::raw(x)).val() << '\\n';\n    \
    \    }\n    }\n}\n"
  dependsOn:
  - datastructure/segtree.hpp
  - algebra/concept.hpp
  - algebra/monoid_affine.hpp
  isVerificationFile: true
  path: test/library-checker/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 01:30:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/point_set_range_composite.test.cpp
- /verify/test/library-checker/point_set_range_composite.test.cpp.html
title: test/library-checker/point_set_range_composite.test.cpp
---
