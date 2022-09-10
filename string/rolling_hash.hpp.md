---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint2305843009213693951.hpp
    title: math/modint2305843009213693951.hpp
  - icon: ':heavy_check_mark:'
    path: math/pow_table.hpp
    title: math/pow_table.hpp
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rolling_hash.hpp\"\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n#include <random>\n#include <vector>\n\n#line 2\
    \ \"math/modint2305843009213693951.hpp\"\n#include <cstdint>\nstruct modint2305843009213693951\
    \ {\n    using mint = modint2305843009213693951;\n\npublic:\n    static constexpr\
    \ uint64_t mod = 2305843009213693951;\n    modint2305843009213693951() : _v(0)\
    \ {\n    }\n    modint2305843009213693951(uint64_t v) : _v(fast_mod(v)) {\n  \
    \  }\n    static constexpr uint64_t fast_mod(uint64_t v) {\n        uint64_t u\
    \ = v >> 61;\n        uint64_t d = v & mod;\n        uint64_t x = u + d;\n   \
    \     if (x > mod) x -= mod;\n        return x;\n    }\n    uint64_t val() const\
    \ {\n        return _v;\n    }\n\n    mint& operator+=(const mint& rhs) {\n  \
    \      _v += rhs._v;\n        if (_v >= mod) _v -= mod;\n        return *this;\n\
    \    }\n    mint& operator-=(const mint& rhs) {\n        _v -= rhs._v;\n     \
    \   if (_v >= mod) _v += mod;\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        static constexpr uint64_t mask31 = (uint64_t(1) << 31)\
    \ - 1;\n        static constexpr uint64_t mask30 = (uint64_t(1) << 30) - 1;\n\
    \        uint64_t au = _v >> 31;\n        uint64_t ad = _v & mask31;\n       \
    \ uint64_t bu = rhs._v >> 31;\n        uint64_t bd = rhs._v & mask31;\n      \
    \  uint64_t m = ad * bu + au * bd;\n        uint64_t mu = m >> 30;\n        uint64_t\
    \ md = m & mask30;\n        _v = fast_mod((au * bu << 1) + mu + (md << 31) + ad\
    \ * bd);\n        return *this;\n    }\n    mint operator+() const {\n       \
    \ return *this;\n    }\n    mint operator-() const {\n        return mint() -\
    \ *this;\n    }\n    mint pow(uint64_t n) const {\n        mint x = *this, r =\
    \ 1;\n        while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return r;\n    }\n    friend mint operator+(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n   \
    \ friend mint operator-(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ -= rhs;\n    }\n    friend mint operator*(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) *= rhs;\n    }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n   \
    \ friend bool operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v\
    \ != rhs._v;\n    }\n\nprivate:\n    uint64_t _v;\n};\n#line 3 \"math/pow_table.hpp\"\
    \ntemplate <typename mint>\nstruct pow_mods {\n    pow_mods() {\n    }\n    pow_mods(mint\
    \ base, int n) : base(base) {\n        ensure(n);\n    }\n    const mint& operator[](int\
    \ i) const {\n        ensure(i);\n        return pows[i];\n    }\n    void ensure(int\
    \ n) const {\n        int sz = pows.size();\n        if (sz > n) return;\n   \
    \     pows.resize(n + 1);\n        for (int i = sz; i <= n; i++) pows[i] = base\
    \ * pows[i - 1];\n    }\n\nprivate:\n    mutable std::vector<mint> pows{1};\n\
    \    mint base;\n    static constexpr int mod = mint::mod;\n};\n#line 10 \"string/rolling_hash.hpp\"\
    \ntemplate <int base_num = 1, typename mint = modint2305843009213693951>\nstruct\
    \ RollingHash {\npublic:\n    RollingHash() {\n    }\n    RollingHash(const std::vector<int>&\
    \ a) : n(a.size()) {\n        for (int base_id = 0; base_id < base_num; base_id++)\
    \ {\n            hashes[base_id].resize(n + 1);\n            hashes[base_id][0]\
    \ = 0;\n            for (int i = 0; i < n; i++) {\n                hashes[base_id][i\
    \ + 1] =\n                    hashes[base_id][i] * bases[base_id] + a[i];\n  \
    \          }\n        }\n    }\n    template <typename Iterable>\n    static RollingHash\
    \ from(const Iterable& s) {\n        std::vector<int> a;\n        for (auto&&\
    \ e : s) a.push_back(int(e));\n        return RollingHash(a);\n    }\n    std::array<mint,\
    \ base_num> operator()(int l, int r) {\n        assert(0 <= l && l <= r && r <=\
    \ n);\n        std::array<mint, base_num> res;\n        for (int base_id = 0;\
    \ base_id < base_num; base_id++) {\n            res[base_id] =\n             \
    \   hashes[base_id][r] - hashes[base_id][l] * pows[base_id][r - l];\n        }\n\
    \        return res;\n    }\n    static std::array<mint, base_num> concat(\n \
    \       const std::array<mint, base_num>& h1,\n        const std::array<mint,\
    \ base_num>& h2, int h2_len) {\n        std::array<mint, base_num> res;\n    \
    \    for (int base_id = 0; base_id < base_num; base_id++) {\n            res[base_id]\
    \ = h1[base_id] * pows[base_id][h2_len] + h2[base_id];\n        }\n        return\
    \ res;\n    }\n    int lcp(int l1, int r1, int l2, int r2) {\n        int len\
    \ = std::min(r1 - l1, r2 - l2);\n        int ok = 0, ng = len + 1;\n        while\
    \ (ng - ok > 1) {\n            int mid = (ok + ng) / 2;\n            bool f =\
    \ (*this)(l1, l1 + mid) == (*this)(l2, l2 + mid);\n            (f ? ok : ng) =\
    \ mid;\n        }\n        return ok;\n    }\n    int cmp(int l1, int r1, int\
    \ l2, int r2) {\n        int x = std::min({lcp(l1, r1, l2, r2), r1 - l1, r2 -\
    \ l2});\n        if (l1 + x == r1 && l2 + x != r2) return -1;\n        if (l1\
    \ + x == r1 && l2 + x == r2) return 0;\n        if (l1 + x != r1 && l2 + x ==\
    \ r2) return 1;\n        return (*this)(l1 + x, l1 + x + 1)[0].val() <\n     \
    \                  (*this)(l2 + x, l2 + x + 1)[0].val()\n                   ?\
    \ -1\n                   : 1;\n    }\n    static int lcp(RollingHash<base_num,\
    \ mint>& rh1, int l1, int r1,\n                   RollingHash<base_num, mint>&\
    \ rh2, int l2, int r2) {\n        int len = std::min(r1 - l1, r2 - l2);\n    \
    \    int ok = 0, ng = len + 1;\n        while (ng - ok > 1) {\n            int\
    \ mid = (ok + ng) / 2;\n            bool f = rh1(l1, l1 + mid) == rh2(l2, l2 +\
    \ mid);\n            (f ? ok : ng) = mid;\n        }\n        return ok;\n   \
    \ }\n    static int cmp(RollingHash<base_num, mint>& rh1, int l1, int r1,\n  \
    \                 RollingHash<base_num, mint>& rh2, int l2, int r2) {\n      \
    \  int x = std::min({lcp(rh1, l1, r1, rh2, l2, r2), r1 - l1, r2 - l2});\n    \
    \    if (l1 + x == r1 && l2 + x != r2) return -1;\n        if (l1 + x == r1 &&\
    \ l2 + x == r2) return 0;\n        if (l1 + x != r1 && l2 + x == r2) return 1;\n\
    \        return rh1(l1 + x, l1 + x + 1)[0].val() <\n                       rh2(l2\
    \ + x, l2 + x + 1)[0].val()\n                   ? -1\n                   : 1;\n\
    \    }\n\nprivate:\n    static inline std::array<mint, base_num> gen_bases() {\n\
    \        static std::mt19937_64 rng(std::random_device{}());\n        std::array<mint,\
    \ base_num> bases;\n        for (int i = 0; i < base_num; i++) {\n           \
    \ while (true) {\n                uint64_t k = std::uniform_int_distribution<uint64_t>(\n\
    \                    1, mint::mod - 1)(rng);\n                if (std::gcd(k,\
    \ mint::mod - 1) != 1) continue;\n                uint64_t b = mint(r).pow(k).val();\n\
    \                if (b <= A) continue;\n                bases[i] = b;\n      \
    \          break;\n            }\n        }\n        return bases;\n    }\n  \
    \  static inline std::array<pow_mods<mint>, base_num> init_pows(\n        const\
    \ std::array<mint, base_num>& bases) {\n        std::array<pow_mods<mint>, base_num>\
    \ pows;\n        for (int i = 0; i < base_num; i++) {\n            pows[i] = pow_mods<mint>(bases[i],\
    \ 0);\n        }\n        return pows;\n    }\n    static inline std::array<mint,\
    \ base_num> bases = gen_bases();\n    static inline std::array<pow_mods<mint>,\
    \ base_num> pows = init_pows(bases);\n    int n;\n    std::array<std::vector<mint>,\
    \ base_num> hashes;\n    static constexpr uint64_t r = 37;\n    static constexpr\
    \ uint64_t A = 2147483647;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <array>\n#include <cassert>\n\
    #include <random>\n#include <vector>\n\n#include \"../math/modint2305843009213693951.hpp\"\
    \n#include \"../math/pow_table.hpp\"\ntemplate <int base_num = 1, typename mint\
    \ = modint2305843009213693951>\nstruct RollingHash {\npublic:\n    RollingHash()\
    \ {\n    }\n    RollingHash(const std::vector<int>& a) : n(a.size()) {\n     \
    \   for (int base_id = 0; base_id < base_num; base_id++) {\n            hashes[base_id].resize(n\
    \ + 1);\n            hashes[base_id][0] = 0;\n            for (int i = 0; i <\
    \ n; i++) {\n                hashes[base_id][i + 1] =\n                    hashes[base_id][i]\
    \ * bases[base_id] + a[i];\n            }\n        }\n    }\n    template <typename\
    \ Iterable>\n    static RollingHash from(const Iterable& s) {\n        std::vector<int>\
    \ a;\n        for (auto&& e : s) a.push_back(int(e));\n        return RollingHash(a);\n\
    \    }\n    std::array<mint, base_num> operator()(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        std::array<mint, base_num> res;\n      \
    \  for (int base_id = 0; base_id < base_num; base_id++) {\n            res[base_id]\
    \ =\n                hashes[base_id][r] - hashes[base_id][l] * pows[base_id][r\
    \ - l];\n        }\n        return res;\n    }\n    static std::array<mint, base_num>\
    \ concat(\n        const std::array<mint, base_num>& h1,\n        const std::array<mint,\
    \ base_num>& h2, int h2_len) {\n        std::array<mint, base_num> res;\n    \
    \    for (int base_id = 0; base_id < base_num; base_id++) {\n            res[base_id]\
    \ = h1[base_id] * pows[base_id][h2_len] + h2[base_id];\n        }\n        return\
    \ res;\n    }\n    int lcp(int l1, int r1, int l2, int r2) {\n        int len\
    \ = std::min(r1 - l1, r2 - l2);\n        int ok = 0, ng = len + 1;\n        while\
    \ (ng - ok > 1) {\n            int mid = (ok + ng) / 2;\n            bool f =\
    \ (*this)(l1, l1 + mid) == (*this)(l2, l2 + mid);\n            (f ? ok : ng) =\
    \ mid;\n        }\n        return ok;\n    }\n    int cmp(int l1, int r1, int\
    \ l2, int r2) {\n        int x = std::min({lcp(l1, r1, l2, r2), r1 - l1, r2 -\
    \ l2});\n        if (l1 + x == r1 && l2 + x != r2) return -1;\n        if (l1\
    \ + x == r1 && l2 + x == r2) return 0;\n        if (l1 + x != r1 && l2 + x ==\
    \ r2) return 1;\n        return (*this)(l1 + x, l1 + x + 1)[0].val() <\n     \
    \                  (*this)(l2 + x, l2 + x + 1)[0].val()\n                   ?\
    \ -1\n                   : 1;\n    }\n    static int lcp(RollingHash<base_num,\
    \ mint>& rh1, int l1, int r1,\n                   RollingHash<base_num, mint>&\
    \ rh2, int l2, int r2) {\n        int len = std::min(r1 - l1, r2 - l2);\n    \
    \    int ok = 0, ng = len + 1;\n        while (ng - ok > 1) {\n            int\
    \ mid = (ok + ng) / 2;\n            bool f = rh1(l1, l1 + mid) == rh2(l2, l2 +\
    \ mid);\n            (f ? ok : ng) = mid;\n        }\n        return ok;\n   \
    \ }\n    static int cmp(RollingHash<base_num, mint>& rh1, int l1, int r1,\n  \
    \                 RollingHash<base_num, mint>& rh2, int l2, int r2) {\n      \
    \  int x = std::min({lcp(rh1, l1, r1, rh2, l2, r2), r1 - l1, r2 - l2});\n    \
    \    if (l1 + x == r1 && l2 + x != r2) return -1;\n        if (l1 + x == r1 &&\
    \ l2 + x == r2) return 0;\n        if (l1 + x != r1 && l2 + x == r2) return 1;\n\
    \        return rh1(l1 + x, l1 + x + 1)[0].val() <\n                       rh2(l2\
    \ + x, l2 + x + 1)[0].val()\n                   ? -1\n                   : 1;\n\
    \    }\n\nprivate:\n    static inline std::array<mint, base_num> gen_bases() {\n\
    \        static std::mt19937_64 rng(std::random_device{}());\n        std::array<mint,\
    \ base_num> bases;\n        for (int i = 0; i < base_num; i++) {\n           \
    \ while (true) {\n                uint64_t k = std::uniform_int_distribution<uint64_t>(\n\
    \                    1, mint::mod - 1)(rng);\n                if (std::gcd(k,\
    \ mint::mod - 1) != 1) continue;\n                uint64_t b = mint(r).pow(k).val();\n\
    \                if (b <= A) continue;\n                bases[i] = b;\n      \
    \          break;\n            }\n        }\n        return bases;\n    }\n  \
    \  static inline std::array<pow_mods<mint>, base_num> init_pows(\n        const\
    \ std::array<mint, base_num>& bases) {\n        std::array<pow_mods<mint>, base_num>\
    \ pows;\n        for (int i = 0; i < base_num; i++) {\n            pows[i] = pow_mods<mint>(bases[i],\
    \ 0);\n        }\n        return pows;\n    }\n    static inline std::array<mint,\
    \ base_num> bases = gen_bases();\n    static inline std::array<pow_mods<mint>,\
    \ base_num> pows = init_pows(bases);\n    int n;\n    std::array<std::vector<mint>,\
    \ base_num> hashes;\n    static constexpr uint64_t r = 37;\n    static constexpr\
    \ uint64_t A = 2147483647;\n};"
  dependsOn:
  - math/modint2305843009213693951.hpp
  - math/pow_table.hpp
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2022-09-11 05:20:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/zalgorithm_rolling_hash.test.cpp
  - test/library-checker/suffix_array_rolling_hash.test.cpp
  - test/library-checker/enumerate_palindromes.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
title: Rolling-Hash
---

### 概要
- ハッシュを用いて文字列の一致判定を高速に行う。
  
### 使い方
- `RollingHash<base_num, mint>::from(s)`: 文字列 `s` のローリングハッシュを構築する。`base_num` 個の基数を用いて、`mint` でハッシュを計算する。デフォルトは、`base_num = 1, mint = modint2305843009213693951`。
- `rlh(l, r)`: `s[l..r]` のハッシュ値を求める。
- `lcp(l1, r1, l2, r2)`: `s[l1..r1]` と `s[l2..r2]` の LCP の長さを求める。
- `RollingHash<>::lcp(rh1, l1, r1, rh2, l2, r2)`: `s1[l1..r1]` と `s2[l2..r2]` の LCP の長さを求める。
- `cmp(l1, r1, l2, r2)`: `s1 = s[l1..r1]` と `s2 = s[l2..r2]` を辞書順で比較する。返り値は、`s1 < s2 ? -1 : s1 == s2 ? 0 : 1`。
- `RollingHash<>::cmp(rh1, l1, r1, rh2, l2, r2)`: `s1[l1..r1]` と `s2[l2..r2]` を辞書順で比較する。
- `RollingHash<>::concat(h1, h2, h2_len)`: ハッシュ値が `h1` の文字列と、ハッシュ値が `h2` で長さが `h2_len` の文字列を連結した文字列のハッシュ値を求める。

### 計算量
- 構築: $\mathcal{O}(N)$
- クエリ: $\mathcal{O}(1)$
- `lcp`: $\mathcal{O}(\log N)$
- `cmp`: $\mathcal{O}(\log N)$
- `concat`: $\mathcal{O}(1)$