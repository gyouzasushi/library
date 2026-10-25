---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lowlink.hpp
    title: Lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unit/lowlink.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <random>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"graph/lowlink.hpp\"\n#include <algorithm>\n#line\
    \ 6 \"graph/lowlink.hpp\"\nstruct lowlink {\npublic:\n    lowlink() : lowlink(0)\
    \ {\n    }\n    explicit lowlink(int n) : _n(n), g(n), ord(n, -1), low(n), comp(n,\
    \ -1), art(n, false) {\n    }\n    int add_edge(int u, int v) {\n        assert(0\
    \ <= u && u < _n);\n        assert(0 <= v && v < _n);\n        int e = int(edges.size());\n\
    \        edges.emplace_back(u, v);\n        g[u].emplace_back(v, e);\n       \
    \ g[v].emplace_back(u, e);\n        return e;\n    }\n    void build() {\n   \
    \     int m = int(edges.size());\n        bridge.assign(m, false);\n        std::vector<int>\
    \ it(_n, 0), par_edge(_n, -1), children(_n, 0);\n        int t = 0;\n        for\
    \ (int r = 0; r < _n; r++) {\n            if (ord[r] != -1) continue;\n      \
    \      std::vector<int> st = {r};\n            ord[r] = low[r] = t++;\n      \
    \      while (!st.empty()) {\n                int v = st.back();\n           \
    \     if (it[v] < int(g[v].size())) {\n                    auto [u, e] = g[v][it[v]++];\n\
    \                    if (e == par_edge[v]) continue;\n                    if (ord[u]\
    \ == -1) {\n                        ord[u] = low[u] = t++;\n                 \
    \       par_edge[u] = e;\n                        children[v]++;\n           \
    \             st.push_back(u);\n                    } else {\n               \
    \         low[v] = std::min(low[v], ord[u]);\n                    }\n        \
    \        } else {\n                    st.pop_back();\n                    if\
    \ (st.empty()) continue;\n                    int p = st.back();\n           \
    \         low[p] = std::min(low[p], low[v]);\n                    if (low[v] >\
    \ ord[p]) bridge[par_edge[v]] = true;\n                    if (low[v] >= ord[p]\
    \ && p != r) art[p] = true;\n                }\n            }\n            art[r]\
    \ = children[r] >= 2;\n        }\n        _num_components = 0;\n        for (int\
    \ r = 0; r < _n; r++) {\n            if (comp[r] != -1) continue;\n          \
    \  comp[r] = _num_components;\n            std::vector<int> st = {r};\n      \
    \      while (!st.empty()) {\n                int v = st.back();\n           \
    \     st.pop_back();\n                for (auto [u, e] : g[v]) {\n           \
    \         if (bridge[e] || comp[u] != -1) continue;\n                    comp[u]\
    \ = _num_components;\n                    st.push_back(u);\n                }\n\
    \            }\n            _num_components++;\n        }\n    }\n    bool is_bridge(int\
    \ e) const {\n        assert(0 <= e && e < int(edges.size()));\n        return\
    \ bridge[e];\n    }\n    bool is_articulation(int v) const {\n        assert(0\
    \ <= v && v < _n);\n        return art[v];\n    }\n    std::vector<int> bridges()\
    \ const {\n        std::vector<int> res;\n        for (int e = 0; e < int(edges.size());\
    \ e++) {\n            if (bridge[e]) res.push_back(e);\n        }\n        return\
    \ res;\n    }\n    std::vector<int> articulation_points() const {\n        std::vector<int>\
    \ res;\n        for (int v = 0; v < _n; v++) {\n            if (art[v]) res.push_back(v);\n\
    \        }\n        return res;\n    }\n    int component(int v) const {\n   \
    \     assert(0 <= v && v < _n);\n        return comp[v];\n    }\n    std::vector<std::vector<int>>\
    \ two_edge_connected_components() const {\n        std::vector<std::vector<int>>\
    \ res(_num_components);\n        for (int v = 0; v < _n; v++) res[comp[v]].push_back(v);\n\
    \        return res;\n    }\n\nprivate:\n    int _n, _num_components = 0;\n  \
    \  std::vector<std::vector<std::pair<int, int>>> g;\n    std::vector<std::pair<int,\
    \ int>> edges;\n    std::vector<int> ord, low, comp;\n    std::vector<bool> art,\
    \ bridge;\n};\n#line 9 \"test/unit/lowlink.test.cpp\"\n\n// number of connected\
    \ components after removing vertex `skip_v` and edge `skip_e`\nint components(int\
    \ n, const std::vector<std::pair<int, int>>& edges, int skip_v, int skip_e) {\n\
    \    std::vector<std::vector<int>> g(n);\n    for (int e = 0; e < int(edges.size());\
    \ e++) {\n        if (e == skip_e) continue;\n        auto [u, v] = edges[e];\n\
    \        if (u == skip_v || v == skip_v) continue;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n    std::vector<bool> seen(n, false);\n  \
    \  int res = 0;\n    for (int r = 0; r < n; r++) {\n        if (r == skip_v ||\
    \ seen[r]) continue;\n        res++;\n        std::vector<int> st = {r};\n   \
    \     seen[r] = true;\n        while (!st.empty()) {\n            int v = st.back();\n\
    \            st.pop_back();\n            for (int u : g[v]) {\n              \
    \  if (!seen[u]) seen[u] = true, st.push_back(u);\n            }\n        }\n\
    \    }\n    return res;\n}\n\nint main() {\n    std::mt19937 rng(777);\n    for\
    \ (int it = 0; it < 500; it++) {\n        int n = 1 + rng() % 9;\n        int\
    \ m = rng() % 14;\n        std::vector<std::pair<int, int>> edges(m);\n      \
    \  for (auto& [u, v] : edges) u = rng() % n, v = rng() % n;  // multi-edges and\
    \ self-loops\n        lowlink g(n);\n        for (int e = 0; e < m; e++) assert(g.add_edge(edges[e].first,\
    \ edges[e].second) == e);\n        g.build();\n        int base = components(n,\
    \ edges, -1, -1);\n        std::vector<int> br, ap;\n        for (int e = 0; e\
    \ < m; e++) {\n            bool b = components(n, edges, -1, e) > base;\n    \
    \        assert(g.is_bridge(e) == b);\n            if (b) br.push_back(e);\n \
    \       }\n        assert(g.bridges() == br);\n        for (int v = 0; v < n;\
    \ v++) {\n            // removing v also removes v itself from the count\n   \
    \         bool a = components(n, edges, v, -1) > base;\n            assert(g.is_articulation(v)\
    \ == a);\n            if (a) ap.push_back(v);\n        }\n        assert(g.articulation_points()\
    \ == ap);\n        // same 2-edge-connected component <=> connected after removing\
    \ any single edge\n        auto groups = g.two_edge_connected_components();\n\
    \        std::vector<int> cnt(groups.size(), 0);\n        for (int c = 0; c <\
    \ int(groups.size()); c++) {\n            for (int v : groups[c]) assert(g.component(v)\
    \ == c), cnt[c]++;\n        }\n        int total = 0;\n        for (int x : cnt)\
    \ assert(x > 0), total += x;\n        assert(total == n);\n        for (int u\
    \ = 0; u < n; u++) {\n            for (int v = u + 1; v < n; v++) {\n        \
    \        bool same = true;\n                // connected in the graph without\
    \ bridges?\n                std::vector<std::pair<int, int>> nb;\n           \
    \     for (int e = 0; e < m; e++) if (!g.is_bridge(e)) nb.push_back(edges[e]);\n\
    \                std::vector<std::vector<int>> h(n);\n                for (auto\
    \ [a, b] : nb) h[a].push_back(b), h[b].push_back(a);\n                std::vector<bool>\
    \ seen(n, false);\n                std::vector<int> st = {u};\n              \
    \  seen[u] = true;\n                while (!st.empty()) {\n                  \
    \  int x = st.back();\n                    st.pop_back();\n                  \
    \  for (int y : h[x]) if (!seen[y]) seen[y] = true, st.push_back(y);\n       \
    \         }\n                same = seen[v];\n                assert((g.component(u)\
    \ == g.component(v)) == same);\n            }\n        }\n    }\n    // long path:\
    \ no recursion, so n = 200000 must not overflow the stack\n    {\n        int\
    \ n = 200000;\n        lowlink g(n);\n        for (int i = 0; i + 1 < n; i++)\
    \ g.add_edge(i, i + 1);\n        g.build();\n        assert(int(g.bridges().size())\
    \ == n - 1);\n        assert(int(g.articulation_points().size()) == n - 2);\n\
    \        assert(g.two_edge_connected_components().size() == size_t(n));\n    }\n\
    \    std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <random>\n#include <utility>\n\
    #include <vector>\n\n#include \"graph/lowlink.hpp\"\n\n// number of connected\
    \ components after removing vertex `skip_v` and edge `skip_e`\nint components(int\
    \ n, const std::vector<std::pair<int, int>>& edges, int skip_v, int skip_e) {\n\
    \    std::vector<std::vector<int>> g(n);\n    for (int e = 0; e < int(edges.size());\
    \ e++) {\n        if (e == skip_e) continue;\n        auto [u, v] = edges[e];\n\
    \        if (u == skip_v || v == skip_v) continue;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n    std::vector<bool> seen(n, false);\n  \
    \  int res = 0;\n    for (int r = 0; r < n; r++) {\n        if (r == skip_v ||\
    \ seen[r]) continue;\n        res++;\n        std::vector<int> st = {r};\n   \
    \     seen[r] = true;\n        while (!st.empty()) {\n            int v = st.back();\n\
    \            st.pop_back();\n            for (int u : g[v]) {\n              \
    \  if (!seen[u]) seen[u] = true, st.push_back(u);\n            }\n        }\n\
    \    }\n    return res;\n}\n\nint main() {\n    std::mt19937 rng(777);\n    for\
    \ (int it = 0; it < 500; it++) {\n        int n = 1 + rng() % 9;\n        int\
    \ m = rng() % 14;\n        std::vector<std::pair<int, int>> edges(m);\n      \
    \  for (auto& [u, v] : edges) u = rng() % n, v = rng() % n;  // multi-edges and\
    \ self-loops\n        lowlink g(n);\n        for (int e = 0; e < m; e++) assert(g.add_edge(edges[e].first,\
    \ edges[e].second) == e);\n        g.build();\n        int base = components(n,\
    \ edges, -1, -1);\n        std::vector<int> br, ap;\n        for (int e = 0; e\
    \ < m; e++) {\n            bool b = components(n, edges, -1, e) > base;\n    \
    \        assert(g.is_bridge(e) == b);\n            if (b) br.push_back(e);\n \
    \       }\n        assert(g.bridges() == br);\n        for (int v = 0; v < n;\
    \ v++) {\n            // removing v also removes v itself from the count\n   \
    \         bool a = components(n, edges, v, -1) > base;\n            assert(g.is_articulation(v)\
    \ == a);\n            if (a) ap.push_back(v);\n        }\n        assert(g.articulation_points()\
    \ == ap);\n        // same 2-edge-connected component <=> connected after removing\
    \ any single edge\n        auto groups = g.two_edge_connected_components();\n\
    \        std::vector<int> cnt(groups.size(), 0);\n        for (int c = 0; c <\
    \ int(groups.size()); c++) {\n            for (int v : groups[c]) assert(g.component(v)\
    \ == c), cnt[c]++;\n        }\n        int total = 0;\n        for (int x : cnt)\
    \ assert(x > 0), total += x;\n        assert(total == n);\n        for (int u\
    \ = 0; u < n; u++) {\n            for (int v = u + 1; v < n; v++) {\n        \
    \        bool same = true;\n                // connected in the graph without\
    \ bridges?\n                std::vector<std::pair<int, int>> nb;\n           \
    \     for (int e = 0; e < m; e++) if (!g.is_bridge(e)) nb.push_back(edges[e]);\n\
    \                std::vector<std::vector<int>> h(n);\n                for (auto\
    \ [a, b] : nb) h[a].push_back(b), h[b].push_back(a);\n                std::vector<bool>\
    \ seen(n, false);\n                std::vector<int> st = {u};\n              \
    \  seen[u] = true;\n                while (!st.empty()) {\n                  \
    \  int x = st.back();\n                    st.pop_back();\n                  \
    \  for (int y : h[x]) if (!seen[y]) seen[y] = true, st.push_back(y);\n       \
    \         }\n                same = seen[v];\n                assert((g.component(u)\
    \ == g.component(v)) == same);\n            }\n        }\n    }\n    // long path:\
    \ no recursion, so n = 200000 must not overflow the stack\n    {\n        int\
    \ n = 200000;\n        lowlink g(n);\n        for (int i = 0; i + 1 < n; i++)\
    \ g.add_edge(i, i + 1);\n        g.build();\n        assert(int(g.bridges().size())\
    \ == n - 1);\n        assert(int(g.articulation_points().size()) == n - 2);\n\
    \        assert(g.two_edge_connected_components().size() == size_t(n));\n    }\n\
    \    std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - graph/lowlink.hpp
  isVerificationFile: true
  path: test/unit/lowlink.test.cpp
  requiredBy: []
  timestamp: '2026-10-25 23:38:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/lowlink.test.cpp
layout: document
redirect_from:
- /verify/test/unit/lowlink.test.cpp
- /verify/test/unit/lowlink.test.cpp.html
title: test/unit/lowlink.test.cpp
---
