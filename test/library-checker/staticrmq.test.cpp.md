---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_min.hpp
    title: 'Monoid: Min'
  - icon: ':heavy_check_mark:'
    path: datastructure/sparse_table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/library-checker/staticrmq.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <iostream>\n#include\
    \ <vector>\n\n#line 2 \"datastructure/sparse_table.hpp\"\n#include <algorithm>\n\
    #include <bit>\n#include <cassert>\n#line 6 \"datastructure/sparse_table.hpp\"\
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
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\n#line 8 \"datastructure/sparse_table.hpp\"\
    \ntemplate <semigroup M> struct sparse_table {\n    using S = typename M::S;\n\
    \    sparse_table() : _n(0) {\n    }\n    explicit sparse_table(const std::vector<S>&\
    \ a) : _n(int(a.size())) {\n        int log = std::max(1, std::bit_width((unsigned)_n));\n\
    \        t.resize(log);\n        t[0] = a;\n        for (int k = 1; k < log; k++)\
    \ {\n            t[k].resize(_n - (1 << k) + 1);\n            for (int i = 0;\
    \ i + (1 << k) <= _n; i++) {\n                t[k][i] = M::op(t[k - 1][i], t[k\
    \ - 1][i + (1 << (k - 1))]);\n            }\n        }\n    }\n    S prod(int\
    \ l, int r) const {\n        assert(0 <= l && l < r && r <= _n);\n        int\
    \ k = std::bit_width((unsigned)(r - l)) - 1;\n        return M::op(t[k][l], t[k][r\
    \ - (1 << k)]);\n    }\n\nprivate:\n    int _n;\n    std::vector<std::vector<S>>\
    \ t;\n};\n#line 3 \"algebra/monoid_min.hpp\"\n#include <limits>\ntemplate <class\
    \ T>\nstruct monoid_min {\n    using S = T;\n    static S op(S a, S b) {\n   \
    \     return std::min(a, b);\n    }\n    static S e() {\n        return std::numeric_limits<T>::max();\n\
    \    }\n};\n#line 7 \"test/library-checker/staticrmq.test.cpp\"\nint main() {\n\
    \    int n, q;\n    std::cin >> n >> q;\n    std::vector<int> a(n);\n    for (int&\
    \ x : a) std::cin >> x;\n    sparse_table<monoid_min<int>> st(a);\n    while (q--)\
    \ {\n        int l, r;\n        std::cin >> l >> r;\n        std::cout << st.prod(l,\
    \ r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <iostream>\n\
    #include <vector>\n\n#include \"datastructure/sparse_table.hpp\"\n#include \"\
    algebra/monoid_min.hpp\"\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\
    \    std::vector<int> a(n);\n    for (int& x : a) std::cin >> x;\n    sparse_table<monoid_min<int>>\
    \ st(a);\n    while (q--) {\n        int l, r;\n        std::cin >> l >> r;\n\
    \        std::cout << st.prod(l, r) << '\\n';\n    }\n}\n"
  dependsOn:
  - datastructure/sparse_table.hpp
  - algebra/concept.hpp
  - algebra/monoid_min.hpp
  isVerificationFile: true
  path: test/library-checker/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 01:30:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/staticrmq.test.cpp
- /verify/test/library-checker/staticrmq.test.cpp.html
title: test/library-checker/staticrmq.test.cpp
---
