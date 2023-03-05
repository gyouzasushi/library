---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/library-checker/scc.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/scc\"\n#line 1 \"atcoder/scc.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <vector>\n\n#line 1 \"atcoder/internal_scc.hpp\"\
    \n\n\n\n#line 5 \"atcoder/internal_scc.hpp\"\n#include <utility>\n#line 7 \"atcoder/internal_scc.hpp\"\
    \n\n#line 1 \"atcoder/internal_csr.hpp\"\n\n\n\n#line 7 \"atcoder/internal_csr.hpp\"\
    \n\nnamespace atcoder {\nnamespace internal {\n\ntemplate <class E> struct csr\
    \ {\n    std::vector<int> start;\n    std::vector<E> elist;\n    explicit csr(int\
    \ n, const std::vector<std::pair<int, E>>& edges)\n        : start(n + 1), elist(edges.size())\
    \ {\n        for (auto e : edges) {\n            start[e.first + 1]++;\n     \
    \   }\n        for (int i = 1; i <= n; i++) {\n            start[i] += start[i\
    \ - 1];\n        }\n        auto counter = start;\n        for (auto e : edges)\
    \ {\n            elist[counter[e.first]++] = e.second;\n        }\n    }\n};\n\
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 9 \"atcoder/internal_scc.hpp\"\
    \n\nnamespace atcoder {\nnamespace internal {\n\n// Reference:\n// R. Tarjan,\n\
    // Depth-First Search and Linear Graph Algorithms\nstruct scc_graph {\n  public:\n\
    \    explicit scc_graph(int n) : _n(n) {}\n\n    int num_vertices() { return _n;\
    \ }\n\n    void add_edge(int from, int to) { edges.push_back({from, {to}}); }\n\
    \n    // @return pair of (# of scc, scc id)\n    std::pair<int, std::vector<int>>\
    \ scc_ids() {\n        auto g = csr<edge>(_n, edges);\n        int now_ord = 0,\
    \ group_num = 0;\n        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);\n\
    \        visited.reserve(_n);\n        auto dfs = [&](auto self, int v) -> void\
    \ {\n            low[v] = ord[v] = now_ord++;\n            visited.push_back(v);\n\
    \            for (int i = g.start[v]; i < g.start[v + 1]; i++) {\n           \
    \     auto to = g.elist[i].to;\n                if (ord[to] == -1) {\n       \
    \             self(self, to);\n                    low[v] = std::min(low[v], low[to]);\n\
    \                } else {\n                    low[v] = std::min(low[v], ord[to]);\n\
    \                }\n            }\n            if (low[v] == ord[v]) {\n     \
    \           while (true) {\n                    int u = visited.back();\n    \
    \                visited.pop_back();\n                    ord[u] = _n;\n     \
    \               ids[u] = group_num;\n                    if (u == v) break;\n\
    \                }\n                group_num++;\n            }\n        };\n\
    \        for (int i = 0; i < _n; i++) {\n            if (ord[i] == -1) dfs(dfs,\
    \ i);\n        }\n        for (auto& x : ids) {\n            x = group_num - 1\
    \ - x;\n        }\n        return {group_num, ids};\n    }\n\n    std::vector<std::vector<int>>\
    \ scc() {\n        auto ids = scc_ids();\n        int group_num = ids.first;\n\
    \        std::vector<int> counts(group_num);\n        for (auto x : ids.second)\
    \ counts[x]++;\n        std::vector<std::vector<int>> groups(ids.first);\n   \
    \     for (int i = 0; i < group_num; i++) {\n            groups[i].reserve(counts[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            groups[ids.second[i]].push_back(i);\n\
    \        }\n        return groups;\n    }\n\n  private:\n    int _n;\n    struct\
    \ edge {\n        int to;\n    };\n    std::vector<std::pair<int, edge>> edges;\n\
    };\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 9 \"atcoder/scc.hpp\"\
    \n\nnamespace atcoder {\n\nstruct scc_graph {\n  public:\n    scc_graph() : internal(0)\
    \ {}\n    explicit scc_graph(int n) : internal(n) {}\n\n    void add_edge(int\
    \ from, int to) {\n        int n = internal.num_vertices();\n        assert(0\
    \ <= from && from < n);\n        assert(0 <= to && to < n);\n        internal.add_edge(from,\
    \ to);\n    }\n\n    std::vector<std::vector<int>> scc() { return internal.scc();\
    \ }\n\n  private:\n    internal::scc_graph internal;\n};\n\n}  // namespace atcoder\n\
    \n\n#line 3 \"test/library-checker/scc.test.cpp\"\n\n#include <iostream>\n\nint\
    \ main() {\n    int n, m;\n    std::cin >> n >> m;\n    atcoder::scc_graph g(n);\n\
    \    for (int i = 0; i < m; i++) {\n        int u, v;\n        std::cin >> u >>\
    \ v;\n        g.add_edge(u, v);\n    }\n    auto scc = g.scc();\n    std::cout\
    \ << scc.size() << '\\n';\n    for (auto &v : scc) {\n        int k = v.size();\n\
    \        std::cout << k << ' ';\n        for (int i = 0; i < k; i++) {\n     \
    \       std::cout << v[i] << \" \\n\"[i == k - 1];\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include \"atcoder/scc.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n    int n, m;\n    std::cin >> n >> m;\n\
    \    atcoder::scc_graph g(n);\n    for (int i = 0; i < m; i++) {\n        int\
    \ u, v;\n        std::cin >> u >> v;\n        g.add_edge(u, v);\n    }\n    auto\
    \ scc = g.scc();\n    std::cout << scc.size() << '\\n';\n    for (auto &v : scc)\
    \ {\n        int k = v.size();\n        std::cout << k << ' ';\n        for (int\
    \ i = 0; i < k; i++) {\n            std::cout << v[i] << \" \\n\"[i == k - 1];\n\
    \        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/scc.test.cpp
  requiredBy: []
  timestamp: '2023-03-05 19:19:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/scc.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/scc.test.cpp
- /verify/test/library-checker/scc.test.cpp.html
title: test/library-checker/scc.test.cpp
---
