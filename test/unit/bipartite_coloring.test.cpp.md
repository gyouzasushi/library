---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bipartite_coloring.hpp
    title: Bipartite Coloring
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
  bundledCode: "#line 1 \"test/unit/bipartite_coloring.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <cassert>\n#include <iostream>\n#include <random>\n#include <set>\n#include\
    \ <vector>\n\n#line 2 \"graph/bipartite_coloring.hpp\"\n#include <algorithm>\n\
    #line 4 \"graph/bipartite_coloring.hpp\"\n#include <utility>\n#line 6 \"graph/bipartite_coloring.hpp\"\
    \nstruct bipartite_coloring {\npublic:\n    bipartite_coloring() : bipartite_coloring(0)\
    \ {\n    }\n    explicit bipartite_coloring(int n) : _n(n), g(n), _color(n, -1)\
    \ {\n    }\n    void add_edge(int u, int v) {\n        assert(0 <= u && u < _n);\n\
    \        assert(0 <= v && v < _n);\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \    }\n    void build() {\n        _color.assign(_n, -1);\n        _cycle.clear();\n\
    \        std::vector<int> par(_n, -1), it(_n, 0), st;\n        for (int s = 0;\
    \ s < _n; s++) {\n            if (_color[s] != -1) continue;\n            _color[s]\
    \ = 0;\n            st.assign(1, s);\n            while (!st.empty()) {\n    \
    \            int u = st.back();\n                if (it[u] == int(g[u].size()))\
    \ {\n                    st.pop_back();\n                    continue;\n     \
    \           }\n                int v = g[u][it[u]++];\n                if (_color[v]\
    \ == -1) {\n                    _color[v] = _color[u] ^ 1;\n                 \
    \   par[v] = u;\n                    st.push_back(v);\n                } else\
    \ if (_color[v] == _color[u] && _cycle.empty()) {\n                    for (int\
    \ x = u; x != v; x = par[x]) _cycle.push_back(x);\n                    _cycle.push_back(v);\n\
    \                    std::ranges::reverse(_cycle);\n                }\n      \
    \      }\n        }\n    }\n    bool is_bipartite() const {\n        return _cycle.empty();\n\
    \    }\n    int color(int v) const {\n        assert(0 <= v && v < _n);\n    \
    \    return _color[v];\n    }\n    const std::vector<int>& odd_cycle() const {\n\
    \        return _cycle;\n    }\n\nprivate:\n    int _n;\n    std::vector<std::vector<int>>\
    \ g;\n    std::vector<int> _color, _cycle;\n};\n#line 9 \"test/unit/bipartite_coloring.test.cpp\"\
    \nint main() {\n    std::mt19937 rng(20261029);\n    for (int trial = 0; trial\
    \ < 2000; trial++) {\n        int n = 1 + rng() % 10;\n        int m = rng() %\
    \ 14;\n        std::vector<std::pair<int, int>> edges;\n        std::set<std::pair<int,\
    \ int>> es;\n        bipartite_coloring g(n);\n        for (int i = 0; i < m;\
    \ i++) {\n            int u = rng() % n, v = rng() % n;\n            if (trial\
    \ % 4 == 0 && u == v) continue;\n            edges.emplace_back(u, v);\n     \
    \       es.emplace(u, v);\n            es.emplace(v, u);\n            g.add_edge(u,\
    \ v);\n        }\n        g.build();\n        bool expect = false;\n        for\
    \ (int mask = 0; mask < (1 << n) && !expect; mask++) {\n            bool ok =\
    \ true;\n            for (auto [u, v] : edges) ok &= ((mask >> u & 1) != (mask\
    \ >> v & 1));\n            expect |= ok;\n        }\n        assert(g.is_bipartite()\
    \ == expect);\n        assert(g.odd_cycle().empty() == expect);\n        for (int\
    \ v = 0; v < n; v++) assert(g.color(v) == 0 || g.color(v) == 1);\n        if (expect)\
    \ {\n            for (auto [u, v] : edges) assert(g.color(u) != g.color(v));\n\
    \        } else {\n            const std::vector<int>& c = g.odd_cycle();\n  \
    \          int k = int(c.size());\n            assert(k % 2 == 1);\n         \
    \   std::set<int> seen(c.begin(), c.end());\n            assert(int(seen.size())\
    \ == k);\n            for (int i = 0; i < k; i++) assert(es.count({c[i], c[(i\
    \ + 1) % k]}));\n        }\n    }\n    std::cout << \"Hello World\\n\";\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <random>\n#include <set>\n\
    #include <vector>\n\n#include \"graph/bipartite_coloring.hpp\"\nint main() {\n\
    \    std::mt19937 rng(20261029);\n    for (int trial = 0; trial < 2000; trial++)\
    \ {\n        int n = 1 + rng() % 10;\n        int m = rng() % 14;\n        std::vector<std::pair<int,\
    \ int>> edges;\n        std::set<std::pair<int, int>> es;\n        bipartite_coloring\
    \ g(n);\n        for (int i = 0; i < m; i++) {\n            int u = rng() % n,\
    \ v = rng() % n;\n            if (trial % 4 == 0 && u == v) continue;\n      \
    \      edges.emplace_back(u, v);\n            es.emplace(u, v);\n            es.emplace(v,\
    \ u);\n            g.add_edge(u, v);\n        }\n        g.build();\n        bool\
    \ expect = false;\n        for (int mask = 0; mask < (1 << n) && !expect; mask++)\
    \ {\n            bool ok = true;\n            for (auto [u, v] : edges) ok &=\
    \ ((mask >> u & 1) != (mask >> v & 1));\n            expect |= ok;\n        }\n\
    \        assert(g.is_bipartite() == expect);\n        assert(g.odd_cycle().empty()\
    \ == expect);\n        for (int v = 0; v < n; v++) assert(g.color(v) == 0 || g.color(v)\
    \ == 1);\n        if (expect) {\n            for (auto [u, v] : edges) assert(g.color(u)\
    \ != g.color(v));\n        } else {\n            const std::vector<int>& c = g.odd_cycle();\n\
    \            int k = int(c.size());\n            assert(k % 2 == 1);\n       \
    \     std::set<int> seen(c.begin(), c.end());\n            assert(int(seen.size())\
    \ == k);\n            for (int i = 0; i < k; i++) assert(es.count({c[i], c[(i\
    \ + 1) % k]}));\n        }\n    }\n    std::cout << \"Hello World\\n\";\n}\n"
  dependsOn:
  - graph/bipartite_coloring.hpp
  isVerificationFile: true
  path: test/unit/bipartite_coloring.test.cpp
  requiredBy: []
  timestamp: '2026-10-29 13:31:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/bipartite_coloring.test.cpp
layout: document
redirect_from:
- /verify/test/unit/bipartite_coloring.test.cpp
- /verify/test/unit/bipartite_coloring.test.cpp.html
title: test/unit/bipartite_coloring.test.cpp
---
