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
    path: datastructure/plus_minus_one_rmq.hpp
    title: Plus Minus One RMQ
  - icon: ':heavy_check_mark:'
    path: datastructure/sparse_table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/lca.test.cpp
    title: test/library-checker/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/lowest_common_ancestor.hpp\"\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"datastructure/plus_minus_one_rmq.hpp\"\n#include\
    \ <algorithm>\n#include <bit>\n#line 6 \"datastructure/plus_minus_one_rmq.hpp\"\
    \n\n#line 6 \"datastructure/sparse_table.hpp\"\n\n#line 2 \"algebra/concept.hpp\"\
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
    \ j);\n    }\n};\n#line 6 \"graph/lowest_common_ancestor.hpp\"\nstruct lowest_common_ancestor\
    \ {\npublic:\n    lowest_common_ancestor() {\n    }\n    lowest_common_ancestor(int\
    \ n, int root = 0)\n        : _n(n), _root(root), g(n), id(n), vs(2 * n - 1),\
    \ dep(2 * n - 1) {\n    }\n    void add_edge(int from, int to) {\n        assert(0\
    \ <= from && from < _n);\n        assert(0 <= to && to < _n);\n        g[from].push_back(to);\n\
    \        g[to].push_back(from);\n    }\n    void build() {\n        int k = 0;\n\
    \        auto dfs = [&](auto dfs, int pos, int pre, int d) -> void {\n       \
    \     id[pos] = k;\n            vs[k] = pos;\n            dep[k++] = d;\n    \
    \        for (int nxt : g[pos]) {\n                if (nxt == pre) continue;\n\
    \                dfs(dfs, nxt, pos, d + 1);\n                vs[k] = pos;\n  \
    \              dep[k++] = d;\n            }\n        };\n        dfs(dfs, _root,\
    \ -1, 0);\n        rmq = plus_minus_one_rmq(dep);\n    }\n\n    int get(int u,\
    \ int v) {\n        int l = std::min(id[u], id[v]);\n        int r = std::max(id[u],\
    \ id[v]) + 1;\n        return vs[rmq.prod(l, r)];\n    }\n    int get(int u, int\
    \ v, int r) {\n        return get(r, u) ^ get(u, v) ^ get(v, r);\n    }\n    int\
    \ depth(int u) {\n        return dep[id[u]];\n    }\n    int dist(int u, int v)\
    \ {\n        return depth(u) + depth(v) - 2 * depth(get(u, v));\n    }\n\nprivate:\n\
    \    int _n, _root;\n    std::vector<std::vector<int>> g;\n    std::vector<int>\
    \ id, vs, dep;\n    plus_minus_one_rmq rmq;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\n#include \"datastructure/plus_minus_one_rmq.hpp\"\
    \nstruct lowest_common_ancestor {\npublic:\n    lowest_common_ancestor() {\n \
    \   }\n    lowest_common_ancestor(int n, int root = 0)\n        : _n(n), _root(root),\
    \ g(n), id(n), vs(2 * n - 1), dep(2 * n - 1) {\n    }\n    void add_edge(int from,\
    \ int to) {\n        assert(0 <= from && from < _n);\n        assert(0 <= to &&\
    \ to < _n);\n        g[from].push_back(to);\n        g[to].push_back(from);\n\
    \    }\n    void build() {\n        int k = 0;\n        auto dfs = [&](auto dfs,\
    \ int pos, int pre, int d) -> void {\n            id[pos] = k;\n            vs[k]\
    \ = pos;\n            dep[k++] = d;\n            for (int nxt : g[pos]) {\n  \
    \              if (nxt == pre) continue;\n                dfs(dfs, nxt, pos, d\
    \ + 1);\n                vs[k] = pos;\n                dep[k++] = d;\n       \
    \     }\n        };\n        dfs(dfs, _root, -1, 0);\n        rmq = plus_minus_one_rmq(dep);\n\
    \    }\n\n    int get(int u, int v) {\n        int l = std::min(id[u], id[v]);\n\
    \        int r = std::max(id[u], id[v]) + 1;\n        return vs[rmq.prod(l, r)];\n\
    \    }\n    int get(int u, int v, int r) {\n        return get(r, u) ^ get(u,\
    \ v) ^ get(v, r);\n    }\n    int depth(int u) {\n        return dep[id[u]];\n\
    \    }\n    int dist(int u, int v) {\n        return depth(u) + depth(v) - 2 *\
    \ depth(get(u, v));\n    }\n\nprivate:\n    int _n, _root;\n    std::vector<std::vector<int>>\
    \ g;\n    std::vector<int> id, vs, dep;\n    plus_minus_one_rmq rmq;\n};"
  dependsOn:
  - datastructure/plus_minus_one_rmq.hpp
  - datastructure/sparse_table.hpp
  - algebra/concept.hpp
  - algebra/monoid_argmin.hpp
  isVerificationFile: false
  path: graph/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2026-10-26 01:30:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/lca.test.cpp
documentation_of: graph/lowest_common_ancestor.hpp
layout: document
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148(LCA)"
---

### 概要
- 最小共通祖先(LCA)他を求める。
  
### 使い方
- `lowest_common_ancestor(n, root = 0)`: $\mathrm n$ 頂点で初期化する。頂点 `root` が根になる。
- `add_edge(u, v)`: 頂点 `u` と 頂点 `v` とを結ぶ辺を追加する。
- `build()`: 構築する。
- `get(u, v)`: 頂点 `u` と頂点 `v` のLCAを求める。
- `get(u, v, r)`: 頂点 `r` を根とみたときの、頂点 `u` と頂点 `v` のLCAを求める。
- `depth(u)`: 根と頂点 `u` との距離を求める。
- `dist(u, v)`: 頂点 `u` と頂点 `v` との距離を求める。
  
### 計算量
- 構築 $\mathcal O(N)$
- クエリ $\mathcal O(1)$