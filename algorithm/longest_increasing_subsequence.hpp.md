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
  bundledCode: "#line 2 \"algorithm/longest_increasing_subsequence.hpp\"\n#include\
    \ <vector>\ntemplate <typename T, class Compare>\nstd::vector<T> longest_increasing_subsequence(const\
    \ std::vector<T> &v,\n                                              Compare comp)\
    \ {\n    const int n = v.size();\n    std::vector<T> dp;\n    std::vector<int>\
    \ id(n);\n    for (int i = 0; i < n; i++) {\n        typename std::vector<T>::iterator\
    \ it =\n            std::lower_bound(dp.begin(), dp.end(), v[i], comp);\n    \
    \    id[i] = std::distance(dp.begin(), it);\n        if (it == dp.end()) {\n \
    \           dp.push_back(v[i]);\n        } else {\n            *it = v[i];\n \
    \       }\n    }\n    std::vector<T> lis(dp.size());\n    for (int i = n - 1,\
    \ j = lis.size() - 1; i >= 0; i--) {\n        if (id[i] == j) {\n            lis[j--]\
    \ = i;\n        }\n    }\n    return lis;\n}\ntemplate <typename T>\nstd::vector<T>\
    \ longest_increasing_subsequence(const std::vector<T> &v) {\n    return longest_increasing_subsequence(v,\
    \ std::less<T>());\n}\n"
  code: "#pragma once\n#include <vector>\ntemplate <typename T, class Compare>\nstd::vector<T>\
    \ longest_increasing_subsequence(const std::vector<T> &v,\n                  \
    \                            Compare comp) {\n    const int n = v.size();\n  \
    \  std::vector<T> dp;\n    std::vector<int> id(n);\n    for (int i = 0; i < n;\
    \ i++) {\n        typename std::vector<T>::iterator it =\n            std::lower_bound(dp.begin(),\
    \ dp.end(), v[i], comp);\n        id[i] = std::distance(dp.begin(), it);\n   \
    \     if (it == dp.end()) {\n            dp.push_back(v[i]);\n        } else {\n\
    \            *it = v[i];\n        }\n    }\n    std::vector<T> lis(dp.size());\n\
    \    for (int i = n - 1, j = lis.size() - 1; i >= 0; i--) {\n        if (id[i]\
    \ == j) {\n            lis[j--] = i;\n        }\n    }\n    return lis;\n}\ntemplate\
    \ <typename T>\nstd::vector<T> longest_increasing_subsequence(const std::vector<T>\
    \ &v) {\n    return longest_increasing_subsequence(v, std::less<T>());\n}"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2022-09-01 13:39:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/longest_increasing_subsequence.hpp
layout: document
title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217(LIS)"
---

## 最長増加部分列(LIS)
### 使い方
- がんばれ！