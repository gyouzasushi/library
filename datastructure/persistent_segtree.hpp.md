---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/persistent_segtree.test.cpp
    title: test/unit/persistent_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/persistent_segtree.hpp\"\n#include <cassert>\n\
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
    \ {\n    { x.fail } -> std::convertible_to<bool>;\n};\n#line 6 \"datastructure/persistent_segtree.hpp\"\
    \ntemplate <monoid M> struct persistent_segtree {\npublic:\n    using S = typename\
    \ M::S;\n    explicit persistent_segtree(int n) : persistent_segtree(std::vector<S>(n,\
    \ M::e())) {\n    }\n    explicit persistent_segtree(const std::vector<S>& v)\
    \ : _n(int(v.size())) {\n        nodes.reserve(2 * _n);\n        if (_n > 0) build(v,\
    \ 0, _n);\n    }\n    int size() const {\n        return _n;\n    }\n    S get(int\
    \ root, int p) const {\n        assert(0 <= p && p < _n);\n        int cur = root,\
    \ l = 0, r = _n;\n        while (r - l > 1) {\n            int mid = (l + r) /\
    \ 2;\n            if (p < mid) {\n                cur = nodes[cur].l, r = mid;\n\
    \            } else {\n                cur = nodes[cur].r, l = mid;\n        \
    \    }\n        }\n        return nodes[cur].val;\n    }\n    int set(int root,\
    \ int p, const S& x) {\n        assert(0 <= p && p < _n);\n        int res = copy(root);\n\
    \        int cur = res, l = 0, r = _n;\n        path.clear();\n        while (r\
    \ - l > 1) {\n            path.push_back(cur);\n            int mid = (l + r)\
    \ / 2;\n            if (p < mid) {\n                int nxt = copy(nodes[cur].l);\n\
    \                nodes[cur].l = nxt;\n                cur = nxt, r = mid;\n  \
    \          } else {\n                int nxt = copy(nodes[cur].r);\n         \
    \       nodes[cur].r = nxt;\n                cur = nxt, l = mid;\n           \
    \ }\n        }\n        nodes[cur].val = x;\n        for (int i = int(path.size())\
    \ - 1; i >= 0; i--) {\n            node& v = nodes[path[i]];\n            v.val\
    \ = M::op(nodes[v.l].val, nodes[v.r].val);\n        }\n        return res;\n \
    \   }\n    S prod(int root, int l, int r) const {\n        assert(0 <= l && l\
    \ <= r && r <= _n);\n        return prod(root, 0, _n, l, r);\n    }\n    S all_prod(int\
    \ root) const {\n        return _n == 0 ? M::e() : nodes[root].val;\n    }\n\n\
    private:\n    struct node {\n        int l, r;\n        S val;\n    };\n    int\
    \ _n;\n    std::vector<node> nodes;\n    std::vector<int> path;\n    int copy(int\
    \ v) {\n        nodes.push_back(nodes[v]);\n        return int(nodes.size()) -\
    \ 1;\n    }\n    int build(const std::vector<S>& v, int l, int r) {\n        if\
    \ (r - l == 1) {\n            nodes.push_back({-1, -1, v[l]});\n            return\
    \ int(nodes.size()) - 1;\n        }\n        int mid = (l + r) / 2;\n        int\
    \ res = int(nodes.size());\n        nodes.push_back({-1, -1, M::e()});\n     \
    \   int lc = build(v, l, mid);\n        int rc = build(v, mid, r);\n        nodes[res].l\
    \ = lc, nodes[res].r = rc;\n        nodes[res].val = M::op(nodes[lc].val, nodes[rc].val);\n\
    \        return res;\n    }\n    S prod(int cur, int nl, int nr, int l, int r)\
    \ const {\n        if (r <= nl || nr <= l) return M::e();\n        if (l <= nl\
    \ && nr <= r) return nodes[cur].val;\n        int mid = (nl + nr) / 2;\n     \
    \   return M::op(prod(nodes[cur].l, nl, mid, l, r), prod(nodes[cur].r, mid, nr,\
    \ l, r));\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\n#include \"algebra/concept.hpp\"\
    \ntemplate <monoid M> struct persistent_segtree {\npublic:\n    using S = typename\
    \ M::S;\n    explicit persistent_segtree(int n) : persistent_segtree(std::vector<S>(n,\
    \ M::e())) {\n    }\n    explicit persistent_segtree(const std::vector<S>& v)\
    \ : _n(int(v.size())) {\n        nodes.reserve(2 * _n);\n        if (_n > 0) build(v,\
    \ 0, _n);\n    }\n    int size() const {\n        return _n;\n    }\n    S get(int\
    \ root, int p) const {\n        assert(0 <= p && p < _n);\n        int cur = root,\
    \ l = 0, r = _n;\n        while (r - l > 1) {\n            int mid = (l + r) /\
    \ 2;\n            if (p < mid) {\n                cur = nodes[cur].l, r = mid;\n\
    \            } else {\n                cur = nodes[cur].r, l = mid;\n        \
    \    }\n        }\n        return nodes[cur].val;\n    }\n    int set(int root,\
    \ int p, const S& x) {\n        assert(0 <= p && p < _n);\n        int res = copy(root);\n\
    \        int cur = res, l = 0, r = _n;\n        path.clear();\n        while (r\
    \ - l > 1) {\n            path.push_back(cur);\n            int mid = (l + r)\
    \ / 2;\n            if (p < mid) {\n                int nxt = copy(nodes[cur].l);\n\
    \                nodes[cur].l = nxt;\n                cur = nxt, r = mid;\n  \
    \          } else {\n                int nxt = copy(nodes[cur].r);\n         \
    \       nodes[cur].r = nxt;\n                cur = nxt, l = mid;\n           \
    \ }\n        }\n        nodes[cur].val = x;\n        for (int i = int(path.size())\
    \ - 1; i >= 0; i--) {\n            node& v = nodes[path[i]];\n            v.val\
    \ = M::op(nodes[v.l].val, nodes[v.r].val);\n        }\n        return res;\n \
    \   }\n    S prod(int root, int l, int r) const {\n        assert(0 <= l && l\
    \ <= r && r <= _n);\n        return prod(root, 0, _n, l, r);\n    }\n    S all_prod(int\
    \ root) const {\n        return _n == 0 ? M::e() : nodes[root].val;\n    }\n\n\
    private:\n    struct node {\n        int l, r;\n        S val;\n    };\n    int\
    \ _n;\n    std::vector<node> nodes;\n    std::vector<int> path;\n    int copy(int\
    \ v) {\n        nodes.push_back(nodes[v]);\n        return int(nodes.size()) -\
    \ 1;\n    }\n    int build(const std::vector<S>& v, int l, int r) {\n        if\
    \ (r - l == 1) {\n            nodes.push_back({-1, -1, v[l]});\n            return\
    \ int(nodes.size()) - 1;\n        }\n        int mid = (l + r) / 2;\n        int\
    \ res = int(nodes.size());\n        nodes.push_back({-1, -1, M::e()});\n     \
    \   int lc = build(v, l, mid);\n        int rc = build(v, mid, r);\n        nodes[res].l\
    \ = lc, nodes[res].r = rc;\n        nodes[res].val = M::op(nodes[lc].val, nodes[rc].val);\n\
    \        return res;\n    }\n    S prod(int cur, int nl, int nr, int l, int r)\
    \ const {\n        if (r <= nl || nr <= l) return M::e();\n        if (l <= nl\
    \ && nr <= r) return nodes[cur].val;\n        int mid = (nl + nr) / 2;\n     \
    \   return M::op(prod(nodes[cur].l, nl, mid, l, r), prod(nodes[cur].r, mid, nr,\
    \ l, r));\n    }\n};\n"
  dependsOn:
  - algebra/concept.hpp
  isVerificationFile: false
  path: datastructure/persistent_segtree.hpp
  requiredBy: []
  timestamp: '2026-10-29 12:09:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/persistent_segtree.test.cpp
documentation_of: datastructure/persistent_segtree.hpp
layout: document
title: Persistent Segment Tree
---

### 概要
- 1 点更新のたびに新しい版を作り、過去の版に対しても区間の総積を求められるセグメント木。版は `int` の番号で扱う。

### 使い方
- `persistent_segtree<M>(n)`: `M` は `S`, `op`, `e` を static メンバとして持つ構造体。全要素 `M::e()` の長さ $n$ の列を版 $0$ として作る。
- `persistent_segtree<M>(v)`: 列 `v` を版 $0$ として作る。
- `size()`: 列の長さを返す。
- `get(root, p)`: 版 `root` の `a[p]` を返す。
- `set(root, p, x)`: 版 `root` の `a[p]` を `x` に変えた新しい版を作り、その番号を返す。版 `root` は変わらない。
- `prod(root, l, r)`: 版 `root` の `op(a[l], ..., a[r - 1])` を返す。$l = r$ なら `e()`。
- `all_prod(root)`: 版 `root` の `op(a[0], ..., a[n - 1])` を返す。

### 制約
- $0 \le p < n$
- $0 \le l \le r \le n$

### 計算量
- 構築: $\mathcal{O}(n)$
- `get`, `set`, `prod`: $\mathcal{O}(\log n)$。`set` 1 回でメモリが $\mathcal{O}(\log n)$ 増える。
- `all_prod`: $\mathcal{O}(1)$
