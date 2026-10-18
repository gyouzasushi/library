---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: acted_monoid/range_add_range_sum.hpp
    title: 'Acted Monoid: Range Add Range Sum'
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G
  bundledCode: "#line 1 \"test/aoj/DSL_2_G.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G\"\
    \n#include <iostream>\n#include <vector>\n\n#line 2 \"acted_monoid/range_add_range_sum.hpp\"\
    \ntemplate <class T>\nstruct range_add_range_sum {\n    struct S {\n        T\
    \ sum;\n        int len;\n    };\n    using F = T;\n    static S op(S a, S b)\
    \ {\n        return {a.sum + b.sum, a.len + b.len};\n    }\n    static S e() {\n\
    \        return {T(0), 0};\n    }\n    static S mapping(F f, S x) {\n        return\
    \ {x.sum + f * x.len, x.len};\n    }\n    static F composition(F f, F g) {\n \
    \       return f + g;\n    }\n    static F id() {\n        return T(0);\n    }\n\
    \    static S from(T v) {\n        return {v, 1};\n    }\n};\n#line 2 \"datastructure/lazy_segtree.hpp\"\
    \n#include <atcoder/lazysegtree>\ntemplate <class A>\nusing lazy_segtree = atcoder::lazy_segtree<typename\
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
    \ <iostream>\n#include <vector>\n\n#include \"acted_monoid/range_add_range_sum.hpp\"\
    \n#include \"datastructure/lazy_segtree.hpp\"\nint main() {\n    int n, q;\n \
    \   std::cin >> n >> q;\n    using A = range_add_range_sum<long long>;\n    lazy_segtree<A>\
    \ seg(std::vector<A::S>(n, A::from(0)));\n    while (q--) {\n        int t;\n\
    \        std::cin >> t;\n        if (t == 0) {\n            int s, e;\n      \
    \      long long x;\n            std::cin >> s >> e >> x;\n            seg.apply(s\
    \ - 1, e, x);\n        } else {\n            int s, e;\n            std::cin >>\
    \ s >> e;\n            std::cout << seg.prod(s - 1, e).sum << '\\n';\n       \
    \ }\n    }\n}\n"
  dependsOn:
  - acted_monoid/range_add_range_sum.hpp
  - datastructure/lazy_segtree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_G.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 02:48:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_G.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_G.test.cpp
- /verify/test/aoj/DSL_2_G.test.cpp.html
title: test/aoj/DSL_2_G.test.cpp
---
