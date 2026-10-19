---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/range_map.hpp
    title: Range Map
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
  bundledCode: "#line 1 \"test/unit/range_map.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <map>\n#include <optional>\n\
    #include <random>\n#include <vector>\n\n#line 3 \"datastructure/range_map.hpp\"\
    \n#include <iterator>\n#line 5 \"datastructure/range_map.hpp\"\n#include <set>\n\
    template <class T, class S>\nstruct range_map {\npublic:\n    struct run {\n \
    \       T l, r;\n        S x;\n    };\n\nprivate:\n    struct cmp {\n        using\
    \ is_transparent = void;\n        bool operator()(const run& a, const run& b)\
    \ const {\n            return a.l < b.l;\n        }\n        bool operator()(const\
    \ run& a, const T& b) const {\n            return a.l < b;\n        }\n      \
    \  bool operator()(const T& a, const run& b) const {\n            return a < b.l;\n\
    \        }\n    };\n\npublic:\n    using iterator = typename std::set<run, cmp>::const_iterator;\n\
    \    range_map() {\n    }\n    // p \u3092\u542B\u3080 run\u3002\u7121\u3051\u308C\
    \u3070 end()\n    iterator find(T p) const {\n        auto it = runs.upper_bound(p);\n\
    \        if (it == runs.begin()) return runs.end();\n        it--;\n        if\
    \ (it->r <= p) return runs.end();\n        return it;\n    }\n    bool contains(T\
    \ p) const {\n        return find(p) != runs.end();\n    }\n    void assign(T\
    \ l, T r, S x) {\n        assign(l, r, x, [](T, T, const S&) {}, [](T, T, const\
    \ S&) {});\n    }\n    // f: \u3067\u304D\u305F run \u3054\u3068\u306B\u547C\u3076\
    , g: \u6D88\u3048\u305F run \u3054\u3068\u306B\u547C\u3076\n    template <class\
    \ F, class G>\n    void assign(T l, T r, S x, const F& f, const G& g) {\n    \
    \    assert(l < r);\n        {\n            auto it = find(l);\n            if\
    \ (it != runs.end() && r <= it->r && it->x == x) return;\n        }\n        T\
    \ nl = l, nr = r;\n        std::optional<run> left, right;\n        auto first\
    \ = runs.upper_bound(l);\n        if (first != runs.begin()) {\n            auto\
    \ p = std::prev(first);\n            if (l < p->r) {\n                first =\
    \ p;\n                if (p->l < l) {\n                    if (p->x == x) {\n\
    \                        nl = p->l;\n                    } else {\n          \
    \              left = run{p->l, l, p->x};\n                    }\n           \
    \     }\n            } else if (p->r == l && p->x == x) {\n                first\
    \ = p;\n                nl = p->l;\n            }\n        }\n        if (first\
    \ != runs.end() && first != runs.begin() && first->l == l) {\n            auto\
    \ p = std::prev(first);\n            if (p->r == l && p->x == x) {\n         \
    \       first = p;\n                nl = p->l;\n            }\n        }\n   \
    \     auto last = runs.lower_bound(r);\n        if (last != runs.begin()) {\n\
    \            auto q = std::prev(last);\n            if (r < q->r) {\n        \
    \        if (q->x == x) {\n                    nr = q->r;\n                } else\
    \ {\n                    right = run{r, q->r, q->x};\n                }\n    \
    \        }\n        }\n        if (last != runs.end() && last->l == r && last->x\
    \ == x) {\n            nr = last->r;\n            last++;\n        }\n       \
    \ for (auto it = first; it != last;) {\n            g(it->l, it->r, it->x);\n\
    \            it = runs.erase(it);\n        }\n        if (left) {\n          \
    \  runs.insert(*left);\n            f(left->l, left->r, left->x);\n        }\n\
    \        runs.insert({nl, nr, x});\n        f(nl, nr, x);\n        if (right)\
    \ {\n            runs.insert(*right);\n            f(right->l, right->r, right->x);\n\
    \        }\n    }\n    void erase(T l, T r) {\n        erase(l, r, [](T, T, const\
    \ S&) {}, [](T, T, const S&) {});\n    }\n    template <class F, class G>\n  \
    \  void erase(T l, T r, const F& f, const G& g) {\n        assert(l < r);\n  \
    \      auto it = runs.upper_bound(l);\n        if (it != runs.begin() && l < std::prev(it)->r)\
    \ it--;\n        while (it != runs.end() && it->l < r) {\n            run cur\
    \ = *it;\n            g(cur.l, cur.r, cur.x);\n            it = runs.erase(it);\n\
    \            if (cur.l < l) {\n                runs.insert({cur.l, l, cur.x});\n\
    \                f(cur.l, l, cur.x);\n            }\n            if (r < cur.r)\
    \ {\n                runs.insert({r, cur.r, cur.x});\n                f(r, cur.r,\
    \ cur.x);\n            }\n        }\n    }\n    int size() const {\n        return\
    \ int(runs.size());\n    }\n    iterator begin() const {\n        return runs.begin();\n\
    \    }\n    iterator end() const {\n        return runs.end();\n    }\n\nprivate:\n\
    \    std::set<run, cmp> runs;\n};\n#line 10 \"test/unit/range_map.test.cpp\"\n\
    void stress(std::mt19937& rng) {\n    const int U = 1 + rng() % 30;\n    const\
    \ int K = 1 + rng() % 4;  // \u5024\u306E\u7A2E\u985E\n    const int NONE = -1;\n\
    \    std::vector<int> a(U, NONE);\n    range_map<int, int> mp;\n    std::map<int,\
    \ long long> cnt;  // \u30B3\u30FC\u30EB\u30D0\u30C3\u30AF\u3067\u7BA1\u7406\u3059\
    \u308B\u5024\u3054\u3068\u306E\u500B\u6570\n    long long runs = 0;          \
    \  // \u30B3\u30FC\u30EB\u30D0\u30C3\u30AF\u3067\u7BA1\u7406\u3059\u308B run \u306E\
    \u500B\u6570\n    auto f = [&](int l, int r, const int& x) {\n        cnt[x] +=\
    \ r - l;\n        runs++;\n    };\n    auto g = [&](int l, int r, const int& x)\
    \ {\n        cnt[x] -= r - l;\n        runs--;\n    };\n    for (int it = 0; it\
    \ < 200; it++) {\n        int l = rng() % U, r = rng() % U;\n        if (l > r)\
    \ std::swap(l, r);\n        r++;\n        if (rng() % 3) {\n            int x\
    \ = rng() % K;\n            mp.assign(l, r, x, f, g);\n            for (int i\
    \ = l; i < r; i++) a[i] = x;\n        } else {\n            mp.erase(l, r, f,\
    \ g);\n            for (int i = l; i < r; i++) a[i] = NONE;\n        }\n     \
    \   // \u5024\u3068 contains\n        for (int p = 0; p < U; p++) {\n        \
    \    auto fi = mp.find(p);\n            assert(mp.contains(p) == (a[p] != NONE));\n\
    \            if (a[p] != NONE) {\n                assert(fi != mp.end() && fi->l\
    \ <= p && p < fi->r && fi->x == a[p]);\n            } else {\n               \
    \ assert(fi == mp.end());\n            }\n        }\n        // run \u304C\u6B63\
    \u898F\u5F62: \u5024\u306E\u3042\u308B\u6975\u5927\u306A\u9023\u7D9A\u533A\u9593\
    \u3068\u4E00\u81F4\n        int expect_runs = 0;\n        for (int p = 0; p <\
    \ U; p++) expect_runs += a[p] != NONE && (p == 0 || a[p] != a[p - 1]);\n     \
    \   assert(mp.size() == expect_runs);\n        assert(runs == expect_runs);\n\
    \        int prev_r = -1;\n        std::optional<int> prev_x;\n        for (auto\
    \ [rl, rr, rx] : mp) {\n            assert(rl < rr);\n            assert(prev_r\
    \ <= rl);\n            if (prev_r == rl) assert(*prev_x != rx);\n            for\
    \ (int p = rl; p < rr; p++) assert(a[p] == rx);\n            if (rl > 0) assert(a[rl\
    \ - 1] != rx);\n            if (rr < U) assert(a[rr] != rx);\n            prev_r\
    \ = rr;\n            prev_x = rx;\n        }\n        // \u30D2\u30B9\u30C8\u30B0\
    \u30E9\u30E0\n        std::map<int, long long> expect;\n        for (int v : a)\
    \ {\n            if (v != NONE) expect[v]++;\n        }\n        for (auto [v,\
    \ c] : cnt) assert(c == expect[v]);\n    }\n}\nint main() {\n    std::mt19937\
    \ rng(7959);\n    for (int trial = 0; trial < 300; trial++) stress(rng);\n   \
    \ std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <map>\n#include <optional>\n\
    #include <random>\n#include <vector>\n\n#include \"datastructure/range_map.hpp\"\
    \nvoid stress(std::mt19937& rng) {\n    const int U = 1 + rng() % 30;\n    const\
    \ int K = 1 + rng() % 4;  // \u5024\u306E\u7A2E\u985E\n    const int NONE = -1;\n\
    \    std::vector<int> a(U, NONE);\n    range_map<int, int> mp;\n    std::map<int,\
    \ long long> cnt;  // \u30B3\u30FC\u30EB\u30D0\u30C3\u30AF\u3067\u7BA1\u7406\u3059\
    \u308B\u5024\u3054\u3068\u306E\u500B\u6570\n    long long runs = 0;          \
    \  // \u30B3\u30FC\u30EB\u30D0\u30C3\u30AF\u3067\u7BA1\u7406\u3059\u308B run \u306E\
    \u500B\u6570\n    auto f = [&](int l, int r, const int& x) {\n        cnt[x] +=\
    \ r - l;\n        runs++;\n    };\n    auto g = [&](int l, int r, const int& x)\
    \ {\n        cnt[x] -= r - l;\n        runs--;\n    };\n    for (int it = 0; it\
    \ < 200; it++) {\n        int l = rng() % U, r = rng() % U;\n        if (l > r)\
    \ std::swap(l, r);\n        r++;\n        if (rng() % 3) {\n            int x\
    \ = rng() % K;\n            mp.assign(l, r, x, f, g);\n            for (int i\
    \ = l; i < r; i++) a[i] = x;\n        } else {\n            mp.erase(l, r, f,\
    \ g);\n            for (int i = l; i < r; i++) a[i] = NONE;\n        }\n     \
    \   // \u5024\u3068 contains\n        for (int p = 0; p < U; p++) {\n        \
    \    auto fi = mp.find(p);\n            assert(mp.contains(p) == (a[p] != NONE));\n\
    \            if (a[p] != NONE) {\n                assert(fi != mp.end() && fi->l\
    \ <= p && p < fi->r && fi->x == a[p]);\n            } else {\n               \
    \ assert(fi == mp.end());\n            }\n        }\n        // run \u304C\u6B63\
    \u898F\u5F62: \u5024\u306E\u3042\u308B\u6975\u5927\u306A\u9023\u7D9A\u533A\u9593\
    \u3068\u4E00\u81F4\n        int expect_runs = 0;\n        for (int p = 0; p <\
    \ U; p++) expect_runs += a[p] != NONE && (p == 0 || a[p] != a[p - 1]);\n     \
    \   assert(mp.size() == expect_runs);\n        assert(runs == expect_runs);\n\
    \        int prev_r = -1;\n        std::optional<int> prev_x;\n        for (auto\
    \ [rl, rr, rx] : mp) {\n            assert(rl < rr);\n            assert(prev_r\
    \ <= rl);\n            if (prev_r == rl) assert(*prev_x != rx);\n            for\
    \ (int p = rl; p < rr; p++) assert(a[p] == rx);\n            if (rl > 0) assert(a[rl\
    \ - 1] != rx);\n            if (rr < U) assert(a[rr] != rx);\n            prev_r\
    \ = rr;\n            prev_x = rx;\n        }\n        // \u30D2\u30B9\u30C8\u30B0\
    \u30E9\u30E0\n        std::map<int, long long> expect;\n        for (int v : a)\
    \ {\n            if (v != NONE) expect[v]++;\n        }\n        for (auto [v,\
    \ c] : cnt) assert(c == expect[v]);\n    }\n}\nint main() {\n    std::mt19937\
    \ rng(7959);\n    for (int trial = 0; trial < 300; trial++) stress(rng);\n   \
    \ std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - datastructure/range_map.hpp
  isVerificationFile: true
  path: test/unit/range_map.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 22:21:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/range_map.test.cpp
layout: document
redirect_from:
- /verify/test/unit/range_map.test.cpp
- /verify/test/unit/range_map.test.cpp.html
title: test/unit/range_map.test.cpp
---
