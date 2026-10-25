---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  - icon: ':question:'
    path: algebra/range_add_range_sum.hpp
    title: 'Acted Monoid: Range Add Range Sum'
  - icon: ':question:'
    path: datastructure/lazy_segtree.hpp
    title: Lazy Segment Tree (acted monoid wrapper)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G
  bundledCode: "#line 1 \"test/aoj/DSL_2_G.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G\"\
    \n#include <iostream>\n#include <vector>\n\n#line 2 \"algebra/range_add_range_sum.hpp\"\
    \ntemplate <class T>\nstruct range_add_range_sum {\n    struct S {\n        T\
    \ sum;\n        int len;\n    };\n    using F = T;\n    static S op(S a, S b)\
    \ {\n        return {a.sum + b.sum, a.len + b.len};\n    }\n    static S e() {\n\
    \        return {T(0), 0};\n    }\n    static S mapping(F f, S x) {\n        return\
    \ {x.sum + f * x.len, x.len};\n    }\n    static F composition(F f, F g) {\n \
    \       return f + g;\n    }\n    static F id() {\n        return T(0);\n    }\n\
    \    static constexpr bool composition_commutative = true;\n    static S from(T\
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
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\n#line 5 \"datastructure/lazy_segtree.hpp\"\
    \ntemplate <acted_monoid A>\nusing lazy_segtree = atcoder::lazy_segtree<typename\
    \ A::S, A::op, A::e, typename A::F, A::mapping, A::composition, A::id>;\n#line\
    \ 7 \"test/aoj/DSL_2_G.test.cpp\"\nint main() {\n    int n, q;\n    std::cin >>\
    \ n >> q;\n    using A = range_add_range_sum<long long>;\n    lazy_segtree<A>\
    \ seg(std::vector<A::S>(n, A::from(0)));\n    while (q--) {\n        int t;\n\
    \        std::cin >> t;\n        if (t == 0) {\n            int s, e;\n      \
    \      long long x;\n            std::cin >> s >> e >> x;\n            seg.apply(s\
    \ - 1, e, x);\n        } else {\n            int s, e;\n            std::cin >>\
    \ s >> e;\n            std::cout << seg.prod(s - 1, e).sum << '\\n';\n       \
    \ }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G\"\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"algebra/range_add_range_sum.hpp\"\
    \n#include \"datastructure/lazy_segtree.hpp\"\nint main() {\n    int n, q;\n \
    \   std::cin >> n >> q;\n    using A = range_add_range_sum<long long>;\n    lazy_segtree<A>\
    \ seg(std::vector<A::S>(n, A::from(0)));\n    while (q--) {\n        int t;\n\
    \        std::cin >> t;\n        if (t == 0) {\n            int s, e;\n      \
    \      long long x;\n            std::cin >> s >> e >> x;\n            seg.apply(s\
    \ - 1, e, x);\n        } else {\n            int s, e;\n            std::cin >>\
    \ s >> e;\n            std::cout << seg.prod(s - 1, e).sum << '\\n';\n       \
    \ }\n    }\n}\n"
  dependsOn:
  - algebra/range_add_range_sum.hpp
  - datastructure/lazy_segtree.hpp
  - algebra/concept.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_G.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 01:30:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_G.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_G.test.cpp
- /verify/test/aoj/DSL_2_G.test.cpp.html
title: test/aoj/DSL_2_G.test.cpp
---
