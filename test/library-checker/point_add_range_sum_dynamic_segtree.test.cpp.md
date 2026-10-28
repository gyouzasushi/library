---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  - icon: ':question:'
    path: algebra/monoid_add.hpp
    title: 'Monoid: Add'
  - icon: ':x:'
    path: datastructure/dynamic_segtree.hpp
    title: Dynamic Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/library-checker/point_add_range_sum_dynamic_segtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include\
    \ <iostream>\n\n#line 2 \"algebra/monoid_add.hpp\"\ntemplate <class T>\nstruct\
    \ monoid_add {\n    using S = T;\n    static S op(S a, S b) {\n        return\
    \ a + b;\n    }\n    static S e() {\n        return T(0);\n    }\n};\n#line 2\
    \ \"datastructure/dynamic_segtree.hpp\"\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"algebra/concept.hpp\"\n#include <concepts>\ntemplate\
    \ <class M>\nconcept semigroup = requires(typename M::S a, typename M::S b) {\n\
    \    { M::op(a, b) } -> std::same_as<typename M::S>;\n};\ntemplate <class M>\n\
    concept monoid = semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename\
    \ M::S>;\n};\ntemplate <class G>\nconcept group = monoid<G> && requires(typename\
    \ G::S a) {\n    { G::inv(a) } -> std::same_as<typename G::S>;\n};\ntemplate <class\
    \ A>\nconcept action = requires(typename A::F f, typename A::F g) {\n    { A::composition(f,\
    \ g) } -> std::same_as<typename A::F>;\n    { A::id() } -> std::same_as<typename\
    \ A::F>;\n    { A::composition_commutative } -> std::convertible_to<bool>;\n};\n\
    template <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
    \ A::S x, typename A::F f) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n};\ntemplate <class R>\nconcept semiring = requires(typename R::S a,\
    \ typename R::S b) {\n    { R::add(a, b) } -> std::same_as<typename R::S>;\n \
    \   { R::zero() } -> std::same_as<typename R::S>;\n    { R::mul(a, b) } -> std::same_as<typename\
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\n#line 7 \"datastructure/dynamic_segtree.hpp\"\
    \ntemplate <monoid M> struct dynamic_segtree {\npublic:\n    using S = typename\
    \ M::S;\n    explicit dynamic_segtree(long long lo = -(1LL << 62), long long hi\
    \ = 1LL << 62) : lo(lo), hi(hi) {\n        assert(lo < hi);\n    }\n    void set(long\
    \ long p, S x) {\n        assert(lo <= p && p < hi);\n        root = set(root,\
    \ lo, hi, p, x);\n    }\n    S get(long long p) const {\n        assert(lo <=\
    \ p && p < hi);\n        int t = root;\n        long long a = lo, b = hi;\n  \
    \      while (t != -1) {\n            if (nodes[t].idx == p) return nodes[t].val;\n\
    \            long long c = mid(a, b);\n            if (p < c) {\n            \
    \    t = nodes[t].l, b = c;\n            } else {\n                t = nodes[t].r,\
    \ a = c;\n            }\n        }\n        return M::e();\n    }\n    S prod(long\
    \ long l, long long r) const {\n        assert(lo <= l && l <= r && r <= hi);\n\
    \        return prod(root, lo, hi, l, r);\n    }\n    S all_prod() const {\n \
    \       return root == -1 ? M::e() : nodes[root].prod;\n    }\n    template <bool\
    \ (*f)(S)> long long max_right(long long l) const {\n        return max_right(l,\
    \ [](S x) { return f(x); });\n    }\n    template <class F> long long max_right(long\
    \ long l, F f) const {\n        assert(lo <= l && l <= hi);\n        S product\
    \ = M::e();\n        assert(f(product));\n        return max_right(root, lo, hi,\
    \ l, f, product);\n    }\n    template <bool (*f)(S)> long long min_left(long\
    \ long r) const {\n        return min_left(r, [](S x) { return f(x); });\n   \
    \ }\n    template <class F> long long min_left(long long r, F f) const {\n   \
    \     assert(lo <= r && r <= hi);\n        S product = M::e();\n        assert(f(product));\n\
    \        return min_left(root, lo, hi, r, f, product);\n    }\n\nprivate:\n  \
    \  struct node {\n        long long idx;\n        S val, prod;\n        int l\
    \ = -1, r = -1;\n    };\n    long long lo, hi;\n    int root = -1;\n    std::vector<node>\
    \ nodes;\n    static long long mid(long long a, long long b) {\n        return\
    \ a + (long long)(((unsigned long long)b - (unsigned long long)a) / 2);\n    }\n\
    \    void update(int t) {\n        node& v = nodes[t];\n        S res = v.l ==\
    \ -1 ? v.val : M::op(nodes[v.l].prod, v.val);\n        v.prod = v.r == -1 ? res\
    \ : M::op(res, nodes[v.r].prod);\n    }\n    int set(int t, long long a, long\
    \ long b, long long p, S x) {\n        if (t == -1) {\n            nodes.push_back({p,\
    \ x, x});\n            return int(nodes.size()) - 1;\n        }\n        if (nodes[t].idx\
    \ == p) {\n            nodes[t].val = x;\n            update(t);\n           \
    \ return t;\n        }\n        long long c = mid(a, b);\n        if (p < c) {\n\
    \            if (nodes[t].idx < p) std::swap(nodes[t].idx, p), std::swap(nodes[t].val,\
    \ x);\n            int child = set(nodes[t].l, a, c, p, x);\n            nodes[t].l\
    \ = child;\n        } else {\n            if (p < nodes[t].idx) std::swap(nodes[t].idx,\
    \ p), std::swap(nodes[t].val, x);\n            int child = set(nodes[t].r, c,\
    \ b, p, x);\n            nodes[t].r = child;\n        }\n        update(t);\n\
    \        return t;\n    }\n    S prod(int t, long long a, long long b, long long\
    \ l, long long r) const {\n        if (t == -1 || b <= l || r <= a) return M::e();\n\
    \        const node& v = nodes[t];\n        if (l <= a && b <= r) return v.prod;\n\
    \        long long c = mid(a, b);\n        S res = prod(v.l, a, c, l, r);\n  \
    \      if (l <= v.idx && v.idx < r) res = M::op(res, v.val);\n        return M::op(res,\
    \ prod(v.r, c, b, l, r));\n    }\n    template <class F>\n    long long max_right(int\
    \ t, long long a, long long b, long long l, const F& f, S& product) const {\n\
    \        if (t == -1 || b <= l) return hi;\n        const node& v = nodes[t];\n\
    \        if (l <= a && f(M::op(product, v.prod))) {\n            product = M::op(product,\
    \ v.prod);\n            return hi;\n        }\n        long long c = mid(a, b);\n\
    \        long long res = max_right(v.l, a, c, l, f, product);\n        if (res\
    \ != hi) return res;\n        if (l <= v.idx) {\n            product = M::op(product,\
    \ v.val);\n            if (!f(product)) return v.idx;\n        }\n        return\
    \ max_right(v.r, c, b, l, f, product);\n    }\n    template <class F>\n    long\
    \ long min_left(int t, long long a, long long b, long long r, const F& f, S& product)\
    \ const {\n        if (t == -1 || r <= a) return lo;\n        const node& v =\
    \ nodes[t];\n        if (b <= r && f(M::op(v.prod, product))) {\n            product\
    \ = M::op(v.prod, product);\n            return lo;\n        }\n        long long\
    \ c = mid(a, b);\n        long long res = min_left(v.r, c, b, r, f, product);\n\
    \        if (res != lo) return res;\n        if (v.idx < r) {\n            product\
    \ = M::op(v.val, product);\n            if (!f(product)) return v.idx + 1;\n \
    \       }\n        return min_left(v.l, a, c, r, f, product);\n    }\n};\n#line\
    \ 6 \"test/library-checker/point_add_range_sum_dynamic_segtree.test.cpp\"\nint\
    \ main() {\n    int n, q;\n    std::cin >> n >> q;\n    dynamic_segtree<monoid_add<long\
    \ long>> seg;\n    for (int i = 0; i < n; i++) {\n        long long a;\n     \
    \   std::cin >> a;\n        seg.set(i, a);\n    }\n    while (q--) {\n       \
    \ int t;\n        std::cin >> t;\n        if (t == 0) {\n            int p;\n\
    \            long long x;\n            std::cin >> p >> x;\n            seg.set(p,\
    \ seg.get(p) + x);\n        }\n        if (t == 1) {\n            int l, r;\n\
    \            std::cin >> l >> r;\n            std::cout << seg.prod(l, r) << '\\\
    n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <iostream>\n\n#include \"algebra/monoid_add.hpp\"\n#include \"datastructure/dynamic_segtree.hpp\"\
    \nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    dynamic_segtree<monoid_add<long\
    \ long>> seg;\n    for (int i = 0; i < n; i++) {\n        long long a;\n     \
    \   std::cin >> a;\n        seg.set(i, a);\n    }\n    while (q--) {\n       \
    \ int t;\n        std::cin >> t;\n        if (t == 0) {\n            int p;\n\
    \            long long x;\n            std::cin >> p >> x;\n            seg.set(p,\
    \ seg.get(p) + x);\n        }\n        if (t == 1) {\n            int l, r;\n\
    \            std::cin >> l >> r;\n            std::cout << seg.prod(l, r) << '\\\
    n';\n        }\n    }\n}\n"
  dependsOn:
  - algebra/monoid_add.hpp
  - datastructure/dynamic_segtree.hpp
  - algebra/concept.hpp
  isVerificationFile: true
  path: test/library-checker/point_add_range_sum_dynamic_segtree.test.cpp
  requiredBy: []
  timestamp: '2026-10-28 22:07:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/point_add_range_sum_dynamic_segtree.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/point_add_range_sum_dynamic_segtree.test.cpp
- /verify/test/library-checker/point_add_range_sum_dynamic_segtree.test.cpp.html
title: test/library-checker/point_add_range_sum_dynamic_segtree.test.cpp
---
