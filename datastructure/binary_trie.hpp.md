---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/set_xor_min.test.cpp
    title: test/library-checker/set_xor_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/binary_trie.test.cpp
    title: test/unit/binary_trie.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/binary_trie.hpp\"\n#include <array>\n#include\
    \ <cassert>\n#include <vector>\ntemplate <int log = 30> struct binary_trie {\n\
    \    static_assert(1 <= log && log <= 62);\n\npublic:\n    binary_trie() : ch(1,\
    \ {-1, -1}), cnt(1, 0) {\n    }\n    int size() const {\n        return cnt[0];\n\
    \    }\n    void insert(long long x, int k = 1) {\n        assert(0 <= x && x\
    \ < (1LL << log));\n        assert(k >= 0);\n        int v = 0;\n        cnt[v]\
    \ += k;\n        for (int d = log - 1; d >= 0; d--) {\n            int b = x >>\
    \ d & 1;\n            if (ch[v][b] == -1) {\n                ch[v][b] = int(ch.size());\n\
    \                ch.push_back({-1, -1});\n                cnt.push_back(0);\n\
    \            }\n            v = ch[v][b];\n            cnt[v] += k;\n        }\n\
    \    }\n    void erase(long long x, int k = 1) {\n        assert(0 <= x && x <\
    \ (1LL << log));\n        assert(0 <= k && k <= count(x));\n        int v = 0;\n\
    \        cnt[v] -= k;\n        for (int d = log - 1; d >= 0; d--) {\n        \
    \    v = ch[v][x >> d & 1];\n            cnt[v] -= k;\n        }\n    }\n    int\
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
    \ cnt;\n};\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <vector>\ntemplate\
    \ <int log = 30> struct binary_trie {\n    static_assert(1 <= log && log <= 62);\n\
    \npublic:\n    binary_trie() : ch(1, {-1, -1}), cnt(1, 0) {\n    }\n    int size()\
    \ const {\n        return cnt[0];\n    }\n    void insert(long long x, int k =\
    \ 1) {\n        assert(0 <= x && x < (1LL << log));\n        assert(k >= 0);\n\
    \        int v = 0;\n        cnt[v] += k;\n        for (int d = log - 1; d >=\
    \ 0; d--) {\n            int b = x >> d & 1;\n            if (ch[v][b] == -1)\
    \ {\n                ch[v][b] = int(ch.size());\n                ch.push_back({-1,\
    \ -1});\n                cnt.push_back(0);\n            }\n            v = ch[v][b];\n\
    \            cnt[v] += k;\n        }\n    }\n    void erase(long long x, int k\
    \ = 1) {\n        assert(0 <= x && x < (1LL << log));\n        assert(0 <= k &&\
    \ k <= count(x));\n        int v = 0;\n        cnt[v] -= k;\n        for (int\
    \ d = log - 1; d >= 0; d--) {\n            v = ch[v][x >> d & 1];\n          \
    \  cnt[v] -= k;\n        }\n    }\n    int count(long long x) const {\n      \
    \  assert(0 <= x && x < (1LL << log));\n        int v = 0;\n        for (int d\
    \ = log - 1; d >= 0; d--) {\n            v = ch[v][x >> d & 1];\n            if\
    \ (v == -1) return 0;\n        }\n        return cnt[v];\n    }\n    // #{ a :\
    \ (a ^ xor_val) < upper }\n    int count_less(long long upper, long long xor_val\
    \ = 0) const {\n        assert(0 <= xor_val && xor_val < (1LL << log));\n    \
    \    if (upper <= 0) return 0;\n        if (upper >= (1LL << log)) return size();\n\
    \        int v = 0, res = 0;\n        for (int d = log - 1; d >= 0; d--) {\n \
    \           int b = (upper >> d & 1), f = (xor_val >> d & 1);\n            if\
    \ (b) {\n                int c = ch[v][f];\n                if (c != -1) res +=\
    \ cnt[c];\n            }\n            v = ch[v][b ^ f];\n            if (v ==\
    \ -1) break;\n        }\n        return res;\n    }\n    // k-th smallest (0-indexed)\
    \ of { a ^ xor_val }\n    long long kth_smallest(int k, long long xor_val = 0)\
    \ const {\n        assert(0 <= k && k < size());\n        assert(0 <= xor_val\
    \ && xor_val < (1LL << log));\n        int v = 0;\n        long long res = 0;\n\
    \        for (int d = log - 1; d >= 0; d--) {\n            int f = xor_val >>\
    \ d & 1;\n            int c = ch[v][f];\n            int c_cnt = c == -1 ? 0 :\
    \ cnt[c];\n            if (k < c_cnt) {\n                v = c;\n            }\
    \ else {\n                k -= c_cnt;\n                v = ch[v][f ^ 1];\n   \
    \             res |= 1LL << d;\n            }\n        }\n        return res;\n\
    \    }\n    long long kth_largest(int k, long long xor_val = 0) const {\n    \
    \    assert(0 <= k && k < size());\n        return kth_smallest(size() - 1 - k,\
    \ xor_val);\n    }\n    long long min(long long xor_val = 0) const {\n       \
    \ return kth_smallest(0, xor_val);\n    }\n    long long max(long long xor_val\
    \ = 0) const {\n        return kth_smallest(size() - 1, xor_val);\n    }\n\nprivate:\n\
    \    std::vector<std::array<int, 2>> ch;\n    std::vector<int> cnt;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/binary_trie.hpp
  requiredBy: []
  timestamp: '2026-10-26 02:09:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/binary_trie.test.cpp
  - test/library-checker/set_xor_min.test.cpp
documentation_of: datastructure/binary_trie.hpp
layout: document
title: Binary Trie
---

### 概要
- 非負整数の多重集合。各要素と `xor_val` との xor をとった値の順序で問い合わせる。

### 使い方
- `binary_trie<log>()`: $[0, 2^{\text{log}})$ の整数を入れる空の多重集合を作る。
- `size()`: 要素数を返す。
- `insert(x, k = 1)`: `x` を `k` 個追加する。
- `erase(x, k = 1)`: `x` を `k` 個削除する。
- `count(x)`: `x` の個数を返す。
- `count_less(upper, xor_val = 0)`: `(a ^ xor_val) < upper` となる要素 `a` の個数を返す。
- `kth_smallest(k, xor_val = 0)`: `a ^ xor_val` を昇順に並べたときの `k` 番目 (0-indexed) を返す。
- `kth_largest(k, xor_val = 0)`: `a ^ xor_val` を降順に並べたときの `k` 番目 (0-indexed) を返す。
- `min(xor_val = 0)`: `a ^ xor_val` の最小値を返す。
- `max(xor_val = 0)`: `a ^ xor_val` の最大値を返す。

### 制約
- $1 \le \text{log} \le 62$
- $0 \le x, \text{xor\_val} < 2^{\text{log}}$
- `erase`: $0 \le k \le$ `count(x)`
- `kth_smallest`, `kth_largest`: $0 \le k <$ `size()`
- `min`, `max`: $1 \le$ `size()`

### 計算量
- 各操作: $\mathcal{O}(\text{log})$
