---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/range_affine_point_get.test.cpp
    title: test/library-checker/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/dual_segtree.test.cpp
    title: test/unit/dual_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/dual_segtree.hpp\"\n#include <algorithm>\n\
    #include <bit>\n#include <cassert>\n#include <vector>\n\n#line 2 \"algebra/concept.hpp\"\
    \n#include <concepts>\ntemplate <class M>\nconcept semigroup = requires(typename\
    \ M::S a, typename M::S b) {\n    { M::op(a, b) } -> std::same_as<typename M::S>;\n\
    };\ntemplate <class M>\nconcept monoid = semigroup<M> && requires {\n    { M::e()\
    \ } -> std::same_as<typename M::S>;\n};\ntemplate <class A>\nconcept action =\
    \ requires(typename A::F f, typename A::F g) {\n    { A::composition(f, g) } ->\
    \ std::same_as<typename A::F>;\n    { A::id() } -> std::same_as<typename A::F>;\n\
    \    { A::composition_commutative } -> std::convertible_to<bool>;\n};\ntemplate\
    \ <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
    \ A::S x, typename A::F f) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n};\ntemplate <class R>\nconcept semiring = requires(typename R::S a,\
    \ typename R::S b) {\n    { R::add(a, b) } -> std::same_as<typename R::S>;\n \
    \   { R::zero() } -> std::same_as<typename R::S>;\n    { R::mul(a, b) } -> std::same_as<typename\
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\n#line 8 \"datastructure/dual_segtree.hpp\"\
    \ntemplate <action A>\nstruct dual_segtree {\n    using F = typename A::F;\n \
    \   dual_segtree() : dual_segtree(0) {}\n    explicit dual_segtree(int n) : dual_segtree(std::vector<F>(n,\
    \ A::id())) {}\n    explicit dual_segtree(const std::vector<F>& v) : n(int(v.size()))\
    \ {\n        log = std::bit_width(unsigned(std::max(n - 1, 0)));\n        size\
    \ = 1 << log;\n        d.assign(2 * size, A::id());\n        for (int i = 0; i\
    \ < n; i++) d[size + i] = v[i];\n    }\n    void set(int p, F x) {\n        assert(0\
    \ <= p && p < n);\n        p += size;\n        thrust(p);\n        d[p] = x;\n\
    \    }\n    F get(int p) {\n        assert(0 <= p && p < n);\n        p += size;\n\
    \        if constexpr (A::composition_commutative) {\n            F ret = d[p];\n\
    \            while (p >>= 1) ret = A::composition(d[p], ret);\n            return\
    \ ret;\n        } else {\n            thrust(p);\n            return d[p];\n \
    \       }\n    }\n    void apply(int l, int r, F f) {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        if (l == r) return;\n        l += size;\n      \
    \  r += size;\n        if constexpr (!A::composition_commutative) {\n        \
    \    thrust(l);\n            thrust(r - 1);\n        }\n        while (l < r)\
    \ {\n            if (l & 1) d[l] = A::composition(f, d[l]), l++;\n           \
    \ if (r & 1) --r, d[r] = A::composition(f, d[r]);\n            l >>= 1, r >>=\
    \ 1;\n        }\n    }\n\nprivate:\n    int n, size, log;\n    std::vector<F>\
    \ d;\n    void propagate(int k) {\n        d[2 * k] = A::composition(d[k], d[2\
    \ * k]);\n        d[2 * k + 1] = A::composition(d[k], d[2 * k + 1]);\n       \
    \ d[k] = A::id();\n    }\n    void thrust(int k) {\n        for (int i = log;\
    \ i >= 1; i--) propagate(k >> i);\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <bit>\n#include <cassert>\n\
    #include <vector>\n\n#include \"algebra/concept.hpp\"\ntemplate <action A>\nstruct\
    \ dual_segtree {\n    using F = typename A::F;\n    dual_segtree() : dual_segtree(0)\
    \ {}\n    explicit dual_segtree(int n) : dual_segtree(std::vector<F>(n, A::id()))\
    \ {}\n    explicit dual_segtree(const std::vector<F>& v) : n(int(v.size())) {\n\
    \        log = std::bit_width(unsigned(std::max(n - 1, 0)));\n        size = 1\
    \ << log;\n        d.assign(2 * size, A::id());\n        for (int i = 0; i < n;\
    \ i++) d[size + i] = v[i];\n    }\n    void set(int p, F x) {\n        assert(0\
    \ <= p && p < n);\n        p += size;\n        thrust(p);\n        d[p] = x;\n\
    \    }\n    F get(int p) {\n        assert(0 <= p && p < n);\n        p += size;\n\
    \        if constexpr (A::composition_commutative) {\n            F ret = d[p];\n\
    \            while (p >>= 1) ret = A::composition(d[p], ret);\n            return\
    \ ret;\n        } else {\n            thrust(p);\n            return d[p];\n \
    \       }\n    }\n    void apply(int l, int r, F f) {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        if (l == r) return;\n        l += size;\n      \
    \  r += size;\n        if constexpr (!A::composition_commutative) {\n        \
    \    thrust(l);\n            thrust(r - 1);\n        }\n        while (l < r)\
    \ {\n            if (l & 1) d[l] = A::composition(f, d[l]), l++;\n           \
    \ if (r & 1) --r, d[r] = A::composition(f, d[r]);\n            l >>= 1, r >>=\
    \ 1;\n        }\n    }\n\nprivate:\n    int n, size, log;\n    std::vector<F>\
    \ d;\n    void propagate(int k) {\n        d[2 * k] = A::composition(d[k], d[2\
    \ * k]);\n        d[2 * k + 1] = A::composition(d[k], d[2 * k + 1]);\n       \
    \ d[k] = A::id();\n    }\n    void thrust(int k) {\n        for (int i = log;\
    \ i >= 1; i--) propagate(k >> i);\n    }\n};\n"
  dependsOn:
  - algebra/concept.hpp
  isVerificationFile: false
  path: datastructure/dual_segtree.hpp
  requiredBy: []
  timestamp: '2026-10-23 22:22:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/dual_segtree.test.cpp
  - test/library-checker/range_affine_point_get.test.cpp
documentation_of: datastructure/dual_segtree.hpp
layout: document
title: Dual Segment Tree
---

### 概要
- 区間作用と一点取得ができるデータ構造。

### 使い方
- `dual_segtree<A>(n)`: 長さ $n$ の数列 `a` を `id()` で初期化して作る。`A` は `F`, `composition`, `id`, `composition_commutative` を static メンバとして持つ構造体。
- `dual_segtree<A>(v)`: 数列 `a` を `v` で初期化して作る。
- `apply(l, r, f)`: `a[l], ..., a[r - 1]` のそれぞれを `composition(f, a[i])` に置き換える。
- `set(p, x)`: `a[p]` を `x` に置き換える。
- `get(p)`: `a[p]` を返す。

### 制約
- $0 \le l \le r \le n$
- $0 \le p < n$

### 計算量
- 構築: $\mathcal{O}(n)$
- `apply`, `set`, `get`: $\mathcal{O}(\log n)$
