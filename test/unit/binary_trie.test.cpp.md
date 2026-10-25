---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/binary_trie.hpp
    title: Binary Trie
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
  bundledCode: "#line 1 \"test/unit/binary_trie.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\n#line 2 \"datastructure/binary_trie.hpp\"\n#include <array>\n\
    #line 5 \"datastructure/binary_trie.hpp\"\ntemplate <int log = 30> struct binary_trie\
    \ {\n    static_assert(1 <= log && log <= 62);\n\npublic:\n    binary_trie() :\
    \ ch(1, {-1, -1}), cnt(1, 0) {\n    }\n    int size() const {\n        return\
    \ cnt[0];\n    }\n    void insert(long long x, int k = 1) {\n        assert(0\
    \ <= x && x < (1LL << log));\n        assert(k >= 0);\n        int v = 0;\n  \
    \      cnt[v] += k;\n        for (int d = log - 1; d >= 0; d--) {\n          \
    \  int b = x >> d & 1;\n            if (ch[v][b] == -1) {\n                ch[v][b]\
    \ = int(ch.size());\n                ch.push_back({-1, -1});\n               \
    \ cnt.push_back(0);\n            }\n            v = ch[v][b];\n            cnt[v]\
    \ += k;\n        }\n    }\n    void erase(long long x, int k = 1) {\n        assert(0\
    \ <= x && x < (1LL << log));\n        assert(0 <= k && k <= count(x));\n     \
    \   int v = 0;\n        cnt[v] -= k;\n        for (int d = log - 1; d >= 0; d--)\
    \ {\n            v = ch[v][x >> d & 1];\n            cnt[v] -= k;\n        }\n\
    \    }\n    int count(long long x) const {\n        assert(0 <= x && x < (1LL\
    \ << log));\n        int v = 0;\n        for (int d = log - 1; d >= 0; d--) {\n\
    \            v = ch[v][x >> d & 1];\n            if (v == -1) return 0;\n    \
    \    }\n        return cnt[v];\n    }\n    // #{ a : (a ^ xor_val) < upper }\n\
    \    int count_less(long long upper, long long xor_val = 0) const {\n        assert(0\
    \ <= xor_val && xor_val < (1LL << log));\n        if (upper <= 0) return 0;\n\
    \        if (upper >= (1LL << log)) return size();\n        int v = 0, res = 0;\n\
    \        for (int d = log - 1; d >= 0; d--) {\n            int b = (upper >> d\
    \ & 1), f = (xor_val >> d & 1);\n            if (b) {\n                int c =\
    \ ch[v][f];\n                if (c != -1) res += cnt[c];\n            }\n    \
    \        v = ch[v][b ^ f];\n            if (v == -1) break;\n        }\n     \
    \   return res;\n    }\n    // k-th smallest (0-indexed) of { a ^ xor_val }\n\
    \    long long kth_smallest(int k, long long xor_val = 0) const {\n        assert(0\
    \ <= k && k < size());\n        assert(0 <= xor_val && xor_val < (1LL << log));\n\
    \        int v = 0;\n        long long res = 0;\n        for (int d = log - 1;\
    \ d >= 0; d--) {\n            int f = xor_val >> d & 1;\n            int c = ch[v][f];\n\
    \            int c_cnt = c == -1 ? 0 : cnt[c];\n            if (k < c_cnt) {\n\
    \                v = c;\n            } else {\n                k -= c_cnt;\n \
    \               v = ch[v][f ^ 1];\n                res |= 1LL << d;\n        \
    \    }\n        }\n        return res;\n    }\n    long long kth_largest(int k,\
    \ long long xor_val = 0) const {\n        assert(0 <= k && k < size());\n    \
    \    return kth_smallest(size() - 1 - k, xor_val);\n    }\n    long long min(long\
    \ long xor_val = 0) const {\n        return kth_smallest(0, xor_val);\n    }\n\
    \    long long max(long long xor_val = 0) const {\n        return kth_smallest(size()\
    \ - 1, xor_val);\n    }\n\nprivate:\n    std::vector<std::array<int, 2>> ch;\n\
    \    std::vector<int> cnt;\n};\n#line 9 \"test/unit/binary_trie.test.cpp\"\n\n\
    template <int log> void run(std::mt19937_64& rng, int iters) {\n    const long\
    \ long lim = 1LL << log;\n    for (int it = 0; it < iters; it++) {\n        binary_trie<log>\
    \ t;\n        std::vector<long long> ms;  // multiset\n        int range = log\
    \ <= 4 ? int(lim) : 50;\n        for (int q = 0; q < 200; q++) {\n           \
    \ long long x = log <= 4 ? (long long)(rng() % lim) : (rng() % 3 ? (long long)(rng()\
    \ % range) : (long long)(rng() % lim));\n            int op = rng() % 4;\n   \
    \         if (op == 0) {\n                int k = rng() % 3;\n               \
    \ t.insert(x, k);\n                for (int i = 0; i < k; i++) ms.push_back(x);\n\
    \            } else if (op == 1) {\n                int c = int(std::count(ms.begin(),\
    \ ms.end(), x));\n                assert(t.count(x) == c);\n                if\
    \ (c > 0) {\n                    int k = rng() % (c + 1);\n                  \
    \  t.erase(x, k);\n                    for (int i = 0; i < k; i++) ms.erase(std::find(ms.begin(),\
    \ ms.end(), x));\n                }\n            }\n            assert(t.size()\
    \ == int(ms.size()));\n            long long v = log <= 4 ? (long long)(rng()\
    \ % lim) : (rng() % 2 ? (long long)(rng() % range) : (long long)(rng() % lim));\n\
    \            std::vector<long long> xs;\n            for (long long a : ms) xs.push_back(a\
    \ ^ v);\n            std::sort(xs.begin(), xs.end());\n            long long upper\
    \ = log <= 4 ? (long long)(rng() % (lim + 2)) - 1 : (long long)(rng() % (range\
    \ + 2)) - 1;\n            assert(t.count_less(upper, v) == int(std::lower_bound(xs.begin(),\
    \ xs.end(), upper) - xs.begin()));\n            assert(t.count_less(lim, v) ==\
    \ int(xs.size()));\n            assert(t.count_less(lim + 5, v) == int(xs.size()));\n\
    \            assert(t.count_less(0, v) == 0);\n            if (!xs.empty()) {\n\
    \                int k = rng() % xs.size();\n                assert(t.kth_smallest(k,\
    \ v) == xs[k]);\n                assert(t.kth_largest(k, v) == xs[xs.size() -\
    \ 1 - k]);\n                assert(t.min(v) == xs.front());\n                assert(t.max(v)\
    \ == xs.back());\n                assert(t.min() == *std::min_element(ms.begin(),\
    \ ms.end()));\n            }\n        }\n    }\n}\n\nint main() {\n    std::mt19937_64\
    \ rng(31);\n    run<3>(rng, 200);\n    run<30>(rng, 100);\n    run<62>(rng, 30);\n\
    \    std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\n#include \"datastructure/binary_trie.hpp\"\n\ntemplate <int\
    \ log> void run(std::mt19937_64& rng, int iters) {\n    const long long lim =\
    \ 1LL << log;\n    for (int it = 0; it < iters; it++) {\n        binary_trie<log>\
    \ t;\n        std::vector<long long> ms;  // multiset\n        int range = log\
    \ <= 4 ? int(lim) : 50;\n        for (int q = 0; q < 200; q++) {\n           \
    \ long long x = log <= 4 ? (long long)(rng() % lim) : (rng() % 3 ? (long long)(rng()\
    \ % range) : (long long)(rng() % lim));\n            int op = rng() % 4;\n   \
    \         if (op == 0) {\n                int k = rng() % 3;\n               \
    \ t.insert(x, k);\n                for (int i = 0; i < k; i++) ms.push_back(x);\n\
    \            } else if (op == 1) {\n                int c = int(std::count(ms.begin(),\
    \ ms.end(), x));\n                assert(t.count(x) == c);\n                if\
    \ (c > 0) {\n                    int k = rng() % (c + 1);\n                  \
    \  t.erase(x, k);\n                    for (int i = 0; i < k; i++) ms.erase(std::find(ms.begin(),\
    \ ms.end(), x));\n                }\n            }\n            assert(t.size()\
    \ == int(ms.size()));\n            long long v = log <= 4 ? (long long)(rng()\
    \ % lim) : (rng() % 2 ? (long long)(rng() % range) : (long long)(rng() % lim));\n\
    \            std::vector<long long> xs;\n            for (long long a : ms) xs.push_back(a\
    \ ^ v);\n            std::sort(xs.begin(), xs.end());\n            long long upper\
    \ = log <= 4 ? (long long)(rng() % (lim + 2)) - 1 : (long long)(rng() % (range\
    \ + 2)) - 1;\n            assert(t.count_less(upper, v) == int(std::lower_bound(xs.begin(),\
    \ xs.end(), upper) - xs.begin()));\n            assert(t.count_less(lim, v) ==\
    \ int(xs.size()));\n            assert(t.count_less(lim + 5, v) == int(xs.size()));\n\
    \            assert(t.count_less(0, v) == 0);\n            if (!xs.empty()) {\n\
    \                int k = rng() % xs.size();\n                assert(t.kth_smallest(k,\
    \ v) == xs[k]);\n                assert(t.kth_largest(k, v) == xs[xs.size() -\
    \ 1 - k]);\n                assert(t.min(v) == xs.front());\n                assert(t.max(v)\
    \ == xs.back());\n                assert(t.min() == *std::min_element(ms.begin(),\
    \ ms.end()));\n            }\n        }\n    }\n}\n\nint main() {\n    std::mt19937_64\
    \ rng(31);\n    run<3>(rng, 200);\n    run<30>(rng, 100);\n    run<62>(rng, 30);\n\
    \    std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - datastructure/binary_trie.hpp
  isVerificationFile: true
  path: test/unit/binary_trie.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 02:09:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/binary_trie.test.cpp
layout: document
redirect_from:
- /verify/test/unit/binary_trie.test.cpp
- /verify/test/unit/binary_trie.test.cpp.html
title: test/unit/binary_trie.test.cpp
---
