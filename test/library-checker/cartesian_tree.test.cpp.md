---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/cartesian_tree.hpp
    title: Cartesian Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"test/library-checker/cartesian_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#line 2 \"datastructure/cartesian_tree.hpp\"\
    \n#include <numeric>\n#include <optional>\n#include <stack>\n#include <vector>\n\
    template <typename T>\nstd::vector<int> CartesianTree(std::vector<T> &a) {\n \
    \   int n = int(a.size());\n    std::vector<int> p(n);\n    std::iota(p.begin(),\
    \ p.end(), 0);\n    std::stack<int> st;\n    for (int i = 0; i < n; i++) {\n \
    \       std::optional<int> pre = std::nullopt;\n        while (!st.empty() &&\
    \ a[i] < a[st.top()]) {\n            pre = st.top();\n            st.pop();\n\
    \        }\n        if (pre) p[pre.value()] = i;\n        if (!st.empty()) p[i]\
    \ = st.top();\n        st.push(i);\n    }\n    return p;\n}\n#line 4 \"test/library-checker/cartesian_tree.test.cpp\"\
    \n\n#include <iostream>\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<int>\
    \ a(n);\n    for (int i = 0; i < n; i++) std::cin >> a[i];\n    std::vector<int>\
    \ p = CartesianTree(a);\n    for (int i = 0; i < n; i++) std::cout << p[i] <<\
    \ \" \\n\"[i == n - 1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ \"../../datastructure/cartesian_tree.hpp\"\n\n#include <iostream>\nint main()\
    \ {\n    int n;\n    std::cin >> n;\n    std::vector<int> a(n);\n    for (int\
    \ i = 0; i < n; i++) std::cin >> a[i];\n    std::vector<int> p = CartesianTree(a);\n\
    \    for (int i = 0; i < n; i++) std::cout << p[i] << \" \\n\"[i == n - 1];\n}"
  dependsOn:
  - datastructure/cartesian_tree.hpp
  isVerificationFile: true
  path: test/library-checker/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2022-12-18 15:12:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/cartesian_tree.test.cpp
- /verify/test/library-checker/cartesian_tree.test.cpp.html
title: test/library-checker/cartesian_tree.test.cpp
---
