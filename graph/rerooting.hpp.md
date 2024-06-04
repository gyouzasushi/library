---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/rerooting.hpp\"\n#include <cassert>\n#include <vector>\n\
    template <class S, S (*op)(S, S), S (*e)(), S (*put_edge)(S, int, int),\n    \
    \      S (*put_vertex)(S, int), S (*leaf)(int)>\nstruct rerooting {\npublic:\n\
    \    rerooting() {\n    }\n    rerooting(int n) : _n(n), g(n), dp(n) {\n    }\n\
    \    void add_edge(int u, int v) {\n        assert(0 <= u && u < _n);\n      \
    \  assert(0 <= v && v < _n);\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \    }\n    std::vector<S> solve() {\n        for (int i = 0; i < _n; i++) {\n\
    \            int deg = int(g[i].size());\n            dp[i].resize(deg);\n   \
    \     }\n        auto dfs1 = [&](auto dfs1, int u, int p) -> S {\n           \
    \ S ret = e();\n            int deg = int(g[u].size());\n            bool upd\
    \ = false;\n            for (int i = 0; i < deg; i++) {\n                int v\
    \ = g[u][i];\n                if (v == p) continue;\n                dp[u][i]\
    \ = dfs1(dfs1, v, u);\n                ret = op(ret, put_edge(dp[u][i], u, v));\n\
    \                upd = true;\n            }\n            if (!upd) return leaf(u);\n\
    \            return put_vertex(ret, u);\n        };\n        auto dfs2 = [&](auto\
    \ dfs2, int u, int p, const S& top) -> void {\n            int deg = int(g[u].size());\n\
    \            std::vector<S> cum_left(deg + 1, e()), cum_right(deg + 1, e());\n\
    \            for (int i = 0; i < deg; i++) {\n                int v = g[u][i];\n\
    \                if (v == p) dp[u][i] = top;\n                cum_left[i + 1]\
    \ = op(cum_left[i], put_edge(dp[u][i], u, v));\n            }\n            for\
    \ (int i = deg; i > 0; i--) {\n                int v = g[u][i - 1];\n        \
    \        if (v == p) dp[u][i - 1] = top;\n                cum_right[i - 1] =\n\
    \                    op(cum_right[i], put_edge(dp[u][i - 1], u, v));\n       \
    \     }\n            for (int i = 0; i < deg; i++) {\n                int v =\
    \ g[u][i];\n                if (v == p) continue;\n                dfs2(dfs2,\
    \ v, u,\n                     deg == 1\n                         ? leaf(u)\n \
    \                        : put_vertex(op(cum_left[i], cum_right[i + 1]), u));\n\
    \            }\n        };\n        dfs1(dfs1, 0, -1);\n        dfs2(dfs2, 0,\
    \ -1, e());\n        std::vector<S> ret(_n, e());\n        for (int u = 0; u <\
    \ _n; u++) {\n            int deg = int(g[u].size());\n            for (int i\
    \ = 0; i < deg; i++) {\n                int v = g[u][i];\n                ret[u]\
    \ = op(ret[u], put_edge(dp[u][i], u, v));\n            }\n            ret[u] =\
    \ put_vertex(ret[u], u);\n        }\n        return ret;\n    }\n\nprivate:\n\
    \    int _n;\n    std::vector<std::vector<int>> g;\n    std::vector<std::vector<S>>\
    \ dp;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\ntemplate <class S, S\
    \ (*op)(S, S), S (*e)(), S (*put_edge)(S, int, int),\n          S (*put_vertex)(S,\
    \ int), S (*leaf)(int)>\nstruct rerooting {\npublic:\n    rerooting() {\n    }\n\
    \    rerooting(int n) : _n(n), g(n), dp(n) {\n    }\n    void add_edge(int u,\
    \ int v) {\n        assert(0 <= u && u < _n);\n        assert(0 <= v && v < _n);\n\
    \        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n    std::vector<S>\
    \ solve() {\n        for (int i = 0; i < _n; i++) {\n            int deg = int(g[i].size());\n\
    \            dp[i].resize(deg);\n        }\n        auto dfs1 = [&](auto dfs1,\
    \ int u, int p) -> S {\n            S ret = e();\n            int deg = int(g[u].size());\n\
    \            bool upd = false;\n            for (int i = 0; i < deg; i++) {\n\
    \                int v = g[u][i];\n                if (v == p) continue;\n   \
    \             dp[u][i] = dfs1(dfs1, v, u);\n                ret = op(ret, put_edge(dp[u][i],\
    \ u, v));\n                upd = true;\n            }\n            if (!upd) return\
    \ leaf(u);\n            return put_vertex(ret, u);\n        };\n        auto dfs2\
    \ = [&](auto dfs2, int u, int p, const S& top) -> void {\n            int deg\
    \ = int(g[u].size());\n            std::vector<S> cum_left(deg + 1, e()), cum_right(deg\
    \ + 1, e());\n            for (int i = 0; i < deg; i++) {\n                int\
    \ v = g[u][i];\n                if (v == p) dp[u][i] = top;\n                cum_left[i\
    \ + 1] = op(cum_left[i], put_edge(dp[u][i], u, v));\n            }\n         \
    \   for (int i = deg; i > 0; i--) {\n                int v = g[u][i - 1];\n  \
    \              if (v == p) dp[u][i - 1] = top;\n                cum_right[i -\
    \ 1] =\n                    op(cum_right[i], put_edge(dp[u][i - 1], u, v));\n\
    \            }\n            for (int i = 0; i < deg; i++) {\n                int\
    \ v = g[u][i];\n                if (v == p) continue;\n                dfs2(dfs2,\
    \ v, u,\n                     deg == 1\n                         ? leaf(u)\n \
    \                        : put_vertex(op(cum_left[i], cum_right[i + 1]), u));\n\
    \            }\n        };\n        dfs1(dfs1, 0, -1);\n        dfs2(dfs2, 0,\
    \ -1, e());\n        std::vector<S> ret(_n, e());\n        for (int u = 0; u <\
    \ _n; u++) {\n            int deg = int(g[u].size());\n            for (int i\
    \ = 0; i < deg; i++) {\n                int v = g[u][i];\n                ret[u]\
    \ = op(ret[u], put_edge(dp[u][i], u, v));\n            }\n            ret[u] =\
    \ put_vertex(ret[u], u);\n        }\n        return ret;\n    }\n\nprivate:\n\
    \    int _n;\n    std::vector<std::vector<int>> g;\n    std::vector<std::vector<S>>\
    \ dp;\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/rerooting.hpp
  requiredBy: []
  timestamp: '2024-05-30 15:02:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/rerooting.hpp
layout: document
redirect_from:
- /library/graph/rerooting.hpp
- /library/graph/rerooting.hpp.html
title: graph/rerooting.hpp
---
