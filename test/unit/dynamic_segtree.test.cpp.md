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
    path: algebra/monoid_max.hpp
    title: 'Monoid: Max'
  - icon: ':heavy_check_mark:'
    path: datastructure/dynamic_segtree.hpp
    title: Dynamic Segment Tree
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
  bundledCode: "#line 1 \"test/unit/dynamic_segtree.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <cassert>\n#include <iostream>\n#include <map>\n#include <random>\n#include\
    \ <vector>\n\n#line 2 \"algebra/monoid_add.hpp\"\ntemplate <class T>\nstruct monoid_add\
    \ {\n    using S = T;\n    static S op(S a, S b) {\n        return a + b;\n  \
    \  }\n    static S e() {\n        return T(0);\n    }\n};\n#line 2 \"algebra/monoid_affine.hpp\"\
    \ntemplate <class T>\nstruct monoid_affine {\n    struct S {\n        T a, b;\n\
    \    };\n    static S op(S f, S g) {\n        return {g.a * f.a, g.a * f.b + g.b};\n\
    \    }\n    static S e() {\n        return {T(1), T(0)};\n    }\n    static T\
    \ eval(S f, T x) {\n        return f.a * x + f.b;\n    }\n};\n#line 2 \"algebra/monoid_max.hpp\"\
    \n#include <algorithm>\n#include <limits>\ntemplate <class T>\nstruct monoid_max\
    \ {\n    using S = T;\n    static S op(S a, S b) {\n        return std::max(a,\
    \ b);\n    }\n    static S e() {\n        return std::numeric_limits<T>::lowest();\n\
    \    }\n};\n#line 3 \"datastructure/dynamic_segtree.hpp\"\n#include <utility>\n\
    #line 5 \"datastructure/dynamic_segtree.hpp\"\n\n#line 2 \"algebra/concept.hpp\"\
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
    \ 12 \"test/unit/dynamic_segtree.test.cpp\"\nbool at_most_10(long long x) {\n\
    \    return x <= 10;\n}\nvoid stress_small(std::mt19937& rng) {\n    const long\
    \ long lo = -(long long)(rng() % 20), hi = lo + 1 + rng() % 40;\n    const long\
    \ long n = hi - lo;\n    std::vector<long long> a(n, 0);\n    dynamic_segtree<monoid_add<long\
    \ long>> seg(lo, hi);\n    for (int it = 0; it < 300; it++) {\n        int type\
    \ = rng() % 5;\n        if (type == 0) {\n            long long p = lo + rng()\
    \ % n;\n            long long x = rng() % 5;\n            a[p - lo] = x;\n   \
    \         seg.set(p, x);\n        } else if (type == 1) {\n            long long\
    \ p = lo + rng() % n;\n            assert(seg.get(p) == a[p - lo]);\n        }\
    \ else if (type == 2) {\n            long long l = lo + rng() % (n + 1), r = lo\
    \ + rng() % (n + 1);\n            if (l > r) std::swap(l, r);\n            long\
    \ long expect = 0;\n            for (long long i = l; i < r; i++) expect += a[i\
    \ - lo];\n            assert(seg.prod(l, r) == expect);\n        } else if (type\
    \ == 3) {\n            long long l = lo + rng() % (n + 1);\n            long long\
    \ k = rng() % 15;\n            long long r = l, sum = 0;\n            while (r\
    \ < hi && sum + a[r - lo] <= k) sum += a[r - lo], r++;\n            assert(seg.max_right(l,\
    \ [&](long long x) { return x <= k; }) == r);\n            if (k == 10) assert(seg.max_right<at_most_10>(l)\
    \ == r);\n        } else {\n            long long r = lo + rng() % (n + 1);\n\
    \            long long k = rng() % 15;\n            long long l = r, sum = 0;\n\
    \            while (l > lo && sum + a[l - 1 - lo] <= k) sum += a[l - 1 - lo],\
    \ l--;\n            assert(seg.min_left(r, [&](long long x) { return x <= k; })\
    \ == l);\n        }\n    }\n    long long total = 0;\n    for (long long x : a)\
    \ total += x;\n    assert(seg.all_prod() == total);\n}\nvoid stress_wide(std::mt19937&\
    \ rng) {\n    dynamic_segtree<monoid_max<long long>> seg;\n    std::map<long long,\
    \ long long> a;\n    const long long lim = 1LL << 62;\n    for (int it = 0; it\
    \ < 300; it++) {\n        long long p = (long long)(rng() % (2 * (unsigned long\
    \ long)lim)) - lim;\n        if (rng() % 2) p = (long long)(rng() % 100) - 50;\n\
    \        if (rng() % 2) {\n            long long x = rng() % 1000;\n         \
    \   a[p] = x;\n            seg.set(p, x);\n        } else {\n            long\
    \ long q = (long long)(rng() % (2 * (unsigned long long)lim)) - lim;\n       \
    \     long long l = std::min(p, q), r = std::max(p, q) + 1;\n            long\
    \ long expect = monoid_max<long long>::e();\n            for (auto it2 = a.lower_bound(l);\
    \ it2 != a.end() && it2->first < r; ++it2) expect = std::max(expect, it2->second);\n\
    \            assert(seg.prod(l, r) == expect);\n        }\n    }\n}\nvoid stress_noncommutative(std::mt19937&\
    \ rng) {\n    using M = monoid_affine<long long>;\n    const long long n = 1 +\
    \ rng() % 30;\n    std::vector<M::S> a(n, M::e());\n    dynamic_segtree<M> seg(0,\
    \ n);\n    for (int it = 0; it < 200; it++) {\n        if (rng() % 2) {\n    \
    \        long long p = rng() % n;\n            a[p] = {(long long)(rng() % 3),\
    \ (long long)(rng() % 3)};\n            seg.set(p, a[p]);\n        } else {\n\
    \            long long l = rng() % (n + 1), r = rng() % (n + 1);\n           \
    \ if (l > r) std::swap(l, r);\n            M::S expect = M::e();\n           \
    \ for (long long i = l; i < r; i++) expect = M::op(expect, a[i]);\n          \
    \  M::S got = seg.prod(l, r);\n            assert(M::eval(got, 7) == M::eval(expect,\
    \ 7));\n        }\n    }\n}\nint main() {\n    std::mt19937 rng(20261028);\n \
    \   for (int trial = 0; trial < 100; trial++) {\n        stress_small(rng);\n\
    \        stress_wide(rng);\n        stress_noncommutative(rng);\n    }\n    std::cout\
    \ << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <map>\n#include <random>\n\
    #include <vector>\n\n#include \"algebra/monoid_add.hpp\"\n#include \"algebra/monoid_affine.hpp\"\
    \n#include \"algebra/monoid_max.hpp\"\n#include \"datastructure/dynamic_segtree.hpp\"\
    \nbool at_most_10(long long x) {\n    return x <= 10;\n}\nvoid stress_small(std::mt19937&\
    \ rng) {\n    const long long lo = -(long long)(rng() % 20), hi = lo + 1 + rng()\
    \ % 40;\n    const long long n = hi - lo;\n    std::vector<long long> a(n, 0);\n\
    \    dynamic_segtree<monoid_add<long long>> seg(lo, hi);\n    for (int it = 0;\
    \ it < 300; it++) {\n        int type = rng() % 5;\n        if (type == 0) {\n\
    \            long long p = lo + rng() % n;\n            long long x = rng() %\
    \ 5;\n            a[p - lo] = x;\n            seg.set(p, x);\n        } else if\
    \ (type == 1) {\n            long long p = lo + rng() % n;\n            assert(seg.get(p)\
    \ == a[p - lo]);\n        } else if (type == 2) {\n            long long l = lo\
    \ + rng() % (n + 1), r = lo + rng() % (n + 1);\n            if (l > r) std::swap(l,\
    \ r);\n            long long expect = 0;\n            for (long long i = l; i\
    \ < r; i++) expect += a[i - lo];\n            assert(seg.prod(l, r) == expect);\n\
    \        } else if (type == 3) {\n            long long l = lo + rng() % (n +\
    \ 1);\n            long long k = rng() % 15;\n            long long r = l, sum\
    \ = 0;\n            while (r < hi && sum + a[r - lo] <= k) sum += a[r - lo], r++;\n\
    \            assert(seg.max_right(l, [&](long long x) { return x <= k; }) == r);\n\
    \            if (k == 10) assert(seg.max_right<at_most_10>(l) == r);\n       \
    \ } else {\n            long long r = lo + rng() % (n + 1);\n            long\
    \ long k = rng() % 15;\n            long long l = r, sum = 0;\n            while\
    \ (l > lo && sum + a[l - 1 - lo] <= k) sum += a[l - 1 - lo], l--;\n          \
    \  assert(seg.min_left(r, [&](long long x) { return x <= k; }) == l);\n      \
    \  }\n    }\n    long long total = 0;\n    for (long long x : a) total += x;\n\
    \    assert(seg.all_prod() == total);\n}\nvoid stress_wide(std::mt19937& rng)\
    \ {\n    dynamic_segtree<monoid_max<long long>> seg;\n    std::map<long long,\
    \ long long> a;\n    const long long lim = 1LL << 62;\n    for (int it = 0; it\
    \ < 300; it++) {\n        long long p = (long long)(rng() % (2 * (unsigned long\
    \ long)lim)) - lim;\n        if (rng() % 2) p = (long long)(rng() % 100) - 50;\n\
    \        if (rng() % 2) {\n            long long x = rng() % 1000;\n         \
    \   a[p] = x;\n            seg.set(p, x);\n        } else {\n            long\
    \ long q = (long long)(rng() % (2 * (unsigned long long)lim)) - lim;\n       \
    \     long long l = std::min(p, q), r = std::max(p, q) + 1;\n            long\
    \ long expect = monoid_max<long long>::e();\n            for (auto it2 = a.lower_bound(l);\
    \ it2 != a.end() && it2->first < r; ++it2) expect = std::max(expect, it2->second);\n\
    \            assert(seg.prod(l, r) == expect);\n        }\n    }\n}\nvoid stress_noncommutative(std::mt19937&\
    \ rng) {\n    using M = monoid_affine<long long>;\n    const long long n = 1 +\
    \ rng() % 30;\n    std::vector<M::S> a(n, M::e());\n    dynamic_segtree<M> seg(0,\
    \ n);\n    for (int it = 0; it < 200; it++) {\n        if (rng() % 2) {\n    \
    \        long long p = rng() % n;\n            a[p] = {(long long)(rng() % 3),\
    \ (long long)(rng() % 3)};\n            seg.set(p, a[p]);\n        } else {\n\
    \            long long l = rng() % (n + 1), r = rng() % (n + 1);\n           \
    \ if (l > r) std::swap(l, r);\n            M::S expect = M::e();\n           \
    \ for (long long i = l; i < r; i++) expect = M::op(expect, a[i]);\n          \
    \  M::S got = seg.prod(l, r);\n            assert(M::eval(got, 7) == M::eval(expect,\
    \ 7));\n        }\n    }\n}\nint main() {\n    std::mt19937 rng(20261028);\n \
    \   for (int trial = 0; trial < 100; trial++) {\n        stress_small(rng);\n\
    \        stress_wide(rng);\n        stress_noncommutative(rng);\n    }\n    std::cout\
    \ << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - algebra/monoid_add.hpp
  - algebra/monoid_affine.hpp
  - algebra/monoid_max.hpp
  - datastructure/dynamic_segtree.hpp
  - algebra/concept.hpp
  isVerificationFile: true
  path: test/unit/dynamic_segtree.test.cpp
  requiredBy: []
  timestamp: '2026-10-28 22:07:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/dynamic_segtree.test.cpp
layout: document
redirect_from:
- /verify/test/unit/dynamic_segtree.test.cpp
- /verify/test/unit/dynamic_segtree.test.cpp.html
title: test/unit/dynamic_segtree.test.cpp
---
