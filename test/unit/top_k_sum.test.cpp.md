---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/top_k_sum.hpp
    title: Top K Sum
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
  bundledCode: "#line 1 \"test/unit/top_k_sum.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <chrono>\n#include <functional>\n\
    #include <iostream>\n#include <random>\n#include <vector>\n\n#line 4 \"datastructure/top_k_sum.hpp\"\
    \n#include <queue>\n#line 6 \"datastructure/top_k_sum.hpp\"\ntemplate <class T,\
    \ class Compare = std::greater<T>>\nstruct top_k_sum {\npublic:\n    explicit\
    \ top_k_sum(int k) : _k(k), _sum(T()) {\n        assert(k >= 0);\n    }\n    void\
    \ insert(const T& x) {\n        in.push(x);\n        _sum += x;\n        modify();\n\
    \    }\n    void erase(const T& x) {\n        assert(size() > 0);\n        if\
    \ (!in.empty() && in.top() == x) {\n            _sum -= x;\n            in.pop();\n\
    \        } else if (!in.empty() && Compare()(x, in.top())) {\n            _sum\
    \ -= x;\n            d_in.push(x);\n        } else {\n            d_out.push(x);\n\
    \        }\n        modify();\n    }\n    void set_k(int k) {\n        assert(k\
    \ >= 0);\n        _k = k;\n        modify();\n    }\n    int k() const {\n   \
    \     return _k;\n    }\n    T sum() const {\n        return _sum;\n    }\n  \
    \  int size() const {\n        return int(in.size() + out.size() - d_in.size()\
    \ - d_out.size());\n    }\n\nprivate:\n    struct reverse_compare {\n        bool\
    \ operator()(const T& a, const T& b) const {\n            return Compare()(b,\
    \ a);\n        }\n    };\n    std::priority_queue<T, std::vector<T>, Compare>\
    \ in, d_in;\n    std::priority_queue<T, std::vector<T>, reverse_compare> out,\
    \ d_out;\n    int _k;\n    T _sum;\n    int in_size() const {\n        return\
    \ int(in.size() - d_in.size());\n    }\n    void modify() {\n        while (in_size()\
    \ < _k && !out.empty()) {\n            T p = out.top();\n            out.pop();\n\
    \            if (!d_out.empty() && p == d_out.top()) {\n                d_out.pop();\n\
    \            } else {\n                _sum += p;\n                in.push(p);\n\
    \            }\n        }\n        while (in_size() > _k) {\n            T p =\
    \ in.top();\n            in.pop();\n            if (!d_in.empty() && p == d_in.top())\
    \ {\n                d_in.pop();\n            } else {\n                _sum -=\
    \ p;\n                out.push(p);\n            }\n        }\n        while (!d_in.empty()\
    \ && in.top() == d_in.top()) {\n            in.pop();\n            d_in.pop();\n\
    \        }\n    }\n};\n#line 11 \"test/unit/top_k_sum.test.cpp\"\ntemplate <class\
    \ Compare>\nvoid check(std::mt19937_64& rng, int iters, int ops, int vals) {\n\
    \    for (int iter = 0; iter < iters; iter++) {\n        int k = rng() % 6;\n\
    \        top_k_sum<long long, Compare> s(k);\n        std::vector<long long> v;\n\
    \        for (int t = 0; t < ops; t++) {\n            int c = rng() % 4;\n   \
    \         if (c == 0 || v.empty()) {\n                long long x = rng() % vals;\n\
    \                s.insert(x);\n                v.push_back(x);\n            }\
    \ else if (c == 1) {\n                int i = rng() % v.size();\n            \
    \    s.erase(v[i]);\n                v.erase(v.begin() + i);\n            } else\
    \ if (c == 2) {\n                k = rng() % 6;\n                s.set_k(k);\n\
    \            }\n            std::vector<long long> w = v;\n            std::sort(w.begin(),\
    \ w.end(), Compare());\n            long long expect = 0;\n            for (int\
    \ i = 0; i < std::min<int>(k, w.size()); i++) expect += w[i];\n            assert(s.size()\
    \ == int(v.size()));\n            assert(s.k() == k);\n            assert(s.sum()\
    \ == expect);\n        }\n    }\n}\nint main() {\n    std::mt19937_64 rng(20261027);\n\
    \    check<std::greater<long long>>(rng, 300, 60, 5);\n    check<std::greater<long\
    \ long>>(rng, 300, 60, 1000);\n    check<std::less<long long>>(rng, 300, 60, 5);\n\
    \    check<std::less<long long>>(rng, 300, 60, 1000);\n    {\n        // k = 0\
    \ \u3068 k > size\n        top_k_sum<int> s(0);\n        s.insert(5);\n      \
    \  assert(s.sum() == 0);\n        s.set_k(10);\n        assert(s.sum() == 5);\n\
    \        s.erase(5);\n        assert(s.sum() == 0 && s.size() == 0);\n    }\n\
    \    {\n        int n = 200000;\n        auto start = std::chrono::steady_clock::now();\n\
    \        top_k_sum<long long> s(n / 2);\n        std::vector<long long> v(n);\n\
    \        for (int i = 0; i < n; i++) {\n            v[i] = rng() % 1000000000;\n\
    \            s.insert(v[i]);\n        }\n        long long acc = 0;\n        for\
    \ (int i = 0; i < n; i++) {\n            s.erase(v[i]);\n            v[i] = rng()\
    \ % 1000000000;\n            s.insert(v[i]);\n            s.set_k(s.k() + (i %\
    \ 2 ? 1 : -1));\n            acc = (acc + s.sum()) % 1000000007;\n        }\n\
    \        std::vector<long long> w = v;\n        std::sort(w.begin(), w.end(),\
    \ std::greater<long long>());\n        long long expect = 0;\n        for (int\
    \ i = 0; i < s.k(); i++) expect += w[i];\n        assert(s.sum() == expect);\n\
    \        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()\
    \ - start).count();\n        std::cerr << \"perf \" << n << \" ops: \" << ms <<\
    \ \" ms (\" << acc % 1000 << \")\\n\";\n    }\n    std::cout << \"Hello World\\\
    n\";\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <chrono>\n#include <functional>\n\
    #include <iostream>\n#include <random>\n#include <vector>\n\n#include \"datastructure/top_k_sum.hpp\"\
    \ntemplate <class Compare>\nvoid check(std::mt19937_64& rng, int iters, int ops,\
    \ int vals) {\n    for (int iter = 0; iter < iters; iter++) {\n        int k =\
    \ rng() % 6;\n        top_k_sum<long long, Compare> s(k);\n        std::vector<long\
    \ long> v;\n        for (int t = 0; t < ops; t++) {\n            int c = rng()\
    \ % 4;\n            if (c == 0 || v.empty()) {\n                long long x =\
    \ rng() % vals;\n                s.insert(x);\n                v.push_back(x);\n\
    \            } else if (c == 1) {\n                int i = rng() % v.size();\n\
    \                s.erase(v[i]);\n                v.erase(v.begin() + i);\n   \
    \         } else if (c == 2) {\n                k = rng() % 6;\n             \
    \   s.set_k(k);\n            }\n            std::vector<long long> w = v;\n  \
    \          std::sort(w.begin(), w.end(), Compare());\n            long long expect\
    \ = 0;\n            for (int i = 0; i < std::min<int>(k, w.size()); i++) expect\
    \ += w[i];\n            assert(s.size() == int(v.size()));\n            assert(s.k()\
    \ == k);\n            assert(s.sum() == expect);\n        }\n    }\n}\nint main()\
    \ {\n    std::mt19937_64 rng(20261027);\n    check<std::greater<long long>>(rng,\
    \ 300, 60, 5);\n    check<std::greater<long long>>(rng, 300, 60, 1000);\n    check<std::less<long\
    \ long>>(rng, 300, 60, 5);\n    check<std::less<long long>>(rng, 300, 60, 1000);\n\
    \    {\n        // k = 0 \u3068 k > size\n        top_k_sum<int> s(0);\n     \
    \   s.insert(5);\n        assert(s.sum() == 0);\n        s.set_k(10);\n      \
    \  assert(s.sum() == 5);\n        s.erase(5);\n        assert(s.sum() == 0 &&\
    \ s.size() == 0);\n    }\n    {\n        int n = 200000;\n        auto start =\
    \ std::chrono::steady_clock::now();\n        top_k_sum<long long> s(n / 2);\n\
    \        std::vector<long long> v(n);\n        for (int i = 0; i < n; i++) {\n\
    \            v[i] = rng() % 1000000000;\n            s.insert(v[i]);\n       \
    \ }\n        long long acc = 0;\n        for (int i = 0; i < n; i++) {\n     \
    \       s.erase(v[i]);\n            v[i] = rng() % 1000000000;\n            s.insert(v[i]);\n\
    \            s.set_k(s.k() + (i % 2 ? 1 : -1));\n            acc = (acc + s.sum())\
    \ % 1000000007;\n        }\n        std::vector<long long> w = v;\n        std::sort(w.begin(),\
    \ w.end(), std::greater<long long>());\n        long long expect = 0;\n      \
    \  for (int i = 0; i < s.k(); i++) expect += w[i];\n        assert(s.sum() ==\
    \ expect);\n        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()\
    \ - start).count();\n        std::cerr << \"perf \" << n << \" ops: \" << ms <<\
    \ \" ms (\" << acc % 1000 << \")\\n\";\n    }\n    std::cout << \"Hello World\\\
    n\";\n}\n"
  dependsOn:
  - datastructure/top_k_sum.hpp
  isVerificationFile: true
  path: test/unit/top_k_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 20:36:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/top_k_sum.test.cpp
layout: document
redirect_from:
- /verify/test/unit/top_k_sum.test.cpp
- /verify/test/unit/top_k_sum.test.cpp.html
title: test/unit/top_k_sum.test.cpp
---
