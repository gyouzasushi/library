---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/mo.hpp
    title: Mo's Algorithm
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
  bundledCode: "#line 1 \"test/unit/mo.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\n#line 4 \"algorithm/mo.hpp\"\n#include <cmath>\n#include\
    \ <cstdlib>\n#include <numeric>\n#include <utility>\n#line 9 \"algorithm/mo.hpp\"\
    \n\nstruct mo {\n    mo() = default;\n    int add(int l, int r) {\n        assert(0\
    \ <= l && l <= r);\n        lr.emplace_back(l, r);\n        return (int)lr.size()\
    \ - 1;\n    }\n    void run(auto add_left, auto add_right, auto erase_left, auto\
    \ erase_right,\n             auto out) const {\n        int l = 0, r = 0;\n  \
    \      for (int i : order()) {\n            while (l > lr[i].first) add_left(--l);\n\
    \            while (r < lr[i].second) add_right(r++);\n            while (l <\
    \ lr[i].first) erase_left(l++);\n            while (r > lr[i].second) erase_right(--r);\n\
    \            out(i);\n        }\n    }\n    void run(auto add, auto erase, auto\
    \ out) const {\n        run(add, add, erase, erase, out);\n    }\n\n  private:\n\
    \    std::vector<std::pair<int, int>> lr;\n    std::vector<int> order() const\
    \ {\n        int q = lr.size();\n        if (q == 0) return {};\n        int n\
    \ = 1;\n        for (auto [l, r] : lr) n = std::max(n, r);\n        int w = std::max(1,\
    \ (int)(std::sqrt(3.0) * n / std::sqrt(2.0 * q)));\n        std::vector<int> ord(q);\n\
    \        std::iota(ord.begin(), ord.end(), 0);\n        std::sort(ord.begin(),\
    \ ord.end(), [&](int a, int b) {\n            int ba = lr[a].first / w, bb = lr[b].first\
    \ / w;\n            if (ba != bb) return ba < bb;\n            return (ba & 1)\
    \ ? lr[a].second > lr[b].second\n                            : lr[a].second <\
    \ lr[b].second;\n        });\n        auto cost = [&](int a, int b) {\n      \
    \      return std::abs(lr[ord[a]].first - lr[ord[b]].first) +\n              \
    \     std::abs(lr[ord[a]].second - lr[ord[b]].second);\n        };\n        auto\
    \ improve = [&](int k) {\n            if (cost(k, k + 2) + cost(k + 1, k + 3)\
    \ <\n                cost(k, k + 1) + cost(k + 2, k + 3))\n                std::swap(ord[k\
    \ + 1], ord[k + 2]);\n            if (cost(k, k + 3) + cost(k + 1, k + 4) <\n\
    \                cost(k, k + 1) + cost(k + 3, k + 4))\n                std::swap(ord[k\
    \ + 1], ord[k + 3]);\n        };\n        for (int k = 0; k + 5 <= q; k++) improve(k);\n\
    \        for (int k = q - 5; k >= 0; k--) improve(k);\n        return ord;\n \
    \   }\n};\n#line 9 \"test/unit/mo.test.cpp\"\n\nint main() {\n    std::mt19937\
    \ rng(12345);\n    for (int it = 0; it < 300; it++) {\n        int n = rng() %\
    \ 30, q = rng() % 40;\n        std::vector<int> a(n);\n        for (auto& x :\
    \ a) x = rng() % 5;\n        mo m;\n        std::vector<std::pair<int, int>> qs(q);\n\
    \        for (int i = 0; i < q; i++) {\n            int l = rng() % (n + 1), r\
    \ = rng() % (n + 1);\n            if (l > r) std::swap(l, r);\n            qs[i]\
    \ = {l, r};\n            assert(m.add(l, r) == i);\n        }\n        // distinct\
    \ count: symmetric callbacks\n        {\n            std::vector<int> cnt(5),\
    \ ans(q, -1);\n            int distinct = 0;\n            m.run([&](int i) { if\
    \ (cnt[a[i]]++ == 0) distinct++; },\n                  [&](int i) { if (--cnt[a[i]]\
    \ == 0) distinct--; },\n                  [&](int k) { ans[k] = distinct; });\n\
    \            for (int k = 0; k < q; k++) {\n                auto [l, r] = qs[k];\n\
    \                std::vector<int> b(a.begin() + l, a.begin() + r);\n         \
    \       std::sort(b.begin(), b.end());\n                assert(ans[k] == (int)(std::unique(b.begin(),\
    \ b.end()) - b.begin()));\n            }\n            for (int c : cnt) assert(c\
    \ >= 0);\n        }\n        // inversions: left/right differ, and the window\
    \ must satisfy l <= r\n        {\n            std::vector<int> cnt(5), ans(q,\
    \ -1);\n            int size = 0, inv = 0;\n            auto less = [&](int v)\
    \ { int s = 0; for (int u = 0; u < v; u++) s += cnt[u]; return s; };\n       \
    \     auto greater = [&](int v) { int s = 0; for (int u = v + 1; u < 5; u++) s\
    \ += cnt[u]; return s; };\n            m.run([&](int i) { inv += less(a[i]); cnt[a[i]]++;\
    \ size++; },\n                  [&](int i) { inv += greater(a[i]); cnt[a[i]]++;\
    \ size++; },\n                  [&](int i) { cnt[a[i]]--; size--; inv -= less(a[i]);\
    \ assert(size >= 0); },\n                  [&](int i) { cnt[a[i]]--; size--; inv\
    \ -= greater(a[i]); assert(size >= 0); },\n                  [&](int k) { ans[k]\
    \ = inv; });\n            for (int k = 0; k < q; k++) {\n                auto\
    \ [l, r] = qs[k];\n                int e = 0;\n                for (int i = l;\
    \ i < r; i++)\n                    for (int j = i + 1; j < r; j++) e += a[i] >\
    \ a[j];\n                assert(ans[k] == e);\n            }\n        }\n    }\n\
    \    // no queries\n    {\n        mo m;\n        int calls = 0;\n        auto\
    \ f = [&](int) { calls++; };\n        m.run(f, f, f);\n        assert(calls ==\
    \ 0);\n    }\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\n#include \"algorithm/mo.hpp\"\n\nint main() {\n    std::mt19937\
    \ rng(12345);\n    for (int it = 0; it < 300; it++) {\n        int n = rng() %\
    \ 30, q = rng() % 40;\n        std::vector<int> a(n);\n        for (auto& x :\
    \ a) x = rng() % 5;\n        mo m;\n        std::vector<std::pair<int, int>> qs(q);\n\
    \        for (int i = 0; i < q; i++) {\n            int l = rng() % (n + 1), r\
    \ = rng() % (n + 1);\n            if (l > r) std::swap(l, r);\n            qs[i]\
    \ = {l, r};\n            assert(m.add(l, r) == i);\n        }\n        // distinct\
    \ count: symmetric callbacks\n        {\n            std::vector<int> cnt(5),\
    \ ans(q, -1);\n            int distinct = 0;\n            m.run([&](int i) { if\
    \ (cnt[a[i]]++ == 0) distinct++; },\n                  [&](int i) { if (--cnt[a[i]]\
    \ == 0) distinct--; },\n                  [&](int k) { ans[k] = distinct; });\n\
    \            for (int k = 0; k < q; k++) {\n                auto [l, r] = qs[k];\n\
    \                std::vector<int> b(a.begin() + l, a.begin() + r);\n         \
    \       std::sort(b.begin(), b.end());\n                assert(ans[k] == (int)(std::unique(b.begin(),\
    \ b.end()) - b.begin()));\n            }\n            for (int c : cnt) assert(c\
    \ >= 0);\n        }\n        // inversions: left/right differ, and the window\
    \ must satisfy l <= r\n        {\n            std::vector<int> cnt(5), ans(q,\
    \ -1);\n            int size = 0, inv = 0;\n            auto less = [&](int v)\
    \ { int s = 0; for (int u = 0; u < v; u++) s += cnt[u]; return s; };\n       \
    \     auto greater = [&](int v) { int s = 0; for (int u = v + 1; u < 5; u++) s\
    \ += cnt[u]; return s; };\n            m.run([&](int i) { inv += less(a[i]); cnt[a[i]]++;\
    \ size++; },\n                  [&](int i) { inv += greater(a[i]); cnt[a[i]]++;\
    \ size++; },\n                  [&](int i) { cnt[a[i]]--; size--; inv -= less(a[i]);\
    \ assert(size >= 0); },\n                  [&](int i) { cnt[a[i]]--; size--; inv\
    \ -= greater(a[i]); assert(size >= 0); },\n                  [&](int k) { ans[k]\
    \ = inv; });\n            for (int k = 0; k < q; k++) {\n                auto\
    \ [l, r] = qs[k];\n                int e = 0;\n                for (int i = l;\
    \ i < r; i++)\n                    for (int j = i + 1; j < r; j++) e += a[i] >\
    \ a[j];\n                assert(ans[k] == e);\n            }\n        }\n    }\n\
    \    // no queries\n    {\n        mo m;\n        int calls = 0;\n        auto\
    \ f = [&](int) { calls++; };\n        m.run(f, f, f);\n        assert(calls ==\
    \ 0);\n    }\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - algorithm/mo.hpp
  isVerificationFile: true
  path: test/unit/mo.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 21:19:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/mo.test.cpp
layout: document
redirect_from:
- /verify/test/unit/mo.test.cpp
- /verify/test/unit/mo.test.cpp.html
title: test/unit/mo.test.cpp
---
