---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/range_set.hpp
    title: Range Set
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
  bundledCode: "#line 1 \"test/unit/range_set.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \n#line 3 \"datastructure/range_set.hpp\"\n#include <map>\ntemplate <class T>\n\
    struct range_set {\npublic:\n    using iterator = typename std::map<T, T>::const_iterator;\n\
    \    range_set() {\n    }\n    // p \u3092\u542B\u3080\u533A\u9593\u3002\u7121\
    \u3051\u308C\u3070 end()\n    iterator find(T p) const {\n        auto it = ranges.upper_bound(p);\n\
    \        if (it == ranges.begin()) return ranges.end();\n        it--;\n     \
    \   if (it->second <= p) return ranges.end();\n        return it;\n    }\n   \
    \ bool contains(T p) const {\n        return find(p) != ranges.end();\n    }\n\
    \    // [l, r) \u304C 1 \u3064\u306E\u533A\u9593\u306B\u542B\u307E\u308C\u308B\
    \u304B\n    bool covers(T l, T r) const {\n        assert(l < r);\n        auto\
    \ it = find(l);\n        return it != ranges.end() && r <= it->second;\n    }\n\
    \    // x \u4EE5\u4E0A\u3067\u542B\u307E\u308C\u306A\u3044\u6700\u5C0F\u306E\u5024\
    \uFF08\u6574\u6570\u5411\u3051\uFF09\n    T mex(T x) const {\n        auto it\
    \ = find(x);\n        return it == ranges.end() ? x : it->second;\n    }\n   \
    \ void insert(T l, T r) {\n        insert(l, r, [](T, T) {}, [](T, T) {});\n \
    \   }\n    // f: \u8FFD\u52A0\u3055\u308C\u305F\u533A\u9593\u3054\u3068\u306B\u547C\
    \u3076, g: \u524A\u9664\u3055\u308C\u305F\u533A\u9593\u3054\u3068\u306B\u547C\u3076\
    \n    template <class F, class G>\n    void insert(T l, T r, const F& f, const\
    \ G& g) {\n        assert(l < r);\n        auto it = ranges.upper_bound(l);\n\
    \        if (it != ranges.begin() && l <= std::prev(it)->second) it--;\n     \
    \   while (it != ranges.end() && it->first <= r) {\n            l = std::min(l,\
    \ it->first);\n            r = std::max(r, it->second);\n            g(it->first,\
    \ it->second);\n            it = ranges.erase(it);\n        }\n        ranges[l]\
    \ = r;\n        f(l, r);\n    }\n    void erase(T l, T r) {\n        erase(l,\
    \ r, [](T, T) {}, [](T, T) {});\n    }\n    template <class F, class G>\n    void\
    \ erase(T l, T r, const F& f, const G& g) {\n        assert(l < r);\n        auto\
    \ it = ranges.upper_bound(l);\n        if (it != ranges.begin() && l < std::prev(it)->second)\
    \ it--;\n        while (it != ranges.end() && it->first < r) {\n            T\
    \ a = it->first, b = it->second;\n            g(a, b);\n            it = ranges.erase(it);\n\
    \            if (a < l) {\n                ranges[a] = l;\n                f(a,\
    \ l);\n            }\n            if (r < b) {\n                ranges[r] = b;\n\
    \                f(r, b);\n            }\n        }\n    }\n    int size() const\
    \ {\n        return int(ranges.size());\n    }\n    iterator begin() const {\n\
    \        return ranges.begin();\n    }\n    iterator end() const {\n        return\
    \ ranges.end();\n    }\n\nprivate:\n    std::map<T, T> ranges;\n};\n#line 8 \"\
    test/unit/range_set.test.cpp\"\nvoid stress(std::mt19937& rng) {\n    const int\
    \ U = 1 + rng() % 30;\n    std::vector<bool> a(U, false);\n    range_set<int>\
    \ st;\n    long long len = 0;  // \u30B3\u30FC\u30EB\u30D0\u30C3\u30AF\u3067\u7BA1\
    \u7406\u3059\u308B\u88AB\u8986\u9577\n    auto f = [&](int l, int r) { len +=\
    \ r - l; };\n    auto g = [&](int l, int r) { len -= r - l; };\n    for (int it\
    \ = 0; it < 200; it++) {\n        int l = rng() % U, r = rng() % U;\n        if\
    \ (l > r) std::swap(l, r);\n        r++;\n        if (rng() % 2) {\n         \
    \   st.insert(l, r, f, g);\n            for (int i = l; i < r; i++) a[i] = true;\n\
    \        } else {\n            st.erase(l, r, f, g);\n            for (int i =\
    \ l; i < r; i++) a[i] = false;\n        }\n        // contains, mex\n        long\
    \ long naive_len = 0;\n        for (int p = 0; p < U; p++) {\n            assert(st.contains(p)\
    \ == a[p]);\n            naive_len += a[p];\n            int m = p;\n        \
    \    while (m < U && a[m]) m++;\n            assert(st.mex(p) == m);\n       \
    \ }\n        assert(len == naive_len);\n        // size: \u6975\u5927\u306A\u9023\
    \u7D9A\u533A\u9593\u306E\u500B\u6570\n        int runs = 0;\n        for (int\
    \ p = 0; p < U; p++) runs += a[p] && (p == 0 || !a[p - 1]);\n        assert(st.size()\
    \ == runs);\n        // \u5217\u6319: \u6607\u9806\u30FB\u4E92\u3044\u306B\u96E2\
    \u308C\u3066\u3044\u308B\u30FB\u4E2D\u8EAB\u304C\u4E00\u81F4\n        int prev_r\
    \ = -1;\n        for (auto [x, y] : st) {\n            assert(x < y);\n      \
    \      assert(prev_r < x);\n            for (int p = x; p < y; p++) assert(a[p]);\n\
    \            prev_r = y;\n        }\n        // covers, find\n        int ql =\
    \ rng() % U, qr = rng() % U;\n        if (ql > qr) std::swap(ql, qr);\n      \
    \  qr++;\n        bool cov = true;\n        for (int p = ql; p < qr; p++) cov\
    \ &= a[p];\n        assert(st.covers(ql, qr) == cov);\n        auto fi = st.find(ql);\n\
    \        if (a[ql]) {\n            assert(fi != st.end() && fi->first <= ql &&\
    \ ql < fi->second);\n        } else {\n            assert(fi == st.end());\n \
    \       }\n    }\n}\nint main() {\n    std::mt19937 rng(7959);\n    for (int trial\
    \ = 0; trial < 300; trial++) stress(rng);\n    std::cout << \"Hello World\" <<\
    \ std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \n#include \"datastructure/range_set.hpp\"\nvoid stress(std::mt19937& rng) {\n\
    \    const int U = 1 + rng() % 30;\n    std::vector<bool> a(U, false);\n    range_set<int>\
    \ st;\n    long long len = 0;  // \u30B3\u30FC\u30EB\u30D0\u30C3\u30AF\u3067\u7BA1\
    \u7406\u3059\u308B\u88AB\u8986\u9577\n    auto f = [&](int l, int r) { len +=\
    \ r - l; };\n    auto g = [&](int l, int r) { len -= r - l; };\n    for (int it\
    \ = 0; it < 200; it++) {\n        int l = rng() % U, r = rng() % U;\n        if\
    \ (l > r) std::swap(l, r);\n        r++;\n        if (rng() % 2) {\n         \
    \   st.insert(l, r, f, g);\n            for (int i = l; i < r; i++) a[i] = true;\n\
    \        } else {\n            st.erase(l, r, f, g);\n            for (int i =\
    \ l; i < r; i++) a[i] = false;\n        }\n        // contains, mex\n        long\
    \ long naive_len = 0;\n        for (int p = 0; p < U; p++) {\n            assert(st.contains(p)\
    \ == a[p]);\n            naive_len += a[p];\n            int m = p;\n        \
    \    while (m < U && a[m]) m++;\n            assert(st.mex(p) == m);\n       \
    \ }\n        assert(len == naive_len);\n        // size: \u6975\u5927\u306A\u9023\
    \u7D9A\u533A\u9593\u306E\u500B\u6570\n        int runs = 0;\n        for (int\
    \ p = 0; p < U; p++) runs += a[p] && (p == 0 || !a[p - 1]);\n        assert(st.size()\
    \ == runs);\n        // \u5217\u6319: \u6607\u9806\u30FB\u4E92\u3044\u306B\u96E2\
    \u308C\u3066\u3044\u308B\u30FB\u4E2D\u8EAB\u304C\u4E00\u81F4\n        int prev_r\
    \ = -1;\n        for (auto [x, y] : st) {\n            assert(x < y);\n      \
    \      assert(prev_r < x);\n            for (int p = x; p < y; p++) assert(a[p]);\n\
    \            prev_r = y;\n        }\n        // covers, find\n        int ql =\
    \ rng() % U, qr = rng() % U;\n        if (ql > qr) std::swap(ql, qr);\n      \
    \  qr++;\n        bool cov = true;\n        for (int p = ql; p < qr; p++) cov\
    \ &= a[p];\n        assert(st.covers(ql, qr) == cov);\n        auto fi = st.find(ql);\n\
    \        if (a[ql]) {\n            assert(fi != st.end() && fi->first <= ql &&\
    \ ql < fi->second);\n        } else {\n            assert(fi == st.end());\n \
    \       }\n    }\n}\nint main() {\n    std::mt19937 rng(7959);\n    for (int trial\
    \ = 0; trial < 300; trial++) stress(rng);\n    std::cout << \"Hello World\" <<\
    \ std::endl;\n    return 0;\n}\n"
  dependsOn:
  - datastructure/range_set.hpp
  isVerificationFile: true
  path: test/unit/range_set.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 20:56:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/range_set.test.cpp
layout: document
redirect_from:
- /verify/test/unit/range_set.test.cpp
- /verify/test/unit/range_set.test.cpp.html
title: test/unit/range_set.test.cpp
---
