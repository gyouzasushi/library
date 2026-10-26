---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/cumulative_sum.hpp
    title: Cumulative Sum
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
    \n#line 4 \"datastructure/cumulative_sum.hpp\"\n\ntemplate <class T> struct cumulative_sum\
    \ {\n    cumulative_sum() = default;\n    explicit cumulative_sum(const std::vector<T>&\
    \ a) : n(a.size()), s(n + 1) {\n        for (int i = 0; i < n; i++) s[i + 1] =\
    \ s[i] + a[i];\n    }\n    T sum(int l, int r) const {\n        assert(0 <= l\
    \ && l <= r && r <= n);\n        return s[r] - s[l];\n    }\n\n  private:\n  \
    \  int n = 0;\n    std::vector<T> s;\n};\n#line 5 \"test/library-checker/static_range_sum.test.cpp\"\
    \nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<long long>\
    \ a(n);\n    for (int i = 0; i < n; i++) std::cin >> a[i];\n    cumulative_sum\
    \ cs(a);\n    while (q--) {\n        int l, r;\n        std::cin >> l >> r;\n\
    \        std::cout << cs.sum(l, r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <bits/stdc++.h>\n\n#include \"datastructure/cumulative_sum.hpp\"\nint main()\
    \ {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<long long> a(n);\n\
    \    for (int i = 0; i < n; i++) std::cin >> a[i];\n    cumulative_sum cs(a);\n\
    \    while (q--) {\n        int l, r;\n        std::cin >> l >> r;\n        std::cout\
    \ << cs.sum(l, r) << '\\n';\n    }\n}"
  dependsOn:
  - datastructure/cumulative_sum.hpp
  isVerificationFile: true
  path: test/library-checker/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 22:21:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/static_range_sum.test.cpp
- /verify/test/library-checker/static_range_sum.test.cpp.html
title: test/library-checker/static_range_sum.test.cpp
---
