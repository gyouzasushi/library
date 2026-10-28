---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/point_add_range_sum_dynamic_segtree.test.cpp
    title: test/library-checker/point_add_range_sum_dynamic_segtree.test.cpp
  - icon: ':x:'
    path: test/unit/dynamic_segtree.test.cpp
    title: test/unit/dynamic_segtree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/dynamic_segtree.hpp\"\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\n#line 2 \"algebra/concept.hpp\"\n#include\
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
    \       }\n        return min_left(v.l, a, c, r, f, product);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \n#include \"algebra/concept.hpp\"\ntemplate <monoid M> struct dynamic_segtree\
    \ {\npublic:\n    using S = typename M::S;\n    explicit dynamic_segtree(long\
    \ long lo = -(1LL << 62), long long hi = 1LL << 62) : lo(lo), hi(hi) {\n     \
    \   assert(lo < hi);\n    }\n    void set(long long p, S x) {\n        assert(lo\
    \ <= p && p < hi);\n        root = set(root, lo, hi, p, x);\n    }\n    S get(long\
    \ long p) const {\n        assert(lo <= p && p < hi);\n        int t = root;\n\
    \        long long a = lo, b = hi;\n        while (t != -1) {\n            if\
    \ (nodes[t].idx == p) return nodes[t].val;\n            long long c = mid(a, b);\n\
    \            if (p < c) {\n                t = nodes[t].l, b = c;\n          \
    \  } else {\n                t = nodes[t].r, a = c;\n            }\n        }\n\
    \        return M::e();\n    }\n    S prod(long long l, long long r) const {\n\
    \        assert(lo <= l && l <= r && r <= hi);\n        return prod(root, lo,\
    \ hi, l, r);\n    }\n    S all_prod() const {\n        return root == -1 ? M::e()\
    \ : nodes[root].prod;\n    }\n    template <bool (*f)(S)> long long max_right(long\
    \ long l) const {\n        return max_right(l, [](S x) { return f(x); });\n  \
    \  }\n    template <class F> long long max_right(long long l, F f) const {\n \
    \       assert(lo <= l && l <= hi);\n        S product = M::e();\n        assert(f(product));\n\
    \        return max_right(root, lo, hi, l, f, product);\n    }\n    template <bool\
    \ (*f)(S)> long long min_left(long long r) const {\n        return min_left(r,\
    \ [](S x) { return f(x); });\n    }\n    template <class F> long long min_left(long\
    \ long r, F f) const {\n        assert(lo <= r && r <= hi);\n        S product\
    \ = M::e();\n        assert(f(product));\n        return min_left(root, lo, hi,\
    \ r, f, product);\n    }\n\nprivate:\n    struct node {\n        long long idx;\n\
    \        S val, prod;\n        int l = -1, r = -1;\n    };\n    long long lo,\
    \ hi;\n    int root = -1;\n    std::vector<node> nodes;\n    static long long\
    \ mid(long long a, long long b) {\n        return a + (long long)(((unsigned long\
    \ long)b - (unsigned long long)a) / 2);\n    }\n    void update(int t) {\n   \
    \     node& v = nodes[t];\n        S res = v.l == -1 ? v.val : M::op(nodes[v.l].prod,\
    \ v.val);\n        v.prod = v.r == -1 ? res : M::op(res, nodes[v.r].prod);\n \
    \   }\n    int set(int t, long long a, long long b, long long p, S x) {\n    \
    \    if (t == -1) {\n            nodes.push_back({p, x, x});\n            return\
    \ int(nodes.size()) - 1;\n        }\n        if (nodes[t].idx == p) {\n      \
    \      nodes[t].val = x;\n            update(t);\n            return t;\n    \
    \    }\n        long long c = mid(a, b);\n        if (p < c) {\n            if\
    \ (nodes[t].idx < p) std::swap(nodes[t].idx, p), std::swap(nodes[t].val, x);\n\
    \            int child = set(nodes[t].l, a, c, p, x);\n            nodes[t].l\
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
    \       }\n        return min_left(v.l, a, c, r, f, product);\n    }\n};\n"
  dependsOn:
  - algebra/concept.hpp
  isVerificationFile: false
  path: datastructure/dynamic_segtree.hpp
  requiredBy: []
  timestamp: '2026-10-28 22:07:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unit/dynamic_segtree.test.cpp
  - test/library-checker/point_add_range_sum_dynamic_segtree.test.cpp
documentation_of: datastructure/dynamic_segtree.hpp
layout: document
title: Dynamic Segment Tree
---

### 概要
- 添字の範囲が広い列に対する、1 点更新と区間の総積を求めるセグメント木。ノードは `set` した位置の分だけ作る。

### 使い方
- `dynamic_segtree<M>(lo = -2^62, hi = 2^62)`: `M` は `S`, `op`, `e` を static メンバとして持つ構造体。添字 $[\text{lo}, \text{hi})$ の全要素 `M::e()` の列を作る。
- `set(p, x)`: `a[p]` を `x` にする。
- `get(p)`: `a[p]` を返す。
- `prod(l, r)`: `op(a[l], ..., a[r - 1])` を返す。$l = r$ なら `e()`。
- `all_prod()`: `op(a[lo], ..., a[hi - 1])` を返す。
- `max_right(l, f)`: `f(op(a[l], ..., a[r - 1]))` が真となる最大の `r` を返す。全体で真なら `hi`。`f` は `atcoder::segtree` と同じ条件を満たすもの。
- `min_left(r, f)`: `f(op(a[l], ..., a[r - 1]))` が真となる最小の `l` を返す。全体で真なら `lo`。

### 制約
- $\text{lo} < \text{hi}$
- `set`, `get`: $\text{lo} \le p < \text{hi}$
- `prod`: $\text{lo} \le l \le r \le \text{hi}$
- `max_right`, `min_left`: $\text{lo} \le l, r \le \text{hi}$

### 計算量
- $N = \text{hi} - \text{lo}$ として
- `set`, `get`, `prod`, `max_right`, `min_left`: $\mathcal{O}(\log N)$
- `all_prod`: $\mathcal{O}(1)$
- メモリは `set` した位置の個数に比例する。
