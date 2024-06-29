---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1160.test.cpp
    title: test/aoj/1160.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/manhattanmst.test.cpp
    title: test/library-checker/manhattanmst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/unionfind.test.cpp
    title: test/library-checker/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/unionfind.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\nstruct unionfind {\n    int n;\n    std::vector<int> data;\n    unionfind(int\
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
  code: "#pragma once\n#include <algorithm>\n#include <vector>\nstruct unionfind {\n\
    \    int n;\n    std::vector<int> data;\n    unionfind(int _n) : n(_n), data(_n,\
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
  path: datastructure/unionfind.hpp
  requiredBy: []
  timestamp: '2023-03-05 19:05:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1160.test.cpp
  - test/library-checker/manhattanmst.test.cpp
  - test/library-checker/unionfind.test.cpp
documentation_of: datastructure/unionfind.hpp
layout: document
redirect_from:
- /library/datastructure/unionfind.hpp
- /library/datastructure/unionfind.hpp.html
title: datastructure/unionfind.hpp
---
