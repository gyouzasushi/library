---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_E.test.cpp
    title: test/aoj/GRL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/jump_on_tree.test.cpp
    title: test/library-checker/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/lca_heavy_light_decomposition.test.cpp
    title: test/library-checker/lca_heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/vertex_add_path_sum.test.cpp
    title: test/library-checker/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/vertex_add_subtree_sum.test.cpp
    title: test/library-checker/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/vertex_set_path_composite.test.cpp
    title: test/library-checker/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/heavy_light_decomposition.test.cpp
    title: test/unit/heavy_light_decomposition.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/heavy_light_decomposition.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\nstruct heavy_light_decomposition\
    \ {\npublic:\n    heavy_light_decomposition() {\n    }\n    heavy_light_decomposition(int\
    \ n, int root = 0)\n        : _n(n),\n          _root(root),\n          g(n),\n\
    \          sub(n),\n          dep(n),\n          par(n),\n          heavy(n, -1),\n\
    \          head(n),\n          in(n),\n          out(n),\n          rev(n) {\n\
    \    }\n    void add_edge(int u, int v) {\n        assert(0 <= u && u < _n);\n\
    \        assert(0 <= v && v < _n);\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \        edges.emplace_back(u, v);\n    }\n    void build() {\n        par[_root]\
    \ = -1;\n        dep[_root] = 0;\n        std::vector<int> order, st = {_root};\n\
    \        order.reserve(_n);\n        while (!st.empty()) {\n            int v\
    \ = st.back();\n            st.pop_back();\n            order.push_back(v);\n\
    \            for (int c : g[v]) {\n                if (c == par[v]) continue;\n\
    \                par[c] = v;\n                dep[c] = dep[v] + 1;\n         \
    \       st.push_back(c);\n            }\n        }\n        for (int i = _n -\
    \ 1; i >= 0; i--) {\n            int v = order[i], p = par[v];\n            sub[v]++;\n\
    \            if (p == -1) continue;\n            sub[p] += sub[v];\n         \
    \   if (heavy[p] == -1 || sub[v] > sub[heavy[p]]) heavy[p] = v;\n        }\n \
    \       int t = 0;\n        head[_root] = _root;\n        st = {_root};\n    \
    \    while (!st.empty()) {\n            int v = st.back();\n            st.pop_back();\n\
    \            in[v] = t++;\n            rev[in[v]] = v;\n            out[v] = in[v]\
    \ + sub[v];\n            for (int c : g[v]) {\n                if (c == par[v]\
    \ || c == heavy[v]) continue;\n                head[c] = c;\n                st.push_back(c);\n\
    \            }\n            if (heavy[v] != -1) {\n                head[heavy[v]]\
    \ = head[v];\n                st.push_back(heavy[v]);\n            }\n       \
    \ }\n    }\n\n    int index(int v) const {\n        return in[v];\n    }\n   \
    \ int vertex(int i) const {\n        return rev[i];\n    }\n    std::pair<int,\
    \ int> subtree(int v) const {\n        return {in[v], out[v]};\n    }\n    int\
    \ edge_index(int i) const {\n        assert(0 <= i && i < (int)edges.size());\n\
    \        auto [u, v] = edges[i];\n        return in[par[u] == v ? u : v];\n  \
    \  }\n    int depth(int v) const {\n        return dep[v];\n    }\n    int parent(int\
    \ v) const {\n        return par[v];\n    }\n    int head_of(int v) const {\n\
    \        return head[v];\n    }\n    int lca(int u, int v) const {\n        while\
    \ (head[u] != head[v]) {\n            if (dep[head[u]] < dep[head[v]]) std::swap(u,\
    \ v);\n            u = par[head[u]];\n        }\n        return dep[u] < dep[v]\
    \ ? u : v;\n    }\n    int lca(int u, int v, int r) const {\n        return lca(u,\
    \ v) ^ lca(v, r) ^ lca(r, u);\n    }\n    int dist(int u, int v) const {\n   \
    \     return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n    int la(int v, int\
    \ k) const {\n        if (k < 0 || dep[v] < k) return -1;\n        while (dep[v]\
    \ - dep[head[v]] < k) {\n            k -= dep[v] - dep[head[v]] + 1;\n       \
    \     v = par[head[v]];\n        }\n        return rev[in[v] - k];\n    }\n  \
    \  int jump(int s, int t, int k) const {\n        int l = lca(s, t);\n       \
    \ int d = dep[s] + dep[t] - 2 * dep[l];\n        if (k < 0 || d < k) return -1;\n\
    \        if (k <= dep[s] - dep[l]) return la(s, k);\n        return la(t, d -\
    \ k);\n    }\n    bool in_subtree(int u, int v) const {\n        return in[u]\
    \ <= in[v] && in[v] < out[u];\n    }\n    bool on_path(int s, int t, int x) const\
    \ {\n        return dist(s, x) + dist(x, t) == dist(s, t);\n    }\n\n    template\
    \ <typename F>\n    void for_each_vertex(int u, int v, const F& f) const {\n \
    \       for_each(u, v, false, f);\n    }\n    template <typename F>\n    void\
    \ for_each_edge(int u, int v, const F& f) const {\n        for_each(u, v, true,\
    \ f);\n    }\n    template <typename F>\n    void for_each_vertex_noncommutative(int\
    \ u, int v, const F& f) const {\n        for_each_noncommutative(u, v, false,\
    \ f);\n    }\n    template <typename F>\n    void for_each_edge_noncommutative(int\
    \ u, int v, const F& f) const {\n        for_each_noncommutative(u, v, true, f);\n\
    \    }\n    template <typename F>\n    void for_each_vertex_in_subtree(int v,\
    \ const F& f) const {\n        f(in[v], out[v]);\n    }\n    template <typename\
    \ F>\n    void for_each_edge_in_subtree(int v, const F& f) const {\n        if\
    \ (in[v] + 1 < out[v]) f(in[v] + 1, out[v]);\n    }\n\nprivate:\n    int _n, _root;\n\
    \    std::vector<std::vector<int>> g;\n    std::vector<std::pair<int, int>> edges;\n\
    \    std::vector<int> sub, dep, par, heavy, head, in, out, rev;\n    template\
    \ <typename F>\n    void for_each(int u, int v, bool edge, const F& f) const {\n\
    \        while (head[u] != head[v]) {\n            if (dep[head[u]] < dep[head[v]])\
    \ std::swap(u, v);\n            f(in[head[u]], in[u] + 1);\n            u = par[head[u]];\n\
    \        }\n        if (dep[u] > dep[v]) std::swap(u, v);\n        if (in[u] +\
    \ edge < in[v] + 1) f(in[u] + edge, in[v] + 1);\n    }\n    template <typename\
    \ F>\n    void for_each_noncommutative(int u, int v, bool edge, const F& f) const\
    \ {\n        std::vector<std::pair<int, int>> down;\n        while (head[u] !=\
    \ head[v]) {\n            if (dep[head[u]] >= dep[head[v]]) {\n              \
    \  f(in[u] + 1, in[head[u]]);\n                u = par[head[u]];\n           \
    \ } else {\n                down.emplace_back(in[head[v]], in[v] + 1);\n     \
    \           v = par[head[v]];\n            }\n        }\n        if (dep[u] >\
    \ dep[v]) {\n            if (in[v] + edge < in[u] + 1) f(in[u] + 1, in[v] + edge);\n\
    \        } else {\n            if (in[u] + edge < in[v] + 1) f(in[u] + edge, in[v]\
    \ + 1);\n        }\n        for (auto it = down.rbegin(); it != down.rend(); it++)\
    \ {\n            f(it->first, it->second);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\nstruct heavy_light_decomposition {\npublic:\n    heavy_light_decomposition()\
    \ {\n    }\n    heavy_light_decomposition(int n, int root = 0)\n        : _n(n),\n\
    \          _root(root),\n          g(n),\n          sub(n),\n          dep(n),\n\
    \          par(n),\n          heavy(n, -1),\n          head(n),\n          in(n),\n\
    \          out(n),\n          rev(n) {\n    }\n    void add_edge(int u, int v)\
    \ {\n        assert(0 <= u && u < _n);\n        assert(0 <= v && v < _n);\n  \
    \      g[u].push_back(v);\n        g[v].push_back(u);\n        edges.emplace_back(u,\
    \ v);\n    }\n    void build() {\n        par[_root] = -1;\n        dep[_root]\
    \ = 0;\n        std::vector<int> order, st = {_root};\n        order.reserve(_n);\n\
    \        while (!st.empty()) {\n            int v = st.back();\n            st.pop_back();\n\
    \            order.push_back(v);\n            for (int c : g[v]) {\n         \
    \       if (c == par[v]) continue;\n                par[c] = v;\n            \
    \    dep[c] = dep[v] + 1;\n                st.push_back(c);\n            }\n \
    \       }\n        for (int i = _n - 1; i >= 0; i--) {\n            int v = order[i],\
    \ p = par[v];\n            sub[v]++;\n            if (p == -1) continue;\n   \
    \         sub[p] += sub[v];\n            if (heavy[p] == -1 || sub[v] > sub[heavy[p]])\
    \ heavy[p] = v;\n        }\n        int t = 0;\n        head[_root] = _root;\n\
    \        st = {_root};\n        while (!st.empty()) {\n            int v = st.back();\n\
    \            st.pop_back();\n            in[v] = t++;\n            rev[in[v]]\
    \ = v;\n            out[v] = in[v] + sub[v];\n            for (int c : g[v]) {\n\
    \                if (c == par[v] || c == heavy[v]) continue;\n               \
    \ head[c] = c;\n                st.push_back(c);\n            }\n            if\
    \ (heavy[v] != -1) {\n                head[heavy[v]] = head[v];\n            \
    \    st.push_back(heavy[v]);\n            }\n        }\n    }\n\n    int index(int\
    \ v) const {\n        return in[v];\n    }\n    int vertex(int i) const {\n  \
    \      return rev[i];\n    }\n    std::pair<int, int> subtree(int v) const {\n\
    \        return {in[v], out[v]};\n    }\n    int edge_index(int i) const {\n \
    \       assert(0 <= i && i < (int)edges.size());\n        auto [u, v] = edges[i];\n\
    \        return in[par[u] == v ? u : v];\n    }\n    int depth(int v) const {\n\
    \        return dep[v];\n    }\n    int parent(int v) const {\n        return\
    \ par[v];\n    }\n    int head_of(int v) const {\n        return head[v];\n  \
    \  }\n    int lca(int u, int v) const {\n        while (head[u] != head[v]) {\n\
    \            if (dep[head[u]] < dep[head[v]]) std::swap(u, v);\n            u\
    \ = par[head[u]];\n        }\n        return dep[u] < dep[v] ? u : v;\n    }\n\
    \    int lca(int u, int v, int r) const {\n        return lca(u, v) ^ lca(v, r)\
    \ ^ lca(r, u);\n    }\n    int dist(int u, int v) const {\n        return dep[u]\
    \ + dep[v] - 2 * dep[lca(u, v)];\n    }\n    int la(int v, int k) const {\n  \
    \      if (k < 0 || dep[v] < k) return -1;\n        while (dep[v] - dep[head[v]]\
    \ < k) {\n            k -= dep[v] - dep[head[v]] + 1;\n            v = par[head[v]];\n\
    \        }\n        return rev[in[v] - k];\n    }\n    int jump(int s, int t,\
    \ int k) const {\n        int l = lca(s, t);\n        int d = dep[s] + dep[t]\
    \ - 2 * dep[l];\n        if (k < 0 || d < k) return -1;\n        if (k <= dep[s]\
    \ - dep[l]) return la(s, k);\n        return la(t, d - k);\n    }\n    bool in_subtree(int\
    \ u, int v) const {\n        return in[u] <= in[v] && in[v] < out[u];\n    }\n\
    \    bool on_path(int s, int t, int x) const {\n        return dist(s, x) + dist(x,\
    \ t) == dist(s, t);\n    }\n\n    template <typename F>\n    void for_each_vertex(int\
    \ u, int v, const F& f) const {\n        for_each(u, v, false, f);\n    }\n  \
    \  template <typename F>\n    void for_each_edge(int u, int v, const F& f) const\
    \ {\n        for_each(u, v, true, f);\n    }\n    template <typename F>\n    void\
    \ for_each_vertex_noncommutative(int u, int v, const F& f) const {\n        for_each_noncommutative(u,\
    \ v, false, f);\n    }\n    template <typename F>\n    void for_each_edge_noncommutative(int\
    \ u, int v, const F& f) const {\n        for_each_noncommutative(u, v, true, f);\n\
    \    }\n    template <typename F>\n    void for_each_vertex_in_subtree(int v,\
    \ const F& f) const {\n        f(in[v], out[v]);\n    }\n    template <typename\
    \ F>\n    void for_each_edge_in_subtree(int v, const F& f) const {\n        if\
    \ (in[v] + 1 < out[v]) f(in[v] + 1, out[v]);\n    }\n\nprivate:\n    int _n, _root;\n\
    \    std::vector<std::vector<int>> g;\n    std::vector<std::pair<int, int>> edges;\n\
    \    std::vector<int> sub, dep, par, heavy, head, in, out, rev;\n    template\
    \ <typename F>\n    void for_each(int u, int v, bool edge, const F& f) const {\n\
    \        while (head[u] != head[v]) {\n            if (dep[head[u]] < dep[head[v]])\
    \ std::swap(u, v);\n            f(in[head[u]], in[u] + 1);\n            u = par[head[u]];\n\
    \        }\n        if (dep[u] > dep[v]) std::swap(u, v);\n        if (in[u] +\
    \ edge < in[v] + 1) f(in[u] + edge, in[v] + 1);\n    }\n    template <typename\
    \ F>\n    void for_each_noncommutative(int u, int v, bool edge, const F& f) const\
    \ {\n        std::vector<std::pair<int, int>> down;\n        while (head[u] !=\
    \ head[v]) {\n            if (dep[head[u]] >= dep[head[v]]) {\n              \
    \  f(in[u] + 1, in[head[u]]);\n                u = par[head[u]];\n           \
    \ } else {\n                down.emplace_back(in[head[v]], in[v] + 1);\n     \
    \           v = par[head[v]];\n            }\n        }\n        if (dep[u] >\
    \ dep[v]) {\n            if (in[v] + edge < in[u] + 1) f(in[u] + 1, in[v] + edge);\n\
    \        } else {\n            if (in[u] + edge < in[v] + 1) f(in[u] + edge, in[v]\
    \ + 1);\n        }\n        for (auto it = down.rbegin(); it != down.rend(); it++)\
    \ {\n            f(it->first, it->second);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2026-10-19 02:29:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_E.test.cpp
  - test/library-checker/lca_heavy_light_decomposition.test.cpp
  - test/library-checker/vertex_set_path_composite.test.cpp
  - test/library-checker/vertex_add_subtree_sum.test.cpp
  - test/library-checker/jump_on_tree.test.cpp
  - test/library-checker/vertex_add_path_sum.test.cpp
  - test/unit/heavy_light_decomposition.test.cpp
documentation_of: graph/heavy_light_decomposition.hpp
layout: document
title: "HL\u5206\u89E3 (Heavy-Light Decomposition)"
---

### 概要
- 木をパスに分解し、パスや部分木に対するクエリを区間クエリに帰着させる。
- 各頂点 `v` には番号 `index(v)` が振られ、部分木は番号の連続区間、任意のパスは $\mathcal O(\log N)$ 個の連続区間になる。

### 使い方
- `heavy_light_decomposition(n, root = 0)`: $\mathrm n$ 頂点で初期化する。頂点 `root` が根になる。
- `add_edge(u, v)`: 頂点 `u` と頂点 `v` とを結ぶ辺を追加する。
- `build()`: 構築する。
- `index(v)`: 頂点 `v` の番号を返す。
- `vertex(i)`: 番号 `i` の頂点を返す。
- `subtree(v)`: 頂点 `v` の部分木に対応する番号の区間 $[l, r)$ を返す。
- `edge_index(i)`: `i` 番目に `add_edge` した辺の番号を返す。辺の番号は子側の頂点の番号で、辺に値を持たせるときの格納位置になる。
- `depth(v)`: 頂点 `v` の深さを返す。
- `parent(v)`: 頂点 `v` の親を返す。根なら `-1`。
- `head_of(v)`: 頂点 `v` を含む heavy path の最も浅い頂点を返す。
- `lca(u, v)`: 頂点 `u` と頂点 `v` のLCAを返す。
- `lca(u, v, r)`: 頂点 `r` を根とみたときの、頂点 `u` と頂点 `v` のLCAを返す。
- `dist(u, v)`: 頂点 `u` と頂点 `v` との距離を返す。
- `la(v, k)`: 頂点 `v` の `k` 個上の祖先を返す。存在しなければ `-1`。
- `jump(s, t, k)`: 頂点 `s` から頂点 `t` へ向かって `k` 回進んだ頂点を返す。存在しなければ `-1`。
- `in_subtree(u, v)`: 頂点 `v` が頂点 `u` の部分木に含まれるか判定する。
- `on_path(s, t, x)`: 頂点 `x` が `s`-`t` パス上にあるか判定する。
- `for_each_vertex(u, v, f)`: `u`-`v` パス上の頂点を番号の区間に分解し、各区間について `f(l, r)` を呼ぶ。
- `for_each_edge(u, v, f)`: `u`-`v` パス上の辺を番号の区間に分解し、各区間について `f(l, r)` を呼ぶ。辺は子側の頂点の番号で表す。
- `for_each_vertex_noncommutative(u, v, f)`: `u` から `v` へ向かう順に区間を `f(a, b)` で呼ぶ。`a < b` なら区間 $[a, b)$ を昇順に、`a > b` なら区間 $[b, a)$ を降順に辿る。
- `for_each_edge_noncommutative(u, v, f)`: 辺版。
- `for_each_vertex_in_subtree(v, f)`: 頂点 `v` の部分木に含まれる頂点の区間について `f(l, r)` を呼ぶ。
- `for_each_edge_in_subtree(v, f)`: 頂点 `v` の部分木に含まれる辺の区間について `f(l, r)` を呼ぶ。

### 計算量
- 構築 $\mathcal O(N)$
- `lca`, `dist`, `la`, `jump`: $\mathcal O(\log N)$
- `for_each_*`: 区間の個数は $\mathcal O(\log N)$ 個
