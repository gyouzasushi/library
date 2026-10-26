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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unit/longest_increasing_subsequence.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include <iostream>\n\
    #include <random>\n#include <string>\n#include <vector>\n\n#line 6 \"algorithm/longest_increasing_subsequence.hpp\"\
    \n\ntemplate <class T, class Compare = std::less<T>>\nstruct longest_increasing_subsequence\
    \ {\n    explicit longest_increasing_subsequence(const std::vector<T>& a,\n  \
    \                                          Compare comp = {})\n        : n(a.size()),\
    \ pos(n) {\n        std::vector<T> dp;\n        for (int i = 0; i < n; i++) {\n\
    \            auto it = std::lower_bound(dp.begin(), dp.end(), a[i], comp);\n \
    \           pos[i] = it - dp.begin();\n            if (it == dp.end()) {\n   \
    \             dp.push_back(a[i]);\n            } else {\n                *it =\
    \ a[i];\n            }\n        }\n        len = dp.size();\n        cand.resize(len);\n\
    \        for (int i = n - 1; i >= 0; i--) {\n            int j = pos[i];\n   \
    \         if (j == len - 1 ||\n                (!cand[j + 1].empty() && comp(a[i],\
    \ a[cand[j + 1].back()]))) {\n                cand[j].push_back(i);\n        \
    \    } else {\n                pos[i] = -1;\n            }\n        }\n      \
    \  for (auto& c : cand) std::reverse(c.begin(), c.end());\n    }\n    int length()\
    \ const { return len; }\n    int position(int i) const {\n        assert(0 <=\
    \ i && i < n);\n        return pos[i];\n    }\n    const std::vector<int>& candidates(int\
    \ j) const {\n        assert(0 <= j && j < len);\n        return cand[j];\n  \
    \  }\n    std::vector<int> indices() const {\n        std::vector<int> res(len);\n\
    \        for (int j = 0; j < len; j++) res[j] = cand[j].front();\n        return\
    \ res;\n    }\n\n  private:\n    int n, len;\n    std::vector<int> pos;\n    std::vector<std::vector<int>>\
    \ cand;\n};\n#line 11 \"test/unit/longest_increasing_subsequence.test.cpp\"\n\n\
    template <class Compare> void check(const std::vector<int>& a, Compare comp) {\n\
    \    int n = a.size();\n    // brute force: enumerate all subsequences\n    std::vector<std::vector<int>>\
    \ all;\n    int best = 0;\n    for (int mask = 0; mask < (1 << n); mask++) {\n\
    \        std::vector<int> idx;\n        for (int i = 0; i < n; i++)\n        \
    \    if (mask >> i & 1) idx.push_back(i);\n        bool ok = true;\n        for\
    \ (int k = 0; k + 1 < (int)idx.size(); k++)\n            if (!comp(a[idx[k]],\
    \ a[idx[k + 1]])) ok = false;\n        if (!ok) continue;\n        if ((int)idx.size()\
    \ > best) best = idx.size(), all.clear();\n        if ((int)idx.size() == best)\
    \ all.push_back(idx);\n    }\n    longest_increasing_subsequence lis(a, comp);\n\
    \    assert(lis.length() == best);\n    std::vector<int> pos(n, -1);\n    std::vector<std::vector<int>>\
    \ cand(best);\n    for (auto& idx : all)\n        for (int j = 0; j < best; j++)\
    \ {\n            assert(pos[idx[j]] == -1 || pos[idx[j]] == j);\n            pos[idx[j]]\
    \ = j;\n            cand[j].push_back(idx[j]);\n        }\n    for (int i = 0;\
    \ i < n; i++) assert(lis.position(i) == pos[i]);\n    for (int j = 0; j < best;\
    \ j++) {\n        std::sort(cand[j].begin(), cand[j].end());\n        cand[j].erase(std::unique(cand[j].begin(),\
    \ cand[j].end()), cand[j].end());\n        assert(lis.candidates(j) == cand[j]);\n\
    \        for (int k = 0; k + 1 < (int)cand[j].size(); k++)\n            assert(!comp(a[cand[j][k]],\
    \ a[cand[j][k + 1]]));  // values non-increasing\n    }\n    std::sort(all.begin(),\
    \ all.end());\n    if (best > 0) assert(lis.indices() == all.front());\n    else\
    \ assert(lis.indices().empty());\n}\n\nint main() {\n    std::mt19937 rng(777);\n\
    \    for (int it = 0; it < 400; it++) {\n        int n = rng() % 11;\n       \
    \ int v = 1 + rng() % 6;\n        std::vector<int> a(n);\n        for (auto& x\
    \ : a) x = rng() % v;\n        check(a, std::less<int>());\n        check(a, std::less_equal<int>());\n\
    \    }\n    // blog example (2, 1, 4, 5, 3): index 4 is useless\n    {\n     \
    \   std::vector<int> a = {2, 1, 4, 5, 3};\n        longest_increasing_subsequence\
    \ lis(a);\n        assert(lis.length() == 3);\n        assert((lis.indices() ==\
    \ std::vector<int>{0, 2, 3}));\n        assert(lis.position(4) == -1);\n     \
    \   assert((lis.candidates(0) == std::vector<int>{0, 1}));\n    }\n    // strings\n\
    \    {\n        std::vector<std::string> a = {\"b\", \"a\", \"c\"};\n        longest_increasing_subsequence\
    \ lis(a);\n        assert(lis.length() == 2);\n    }\n    // large\n    {\n  \
    \      int n = 200000;\n        std::vector<int> a(n);\n        for (auto& x :\
    \ a) x = rng();\n        longest_increasing_subsequence lis(a);\n        assert(lis.length()\
    \ > 0);\n    }\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include <iostream>\n\
    #include <random>\n#include <string>\n#include <vector>\n\n#include \"algorithm/longest_increasing_subsequence.hpp\"\
    \n\ntemplate <class Compare> void check(const std::vector<int>& a, Compare comp)\
    \ {\n    int n = a.size();\n    // brute force: enumerate all subsequences\n \
    \   std::vector<std::vector<int>> all;\n    int best = 0;\n    for (int mask =\
    \ 0; mask < (1 << n); mask++) {\n        std::vector<int> idx;\n        for (int\
    \ i = 0; i < n; i++)\n            if (mask >> i & 1) idx.push_back(i);\n     \
    \   bool ok = true;\n        for (int k = 0; k + 1 < (int)idx.size(); k++)\n \
    \           if (!comp(a[idx[k]], a[idx[k + 1]])) ok = false;\n        if (!ok)\
    \ continue;\n        if ((int)idx.size() > best) best = idx.size(), all.clear();\n\
    \        if ((int)idx.size() == best) all.push_back(idx);\n    }\n    longest_increasing_subsequence\
    \ lis(a, comp);\n    assert(lis.length() == best);\n    std::vector<int> pos(n,\
    \ -1);\n    std::vector<std::vector<int>> cand(best);\n    for (auto& idx : all)\n\
    \        for (int j = 0; j < best; j++) {\n            assert(pos[idx[j]] == -1\
    \ || pos[idx[j]] == j);\n            pos[idx[j]] = j;\n            cand[j].push_back(idx[j]);\n\
    \        }\n    for (int i = 0; i < n; i++) assert(lis.position(i) == pos[i]);\n\
    \    for (int j = 0; j < best; j++) {\n        std::sort(cand[j].begin(), cand[j].end());\n\
    \        cand[j].erase(std::unique(cand[j].begin(), cand[j].end()), cand[j].end());\n\
    \        assert(lis.candidates(j) == cand[j]);\n        for (int k = 0; k + 1\
    \ < (int)cand[j].size(); k++)\n            assert(!comp(a[cand[j][k]], a[cand[j][k\
    \ + 1]]));  // values non-increasing\n    }\n    std::sort(all.begin(), all.end());\n\
    \    if (best > 0) assert(lis.indices() == all.front());\n    else assert(lis.indices().empty());\n\
    }\n\nint main() {\n    std::mt19937 rng(777);\n    for (int it = 0; it < 400;\
    \ it++) {\n        int n = rng() % 11;\n        int v = 1 + rng() % 6;\n     \
    \   std::vector<int> a(n);\n        for (auto& x : a) x = rng() % v;\n       \
    \ check(a, std::less<int>());\n        check(a, std::less_equal<int>());\n   \
    \ }\n    // blog example (2, 1, 4, 5, 3): index 4 is useless\n    {\n        std::vector<int>\
    \ a = {2, 1, 4, 5, 3};\n        longest_increasing_subsequence lis(a);\n     \
    \   assert(lis.length() == 3);\n        assert((lis.indices() == std::vector<int>{0,\
    \ 2, 3}));\n        assert(lis.position(4) == -1);\n        assert((lis.candidates(0)\
    \ == std::vector<int>{0, 1}));\n    }\n    // strings\n    {\n        std::vector<std::string>\
    \ a = {\"b\", \"a\", \"c\"};\n        longest_increasing_subsequence lis(a);\n\
    \        assert(lis.length() == 2);\n    }\n    // large\n    {\n        int n\
    \ = 200000;\n        std::vector<int> a(n);\n        for (auto& x : a) x = rng();\n\
    \        longest_increasing_subsequence lis(a);\n        assert(lis.length() >\
    \ 0);\n    }\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - algorithm/longest_increasing_subsequence.hpp
  isVerificationFile: true
  path: test/unit/longest_increasing_subsequence.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 21:56:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/longest_increasing_subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/unit/longest_increasing_subsequence.test.cpp
- /verify/test/unit/longest_increasing_subsequence.test.cpp.html
title: test/unit/longest_increasing_subsequence.test.cpp
---
