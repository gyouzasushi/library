---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algorithm/longest_increasing_subsequence.hpp
    title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217(LIS)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D
  bundledCode: "#line 1 \"test/aoj/DPL_1_D.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D\"\n#include\
    \ <bits/stdc++.h>\n\n#line 3 \"algorithm/longest_increasing_subsequence.hpp\"\n\
    template <typename T, class Compare>\nstd::vector<T> longest_increasing_subsequence(const\
    \ std::vector<T> &a,\n                                              Compare comp)\
    \ {\n    const int n = a.size();\n    std::vector<T> dp;\n    std::vector<int>\
    \ id(n);\n    for (int i = 0; i < n; i++) {\n        typename std::vector<T>::iterator\
    \ it =\n            std::lower_bound(dp.begin(), dp.end(), a[i], comp);\n    \
    \    id[i] = std::distance(dp.begin(), it);\n        if (it == dp.end()) {\n \
    \           dp.push_back(a[i]);\n        } else {\n            *it = a[i];\n \
    \       }\n    }\n    std::vector<T> lis(dp.size());\n    for (int i = n - 1,\
    \ j = lis.size() - 1; i >= 0; i--) {\n        if (id[i] == j) {\n            lis[j--]\
    \ = i;\n        }\n    }\n    return lis;\n}\ntemplate <typename T>\nstd::vector<T>\
    \ longest_increasing_subsequence(const std::vector<T> &a) {\n    return longest_increasing_subsequence(a,\
    \ std::less<T>());\n}\n#line 6 \"test/aoj/DPL_1_D.test.cpp\"\nusing namespace\
    \ std;\nint main() {\n    int n;\n    cin >> n;\n    vector<int> a(n);\n    for\
    \ (int i = 0; i < n; i++) cin >> a[i];\n    int ans = longest_increasing_subsequence(a).size();\n\
    \    cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D\"\
    \n#include <bits/stdc++.h>\n\n#include \"../../algorithm/longest_increasing_subsequence.hpp\"\
    \nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    vector<int>\
    \ a(n);\n    for (int i = 0; i < n; i++) cin >> a[i];\n    int ans = longest_increasing_subsequence(a).size();\n\
    \    cout << ans << '\\n';\n}"
  dependsOn:
  - algorithm/longest_increasing_subsequence.hpp
  isVerificationFile: true
  path: test/aoj/DPL_1_D.test.cpp
  requiredBy: []
  timestamp: '2022-09-02 13:25:33+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DPL_1_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_1_D.test.cpp
- /verify/test/aoj/DPL_1_D.test.cpp.html
title: test/aoj/DPL_1_D.test.cpp
---
