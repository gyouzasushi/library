---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/trie.hpp
    title: Trie
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
  bundledCode: "#line 1 \"test/unit/trie.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <string>\n#include <vector>\n\n#line 2 \"string/trie.hpp\"\n#include\
    \ <array>\n#line 5 \"string/trie.hpp\"\ntemplate <int sigma = 26, int base = 'a'>\
    \ struct trie {\n    static_assert(sigma >= 1);\n\npublic:\n    trie() : ch(1),\
    \ par(1, -1), dep(1, 0), cnt(1, 0), cnt_prefix(1, 0) {\n        ch[0].fill(-1);\n\
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
    \ par, dep, cnt, cnt_prefix;\n};\n#line 10 \"test/unit/trie.test.cpp\"\n\nstd::string\
    \ rand_str(std::mt19937& rng, int maxlen, int alpha) {\n    int len = rng() %\
    \ (maxlen + 1);\n    std::string s;\n    for (int i = 0; i < len; i++) s += char('a'\
    \ + rng() % alpha);\n    return s;\n}\nbool is_prefix(const std::string& p, const\
    \ std::string& s) {\n    return p.size() <= s.size() && s.compare(0, p.size(),\
    \ p) == 0;\n}\n\nint main() {\n    std::mt19937 rng(4242);\n    // multiset semantics\
    \ vs brute force\n    for (int it = 0; it < 200; it++) {\n        trie<3> t;\n\
    \        std::vector<std::string> ms;\n        for (int q = 0; q < 60; q++) {\n\
    \            std::string s = rand_str(rng, 5, 3);\n            if (rng() % 3 !=\
    \ 0 || ms.empty()) {\n                int v = t.insert(s);\n                ms.push_back(s);\n\
    \                assert(t.find(s) == v && t.depth(v) == int(s.size()));\n    \
    \        } else {\n                std::string e = ms[rng() % ms.size()];\n  \
    \              t.erase(e);\n                ms.erase(std::find(ms.begin(), ms.end(),\
    \ e));\n            }\n            std::string p = rand_str(rng, 5, 3);\n    \
    \        int v = t.find(p);\n            int exact = int(std::count(ms.begin(),\
    \ ms.end(), p));\n            int pref = int(std::count_if(ms.begin(), ms.end(),\
    \ [&](const std::string& x) { return is_prefix(p, x); }));\n            if (v\
    \ == -1) {\n                assert(pref == 0);\n            } else {\n       \
    \         assert(t.count(v) == exact);\n                assert(t.count_prefix(v)\
    \ == pref);\n                assert(t.depth(v) == int(p.size()));\n          \
    \      // walk by next from the root reaches the same node, parent walks back\n\
    \                int w = 0;\n                for (char c : p) w = t.next(w, c);\n\
    \                assert(w == v);\n                int up = v;\n              \
    \  for (size_t i = 0; i < p.size(); i++) up = t.parent(up);\n                assert(up\
    \ == 0 && t.parent(0) == -1);\n            }\n        }\n        assert(t.count_prefix(0)\
    \ == int(ms.size()));\n    }\n    // ABC353 E: sum of LCP over pairs = sum over\
    \ nodes of C(count_prefix, 2)\n    for (int it = 0; it < 50; it++) {\n       \
    \ int n = 1 + rng() % 8;\n        std::vector<std::string> s(n);\n        trie<26>\
    \ t;\n        for (auto& x : s) x = rand_str(rng, 6, 2), t.insert(x);\n      \
    \  long long brute = 0;\n        for (int i = 0; i < n; i++) {\n            for\
    \ (int j = i + 1; j < n; j++) {\n                size_t k = 0;\n             \
    \   while (k < s[i].size() && k < s[j].size() && s[i][k] == s[j][k]) k++;\n  \
    \              brute += k;\n            }\n        }\n        long long got =\
    \ 0;\n        for (int v = 1; v < t.size(); v++) got += (long long)t.count_prefix(v)\
    \ * (t.count_prefix(v) - 1) / 2;\n        assert(got == brute);\n    }\n    //\
    \ ABC377 G: min over X in {\"\", S_1..S_{k-1}} of |T| + |X| - 2 LCP(T, X), with\
    \ per-node side data\n    for (int it = 0; it < 50; it++) {\n        int n = 1\
    \ + rng() % 8;\n        std::vector<std::string> s(n);\n        for (auto& x :\
    \ s) x = rand_str(rng, 6, 2);\n        trie<26> t;\n        std::vector<int> min_len\
    \ = {0};  // min length of inserted strings in the subtree; root: \"\" allowed\n\
    \        for (int k = 0; k < n; k++) {\n            const std::string& T = s[k];\n\
    \            int brute = int(T.size());\n            for (int i = 0; i < k; i++)\
    \ {\n                size_t l = 0;\n                while (l < T.size() && l <\
    \ s[i].size() && T[l] == s[i][l]) l++;\n                brute = std::min(brute,\
    \ int(T.size() + s[i].size() - 2 * l));\n            }\n            int got =\
    \ int(T.size());\n            int v = 0;\n            for (size_t j = 0; j <=\
    \ T.size(); j++) {\n                got = std::min(got, int(T.size() - j) + min_len[v]\
    \ - int(j));\n                if (j == T.size() || (v = t.next(v, T[j])) == -1)\
    \ break;\n            }\n            assert(got == brute);\n            int e\
    \ = t.insert(T);\n            min_len.resize(t.size(), 1 << 30);\n           \
    \ for (int u = e; u != 0; u = t.parent(u)) min_len[u] = std::min(min_len[u], int(T.size()));\n\
    \        }\n    }\n    // integer sequences\n    {\n        trie<10, 0> t;\n \
    \       std::vector<int> a = {3, 1, 4}, b = {3, 1}, c = {3, 1, 5};\n        int\
    \ va = t.insert(a), vb = t.insert(b);\n        assert(t.find(c) == -1 && t.find(b)\
    \ == vb && t.parent(va) == vb);\n        assert(t.count_prefix(vb) == 2 && t.count(vb)\
    \ == 1 && t.count_prefix(0) == 2);\n        assert(t.next(vb, 4) == va && t.next(vb,\
    \ 5) == -1);\n    }\n    std::cout << \"Hello World\" << std::endl;\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <string>\n#include <vector>\n\n#include \"string/trie.hpp\"\n\nstd::string\
    \ rand_str(std::mt19937& rng, int maxlen, int alpha) {\n    int len = rng() %\
    \ (maxlen + 1);\n    std::string s;\n    for (int i = 0; i < len; i++) s += char('a'\
    \ + rng() % alpha);\n    return s;\n}\nbool is_prefix(const std::string& p, const\
    \ std::string& s) {\n    return p.size() <= s.size() && s.compare(0, p.size(),\
    \ p) == 0;\n}\n\nint main() {\n    std::mt19937 rng(4242);\n    // multiset semantics\
    \ vs brute force\n    for (int it = 0; it < 200; it++) {\n        trie<3> t;\n\
    \        std::vector<std::string> ms;\n        for (int q = 0; q < 60; q++) {\n\
    \            std::string s = rand_str(rng, 5, 3);\n            if (rng() % 3 !=\
    \ 0 || ms.empty()) {\n                int v = t.insert(s);\n                ms.push_back(s);\n\
    \                assert(t.find(s) == v && t.depth(v) == int(s.size()));\n    \
    \        } else {\n                std::string e = ms[rng() % ms.size()];\n  \
    \              t.erase(e);\n                ms.erase(std::find(ms.begin(), ms.end(),\
    \ e));\n            }\n            std::string p = rand_str(rng, 5, 3);\n    \
    \        int v = t.find(p);\n            int exact = int(std::count(ms.begin(),\
    \ ms.end(), p));\n            int pref = int(std::count_if(ms.begin(), ms.end(),\
    \ [&](const std::string& x) { return is_prefix(p, x); }));\n            if (v\
    \ == -1) {\n                assert(pref == 0);\n            } else {\n       \
    \         assert(t.count(v) == exact);\n                assert(t.count_prefix(v)\
    \ == pref);\n                assert(t.depth(v) == int(p.size()));\n          \
    \      // walk by next from the root reaches the same node, parent walks back\n\
    \                int w = 0;\n                for (char c : p) w = t.next(w, c);\n\
    \                assert(w == v);\n                int up = v;\n              \
    \  for (size_t i = 0; i < p.size(); i++) up = t.parent(up);\n                assert(up\
    \ == 0 && t.parent(0) == -1);\n            }\n        }\n        assert(t.count_prefix(0)\
    \ == int(ms.size()));\n    }\n    // ABC353 E: sum of LCP over pairs = sum over\
    \ nodes of C(count_prefix, 2)\n    for (int it = 0; it < 50; it++) {\n       \
    \ int n = 1 + rng() % 8;\n        std::vector<std::string> s(n);\n        trie<26>\
    \ t;\n        for (auto& x : s) x = rand_str(rng, 6, 2), t.insert(x);\n      \
    \  long long brute = 0;\n        for (int i = 0; i < n; i++) {\n            for\
    \ (int j = i + 1; j < n; j++) {\n                size_t k = 0;\n             \
    \   while (k < s[i].size() && k < s[j].size() && s[i][k] == s[j][k]) k++;\n  \
    \              brute += k;\n            }\n        }\n        long long got =\
    \ 0;\n        for (int v = 1; v < t.size(); v++) got += (long long)t.count_prefix(v)\
    \ * (t.count_prefix(v) - 1) / 2;\n        assert(got == brute);\n    }\n    //\
    \ ABC377 G: min over X in {\"\", S_1..S_{k-1}} of |T| + |X| - 2 LCP(T, X), with\
    \ per-node side data\n    for (int it = 0; it < 50; it++) {\n        int n = 1\
    \ + rng() % 8;\n        std::vector<std::string> s(n);\n        for (auto& x :\
    \ s) x = rand_str(rng, 6, 2);\n        trie<26> t;\n        std::vector<int> min_len\
    \ = {0};  // min length of inserted strings in the subtree; root: \"\" allowed\n\
    \        for (int k = 0; k < n; k++) {\n            const std::string& T = s[k];\n\
    \            int brute = int(T.size());\n            for (int i = 0; i < k; i++)\
    \ {\n                size_t l = 0;\n                while (l < T.size() && l <\
    \ s[i].size() && T[l] == s[i][l]) l++;\n                brute = std::min(brute,\
    \ int(T.size() + s[i].size() - 2 * l));\n            }\n            int got =\
    \ int(T.size());\n            int v = 0;\n            for (size_t j = 0; j <=\
    \ T.size(); j++) {\n                got = std::min(got, int(T.size() - j) + min_len[v]\
    \ - int(j));\n                if (j == T.size() || (v = t.next(v, T[j])) == -1)\
    \ break;\n            }\n            assert(got == brute);\n            int e\
    \ = t.insert(T);\n            min_len.resize(t.size(), 1 << 30);\n           \
    \ for (int u = e; u != 0; u = t.parent(u)) min_len[u] = std::min(min_len[u], int(T.size()));\n\
    \        }\n    }\n    // integer sequences\n    {\n        trie<10, 0> t;\n \
    \       std::vector<int> a = {3, 1, 4}, b = {3, 1}, c = {3, 1, 5};\n        int\
    \ va = t.insert(a), vb = t.insert(b);\n        assert(t.find(c) == -1 && t.find(b)\
    \ == vb && t.parent(va) == vb);\n        assert(t.count_prefix(vb) == 2 && t.count(vb)\
    \ == 1 && t.count_prefix(0) == 2);\n        assert(t.next(vb, 4) == va && t.next(vb,\
    \ 5) == -1);\n    }\n    std::cout << \"Hello World\" << std::endl;\n    return\
    \ 0;\n}\n"
  dependsOn:
  - string/trie.hpp
  isVerificationFile: true
  path: test/unit/trie.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 15:53:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/trie.test.cpp
layout: document
redirect_from:
- /verify/test/unit/trie.test.cpp
- /verify/test/unit/trie.test.cpp.html
title: test/unit/trie.test.cpp
---
