---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/cartesian_tree.test.cpp
    title: test/library-checker/cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/cartesian_tree.hpp\"\n#include <numeric>\n\
    #include <optional>\n#include <stack>\n#include <vector>\ntemplate <typename T>\n\
    std::vector<int> cartesian_tree(std::vector<T> &a) {\n    int n = int(a.size());\n\
    \    std::vector<int> p(n);\n    std::iota(p.begin(), p.end(), 0);\n    std::stack<int>\
    \ st;\n    for (int i = 0; i < n; i++) {\n        std::optional<int> pre = std::nullopt;\n\
    \        while (!st.empty() && a[i] < a[st.top()]) {\n            pre = st.top();\n\
    \            st.pop();\n        }\n        if (pre) p[pre.value()] = i;\n    \
    \    if (!st.empty()) p[i] = st.top();\n        st.push(i);\n    }\n    return\
    \ p;\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <optional>\n#include <stack>\n\
    #include <vector>\ntemplate <typename T>\nstd::vector<int> cartesian_tree(std::vector<T>\
    \ &a) {\n    int n = int(a.size());\n    std::vector<int> p(n);\n    std::iota(p.begin(),\
    \ p.end(), 0);\n    std::stack<int> st;\n    for (int i = 0; i < n; i++) {\n \
    \       std::optional<int> pre = std::nullopt;\n        while (!st.empty() &&\
    \ a[i] < a[st.top()]) {\n            pre = st.top();\n            st.pop();\n\
    \        }\n        if (pre) p[pre.value()] = i;\n        if (!st.empty()) p[i]\
    \ = st.top();\n        st.push(i);\n    }\n    return p;\n}"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2023-03-05 19:05:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/cartesian_tree.test.cpp
documentation_of: datastructure/cartesian_tree.hpp
layout: document
title: Cartesian Tree
---
  
### 使い方
- `CartesianTree(a)`: 数列 $\mathrm a$ から誘導される Cartesian Tree を求める。`p[i]`  は頂点 `i` の親を表す。ただし、根である頂点 `r` については `p[r] = r`。