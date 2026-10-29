---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lowlink.hpp
    title: Lowlink
  - icon: ':heavy_check_mark:'
    path: graph/quotient_graph.hpp
    title: Quotient Graph
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
  bundledCode: "#line 1 \"test/unit/quotient_graph.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n#include\
    \ <set>\n#include <vector>\n\n#line 1 \"atcoder/scc.hpp\"\n\n\n\n#line 7 \"atcoder/scc.hpp\"\
    \n\n#line 1 \"atcoder/internal_scc.hpp\"\n\n\n\n#line 5 \"atcoder/internal_scc.hpp\"\
    \n#include <utility>\n#line 7 \"atcoder/internal_scc.hpp\"\n\n#line 1 \"atcoder/internal_csr.hpp\"\
    \n\n\n\n#line 7 \"atcoder/internal_csr.hpp\"\n\nnamespace atcoder {\nnamespace\
    \ internal {\n\ntemplate <class E> struct csr {\n    std::vector<int> start;\n\
    \    std::vector<E> elist;\n    explicit csr(int n, const std::vector<std::pair<int,\
    \ E>>& edges)\n        : start(n + 1), elist(edges.size()) {\n        for (auto\
    \ e : edges) {\n            start[e.first + 1]++;\n        }\n        for (int\
    \ i = 1; i <= n; i++) {\n            start[i] += start[i - 1];\n        }\n  \
    \      auto counter = start;\n        for (auto e : edges) {\n            elist[counter[e.first]++]\
    \ = e.second;\n        }\n    }\n};\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n\n#line 9 \"atcoder/internal_scc.hpp\"\n\nnamespace atcoder {\nnamespace\
    \ internal {\n\n// Reference:\n// R. Tarjan,\n// Depth-First Search and Linear\
    \ Graph Algorithms\nstruct scc_graph {\n  public:\n    explicit scc_graph(int\
    \ n) : _n(n) {}\n\n    int num_vertices() { return _n; }\n\n    void add_edge(int\
    \ from, int to) { edges.push_back({from, {to}}); }\n\n    // @return pair of (#\
    \ of scc, scc id)\n    std::pair<int, std::vector<int>> scc_ids() {\n        auto\
    \ g = csr<edge>(_n, edges);\n        int now_ord = 0, group_num = 0;\n       \
    \ std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);\n        visited.reserve(_n);\n\
    \        auto dfs = [&](auto self, int v) -> void {\n            low[v] = ord[v]\
    \ = now_ord++;\n            visited.push_back(v);\n            for (int i = g.start[v];\
    \ i < g.start[v + 1]; i++) {\n                auto to = g.elist[i].to;\n     \
    \           if (ord[to] == -1) {\n                    self(self, to);\n      \
    \              low[v] = std::min(low[v], low[to]);\n                } else {\n\
    \                    low[v] = std::min(low[v], ord[to]);\n                }\n\
    \            }\n            if (low[v] == ord[v]) {\n                while (true)\
    \ {\n                    int u = visited.back();\n                    visited.pop_back();\n\
    \                    ord[u] = _n;\n                    ids[u] = group_num;\n \
    \                   if (u == v) break;\n                }\n                group_num++;\n\
    \            }\n        };\n        for (int i = 0; i < _n; i++) {\n         \
    \   if (ord[i] == -1) dfs(dfs, i);\n        }\n        for (auto& x : ids) {\n\
    \            x = group_num - 1 - x;\n        }\n        return {group_num, ids};\n\
    \    }\n\n    std::vector<std::vector<int>> scc() {\n        auto ids = scc_ids();\n\
    \        int group_num = ids.first;\n        std::vector<int> counts(group_num);\n\
    \        for (auto x : ids.second) counts[x]++;\n        std::vector<std::vector<int>>\
    \ groups(ids.first);\n        for (int i = 0; i < group_num; i++) {\n        \
    \    groups[i].reserve(counts[i]);\n        }\n        for (int i = 0; i < _n;\
    \ i++) {\n            groups[ids.second[i]].push_back(i);\n        }\n       \
    \ return groups;\n    }\n\n  private:\n    int _n;\n    struct edge {\n      \
    \  int to;\n    };\n    std::vector<std::pair<int, edge>> edges;\n};\n\n}  //\
    \ namespace internal\n\n}  // namespace atcoder\n\n\n#line 9 \"atcoder/scc.hpp\"\
    \n\nnamespace atcoder {\n\nstruct scc_graph {\n  public:\n    scc_graph() : internal(0)\
    \ {}\n    explicit scc_graph(int n) : internal(n) {}\n\n    void add_edge(int\
    \ from, int to) {\n        int n = internal.num_vertices();\n        assert(0\
    \ <= from && from < n);\n        assert(0 <= to && to < n);\n        internal.add_edge(from,\
    \ to);\n    }\n\n    std::vector<std::vector<int>> scc() { return internal.scc();\
    \ }\n\n  private:\n    internal::scc_graph internal;\n};\n\n}  // namespace atcoder\n\
    \n\n#line 6 \"graph/lowlink.hpp\"\nstruct lowlink {\npublic:\n    lowlink() :\
    \ lowlink(0) {\n    }\n    explicit lowlink(int n) : _n(n), g(n), ord(n, -1),\
    \ low(n), comp(n, -1), art(n, false) {\n    }\n    int add_edge(int u, int v)\
    \ {\n        assert(0 <= u && u < _n);\n        assert(0 <= v && v < _n);\n  \
    \      int e = int(edges.size());\n        edges.emplace_back(u, v);\n       \
    \ g[u].emplace_back(v, e);\n        g[v].emplace_back(u, e);\n        return e;\n\
    \    }\n    void build() {\n        int m = int(edges.size());\n        bridge.assign(m,\
    \ false);\n        std::vector<int> it(_n, 0), par_edge(_n, -1), children(_n,\
    \ 0);\n        int t = 0;\n        for (int r = 0; r < _n; r++) {\n          \
    \  if (ord[r] != -1) continue;\n            std::vector<int> st = {r};\n     \
    \       ord[r] = low[r] = t++;\n            while (!st.empty()) {\n          \
    \      int v = st.back();\n                if (it[v] < int(g[v].size())) {\n \
    \                   auto [u, e] = g[v][it[v]++];\n                    if (e ==\
    \ par_edge[v]) continue;\n                    if (ord[u] == -1) {\n          \
    \              ord[u] = low[u] = t++;\n                        par_edge[u] = e;\n\
    \                        children[v]++;\n                        st.push_back(u);\n\
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
    \ bridge;\n};\n#line 4 \"graph/quotient_graph.hpp\"\ninline std::vector<int> component_id(int\
    \ n, const std::vector<std::vector<int>>& groups) {\n    std::vector<int> id(n);\n\
    \    for (int i = 0; i < int(groups.size()); i++) {\n        for (int v : groups[i])\
    \ id[v] = i;\n    }\n    return id;\n}\ninline std::vector<std::vector<int>> quotient_graph(const\
    \ std::vector<std::vector<int>>& g, const std::vector<std::vector<int>>& groups)\
    \ {\n    std::vector<int> id = component_id(int(g.size()), groups);\n    std::vector<std::vector<int>>\
    \ q(groups.size());\n    for (int u = 0; u < int(g.size()); u++) {\n        for\
    \ (int v : g[u]) {\n            if (id[u] != id[v]) q[id[u]].push_back(id[v]);\n\
    \        }\n    }\n    for (auto& es : q) {\n        std::ranges::sort(es);\n\
    \        es.erase(std::ranges::unique(es).begin(), es.end());\n    }\n    return\
    \ q;\n}\n#line 12 \"test/unit/quotient_graph.test.cpp\"\nint main() {\n    std::mt19937\
    \ rng(20261029);\n    for (int trial = 0; trial < 2000; trial++) {\n        int\
    \ n = 1 + rng() % 8;\n        int m = rng() % 16;\n        atcoder::scc_graph\
    \ sg(n);\n        std::vector<std::vector<int>> g(n);\n        std::vector<std::vector<bool>>\
    \ reach(n, std::vector<bool>(n, false));\n        for (int i = 0; i < n; i++)\
    \ reach[i][i] = true;\n        for (int i = 0; i < m; i++) {\n            int\
    \ u = rng() % n, v = rng() % n;\n            sg.add_edge(u, v);\n            g[u].push_back(v);\n\
    \            reach[u][v] = true;\n        }\n        for (int k = 0; k < n; k++)\
    \ {\n            for (int i = 0; i < n; i++) {\n                for (int j = 0;\
    \ j < n; j++) reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);\n   \
    \         }\n        }\n        std::vector<std::vector<int>> scc = sg.scc();\n\
    \        std::vector<int> id = component_id(n, scc);\n        std::vector<std::vector<int>>\
    \ dag = quotient_graph(g, scc);\n        int k = int(scc.size());\n        assert(int(dag.size())\
    \ == k);\n        for (int u = 0; u < n; u++) {\n            assert(0 <= id[u]\
    \ && id[u] < k);\n            for (int v = 0; v < n; v++) assert((id[u] == id[v])\
    \ == (reach[u][v] && reach[v][u]));\n            for (int v : g[u]) assert(id[u]\
    \ <= id[v]);\n        }\n        for (int i = 0; i < k; i++) {\n            for\
    \ (int v : scc[i]) assert(id[v] == i);\n        }\n        std::vector<std::set<int>>\
    \ expect(k);\n        for (int u = 0; u < n; u++) {\n            for (int v :\
    \ g[u]) {\n                if (id[u] != id[v]) expect[id[u]].insert(id[v]);\n\
    \            }\n        }\n        for (int i = 0; i < k; i++) {\n           \
    \ assert(dag[i] == std::vector<int>(expect[i].begin(), expect[i].end()));\n  \
    \          for (int j : dag[i]) assert(i < j);\n        }\n    }\n    for (int\
    \ trial = 0; trial < 2000; trial++) {\n        int n = 1 + rng() % 8;\n      \
    \  int m = rng() % 12;\n        lowlink lk(n);\n        std::vector<std::vector<int>>\
    \ g(n);\n        for (int i = 0; i < m; i++) {\n            int u = rng() % n,\
    \ v = rng() % n;\n            lk.add_edge(u, v);\n            g[u].push_back(v);\n\
    \            g[v].push_back(u);\n        }\n        lk.build();\n        std::vector<std::vector<int>>\
    \ comps = lk.two_edge_connected_components();\n        std::vector<int> id = component_id(n,\
    \ comps);\n        std::vector<std::vector<int>> tree = quotient_graph(g, comps);\n\
    \        int k = int(comps.size());\n        int edges = 0;\n        for (int\
    \ i = 0; i < k; i++) {\n            edges += int(tree[i].size());\n          \
    \  for (int j : tree[i]) assert(std::ranges::binary_search(tree[j], i));\n   \
    \     }\n        assert(edges == 2 * int(lk.bridges().size()));\n        for (int\
    \ v = 0; v < n; v++) assert(id[v] == lk.component(v));\n    }\n    std::cout <<\
    \ \"Hello World\\n\";\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <set>\n#include <vector>\n\n#include \"atcoder/scc\"\n#include \"graph/lowlink.hpp\"\
    \n#include \"graph/quotient_graph.hpp\"\nint main() {\n    std::mt19937 rng(20261029);\n\
    \    for (int trial = 0; trial < 2000; trial++) {\n        int n = 1 + rng() %\
    \ 8;\n        int m = rng() % 16;\n        atcoder::scc_graph sg(n);\n       \
    \ std::vector<std::vector<int>> g(n);\n        std::vector<std::vector<bool>>\
    \ reach(n, std::vector<bool>(n, false));\n        for (int i = 0; i < n; i++)\
    \ reach[i][i] = true;\n        for (int i = 0; i < m; i++) {\n            int\
    \ u = rng() % n, v = rng() % n;\n            sg.add_edge(u, v);\n            g[u].push_back(v);\n\
    \            reach[u][v] = true;\n        }\n        for (int k = 0; k < n; k++)\
    \ {\n            for (int i = 0; i < n; i++) {\n                for (int j = 0;\
    \ j < n; j++) reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);\n   \
    \         }\n        }\n        std::vector<std::vector<int>> scc = sg.scc();\n\
    \        std::vector<int> id = component_id(n, scc);\n        std::vector<std::vector<int>>\
    \ dag = quotient_graph(g, scc);\n        int k = int(scc.size());\n        assert(int(dag.size())\
    \ == k);\n        for (int u = 0; u < n; u++) {\n            assert(0 <= id[u]\
    \ && id[u] < k);\n            for (int v = 0; v < n; v++) assert((id[u] == id[v])\
    \ == (reach[u][v] && reach[v][u]));\n            for (int v : g[u]) assert(id[u]\
    \ <= id[v]);\n        }\n        for (int i = 0; i < k; i++) {\n            for\
    \ (int v : scc[i]) assert(id[v] == i);\n        }\n        std::vector<std::set<int>>\
    \ expect(k);\n        for (int u = 0; u < n; u++) {\n            for (int v :\
    \ g[u]) {\n                if (id[u] != id[v]) expect[id[u]].insert(id[v]);\n\
    \            }\n        }\n        for (int i = 0; i < k; i++) {\n           \
    \ assert(dag[i] == std::vector<int>(expect[i].begin(), expect[i].end()));\n  \
    \          for (int j : dag[i]) assert(i < j);\n        }\n    }\n    for (int\
    \ trial = 0; trial < 2000; trial++) {\n        int n = 1 + rng() % 8;\n      \
    \  int m = rng() % 12;\n        lowlink lk(n);\n        std::vector<std::vector<int>>\
    \ g(n);\n        for (int i = 0; i < m; i++) {\n            int u = rng() % n,\
    \ v = rng() % n;\n            lk.add_edge(u, v);\n            g[u].push_back(v);\n\
    \            g[v].push_back(u);\n        }\n        lk.build();\n        std::vector<std::vector<int>>\
    \ comps = lk.two_edge_connected_components();\n        std::vector<int> id = component_id(n,\
    \ comps);\n        std::vector<std::vector<int>> tree = quotient_graph(g, comps);\n\
    \        int k = int(comps.size());\n        int edges = 0;\n        for (int\
    \ i = 0; i < k; i++) {\n            edges += int(tree[i].size());\n          \
    \  for (int j : tree[i]) assert(std::ranges::binary_search(tree[j], i));\n   \
    \     }\n        assert(edges == 2 * int(lk.bridges().size()));\n        for (int\
    \ v = 0; v < n; v++) assert(id[v] == lk.component(v));\n    }\n    std::cout <<\
    \ \"Hello World\\n\";\n}\n"
  dependsOn:
  - graph/lowlink.hpp
  - graph/quotient_graph.hpp
  isVerificationFile: true
  path: test/unit/quotient_graph.test.cpp
  requiredBy: []
  timestamp: '2026-10-29 21:49:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/quotient_graph.test.cpp
layout: document
redirect_from:
- /verify/test/unit/quotient_graph.test.cpp
- /verify/test/unit/quotient_graph.test.cpp.html
title: test/unit/quotient_graph.test.cpp
---
