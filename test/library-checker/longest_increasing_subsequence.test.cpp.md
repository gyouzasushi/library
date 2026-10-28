---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/longest_increasing_subsequence.hpp
    title: Longest Increasing Subsequence
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"test/library-checker/longest_increasing_subsequence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#include <iostream>\n#include <vector>\n\n#line 2 \"algorithm/longest_increasing_subsequence.hpp\"\
    \n#include <algorithm>\n#include <cassert>\n#include <functional>\n#line 6 \"\
    algorithm/longest_increasing_subsequence.hpp\"\n\ntemplate <class T, class Compare\
    \ = std::less<T>>\nstruct longest_increasing_subsequence {\n    explicit longest_increasing_subsequence(const\
    \ std::vector<T>& a,\n                                            Compare comp\
    \ = {})\n        : n(a.size()), pos(n) {\n        std::vector<T> dp;\n       \
    \ for (int i = 0; i < n; i++) {\n            auto it = std::ranges::lower_bound(dp,\
    \ a[i], comp);\n            pos[i] = it - dp.begin();\n            if (it == dp.end())\
    \ {\n                dp.push_back(a[i]);\n            } else {\n             \
    \   *it = a[i];\n            }\n        }\n        len = dp.size();\n        cand.resize(len);\n\
    \        for (int i = n - 1; i >= 0; i--) {\n            int j = pos[i];\n   \
    \         if (j == len - 1 ||\n                (!cand[j + 1].empty() && comp(a[i],\
    \ a[cand[j + 1].back()]))) {\n                cand[j].push_back(i);\n        \
    \    } else {\n                pos[i] = -1;\n            }\n        }\n      \
    \  for (auto& c : cand) std::ranges::reverse(c);\n    }\n    int length() const\
    \ { return len; }\n    int position(int i) const {\n        assert(0 <= i && i\
    \ < n);\n        return pos[i];\n    }\n    const std::vector<int>& candidates(int\
    \ j) const {\n        assert(0 <= j && j < len);\n        return cand[j];\n  \
    \  }\n    std::vector<int> indices() const {\n        std::vector<int> res(len);\n\
    \        for (int j = 0; j < len; j++) res[j] = cand[j].front();\n        return\
    \ res;\n    }\n\n  private:\n    int n, len;\n    std::vector<int> pos;\n    std::vector<std::vector<int>>\
    \ cand;\n};\n#line 6 \"test/library-checker/longest_increasing_subsequence.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<int> a(n);\n\
    \    for (auto& x : a) std::cin >> x;\n    longest_increasing_subsequence lis(a);\n\
    \    std::cout << lis.length() << '\\n';\n    for (int i : lis.indices()) std::cout\
    \ << i << ' ';\n    std::cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#include <iostream>\n#include <vector>\n\n#include \"algorithm/longest_increasing_subsequence.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<int> a(n);\n\
    \    for (auto& x : a) std::cin >> x;\n    longest_increasing_subsequence lis(a);\n\
    \    std::cout << lis.length() << '\\n';\n    for (int i : lis.indices()) std::cout\
    \ << i << ' ';\n    std::cout << '\\n';\n}\n"
  dependsOn:
  - algorithm/longest_increasing_subsequence.hpp
  isVerificationFile: true
  path: test/library-checker/longest_increasing_subsequence.test.cpp
  requiredBy: []
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/longest_increasing_subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/longest_increasing_subsequence.test.cpp
- /verify/test/library-checker/longest_increasing_subsequence.test.cpp.html
title: test/library-checker/longest_increasing_subsequence.test.cpp
---
