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
  bundledCode: "#line 2 \"datastructure/cumulative_sum.hpp\"\ntemplate <typename T>\n\
    struct CumulativeSum {\n    int n;\n    vector<T> cumsum;\n    CumulativeSum()\
    \ {\n    }\n    CumulativeSum(vector<T>& d) : n(d.size()), cumsum(n + 1) {\n \
    \       for (int i = 0; i < n; i++) {\n            cumsum[i + 1] = cumsum[i] +\
    \ d[i];\n        }\n    }\n    T sum(int l, int r) {\n        // 0-indexed\n \
    \       // [l, r)\n        return cumsum[r] - cumsum[l];\n    }\n};\n"
  code: "#pragma once\ntemplate <typename T>\nstruct CumulativeSum {\n    int n;\n\
    \    vector<T> cumsum;\n    CumulativeSum() {\n    }\n    CumulativeSum(vector<T>&\
    \ d) : n(d.size()), cumsum(n + 1) {\n        for (int i = 0; i < n; i++) {\n \
    \           cumsum[i + 1] = cumsum[i] + d[i];\n        }\n    }\n    T sum(int\
    \ l, int r) {\n        // 0-indexed\n        // [l, r)\n        return cumsum[r]\
    \ - cumsum[l];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/cumulative_sum.hpp
  requiredBy: []
  timestamp: '2022-09-01 13:39:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/cumulative_sum.hpp
layout: document
redirect_from:
- /library/datastructure/cumulative_sum.hpp
- /library/datastructure/cumulative_sum.hpp.html
title: datastructure/cumulative_sum.hpp
---
