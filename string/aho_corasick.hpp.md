---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/trie.hpp
    title: Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/aho_corasick.test.cpp
    title: test/unit/aho_corasick.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/430.test.cpp
    title: test/yukicoder/430.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/aho_corasick.hpp\"\n#include <array>\n#include <cassert>\n\
    #include <vector>\n\n#line 5 \"string/trie.hpp\"\ntemplate <int sigma = 26, int\
    \ base = 'a'> struct trie {\n    static_assert(sigma >= 1);\n\npublic:\n    trie()\
    \ : ch(1), par(1, -1), dep(1, 0), cnt(1, 0), cnt_prefix(1, 0) {\n        ch[0].fill(-1);\n\
    \    }\n    int size() const {\n        return int(ch.size());\n    }\n    template\
    \ <class Seq> int insert(const Seq& s) {\n        int v = 0;\n        cnt_prefix[v]++;\n\
    \        for (auto c : s) {\n            int x = int(c) - base;\n            assert(0\
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
    \ par, dep, cnt, cnt_prefix;\n};\n#line 7 \"string/aho_corasick.hpp\"\ntemplate\
    \ <int sigma = 26, int base = 'a'> struct aho_corasick {\n    explicit aho_corasick(const\
    \ trie<sigma, base>& t) : _n(t.size()), nxt(_n), fl(_n, -1), cnt(_n) {\n     \
    \   ord.reserve(_n);\n        ord.push_back(0);\n        for (int i = 0; i < _n;\
    \ i++) {\n            int v = ord[i];\n            cnt[v] = t.count(v) + (v ==\
    \ 0 ? 0 : cnt[fl[v]]);\n            for (int c = 0; c < sigma; c++) {\n      \
    \          int w = t.next(v, base + c);\n                if (w == -1) {\n    \
    \                nxt[v][c] = v == 0 ? 0 : nxt[fl[v]][c];\n                } else\
    \ {\n                    nxt[v][c] = w;\n                    fl[w] = v == 0 ?\
    \ 0 : nxt[fl[v]][c];\n                    ord.push_back(w);\n                }\n\
    \            }\n        }\n        assert(int(ord.size()) == _n);\n    }\n   \
    \ int size() const {\n        return _n;\n    }\n    int next(int v, int c) const\
    \ {\n        assert(0 <= v && v < _n);\n        int x = c - base;\n        assert(0\
    \ <= x && x < sigma);\n        return nxt[v][x];\n    }\n    int fail(int v) const\
    \ {\n        assert(0 <= v && v < _n);\n        return fl[v];\n    }\n    int\
    \ count(int v) const {\n        assert(0 <= v && v < _n);\n        return cnt[v];\n\
    \    }\n    const std::vector<int>& order() const {\n        return ord;\n   \
    \ }\n\n  private:\n    int _n;\n    std::vector<std::array<int, sigma>> nxt;\n\
    \    std::vector<int> fl, cnt, ord;\n};\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <vector>\n\n\
    #include \"string/trie.hpp\"\ntemplate <int sigma = 26, int base = 'a'> struct\
    \ aho_corasick {\n    explicit aho_corasick(const trie<sigma, base>& t) : _n(t.size()),\
    \ nxt(_n), fl(_n, -1), cnt(_n) {\n        ord.reserve(_n);\n        ord.push_back(0);\n\
    \        for (int i = 0; i < _n; i++) {\n            int v = ord[i];\n       \
    \     cnt[v] = t.count(v) + (v == 0 ? 0 : cnt[fl[v]]);\n            for (int c\
    \ = 0; c < sigma; c++) {\n                int w = t.next(v, base + c);\n     \
    \           if (w == -1) {\n                    nxt[v][c] = v == 0 ? 0 : nxt[fl[v]][c];\n\
    \                } else {\n                    nxt[v][c] = w;\n              \
    \      fl[w] = v == 0 ? 0 : nxt[fl[v]][c];\n                    ord.push_back(w);\n\
    \                }\n            }\n        }\n        assert(int(ord.size()) ==\
    \ _n);\n    }\n    int size() const {\n        return _n;\n    }\n    int next(int\
    \ v, int c) const {\n        assert(0 <= v && v < _n);\n        int x = c - base;\n\
    \        assert(0 <= x && x < sigma);\n        return nxt[v][x];\n    }\n    int\
    \ fail(int v) const {\n        assert(0 <= v && v < _n);\n        return fl[v];\n\
    \    }\n    int count(int v) const {\n        assert(0 <= v && v < _n);\n    \
    \    return cnt[v];\n    }\n    const std::vector<int>& order() const {\n    \
    \    return ord;\n    }\n\n  private:\n    int _n;\n    std::vector<std::array<int,\
    \ sigma>> nxt;\n    std::vector<int> fl, cnt, ord;\n};\n"
  dependsOn:
  - string/trie.hpp
  isVerificationFile: false
  path: string/aho_corasick.hpp
  requiredBy: []
  timestamp: '2026-10-27 07:43:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/aho_corasick.test.cpp
  - test/yukicoder/430.test.cpp
documentation_of: string/aho_corasick.hpp
layout: document
title: Aho-Corasick
---

### 概要
- trie の文字列集合を pattern とするオートマトン。状態は trie のノード番号。

### 使い方
- `aho_corasick<sigma, base>(t)`: trie `t` の現在の中身から構築する。
- `size()`: 状態数を返す。
- `next(v, c)`: 状態 `v` で文字 `c` を読んだ次の状態を返す。
- `fail(v)`: 状態 `v` の文字列の真の接尾辞のうち trie のノードである最長のものを返す。根なら `-1`。
- `count(v)`: 状態 `v` の文字列を接尾辞に持つ pattern の個数を返す。
- `order()`: 状態を深さの昇順に並べた列を返す。

### 制約
- `c` は $\text{base} \le c < \text{base} + \sigma$
- $0 \le v <$ `size()`

### 計算量
- 構築: $\mathcal{O}(\sigma \cdot \text{size}())$
- その他: $\mathcal{O}(1)$
