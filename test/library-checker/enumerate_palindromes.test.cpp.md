---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/rolling_hash.hpp
    title: string/rolling_hash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: '"https://judge.yosupo.jp/problem/enumerate_palindromes";'
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"test/library-checker/enumerate_palindromes.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\";\n#include\
    \ <iostream>\n\n#line 2 \"string/rolling_hash.hpp\"\n#include <cstdint>\nstruct\
    \ modint2305843009213693951 {\n    using mint = modint2305843009213693951;\n\n\
    public:\n    static constexpr uint64_t mod = 2305843009213693951;\n    modint2305843009213693951()\
    \ : _v(0) {\n    }\n    modint2305843009213693951(uint64_t v) : _v(fast_mod(v))\
    \ {\n    }\n    static constexpr uint64_t fast_mod(uint64_t v) {\n        uint64_t\
    \ u = v >> 61;\n        uint64_t d = v & mod;\n        uint64_t x = u + d;\n \
    \       if (x > mod) x -= mod;\n        return x;\n    }\n    uint64_t val() const\
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
    \ *this;\n    }\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n\
    \        return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint&\
    \ lhs, const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend\
    \ mint operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ *= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n\nprivate:\n\
    \    uint64_t _v;\n};\n\n#include <vector>\ntemplate <typename mint>\nstruct pow_mods\
    \ {\n    pow_mods() {\n    }\n    pow_mods(mint base, int n) : base(base) {\n\
    \        ensure(n);\n    }\n    const mint& operator[](int i) const {\n      \
    \  ensure(i);\n        return pows[i];\n    }\n    void ensure(int n) const {\n\
    \        int sz = pows.size();\n        if (sz > n) return;\n        pows.resize(n\
    \ + 1);\n        for (int i = sz; i <= n; i++) pows[i] = base * pows[i - 1];\n\
    \    }\n\nprivate:\n    mutable std::vector<mint> pows{1};\n    mint base;\n \
    \   static constexpr int mod = mint::mod;\n};\n\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n#include <random>\ntemplate <int base_num = 1,\
    \ typename mint = modint2305843009213693951>\nstruct RollingHash {\npublic:\n\
    \    RollingHash() {\n    }\n    RollingHash(const std::vector<int>& a) : n(a.size())\
    \ {\n        for (int base_id = 0; base_id < base_num; base_id++) {\n        \
    \    hashes[base_id].resize(n + 1);\n            hashes[base_id][0] = 0;\n   \
    \         for (int i = 0; i < n; i++) {\n                hashes[base_id][i + 1]\
    \ =\n                    hashes[base_id][i] * bases[base_id] + a[i];\n       \
    \     }\n        }\n    }\n    template <typename Iterable>\n    static RollingHash\
    \ from(const Iterable& s) {\n        std::vector<int> a;\n        for (auto&&\
    \ e : s) a.push_back(int(e));\n        return RollingHash(a);\n    }\n    std::array<mint,\
    \ base_num> operator()(int l, int r) {\n        assert(0 <= l && l < n);\n   \
    \     assert(0 <= r && r <= n);\n        assert(l <= r);\n        std::array<mint,\
    \ base_num> res;\n        for (int base_id = 0; base_id < base_num; base_id++)\
    \ {\n            res[base_id] =\n                hashes[base_id][r] - hashes[base_id][l]\
    \ * pows[base_id][r - l];\n        }\n        return res;\n    }\n    static std::array<mint,\
    \ base_num> concat(\n        const std::array<mint, base_num>& h1,\n        const\
    \ std::array<mint, base_num>& h2, int h2_len) {\n        std::array<mint, base_num>\
    \ res;\n        for (int base_id = 0; base_id < base_num; base_id++) {\n     \
    \       res[base_id] = h1[base_id] * pows[base_id][h2_len] + h2[base_id];\n  \
    \      }\n        return res;\n    }\n    int lcp(int l1, int r1, int l2, int\
    \ r2) {\n        int len = std::min(r1 - l1, r2 - l2);\n        int ok = 0, ng\
    \ = len + 1;\n        while (ng - ok > 1) {\n            int mid = (ok + ng) /\
    \ 2;\n            bool f = (*this)(l1, l1 + mid) == (*this)(l2, l2 + mid);\n \
    \           (f ? ok : ng) = mid;\n        }\n        return ok;\n    }\n    int\
    \ cmp(int l1, int r1, int l2, int r2) {\n        int x = std::min({lcp(l1, r1,\
    \ l2, r2), r1 - l1, r2 - l2});\n        if (l1 + x == r1 && l2 + x != r2) return\
    \ -1;\n        if (l1 + x == r1 || l2 + x == r2) return 0;\n        if (l1 + x\
    \ != r1 && l2 + x == r2) return 1;\n        return (*this)(l1 + x, l1 + x + 1)[0].val()\
    \ <\n                       (*this)(l2 + x, l2 + x + 1)[0].val()\n           \
    \        ? -1\n                   : 1;\n    }\n    static int lcp(RollingHash<base_num,\
    \ mint>& rh1, int l1, int r1,\n                   RollingHash<base_num, mint>&\
    \ rh2, int l2, int r2) {\n        int len = std::min(r1 - l1, r2 - l2);\n    \
    \    int ok = 0, ng = len + 1;\n        while (ng - ok > 1) {\n            int\
    \ mid = (ok + ng) / 2;\n            bool f = rh1(l1, l1 + mid) == rh2(l2, l2 +\
    \ mid);\n            (f ? ok : ng) = mid;\n        }\n        return ok;\n   \
    \ }\n    static int cmp(RollingHash<base_num, mint>& rh1, int l1, int r1,\n  \
    \                 RollingHash<base_num, mint>& rh2, int l2, int r2) {\n      \
    \  int x = std::min({lcp(rh1, l1, r1, rh2, l2, r2), r1 - l1, r2 - l2});\n    \
    \    if (l1 + x == r1 && l2 + x != r2) return -1;\n        if (l1 + x == r1 ||\
    \ l2 + x == r2) return 0;\n        if (l1 + x != r1 && l2 + x == r2) return 1;\n\
    \        return rh1(l1 + x, l1 + x + 1)[0].val() <\n                       rh2(l2\
    \ + x, l2 + x + 1)[0].val()\n                   ? -1\n                   : 1;\n\
    \    }\n\nprivate:\n    static inline std::array<mint, base_num> gen_bases() {\n\
    \        static std::mt19937_64 rng(std::random_device{}());\n        std::array<mint,\
    \ base_num> bases;\n        for (int i = 0; i < base_num; i++) {\n           \
    \ bases[i] =\n                std::uniform_int_distribution<uint64_t>(1, mint::mod\
    \ - 1)(rng);\n        }\n        return bases;\n    }\n    static inline std::array<pow_mods<mint>,\
    \ base_num> init_pows(\n        const std::array<mint, base_num>& bases) {\n \
    \       std::array<pow_mods<mint>, base_num> pows;\n        for (int i = 0; i\
    \ < base_num; i++) {\n            pows[i] = pow_mods<mint>(bases[i], 0);\n   \
    \     }\n        return pows;\n    }\n    static inline std::array<mint, base_num>\
    \ bases = gen_bases();\n    static inline std::array<pow_mods<mint>, base_num>\
    \ pows = init_pows(bases);\n    int n;\n    std::array<std::vector<mint>, base_num>\
    \ hashes;\n};\n#line 5 \"test/library-checker/enumerate_palindromes.test.cpp\"\
    \nint main() {\n    std::string s;\n    std::cin >> s;\n    int n = s.size();\n\
    \n    auto rh = RollingHash<>::from(s);\n    auto rh_rev = RollingHash<>::from(std::string(s.rbegin(),\
    \ s.rend()));\n\n    std::vector<int> ans(2 * n - 1);\n    for (int i = 0, j =\
    \ 0; i < n; i++, j += 2) {\n        int ok = 0, ng = std::min(i, n - i - 1) +\
    \ 1;\n        while (ng - ok > 1) {\n            int mid = (ok + ng) / 2;\n  \
    \          bool f = rh(i - mid, i) == rh_rev(n - (i + 1 + mid), n - (i + 1));\n\
    \            (f ? ok : ng) = mid;\n        }\n        ans[j] = ok * 2 + 1;\n \
    \   }\n    for (int i = 0, j = 1; i + 1 < n; i++, j += 2) {\n        int ok =\
    \ 0, ng = std::min(i + 1, n - i - 1) + 1;\n        while (ng - ok > 1) {\n   \
    \         int mid = (ok + ng) / 2;\n            bool f = rh(i - mid + 1, i + 1)\
    \ ==\n                     rh_rev(n - (i + 1 + mid), n - (i + 1));\n         \
    \   (f ? ok : ng) = mid;\n        }\n        ans[j] = ok * 2;\n    }\n    for\
    \ (int i = 0; i < 2 * n - 1; i++) {\n        std::cout << ans[i] << \" \\n\"[i\
    \ == 2 * n - 2];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    ;\n#include <iostream>\n\n#include \"../../string/rolling_hash.hpp\"\nint main()\
    \ {\n    std::string s;\n    std::cin >> s;\n    int n = s.size();\n\n    auto\
    \ rh = RollingHash<>::from(s);\n    auto rh_rev = RollingHash<>::from(std::string(s.rbegin(),\
    \ s.rend()));\n\n    std::vector<int> ans(2 * n - 1);\n    for (int i = 0, j =\
    \ 0; i < n; i++, j += 2) {\n        int ok = 0, ng = std::min(i, n - i - 1) +\
    \ 1;\n        while (ng - ok > 1) {\n            int mid = (ok + ng) / 2;\n  \
    \          bool f = rh(i - mid, i) == rh_rev(n - (i + 1 + mid), n - (i + 1));\n\
    \            (f ? ok : ng) = mid;\n        }\n        ans[j] = ok * 2 + 1;\n \
    \   }\n    for (int i = 0, j = 1; i + 1 < n; i++, j += 2) {\n        int ok =\
    \ 0, ng = std::min(i + 1, n - i - 1) + 1;\n        while (ng - ok > 1) {\n   \
    \         int mid = (ok + ng) / 2;\n            bool f = rh(i - mid + 1, i + 1)\
    \ ==\n                     rh_rev(n - (i + 1 + mid), n - (i + 1));\n         \
    \   (f ? ok : ng) = mid;\n        }\n        ans[j] = ok * 2;\n    }\n    for\
    \ (int i = 0; i < 2 * n - 1; i++) {\n        std::cout << ans[i] << \" \\n\"[i\
    \ == 2 * n - 2];\n    }\n}"
  dependsOn:
  - string/rolling_hash.hpp
  isVerificationFile: true
  path: test/library-checker/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2022-09-04 19:05:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/enumerate_palindromes.test.cpp
- /verify/test/library-checker/enumerate_palindromes.test.cpp.html
title: test/library-checker/enumerate_palindromes.test.cpp
---
