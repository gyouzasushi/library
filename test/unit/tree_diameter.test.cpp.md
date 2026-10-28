---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/tree_diameter.hpp
    title: Tree Diameter
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
  bundledCode: "#line 1 \"test/unit/tree_diameter.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\n#line 4 \"graph/tree_diameter.hpp\"\n#include <utility>\n\
    #line 6 \"graph/tree_diameter.hpp\"\ntemplate <class T>\nstruct tree_diameter\
    \ {\npublic:\n    tree_diameter() : tree_diameter(0) {\n    }\n    explicit tree_diameter(int\
    \ n) : _n(n), g(n) {\n    }\n    void add_edge(int u, int v, T w = 1) {\n    \
    \    assert(0 <= u && u < _n);\n        assert(0 <= v && v < _n);\n        g[u].emplace_back(v,\
    \ w);\n        g[v].emplace_back(u, w);\n    }\n    void build() {\n        assert(_n\
    \ >= 1);\n        std::vector<int> par;\n        std::vector<T> d0;\n        search(0,\
    \ d0, par);\n        _u = int(std::max_element(d0.begin(), d0.end()) - d0.begin());\n\
    \        search(_u, du, par);\n        _v = int(std::max_element(du.begin(), du.end())\
    \ - du.begin());\n        _path.clear();\n        for (int x = _v; x != -1; x\
    \ = par[x]) _path.push_back(x);\n        std::reverse(_path.begin(), _path.end());\n\
    \        search(_v, dv, par);\n    }\n    T length() const {\n        return du[_v];\n\
    \    }\n    std::pair<int, int> ends() const {\n        return {_u, _v};\n   \
    \ }\n    const std::vector<int>& path() const {\n        return _path;\n    }\n\
    \    T farthest_dist(int x) const {\n        assert(0 <= x && x < _n);\n     \
    \   return std::max(du[x], dv[x]);\n    }\n    int farthest(int x) const {\n \
    \       assert(0 <= x && x < _n);\n        if (du[x] != dv[x]) return du[x] >\
    \ dv[x] ? _u : _v;\n        return std::min(_u, _v);\n    }\n\nprivate:\n    int\
    \ _n, _u = -1, _v = -1;\n    std::vector<std::vector<std::pair<int, T>>> g;\n\
    \    std::vector<T> du, dv;\n    std::vector<int> _path;\n    void search(int\
    \ s, std::vector<T>& d, std::vector<int>& par) const {\n        d.assign(_n, T(0));\n\
    \        par.assign(_n, -1);\n        std::vector<int> st = {s};\n        par[s]\
    \ = s;\n        while (!st.empty()) {\n            int x = st.back();\n      \
    \      st.pop_back();\n            for (auto [y, w] : g[x]) {\n              \
    \  if (par[y] != -1) continue;\n                par[y] = x;\n                d[y]\
    \ = d[x] + w;\n                st.push_back(y);\n            }\n        }\n  \
    \      par[s] = -1;\n    }\n};\n#line 9 \"test/unit/tree_diameter.test.cpp\"\n\
    int main() {\n    std::mt19937 rng(20261028);\n    for (int trial = 0; trial <\
    \ 300; trial++) {\n        int n = 1 + rng() % 12;\n        bool weighted = trial\
    \ % 2;\n        std::vector<std::vector<std::pair<int, long long>>> g(n);\n  \
    \      tree_diameter<long long> d(n);\n        for (int v = 1; v < n; v++) {\n\
    \            int p = rng() % v;\n            long long w = weighted ? rng() %\
    \ 5 : 1;\n            g[v].emplace_back(p, w);\n            g[p].emplace_back(v,\
    \ w);\n            d.add_edge(p, v, w);\n        }\n        d.build();\n     \
    \   std::vector<std::vector<long long>> dist(n, std::vector<long long>(n, -1));\n\
    \        for (int s = 0; s < n; s++) {\n            std::vector<int> st = {s};\n\
    \            dist[s][s] = 0;\n            while (!st.empty()) {\n            \
    \    int x = st.back();\n                st.pop_back();\n                for (auto\
    \ [y, w] : g[x]) {\n                    if (dist[s][y] != -1) continue;\n    \
    \                dist[s][y] = dist[s][x] + w;\n                    st.push_back(y);\n\
    \                }\n            }\n        }\n        long long diam = 0;\n  \
    \      for (int s = 0; s < n; s++) diam = std::max(diam, *std::max_element(dist[s].begin(),\
    \ dist[s].end()));\n        assert(d.length() == diam);\n        auto [u, v] =\
    \ d.ends();\n        assert(dist[u][v] == diam);\n        const std::vector<int>&\
    \ path = d.path();\n        assert(path.front() == u && path.back() == v);\n \
    \       long long len = 0;\n        for (int i = 0; i + 1 < int(path.size());\
    \ i++) {\n            bool found = false;\n            for (auto [y, w] : g[path[i]])\
    \ {\n                if (y == path[i + 1]) found = true, len += w;\n         \
    \   }\n            assert(found);\n        }\n        assert(len == diam);\n \
    \       for (int x = 0; x < n; x++) {\n            long long far = *std::max_element(dist[x].begin(),\
    \ dist[x].end());\n            assert(d.farthest_dist(x) == far);\n          \
    \  int f = d.farthest(x);\n            assert(dist[x][f] == far);\n          \
    \  assert(f == int(std::max_element(dist[x].begin(), dist[x].end()) - dist[x].begin()));\n\
    \        }\n    }\n    std::cout << \"Hello World\" << std::endl;\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\n#include \"graph/tree_diameter.hpp\"\nint main() {\n    std::mt19937\
    \ rng(20261028);\n    for (int trial = 0; trial < 300; trial++) {\n        int\
    \ n = 1 + rng() % 12;\n        bool weighted = trial % 2;\n        std::vector<std::vector<std::pair<int,\
    \ long long>>> g(n);\n        tree_diameter<long long> d(n);\n        for (int\
    \ v = 1; v < n; v++) {\n            int p = rng() % v;\n            long long\
    \ w = weighted ? rng() % 5 : 1;\n            g[v].emplace_back(p, w);\n      \
    \      g[p].emplace_back(v, w);\n            d.add_edge(p, v, w);\n        }\n\
    \        d.build();\n        std::vector<std::vector<long long>> dist(n, std::vector<long\
    \ long>(n, -1));\n        for (int s = 0; s < n; s++) {\n            std::vector<int>\
    \ st = {s};\n            dist[s][s] = 0;\n            while (!st.empty()) {\n\
    \                int x = st.back();\n                st.pop_back();\n        \
    \        for (auto [y, w] : g[x]) {\n                    if (dist[s][y] != -1)\
    \ continue;\n                    dist[s][y] = dist[s][x] + w;\n              \
    \      st.push_back(y);\n                }\n            }\n        }\n       \
    \ long long diam = 0;\n        for (int s = 0; s < n; s++) diam = std::max(diam,\
    \ *std::max_element(dist[s].begin(), dist[s].end()));\n        assert(d.length()\
    \ == diam);\n        auto [u, v] = d.ends();\n        assert(dist[u][v] == diam);\n\
    \        const std::vector<int>& path = d.path();\n        assert(path.front()\
    \ == u && path.back() == v);\n        long long len = 0;\n        for (int i =\
    \ 0; i + 1 < int(path.size()); i++) {\n            bool found = false;\n     \
    \       for (auto [y, w] : g[path[i]]) {\n                if (y == path[i + 1])\
    \ found = true, len += w;\n            }\n            assert(found);\n       \
    \ }\n        assert(len == diam);\n        for (int x = 0; x < n; x++) {\n   \
    \         long long far = *std::max_element(dist[x].begin(), dist[x].end());\n\
    \            assert(d.farthest_dist(x) == far);\n            int f = d.farthest(x);\n\
    \            assert(dist[x][f] == far);\n            assert(f == int(std::max_element(dist[x].begin(),\
    \ dist[x].end()) - dist[x].begin()));\n        }\n    }\n    std::cout << \"Hello\
    \ World\" << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - graph/tree_diameter.hpp
  isVerificationFile: true
  path: test/unit/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2026-10-28 19:31:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/test/unit/tree_diameter.test.cpp
- /verify/test/unit/tree_diameter.test.cpp.html
title: test/unit/tree_diameter.test.cpp
---
