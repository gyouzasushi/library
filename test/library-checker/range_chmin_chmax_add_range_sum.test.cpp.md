---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  - icon: ':heavy_check_mark:'
    path: algebra/range_chmin_chmax_add_range_sum.hpp
    title: 'Acted Monoid: Range Chmin Chmax Add Range Sum'
  - icon: ':heavy_check_mark:'
    path: datastructure/segtree_beats.hpp
    title: Segment Tree Beats
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/library-checker/range_chmin_chmax_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include <iostream>\n\n#line 2 \"algebra/range_chmin_chmax_add_range_sum.hpp\"\
    \n#include <algorithm>\n#include <limits>\ntemplate <class T>\nstruct range_chmin_chmax_add_range_sum\
    \ {\n    struct S {\n        T sum, min, max, min2, max2;\n        int minc, maxc,\
    \ len;\n        bool fail;\n    };\n    struct F {\n        T add, chmin, chmax;\n\
    \    };\n    static S op(S a, S b) {\n        if (a.len == 0) return b;\n    \
    \    if (b.len == 0) return a;\n        S c;\n        c.sum = a.sum + b.sum;\n\
    \        c.len = a.len + b.len;\n        c.fail = false;\n        if (a.max >\
    \ b.max) {\n            c.max = a.max;\n            c.maxc = a.maxc;\n       \
    \     c.max2 = std::max(a.max2, b.max);\n        } else if (a.max < b.max) {\n\
    \            c.max = b.max;\n            c.maxc = b.maxc;\n            c.max2\
    \ = std::max(a.max, b.max2);\n        } else {\n            c.max = a.max;\n \
    \           c.maxc = a.maxc + b.maxc;\n            c.max2 = std::max(a.max2, b.max2);\n\
    \        }\n        if (a.min < b.min) {\n            c.min = a.min;\n       \
    \     c.minc = a.minc;\n            c.min2 = std::min(a.min2, b.min);\n      \
    \  } else if (a.min > b.min) {\n            c.min = b.min;\n            c.minc\
    \ = b.minc;\n            c.min2 = std::min(a.min, b.min2);\n        } else {\n\
    \            c.min = a.min;\n            c.minc = a.minc + b.minc;\n         \
    \   c.min2 = std::min(a.min2, b.min2);\n        }\n        return c;\n    }\n\
    \    static S e() {\n        return {T(0), inf, ninf, inf, ninf, 0, 0, 0, false};\n\
    \    }\n    static S mapping(F f, S x) {\n        if (x.len == 0) return x;\n\
    \        if (f.add != T(0)) {\n            x.sum += f.add * x.len;\n         \
    \   x.min += f.add;\n            x.max += f.add;\n            if (x.min2 != inf)\
    \ x.min2 += f.add;\n            if (x.max2 != ninf) x.max2 += f.add;\n       \
    \ }\n        if (f.chmin < x.max) {\n            if (f.chmin <= x.min) {\n   \
    \             fill(x, f.chmin);\n            } else if (x.max2 < f.chmin) {\n\
    \                x.sum += (f.chmin - x.max) * x.maxc;\n                if (x.min2\
    \ == x.max) x.min2 = f.chmin;\n                x.max = f.chmin;\n            }\
    \ else {\n                x.fail = true;\n                return x;\n        \
    \    }\n        }\n        if (f.chmax > x.min) {\n            if (f.chmax >=\
    \ x.max) {\n                fill(x, f.chmax);\n            } else if (f.chmax\
    \ < x.min2) {\n                x.sum += (f.chmax - x.min) * x.minc;\n        \
    \        if (x.max2 == x.min) x.max2 = f.chmax;\n                x.min = f.chmax;\n\
    \            } else {\n                x.fail = true;\n            }\n       \
    \ }\n        return x;\n    }\n    static F composition(F f, F g) {\n        T\
    \ chmin = g.chmin == inf ? inf : g.chmin + f.add;\n        T chmax = g.chmax ==\
    \ ninf ? ninf : g.chmax + f.add;\n        return {f.add + g.add, std::min(chmin,\
    \ f.chmin), std::max(std::min(chmax, f.chmin), f.chmax)};\n    }\n    static F\
    \ id() {\n        return {T(0), inf, ninf};\n    }\n    static constexpr bool\
    \ composition_commutative = false;\n    static S from(T v) {\n        return {v,\
    \ v, v, inf, ninf, 1, 1, 1, false};\n    }\n    static F chmin(T x) {\n      \
    \  return {T(0), x, ninf};\n    }\n    static F chmax(T x) {\n        return {T(0),\
    \ inf, x};\n    }\n    static F add(T x) {\n        return {x, inf, ninf};\n \
    \   }\n    static F assign(T x) {\n        return {T(0), x, x};\n    }\n\nprivate:\n\
    \    static constexpr T inf = std::numeric_limits<T>::max();\n    static constexpr\
    \ T ninf = std::numeric_limits<T>::lowest();\n    static void fill(S& x, T v)\
    \ {\n        x.sum = v * x.len;\n        x.min = x.max = v;\n        x.min2 =\
    \ inf;\n        x.max2 = ninf;\n        x.minc = x.maxc = x.len;\n    }\n};\n\
    #line 2 \"datastructure/segtree_beats.hpp\"\n#include <bit>\n#include <cassert>\n\
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
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\ntemplate <class\
    \ A>\nconcept beats_acted_monoid = acted_monoid<A> && requires(typename A::S x)\
    \ {\n    { x.fail } -> std::convertible_to<bool>;\n};\n#line 7 \"datastructure/segtree_beats.hpp\"\
    \ntemplate <beats_acted_monoid A> struct segtree_beats {\npublic:\n    using S\
    \ = typename A::S;\n    using F = typename A::F;\n    segtree_beats() : segtree_beats(0)\
    \ {\n    }\n    explicit segtree_beats(int n) : segtree_beats(std::vector<S>(n,\
    \ A::e())) {\n    }\n    explicit segtree_beats(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n        size = int(std::bit_ceil(unsigned(_n)));\n        log = std::countr_zero(unsigned(size));\n\
    \        d = std::vector<S>(2 * size, A::e());\n        lz = std::vector<F>(size,\
    \ A::id());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n      \
    \  for (int i = size - 1; i >= 1; i--) update(i);\n    }\n    void set(int p,\
    \ S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n        for (int i =\
    \ 1; i <= log; i++) update(p >> i);\n    }\n    S get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        return d[p];\n    }\n    S prod(int l, int r) {\n   \
    \     assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return A::e();\n\
    \        l += size;\n        r += size;\n        for (int i = log; i >= 1; i--)\
    \ {\n            if (((l >> i) << i) != l) push(l >> i);\n            if (((r\
    \ >> i) << i) != r) push((r - 1) >> i);\n        }\n        S sml = A::e(), smr\
    \ = A::e();\n        while (l < r) {\n            if (l & 1) sml = A::op(sml,\
    \ d[l++]);\n            if (r & 1) smr = A::op(d[--r], smr);\n            l >>=\
    \ 1;\n            r >>= 1;\n        }\n        return A::op(sml, smr);\n    }\n\
    \    S all_prod() const {\n        return d[1];\n    }\n    void apply(int p,\
    \ F f) {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        d[p] = A::mapping(f, d[p]);\n \
    \       for (int i = 1; i <= log; i++) update(p >> i);\n    }\n    void apply(int\
    \ l, int r, F f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l\
    \ == r) return;\n        l += size;\n        r += size;\n        for (int i =\
    \ log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n \
    \           if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n       \
    \ {\n            int l2 = l, r2 = r;\n            while (l < r) {\n          \
    \      if (l & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2;\n            r = r2;\n        }\n        for (int i = 1; i <=\
    \ log; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n       \
    \     if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n    template\
    \ <bool (*g)(S)> int max_right(int l) {\n        return max_right(l, [](S x) {\
    \ return g(x); });\n    }\n    template <class G> int max_right(int l, G g) {\n\
    \        assert(0 <= l && l <= _n);\n        assert(g(A::e()));\n        if (l\
    \ == _n) return _n;\n        l += size;\n        for (int i = log; i >= 1; i--)\
    \ push(l >> i);\n        S sm = A::e();\n        do {\n            while (l %\
    \ 2 == 0) l >>= 1;\n            if (!g(A::op(sm, d[l]))) {\n                while\
    \ (l < size) {\n                    push(l);\n                    l = (2 * l);\n\
    \                    if (g(A::op(sm, d[l]))) {\n                        sm = A::op(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - size;\n            }\n            sm = A::op(sm,\
    \ d[l]);\n            l++;\n        } while ((l & -l) != l);\n        return _n;\n\
    \    }\n    template <bool (*g)(S)> int min_left(int r) {\n        return min_left(r,\
    \ [](S x) { return g(x); });\n    }\n    template <class G> int min_left(int r,\
    \ G g) {\n        assert(0 <= r && r <= _n);\n        assert(g(A::e()));\n   \
    \     if (r == 0) return 0;\n        r += size;\n        for (int i = log; i >=\
    \ 1; i--) push((r - 1) >> i);\n        S sm = A::e();\n        do {\n        \
    \    r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(A::op(d[r],\
    \ sm))) {\n                while (r < size) {\n                    push(r);\n\
    \                    r = (2 * r + 1);\n                    if (g(A::op(d[r], sm)))\
    \ {\n                        sm = A::op(d[r], sm);\n                        r--;\n\
    \                    }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = A::op(d[r], sm);\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n\nprivate:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    std::vector<F> lz;\n    void update(int k) {\n        d[k] = A::op(d[2\
    \ * k], d[2 * k + 1]);\n    }\n    void all_apply(int k, F f) {\n        d[k]\
    \ = A::mapping(f, d[k]);\n        if (k < size) {\n            lz[k] = A::composition(f,\
    \ lz[k]);\n            if (d[k].fail) {\n                push(k);\n          \
    \      update(k);\n            }\n        }\n    }\n    void push(int k) {\n \
    \       all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n     \
    \   lz[k] = A::id();\n    }\n};\n#line 6 \"test/library-checker/range_chmin_chmax_add_range_sum.test.cpp\"\
    \nint main() {\n    using A = range_chmin_chmax_add_range_sum<long long>;\n  \
    \  int n, q;\n    std::cin >> n >> q;\n    std::vector<A::S> a(n);\n    for (auto&\
    \ x : a) {\n        long long v;\n        std::cin >> v;\n        x = A::from(v);\n\
    \    }\n    segtree_beats<A> seg(a);\n    while (q--) {\n        int t, l, r;\n\
    \        std::cin >> t >> l >> r;\n        if (t == 3) {\n            std::cout\
    \ << seg.prod(l, r).sum << '\\n';\n            continue;\n        }\n        long\
    \ long b;\n        std::cin >> b;\n        if (t == 0) seg.apply(l, r, A::chmin(b));\n\
    \        if (t == 1) seg.apply(l, r, A::chmax(b));\n        if (t == 2) seg.apply(l,\
    \ r, A::add(b));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include <iostream>\n\n#include \"algebra/range_chmin_chmax_add_range_sum.hpp\"\
    \n#include \"datastructure/segtree_beats.hpp\"\nint main() {\n    using A = range_chmin_chmax_add_range_sum<long\
    \ long>;\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<A::S> a(n);\n\
    \    for (auto& x : a) {\n        long long v;\n        std::cin >> v;\n     \
    \   x = A::from(v);\n    }\n    segtree_beats<A> seg(a);\n    while (q--) {\n\
    \        int t, l, r;\n        std::cin >> t >> l >> r;\n        if (t == 3) {\n\
    \            std::cout << seg.prod(l, r).sum << '\\n';\n            continue;\n\
    \        }\n        long long b;\n        std::cin >> b;\n        if (t == 0)\
    \ seg.apply(l, r, A::chmin(b));\n        if (t == 1) seg.apply(l, r, A::chmax(b));\n\
    \        if (t == 2) seg.apply(l, r, A::add(b));\n    }\n}\n"
  dependsOn:
  - algebra/range_chmin_chmax_add_range_sum.hpp
  - datastructure/segtree_beats.hpp
  - algebra/concept.hpp
  isVerificationFile: true
  path: test/library-checker/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-29 12:09:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test/library-checker/range_chmin_chmax_add_range_sum.test.cpp.html
title: test/library-checker/range_chmin_chmax_add_range_sum.test.cpp
---
