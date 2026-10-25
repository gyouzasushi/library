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
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/library-checker/set_xor_min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/set_xor_min\"\n#include <iostream>\n\n#line\
    \ 2 \"datastructure/binary_trie.hpp\"\n#include <array>\n#include <cassert>\n\
    #include <vector>\ntemplate <int log = 30> struct binary_trie {\n    static_assert(1\
    \ <= log && log <= 62);\n\npublic:\n    binary_trie() : ch(1, {-1, -1}), cnt(1,\
    \ 0) {\n    }\n    int size() const {\n        return cnt[0];\n    }\n    void\
    \ insert(long long x, int k = 1) {\n        assert(0 <= x && x < (1LL << log));\n\
    \        assert(k >= 0);\n        int v = 0;\n        cnt[v] += k;\n        for\
    \ (int d = log - 1; d >= 0; d--) {\n            int b = x >> d & 1;\n        \
    \    if (ch[v][b] == -1) {\n                ch[v][b] = int(ch.size());\n     \
    \           ch.push_back({-1, -1});\n                cnt.push_back(0);\n     \
    \       }\n            v = ch[v][b];\n            cnt[v] += k;\n        }\n  \
    \  }\n    void erase(long long x, int k = 1) {\n        assert(0 <= x && x < (1LL\
    \ << log));\n        assert(0 <= k && k <= count(x));\n        int v = 0;\n  \
    \      cnt[v] -= k;\n        for (int d = log - 1; d >= 0; d--) {\n          \
    \  v = ch[v][x >> d & 1];\n            cnt[v] -= k;\n        }\n    }\n    int\
    \ count(long long x) const {\n        assert(0 <= x && x < (1LL << log));\n  \
    \      int v = 0;\n        for (int d = log - 1; d >= 0; d--) {\n            v\
    \ = ch[v][x >> d & 1];\n            if (v == -1) return 0;\n        }\n      \
    \  return cnt[v];\n    }\n    // #{ a : (a ^ xor_val) < upper }\n    int count_less(long\
    \ long upper, long long xor_val = 0) const {\n        assert(0 <= xor_val && xor_val\
    \ < (1LL << log));\n        if (upper <= 0) return 0;\n        if (upper >= (1LL\
    \ << log)) return size();\n        int v = 0, res = 0;\n        for (int d = log\
    \ - 1; d >= 0; d--) {\n            int b = (upper >> d & 1), f = (xor_val >> d\
    \ & 1);\n            if (b) {\n                int c = ch[v][f];\n           \
    \     if (c != -1) res += cnt[c];\n            }\n            v = ch[v][b ^ f];\n\
    \            if (v == -1) break;\n        }\n        return res;\n    }\n    //\
    \ k-th smallest (0-indexed) of { a ^ xor_val }\n    long long kth_smallest(int\
    \ k, long long xor_val = 0) const {\n        assert(0 <= k && k < size());\n \
    \       assert(0 <= xor_val && xor_val < (1LL << log));\n        int v = 0;\n\
    \        long long res = 0;\n        for (int d = log - 1; d >= 0; d--) {\n  \
    \          int f = xor_val >> d & 1;\n            int c = ch[v][f];\n        \
    \    int c_cnt = c == -1 ? 0 : cnt[c];\n            if (k < c_cnt) {\n       \
    \         v = c;\n            } else {\n                k -= c_cnt;\n        \
    \        v = ch[v][f ^ 1];\n                res |= 1LL << d;\n            }\n\
    \        }\n        return res;\n    }\n    long long kth_largest(int k, long\
    \ long xor_val = 0) const {\n        assert(0 <= k && k < size());\n        return\
    \ kth_smallest(size() - 1 - k, xor_val);\n    }\n    long long min(long long xor_val\
    \ = 0) const {\n        return kth_smallest(0, xor_val);\n    }\n    long long\
    \ max(long long xor_val = 0) const {\n        return kth_smallest(size() - 1,\
    \ xor_val);\n    }\n\nprivate:\n    std::vector<std::array<int, 2>> ch;\n    std::vector<int>\
    \ cnt;\n};\n#line 5 \"test/library-checker/set_xor_min.test.cpp\"\n\nint main()\
    \ {\n    int q;\n    std::cin >> q;\n    binary_trie<30> t;\n    while (q--) {\n\
    \        int c, x;\n        std::cin >> c >> x;\n        if (c == 0) {\n     \
    \       if (t.count(x) == 0) t.insert(x);\n        } else if (c == 1) {\n    \
    \        if (t.count(x) == 1) t.erase(x);\n        } else {\n            std::cout\
    \ << t.min(x) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#include\
    \ <iostream>\n\n#include \"datastructure/binary_trie.hpp\"\n\nint main() {\n \
    \   int q;\n    std::cin >> q;\n    binary_trie<30> t;\n    while (q--) {\n  \
    \      int c, x;\n        std::cin >> c >> x;\n        if (c == 0) {\n       \
    \     if (t.count(x) == 0) t.insert(x);\n        } else if (c == 1) {\n      \
    \      if (t.count(x) == 1) t.erase(x);\n        } else {\n            std::cout\
    \ << t.min(x) << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - datastructure/binary_trie.hpp
  isVerificationFile: true
  path: test/library-checker/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 02:09:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/set_xor_min.test.cpp
- /verify/test/library-checker/set_xor_min.test.cpp.html
title: test/library-checker/set_xor_min.test.cpp
---
