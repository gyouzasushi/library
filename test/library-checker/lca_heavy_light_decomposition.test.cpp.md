---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/heavy_light_decomposition.hpp
    title: "HL\u5206\u89E3 (Heavy-Light Decomposition)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/library-checker/lca_heavy_light_decomposition.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include <iostream>\n\
    \n#line 2 \"graph/heavy_light_decomposition.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\nstruct heavy_light_decomposition\
    \ {\npublic:\n    heavy_light_decomposition() {\n    }\n    heavy_light_decomposition(int\
    \ n, int root = 0)\n        : _n(n),\n          _root(root),\n          g(n),\n\
    \          sz(n),\n          dep(n),\n          par(n),\n          heavy(n, -1),\n\
    \          head(n),\n          in(n),\n          out(n),\n          rev(n) {\n\
    \    }\n    void add_edge(int u, int v) {\n        assert(0 <= u && u < _n);\n\
    \        assert(0 <= v && v < _n);\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \    }\n    void build() {\n        par[_root] = -1;\n        dep[_root] = 0;\n\
    \        std::vector<int> order, st = {_root};\n        order.reserve(_n);\n \
    \       while (!st.empty()) {\n            int v = st.back();\n            st.pop_back();\n\
    \            order.push_back(v);\n            for (int c : g[v]) {\n         \
    \       if (c == par[v]) continue;\n                par[c] = v;\n            \
    \    dep[c] = dep[v] + 1;\n                st.push_back(c);\n            }\n \
    \       }\n        for (int i = _n - 1; i >= 0; i--) {\n            int v = order[i],\
    \ p = par[v];\n            sz[v]++;\n            if (p == -1) continue;\n    \
    \        sz[p] += sz[v];\n            if (heavy[p] == -1 || sz[v] > sz[heavy[p]])\
    \ heavy[p] = v;\n        }\n        int t = 0;\n        head[_root] = _root;\n\
    \        st = {_root};\n        while (!st.empty()) {\n            int v = st.back();\n\
    \            st.pop_back();\n            in[v] = t++;\n            rev[in[v]]\
    \ = v;\n            out[v] = in[v] + sz[v];\n            for (int c : g[v]) {\n\
    \                if (c == par[v] || c == heavy[v]) continue;\n               \
    \ head[c] = c;\n                st.push_back(c);\n            }\n            if\
    \ (heavy[v] != -1) {\n                head[heavy[v]] = head[v];\n            \
    \    st.push_back(heavy[v]);\n            }\n        }\n    }\n\n    int index(int\
    \ v) const {\n        return in[v];\n    }\n    int vertex(int i) const {\n  \
    \      return rev[i];\n    }\n    std::pair<int, int> subtree(int v) const {\n\
    \        return {in[v], out[v]};\n    }\n    int depth(int v) const {\n      \
    \  return dep[v];\n    }\n    int parent(int v) const {\n        return par[v];\n\
    \    }\n    int head_of(int v) const {\n        return head[v];\n    }\n    int\
    \ lca(int u, int v) const {\n        while (head[u] != head[v]) {\n          \
    \  if (dep[head[u]] < dep[head[v]]) std::swap(u, v);\n            u = par[head[u]];\n\
    \        }\n        return dep[u] < dep[v] ? u : v;\n    }\n    int lca(int u,\
    \ int v, int r) const {\n        return lca(u, v) ^ lca(v, r) ^ lca(r, u);\n \
    \   }\n    int dist(int u, int v) const {\n        return dep[u] + dep[v] - 2\
    \ * dep[lca(u, v)];\n    }\n    int la(int v, int k) const {\n        if (k <\
    \ 0 || dep[v] < k) return -1;\n        while (dep[v] - dep[head[v]] < k) {\n \
    \           k -= dep[v] - dep[head[v]] + 1;\n            v = par[head[v]];\n \
    \       }\n        return rev[in[v] - k];\n    }\n    int jump(int s, int t, int\
    \ k) const {\n        int l = lca(s, t);\n        int d = dep[s] + dep[t] - 2\
    \ * dep[l];\n        if (k < 0 || d < k) return -1;\n        if (k <= dep[s] -\
    \ dep[l]) return la(s, k);\n        return la(t, d - k);\n    }\n    bool in_subtree(int\
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
    \    std::vector<std::vector<int>> g;\n    std::vector<int> sz, dep, par, heavy,\
    \ head, in, out, rev;\n    template <typename F>\n    void for_each(int u, int\
    \ v, bool edge, const F& f) const {\n        while (head[u] != head[v]) {\n  \
    \          if (dep[head[u]] < dep[head[v]]) std::swap(u, v);\n            f(in[head[u]],\
    \ in[u] + 1);\n            u = par[head[u]];\n        }\n        if (dep[u] >\
    \ dep[v]) std::swap(u, v);\n        if (in[u] + edge < in[v] + 1) f(in[u] + edge,\
    \ in[v] + 1);\n    }\n    template <typename F>\n    void for_each_noncommutative(int\
    \ u, int v, bool edge, const F& f) const {\n        std::vector<std::pair<int,\
    \ int>> down;\n        while (head[u] != head[v]) {\n            if (dep[head[u]]\
    \ >= dep[head[v]]) {\n                f(in[u] + 1, in[head[u]]);\n           \
    \     u = par[head[u]];\n            } else {\n                down.emplace_back(in[head[v]],\
    \ in[v] + 1);\n                v = par[head[v]];\n            }\n        }\n \
    \       if (dep[u] > dep[v]) {\n            if (in[v] + edge < in[u] + 1) f(in[u]\
    \ + 1, in[v] + edge);\n        } else {\n            if (in[u] + edge < in[v]\
    \ + 1) f(in[u] + edge, in[v] + 1);\n        }\n        for (auto it = down.rbegin();\
    \ it != down.rend(); it++) {\n            f(it->first, it->second);\n        }\n\
    \    }\n};\n#line 5 \"test/library-checker/lca_heavy_light_decomposition.test.cpp\"\
    \nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    heavy_light_decomposition\
    \ hld(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n        std::cin\
    \ >> p;\n        hld.add_edge(i, p);\n    }\n    hld.build();\n    while (q--)\
    \ {\n        int u, v;\n        std::cin >> u >> v;\n        std::cout << hld.lca(u,\
    \ v) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include <iostream>\n\
    \n#include \"graph/heavy_light_decomposition.hpp\"\nint main() {\n    int n, q;\n\
    \    std::cin >> n >> q;\n    heavy_light_decomposition hld(n);\n    for (int\
    \ i = 1; i < n; i++) {\n        int p;\n        std::cin >> p;\n        hld.add_edge(i,\
    \ p);\n    }\n    hld.build();\n    while (q--) {\n        int u, v;\n       \
    \ std::cin >> u >> v;\n        std::cout << hld.lca(u, v) << '\\n';\n    }\n}\n"
  dependsOn:
  - graph/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: test/library-checker/lca_heavy_light_decomposition.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 14:39:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/lca_heavy_light_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/lca_heavy_light_decomposition.test.cpp
- /verify/test/library-checker/lca_heavy_light_decomposition.test.cpp.html
title: test/library-checker/lca_heavy_light_decomposition.test.cpp
---
