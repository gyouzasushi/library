---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/tree_path_composite_sum.test.cpp
    title: test/library-checker/tree_path_composite_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/rerooting.test.cpp
    title: test/unit/rerooting.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/rerooting.hpp\"\n#include <cassert>\n#include <functional>\n\
    #include <type_traits>\n#include <utility>\n#include <variant>\n#include <vector>\n\
    template <class R>\nstruct rerooting {\npublic:\n    using T = typename R::T;\n\
    \    using M = typename R::M;\n    using E = typename R::E;\n    using V = typename\
    \ R::V;\n    static_assert(std::is_invocable_r_v<M, decltype(R::put_edge), const\
    \ T&, const E&, int, int>,\n                  \"R::put_edge must work as M(const\
    \ T&, const E&, int u, int v)\");\n    static_assert(std::is_invocable_r_v<M,\
    \ decltype(R::merge), const M&, const M&>,\n                  \"R::merge must\
    \ work as M(const M&, const M&)\");\n    static_assert(std::is_invocable_r_v<M,\
    \ decltype(R::e)>, \"R::e must work as M()\");\n    static_assert(std::is_invocable_r_v<T,\
    \ decltype(R::put_vertex), const M&, const V&, int>,\n                  \"R::put_vertex\
    \ must work as T(const M&, const V&, int v)\");\n\n    rerooting() {\n    }\n\
    \    explicit rerooting(int n) : rerooting(std::vector<V>(n)) {\n    }\n    explicit\
    \ rerooting(std::vector<V> a) : _n(int(a.size())), vdata(std::move(a)), g(_n)\
    \ {\n    }\n    int add_edge(int u, int v, E w = E()) {\n        assert(0 <= u\
    \ && u < _n);\n        assert(0 <= v && v < _n);\n        int i = int(edges.size());\n\
    \        edges.emplace_back(u, v);\n        edata.push_back(std::move(w));\n \
    \       g[u].push_back(i);\n        g[v].push_back(i);\n        return i;\n  \
    \  }\n    void solve() {\n        assert(int(edges.size()) == _n - 1);\n     \
    \   dp.assign(_n, T());\n        agg.assign(_n, R::e());\n        _sub.assign(2\
    \ * (_n - 1), T());\n        std::vector<int> order, par(_n, -1), pe(_n, -1);\n\
    \        order.reserve(_n);\n        order.push_back(0);\n        for (int k =\
    \ 0; k < _n; k++) {\n            int v = order[k];\n            for (int i : g[v])\
    \ {\n                int to = other(i, v);\n                if (to == par[v])\
    \ continue;\n                par[to] = v;\n                pe[to] = i;\n     \
    \           order.push_back(to);\n            }\n        }\n        // bottom-up:\
    \ sub(par[v] -> v)\n        for (int k = _n - 1; k > 0; k--) {\n            int\
    \ v = order[k];\n            M acc = R::e();\n            for (int i : g[v]) {\n\
    \                int to = other(i, v);\n                if (to == par[v]) continue;\n\
    \                acc = R::merge(acc, R::put_edge(_sub[dir(i, v)], edata[i], v,\
    \ to));\n            }\n            _sub[dir(pe[v], par[v])] = R::put_vertex(acc,\
    \ vdata[v], v);\n        }\n        // top-down: sub(v -> par[v]) is ready when\
    \ v is visited\n        std::vector<M> pre, suf;\n        for (int v : order)\
    \ {\n            int deg = int(g[v].size());\n            pre.assign(deg + 1,\
    \ R::e());\n            suf.assign(deg + 1, R::e());\n            for (int j =\
    \ 0; j < deg; j++) {\n                int i = g[v][j], to = other(i, v);\n   \
    \             pre[j + 1] = R::merge(pre[j], R::put_edge(_sub[dir(i, v)], edata[i],\
    \ v, to));\n            }\n            for (int j = deg; j > 0; j--) {\n     \
    \           int i = g[v][j - 1], to = other(i, v);\n                suf[j - 1]\
    \ = R::merge(R::put_edge(_sub[dir(i, v)], edata[i], v, to), suf[j]);\n       \
    \     }\n            agg[v] = pre[deg];\n            dp[v] = R::put_vertex(agg[v],\
    \ vdata[v], v);\n            for (int j = 0; j < deg; j++) {\n               \
    \ int i = g[v][j], to = other(i, v);\n                if (to == par[v]) continue;\n\
    \                _sub[dir(i, to)] = R::put_vertex(R::merge(pre[j], suf[j + 1]),\
    \ vdata[v], v);\n            }\n        }\n    }\n    // dp[v]: \u5168\u4F53\u3092\
    \ v \u3092\u6839\u3068\u3057\u3066\u898B\u305F\u3068\u304D\u306E\u5024\n    std::vector<T>\
    \ dp;\n    // agg[v]: dp[v] \u3092\u4F5C\u308B\u76F4\u524D\u306E\u3001v \u306E\
    \u5168\u96A3\u63A5\u3092\u307E\u3068\u3081\u305F\u5024\n    std::vector<M> agg;\n\
    \    // sub(u, v): \u8FBA (u, v) \u3092\u5207\u3063\u305F\u3068\u304D\u306E v\
    \ \u5074\u306E\u90E8\u5206\u6728\u3092 v \u3092\u6839\u3068\u3057\u3066\u898B\u305F\
    \u5024\n    const T& sub(int u, int v) const {\n        for (int i : g[u]) {\n\
    \            if (other(i, u) == v) return _sub[dir(i, u)];\n        }\n      \
    \  assert(false);\n        return dp[u];\n    }\n    // sub_by_edge(i, v): \u8FBA\
    \ i \u3092\u5207\u3063\u305F\u3068\u304D\u306E v \u5074\u306E\u90E8\u5206\u6728\
    \u3092 v \u3092\u6839\u3068\u3057\u3066\u898B\u305F\u5024\n    const T& sub_by_edge(int\
    \ i, int v) const {\n        assert(0 <= i && i < int(edges.size()));\n      \
    \  assert(edges[i].first == v || edges[i].second == v);\n        return _sub[dir(i,\
    \ other(i, v))];\n    }\n\nprivate:\n    int _n;\n    std::vector<V> vdata;\n\
    \    std::vector<std::vector<int>> g;\n    std::vector<std::pair<int, int>> edges;\n\
    \    std::vector<E> edata;\n    std::vector<T> _sub;\n    int other(int i, int\
    \ v) const {\n        return edges[i].first ^ edges[i].second ^ v;\n    }\n  \
    \  // dir(i, u): \u8FBA i \u3092 u \u304B\u3089\u898B\u3066\u53CD\u5BFE\u5074\u306E\
    \u90E8\u5206\u6728\u306E\u5024\u306E\u683C\u7D0D\u4F4D\u7F6E\n    int dir(int\
    \ i, int u) const {\n        return 2 * i + (edges[i].first == u ? 0 : 1);\n \
    \   }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <functional>\n#include <type_traits>\n\
    #include <utility>\n#include <variant>\n#include <vector>\ntemplate <class R>\n\
    struct rerooting {\npublic:\n    using T = typename R::T;\n    using M = typename\
    \ R::M;\n    using E = typename R::E;\n    using V = typename R::V;\n    static_assert(std::is_invocable_r_v<M,\
    \ decltype(R::put_edge), const T&, const E&, int, int>,\n                  \"\
    R::put_edge must work as M(const T&, const E&, int u, int v)\");\n    static_assert(std::is_invocable_r_v<M,\
    \ decltype(R::merge), const M&, const M&>,\n                  \"R::merge must\
    \ work as M(const M&, const M&)\");\n    static_assert(std::is_invocable_r_v<M,\
    \ decltype(R::e)>, \"R::e must work as M()\");\n    static_assert(std::is_invocable_r_v<T,\
    \ decltype(R::put_vertex), const M&, const V&, int>,\n                  \"R::put_vertex\
    \ must work as T(const M&, const V&, int v)\");\n\n    rerooting() {\n    }\n\
    \    explicit rerooting(int n) : rerooting(std::vector<V>(n)) {\n    }\n    explicit\
    \ rerooting(std::vector<V> a) : _n(int(a.size())), vdata(std::move(a)), g(_n)\
    \ {\n    }\n    int add_edge(int u, int v, E w = E()) {\n        assert(0 <= u\
    \ && u < _n);\n        assert(0 <= v && v < _n);\n        int i = int(edges.size());\n\
    \        edges.emplace_back(u, v);\n        edata.push_back(std::move(w));\n \
    \       g[u].push_back(i);\n        g[v].push_back(i);\n        return i;\n  \
    \  }\n    void solve() {\n        assert(int(edges.size()) == _n - 1);\n     \
    \   dp.assign(_n, T());\n        agg.assign(_n, R::e());\n        _sub.assign(2\
    \ * (_n - 1), T());\n        std::vector<int> order, par(_n, -1), pe(_n, -1);\n\
    \        order.reserve(_n);\n        order.push_back(0);\n        for (int k =\
    \ 0; k < _n; k++) {\n            int v = order[k];\n            for (int i : g[v])\
    \ {\n                int to = other(i, v);\n                if (to == par[v])\
    \ continue;\n                par[to] = v;\n                pe[to] = i;\n     \
    \           order.push_back(to);\n            }\n        }\n        // bottom-up:\
    \ sub(par[v] -> v)\n        for (int k = _n - 1; k > 0; k--) {\n            int\
    \ v = order[k];\n            M acc = R::e();\n            for (int i : g[v]) {\n\
    \                int to = other(i, v);\n                if (to == par[v]) continue;\n\
    \                acc = R::merge(acc, R::put_edge(_sub[dir(i, v)], edata[i], v,\
    \ to));\n            }\n            _sub[dir(pe[v], par[v])] = R::put_vertex(acc,\
    \ vdata[v], v);\n        }\n        // top-down: sub(v -> par[v]) is ready when\
    \ v is visited\n        std::vector<M> pre, suf;\n        for (int v : order)\
    \ {\n            int deg = int(g[v].size());\n            pre.assign(deg + 1,\
    \ R::e());\n            suf.assign(deg + 1, R::e());\n            for (int j =\
    \ 0; j < deg; j++) {\n                int i = g[v][j], to = other(i, v);\n   \
    \             pre[j + 1] = R::merge(pre[j], R::put_edge(_sub[dir(i, v)], edata[i],\
    \ v, to));\n            }\n            for (int j = deg; j > 0; j--) {\n     \
    \           int i = g[v][j - 1], to = other(i, v);\n                suf[j - 1]\
    \ = R::merge(R::put_edge(_sub[dir(i, v)], edata[i], v, to), suf[j]);\n       \
    \     }\n            agg[v] = pre[deg];\n            dp[v] = R::put_vertex(agg[v],\
    \ vdata[v], v);\n            for (int j = 0; j < deg; j++) {\n               \
    \ int i = g[v][j], to = other(i, v);\n                if (to == par[v]) continue;\n\
    \                _sub[dir(i, to)] = R::put_vertex(R::merge(pre[j], suf[j + 1]),\
    \ vdata[v], v);\n            }\n        }\n    }\n    // dp[v]: \u5168\u4F53\u3092\
    \ v \u3092\u6839\u3068\u3057\u3066\u898B\u305F\u3068\u304D\u306E\u5024\n    std::vector<T>\
    \ dp;\n    // agg[v]: dp[v] \u3092\u4F5C\u308B\u76F4\u524D\u306E\u3001v \u306E\
    \u5168\u96A3\u63A5\u3092\u307E\u3068\u3081\u305F\u5024\n    std::vector<M> agg;\n\
    \    // sub(u, v): \u8FBA (u, v) \u3092\u5207\u3063\u305F\u3068\u304D\u306E v\
    \ \u5074\u306E\u90E8\u5206\u6728\u3092 v \u3092\u6839\u3068\u3057\u3066\u898B\u305F\
    \u5024\n    const T& sub(int u, int v) const {\n        for (int i : g[u]) {\n\
    \            if (other(i, u) == v) return _sub[dir(i, u)];\n        }\n      \
    \  assert(false);\n        return dp[u];\n    }\n    // sub_by_edge(i, v): \u8FBA\
    \ i \u3092\u5207\u3063\u305F\u3068\u304D\u306E v \u5074\u306E\u90E8\u5206\u6728\
    \u3092 v \u3092\u6839\u3068\u3057\u3066\u898B\u305F\u5024\n    const T& sub_by_edge(int\
    \ i, int v) const {\n        assert(0 <= i && i < int(edges.size()));\n      \
    \  assert(edges[i].first == v || edges[i].second == v);\n        return _sub[dir(i,\
    \ other(i, v))];\n    }\n\nprivate:\n    int _n;\n    std::vector<V> vdata;\n\
    \    std::vector<std::vector<int>> g;\n    std::vector<std::pair<int, int>> edges;\n\
    \    std::vector<E> edata;\n    std::vector<T> _sub;\n    int other(int i, int\
    \ v) const {\n        return edges[i].first ^ edges[i].second ^ v;\n    }\n  \
    \  // dir(i, u): \u8FBA i \u3092 u \u304B\u3089\u898B\u3066\u53CD\u5BFE\u5074\u306E\
    \u90E8\u5206\u6728\u306E\u5024\u306E\u683C\u7D0D\u4F4D\u7F6E\n    int dir(int\
    \ i, int u) const {\n        return 2 * i + (edges[i].first == u ? 0 : 1);\n \
    \   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/rerooting.hpp
  requiredBy: []
  timestamp: '2026-10-19 03:10:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/rerooting.test.cpp
  - test/library-checker/tree_path_composite_sum.test.cpp
documentation_of: graph/rerooting.hpp
layout: document
title: "\u5168\u65B9\u4F4D\u6728 DP (Rerooting)"
---

### 概要
- 木の全頂点を根としたときの DP の値を $\mathcal O(N)$ で求める。
- 部分木の値の型 `T` と、子をまとめるモノイドの型 `M` を分けて指定する。

### 使い方
- 次の形の構造体 `R` を書き、`rerooting<R>` に渡す。

```cpp
struct R {
    using T = ...;  // 部分木の値
    using M = ...;  // 子をまとめるモノイド
    using E = ...;  // 辺に持たせるデータ。不要なら std::monostate
    using V = ...;  // 頂点に持たせるデータ。不要なら std::monostate
    static M put_edge(const T& x, const E& w, int u, int v);  // v 側の部分木の値 x を辺 (u, v) 経由で u へ持ち上げる
    static M merge(const M& a, const M& b);                   // モノイドの積。非可換でもよい
    static M e();                                             // 単位元
    static T put_vertex(const M& acc, const V& a, int v);     // 子をまとめた値 acc に頂点 v を足して部分木の値にする
};
```

- `rerooting<R>(n)`: $n$ 頂点で初期化する。頂点データは `V()`。
- `rerooting<R>(std::vector<V> a)`: 頂点データ `a` を持たせて初期化する。
- `add_edge(u, v, w = E())`: 辺を追加し、辺番号（追加順）を返す。
- `solve()`: 計算する。
- `dp[v]`: 全体を頂点 `v` を根として見たときの値。
- `agg[v]`: `dp[v]` を作る直前の、`v` の全隣接をまとめた `M` の値。
- `sub(u, v)`: 辺 $(u, v)$ を切ったときの `v` 側の部分木を `v` を根として見た値。
- `sub_by_edge(i, v)`: 辺 `i` を切ったときの `v` 側の部分木を `v` を根として見た値。
- `merge` の順序は各頂点の隣接を `add_edge` 順に並べたものに従う。

### 例
- 距離の総和: `T = M = {cnt, sum}`, `put_edge(x) = {x.cnt, x.sum + x.cnt}`, `merge` は成分ごとの和, `put_vertex(acc) = {acc.cnt + 1, acc.sum}`
- $\max_{j \ne i} (\mathrm{dist}(i, j) + d_j)$: `T = M = E = V = long long`, `put_edge(x, w) = x + w`, `merge = max`, `e = -∞`, `put_vertex(acc, d) = max(acc, d)`。答えは `agg[i]`
- 直径: `T` = 最大深さ, `M` = 深さの上位 2 つ。`T` と `M` が異なる例

### 計算量
- $\mathcal O(N)$ 回の `put_edge`, `merge`, `put_vertex` 呼び出し
