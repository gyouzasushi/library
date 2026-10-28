---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/subtree_classify.hpp
    title: "\u6839\u4ED8\u304D\u6728\u306E\u540C\u578B\u6027\u306B\u3088\u308B\u90E8\
      \u5206\u6728\u306E\u5206\u985E"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unit/subtree_classify.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iostream>\n#include <map>\n#include\
    \ <random>\n#include <string>\n#include <vector>\n\n#line 6 \"graph/subtree_classify.hpp\"\
    \nstd::vector<int> subtree_classify(const std::vector<std::vector<int>>& g, int\
    \ root = 0) {\n    int n = int(g.size());\n    assert(0 <= root && root < n);\n\
    \    std::vector<int> par(n, -1), order;\n    order.reserve(n);\n    order.push_back(root);\n\
    \    par[root] = root;\n    for (int i = 0; i < int(order.size()); i++) {\n  \
    \      int u = order[i];\n        for (int v : g[u]) {\n            if (v == par[u])\
    \ continue;\n            assert(par[v] == -1);\n            par[v] = u;\n    \
    \        order.push_back(v);\n        }\n    }\n    assert(int(order.size()) ==\
    \ n);\n    std::vector<int> ret(n);\n    std::map<std::vector<int>, int> id;\n\
    \    std::vector<int> key;\n    for (int i = n - 1; i >= 0; i--) {\n        int\
    \ u = order[i];\n        key.clear();\n        for (int v : g[u]) {\n        \
    \    if (v != par[u]) key.push_back(ret[v]);\n        }\n        std::ranges::sort(key);\n\
    \        ret[u] = id.try_emplace(key, int(id.size())).first->second;\n    }\n\
    \    return ret;\n}\n#line 11 \"test/unit/subtree_classify.test.cpp\"\n// AHU\
    \ canonical string of the subtree rooted at u\nstd::string canon(const std::vector<std::vector<int>>&\
    \ ch, int u) {\n    std::vector<std::string> s;\n    for (int v : ch[u]) s.push_back(canon(ch,\
    \ v));\n    std::sort(s.begin(), s.end());\n    std::string res = \"(\";\n   \
    \ for (auto& t : s) res += t;\n    return res + \")\";\n}\nvoid check(const std::vector<int>&\
    \ a, const std::vector<std::vector<int>>& ch, int root) {\n    int n = int(ch.size());\n\
    \    std::vector<std::string> c(n);\n    std::vector<int> order{root};\n    for\
    \ (int i = 0; i < int(order.size()); i++)\n        for (int v : ch[order[i]])\
    \ order.push_back(v);\n    for (int u : order) c[u] = canon(ch, u);\n    std::map<std::string,\
    \ int> cls;\n    for (int u = 0; u < n; u++) cls.emplace(c[u], 0);\n    int k\
    \ = int(cls.size());\n    assert(*std::max_element(a.begin(), a.end()) == k -\
    \ 1);\n    assert(*std::min_element(a.begin(), a.end()) == 0);\n    for (int i\
    \ = 0; i < n; i++)\n        for (int j = 0; j < n; j++) assert((a[i] == a[j])\
    \ == (c[i] == c[j]));\n}\nint main() {\n    std::mt19937 rng(20261027);\n    for\
    \ (int iter = 0; iter < 3000; iter++) {\n        int n = 1 + rng() % 9;\n    \
    \    int root = rng() % n;\n        // random labelled tree via random parent\
    \ in a random order\n        std::vector<int> perm(n);\n        for (int i = 0;\
    \ i < n; i++) perm[i] = i;\n        std::shuffle(perm.begin(), perm.end(), rng);\n\
    \        std::swap(perm[0], *std::find(perm.begin(), perm.end(), root));\n   \
    \     std::vector<std::vector<int>> ch(n), und(n);\n        for (int i = 1; i\
    \ < n; i++) {\n            int p = perm[rng() % i], v = perm[i];\n           \
    \ ch[p].push_back(v);\n            und[p].push_back(v);\n            und[v].push_back(p);\n\
    \        }\n        for (auto& l : und) std::shuffle(l.begin(), l.end(), rng);\n\
    \        std::vector<int> a = subtree_classify(ch, root);\n        check(a, ch,\
    \ root);\n        check(subtree_classify(und, root), ch, root);\n    }\n    {\n\
    \        // path of length 2e5: no recursion depth issue\n        int n = 200000;\n\
    \        std::vector<std::vector<int>> g(n);\n        for (int i = 1; i < n; i++)\
    \ {\n            g[i - 1].push_back(i);\n            g[i].push_back(i - 1);\n\
    \        }\n        std::vector<int> a = subtree_classify(g);\n        for (int\
    \ i = 0; i < n; i++) assert(a[i] == n - 1 - i);\n    }\n    {\n        // star:\
    \ all leaves in one class\n        int n = 100000;\n        std::vector<std::vector<int>>\
    \ g(n);\n        for (int i = 1; i < n; i++) g[0].push_back(i);\n        std::vector<int>\
    \ a = subtree_classify(g);\n        assert(a[0] == 1);\n        for (int i = 1;\
    \ i < n; i++) assert(a[i] == 0);\n    }\n    {\n        std::vector<int> a = subtree_classify(std::vector<std::vector<int>>(1));\n\
    \        assert((a == std::vector<int>{0}));\n    }\n    std::cout << \"Hello\
    \ World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <map>\n\
    #include <random>\n#include <string>\n#include <vector>\n\n#include \"graph/subtree_classify.hpp\"\
    \n// AHU canonical string of the subtree rooted at u\nstd::string canon(const\
    \ std::vector<std::vector<int>>& ch, int u) {\n    std::vector<std::string> s;\n\
    \    for (int v : ch[u]) s.push_back(canon(ch, v));\n    std::sort(s.begin(),\
    \ s.end());\n    std::string res = \"(\";\n    for (auto& t : s) res += t;\n \
    \   return res + \")\";\n}\nvoid check(const std::vector<int>& a, const std::vector<std::vector<int>>&\
    \ ch, int root) {\n    int n = int(ch.size());\n    std::vector<std::string> c(n);\n\
    \    std::vector<int> order{root};\n    for (int i = 0; i < int(order.size());\
    \ i++)\n        for (int v : ch[order[i]]) order.push_back(v);\n    for (int u\
    \ : order) c[u] = canon(ch, u);\n    std::map<std::string, int> cls;\n    for\
    \ (int u = 0; u < n; u++) cls.emplace(c[u], 0);\n    int k = int(cls.size());\n\
    \    assert(*std::max_element(a.begin(), a.end()) == k - 1);\n    assert(*std::min_element(a.begin(),\
    \ a.end()) == 0);\n    for (int i = 0; i < n; i++)\n        for (int j = 0; j\
    \ < n; j++) assert((a[i] == a[j]) == (c[i] == c[j]));\n}\nint main() {\n    std::mt19937\
    \ rng(20261027);\n    for (int iter = 0; iter < 3000; iter++) {\n        int n\
    \ = 1 + rng() % 9;\n        int root = rng() % n;\n        // random labelled\
    \ tree via random parent in a random order\n        std::vector<int> perm(n);\n\
    \        for (int i = 0; i < n; i++) perm[i] = i;\n        std::shuffle(perm.begin(),\
    \ perm.end(), rng);\n        std::swap(perm[0], *std::find(perm.begin(), perm.end(),\
    \ root));\n        std::vector<std::vector<int>> ch(n), und(n);\n        for (int\
    \ i = 1; i < n; i++) {\n            int p = perm[rng() % i], v = perm[i];\n  \
    \          ch[p].push_back(v);\n            und[p].push_back(v);\n           \
    \ und[v].push_back(p);\n        }\n        for (auto& l : und) std::shuffle(l.begin(),\
    \ l.end(), rng);\n        std::vector<int> a = subtree_classify(ch, root);\n \
    \       check(a, ch, root);\n        check(subtree_classify(und, root), ch, root);\n\
    \    }\n    {\n        // path of length 2e5: no recursion depth issue\n     \
    \   int n = 200000;\n        std::vector<std::vector<int>> g(n);\n        for\
    \ (int i = 1; i < n; i++) {\n            g[i - 1].push_back(i);\n            g[i].push_back(i\
    \ - 1);\n        }\n        std::vector<int> a = subtree_classify(g);\n      \
    \  for (int i = 0; i < n; i++) assert(a[i] == n - 1 - i);\n    }\n    {\n    \
    \    // star: all leaves in one class\n        int n = 100000;\n        std::vector<std::vector<int>>\
    \ g(n);\n        for (int i = 1; i < n; i++) g[0].push_back(i);\n        std::vector<int>\
    \ a = subtree_classify(g);\n        assert(a[0] == 1);\n        for (int i = 1;\
    \ i < n; i++) assert(a[i] == 0);\n    }\n    {\n        std::vector<int> a = subtree_classify(std::vector<std::vector<int>>(1));\n\
    \        assert((a == std::vector<int>{0}));\n    }\n    std::cout << \"Hello\
    \ World\" << std::endl;\n}\n"
  dependsOn:
  - graph/subtree_classify.hpp
  isVerificationFile: true
  path: test/unit/subtree_classify.test.cpp
  requiredBy: []
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unit/subtree_classify.test.cpp
layout: document
redirect_from:
- /verify/test/unit/subtree_classify.test.cpp
- /verify/test/unit/subtree_classify.test.cpp.html
title: test/unit/subtree_classify.test.cpp
---
