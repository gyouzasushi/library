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
  bundledCode: "#line 2 \"datastructure/union_find.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\nstruct UnionFind {\n    int n;\n    std::vector<int> data;\n    UnionFind(int\
    \ _n) : n(_n), data(_n, -1) {\n    }\n    int root(int x) {\n        return (data[x]\
    \ < 0) ? x : data[x] = root(data[x]);\n    }\n    bool unite(int x, int y) {\n\
    \        x = root(x);\n        y = root(y);\n        if (x != y) {\n         \
    \   if (data[y] < data[x]) std::swap(x, y);\n            data[x] += data[y];\n\
    \            data[y] = x;\n        }\n        return x != y;\n    }\n    bool\
    \ find(int x, int y) {\n        return root(x) == root(y);\n    }\n    int size(int\
    \ x) {\n        return -data[root(x)];\n    }\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> root_buf(n), group_size(n);\n        for\
    \ (int i = 0; i < n; i++) {\n            root_buf[i] = root(i);\n            group_size[root_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> ret(n);\n        for (int i\
    \ = 0; i < n; i++) {\n            ret[i].reserve(group_size[i]);\n        }\n\
    \        for (int i = 0; i < n; i++) {\n            ret[root_buf[i]].push_back(i);\n\
    \        }\n        ret.erase(std::remove_if(\n                      ret.begin(),\
    \ ret.end(),\n                      [&](const std::vector<int>& v) { return v.empty();\
    \ }),\n                  ret.end());\n        return ret;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\nstruct UnionFind {\n\
    \    int n;\n    std::vector<int> data;\n    UnionFind(int _n) : n(_n), data(_n,\
    \ -1) {\n    }\n    int root(int x) {\n        return (data[x] < 0) ? x : data[x]\
    \ = root(data[x]);\n    }\n    bool unite(int x, int y) {\n        x = root(x);\n\
    \        y = root(y);\n        if (x != y) {\n            if (data[y] < data[x])\
    \ std::swap(x, y);\n            data[x] += data[y];\n            data[y] = x;\n\
    \        }\n        return x != y;\n    }\n    bool find(int x, int y) {\n   \
    \     return root(x) == root(y);\n    }\n    int size(int x) {\n        return\
    \ -data[root(x)];\n    }\n    std::vector<std::vector<int>> groups() {\n     \
    \   std::vector<int> root_buf(n), group_size(n);\n        for (int i = 0; i <\
    \ n; i++) {\n            root_buf[i] = root(i);\n            group_size[root_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> ret(n);\n        for (int i\
    \ = 0; i < n; i++) {\n            ret[i].reserve(group_size[i]);\n        }\n\
    \        for (int i = 0; i < n; i++) {\n            ret[root_buf[i]].push_back(i);\n\
    \        }\n        ret.erase(std::remove_if(\n                      ret.begin(),\
    \ ret.end(),\n                      [&](const std::vector<int>& v) { return v.empty();\
    \ }),\n                  ret.end());\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/union_find.hpp
  requiredBy: []
  timestamp: '2022-09-01 13:39:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/union_find.hpp
layout: document
redirect_from:
- /library/datastructure/union_find.hpp
- /library/datastructure/union_find.hpp.html
title: datastructure/union_find.hpp
---
