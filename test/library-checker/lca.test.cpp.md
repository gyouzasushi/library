---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/plus_minus_one_range_minimum.hpp
    title: datastructure/plus_minus_one_range_minimum.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/static_range_minimum.hpp
    title: datastructure/static_range_minimum.hpp
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.hpp
    title: graph/lowest_common_ancestor.hpp
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
  bundledCode: "#line 1 \"test/library-checker/lca.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/lca\"\n#include <iostream>\n\n#line 2 \"graph/lowest_common_ancestor.hpp\"\
    \n#include <cassert>\n#include <vector>\n\n#line 2 \"datastructure/plus_minus_one_range_minimum.hpp\"\
    \n#include <cmath>\n#line 4 \"datastructure/plus_minus_one_range_minimum.hpp\"\
    \n\n#line 3 \"datastructure/static_range_minimum.hpp\"\nstruct StaticRMQ {\npublic:\n\
    \    void init(const std::vector<std::pair<int, int>>& _v) {\n        _n = int(_v.size()),\
    \ d.resize(_n), ceil_log2.resize(_n + 1);\n        ceil_log2[0] = 0;\n       \
    \ ceil_log2[1] = 0;\n        for (int i = 2; i <= _n; i++) ceil_log2[i] = ceil_log2[i\
    \ >> 1] + 1;\n        for (int i = 0; i < _n; i++) {\n            d[i].resize(ceil_log2[_n]\
    \ + 1);\n            d[i][0] = _v[i];\n        }\n        for (int b = 0; b <\
    \ ceil_log2[_n]; b++) {\n            for (int i = 0; i < _n; i++) {\n        \
    \        if (i + (1 << (b + 1)) > _n) break;\n                d[i][b + 1] = std::min(d[i][b],\
    \ d[i + (1 << b)][b]);\n            }\n        }\n    }\n    std::pair<int, int>\
    \ prod(int l, int r) {\n        if (!(l < r)) return PINF;\n        int b = ceil_log2[r\
    \ - l];\n        return std::min(d[l][b], d[r - (1 << b)][b]);\n    }\n\nprivate:\n\
    \    int _n;\n    std::vector<std::vector<std::pair<int, int>>> d;\n    std::vector<int>\
    \ ceil_log2;\n    const std::pair<int, int> PINF = {1 << 30, 1 << 30};\n};\n#line\
    \ 6 \"datastructure/plus_minus_one_range_minimum.hpp\"\nstruct PlusMinusOneRMQ\
    \ {\npublic:\n    void init(const std::vector<int>& _v) {\n        _n = int(_v.size());\n\
    \        v = _v;\n        s = std::max(1, int(std::log2(_n) / 2));\n        B\
    \ = (_n + s - 1) / s;\n        std::vector<std::pair<int, int>> _spt(B);\n   \
    \     pattern.resize(B);\n        for (int i = 0; i < _n; i += s) {\n        \
    \    int min_j = i;\n            int bit = 0;\n            for (int j = i; j <\
    \ std::min(_n, i + s); j++) {\n                if (v[j] < v[min_j]) min_j = j;\n\
    \                if (j + 1 < std::min(_n, i + s) && v[j] < v[j + 1])\n       \
    \             bit |= 1 << (j - i);\n            }\n            _spt[i / s] = {v[min_j],\
    \ min_j};\n            pattern[i / s] = bit;\n        }\n        sparse_table.init(_spt);\n\
    \n        lookup_table.resize(1 << (s - 1));\n        for (int bit = 0; bit <\
    \ (1 << (s - 1)); bit++) {\n            lookup_table[bit].resize(s + 1);\n   \
    \         for (int l = 0; l <= s; l++) {\n                lookup_table[bit][l].resize(s\
    \ + 1, INF);\n                int min_ = 0;\n                int min_i = l;\n\
    \                int sum = 0;\n                for (int r = l + 1; r <= s; r++)\
    \ {\n                    lookup_table[bit][l][r] = min_i;\n                  \
    \  sum += bit >> (r - 1) & 1 ? 1 : -1;\n                    if (sum < min_) {\n\
    \                        min_ = sum;\n                        min_i = r;\n   \
    \                 }\n                }\n            }\n        }\n    }\n    int\
    \ prod(int l, int r) {\n        int m1 = (l + s - 1) / s;\n        int m2 = r\
    \ / s;\n        int l1 = s * m1;\n        int r1 = s * m2;\n        if (m2 < m1)\
    \ {\n            return lookup_table[pattern[m2]][l - r1][r - r1] + r1;\n    \
    \    }\n        int ret = INF;\n        if (m1 > 0) {\n            ret = argmin(\n\
    \                ret, lookup_table[pattern[m1 - 1]][s - (l1 - l)][s] + l1 - s);\n\
    \        }\n        ret = argmin(ret, sparse_table.prod(m1, m2).second);\n   \
    \     if (m2 < B) {\n            ret = argmin(ret, lookup_table[pattern[m2]][0][r\
    \ - r1] + r1);\n        }\n        return ret;\n    }\n\nprivate:\n    int _n;\n\
    \    int s, B;\n    StaticRMQ sparse_table;\n    std::vector<std::vector<std::vector<int>>>\
    \ lookup_table;\n    std::vector<int> pattern, v;\n    const int INF = 1 << 30;\n\
    \    int argmin(int i, int j) {\n        if (i >= INF || j >= INF || v[i] == v[j])\
    \ return std::min(i, j);\n        return v[i] < v[j] ? i : j;\n    }\n};\n#line\
    \ 6 \"graph/lowest_common_ancestor.hpp\"\nstruct LowestCommonAncestor {\npublic:\n\
    \    LowestCommonAncestor() {\n    }\n    LowestCommonAncestor(int n, int root\
    \ = 0)\n        : _n(n), _root(root), g(n), id(n), vs(2 * n - 1), dep(2 * n -\
    \ 1) {\n    }\n    void add_edge(int from, int to) {\n        assert(0 <= from\
    \ && from < _n);\n        assert(0 <= to && to < _n);\n        g[from].push_back(to);\n\
    \        g[to].push_back(from);\n    }\n    void build() {\n        int k = 0;\n\
    \        auto dfs = [&](auto dfs, int pos, int pre, int d) -> void {\n       \
    \     id[pos] = k;\n            vs[k] = pos;\n            dep[k++] = d;\n    \
    \        for (int nxt : g[pos]) {\n                if (nxt == pre) continue;\n\
    \                dfs(dfs, nxt, pos, d + 1);\n                vs[k] = pos;\n  \
    \              dep[k++] = d;\n            }\n        };\n        dfs(dfs, _root,\
    \ -1, 0);\n        rmq.init(dep);\n    }\n\n    int get(int u, int v) {\n    \
    \    int l = std::min(id[u], id[v]);\n        int r = std::max(id[u], id[v]) +\
    \ 1;\n        return vs[rmq.prod(l, r)];\n    }\n    int get(int u, int v, int\
    \ r) {\n        return get(r, u) ^ get(u, v) ^ get(v, r);\n    }\n    int depth(int\
    \ u) {\n        return dep[id[u]];\n    }\n    int dist(int u, int v) {\n    \
    \    return depth(u) + depth(v) - 2 * depth(get(u, v));\n    }\n\nprivate:\n \
    \   int _n, _root;\n    std::vector<std::vector<int>> g;\n    std::vector<int>\
    \ id, vs, dep;\n    PlusMinusOneRMQ rmq;\n};\n#line 5 \"test/library-checker/lca.test.cpp\"\
    \nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    LowestCommonAncestor\
    \ lca(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n        std::cin\
    \ >> p;\n        lca.add_edge(i, p);\n    }\n    lca.build();\n    while (q--)\
    \ {\n        int u, v;\n        std::cin >> u >> v;\n        std::cout << lca.get(u,\
    \ v) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include <iostream>\n\
    \n#include \"../../graph/lowest_common_ancestor.hpp\"\nint main() {\n    int n,\
    \ q;\n    std::cin >> n >> q;\n    LowestCommonAncestor lca(n);\n    for (int\
    \ i = 1; i < n; i++) {\n        int p;\n        std::cin >> p;\n        lca.add_edge(i,\
    \ p);\n    }\n    lca.build();\n    while (q--) {\n        int u, v;\n       \
    \ std::cin >> u >> v;\n        std::cout << lca.get(u, v) << '\\n';\n    }\n}"
  dependsOn:
  - graph/lowest_common_ancestor.hpp
  - datastructure/plus_minus_one_range_minimum.hpp
  - datastructure/static_range_minimum.hpp
  isVerificationFile: true
  path: test/library-checker/lca.test.cpp
  requiredBy: []
  timestamp: '2022-09-02 14:42:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/lca.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/lca.test.cpp
- /verify/test/library-checker/lca.test.cpp.html
title: test/library-checker/lca.test.cpp
---
