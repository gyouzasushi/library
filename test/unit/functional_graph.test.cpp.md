---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/functional_graph.hpp
    title: Functional Graph
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
  bundledCode: "#line 1 \"test/unit/functional_graph.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n#include\
    \ <set>\n#include <vector>\n\n#line 2 \"graph/functional_graph.hpp\"\n#include\
    \ <bit>\n#line 5 \"graph/functional_graph.hpp\"\nstruct functional_graph {\npublic:\n\
    \    functional_graph() : functional_graph(std::vector<int>()) {\n    }\n    explicit\
    \ functional_graph(std::vector<int> f)\n        : _n(int(f.size())),\n       \
    \   _f(std::move(f)),\n          _root(_n, -1),\n          _depth(_n, 0),\n  \
    \        _component(_n, -1),\n          _pos(_n, -1),\n          _children(_n)\
    \ {\n        for (int v = 0; v < _n; v++) assert(0 <= _f[v] && _f[v] < _n);\n\
    \        std::vector<int> state(_n, 0);\n        for (int s = 0; s < _n; s++)\
    \ {\n            if (state[s]) continue;\n            int v = s;\n           \
    \ while (state[v] == 0) {\n                state[v] = 1;\n                v =\
    \ _f[v];\n            }\n            if (state[v] == 1) {\n                int\
    \ k = int(_cycles.size());\n                std::vector<int> cyc;\n          \
    \      int u = v;\n                do {\n                    cyc.push_back(u);\n\
    \                    _root[u] = u;\n                    _component[u] = k;\n \
    \                   _pos[u] = int(cyc.size()) - 1;\n                    u = _f[u];\n\
    \                } while (u != v);\n                _cycles.push_back(std::move(cyc));\n\
    \            }\n            for (int u = s; state[u] == 1; u = _f[u]) state[u]\
    \ = 2;\n        }\n        for (int v = 0; v < _n; v++) {\n            if (_root[v]\
    \ != v) _children[_f[v]].push_back(v);\n        }\n        std::vector<int> order;\n\
    \        order.reserve(_n);\n        for (const std::vector<int>& cyc : _cycles)\
    \ {\n            for (int v : cyc) order.push_back(v);\n        }\n        int\
    \ max_depth = 0;\n        for (int i = 0; i < _n; i++) {\n            int v =\
    \ order[i];\n            for (int c : _children[v]) {\n                _root[c]\
    \ = _root[v];\n                _depth[c] = _depth[v] + 1;\n                _component[c]\
    \ = _component[v];\n                order.push_back(c);\n                if (max_depth\
    \ < _depth[c]) max_depth = _depth[c];\n            }\n        }\n        int log\
    \ = std::bit_width((unsigned)max_depth);\n        _up.assign(log, std::vector<int>(_n));\n\
    \        for (int j = 0; j < log; j++) {\n            for (int v = 0; v < _n;\
    \ v++) {\n                _up[j][v] = j == 0 ? _f[v] : _up[j - 1][_up[j - 1][v]];\n\
    \            }\n        }\n    }\n    int jump(int v, long long k) const {\n \
    \       assert(0 <= v && v < _n);\n        assert(0 <= k);\n        if (k < _depth[v])\
    \ {\n            for (int j = 0; k; j++, k >>= 1) {\n                if (k & 1)\
    \ v = _up[j][v];\n            }\n            return v;\n        }\n        k -=\
    \ _depth[v];\n        const std::vector<int>& cyc = _cycles[_component[v]];\n\
    \        int len = int(cyc.size());\n        return cyc[(_pos[_root[v]] + k %\
    \ len) % len];\n    }\n    bool on_cycle(int v) const {\n        assert(0 <= v\
    \ && v < _n);\n        return _root[v] == v;\n    }\n    int root(int v) const\
    \ {\n        assert(0 <= v && v < _n);\n        return _root[v];\n    }\n    int\
    \ depth(int v) const {\n        assert(0 <= v && v < _n);\n        return _depth[v];\n\
    \    }\n    int component(int v) const {\n        assert(0 <= v && v < _n);\n\
    \        return _component[v];\n    }\n    const std::vector<int>& cycle(int v)\
    \ const {\n        assert(0 <= v && v < _n);\n        return _cycles[_component[v]];\n\
    \    }\n    const std::vector<std::vector<int>>& cycles() const {\n        return\
    \ _cycles;\n    }\n    const std::vector<int>& children(int v) const {\n     \
    \   assert(0 <= v && v < _n);\n        return _children[v];\n    }\n\nprivate:\n\
    \    int _n;\n    std::vector<int> _f, _root, _depth, _component, _pos;\n    std::vector<std::vector<int>>\
    \ _children, _cycles, _up;\n};\n#line 10 \"test/unit/functional_graph.test.cpp\"\
    \nint main() {\n    std::mt19937 rng(12345);\n    for (int it = 0; it < 3000;\
    \ it++) {\n        int n = 1 + rng() % 12;\n        std::vector<int> f(n);\n \
    \       for (int& x : f) x = rng() % n;\n        if (rng() % 3 == 0) {\n     \
    \       // permutation\n            for (int i = 0; i < n; i++) f[i] = i;\n  \
    \          std::shuffle(f.begin(), f.end(), rng);\n        }\n        functional_graph\
    \ g(f);\n\n        // naive: walk from v, find depth (first repeated vertex) and\
    \ cycle\n        std::vector<int> naive_root(n), naive_depth(n);\n        std::vector<std::vector<int>>\
    \ naive_cycle(n);\n        for (int v = 0; v < n; v++) {\n            std::vector<int>\
    \ seen(n, -1), path;\n            int u = v, step = 0;\n            while (seen[u]\
    \ == -1) {\n                seen[u] = step++;\n                path.push_back(u);\n\
    \                u = f[u];\n            }\n            naive_depth[v] = seen[u];\n\
    \            naive_root[v] = u;\n            naive_cycle[v] = std::vector<int>(path.begin()\
    \ + seen[u], path.end());\n        }\n        int total_cycle_vertices = 0;\n\
    \        for (int v = 0; v < n; v++) {\n            assert(g.root(v) == naive_root[v]);\n\
    \            assert(g.depth(v) == naive_depth[v]);\n            assert(g.on_cycle(v)\
    \ == (naive_depth[v] == 0));\n            total_cycle_vertices += g.on_cycle(v);\n\
    \            // cycle(v) is a rotation of naive_cycle[v]\n            const std::vector<int>&\
    \ c = g.cycle(v);\n            assert(c.size() == naive_cycle[v].size());\n  \
    \          int k = int(c.size());\n            int off = int(std::find(c.begin(),\
    \ c.end(), naive_cycle[v][0]) - c.begin());\n            assert(off < k);\n  \
    \          for (int i = 0; i < k; i++) assert(c[(off + i) % k] == naive_cycle[v][i]);\n\
    \            for (int i = 0; i < k; i++) assert(f[c[i]] == c[(i + 1) % k]);\n\
    \            // component ids agree with root's cycle\n            assert(g.component(v)\
    \ == g.component(g.root(v)));\n            assert(&g.cycles()[g.component(v)]\
    \ == &g.cycle(v));\n            // jump\n            for (long long step : {0LL,\
    \ 1LL, 2LL, 3LL, 5LL, 7LL, 12LL, 13LL, 1000000000000000000LL}) {\n           \
    \     int u = v;\n                long long s = step;\n                if (s >\
    \ 50) {\n                    // reduce using cycle length after reaching cycle\n\
    \                    int d = naive_depth[v];\n                    for (int i =\
    \ 0; i < d; i++) u = f[u];\n                    long long rem = (s - d) % (long\
    \ long)naive_cycle[v].size();\n                    for (int i = 0; i < rem; i++)\
    \ u = f[u];\n                } else {\n                    for (int i = 0; i <\
    \ s; i++) u = f[u];\n                }\n                assert(g.jump(v, step)\
    \ == u);\n            }\n        }\n        int cyc_sum = 0;\n        for (const\
    \ std::vector<int>& c : g.cycles()) cyc_sum += int(c.size());\n        assert(cyc_sum\
    \ == total_cycle_vertices);\n        // children: reverse edges excluding cycle\
    \ edges\n        std::vector<std::set<int>> ch(n);\n        for (int v = 0; v\
    \ < n; v++) {\n            if (!g.on_cycle(v)) ch[f[v]].insert(v);\n        }\n\
    \        for (int v = 0; v < n; v++) {\n            std::set<int> got(g.children(v).begin(),\
    \ g.children(v).end());\n            assert(got == ch[v]);\n            assert(got.size()\
    \ == g.children(v).size());\n        }\n    }\n    std::cout << \"Hello World\"\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <set>\n#include <vector>\n\n#include \"graph/functional_graph.hpp\"\n\
    int main() {\n    std::mt19937 rng(12345);\n    for (int it = 0; it < 3000; it++)\
    \ {\n        int n = 1 + rng() % 12;\n        std::vector<int> f(n);\n       \
    \ for (int& x : f) x = rng() % n;\n        if (rng() % 3 == 0) {\n           \
    \ // permutation\n            for (int i = 0; i < n; i++) f[i] = i;\n        \
    \    std::shuffle(f.begin(), f.end(), rng);\n        }\n        functional_graph\
    \ g(f);\n\n        // naive: walk from v, find depth (first repeated vertex) and\
    \ cycle\n        std::vector<int> naive_root(n), naive_depth(n);\n        std::vector<std::vector<int>>\
    \ naive_cycle(n);\n        for (int v = 0; v < n; v++) {\n            std::vector<int>\
    \ seen(n, -1), path;\n            int u = v, step = 0;\n            while (seen[u]\
    \ == -1) {\n                seen[u] = step++;\n                path.push_back(u);\n\
    \                u = f[u];\n            }\n            naive_depth[v] = seen[u];\n\
    \            naive_root[v] = u;\n            naive_cycle[v] = std::vector<int>(path.begin()\
    \ + seen[u], path.end());\n        }\n        int total_cycle_vertices = 0;\n\
    \        for (int v = 0; v < n; v++) {\n            assert(g.root(v) == naive_root[v]);\n\
    \            assert(g.depth(v) == naive_depth[v]);\n            assert(g.on_cycle(v)\
    \ == (naive_depth[v] == 0));\n            total_cycle_vertices += g.on_cycle(v);\n\
    \            // cycle(v) is a rotation of naive_cycle[v]\n            const std::vector<int>&\
    \ c = g.cycle(v);\n            assert(c.size() == naive_cycle[v].size());\n  \
    \          int k = int(c.size());\n            int off = int(std::find(c.begin(),\
    \ c.end(), naive_cycle[v][0]) - c.begin());\n            assert(off < k);\n  \
    \          for (int i = 0; i < k; i++) assert(c[(off + i) % k] == naive_cycle[v][i]);\n\
    \            for (int i = 0; i < k; i++) assert(f[c[i]] == c[(i + 1) % k]);\n\
    \            // component ids agree with root's cycle\n            assert(g.component(v)\
    \ == g.component(g.root(v)));\n            assert(&g.cycles()[g.component(v)]\
    \ == &g.cycle(v));\n            // jump\n            for (long long step : {0LL,\
    \ 1LL, 2LL, 3LL, 5LL, 7LL, 12LL, 13LL, 1000000000000000000LL}) {\n           \
    \     int u = v;\n                long long s = step;\n                if (s >\
    \ 50) {\n                    // reduce using cycle length after reaching cycle\n\
    \                    int d = naive_depth[v];\n                    for (int i =\
    \ 0; i < d; i++) u = f[u];\n                    long long rem = (s - d) % (long\
    \ long)naive_cycle[v].size();\n                    for (int i = 0; i < rem; i++)\
    \ u = f[u];\n                } else {\n                    for (int i = 0; i <\
    \ s; i++) u = f[u];\n                }\n                assert(g.jump(v, step)\
    \ == u);\n            }\n        }\n        int cyc_sum = 0;\n        for (const\
    \ std::vector<int>& c : g.cycles()) cyc_sum += int(c.size());\n        assert(cyc_sum\
    \ == total_cycle_vertices);\n        // children: reverse edges excluding cycle\
    \ edges\n        std::vector<std::set<int>> ch(n);\n        for (int v = 0; v\
    \ < n; v++) {\n            if (!g.on_cycle(v)) ch[f[v]].insert(v);\n        }\n\
    \        for (int v = 0; v < n; v++) {\n            std::set<int> got(g.children(v).begin(),\
    \ g.children(v).end());\n            assert(got == ch[v]);\n            assert(got.size()\
    \ == g.children(v).size());\n        }\n    }\n    std::cout << \"Hello World\"\
    \ << std::endl;\n}\n"
  dependsOn:
  - graph/functional_graph.hpp
  isVerificationFile: true
  path: test/unit/functional_graph.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 22:21:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/functional_graph.test.cpp
layout: document
redirect_from:
- /verify/test/unit/functional_graph.test.cpp
- /verify/test/unit/functional_graph.test.cpp.html
title: test/unit/functional_graph.test.cpp
---
