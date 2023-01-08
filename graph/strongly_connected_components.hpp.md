---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/scc.test.cpp
    title: test/library-checker/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/strongly_connected_components.hpp\"\n#include <cassert>\n\
    #include <vector>\nnamespace internal {\ntemplate <class E>\nstruct csr {\n  \
    \  std::vector<int> start;\n    std::vector<E> elist;\n    csr(int n, const std::vector<std::pair<int,\
    \ E>>& edges)\n        : start(n + 1), elist(edges.size()) {\n        for (auto\
    \ e : edges) {\n            start[e.first + 1]++;\n        }\n        for (int\
    \ i = 1; i <= n; i++) {\n            start[i] += start[i - 1];\n        }\n  \
    \      auto counter = start;\n        for (auto e : edges) {\n            elist[counter[e.first]++]\
    \ = e.second;\n        }\n    }\n};\n\n// Reference:\n// R. Tarjan,\n// Depth-First\
    \ Search and Linear Graph Algorithms\nstruct scc_graph {\npublic:\n    scc_graph(int\
    \ n) : _n(n) {\n    }\n    int num_vertices() {\n        return _n;\n    }\n \
    \   void add_edge(int from, int to) {\n        edges.push_back({from, {to}});\n\
    \    }\n    // @return pair of (# of scc, scc id)\n    std::pair<int, std::vector<int>>\
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
    \ - x;\n        }\n        return {group_num, ids};\n    }\n    std::vector<std::vector<int>>\
    \ scc() {\n        auto ids = scc_ids();\n        int group_num = ids.first;\n\
    \        std::vector<int> counts(group_num);\n        for (auto x : ids.second)\
    \ counts[x]++;\n        std::vector<std::vector<int>> groups(ids.first);\n   \
    \     for (int i = 0; i < group_num; i++) {\n            groups[i].reserve(counts[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            groups[ids.second[i]].push_back(i);\n\
    \        }\n        return groups;\n    }\n\nprivate:\n    int _n;\n    struct\
    \ edge {\n        int to;\n    };\n    std::vector<std::pair<int, edge>> edges;\n\
    };\n}  // namespace internal\n\nstruct scc_graph {\npublic:\n    scc_graph() :\
    \ internal(0) {\n    }\n    scc_graph(int n) : internal(n) {\n    }\n\n    void\
    \ add_edge(int from, int to) {\n        int n = internal.num_vertices();\n   \
    \     assert(0 <= from && from < n);\n        assert(0 <= to && to < n);\n   \
    \     internal.add_edge(from, to);\n    }\n    std::vector<std::vector<int>> scc()\
    \ {\n        return internal.scc();\n    }\n\nprivate:\n    internal::scc_graph\
    \ internal;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nnamespace internal {\n\
    template <class E>\nstruct csr {\n    std::vector<int> start;\n    std::vector<E>\
    \ elist;\n    csr(int n, const std::vector<std::pair<int, E>>& edges)\n      \
    \  : start(n + 1), elist(edges.size()) {\n        for (auto e : edges) {\n   \
    \         start[e.first + 1]++;\n        }\n        for (int i = 1; i <= n; i++)\
    \ {\n            start[i] += start[i - 1];\n        }\n        auto counter =\
    \ start;\n        for (auto e : edges) {\n            elist[counter[e.first]++]\
    \ = e.second;\n        }\n    }\n};\n\n// Reference:\n// R. Tarjan,\n// Depth-First\
    \ Search and Linear Graph Algorithms\nstruct scc_graph {\npublic:\n    scc_graph(int\
    \ n) : _n(n) {\n    }\n    int num_vertices() {\n        return _n;\n    }\n \
    \   void add_edge(int from, int to) {\n        edges.push_back({from, {to}});\n\
    \    }\n    // @return pair of (# of scc, scc id)\n    std::pair<int, std::vector<int>>\
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
    \ - x;\n        }\n        return {group_num, ids};\n    }\n    std::vector<std::vector<int>>\
    \ scc() {\n        auto ids = scc_ids();\n        int group_num = ids.first;\n\
    \        std::vector<int> counts(group_num);\n        for (auto x : ids.second)\
    \ counts[x]++;\n        std::vector<std::vector<int>> groups(ids.first);\n   \
    \     for (int i = 0; i < group_num; i++) {\n            groups[i].reserve(counts[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            groups[ids.second[i]].push_back(i);\n\
    \        }\n        return groups;\n    }\n\nprivate:\n    int _n;\n    struct\
    \ edge {\n        int to;\n    };\n    std::vector<std::pair<int, edge>> edges;\n\
    };\n}  // namespace internal\n\nstruct scc_graph {\npublic:\n    scc_graph() :\
    \ internal(0) {\n    }\n    scc_graph(int n) : internal(n) {\n    }\n\n    void\
    \ add_edge(int from, int to) {\n        int n = internal.num_vertices();\n   \
    \     assert(0 <= from && from < n);\n        assert(0 <= to && to < n);\n   \
    \     internal.add_edge(from, to);\n    }\n    std::vector<std::vector<int>> scc()\
    \ {\n        return internal.scc();\n    }\n\nprivate:\n    internal::scc_graph\
    \ internal;\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/strongly_connected_components.hpp
  requiredBy: []
  timestamp: '2023-01-08 14:08:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/scc.test.cpp
documentation_of: graph/strongly_connected_components.hpp
layout: document
title: Strongly Connected Components
---

### 概要
- ACL の SCC。
  
### 使い方
- [ACL のドキュメント](https://atcoder.github.io/ac-library/production/document_ja/scc.html)を参照。