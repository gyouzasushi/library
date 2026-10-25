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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B
  bundledCode: "#line 1 \"test/aoj/GRL_3_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B\"\
    \n#include <algorithm>\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    \n#line 3 \"graph/lowlink.hpp\"\n#include <cassert>\n#line 6 \"graph/lowlink.hpp\"\
    \nstruct lowlink {\npublic:\n    lowlink() : lowlink(0) {\n    }\n    explicit\
    \ lowlink(int n) : _n(n), g(n), ord(n, -1), low(n), comp(n, -1), art(n, false)\
    \ {\n    }\n    int add_edge(int u, int v) {\n        assert(0 <= u && u < _n);\n\
    \        assert(0 <= v && v < _n);\n        int e = int(edges.size());\n     \
    \   edges.emplace_back(u, v);\n        g[u].emplace_back(v, e);\n        g[v].emplace_back(u,\
    \ e);\n        return e;\n    }\n    void build() {\n        int m = int(edges.size());\n\
    \        bridge.assign(m, false);\n        std::vector<int> it(_n, 0), par_edge(_n,\
    \ -1), children(_n, 0);\n        int t = 0;\n        for (int r = 0; r < _n; r++)\
    \ {\n            if (ord[r] != -1) continue;\n            std::vector<int> st\
    \ = {r};\n            ord[r] = low[r] = t++;\n            while (!st.empty())\
    \ {\n                int v = st.back();\n                if (it[v] < int(g[v].size()))\
    \ {\n                    auto [u, e] = g[v][it[v]++];\n                    if\
    \ (e == par_edge[v]) continue;\n                    if (ord[u] == -1) {\n    \
    \                    ord[u] = low[u] = t++;\n                        par_edge[u]\
    \ = e;\n                        children[v]++;\n                        st.push_back(u);\n\
    \                    } else {\n                        low[v] = std::min(low[v],\
    \ ord[u]);\n                    }\n                } else {\n                \
    \    st.pop_back();\n                    if (st.empty()) continue;\n         \
    \           int p = st.back();\n                    low[p] = std::min(low[p],\
    \ low[v]);\n                    if (low[v] > ord[p]) bridge[par_edge[v]] = true;\n\
    \                    if (low[v] >= ord[p] && p != r) art[p] = true;\n        \
    \        }\n            }\n            art[r] = children[r] >= 2;\n        }\n\
    \        _num_components = 0;\n        for (int r = 0; r < _n; r++) {\n      \
    \      if (comp[r] != -1) continue;\n            comp[r] = _num_components;\n\
    \            std::vector<int> st = {r};\n            while (!st.empty()) {\n \
    \               int v = st.back();\n                st.pop_back();\n         \
    \       for (auto [u, e] : g[v]) {\n                    if (bridge[e] || comp[u]\
    \ != -1) continue;\n                    comp[u] = _num_components;\n         \
    \           st.push_back(u);\n                }\n            }\n            _num_components++;\n\
    \        }\n    }\n    bool is_bridge(int e) const {\n        assert(0 <= e &&\
    \ e < int(edges.size()));\n        return bridge[e];\n    }\n    bool is_articulation(int\
    \ v) const {\n        assert(0 <= v && v < _n);\n        return art[v];\n    }\n\
    \    std::vector<int> bridges() const {\n        std::vector<int> res;\n     \
    \   for (int e = 0; e < int(edges.size()); e++) {\n            if (bridge[e])\
    \ res.push_back(e);\n        }\n        return res;\n    }\n    std::vector<int>\
    \ articulation_points() const {\n        std::vector<int> res;\n        for (int\
    \ v = 0; v < _n; v++) {\n            if (art[v]) res.push_back(v);\n        }\n\
    \        return res;\n    }\n    int component(int v) const {\n        assert(0\
    \ <= v && v < _n);\n        return comp[v];\n    }\n    std::vector<std::vector<int>>\
    \ two_edge_connected_components() const {\n        std::vector<std::vector<int>>\
    \ res(_num_components);\n        for (int v = 0; v < _n; v++) res[comp[v]].push_back(v);\n\
    \        return res;\n    }\n\nprivate:\n    int _n, _num_components = 0;\n  \
    \  std::vector<std::vector<std::pair<int, int>>> g;\n    std::vector<std::pair<int,\
    \ int>> edges;\n    std::vector<int> ord, low, comp;\n    std::vector<bool> art,\
    \ bridge;\n};\n#line 8 \"test/aoj/GRL_3_B.test.cpp\"\n\nint main() {\n    int\
    \ n, m;\n    std::cin >> n >> m;\n    lowlink g(n);\n    std::vector<std::pair<int,\
    \ int>> edges(m);\n    for (auto& [s, t] : edges) {\n        std::cin >> s >>\
    \ t;\n        if (s > t) std::swap(s, t);\n        g.add_edge(s, t);\n    }\n\
    \    g.build();\n    std::vector<std::pair<int, int>> res;\n    for (int e : g.bridges())\
    \ res.push_back(edges[e]);\n    std::sort(res.begin(), res.end());\n    for (auto\
    \ [s, t] : res) std::cout << s << ' ' << t << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B\"\n#include\
    \ <algorithm>\n#include <iostream>\n#include <utility>\n#include <vector>\n\n\
    #include \"graph/lowlink.hpp\"\n\nint main() {\n    int n, m;\n    std::cin >>\
    \ n >> m;\n    lowlink g(n);\n    std::vector<std::pair<int, int>> edges(m);\n\
    \    for (auto& [s, t] : edges) {\n        std::cin >> s >> t;\n        if (s\
    \ > t) std::swap(s, t);\n        g.add_edge(s, t);\n    }\n    g.build();\n  \
    \  std::vector<std::pair<int, int>> res;\n    for (int e : g.bridges()) res.push_back(edges[e]);\n\
    \    std::sort(res.begin(), res.end());\n    for (auto [s, t] : res) std::cout\
    \ << s << ' ' << t << '\\n';\n}\n"
  dependsOn:
  - graph/lowlink.hpp
  isVerificationFile: true
  path: test/aoj/GRL_3_B.test.cpp
  requiredBy: []
  timestamp: '2026-10-25 23:38:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_3_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_B.test.cpp
- /verify/test/aoj/GRL_3_B.test.cpp.html
title: test/aoj/GRL_3_B.test.cpp
---
