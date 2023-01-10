---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/unionfind.hpp
    title: datastructure/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/library-checker/unionfind.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#line 4 \"datastructure/unionfind.hpp\"\nstruct UnionFind {\n    int n;\n  \
    \  std::vector<int> data;\n    UnionFind(int _n) : n(_n), data(_n, -1) {\n   \
    \ }\n    int root(int x) {\n        return (data[x] < 0) ? x : data[x] = root(data[x]);\n\
    \    }\n    bool unite(int x, int y) {\n        x = root(x);\n        y = root(y);\n\
    \        if (x != y) {\n            if (data[y] < data[x]) std::swap(x, y);\n\
    \            data[x] += data[y];\n            data[y] = x;\n        }\n      \
    \  return x != y;\n    }\n    bool find(int x, int y) {\n        return root(x)\
    \ == root(y);\n    }\n    int size(int x) {\n        return -data[root(x)];\n\
    \    }\n    std::vector<std::vector<int>> groups() {\n        std::vector<int>\
    \ root_buf(n), group_size(n);\n        for (int i = 0; i < n; i++) {\n       \
    \     root_buf[i] = root(i);\n            group_size[root_buf[i]]++;\n       \
    \ }\n        std::vector<std::vector<int>> ret(n);\n        for (int i = 0; i\
    \ < n; i++) {\n            ret[i].reserve(group_size[i]);\n        }\n       \
    \ for (int i = 0; i < n; i++) {\n            ret[root_buf[i]].push_back(i);\n\
    \        }\n        ret.erase(std::remove_if(\n                      ret.begin(),\
    \ ret.end(),\n                      [&](const std::vector<int>& v) { return v.empty();\
    \ }),\n                  ret.end());\n        return ret;\n    }\n};\n#line 6\
    \ \"test/library-checker/unionfind.test.cpp\"\n\nint main() {\n    int n, q;\n\
    \    cin >> n >> q;\n    UnionFind uf(n);\n    while (q--) {\n        int t, u,\
    \ v;\n        cin >> t >> u >> v;\n        if (t == 0) {\n            uf.unite(u,\
    \ v);\n        }\n        if (t == 1) {\n            cout << int(uf.find(u, v))\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include \"../../datastructure/unionfind.hpp\"\n\nint main() {\n    int n, q;\n\
    \    cin >> n >> q;\n    UnionFind uf(n);\n    while (q--) {\n        int t, u,\
    \ v;\n        cin >> t >> u >> v;\n        if (t == 0) {\n            uf.unite(u,\
    \ v);\n        }\n        if (t == 1) {\n            cout << int(uf.find(u, v))\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn:
  - datastructure/unionfind.hpp
  isVerificationFile: true
  path: test/library-checker/unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-09-01 17:53:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/unionfind.test.cpp
- /verify/test/library-checker/unionfind.test.cpp.html
title: test/library-checker/unionfind.test.cpp
---
