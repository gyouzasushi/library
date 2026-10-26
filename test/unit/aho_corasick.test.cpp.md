---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/aho_corasick.hpp
    title: Aho-Corasick
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
  bundledCode: "#line 1 \"test/unit/aho_corasick.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <string>\n#include <vector>\n\n#line 2 \"string/aho_corasick.hpp\"\n\
    #include <array>\n#line 5 \"string/aho_corasick.hpp\"\n\n#line 5 \"string/trie.hpp\"\
    \ntemplate <int sigma = 26, int base = 'a'> struct trie {\n    static_assert(sigma\
    \ >= 1);\n\npublic:\n    trie() : ch(1), par(1, -1), dep(1, 0), cnt(1, 0), cnt_prefix(1,\
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
    \    std::vector<int> fl, cnt, ord;\n};\n#line 11 \"test/unit/aho_corasick.test.cpp\"\
    \nstd::string rand_str(std::mt19937& rng, int maxlen, int alpha) {\n    int len\
    \ = rng() % (maxlen + 1);\n    std::string s;\n    for (int i = 0; i < len; i++)\
    \ s += char('a' + rng() % alpha);\n    return s;\n}\nbool ends_with(const std::string&\
    \ s, const std::string& p) {\n    return p.size() <= s.size() && s.compare(s.size()\
    \ - p.size(), p.size(), p) == 0;\n}\nint main() {\n    std::mt19937 rng(430);\n\
    \    for (int it = 0; it < 500; it++) {\n        int alpha = 1 + rng() % 3, m\
    \ = rng() % 8;\n        trie<3> t;\n        std::vector<std::string> pats;\n \
    \       std::vector<int> end;\n        for (int i = 0; i < m; i++) {\n       \
    \     pats.push_back(rand_str(rng, 4, alpha));\n            end.push_back(t.insert(pats.back()));\n\
    \        }\n        aho_corasick ac(t);\n        assert(ac.size() == t.size());\n\
    \        // order: increasing depth, starts with root\n        const auto& ord\
    \ = ac.order();\n        assert(int(ord.size()) == t.size() && ord[0] == 0);\n\
    \        for (int i = 1; i < int(ord.size()); i++) assert(t.depth(ord[i - 1])\
    \ <= t.depth(ord[i]));\n        // fail: longest proper suffix that is a trie\
    \ node\n        std::vector<std::string> str(t.size());\n        for (int v :\
    \ ord) {\n            if (v == 0) continue;\n            int p = t.parent(v);\n\
    \            for (int c = 0; c < 3; c++) {\n                if (t.next(p, 'a'\
    \ + c) == v) str[v] = str[p] + char('a' + c);\n            }\n        }\n    \
    \    for (int v = 0; v < t.size(); v++) {\n            if (v == 0) {\n       \
    \         assert(ac.fail(v) == -1);\n                continue;\n            }\n\
    \            int best = 0;\n            for (int u = 0; u < t.size(); u++) {\n\
    \                if (u != v && ends_with(str[v], str[u]) && str[u].size() > str[best].size())\
    \ best = u;\n            }\n            assert(ac.fail(v) == best);\n        \
    \    int c = 0;\n            for (auto& p : pats) c += ends_with(str[v], p);\n\
    \            assert(ac.count(v) == c);\n        }\n        // scan a text: state\
    \ = longest suffix of the read prefix that is a trie node\n        std::string\
    \ s = rand_str(rng, 30, alpha);\n        std::vector<long long> hit(t.size());\n\
    \        std::vector<int> occ(m);\n        int v = 0;\n        long long total\
    \ = 0;\n        for (int i = 0; i < int(s.size()); i++) {\n            v = ac.next(v,\
    \ s[i]);\n            hit[v]++;\n            total += ac.count(v);\n         \
    \   std::string pre = s.substr(0, i + 1);\n            int best = 0;\n       \
    \     for (int u = 0; u < t.size(); u++) {\n                if (ends_with(pre,\
    \ str[u]) && str[u].size() > str[best].size()) best = u;\n            }\n    \
    \        assert(v == best);\n            for (int j = 0; j < m; j++) occ[j] +=\
    \ ends_with(pre, pats[j]);\n        }\n        long long brute = 0;\n        for\
    \ (int j = 0; j < m; j++) brute += occ[j];\n        assert(total == brute);\n\
    \        for (int i = int(ord.size()) - 1; i >= 1; i--) hit[ac.fail(ord[i])] +=\
    \ hit[ord[i]];\n        for (int j = 0; j < m; j++) assert(hit[end[j]] == occ[j]);\n\
    \    }\n    {\n        // empty pattern matches at every position\n        trie<2>\
    \ t;\n        t.insert(std::string());\n        aho_corasick ac(t);\n        assert(ac.size()\
    \ == 1 && ac.count(0) == 1 && ac.next(0, 'a') == 0 && ac.next(0, 'b') == 0);\n\
    \    }\n    {\n        // large: 2e5 patterns of length 5 over 26 letters, text\
    \ 2e5\n        trie<26> t;\n        for (int i = 0; i < 200000; i++) t.insert(rand_str(rng,\
    \ 5, 26) + \"a\");\n        aho_corasick ac(t);\n        int v = 0;\n        long\
    \ long total = 0;\n        for (int i = 0; i < 200000; i++) {\n            v =\
    \ ac.next(v, 'a' + rng() % 26);\n            total += ac.count(v);\n        }\n\
    \        assert(total >= 0);\n    }\n    std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <string>\n#include <vector>\n\n#include \"string/aho_corasick.hpp\"\n\
    #include \"string/trie.hpp\"\nstd::string rand_str(std::mt19937& rng, int maxlen,\
    \ int alpha) {\n    int len = rng() % (maxlen + 1);\n    std::string s;\n    for\
    \ (int i = 0; i < len; i++) s += char('a' + rng() % alpha);\n    return s;\n}\n\
    bool ends_with(const std::string& s, const std::string& p) {\n    return p.size()\
    \ <= s.size() && s.compare(s.size() - p.size(), p.size(), p) == 0;\n}\nint main()\
    \ {\n    std::mt19937 rng(430);\n    for (int it = 0; it < 500; it++) {\n    \
    \    int alpha = 1 + rng() % 3, m = rng() % 8;\n        trie<3> t;\n        std::vector<std::string>\
    \ pats;\n        std::vector<int> end;\n        for (int i = 0; i < m; i++) {\n\
    \            pats.push_back(rand_str(rng, 4, alpha));\n            end.push_back(t.insert(pats.back()));\n\
    \        }\n        aho_corasick ac(t);\n        assert(ac.size() == t.size());\n\
    \        // order: increasing depth, starts with root\n        const auto& ord\
    \ = ac.order();\n        assert(int(ord.size()) == t.size() && ord[0] == 0);\n\
    \        for (int i = 1; i < int(ord.size()); i++) assert(t.depth(ord[i - 1])\
    \ <= t.depth(ord[i]));\n        // fail: longest proper suffix that is a trie\
    \ node\n        std::vector<std::string> str(t.size());\n        for (int v :\
    \ ord) {\n            if (v == 0) continue;\n            int p = t.parent(v);\n\
    \            for (int c = 0; c < 3; c++) {\n                if (t.next(p, 'a'\
    \ + c) == v) str[v] = str[p] + char('a' + c);\n            }\n        }\n    \
    \    for (int v = 0; v < t.size(); v++) {\n            if (v == 0) {\n       \
    \         assert(ac.fail(v) == -1);\n                continue;\n            }\n\
    \            int best = 0;\n            for (int u = 0; u < t.size(); u++) {\n\
    \                if (u != v && ends_with(str[v], str[u]) && str[u].size() > str[best].size())\
    \ best = u;\n            }\n            assert(ac.fail(v) == best);\n        \
    \    int c = 0;\n            for (auto& p : pats) c += ends_with(str[v], p);\n\
    \            assert(ac.count(v) == c);\n        }\n        // scan a text: state\
    \ = longest suffix of the read prefix that is a trie node\n        std::string\
    \ s = rand_str(rng, 30, alpha);\n        std::vector<long long> hit(t.size());\n\
    \        std::vector<int> occ(m);\n        int v = 0;\n        long long total\
    \ = 0;\n        for (int i = 0; i < int(s.size()); i++) {\n            v = ac.next(v,\
    \ s[i]);\n            hit[v]++;\n            total += ac.count(v);\n         \
    \   std::string pre = s.substr(0, i + 1);\n            int best = 0;\n       \
    \     for (int u = 0; u < t.size(); u++) {\n                if (ends_with(pre,\
    \ str[u]) && str[u].size() > str[best].size()) best = u;\n            }\n    \
    \        assert(v == best);\n            for (int j = 0; j < m; j++) occ[j] +=\
    \ ends_with(pre, pats[j]);\n        }\n        long long brute = 0;\n        for\
    \ (int j = 0; j < m; j++) brute += occ[j];\n        assert(total == brute);\n\
    \        for (int i = int(ord.size()) - 1; i >= 1; i--) hit[ac.fail(ord[i])] +=\
    \ hit[ord[i]];\n        for (int j = 0; j < m; j++) assert(hit[end[j]] == occ[j]);\n\
    \    }\n    {\n        // empty pattern matches at every position\n        trie<2>\
    \ t;\n        t.insert(std::string());\n        aho_corasick ac(t);\n        assert(ac.size()\
    \ == 1 && ac.count(0) == 1 && ac.next(0, 'a') == 0 && ac.next(0, 'b') == 0);\n\
    \    }\n    {\n        // large: 2e5 patterns of length 5 over 26 letters, text\
    \ 2e5\n        trie<26> t;\n        for (int i = 0; i < 200000; i++) t.insert(rand_str(rng,\
    \ 5, 26) + \"a\");\n        aho_corasick ac(t);\n        int v = 0;\n        long\
    \ long total = 0;\n        for (int i = 0; i < 200000; i++) {\n            v =\
    \ ac.next(v, 'a' + rng() % 26);\n            total += ac.count(v);\n        }\n\
    \        assert(total >= 0);\n    }\n    std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - string/aho_corasick.hpp
  - string/trie.hpp
  isVerificationFile: true
  path: test/unit/aho_corasick.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 07:43:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/aho_corasick.test.cpp
layout: document
redirect_from:
- /verify/test/unit/aho_corasick.test.cpp
- /verify/test/unit/aho_corasick.test.cpp.html
title: test/unit/aho_corasick.test.cpp
---
