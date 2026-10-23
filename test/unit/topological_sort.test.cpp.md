---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/topological_sort.hpp
    title: graph/topological_sort.hpp
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
  bundledCode: "#line 1 \"test/unit/topological_sort.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iostream>\n#include <numeric>\n#include\
    \ <random>\n#include <vector>\n\n#line 2 \"graph/topological_sort.hpp\"\n#include\
    \ <queue>\nstd::vector<int> topological_sort(const std::vector<std::vector<int>>\
    \ &g) {\n    int n = g.size();\n    std::vector<int> deg(n);\n    for (int i =\
    \ 0; i < n; i++) {\n        for (int j : g[i]) {\n            deg[j]++;\n    \
    \    }\n    }\n    std::vector<int> ret;\n    std::queue<int> q;\n    for (int\
    \ i = 0; i < n; i++) {\n        if (deg[i] == 0) {\n            q.push(i);\n \
    \       }\n    }\n    while (!q.empty()) {\n        int u = q.front();\n     \
    \   q.pop();\n        ret.push_back(u);\n        for (int v : g[u]) {\n      \
    \      if (--deg[v] == 0) {\n                q.push(v);\n            }\n     \
    \   }\n    }\n    if (int(ret.size()) != n) {\n        return {};\n    }\n   \
    \ return ret;\n}\n#line 10 \"test/unit/topological_sort.test.cpp\"\nint main()\
    \ {\n    std::mt19937 rng(7959);\n    for (int trial = 0; trial < 300; trial++)\
    \ {\n        int n = rng() % 12;\n        std::vector<int> perm(n);\n        std::iota(perm.begin(),\
    \ perm.end(), 0);\n        std::shuffle(perm.begin(), perm.end(), rng);\n    \
    \    std::vector<std::vector<int>> g(n);\n        std::vector<std::pair<int, int>>\
    \ edges;\n        for (int i = 0; i < n; i++) {\n            for (int j = i +\
    \ 1; j < n; j++) {\n                if (rng() % 3 == 0) {\n                  \
    \  g[perm[i]].push_back(perm[j]);\n                    edges.emplace_back(perm[i],\
    \ perm[j]);\n                }\n            }\n        }\n        auto order =\
    \ topological_sort(g);\n        assert(int(order.size()) == n);\n        std::vector<int>\
    \ pos(n, -1);\n        for (int i = 0; i < n; i++) {\n            assert(0 <=\
    \ order[i] && order[i] < n);\n            assert(pos[order[i]] == -1);\n     \
    \       pos[order[i]] = i;\n        }\n        for (auto [u, v] : edges) assert(pos[u]\
    \ < pos[v]);\n        if (!edges.empty()) {\n            auto [u, v] = edges[rng()\
    \ % edges.size()];\n            g[v].push_back(u);\n            assert(topological_sort(g).empty());\n\
    \        }\n    }\n    {\n        std::vector<std::vector<int>> g(1);\n      \
    \  g[0].push_back(0);\n        assert(topological_sort(g).empty());\n    }\n \
    \   std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <numeric>\n\
    #include <random>\n#include <vector>\n\n#include \"graph/topological_sort.hpp\"\
    \nint main() {\n    std::mt19937 rng(7959);\n    for (int trial = 0; trial < 300;\
    \ trial++) {\n        int n = rng() % 12;\n        std::vector<int> perm(n);\n\
    \        std::iota(perm.begin(), perm.end(), 0);\n        std::shuffle(perm.begin(),\
    \ perm.end(), rng);\n        std::vector<std::vector<int>> g(n);\n        std::vector<std::pair<int,\
    \ int>> edges;\n        for (int i = 0; i < n; i++) {\n            for (int j\
    \ = i + 1; j < n; j++) {\n                if (rng() % 3 == 0) {\n            \
    \        g[perm[i]].push_back(perm[j]);\n                    edges.emplace_back(perm[i],\
    \ perm[j]);\n                }\n            }\n        }\n        auto order =\
    \ topological_sort(g);\n        assert(int(order.size()) == n);\n        std::vector<int>\
    \ pos(n, -1);\n        for (int i = 0; i < n; i++) {\n            assert(0 <=\
    \ order[i] && order[i] < n);\n            assert(pos[order[i]] == -1);\n     \
    \       pos[order[i]] = i;\n        }\n        for (auto [u, v] : edges) assert(pos[u]\
    \ < pos[v]);\n        if (!edges.empty()) {\n            auto [u, v] = edges[rng()\
    \ % edges.size()];\n            g[v].push_back(u);\n            assert(topological_sort(g).empty());\n\
    \        }\n    }\n    {\n        std::vector<std::vector<int>> g(1);\n      \
    \  g[0].push_back(0);\n        assert(topological_sort(g).empty());\n    }\n \
    \   std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - graph/topological_sort.hpp
  isVerificationFile: true
  path: test/unit/topological_sort.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:43:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/topological_sort.test.cpp
layout: document
redirect_from:
- /verify/test/unit/topological_sort.test.cpp
- /verify/test/unit/topological_sort.test.cpp.html
title: test/unit/topological_sort.test.cpp
---
