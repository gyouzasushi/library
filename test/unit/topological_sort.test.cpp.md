---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/topological_sort.hpp
    title: Topological Sort
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
    \ <algorithm>\n#include <cassert>\n#include <functional>\n#include <iostream>\n\
    #include <numeric>\n#include <random>\n#include <vector>\n\n#line 3 \"graph/topological_sort.hpp\"\
    \n#include <optional>\n#include <queue>\n#line 6 \"graph/topological_sort.hpp\"\
    \ntemplate <class Compare>\nstd::optional<std::vector<int>> topological_sort(const\
    \ std::vector<std::vector<int>>& g, Compare comp) {\n    int n = int(g.size());\n\
    \    std::vector<int> deg(n);\n    for (int u = 0; u < n; u++) {\n        for\
    \ (int v : g[u]) deg[v]++;\n    }\n    auto rev = [&](int a, int b) { return comp(b,\
    \ a); };\n    std::priority_queue<int, std::vector<int>, decltype(rev)> q(rev);\n\
    \    for (int v = 0; v < n; v++) {\n        if (deg[v] == 0) q.push(v);\n    }\n\
    \    std::vector<int> order;\n    order.reserve(n);\n    while (!q.empty()) {\n\
    \        int u = q.top();\n        q.pop();\n        order.push_back(u);\n   \
    \     for (int v : g[u]) {\n            if (--deg[v] == 0) q.push(v);\n      \
    \  }\n    }\n    if (int(order.size()) != n) return std::nullopt;\n    return\
    \ order;\n}\nstd::optional<std::vector<int>> topological_sort(const std::vector<std::vector<int>>&\
    \ g) {\n    int n = int(g.size());\n    std::vector<int> deg(n);\n    for (int\
    \ u = 0; u < n; u++) {\n        for (int v : g[u]) deg[v]++;\n    }\n    std::queue<int>\
    \ q;\n    for (int v = 0; v < n; v++) {\n        if (deg[v] == 0) q.push(v);\n\
    \    }\n    std::vector<int> order;\n    order.reserve(n);\n    while (!q.empty())\
    \ {\n        int u = q.front();\n        q.pop();\n        order.push_back(u);\n\
    \        for (int v : g[u]) {\n            if (--deg[v] == 0) q.push(v);\n   \
    \     }\n    }\n    if (int(order.size()) != n) return std::nullopt;\n    return\
    \ order;\n}\n#line 11 \"test/unit/topological_sort.test.cpp\"\nbool valid(const\
    \ std::vector<std::vector<int>>& g, const std::vector<int>& order) {\n    int\
    \ n = int(g.size());\n    if (int(order.size()) != n) return false;\n    std::vector<int>\
    \ pos(n, -1);\n    for (int i = 0; i < n; i++) {\n        if (order[i] < 0 ||\
    \ order[i] >= n || pos[order[i]] != -1) return false;\n        pos[order[i]] =\
    \ i;\n    }\n    for (int u = 0; u < n; u++) {\n        for (int v : g[u]) {\n\
    \            if (pos[u] >= pos[v]) return false;\n        }\n    }\n    return\
    \ true;\n}\nint main() {\n    std::mt19937 rng(7959);\n    for (int trial = 0;\
    \ trial < 300; trial++) {\n        int n = rng() % 9;\n        std::vector<int>\
    \ perm(n);\n        std::iota(perm.begin(), perm.end(), 0);\n        std::shuffle(perm.begin(),\
    \ perm.end(), rng);\n        std::vector<std::vector<int>> g(n);\n        std::vector<std::pair<int,\
    \ int>> edges;\n        for (int i = 0; i < n; i++) {\n            for (int j\
    \ = i + 1; j < n; j++) {\n                if (rng() % 3 == 0) {\n            \
    \        g[perm[i]].push_back(perm[j]);\n                    edges.emplace_back(perm[i],\
    \ perm[j]);\n                }\n            }\n        }\n        auto order =\
    \ topological_sort(g);\n        assert(order && valid(g, *order));\n        auto\
    \ lex = topological_sort(g, std::less<int>());\n        assert(lex && valid(g,\
    \ *lex));\n        std::vector<int> best;\n        std::vector<int> p(n);\n  \
    \      std::iota(p.begin(), p.end(), 0);\n        do {\n            if (valid(g,\
    \ p) && (best.empty() || p < best)) best = p;\n        } while (std::next_permutation(p.begin(),\
    \ p.end()));\n        assert(*lex == best);\n        auto lex_rev = topological_sort(g,\
    \ std::greater<int>());\n        assert(lex_rev && valid(g, *lex_rev));\n    \
    \    if (!edges.empty()) {\n            auto [u, v] = edges[rng() % edges.size()];\n\
    \            g[v].push_back(u);\n            assert(!topological_sort(g));\n \
    \           assert(!topological_sort(g, std::less<int>()));\n        }\n    }\n\
    \    {\n        std::vector<std::vector<int>> g(1);\n        g[0].push_back(0);\n\
    \        assert(!topological_sort(g));\n        assert(topological_sort(std::vector<std::vector<int>>{}).has_value());\n\
    \    }\n    std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include <iostream>\n\
    #include <numeric>\n#include <random>\n#include <vector>\n\n#include \"graph/topological_sort.hpp\"\
    \nbool valid(const std::vector<std::vector<int>>& g, const std::vector<int>& order)\
    \ {\n    int n = int(g.size());\n    if (int(order.size()) != n) return false;\n\
    \    std::vector<int> pos(n, -1);\n    for (int i = 0; i < n; i++) {\n       \
    \ if (order[i] < 0 || order[i] >= n || pos[order[i]] != -1) return false;\n  \
    \      pos[order[i]] = i;\n    }\n    for (int u = 0; u < n; u++) {\n        for\
    \ (int v : g[u]) {\n            if (pos[u] >= pos[v]) return false;\n        }\n\
    \    }\n    return true;\n}\nint main() {\n    std::mt19937 rng(7959);\n    for\
    \ (int trial = 0; trial < 300; trial++) {\n        int n = rng() % 9;\n      \
    \  std::vector<int> perm(n);\n        std::iota(perm.begin(), perm.end(), 0);\n\
    \        std::shuffle(perm.begin(), perm.end(), rng);\n        std::vector<std::vector<int>>\
    \ g(n);\n        std::vector<std::pair<int, int>> edges;\n        for (int i =\
    \ 0; i < n; i++) {\n            for (int j = i + 1; j < n; j++) {\n          \
    \      if (rng() % 3 == 0) {\n                    g[perm[i]].push_back(perm[j]);\n\
    \                    edges.emplace_back(perm[i], perm[j]);\n                }\n\
    \            }\n        }\n        auto order = topological_sort(g);\n       \
    \ assert(order && valid(g, *order));\n        auto lex = topological_sort(g, std::less<int>());\n\
    \        assert(lex && valid(g, *lex));\n        std::vector<int> best;\n    \
    \    std::vector<int> p(n);\n        std::iota(p.begin(), p.end(), 0);\n     \
    \   do {\n            if (valid(g, p) && (best.empty() || p < best)) best = p;\n\
    \        } while (std::next_permutation(p.begin(), p.end()));\n        assert(*lex\
    \ == best);\n        auto lex_rev = topological_sort(g, std::greater<int>());\n\
    \        assert(lex_rev && valid(g, *lex_rev));\n        if (!edges.empty()) {\n\
    \            auto [u, v] = edges[rng() % edges.size()];\n            g[v].push_back(u);\n\
    \            assert(!topological_sort(g));\n            assert(!topological_sort(g,\
    \ std::less<int>()));\n        }\n    }\n    {\n        std::vector<std::vector<int>>\
    \ g(1);\n        g[0].push_back(0);\n        assert(!topological_sort(g));\n \
    \       assert(topological_sort(std::vector<std::vector<int>>{}).has_value());\n\
    \    }\n    std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - graph/topological_sort.hpp
  isVerificationFile: true
  path: test/unit/topological_sort.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:58:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/topological_sort.test.cpp
layout: document
redirect_from:
- /verify/test/unit/topological_sort.test.cpp
- /verify/test/unit/topological_sort.test.cpp.html
title: test/unit/topological_sort.test.cpp
---
