---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/cumulative_sum.hpp
    title: "\u7D2F\u7A4D\u548C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/library-checker/static_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include <bits/stdc++.h>\n\
    \n#line 3 \"datastructure/cumulative_sum.hpp\"\ntemplate <typename T>\nstruct\
    \ CumulativeSum {\n    int n;\n    std::vector<T> cumsum;\n    CumulativeSum()\
    \ {\n    }\n    CumulativeSum(std::vector<T>& d) : n(d.size()), cumsum(n + 1)\
    \ {\n        for (int i = 0; i < n; i++) {\n            cumsum[i + 1] = cumsum[i]\
    \ + d[i];\n        }\n    }\n    T sum(int l, int r) {\n        // 0-indexed\n\
    \        // [l, r)\n        return cumsum[r] - cumsum[l];\n    }\n};\n#line 5\
    \ \"test/library-checker/static_range_sum.test.cpp\"\nusing namespace std;\n\n\
    int main() {\n    int n, q;\n    cin >> n >> q;\n    vector<long long> a(n);\n\
    \    for (int i = 0; i < n; i++) cin >> a[i];\n    CumulativeSum cs(a);\n    while\
    \ (q--) {\n        int l, r;\n        cin >> l >> r;\n        cout << cs.sum(l,\
    \ r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <bits/stdc++.h>\n\n#include \"../../datastructure/cumulative_sum.hpp\"\nusing\
    \ namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<long\
    \ long> a(n);\n    for (int i = 0; i < n; i++) cin >> a[i];\n    CumulativeSum\
    \ cs(a);\n    while (q--) {\n        int l, r;\n        cin >> l >> r;\n     \
    \   cout << cs.sum(l, r) << '\\n';\n    }\n}"
  dependsOn:
  - datastructure/cumulative_sum.hpp
  isVerificationFile: true
  path: test/library-checker/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-09-02 13:25:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/static_range_sum.test.cpp
- /verify/test/library-checker/static_range_sum.test.cpp.html
title: test/library-checker/static_range_sum.test.cpp
---
