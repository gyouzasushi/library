---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint2305843009213693951.hpp
    title: modint2305843009213693951
  - icon: ':heavy_check_mark:'
    path: string/string_hash.hpp
    title: String Hash
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/enumerate_palindromes.test.cpp
    title: test/library-checker/enumerate_palindromes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/suffix_array_rolling_hash.test.cpp
    title: test/library-checker/suffix_array_rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/zalgorithm_rolling_hash.test.cpp
    title: test/library-checker/zalgorithm_rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/string_hash.test.cpp
    title: test/unit/string_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2231.test.cpp
    title: test/yukicoder/2231.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rolling_hash.hpp\"\n#include <array>\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"string/string_hash.hpp\"\n#include <algorithm>\n\
    #line 5 \"string/string_hash.hpp\"\n#include <cstdint>\n#include <numeric>\n#include\
    \ <random>\n#line 9 \"string/string_hash.hpp\"\n\n#line 3 \"math/modint2305843009213693951.hpp\"\
    \n#include <concepts>\n#line 5 \"math/modint2305843009213693951.hpp\"\nstruct\
    \ modint2305843009213693951 {\n    using mint = modint2305843009213693951;\n \
    \   static constexpr uint64_t mod() {\n        return m;\n    }\n    static mint\
    \ raw(uint64_t v) {\n        mint x;\n        x._v = v;\n        return x;\n \
    \   }\n    modint2305843009213693951() : _v(0) {}\n    template <std::unsigned_integral\
    \ T>\n    modint2305843009213693951(T v) : _v(reduce(v)) {}\n    template <std::signed_integral\
    \ T>\n    modint2305843009213693951(T v) {\n        if (v >= 0) {\n          \
    \  _v = reduce(uint64_t(v));\n        } else {\n            uint64_t x = reduce(uint64_t(0)\
    \ - uint64_t(v));\n            _v = x == 0 ? 0 : m - x;\n        }\n    }\n  \
    \  uint64_t val() const {\n        return _v;\n    }\n    mint& operator++() {\n\
    \        if (++_v == m) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = m;\n        _v--;\n        return *this;\n    }\n\
    \    mint operator++(int) {\n        mint r = *this;\n        ++*this;\n     \
    \   return r;\n    }\n    mint operator--(int) {\n        mint r = *this;\n  \
    \      --*this;\n        return r;\n    }\n    mint& operator+=(const mint& rhs)\
    \ {\n        _v += rhs._v;\n        if (_v >= m) _v -= m;\n        return *this;\n\
    \    }\n    mint& operator-=(const mint& rhs) {\n        _v += m - rhs._v;\n \
    \       if (_v >= m) _v -= m;\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        constexpr uint64_t mask31 = (uint64_t(1) << 31) - 1;\n\
    \        constexpr uint64_t mask30 = (uint64_t(1) << 30) - 1;\n        uint64_t\
    \ au = _v >> 31, ad = _v & mask31;\n        uint64_t bu = rhs._v >> 31, bd = rhs._v\
    \ & mask31;\n        uint64_t mid = ad * bu + au * bd;\n        uint64_t mu =\
    \ mid >> 30, md = mid & mask30;\n        _v = reduce((au * bu << 1) + mu + (md\
    \ << 31) + ad * bd);\n        return *this;\n    }\n    mint& operator/=(const\
    \ mint& rhs) {\n        return *this *= rhs.inv();\n    }\n    mint operator+()\
    \ const {\n        return *this;\n    }\n    mint operator-() const {\n      \
    \  return mint() - *this;\n    }\n    mint pow(long long n) const {\n        assert(0\
    \ <= n);\n        mint x = *this, r = 1;\n        while (n) {\n            if\
    \ (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n    \
    \    return r;\n    }\n    mint inv() const {\n        assert(_v != 0);\n    \
    \    return pow(m - 2);\n    }\n    friend mint operator+(const mint& lhs, const\
    \ mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend mint operator-(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n   \
    \ friend mint operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ *= rhs;\n    }\n    friend mint operator/(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n   \
    \ friend bool operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v\
    \ != rhs._v;\n    }\n\nprivate:\n    static constexpr uint64_t m = (uint64_t(1)\
    \ << 61) - 1;\n    static constexpr uint64_t reduce(uint64_t v) {\n        uint64_t\
    \ x = (v >> 61) + (v & m);\n        if (x >= m) x -= m;\n        return x;\n \
    \   }\n    uint64_t _v;\n};\n#line 11 \"string/string_hash.hpp\"\ntemplate <int\
    \ k = 1, class mint = modint2305843009213693951>\nstruct string_hash {\n    static_assert(k\
    \ >= 1);\n    std::array<mint, k> val;\n    int len;\n    string_hash() : val{},\
    \ len(0) {}\n    explicit string_hash(int c) : len(1) {\n        val.fill(mint(c));\n\
    \    }\n    static string_hash repeat(int c, int n) {\n        assert(0 <= n);\n\
    \        string_hash h;\n        h.len = n;\n        for (int i = 0; i < k; i++)\
    \ h.val[i] = mint(c) * pow_sum(i, n);\n        return h;\n    }\n    friend string_hash\
    \ operator+(const string_hash& a, const string_hash& b) {\n        string_hash\
    \ r;\n        r.len = a.len + b.len;\n        for (int i = 0; i < k; i++) r.val[i]\
    \ = a.val[i] * pow(i, b.len) + b.val[i];\n        return r;\n    }\n    string_hash&\
    \ operator+=(const string_hash& b) {\n        return *this = *this + b;\n    }\n\
    \    friend bool operator==(const string_hash& a, const string_hash& b) {\n  \
    \      return a.len == b.len && a.val == b.val;\n    }\n    friend bool operator<(const\
    \ string_hash& a, const string_hash& b) {\n        if (a.len != b.len) return\
    \ a.len < b.len;\n        for (int i = 0; i < k; i++) {\n            if (a.val[i]\
    \ != b.val[i]) return a.val[i].val() < b.val[i].val();\n        }\n        return\
    \ false;\n    }\n    static mint base(int i) {\n        return bases()[i];\n \
    \   }\n    static mint pow(int i, int n) {\n        ensure(n);\n        return\
    \ pows()[i][n];\n    }\n    static mint pow_sum(int i, int n) {\n        ensure(n);\n\
    \        return pow_sums()[i][n];\n    }\n\nprivate:\n    static std::array<mint,\
    \ k> gen_bases() {\n        std::mt19937_64 rng(std::random_device{}());\n   \
    \     std::array<mint, k> b;\n        for (int i = 0; i < k; i++) {\n        \
    \    while (true) {\n                uint64_t e = std::uniform_int_distribution<uint64_t>(1,\
    \ mint::mod() - 1)(rng);\n                if (std::gcd(e, uint64_t(mint::mod()\
    \ - 1)) != 1) continue;\n                b[i] = mint(37).pow(e);\n           \
    \     break;\n            }\n        }\n        return b;\n    }\n    static std::array<mint,\
    \ k>& bases() {\n        static std::array<mint, k> b = gen_bases();\n       \
    \ return b;\n    }\n    static std::array<std::vector<mint>, k>& pows() {\n  \
    \      static std::array<std::vector<mint>, k> p = [] {\n            std::array<std::vector<mint>,\
    \ k> p;\n            for (auto& v : p) v.assign(1, mint(1));\n            return\
    \ p;\n        }();\n        return p;\n    }\n    static std::array<std::vector<mint>,\
    \ k>& pow_sums() {\n        static std::array<std::vector<mint>, k> s = [] {\n\
    \            std::array<std::vector<mint>, k> s;\n            for (auto& v : s)\
    \ v.assign(1, mint(0));\n            return s;\n        }();\n        return s;\n\
    \    }\n    static void ensure(int n) {\n        auto& p = pows();\n        auto&\
    \ s = pow_sums();\n        int sz = int(p[0].size());\n        if (n < sz) return;\n\
    \        int m = std::max(n + 1, 2 * sz);\n        for (int i = 0; i < k; i++)\
    \ {\n            p[i].resize(m);\n            s[i].resize(m);\n            for\
    \ (int j = sz; j < m; j++) {\n                p[i][j] = p[i][j - 1] * base(i);\n\
    \                s[i][j] = s[i][j - 1] + p[i][j - 1];\n            }\n       \
    \ }\n    }\n};\ntemplate <class A, class B>\nint lcp(A& a, int l1, int r1, B&\
    \ b, int l2, int r2) {\n    int ok = 0, ng = std::min(r1 - l1, r2 - l2) + 1;\n\
    \    while (ng - ok > 1) {\n        int mid = (ok + ng) / 2;\n        (a.prod(l1,\
    \ l1 + mid) == b.prod(l2, l2 + mid) ? ok : ng) = mid;\n    }\n    return ok;\n\
    }\ntemplate <class A, class B>\nint cmp(A& a, int l1, int r1, B& b, int l2, int\
    \ r2) {\n    int x = lcp(a, l1, r1, b, l2, r2);\n    bool ea = l1 + x == r1, eb\
    \ = l2 + x == r2;\n    if (ea && eb) return 0;\n    if (ea) return -1;\n    if\
    \ (eb) return 1;\n    return a.get(l1 + x).val[0].val() < b.get(l2 + x).val[0].val()\
    \ ? -1 : 1;\n}\n#line 7 \"string/rolling_hash.hpp\"\ntemplate <int k = 1, class\
    \ mint = modint2305843009213693951>\nstruct rolling_hash {\n    using H = string_hash<k,\
    \ mint>;\n    rolling_hash() : n(0) {}\n    template <class Iterable>\n    explicit\
    \ rolling_hash(const Iterable& s) {\n        std::vector<int> a;\n        for\
    \ (auto&& c : s) a.push_back(int(c));\n        n = int(a.size());\n        for\
    \ (int i = 0; i < k; i++) {\n            h[i].assign(n + 1, mint(0));\n      \
    \      for (int j = 0; j < n; j++) h[i][j + 1] = h[i][j] * H::base(i) + mint(a[j]);\n\
    \        }\n    }\n    int size() const {\n        return n;\n    }\n    H prod(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        H res;\n\
    \        res.len = r - l;\n        for (int i = 0; i < k; i++) res.val[i] = h[i][r]\
    \ - h[i][l] * H::pow(i, r - l);\n        return res;\n    }\n    H get(int p)\
    \ const {\n        return prod(p, p + 1);\n    }\n    H all_prod() const {\n \
    \       return prod(0, n);\n    }\n\nprivate:\n    int n;\n    std::array<std::vector<mint>,\
    \ k> h;\n};\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <vector>\n\n\
    #include \"string/string_hash.hpp\"\ntemplate <int k = 1, class mint = modint2305843009213693951>\n\
    struct rolling_hash {\n    using H = string_hash<k, mint>;\n    rolling_hash()\
    \ : n(0) {}\n    template <class Iterable>\n    explicit rolling_hash(const Iterable&\
    \ s) {\n        std::vector<int> a;\n        for (auto&& c : s) a.push_back(int(c));\n\
    \        n = int(a.size());\n        for (int i = 0; i < k; i++) {\n         \
    \   h[i].assign(n + 1, mint(0));\n            for (int j = 0; j < n; j++) h[i][j\
    \ + 1] = h[i][j] * H::base(i) + mint(a[j]);\n        }\n    }\n    int size()\
    \ const {\n        return n;\n    }\n    H prod(int l, int r) const {\n      \
    \  assert(0 <= l && l <= r && r <= n);\n        H res;\n        res.len = r -\
    \ l;\n        for (int i = 0; i < k; i++) res.val[i] = h[i][r] - h[i][l] * H::pow(i,\
    \ r - l);\n        return res;\n    }\n    H get(int p) const {\n        return\
    \ prod(p, p + 1);\n    }\n    H all_prod() const {\n        return prod(0, n);\n\
    \    }\n\nprivate:\n    int n;\n    std::array<std::vector<mint>, k> h;\n};\n"
  dependsOn:
  - string/string_hash.hpp
  - math/modint2305843009213693951.hpp
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2026-10-24 20:17:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/string_hash.test.cpp
  - test/yukicoder/2231.test.cpp
  - test/library-checker/suffix_array_rolling_hash.test.cpp
  - test/library-checker/enumerate_palindromes.test.cpp
  - test/library-checker/zalgorithm_rolling_hash.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
title: Rolling Hash
---

### 概要
- 静的な文字列の部分文字列のハッシュ値を求める。

### 使い方
- `rolling_hash<k = 1, mint = modint2305843009213693951>(s)`: 文字列 `s` で構築する。`s` は `std::string` か `std::vector<int>`。
- `size()`: `s` の長さを返す。
- `prod(l, r)`: `s[l, r)` のハッシュ値を返す。
- `get(p)`: `s[p]` のハッシュ値を返す。
- `all_prod()`: `s` のハッシュ値を返す。

### 制約
- $0 \le l \le r \le n$
- $0 \le p < n$

### 計算量
- 構築: $\mathcal{O}(kN)$
- `prod`, `get`, `all_prod`: $\mathcal{O}(k)$
