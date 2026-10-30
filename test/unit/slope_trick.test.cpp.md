---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/slope_trick.hpp
    title: Slope Trick
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
  bundledCode: "#line 1 \"test/unit/slope_trick.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <optional>\n\
    #include <random>\n#include <vector>\n\n#line 4 \"datastructure/slope_trick.hpp\"\
    \n#include <functional>\n#line 6 \"datastructure/slope_trick.hpp\"\n#include <utility>\n\
    #line 8 \"datastructure/slope_trick.hpp\"\n\ntemplate <class T> struct slope_trick\
    \ {\n    slope_trick() : min_f(0), add_l(0), add_r(0) {}\n    T min() const {\
    \ return min_f; }\n    std::pair<std::optional<T>, std::optional<T>> argmin()\
    \ const {\n        std::optional<T> l, r;\n        if (!L.empty()) l = L.front()\
    \ + add_l;\n        if (!R.empty()) r = R.front() + add_r;\n        return {l,\
    \ r};\n    }\n    void add(T a) { min_f += a; }\n    void add_x_minus_a(T a) {\n\
    \        if (!L.empty()) min_f += std::max<T>(0, L.front() + add_l - a);\n   \
    \     push_l(a);\n        push_r(pop_l());\n    }\n    void add_a_minus_x(T a)\
    \ {\n        if (!R.empty()) min_f += std::max<T>(0, a - (R.front() + add_r));\n\
    \        push_r(a);\n        push_l(pop_r());\n    }\n    void add_abs(T a) {\n\
    \        add_x_minus_a(a);\n        add_a_minus_x(a);\n    }\n    void prefix_min()\
    \ {\n        R.clear();\n        add_r = 0;\n    }\n    void suffix_min() {\n\
    \        L.clear();\n        add_l = 0;\n    }\n    void shift(T a) { shift(a,\
    \ a); }\n    void shift(T a, T b) {\n        assert(a <= b);\n        add_l +=\
    \ a;\n        add_r += b;\n    }\n    void merge(slope_trick& g) {\n        if\
    \ (L.size() + R.size() < g.L.size() + g.R.size()) std::swap(*this, g);\n     \
    \   min_f += g.min_f;\n        for (T l : g.L) add_a_minus_x(l + g.add_l);\n \
    \       for (T r : g.R) add_x_minus_a(r + g.add_r);\n        g = slope_trick();\n\
    \    }\n    T operator()(T x) const {\n        T res = min_f;\n        for (T\
    \ l : L) res += std::max<T>(0, l + add_l - x);\n        for (T r : R) res += std::max<T>(0,\
    \ x - (r + add_r));\n        return res;\n    }\n\n  private:\n    T min_f, add_l,\
    \ add_r;\n    std::vector<T> L, R;\n    void push_l(T a) {\n        L.push_back(a\
    \ - add_l);\n        std::push_heap(L.begin(), L.end());\n    }\n    void push_r(T\
    \ a) {\n        R.push_back(a - add_r);\n        std::push_heap(R.begin(), R.end(),\
    \ std::greater<T>());\n    }\n    T pop_l() {\n        std::pop_heap(L.begin(),\
    \ L.end());\n        T a = L.back() + add_l;\n        L.pop_back();\n        return\
    \ a;\n    }\n    T pop_r() {\n        std::pop_heap(R.begin(), R.end(), std::greater<T>());\n\
    \        T a = R.back() + add_r;\n        R.pop_back();\n        return a;\n \
    \   }\n};\n#line 10 \"test/unit/slope_trick.test.cpp\"\n\nconstexpr int B = 400;\n\
    constexpr int W = 50;\nstruct brute {\n    std::vector<long long> f;\n    brute()\
    \ : f(2 * B + 1, 0) {}\n    long long& at(long long x) { return f[x + B]; }\n\
    \    long long at(long long x) const { return f[x + B]; }\n    void add(long long\
    \ a) {\n        for (long long& v : f) v += a;\n    }\n    void add_x_minus_a(long\
    \ long a) {\n        for (int x = -B; x <= B; x++) at(x) += std::max<long long>(0,\
    \ x - a);\n    }\n    void add_a_minus_x(long long a) {\n        for (int x =\
    \ -B; x <= B; x++) at(x) += std::max<long long>(0, a - x);\n    }\n    void prefix_min()\
    \ {\n        for (int x = -B + 1; x <= B; x++) at(x) = std::min(at(x), at(x -\
    \ 1));\n    }\n    void suffix_min() {\n        for (int x = B - 1; x >= -B; x--)\
    \ at(x) = std::min(at(x), at(x + 1));\n    }\n    void shift(long long a, long\
    \ long b) {\n        std::vector<long long> g(2 * B + 1);\n        for (int x\
    \ = -B; x <= B; x++) {\n            long long best = at(std::clamp<long long>(x\
    \ - a, -B, B));\n            for (long long y = std::max<long long>(-B, x - b);\
    \ y <= std::min<long long>(B, x - a); y++)\n                best = std::min(best,\
    \ at(y));\n            g[x + B] = best;\n        }\n        f = g;\n    }\n  \
    \  long long min() const { return *std::min_element(f.begin(), f.end()); }\n \
    \   std::pair<std::optional<long long>, std::optional<long long>> argmin() const\
    \ {\n        long long m = min();\n        int l = -B, r = B;\n        while (at(l)\
    \ != m) l++;\n        while (at(r) != m) r--;\n        std::optional<long long>\
    \ ol, orr;\n        if (l != -B) ol = l;\n        if (r != B) orr = r;\n     \
    \   return {ol, orr};\n    }\n};\nvoid random_ops(std::mt19937& rng, slope_trick<long\
    \ long>& st, brute& br, int ops, long long& shifted) {\n    for (int t = 0; t\
    \ < ops; t++) {\n        int c = rng() % 7;\n        long long a = (long long)(rng()\
    \ % 21) - 10;\n        if (c == 0) {\n            st.add(a);\n            br.add(a);\n\
    \        } else if (c == 1) {\n            st.add_x_minus_a(a);\n            br.add_x_minus_a(a);\n\
    \        } else if (c == 2) {\n            st.add_a_minus_x(a);\n            br.add_a_minus_x(a);\n\
    \        } else if (c == 3) {\n            st.add_abs(a);\n            br.add_x_minus_a(a);\n\
    \            br.add_a_minus_x(a);\n        } else if (c == 4) {\n            st.prefix_min();\n\
    \            br.prefix_min();\n        } else if (c == 5) {\n            st.suffix_min();\n\
    \            br.suffix_min();\n        } else {\n            long long b = (long\
    \ long)(rng() % 11) - 5;\n            long long d = rng() % 6;\n            if\
    \ (rng() % 2) {\n                st.shift(b);\n                br.shift(b, b);\n\
    \                shifted += std::abs(b);\n            } else {\n             \
    \   st.shift(b, b + d);\n                br.shift(b, b + d);\n               \
    \ shifted += std::abs(b) + d;\n            }\n        }\n    }\n}\nvoid check(const\
    \ slope_trick<long long>& st, const brute& br, long long shifted) {\n    assert(shifted\
    \ < B - W);\n    assert(st.min() == br.min());\n    assert(st.argmin() == br.argmin());\n\
    \    for (int x = -W; x <= W; x++) assert(st(x) == br.at(x));\n}\nint main() {\n\
    \    std::mt19937 rng(20261030);\n    for (int it = 0; it < 3000; it++) {\n  \
    \      slope_trick<long long> st;\n        brute br;\n        long long shifted\
    \ = 0;\n        int ops = rng() % 25;\n        for (int t = 0; t < ops; t++) {\n\
    \            random_ops(rng, st, br, 1, shifted);\n            check(st, br, shifted);\n\
    \        }\n    }\n    for (int it = 0; it < 2000; it++) {\n        slope_trick<long\
    \ long> f, g;\n        brute bf, bg;\n        long long shifted = 0;\n       \
    \ random_ops(rng, f, bf, rng() % 12, shifted);\n        random_ops(rng, g, bg,\
    \ rng() % 12, shifted);\n        f.merge(g);\n        for (int x = -B; x <= B;\
    \ x++) bf.at(x) += bg.at(x);\n        check(f, bf, shifted);\n        assert(g.min()\
    \ == 0);\n        assert(!g.argmin().first && !g.argmin().second);\n        assert(g(7)\
    \ == 0);\n    }\n    {\n        slope_trick<long long> f;\n        assert(f.min()\
    \ == 0);\n        assert(!f.argmin().first && !f.argmin().second);\n        f.add_x_minus_a(3);\n\
    \        assert(f.argmin() == std::make_pair(std::optional<long long>(), std::optional<long\
    \ long>(3)));\n        f.add_a_minus_x(-2);\n        assert(f.argmin() == std::make_pair(std::optional<long\
    \ long>(-2), std::optional<long long>(3)));\n        f.add_abs(10);\n        assert(f.min()\
    \ == 7);\n        assert(f.argmin() == std::make_pair(std::optional<long long>(3),\
    \ std::optional<long long>(10)));\n    }\n    std::cout << \"Hello World\" <<\
    \ std::endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <optional>\n\
    #include <random>\n#include <vector>\n\n#include \"datastructure/slope_trick.hpp\"\
    \n\nconstexpr int B = 400;\nconstexpr int W = 50;\nstruct brute {\n    std::vector<long\
    \ long> f;\n    brute() : f(2 * B + 1, 0) {}\n    long long& at(long long x) {\
    \ return f[x + B]; }\n    long long at(long long x) const { return f[x + B]; }\n\
    \    void add(long long a) {\n        for (long long& v : f) v += a;\n    }\n\
    \    void add_x_minus_a(long long a) {\n        for (int x = -B; x <= B; x++)\
    \ at(x) += std::max<long long>(0, x - a);\n    }\n    void add_a_minus_x(long\
    \ long a) {\n        for (int x = -B; x <= B; x++) at(x) += std::max<long long>(0,\
    \ a - x);\n    }\n    void prefix_min() {\n        for (int x = -B + 1; x <= B;\
    \ x++) at(x) = std::min(at(x), at(x - 1));\n    }\n    void suffix_min() {\n \
    \       for (int x = B - 1; x >= -B; x--) at(x) = std::min(at(x), at(x + 1));\n\
    \    }\n    void shift(long long a, long long b) {\n        std::vector<long long>\
    \ g(2 * B + 1);\n        for (int x = -B; x <= B; x++) {\n            long long\
    \ best = at(std::clamp<long long>(x - a, -B, B));\n            for (long long\
    \ y = std::max<long long>(-B, x - b); y <= std::min<long long>(B, x - a); y++)\n\
    \                best = std::min(best, at(y));\n            g[x + B] = best;\n\
    \        }\n        f = g;\n    }\n    long long min() const { return *std::min_element(f.begin(),\
    \ f.end()); }\n    std::pair<std::optional<long long>, std::optional<long long>>\
    \ argmin() const {\n        long long m = min();\n        int l = -B, r = B;\n\
    \        while (at(l) != m) l++;\n        while (at(r) != m) r--;\n        std::optional<long\
    \ long> ol, orr;\n        if (l != -B) ol = l;\n        if (r != B) orr = r;\n\
    \        return {ol, orr};\n    }\n};\nvoid random_ops(std::mt19937& rng, slope_trick<long\
    \ long>& st, brute& br, int ops, long long& shifted) {\n    for (int t = 0; t\
    \ < ops; t++) {\n        int c = rng() % 7;\n        long long a = (long long)(rng()\
    \ % 21) - 10;\n        if (c == 0) {\n            st.add(a);\n            br.add(a);\n\
    \        } else if (c == 1) {\n            st.add_x_minus_a(a);\n            br.add_x_minus_a(a);\n\
    \        } else if (c == 2) {\n            st.add_a_minus_x(a);\n            br.add_a_minus_x(a);\n\
    \        } else if (c == 3) {\n            st.add_abs(a);\n            br.add_x_minus_a(a);\n\
    \            br.add_a_minus_x(a);\n        } else if (c == 4) {\n            st.prefix_min();\n\
    \            br.prefix_min();\n        } else if (c == 5) {\n            st.suffix_min();\n\
    \            br.suffix_min();\n        } else {\n            long long b = (long\
    \ long)(rng() % 11) - 5;\n            long long d = rng() % 6;\n            if\
    \ (rng() % 2) {\n                st.shift(b);\n                br.shift(b, b);\n\
    \                shifted += std::abs(b);\n            } else {\n             \
    \   st.shift(b, b + d);\n                br.shift(b, b + d);\n               \
    \ shifted += std::abs(b) + d;\n            }\n        }\n    }\n}\nvoid check(const\
    \ slope_trick<long long>& st, const brute& br, long long shifted) {\n    assert(shifted\
    \ < B - W);\n    assert(st.min() == br.min());\n    assert(st.argmin() == br.argmin());\n\
    \    for (int x = -W; x <= W; x++) assert(st(x) == br.at(x));\n}\nint main() {\n\
    \    std::mt19937 rng(20261030);\n    for (int it = 0; it < 3000; it++) {\n  \
    \      slope_trick<long long> st;\n        brute br;\n        long long shifted\
    \ = 0;\n        int ops = rng() % 25;\n        for (int t = 0; t < ops; t++) {\n\
    \            random_ops(rng, st, br, 1, shifted);\n            check(st, br, shifted);\n\
    \        }\n    }\n    for (int it = 0; it < 2000; it++) {\n        slope_trick<long\
    \ long> f, g;\n        brute bf, bg;\n        long long shifted = 0;\n       \
    \ random_ops(rng, f, bf, rng() % 12, shifted);\n        random_ops(rng, g, bg,\
    \ rng() % 12, shifted);\n        f.merge(g);\n        for (int x = -B; x <= B;\
    \ x++) bf.at(x) += bg.at(x);\n        check(f, bf, shifted);\n        assert(g.min()\
    \ == 0);\n        assert(!g.argmin().first && !g.argmin().second);\n        assert(g(7)\
    \ == 0);\n    }\n    {\n        slope_trick<long long> f;\n        assert(f.min()\
    \ == 0);\n        assert(!f.argmin().first && !f.argmin().second);\n        f.add_x_minus_a(3);\n\
    \        assert(f.argmin() == std::make_pair(std::optional<long long>(), std::optional<long\
    \ long>(3)));\n        f.add_a_minus_x(-2);\n        assert(f.argmin() == std::make_pair(std::optional<long\
    \ long>(-2), std::optional<long long>(3)));\n        f.add_abs(10);\n        assert(f.min()\
    \ == 7);\n        assert(f.argmin() == std::make_pair(std::optional<long long>(3),\
    \ std::optional<long long>(10)));\n    }\n    std::cout << \"Hello World\" <<\
    \ std::endl;\n}\n"
  dependsOn:
  - datastructure/slope_trick.hpp
  isVerificationFile: true
  path: test/unit/slope_trick.test.cpp
  requiredBy: []
  timestamp: '2026-10-30 20:38:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/slope_trick.test.cpp
layout: document
redirect_from:
- /verify/test/unit/slope_trick.test.cpp
- /verify/test/unit/slope_trick.test.cpp.html
title: test/unit/slope_trick.test.cpp
---
