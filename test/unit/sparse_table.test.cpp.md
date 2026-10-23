---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
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
    path: datastructure/plus_minus_one_rmq.hpp
    title: Plus Minus One RMQ
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unit/sparse_table.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <numeric>\n\
    #include <random>\n#include <vector>\n\n#line 3 \"datastructure/plus_minus_one_rmq.hpp\"\
    \n#include <bit>\n#line 6 \"datastructure/plus_minus_one_rmq.hpp\"\n\n#line 6\
    \ \"datastructure/sparse_table.hpp\"\n\n#line 2 \"algebra/concept.hpp\"\n#include\
    \ <concepts>\ntemplate <class M>\nconcept semigroup = requires(typename M::S a,\
    \ typename M::S b) {\n    { M::op(a, b) } -> std::same_as<typename M::S>;\n};\n\
    template <class M>\nconcept monoid = semigroup<M> && requires {\n    { M::e()\
    \ } -> std::same_as<typename M::S>;\n};\ntemplate <class A>\nconcept action =\
    \ requires(typename A::F f, typename A::F g) {\n    { A::composition(f, g) } ->\
    \ std::same_as<typename A::F>;\n    { A::id() } -> std::same_as<typename A::F>;\n\
    \    { A::composition_commutative } -> std::convertible_to<bool>;\n};\ntemplate\
    \ <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
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
    \ t;\n};\n#line 2 \"algebra/monoid_argmin.hpp\"\n#include <limits>\ntemplate <class\
    \ T>\nstruct monoid_argmin {\n    struct S {\n        T val;\n        int id;\n\
    \    };\n    static S op(S a, S b) {\n        if (a.val != b.val) return a.val\
    \ < b.val ? a : b;\n        return a.id < b.id ? a : b;\n    }\n    static S e()\
    \ {\n        return {std::numeric_limits<T>::max(), -1};\n    }\n};\n#line 9 \"\
    datastructure/plus_minus_one_rmq.hpp\"\nstruct plus_minus_one_rmq {\npublic:\n\
    \    plus_minus_one_rmq() : _n(0), s(1), B(0) {\n    }\n    explicit plus_minus_one_rmq(const\
    \ std::vector<int>& a) : _n(int(a.size())), v(a) {\n        s = std::max(1, (std::bit_width((unsigned)_n)\
    \ - 1) / 2);\n        B = (_n + s - 1) / s;\n        std::vector<monoid_argmin<int>::S>\
    \ blocks(B);\n        pattern.resize(B);\n        for (int i = 0; i < _n; i +=\
    \ s) {\n            int min_j = i;\n            int bit = 0;\n            int\
    \ end = std::min(_n, i + s);\n            for (int j = i; j < end; j++) {\n  \
    \              if (v[j] < v[min_j]) min_j = j;\n                if (j + 1 < end\
    \ && v[j] < v[j + 1]) bit |= 1 << (j - i);\n            }\n            blocks[i\
    \ / s] = {v[min_j], min_j};\n            pattern[i / s] = bit;\n        }\n  \
    \      table = sparse_table<monoid_argmin<int>>(blocks);\n        lookup.resize(1\
    \ << (s - 1));\n        for (int bit = 0; bit < (1 << (s - 1)); bit++) {\n   \
    \         lookup[bit].resize(s + 1);\n            for (int l = 0; l <= s; l++)\
    \ {\n                lookup[bit][l].assign(s + 1, INF);\n                int min_sum\
    \ = 0, min_i = l, sum = 0;\n                for (int r = l + 1; r <= s; r++) {\n\
    \                    lookup[bit][l][r] = min_i;\n                    sum += bit\
    \ >> (r - 1) & 1 ? 1 : -1;\n                    if (sum < min_sum) {\n       \
    \                 min_sum = sum;\n                        min_i = r;\n       \
    \             }\n                }\n            }\n        }\n    }\n    int prod(int\
    \ l, int r) const {\n        assert(0 <= l && l < r && r <= _n);\n        int\
    \ m1 = (l + s - 1) / s, m2 = r / s;\n        int l1 = s * m1, r1 = s * m2;\n \
    \       if (m2 < m1) return lookup[pattern[m2]][l - r1][r - r1] + r1;\n      \
    \  int ret = INF;\n        if (m1 > 0) ret = argmin(ret, lookup[pattern[m1 - 1]][s\
    \ - (l1 - l)][s] + l1 - s);\n        if (m1 < m2) ret = argmin(ret, table.prod(m1,\
    \ m2).id);\n        if (m2 < B) ret = argmin(ret, lookup[pattern[m2]][0][r - r1]\
    \ + r1);\n        return ret;\n    }\n\nprivate:\n    static constexpr int INF\
    \ = 1 << 30;\n    int _n, s, B;\n    std::vector<int> v, pattern;\n    sparse_table<monoid_argmin<int>>\
    \ table;\n    std::vector<std::vector<std::vector<int>>> lookup;\n    int argmin(int\
    \ i, int j) const {\n        if (i >= INF) return j;\n        if (j >= INF) return\
    \ i;\n        if (v[i] != v[j]) return v[i] < v[j] ? i : j;\n        return std::min(i,\
    \ j);\n    }\n};\n#line 3 \"algebra/monoid_gcd.hpp\"\ntemplate <class T>\nstruct\
    \ monoid_gcd {\n    using S = T;\n    static S op(S a, S b) {\n        return\
    \ std::gcd(a, b);\n    }\n    static S e() {\n        return T(0);\n    }\n};\n\
    #line 4 \"algebra/monoid_max.hpp\"\ntemplate <class T>\nstruct monoid_max {\n\
    \    using S = T;\n    static S op(S a, S b) {\n        return std::max(a, b);\n\
    \    }\n    static S e() {\n        return std::numeric_limits<T>::lowest();\n\
    \    }\n};\n#line 4 \"algebra/monoid_min.hpp\"\ntemplate <class T>\nstruct monoid_min\
    \ {\n    using S = T;\n    static S op(S a, S b) {\n        return std::min(a,\
    \ b);\n    }\n    static S e() {\n        return std::numeric_limits<T>::max();\n\
    \    }\n};\n#line 15 \"test/unit/sparse_table.test.cpp\"\n// band without identity:\
    \ keep the left operand\nstruct leftmost {\n    using S = int;\n    static S op(S\
    \ a, S) {\n        return a;\n    }\n};\ntemplate <class M, class F> void stress(std::mt19937&\
    \ rng, const F& gen) {\n    using S = typename M::S;\n    int n = 1 + rng() %\
    \ 40;\n    std::vector<S> a(n);\n    for (int i = 0; i < n; i++) a[i] = gen(i);\n\
    \    sparse_table<M> st(a);\n    for (int l = 0; l < n; l++) {\n        for (int\
    \ r = l + 1; r <= n; r++) {\n            S expect = a[l];\n            for (int\
    \ i = l + 1; i < r; i++) expect = M::op(expect, a[i]);\n            assert(st.prod(l,\
    \ r) == expect);\n        }\n    }\n}\nint main() {\n    std::mt19937 rng(99);\n\
    \    for (int it = 0; it < 300; it++) {\n        stress<monoid_min<int>>(rng,\
    \ [&](int) { return int(rng() % 100); });\n        stress<monoid_max<long long>>(rng,\
    \ [&](int) { return (long long)(rng() % 100) - 50; });\n        stress<monoid_gcd<int>>(rng,\
    \ [&](int) { return int(rng() % 60); });\n        stress<leftmost>(rng, [&](int\
    \ i) { return i * 7 % 13; });\n        {\n            int n = 1 + rng() % 40;\n\
    \            std::vector<monoid_argmin<int>::S> a(n);\n            std::vector<int>\
    \ v(n);\n            for (int i = 0; i < n; i++) v[i] = rng() % 5, a[i] = {v[i],\
    \ i};\n            sparse_table<monoid_argmin<int>> st(a);\n            for (int\
    \ l = 0; l < n; l++) {\n                for (int r = l + 1; r <= n; r++) {\n \
    \                   int best = l;\n                    for (int i = l; i < r;\
    \ i++) {\n                        if (v[i] < v[best]) best = i;\n            \
    \        }\n                    assert(st.prod(l, r).id == best && st.prod(l,\
    \ r).val == v[best]);\n                }\n            }\n        }\n        {\n\
    \            int n = 1 + rng() % 70;\n            std::vector<int> v(n);\n   \
    \         v[0] = rng() % 3;\n            for (int i = 1; i < n; i++) v[i] = v[i\
    \ - 1] + (rng() % 2 ? 1 : -1);\n            plus_minus_one_rmq rmq(v);\n     \
    \       for (int l = 0; l < n; l++) {\n                for (int r = l + 1; r <=\
    \ n; r++) {\n                    int best = l;\n                    for (int i\
    \ = l; i < r; i++) {\n                        if (v[i] < v[best]) best = i;\n\
    \                    }\n                    assert(rmq.prod(l, r) == best);\n\
    \                }\n            }\n        }\n    }\n    std::cout << \"Hello\
    \ World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <numeric>\n\
    #include <random>\n#include <vector>\n\n#include \"datastructure/plus_minus_one_rmq.hpp\"\
    \n#include \"datastructure/sparse_table.hpp\"\n#include \"algebra/monoid_argmin.hpp\"\
    \n#include \"algebra/monoid_gcd.hpp\"\n#include \"algebra/monoid_max.hpp\"\n#include\
    \ \"algebra/monoid_min.hpp\"\n// band without identity: keep the left operand\n\
    struct leftmost {\n    using S = int;\n    static S op(S a, S) {\n        return\
    \ a;\n    }\n};\ntemplate <class M, class F> void stress(std::mt19937& rng, const\
    \ F& gen) {\n    using S = typename M::S;\n    int n = 1 + rng() % 40;\n    std::vector<S>\
    \ a(n);\n    for (int i = 0; i < n; i++) a[i] = gen(i);\n    sparse_table<M> st(a);\n\
    \    for (int l = 0; l < n; l++) {\n        for (int r = l + 1; r <= n; r++) {\n\
    \            S expect = a[l];\n            for (int i = l + 1; i < r; i++) expect\
    \ = M::op(expect, a[i]);\n            assert(st.prod(l, r) == expect);\n     \
    \   }\n    }\n}\nint main() {\n    std::mt19937 rng(99);\n    for (int it = 0;\
    \ it < 300; it++) {\n        stress<monoid_min<int>>(rng, [&](int) { return int(rng()\
    \ % 100); });\n        stress<monoid_max<long long>>(rng, [&](int) { return (long\
    \ long)(rng() % 100) - 50; });\n        stress<monoid_gcd<int>>(rng, [&](int)\
    \ { return int(rng() % 60); });\n        stress<leftmost>(rng, [&](int i) { return\
    \ i * 7 % 13; });\n        {\n            int n = 1 + rng() % 40;\n          \
    \  std::vector<monoid_argmin<int>::S> a(n);\n            std::vector<int> v(n);\n\
    \            for (int i = 0; i < n; i++) v[i] = rng() % 5, a[i] = {v[i], i};\n\
    \            sparse_table<monoid_argmin<int>> st(a);\n            for (int l =\
    \ 0; l < n; l++) {\n                for (int r = l + 1; r <= n; r++) {\n     \
    \               int best = l;\n                    for (int i = l; i < r; i++)\
    \ {\n                        if (v[i] < v[best]) best = i;\n                 \
    \   }\n                    assert(st.prod(l, r).id == best && st.prod(l, r).val\
    \ == v[best]);\n                }\n            }\n        }\n        {\n     \
    \       int n = 1 + rng() % 70;\n            std::vector<int> v(n);\n        \
    \    v[0] = rng() % 3;\n            for (int i = 1; i < n; i++) v[i] = v[i - 1]\
    \ + (rng() % 2 ? 1 : -1);\n            plus_minus_one_rmq rmq(v);\n          \
    \  for (int l = 0; l < n; l++) {\n                for (int r = l + 1; r <= n;\
    \ r++) {\n                    int best = l;\n                    for (int i =\
    \ l; i < r; i++) {\n                        if (v[i] < v[best]) best = i;\n  \
    \                  }\n                    assert(rmq.prod(l, r) == best);\n  \
    \              }\n            }\n        }\n    }\n    std::cout << \"Hello World\"\
    \ << std::endl;\n}\n"
  dependsOn:
  - datastructure/plus_minus_one_rmq.hpp
  - datastructure/sparse_table.hpp
  - algebra/concept.hpp
  - algebra/monoid_argmin.hpp
  - algebra/monoid_gcd.hpp
  - algebra/monoid_max.hpp
  - algebra/monoid_min.hpp
  isVerificationFile: true
  path: test/unit/sparse_table.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 22:22:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/unit/sparse_table.test.cpp
- /verify/test/unit/sparse_table.test.cpp.html
title: test/unit/sparse_table.test.cpp
---
