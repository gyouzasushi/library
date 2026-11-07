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
    path: algebra/range_affine_range_sum.hpp
    title: 'Acted Monoid: Range Affine Range Sum'
  - icon: ':heavy_check_mark:'
    path: datastructure/lazy_segtree.hpp
    title: Lazy Segment Tree (acted monoid wrapper)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/library-checker/range_affine_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n#include\
    \ <atcoder/modint>\n#include <iostream>\n#include <vector>\n\n#line 2 \"algebra/monoid_affine.hpp\"\
    \ntemplate <class T>\nstruct monoid_affine {\n    struct S {\n        T a, b;\n\
    \    };\n    static S op(S f, S g) {\n        return {g.a * f.a, g.a * f.b + g.b};\n\
    \    }\n    static S e() {\n        return {T(1), T(0)};\n    }\n    static T\
    \ eval(S f, T x) {\n        return f.a * x + f.b;\n    }\n};\n#line 3 \"algebra/range_affine_range_sum.hpp\"\
    \ntemplate <class T>\nstruct range_affine_range_sum {\n    struct S {\n      \
    \  T sum;\n        int len;\n    };\n    using F = typename monoid_affine<T>::S;\n\
    \    static S op(S a, S b) {\n        return {a.sum + b.sum, a.len + b.len};\n\
    \    }\n    static S e() {\n        return {T(0), 0};\n    }\n    static S mapping(F\
    \ f, S x) {\n        return {f.a * x.sum + f.b * T(x.len), x.len};\n    }\n  \
    \  static F composition(F f, F g) {\n        return monoid_affine<T>::op(g, f);\n\
    \    }\n    static F id() {\n        return monoid_affine<T>::e();\n    }\n  \
    \  static constexpr bool composition_commutative = false;\n    static S from(T\
    \ v) {\n        return {v, 1};\n    }\n};\n#line 2 \"datastructure/lazy_segtree.hpp\"\
    \n#include <atcoder/lazysegtree>\n\n#line 2 \"algebra/concept.hpp\"\n#include\
    \ <concepts>\ntemplate <class M>\nconcept semigroup = requires(typename M::S a,\
    \ typename M::S b) {\n    { M::op(a, b) } -> std::same_as<typename M::S>;\n};\n\
    template <class M>\nconcept monoid = semigroup<M> && requires {\n    { M::e()\
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
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\ntemplate <class\
    \ A>\nconcept beats_acted_monoid = acted_monoid<A> && requires(typename A::S x)\
    \ {\n    { x.fail } -> std::convertible_to<bool>;\n};\n#line 5 \"datastructure/lazy_segtree.hpp\"\
    \ntemplate <acted_monoid A>\nusing lazy_segtree = atcoder::lazy_segtree<typename\
    \ A::S, A::op, A::e, typename A::F, A::mapping, A::composition, A::id>;\n#line\
    \ 8 \"test/library-checker/range_affine_range_sum.test.cpp\"\nusing mint = atcoder::modint998244353;\n\
    int main() {\n    int n, q;\n    std::cin >> n >> q;\n    using A = range_affine_range_sum<mint>;\n\
    \    std::vector<A::S> a(n);\n    for (int i = 0; i < n; i++) {\n        int x;\n\
    \        std::cin >> x;\n        a[i] = A::from(mint::raw(x));\n    }\n    lazy_segtree<A>\
    \ seg(a);\n    while (q--) {\n        int t;\n        std::cin >> t;\n       \
    \ if (t == 0) {\n            int l, r, b, c;\n            std::cin >> l >> r >>\
    \ b >> c;\n            seg.apply(l, r, {mint::raw(b), mint::raw(c)});\n      \
    \  } else {\n            int l, r;\n            std::cin >> l >> r;\n        \
    \    std::cout << seg.prod(l, r).sum.val() << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include <atcoder/modint>\n#include <iostream>\n#include <vector>\n\n#include\
    \ \"algebra/range_affine_range_sum.hpp\"\n#include \"datastructure/lazy_segtree.hpp\"\
    \nusing mint = atcoder::modint998244353;\nint main() {\n    int n, q;\n    std::cin\
    \ >> n >> q;\n    using A = range_affine_range_sum<mint>;\n    std::vector<A::S>\
    \ a(n);\n    for (int i = 0; i < n; i++) {\n        int x;\n        std::cin >>\
    \ x;\n        a[i] = A::from(mint::raw(x));\n    }\n    lazy_segtree<A> seg(a);\n\
    \    while (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int l, r, b, c;\n            std::cin >> l >> r >> b >> c;\n\
    \            seg.apply(l, r, {mint::raw(b), mint::raw(c)});\n        } else {\n\
    \            int l, r;\n            std::cin >> l >> r;\n            std::cout\
    \ << seg.prod(l, r).sum.val() << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - algebra/range_affine_range_sum.hpp
  - algebra/monoid_affine.hpp
  - datastructure/lazy_segtree.hpp
  - algebra/concept.hpp
  isVerificationFile: true
  path: test/library-checker/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-11-07 14:02:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/range_affine_range_sum.test.cpp
- /verify/test/library-checker/range_affine_range_sum.test.cpp.html
title: test/library-checker/range_affine_range_sum.test.cpp
---
