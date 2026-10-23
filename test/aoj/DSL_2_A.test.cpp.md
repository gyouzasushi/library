---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/segtree.hpp
    title: Segment Tree (monoid wrapper)
  - icon: ':heavy_check_mark:'
    path: monoid/concept.hpp
    title: 'Monoid: Concept'
  - icon: ':heavy_check_mark:'
    path: monoid/min.hpp
    title: 'Monoid: Min'
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A
  bundledCode: "#line 1 \"test/aoj/DSL_2_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A\"\
    \n#include <iostream>\n\n#line 2 \"datastructure/segtree.hpp\"\n#include <atcoder/segtree>\n\
    \n#line 2 \"monoid/concept.hpp\"\n#include <concepts>\ntemplate <class M>\nconcept\
    \ semigroup = requires(typename M::S a, typename M::S b) {\n    { M::op(a, b)\
    \ } -> std::same_as<typename M::S>;\n};\ntemplate <class M>\nconcept monoid =\
    \ semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename M::S>;\n\
    };\ntemplate <class A>\nconcept action = requires(typename A::F f, typename A::F\
    \ g) {\n    { A::composition(f, g) } -> std::same_as<typename A::F>;\n    { A::id()\
    \ } -> std::same_as<typename A::F>;\n    { A::composition_commutative } -> std::convertible_to<bool>;\n\
    };\ntemplate <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
    \ A::S x, typename A::F f) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n};\n#line 5 \"datastructure/segtree.hpp\"\ntemplate <monoid M>\nusing\
    \ segtree = atcoder::segtree<typename M::S, M::op, M::e>;\n#line 2 \"monoid/min.hpp\"\
    \n#include <algorithm>\n#include <limits>\ntemplate <class T>\nstruct monoid_min\
    \ {\n    using S = T;\n    static S op(S a, S b) {\n        return std::min(a,\
    \ b);\n    }\n    static S e() {\n        return std::numeric_limits<T>::max();\n\
    \    }\n};\n#line 6 \"test/aoj/DSL_2_A.test.cpp\"\nint main() {\n    int n, q;\n\
    \    std::cin >> n >> q;\n    segtree<monoid_min<int>> seg(n);\n    while (q--)\
    \ {\n        int com, x, y;\n        std::cin >> com >> x >> y;\n        if (com\
    \ == 0) {\n            seg.set(x, y);\n        } else {\n            std::cout\
    \ << seg.prod(x, y + 1) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A\"\n#include\
    \ <iostream>\n\n#include \"datastructure/segtree.hpp\"\n#include \"monoid/min.hpp\"\
    \nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    segtree<monoid_min<int>>\
    \ seg(n);\n    while (q--) {\n        int com, x, y;\n        std::cin >> com\
    \ >> x >> y;\n        if (com == 0) {\n            seg.set(x, y);\n        } else\
    \ {\n            std::cout << seg.prod(x, y + 1) << '\\n';\n        }\n    }\n\
    }\n"
  dependsOn:
  - datastructure/segtree.hpp
  - monoid/concept.hpp
  - monoid/min.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 12:24:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_A.test.cpp
- /verify/test/aoj/DSL_2_A.test.cpp.html
title: test/aoj/DSL_2_A.test.cpp
---
