---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/range_chmin_chmax_add_range_sum.test.cpp
    title: test/library-checker/range_chmin_chmax_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/segtree_beats.test.cpp
    title: test/unit/segtree_beats.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/segtree_beats.hpp\"\n#include <bit>\n#include\
    \ <cassert>\n#include <vector>\n\n#line 2 \"algebra/concept.hpp\"\n#include <concepts>\n\
    template <class M>\nconcept semigroup = requires(typename M::S a, typename M::S\
    \ b) {\n    { M::op(a, b) } -> std::same_as<typename M::S>;\n};\ntemplate <class\
    \ M>\nconcept monoid = semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename\
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
    \   lz[k] = A::id();\n    }\n};\n"
  code: "#pragma once\n#include <bit>\n#include <cassert>\n#include <vector>\n\n#include\
    \ \"algebra/concept.hpp\"\ntemplate <beats_acted_monoid A> struct segtree_beats\
    \ {\npublic:\n    using S = typename A::S;\n    using F = typename A::F;\n   \
    \ segtree_beats() : segtree_beats(0) {\n    }\n    explicit segtree_beats(int\
    \ n) : segtree_beats(std::vector<S>(n, A::e())) {\n    }\n    explicit segtree_beats(const\
    \ std::vector<S>& v) : _n(int(v.size())) {\n        size = int(std::bit_ceil(unsigned(_n)));\n\
    \        log = std::countr_zero(unsigned(size));\n        d = std::vector<S>(2\
    \ * size, A::e());\n        lz = std::vector<F>(size, A::id());\n        for (int\
    \ i = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size - 1; i >=\
    \ 1; i--) update(i);\n    }\n    void set(int p, S x) {\n        assert(0 <= p\
    \ && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >>\
    \ i);\n    }\n    S get(int p) {\n        assert(0 <= p && p < _n);\n        p\
    \ += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        return\
    \ d[p];\n    }\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        if (l == r) return A::e();\n        l += size;\n        r\
    \ += size;\n        for (int i = log; i >= 1; i--) {\n            if (((l >> i)\
    \ << i) != l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n        }\n        S sml = A::e(), smr = A::e();\n        while (l <\
    \ r) {\n            if (l & 1) sml = A::op(sml, d[l++]);\n            if (r &\
    \ 1) smr = A::op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n \
    \       }\n        return A::op(sml, smr);\n    }\n    S all_prod() const {\n\
    \        return d[1];\n    }\n    void apply(int p, F f) {\n        assert(0 <=\
    \ p && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n        d[p] = A::mapping(f, d[p]);\n        for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n    }\n    void apply(int l, int r, F f) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if (l == r) return;\n        l += size;\n\
    \        r += size;\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n        {\n            int l2 = l, r2 = r;\n\
    \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
    \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n   \
    \             r >>= 1;\n            }\n            l = l2;\n            r = r2;\n\
    \        }\n        for (int i = 1; i <= log; i++) {\n            if (((l >> i)\
    \ << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n    template <bool (*g)(S)> int max_right(int\
    \ l) {\n        return max_right(l, [](S x) { return g(x); });\n    }\n    template\
    \ <class G> int max_right(int l, G g) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(g(A::e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        for (int i = log; i >= 1; i--) push(l >> i);\n        S sm = A::e();\n\
    \        do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(A::op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (g(A::op(sm, d[l])))\
    \ {\n                        sm = A::op(sm, d[l]);\n                        l++;\n\
    \                    }\n                }\n                return l - size;\n\
    \            }\n            sm = A::op(sm, d[l]);\n            l++;\n        }\
    \ while ((l & -l) != l);\n        return _n;\n    }\n    template <bool (*g)(S)>\
    \ int min_left(int r) {\n        return min_left(r, [](S x) { return g(x); });\n\
    \    }\n    template <class G> int min_left(int r, G g) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(g(A::e()));\n        if (r == 0) return 0;\n\
    \        r += size;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n\
    \        S sm = A::e();\n        do {\n            r--;\n            while (r\
    \ > 1 && (r % 2)) r >>= 1;\n            if (!g(A::op(d[r], sm))) {\n         \
    \       while (r < size) {\n                    push(r);\n                   \
    \ r = (2 * r + 1);\n                    if (g(A::op(d[r], sm))) {\n          \
    \              sm = A::op(d[r], sm);\n                        r--;\n         \
    \           }\n                }\n                return r + 1 - size;\n     \
    \       }\n            sm = A::op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\nprivate:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    std::vector<F> lz;\n    void update(int k) {\n        d[k] = A::op(d[2\
    \ * k], d[2 * k + 1]);\n    }\n    void all_apply(int k, F f) {\n        d[k]\
    \ = A::mapping(f, d[k]);\n        if (k < size) {\n            lz[k] = A::composition(f,\
    \ lz[k]);\n            if (d[k].fail) {\n                push(k);\n          \
    \      update(k);\n            }\n        }\n    }\n    void push(int k) {\n \
    \       all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n     \
    \   lz[k] = A::id();\n    }\n};\n"
  dependsOn:
  - algebra/concept.hpp
  isVerificationFile: false
  path: datastructure/segtree_beats.hpp
  requiredBy: []
  timestamp: '2026-10-29 12:09:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/segtree_beats.test.cpp
  - test/library-checker/range_chmin_chmax_add_range_sum.test.cpp
documentation_of: datastructure/segtree_beats.hpp
layout: document
title: Segment Tree Beats
---

### 概要
- `mapping` が失敗を返せる遅延セグメント木。失敗したノードは子に作用を押し下げて計算し直す。

### 使い方
- `segtree_beats<A>`: `A` は `lazy_segtree<A>` と同じ構造体で、`S` が `bool fail` を持つもの。
- `mapping(f, x)` は `x` から結果が計算できないときだけ `fail = true` の `S` を返す。要素 1 個の `S` では必ず計算できる。`op`, `e()` が返す `S` は `fail = false`。
- 以降は `atcoder::lazy_segtree` と同じ。

### 計算量
- `mapping` が失敗する回数の合計を $K$ として、全体で $\mathcal{O}((N + Q + K) \log N)$
- `range_chmin_chmax_add_range_sum`: $K = \mathcal{O}((N + Q) \log N)$
