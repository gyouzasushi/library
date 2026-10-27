---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/persistent_array.hpp
    title: Persistent Array
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
  bundledCode: "#line 1 \"test/unit/persistent_array.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <cassert>\n#include <chrono>\n#include <iostream>\n#include <random>\n#include\
    \ <vector>\n\n#line 4 \"datastructure/persistent_array.hpp\"\ntemplate <class\
    \ T> struct persistent_array {\npublic:\n    explicit persistent_array(int n)\
    \ : persistent_array(std::vector<T>(n)) {\n    }\n    explicit persistent_array(const\
    \ std::vector<T>& v) : _n(int(v.size())) {\n        nodes.reserve(2 * _n);\n \
    \       if (_n > 0) build(v, 0, _n);\n    }\n    int size() const {\n        return\
    \ _n;\n    }\n    T get(int root, int p) const {\n        assert(0 <= p && p <\
    \ _n);\n        int cur = root, l = 0, r = _n;\n        while (r - l > 1) {\n\
    \            int mid = (l + r) / 2;\n            if (p < mid) {\n            \
    \    cur = nodes[cur].l, r = mid;\n            } else {\n                cur =\
    \ nodes[cur].r, l = mid;\n            }\n        }\n        return nodes[cur].val;\n\
    \    }\n    int set(int root, int p, const T& x) {\n        assert(0 <= p && p\
    \ < _n);\n        int res = copy(root);\n        int cur = res, l = 0, r = _n;\n\
    \        while (r - l > 1) {\n            int mid = (l + r) / 2;\n           \
    \ if (p < mid) {\n                int nxt = copy(nodes[cur].l);\n            \
    \    nodes[cur].l = nxt;\n                cur = nxt, r = mid;\n            } else\
    \ {\n                int nxt = copy(nodes[cur].r);\n                nodes[cur].r\
    \ = nxt;\n                cur = nxt, l = mid;\n            }\n        }\n    \
    \    nodes[cur].val = x;\n        return res;\n    }\n\nprivate:\n    struct node\
    \ {\n        int l, r;\n        T val;\n    };\n    int _n;\n    std::vector<node>\
    \ nodes;\n    int copy(int v) {\n        nodes.push_back(nodes[v]);\n        return\
    \ int(nodes.size()) - 1;\n    }\n    int build(const std::vector<T>& v, int l,\
    \ int r) {\n        if (r - l == 1) {\n            nodes.push_back({-1, -1, v[l]});\n\
    \            return int(nodes.size()) - 1;\n        }\n        int mid = (l +\
    \ r) / 2;\n        int res = int(nodes.size());\n        nodes.push_back({-1,\
    \ -1, T()});\n        int lc = build(v, l, mid);\n        int rc = build(v, mid,\
    \ r);\n        nodes[res].l = lc, nodes[res].r = rc;\n        return res;\n  \
    \  }\n};\n#line 9 \"test/unit/persistent_array.test.cpp\"\nint main() {\n    std::mt19937_64\
    \ rng(20261027);\n    for (int iter = 0; iter < 300; iter++) {\n        int n\
    \ = 1 + rng() % 20;\n        std::vector<long long> init(n);\n        for (auto&\
    \ x : init) x = rng() % 100;\n        persistent_array<long long> a(init);\n \
    \       std::vector<std::vector<long long>> versions{init};\n        std::vector<int>\
    \ roots{0};\n        assert(a.size() == n);\n        for (int t = 0; t < 60; t++)\
    \ {\n            int k = rng() % roots.size();\n            int p = rng() % n;\n\
    \            long long x = rng() % 100;\n            roots.push_back(a.set(roots[k],\
    \ p, x));\n            std::vector<long long> v = versions[k];\n            v[p]\
    \ = x;\n            versions.push_back(v);\n            int c = rng() % roots.size();\n\
    \            for (int i = 0; i < n; i++) assert(a.get(roots[c], i) == versions[c][i]);\n\
    \        }\n    }\n    {\n        persistent_array<int> a(5);\n        for (int\
    \ i = 0; i < 5; i++) assert(a.get(0, i) == 0);\n        int r1 = a.set(0, 2, 7);\n\
    \        int r2 = a.set(r1, 2, 9);\n        assert(a.get(0, 2) == 0 && a.get(r1,\
    \ 2) == 7 && a.get(r2, 2) == 9);\n    }\n    {\n        int n = 200000, q = 200000;\n\
    \        auto start = std::chrono::steady_clock::now();\n        persistent_array<int>\
    \ a(n);\n        std::vector<int> roots{0};\n        long long acc = 0;\n    \
    \    for (int i = 0; i < q; i++) {\n            int k = rng() % roots.size();\n\
    \            roots.push_back(a.set(roots[k], rng() % n, int(rng() % 1000)));\n\
    \            acc += a.get(roots[rng() % roots.size()], rng() % n);\n        }\n\
    \        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()\
    \ - start).count();\n        std::cerr << \"perf n=q=\" << n << \": \" << ms <<\
    \ \" ms (\" << acc % 1000 << \")\\n\";\n    }\n    std::cout << \"Hello World\\\
    n\";\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <chrono>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\n#include \"datastructure/persistent_array.hpp\"\nint main()\
    \ {\n    std::mt19937_64 rng(20261027);\n    for (int iter = 0; iter < 300; iter++)\
    \ {\n        int n = 1 + rng() % 20;\n        std::vector<long long> init(n);\n\
    \        for (auto& x : init) x = rng() % 100;\n        persistent_array<long\
    \ long> a(init);\n        std::vector<std::vector<long long>> versions{init};\n\
    \        std::vector<int> roots{0};\n        assert(a.size() == n);\n        for\
    \ (int t = 0; t < 60; t++) {\n            int k = rng() % roots.size();\n    \
    \        int p = rng() % n;\n            long long x = rng() % 100;\n        \
    \    roots.push_back(a.set(roots[k], p, x));\n            std::vector<long long>\
    \ v = versions[k];\n            v[p] = x;\n            versions.push_back(v);\n\
    \            int c = rng() % roots.size();\n            for (int i = 0; i < n;\
    \ i++) assert(a.get(roots[c], i) == versions[c][i]);\n        }\n    }\n    {\n\
    \        persistent_array<int> a(5);\n        for (int i = 0; i < 5; i++) assert(a.get(0,\
    \ i) == 0);\n        int r1 = a.set(0, 2, 7);\n        int r2 = a.set(r1, 2, 9);\n\
    \        assert(a.get(0, 2) == 0 && a.get(r1, 2) == 7 && a.get(r2, 2) == 9);\n\
    \    }\n    {\n        int n = 200000, q = 200000;\n        auto start = std::chrono::steady_clock::now();\n\
    \        persistent_array<int> a(n);\n        std::vector<int> roots{0};\n   \
    \     long long acc = 0;\n        for (int i = 0; i < q; i++) {\n            int\
    \ k = rng() % roots.size();\n            roots.push_back(a.set(roots[k], rng()\
    \ % n, int(rng() % 1000)));\n            acc += a.get(roots[rng() % roots.size()],\
    \ rng() % n);\n        }\n        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()\
    \ - start).count();\n        std::cerr << \"perf n=q=\" << n << \": \" << ms <<\
    \ \" ms (\" << acc % 1000 << \")\\n\";\n    }\n    std::cout << \"Hello World\\\
    n\";\n}\n"
  dependsOn:
  - datastructure/persistent_array.hpp
  isVerificationFile: true
  path: test/unit/persistent_array.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 20:36:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/persistent_array.test.cpp
layout: document
redirect_from:
- /verify/test/unit/persistent_array.test.cpp
- /verify/test/unit/persistent_array.test.cpp.html
title: test/unit/persistent_array.test.cpp
---
