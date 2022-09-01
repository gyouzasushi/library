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
  bundledCode: "#line 2 \"graph/rerooting.hpp\"\ntemplate <typename T, T (*f1)(T,\
    \ int, int), T (*f2)(T, int), T (*merge)(T, T),\n          T (*e)()>\nstruct ReRooting\
    \ {\n    // dp_v = f2(merge(f1(dp_c1,v,c1), f1(dp_c2,v,c2), ..., f1(dp_ck,v,ck))\
    \ , v)\npublic:\n    ReRooting() : ReRooting(0) {\n    }\n    ReRooting(int n)\
    \ : n(n), g(n), dp(n) {\n    }\n    void add_edge(int from, int to) {\n      \
    \  assert(0 <= from && from < n);\n        assert(0 <= to && to < n);\n      \
    \  g[from].push_back(to);\n        g[to].push_back(from);\n    }\n\n    void build(int\
    \ root = 0) {\n        for (int i = 0; i < n; i++) {\n            int deg = int(g[i].size());\n\
    \            dp[i].resize(deg);\n        }\n        auto dfs1 = [&](auto dfs1,\
    \ int pos, int pre) -> T {\n            T ret = e();\n            int deg = int(g[pos].size());\n\
    \            for (int i = 0; i < deg; i++) {\n                int nxt = g[pos][i];\n\
    \                if (nxt == pre) continue;\n                dp[pos][i] = dfs1(dfs1,\
    \ nxt, pos);\n                ret = merge(ret, f1(dp[pos][i], pos, nxt));\n  \
    \          }\n            return f2(ret, pos);\n        };\n        auto dfs2\
    \ = [&](auto dfs2, int pos, int pre, const T &top) -> void {\n            int\
    \ deg = int(g[pos].size());\n            vector<T> sum_left(deg + 1, e()), sum_right(deg\
    \ + 1, e());\n            for (int i = 0; i < deg; i++) {\n                int\
    \ nxt = g[pos][i];\n                T tmp = (nxt == pre ? dp[pos][i] = top : dp[pos][i]);\n\
    \                sum_left[i + 1] = merge(sum_left[i], f1(tmp, pos, nxt));\n  \
    \          }\n            for (int i = deg; i > 0; i--) {\n                int\
    \ nxt = g[pos][i - 1];\n                T tmp = (nxt == pre ? dp[pos][i - 1] =\
    \ top : dp[pos][i - 1]);\n                sum_right[i - 1] = merge(sum_right[i],\
    \ f1(tmp, pos, nxt));\n            }\n            for (int i = 0; i < deg; i++)\
    \ {\n                int nxt = g[pos][i];\n                if (nxt == pre) continue;\n\
    \                T tmp = merge(sum_left[i], sum_right[i + 1]);\n             \
    \   dfs2(dfs2, nxt, pos, f2(tmp, pos));\n            }\n        };\n        dfs1(dfs1,\
    \ root, -1);\n        dfs2(dfs2, root, -1, e());\n    }\n\n    T solve(int pos)\
    \ {\n        T ans = e();\n        int deg = int(g[pos].size());\n        for\
    \ (int i = 0; i < deg; i++) {\n            int nxt = g[pos][i];\n            ans\
    \ = merge(ans, f1(dp[pos][i], pos, nxt));\n        }\n        return f2(ans, pos);\n\
    \    }\n\nprivate:\n    int n;\n    vector<vector<int>> g;\n    vector<vector<T>>\
    \ dp;\n};\n"
  code: "#pragma once\ntemplate <typename T, T (*f1)(T, int, int), T (*f2)(T, int),\
    \ T (*merge)(T, T),\n          T (*e)()>\nstruct ReRooting {\n    // dp_v = f2(merge(f1(dp_c1,v,c1),\
    \ f1(dp_c2,v,c2), ..., f1(dp_ck,v,ck)) , v)\npublic:\n    ReRooting() : ReRooting(0)\
    \ {\n    }\n    ReRooting(int n) : n(n), g(n), dp(n) {\n    }\n    void add_edge(int\
    \ from, int to) {\n        assert(0 <= from && from < n);\n        assert(0 <=\
    \ to && to < n);\n        g[from].push_back(to);\n        g[to].push_back(from);\n\
    \    }\n\n    void build(int root = 0) {\n        for (int i = 0; i < n; i++)\
    \ {\n            int deg = int(g[i].size());\n            dp[i].resize(deg);\n\
    \        }\n        auto dfs1 = [&](auto dfs1, int pos, int pre) -> T {\n    \
    \        T ret = e();\n            int deg = int(g[pos].size());\n           \
    \ for (int i = 0; i < deg; i++) {\n                int nxt = g[pos][i];\n    \
    \            if (nxt == pre) continue;\n                dp[pos][i] = dfs1(dfs1,\
    \ nxt, pos);\n                ret = merge(ret, f1(dp[pos][i], pos, nxt));\n  \
    \          }\n            return f2(ret, pos);\n        };\n        auto dfs2\
    \ = [&](auto dfs2, int pos, int pre, const T &top) -> void {\n            int\
    \ deg = int(g[pos].size());\n            vector<T> sum_left(deg + 1, e()), sum_right(deg\
    \ + 1, e());\n            for (int i = 0; i < deg; i++) {\n                int\
    \ nxt = g[pos][i];\n                T tmp = (nxt == pre ? dp[pos][i] = top : dp[pos][i]);\n\
    \                sum_left[i + 1] = merge(sum_left[i], f1(tmp, pos, nxt));\n  \
    \          }\n            for (int i = deg; i > 0; i--) {\n                int\
    \ nxt = g[pos][i - 1];\n                T tmp = (nxt == pre ? dp[pos][i - 1] =\
    \ top : dp[pos][i - 1]);\n                sum_right[i - 1] = merge(sum_right[i],\
    \ f1(tmp, pos, nxt));\n            }\n            for (int i = 0; i < deg; i++)\
    \ {\n                int nxt = g[pos][i];\n                if (nxt == pre) continue;\n\
    \                T tmp = merge(sum_left[i], sum_right[i + 1]);\n             \
    \   dfs2(dfs2, nxt, pos, f2(tmp, pos));\n            }\n        };\n        dfs1(dfs1,\
    \ root, -1);\n        dfs2(dfs2, root, -1, e());\n    }\n\n    T solve(int pos)\
    \ {\n        T ans = e();\n        int deg = int(g[pos].size());\n        for\
    \ (int i = 0; i < deg; i++) {\n            int nxt = g[pos][i];\n            ans\
    \ = merge(ans, f1(dp[pos][i], pos, nxt));\n        }\n        return f2(ans, pos);\n\
    \    }\n\nprivate:\n    int n;\n    vector<vector<int>> g;\n    vector<vector<T>>\
    \ dp;\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/rerooting.hpp
  requiredBy: []
  timestamp: '2022-09-01 13:39:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/rerooting.hpp
layout: document
redirect_from:
- /library/graph/rerooting.hpp
- /library/graph/rerooting.hpp.html
title: graph/rerooting.hpp
---
