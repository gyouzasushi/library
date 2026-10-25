---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/unionfind_with_potential.test.cpp
    title: test/library-checker/unionfind_with_potential.test.cpp
  - icon: ':x:'
    path: test/library-checker/unionfind_with_potential_non_commutative_group.test.cpp
    title: test/library-checker/unionfind_with_potential_non_commutative_group.test.cpp
  - icon: ':x:'
    path: test/unit/weighted_dsu.test.cpp
    title: test/unit/weighted_dsu.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/weighted_dsu.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\n#line 2 \"algebra/concept.hpp\"\
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
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\n#line 8 \"datastructure/weighted_dsu.hpp\"\
    \n\n// potential p[v] of each vertex; diff(a, b) = op(inv(p[a]), p[b])\ntemplate\
    \ <group G> struct weighted_dsu {\npublic:\n    using S = typename G::S;\n   \
    \ weighted_dsu() : weighted_dsu(0) {\n    }\n    explicit weighted_dsu(int n)\
    \ : _n(n), parent_or_size(n, -1), pot(n, G::e()) {\n    }\n    // make diff(a,\
    \ b) == w; returns false if it contradicts the existing constraints\n    bool\
    \ merge(int a, int b, S w) {\n        assert(0 <= a && a < _n);\n        assert(0\
    \ <= b && b < _n);\n        int x = leader(a), y = leader(b);\n        if (x ==\
    \ y) return diff(a, b) == w;\n        // p[y] relative to x: op(inv(p[a]), op(p[y],\
    \ p[b])) == w\n        S py = G::op(G::op(pot[a], w), G::inv(pot[b]));\n     \
    \   if (-parent_or_size[x] < -parent_or_size[y]) {\n            std::swap(x, y);\n\
    \            py = G::inv(py);\n        }\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        pot[y] = py;\n        return true;\n\
    \    }\n    S diff(int a, int b) {\n        assert(same(a, b));\n        return\
    \ G::op(G::inv(pot[a]), pot[b]);\n    }\n    bool same(int a, int b) {\n     \
    \   assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n        return\
    \ leader(a) == leader(b);\n    }\n    int leader(int a) {\n        assert(0 <=\
    \ a && a < _n);\n        if (parent_or_size[a] < 0) return a;\n        int p =\
    \ parent_or_size[a];\n        int r = leader(p);\n        if (p != r) pot[a] =\
    \ G::op(pot[p], pot[a]);\n        return parent_or_size[a] = r;\n    }\n    int\
    \ size(int a) {\n        assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n\
    \    }\n    std::vector<std::vector<int>> groups() {\n        std::vector<int>\
    \ leader_buf(_n), group_size(_n);\n        for (int i = 0; i < _n; i++) {\n  \
    \          leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) result[i].reserve(group_size[i]);\n        for (int i =\
    \ 0; i < _n; i++) result[leader_buf[i]].push_back(i);\n        result.erase(std::remove_if(result.begin(),\
    \ result.end(),\n                                    [&](const std::vector<int>&\
    \ v) { return v.empty(); }),\n                     result.end());\n        return\
    \ result;\n    }\n\nprivate:\n    int _n;\n    std::vector<int> parent_or_size;\n\
    \    std::vector<S> pot;  // relative to parent\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\n#include \"algebra/concept.hpp\"\n\n// potential p[v] of\
    \ each vertex; diff(a, b) = op(inv(p[a]), p[b])\ntemplate <group G> struct weighted_dsu\
    \ {\npublic:\n    using S = typename G::S;\n    weighted_dsu() : weighted_dsu(0)\
    \ {\n    }\n    explicit weighted_dsu(int n) : _n(n), parent_or_size(n, -1), pot(n,\
    \ G::e()) {\n    }\n    // make diff(a, b) == w; returns false if it contradicts\
    \ the existing constraints\n    bool merge(int a, int b, S w) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        int x = leader(a),\
    \ y = leader(b);\n        if (x == y) return diff(a, b) == w;\n        // p[y]\
    \ relative to x: op(inv(p[a]), op(p[y], p[b])) == w\n        S py = G::op(G::op(pot[a],\
    \ w), G::inv(pot[b]));\n        if (-parent_or_size[x] < -parent_or_size[y]) {\n\
    \            std::swap(x, y);\n            py = G::inv(py);\n        }\n     \
    \   parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y] = x;\n\
    \        pot[y] = py;\n        return true;\n    }\n    S diff(int a, int b) {\n\
    \        assert(same(a, b));\n        return G::op(G::inv(pot[a]), pot[b]);\n\
    \    }\n    bool same(int a, int b) {\n        assert(0 <= a && a < _n);\n   \
    \     assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n    }\n\
    \    int leader(int a) {\n        assert(0 <= a && a < _n);\n        if (parent_or_size[a]\
    \ < 0) return a;\n        int p = parent_or_size[a];\n        int r = leader(p);\n\
    \        if (p != r) pot[a] = G::op(pot[p], pot[a]);\n        return parent_or_size[a]\
    \ = r;\n    }\n    int size(int a) {\n        assert(0 <= a && a < _n);\n    \
    \    return -parent_or_size[leader(a)];\n    }\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(_n), group_size(_n);\n     \
    \   for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n \
    \           group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) result[i].reserve(group_size[i]);\n\
    \        for (int i = 0; i < _n; i++) result[leader_buf[i]].push_back(i);\n  \
    \      result.erase(std::remove_if(result.begin(), result.end(),\n           \
    \                         [&](const std::vector<int>& v) { return v.empty(); }),\n\
    \                     result.end());\n        return result;\n    }\n\nprivate:\n\
    \    int _n;\n    std::vector<int> parent_or_size;\n    std::vector<S> pot;  //\
    \ relative to parent\n};\n"
  dependsOn:
  - algebra/concept.hpp
  isVerificationFile: false
  path: datastructure/weighted_dsu.hpp
  requiredBy: []
  timestamp: '2026-10-26 01:30:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unit/weighted_dsu.test.cpp
  - test/library-checker/unionfind_with_potential_non_commutative_group.test.cpp
  - test/library-checker/unionfind_with_potential.test.cpp
documentation_of: datastructure/weighted_dsu.hpp
layout: document
title: Weighted DSU
---

### 概要
- 各頂点にポテンシャルを持つ Union-Find。頂点間のポテンシャルの差を制約として追加し、差を求める。

### 使い方
- `weighted_dsu<G>(n)`: $n$ 頂点 $0$ 辺の無向グラフを作る。`G` は `S`, `op`, `e`, `inv` を static メンバとして持つ群。
- `merge(a, b, w)`: `diff(a, b) == w` となるように辺 $(a, b)$ を追加し、既存の制約と矛盾しないかを返す。矛盾するときは何もしない。
- `diff(a, b)`: 頂点 `a` から頂点 `b` へのポテンシャルの差 `op(inv(p[a]), p[b])` を返す。
- `same(a, b)`: 頂点 `a`, `b` が連結かを返す。
- `leader(a)`: 頂点 `a` の属する連結成分の代表元を返す。
- `size(a)`: 頂点 `a` の属する連結成分のサイズを返す。
- `groups()`: 連結成分ごとの頂点のリストを返す。

### 制約
- $0 \le a, b < n$
- `diff`: `same(a, b)`
- `S` は `==` で比較できる

### 計算量
- `merge`, `diff`, `same`, `leader`, `size`: 償却 $\mathcal{O}(\alpha(n))$
- `groups`: $\mathcal{O}(n)$
