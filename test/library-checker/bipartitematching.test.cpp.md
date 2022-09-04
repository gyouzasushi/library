---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/maxflow.hpp
    title: MaxFlow
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/library-checker/bipartitematching.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include <iostream>\n\
    \n#line 2 \"graph/maxflow.hpp\"\n#include <cassert>\n#include <limits>\n#include\
    \ <vector>\nnamespace internal {\ntemplate <class T>\nstruct simple_queue {\n\
    \    std::vector<T> payload;\n    int pos = 0;\n    void reserve(int n) {\n  \
    \      payload.reserve(n);\n    }\n    int size() const {\n        return int(payload.size())\
    \ - pos;\n    }\n    bool empty() const {\n        return pos == int(payload.size());\n\
    \    }\n    void push(const T& t) {\n        payload.push_back(t);\n    }\n  \
    \  T& front() {\n        return payload[pos];\n    }\n    void clear() {\n   \
    \     payload.clear();\n        pos = 0;\n    }\n    void pop() {\n        pos++;\n\
    \    }\n};\n}  // namespace internal\ntemplate <class Cap>\nstruct mf_graph {\n\
    public:\n    mf_graph() : _n(0) {\n    }\n    mf_graph(int n) : _n(n), g(n) {\n\
    \    }\n    int add_edge(int from, int to, Cap cap) {\n        assert(0 <= from\
    \ && from < _n);\n        assert(0 <= to && to < _n);\n        assert(0 <= cap);\n\
    \        int m = int(pos.size());\n        pos.push_back({from, int(g[from].size())});\n\
    \        g[from].push_back(_edge{to, int(g[to].size()), cap});\n        g[to].push_back(_edge{from,\
    \ int(g[from].size()) - 1, 0});\n        return m;\n    }\n    struct edge {\n\
    \        int from, to;\n        Cap cap, flow;\n    };\n    edge get_edge(int\
    \ i) {\n        int m = int(pos.size());\n        assert(0 <= i && i < m);\n \
    \       auto _e = g[pos[i].first][pos[i].second];\n        auto _re = g[_e.to][_e.rev];\n\
    \        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};\n    }\n\
    \    std::vector<edge> edges() {\n        int m = int(pos.size());\n        std::vector<edge>\
    \ result;\n        for (int i = 0; i < m; i++) {\n            result.push_back(get_edge(i));\n\
    \        }\n        return result;\n    }\n    void change_edge(int i, Cap new_cap,\
    \ Cap new_flow) {\n        int m = int(pos.size());\n        assert(0 <= i &&\
    \ i < m);\n        assert(0 <= new_flow && new_flow <= new_cap);\n        auto&\
    \ _e = g[pos[i].first][pos[i].second];\n        auto& _re = g[_e.to][_e.rev];\n\
    \        _e.cap = new_cap - new_flow;\n        _re.cap = new_flow;\n    }\n  \
    \  Cap flow(int s, int t) {\n        return flow(s, t, std::numeric_limits<Cap>::max());\n\
    \    }\n    Cap flow(int s, int t, Cap flow_limit) {\n        assert(0 <= s &&\
    \ s < _n);\n        assert(0 <= t && t < _n);\n        std::vector<int> level(_n),\
    \ iter(_n);\n        internal::simple_queue<int> que;\n        auto bfs = [&]()\
    \ {\n            std::fill(level.begin(), level.end(), -1);\n            level[s]\
    \ = 0;\n            que.clear();\n            que.push(s);\n            while\
    \ (!que.empty()) {\n                int v = que.front();\n                que.pop();\n\
    \                for (auto e : g[v]) {\n                    if (e.cap == 0 ||\
    \ level[e.to] >= 0) continue;\n                    level[e.to] = level[v] + 1;\n\
    \                    if (e.to == t) return;\n                    que.push(e.to);\n\
    \                }\n            }\n        };\n        auto dfs = [&](auto self,\
    \ int v, Cap up) {\n            if (v == s) return up;\n            Cap res =\
    \ 0;\n            int level_v = level[v];\n            for (int& i = iter[v];\
    \ i < int(g[v].size()); i++) {\n                _edge& e = g[v][i];\n        \
    \        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;\n  \
    \              Cap d =\n                    self(self, e.to, std::min(up - res,\
    \ g[e.to][e.rev].cap));\n                if (d <= 0) continue;\n             \
    \   g[v][i].cap += d;\n                g[e.to][e.rev].cap -= d;\n            \
    \    res += d;\n                if (res == up) break;\n            }\n       \
    \     return res;\n        };\n        Cap flow = 0;\n        while (flow < flow_limit)\
    \ {\n            bfs();\n            if (level[t] == -1) break;\n            std::fill(iter.begin(),\
    \ iter.end(), 0);\n            while (flow < flow_limit) {\n                Cap\
    \ f = dfs(dfs, t, flow_limit - flow);\n                if (!f) break;\n      \
    \          flow += f;\n            }\n        }\n        return flow;\n    }\n\
    \    std::vector<bool> min_cut(int s) {\n        std::vector<bool> visited(_n);\n\
    \        internal::simple_queue<int> que;\n        que.push(s);\n        while\
    \ (!que.empty()) {\n            int p = que.front();\n            que.pop();\n\
    \            visited[p] = true;\n            for (auto e : g[p]) {\n         \
    \       if (e.cap && !visited[e.to]) {\n                    visited[e.to] = true;\n\
    \                    que.push(e.to);\n                }\n            }\n     \
    \   }\n        return visited;\n    }\n\nprivate:\n    int _n;\n    struct _edge\
    \ {\n        int to, rev;\n        Cap cap;\n    };\n    std::vector<std::pair<int,\
    \ int>> pos;\n    std::vector<std::vector<_edge>> g;\n};\n#line 5 \"test/library-checker/bipartitematching.test.cpp\"\
    \n\nint main() {\n    int l, r, m;\n    std::cin >> l >> r >> m;\n    int n =\
    \ l + r + 2;\n    int s = n - 2, t = n - 1;\n    mf_graph<int> g(n);\n    for\
    \ (int a = 0; a < l; a++) g.add_edge(s, a, 1);\n    for (int b = l; b < l + r;\
    \ b++) g.add_edge(b, t, 1);\n    for (int i = 0; i < m; i++) {\n        int a,\
    \ b;\n        std::cin >> a >> b;\n        g.add_edge(a, b + l, 1);\n    }\n \
    \   int k = g.flow(s, t);\n    std::cout << k << '\\n';\n    for (auto e : g.edges())\
    \ {\n        if (e.flow == 1 && e.from != s && e.to != t) {\n            std::cout\
    \ << e.from << ' ' << e.to - l << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ <iostream>\n\n#include \"../../graph/maxflow.hpp\"\n\nint main() {\n    int\
    \ l, r, m;\n    std::cin >> l >> r >> m;\n    int n = l + r + 2;\n    int s =\
    \ n - 2, t = n - 1;\n    mf_graph<int> g(n);\n    for (int a = 0; a < l; a++)\
    \ g.add_edge(s, a, 1);\n    for (int b = l; b < l + r; b++) g.add_edge(b, t, 1);\n\
    \    for (int i = 0; i < m; i++) {\n        int a, b;\n        std::cin >> a >>\
    \ b;\n        g.add_edge(a, b + l, 1);\n    }\n    int k = g.flow(s, t);\n   \
    \ std::cout << k << '\\n';\n    for (auto e : g.edges()) {\n        if (e.flow\
    \ == 1 && e.from != s && e.to != t) {\n            std::cout << e.from << ' '\
    \ << e.to - l << '\\n';\n        }\n    }\n}"
  dependsOn:
  - graph/maxflow.hpp
  isVerificationFile: true
  path: test/library-checker/bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2022-09-03 03:01:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/bipartitematching.test.cpp
- /verify/test/library-checker/bipartitematching.test.cpp.html
title: test/library-checker/bipartitematching.test.cpp
---