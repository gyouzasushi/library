---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/aho_corasick.hpp
    title: Aho-Corasick
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/aho_corasick.test.cpp
    title: test/unit/aho_corasick.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/trie.test.cpp
    title: test/unit/trie.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/430.test.cpp
    title: test/yukicoder/430.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/trie.hpp\"\n#include <array>\n#include <cassert>\n\
    #include <vector>\ntemplate <int sigma = 26, int base = 'a'> struct trie {\n \
    \   static_assert(sigma >= 1);\n\npublic:\n    trie() : ch(1), par(1, -1), dep(1,\
    \ 0), cnt(1, 0), cnt_prefix(1, 0) {\n        ch[0].fill(-1);\n    }\n    int size()\
    \ const {\n        return int(ch.size());\n    }\n    template <class Seq> int\
    \ insert(const Seq& s) {\n        int v = 0;\n        cnt_prefix[v]++;\n     \
    \   for (auto c : s) {\n            int x = int(c) - base;\n            assert(0\
    \ <= x && x < sigma);\n            if (ch[v][x] == -1) {\n                ch[v][x]\
    \ = size();\n                ch.emplace_back().fill(-1);\n                par.push_back(v);\n\
    \                dep.push_back(dep[v] + 1);\n                cnt.push_back(0);\n\
    \                cnt_prefix.push_back(0);\n            }\n            v = ch[v][x];\n\
    \            cnt_prefix[v]++;\n        }\n        cnt[v]++;\n        return v;\n\
    \    }\n    template <class Seq> void erase(const Seq& s) {\n        int t = find(s);\n\
    \        assert(t != -1 && cnt[t] > 0);\n        cnt[t]--;\n        for (int v\
    \ = t; v != -1; v = par[v]) cnt_prefix[v]--;\n    }\n    template <class Seq>\
    \ int find(const Seq& s) const {\n        int v = 0;\n        for (auto c : s)\
    \ {\n            v = next(v, int(c));\n            if (v == -1) return -1;\n \
    \       }\n        return v;\n    }\n    int next(int v, int c) const {\n    \
    \    assert(0 <= v && v < size());\n        int x = c - base;\n        assert(0\
    \ <= x && x < sigma);\n        return ch[v][x];\n    }\n    int parent(int v)\
    \ const {\n        assert(0 <= v && v < size());\n        return par[v];\n   \
    \ }\n    int depth(int v) const {\n        assert(0 <= v && v < size());\n   \
    \     return dep[v];\n    }\n    int count(int v) const {\n        assert(0 <=\
    \ v && v < size());\n        return cnt[v];\n    }\n    int count_prefix(int v)\
    \ const {\n        assert(0 <= v && v < size());\n        return cnt_prefix[v];\n\
    \    }\n\nprivate:\n    std::vector<std::array<int, sigma>> ch;\n    std::vector<int>\
    \ par, dep, cnt, cnt_prefix;\n};\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <vector>\ntemplate\
    \ <int sigma = 26, int base = 'a'> struct trie {\n    static_assert(sigma >= 1);\n\
    \npublic:\n    trie() : ch(1), par(1, -1), dep(1, 0), cnt(1, 0), cnt_prefix(1,\
    \ 0) {\n        ch[0].fill(-1);\n    }\n    int size() const {\n        return\
    \ int(ch.size());\n    }\n    template <class Seq> int insert(const Seq& s) {\n\
    \        int v = 0;\n        cnt_prefix[v]++;\n        for (auto c : s) {\n  \
    \          int x = int(c) - base;\n            assert(0 <= x && x < sigma);\n\
    \            if (ch[v][x] == -1) {\n                ch[v][x] = size();\n     \
    \           ch.emplace_back().fill(-1);\n                par.push_back(v);\n \
    \               dep.push_back(dep[v] + 1);\n                cnt.push_back(0);\n\
    \                cnt_prefix.push_back(0);\n            }\n            v = ch[v][x];\n\
    \            cnt_prefix[v]++;\n        }\n        cnt[v]++;\n        return v;\n\
    \    }\n    template <class Seq> void erase(const Seq& s) {\n        int t = find(s);\n\
    \        assert(t != -1 && cnt[t] > 0);\n        cnt[t]--;\n        for (int v\
    \ = t; v != -1; v = par[v]) cnt_prefix[v]--;\n    }\n    template <class Seq>\
    \ int find(const Seq& s) const {\n        int v = 0;\n        for (auto c : s)\
    \ {\n            v = next(v, int(c));\n            if (v == -1) return -1;\n \
    \       }\n        return v;\n    }\n    int next(int v, int c) const {\n    \
    \    assert(0 <= v && v < size());\n        int x = c - base;\n        assert(0\
    \ <= x && x < sigma);\n        return ch[v][x];\n    }\n    int parent(int v)\
    \ const {\n        assert(0 <= v && v < size());\n        return par[v];\n   \
    \ }\n    int depth(int v) const {\n        assert(0 <= v && v < size());\n   \
    \     return dep[v];\n    }\n    int count(int v) const {\n        assert(0 <=\
    \ v && v < size());\n        return cnt[v];\n    }\n    int count_prefix(int v)\
    \ const {\n        assert(0 <= v && v < size());\n        return cnt_prefix[v];\n\
    \    }\n\nprivate:\n    std::vector<std::array<int, sigma>> ch;\n    std::vector<int>\
    \ par, dep, cnt, cnt_prefix;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy:
  - string/aho_corasick.hpp
  timestamp: '2026-10-26 15:53:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/trie.test.cpp
  - test/unit/aho_corasick.test.cpp
  - test/yukicoder/430.test.cpp
documentation_of: string/trie.hpp
layout: document
title: Trie
---

### 概要
- 文字列の多重集合を木で持つ。ノードは根を $0$ とする作成順の番号で扱う。

### 使い方
- `trie<sigma, base>()`: 文字が `base, ..., base + sigma - 1` の空の trie を作る。
- `size()`: ノード数を返す。
- `insert(s)`: `s` を 1 個追加し、`s` の終端ノードを返す。
- `erase(s)`: `s` を 1 個削除する。
- `find(s)`: `s` の終端ノードを返す。`s` を接頭辞に持つ文字列が無ければ `-1`。
- `next(v, c)`: ノード `v` から文字 `c` で進んだノードを返す。無ければ `-1`。
- `parent(v)`: ノード `v` の親を返す。根なら `-1`。
- `depth(v)`: ノード `v` の深さを返す。
- `count(v)`: ノード `v` で終わる文字列の個数を返す。
- `count_prefix(v)`: ノード `v` を通る文字列の個数を返す。

### 制約
- `s` の各文字 `c` は $\text{base} \le c < \text{base} + \sigma$
- `erase`: `count(find(s))` $\ge 1$
- $0 \le v <$ `size()`

### 計算量
- `insert`, `erase`, `find`: $\mathcal{O}(\lvert s \rvert)$
- その他: $\mathcal{O}(1)$
