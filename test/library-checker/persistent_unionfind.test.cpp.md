---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/rollback_dsu.hpp
    title: Rollback DSU
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/library-checker/persistent_unionfind.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n#include <iostream>\n\
    #include <vector>\n\n#line 2 \"datastructure/rollback_dsu.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#line 6 \"datastructure/rollback_dsu.hpp\"\
    \nstruct rollback_dsu {\npublic:\n    rollback_dsu() : rollback_dsu(0) {\n   \
    \ }\n    explicit rollback_dsu(int n) : _n(n), parent_or_size(n, -1) {\n    }\n\
    \    int merge(int a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0\
    \ <= b && b < _n);\n        int x = leader(a), y = leader(b);\n        if (x ==\
    \ y) {\n            history.emplace_back(-1, -1);\n            return x;\n   \
    \     }\n        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);\n\
    \        history.emplace_back(y, parent_or_size[y]);\n        parent_or_size[x]\
    \ += parent_or_size[y];\n        parent_or_size[y] = x;\n        return x;\n \
    \   }\n    void undo() {\n        assert(!history.empty());\n        auto [y,\
    \ s] = history.back();\n        history.pop_back();\n        if (y == -1) return;\n\
    \        parent_or_size[parent_or_size[y]] -= s;\n        parent_or_size[y] =\
    \ s;\n    }\n    int time() const {\n        return int(history.size());\n   \
    \ }\n    void rollback(int t) {\n        assert(0 <= t && t <= time());\n    \
    \    while (time() > t) undo();\n    }\n    bool same(int a, int b) const {\n\
    \        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n      \
    \  return leader(a) == leader(b);\n    }\n    int leader(int a) const {\n    \
    \    assert(0 <= a && a < _n);\n        while (parent_or_size[a] >= 0) a = parent_or_size[a];\n\
    \        return a;\n    }\n    int size(int a) const {\n        assert(0 <= a\
    \ && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n    std::vector<std::vector<int>>\
    \ groups() const {\n        std::vector<int> leader_buf(_n), group_size(_n);\n\
    \        for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n\
    \            group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) result[i].reserve(group_size[i]);\n\
    \        for (int i = 0; i < _n; i++) result[leader_buf[i]].push_back(i);\n  \
    \      result.erase(std::remove_if(result.begin(), result.end(),\n           \
    \                         [&](const std::vector<int>& v) { return v.empty(); }),\n\
    \                     result.end());\n        return result;\n    }\n\nprivate:\n\
    \    int _n;\n    std::vector<int> parent_or_size;\n    std::vector<std::pair<int,\
    \ int>> history;  // (attached leader, its old parent_or_size)\n};\n#line 6 \"\
    test/library-checker/persistent_unionfind.test.cpp\"\n\nint main() {\n    int\
    \ n, q;\n    std::cin >> n >> q;\n    std::vector<int> t(q), k(q), u(q), v(q);\n\
    \    // version tree: node q is G_{-1}; type-0 query i is node i with parent k\n\
    \    std::vector<std::vector<int>> children(q + 1), asks(q + 1);\n    for (int\
    \ i = 0; i < q; i++) {\n        std::cin >> t[i] >> k[i] >> u[i] >> v[i];\n  \
    \      int p = k[i] == -1 ? q : k[i];\n        if (t[i] == 0) {\n            children[p].push_back(i);\n\
    \        } else {\n            asks[p].push_back(i);\n        }\n    }\n    std::vector<int>\
    \ ans(q, -1);\n    rollback_dsu d(n);\n    std::vector<std::pair<int, int>> st\
    \ = {{q, 0}};  // (node, next child index)\n    while (!st.empty()) {\n      \
    \  auto& [x, it] = st.back();\n        if (it == 0) {\n            if (x != q)\
    \ d.merge(u[x], v[x]);\n            for (int i : asks[x]) ans[i] = d.same(u[i],\
    \ v[i]);\n        }\n        if (it < int(children[x].size())) {\n           \
    \ int c = children[x][it++];\n            st.emplace_back(c, 0);\n        } else\
    \ {\n            if (x != q) d.undo();\n            st.pop_back();\n        }\n\
    \    }\n    for (int i = 0; i < q; i++) {\n        if (t[i] == 1) std::cout <<\
    \ ans[i] << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    #include <iostream>\n#include <vector>\n\n#include \"datastructure/rollback_dsu.hpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<int>\
    \ t(q), k(q), u(q), v(q);\n    // version tree: node q is G_{-1}; type-0 query\
    \ i is node i with parent k\n    std::vector<std::vector<int>> children(q + 1),\
    \ asks(q + 1);\n    for (int i = 0; i < q; i++) {\n        std::cin >> t[i] >>\
    \ k[i] >> u[i] >> v[i];\n        int p = k[i] == -1 ? q : k[i];\n        if (t[i]\
    \ == 0) {\n            children[p].push_back(i);\n        } else {\n         \
    \   asks[p].push_back(i);\n        }\n    }\n    std::vector<int> ans(q, -1);\n\
    \    rollback_dsu d(n);\n    std::vector<std::pair<int, int>> st = {{q, 0}}; \
    \ // (node, next child index)\n    while (!st.empty()) {\n        auto& [x, it]\
    \ = st.back();\n        if (it == 0) {\n            if (x != q) d.merge(u[x],\
    \ v[x]);\n            for (int i : asks[x]) ans[i] = d.same(u[i], v[i]);\n   \
    \     }\n        if (it < int(children[x].size())) {\n            int c = children[x][it++];\n\
    \            st.emplace_back(c, 0);\n        } else {\n            if (x != q)\
    \ d.undo();\n            st.pop_back();\n        }\n    }\n    for (int i = 0;\
    \ i < q; i++) {\n        if (t[i] == 1) std::cout << ans[i] << '\\n';\n    }\n\
    }\n"
  dependsOn:
  - datastructure/rollback_dsu.hpp
  isVerificationFile: true
  path: test/library-checker/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 01:30:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/persistent_unionfind.test.cpp
- /verify/test/library-checker/persistent_unionfind.test.cpp.html
title: test/library-checker/persistent_unionfind.test.cpp
---
