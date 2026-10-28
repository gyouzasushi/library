---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/xor_basis.hpp
    title: Xor Basis
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
  bundledCode: "#line 1 \"test/unit/xor_basis.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <set>\n#include <vector>\n\n#line 3 \"math/xor_basis.hpp\"\n#include\
    \ <bit>\n#line 5 \"math/xor_basis.hpp\"\n#include <concepts>\n#include <functional>\n\
    #include <limits>\n#include <type_traits>\n#line 10 \"math/xor_basis.hpp\"\ntemplate\
    \ <std::integral T = long long> struct xor_basis {\n    xor_basis() = default;\n\
    \    int size() const {\n        return int(b.size());\n    }\n    bool insert(T\
    \ x) {\n        x = reduce(x);\n        if (x == 0) return false;\n        T p\
    \ = T(1) << (std::bit_width(std::make_unsigned_t<T>(x)) - 1);\n        for (T&\
    \ v : b) {\n            if (v & p) v ^= x;\n        }\n        b.insert(std::ranges::lower_bound(b,\
    \ x, std::greater<T>()), x);\n        return true;\n    }\n    bool contains(T\
    \ x) const {\n        return reduce(x) == 0;\n    }\n    T max(T xor_val = 0)\
    \ const {\n        check(xor_val);\n        for (T v : b) xor_val = std::max(xor_val,\
    \ T(xor_val ^ v));\n        return xor_val;\n    }\n    T min(T xor_val = 0) const\
    \ {\n        return reduce(xor_val);\n    }\n    T kth_smallest(T k, T xor_val\
    \ = 0) const {\n        int r = size();\n        assert(0 <= k && (r >= std::numeric_limits<T>::digits\
    \ || k < (T(1) << r)));\n        T x = reduce(xor_val);\n        for (int i =\
    \ 0; i < r; i++) {\n            if ((k >> (r - 1 - i)) & 1) x ^= b[i];\n     \
    \   }\n        return x;\n    }\n    T kth_largest(T k, T xor_val = 0) const {\n\
    \        int r = size();\n        T all = r == 0 ? 0 : ((T(1) << (r - 1)) - 1)\
    \ * 2 + 1;\n        assert(0 <= k && k <= all);\n        return kth_smallest(all\
    \ - k, xor_val);\n    }\n\n  private:\n    std::vector<T> b;\n    static void\
    \ check([[maybe_unused]] T x) {\n        if constexpr (std::is_signed_v<T>) assert(x\
    \ >= 0);\n    }\n    T reduce(T x) const {\n        check(x);\n        for (T\
    \ v : b) x = std::min(x, T(x ^ v));\n        return x;\n    }\n};\n#line 10 \"\
    test/unit/xor_basis.test.cpp\"\nint main() {\n    std::mt19937_64 rng(20261027);\n\
    \    for (int iter = 0; iter < 2000; iter++) {\n        int n = rng() % 11, bits\
    \ = 1 + rng() % 10;\n        std::set<long long> span{0};\n        xor_basis<long\
    \ long> xb;\n        for (int i = 0; i < n; i++) {\n            long long x =\
    \ rng() % (1LL << bits);\n            bool in = span.count(x);\n            assert(xb.contains(x)\
    \ == in);\n            assert(xb.insert(x) == !in);\n            if (!in) {\n\
    \                std::set<long long> nxt = span;\n                for (long long\
    \ v : span) nxt.insert(v ^ x);\n                span = nxt;\n            }\n \
    \       }\n        assert((1LL << xb.size()) == (long long)span.size());\n   \
    \     for (long long x = 0; x < (1LL << bits); x++) assert(xb.contains(x) == span.count(x));\n\
    \        for (int t = 0; t < 5; t++) {\n            long long xv = rng() % (1LL\
    \ << bits);\n            std::vector<long long> sorted;\n            for (long\
    \ long v : span) sorted.push_back(v ^ xv);\n            std::sort(sorted.begin(),\
    \ sorted.end());\n            assert(xb.min(xv) == sorted.front());\n        \
    \    assert(xb.max(xv) == sorted.back());\n            for (int k = 0; k < (int)sorted.size();\
    \ k++) {\n                assert(xb.kth_smallest(k, xv) == sorted[k]);\n     \
    \           assert(xb.kth_largest(k, xv) == sorted[sorted.size() - 1 - k]);\n\
    \            }\n        }\n    }\n    {\n        // full rank over 63 bits, signed\
    \ long long\n        xor_basis<long long> xb;\n        for (int i = 0; i < 63;\
    \ i++) assert(xb.insert(1LL << i));\n        assert(xb.size() == 63);\n      \
    \  assert(!xb.insert(rng() >> 1));\n        assert(xb.max() == std::numeric_limits<long\
    \ long>::max());\n        assert(xb.min(12345) == 0);\n        assert(xb.kth_smallest(std::numeric_limits<long\
    \ long>::max()) == std::numeric_limits<long long>::max());\n        assert(xb.kth_largest(0)\
    \ == std::numeric_limits<long long>::max());\n        assert(xb.kth_smallest(777,\
    \ 1000) == 777);\n    }\n    {\n        // unsigned 64-bit, top bit used\n   \
    \     xor_basis<unsigned long long> xb;\n        for (int i = 0; i < 64; i++)\
    \ assert(xb.insert((rng() & ((1ULL << i) - 1)) | (1ULL << i)));\n        assert(xb.size()\
    \ == 64);\n        assert(xb.max() == ~0ULL && xb.min() == 0);\n        assert(xb.kth_smallest(~0ULL)\
    \ == ~0ULL);\n        assert(xb.kth_largest(~0ULL) == 0);\n    }\n    {\n    \
    \    // many inserts\n        xor_basis<long long> xb;\n        int added = 0;\n\
    \        for (int i = 0; i < 200000; i++) added += xb.insert(rng() % (1LL << 60));\n\
    \        assert(added == 60 && xb.size() == 60);\n    }\n    {\n        xor_basis<long\
    \ long> xb;\n        assert(xb.size() == 0 && xb.contains(0) && !xb.contains(1));\n\
    \        assert(xb.max(5) == 5 && xb.min(5) == 5 && xb.kth_smallest(0, 5) == 5\
    \ && xb.kth_largest(0, 5) == 5);\n    }\n    std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <set>\n#include <vector>\n\n#include \"math/xor_basis.hpp\"\nint main()\
    \ {\n    std::mt19937_64 rng(20261027);\n    for (int iter = 0; iter < 2000; iter++)\
    \ {\n        int n = rng() % 11, bits = 1 + rng() % 10;\n        std::set<long\
    \ long> span{0};\n        xor_basis<long long> xb;\n        for (int i = 0; i\
    \ < n; i++) {\n            long long x = rng() % (1LL << bits);\n            bool\
    \ in = span.count(x);\n            assert(xb.contains(x) == in);\n           \
    \ assert(xb.insert(x) == !in);\n            if (!in) {\n                std::set<long\
    \ long> nxt = span;\n                for (long long v : span) nxt.insert(v ^ x);\n\
    \                span = nxt;\n            }\n        }\n        assert((1LL <<\
    \ xb.size()) == (long long)span.size());\n        for (long long x = 0; x < (1LL\
    \ << bits); x++) assert(xb.contains(x) == span.count(x));\n        for (int t\
    \ = 0; t < 5; t++) {\n            long long xv = rng() % (1LL << bits);\n    \
    \        std::vector<long long> sorted;\n            for (long long v : span)\
    \ sorted.push_back(v ^ xv);\n            std::sort(sorted.begin(), sorted.end());\n\
    \            assert(xb.min(xv) == sorted.front());\n            assert(xb.max(xv)\
    \ == sorted.back());\n            for (int k = 0; k < (int)sorted.size(); k++)\
    \ {\n                assert(xb.kth_smallest(k, xv) == sorted[k]);\n          \
    \      assert(xb.kth_largest(k, xv) == sorted[sorted.size() - 1 - k]);\n     \
    \       }\n        }\n    }\n    {\n        // full rank over 63 bits, signed\
    \ long long\n        xor_basis<long long> xb;\n        for (int i = 0; i < 63;\
    \ i++) assert(xb.insert(1LL << i));\n        assert(xb.size() == 63);\n      \
    \  assert(!xb.insert(rng() >> 1));\n        assert(xb.max() == std::numeric_limits<long\
    \ long>::max());\n        assert(xb.min(12345) == 0);\n        assert(xb.kth_smallest(std::numeric_limits<long\
    \ long>::max()) == std::numeric_limits<long long>::max());\n        assert(xb.kth_largest(0)\
    \ == std::numeric_limits<long long>::max());\n        assert(xb.kth_smallest(777,\
    \ 1000) == 777);\n    }\n    {\n        // unsigned 64-bit, top bit used\n   \
    \     xor_basis<unsigned long long> xb;\n        for (int i = 0; i < 64; i++)\
    \ assert(xb.insert((rng() & ((1ULL << i) - 1)) | (1ULL << i)));\n        assert(xb.size()\
    \ == 64);\n        assert(xb.max() == ~0ULL && xb.min() == 0);\n        assert(xb.kth_smallest(~0ULL)\
    \ == ~0ULL);\n        assert(xb.kth_largest(~0ULL) == 0);\n    }\n    {\n    \
    \    // many inserts\n        xor_basis<long long> xb;\n        int added = 0;\n\
    \        for (int i = 0; i < 200000; i++) added += xb.insert(rng() % (1LL << 60));\n\
    \        assert(added == 60 && xb.size() == 60);\n    }\n    {\n        xor_basis<long\
    \ long> xb;\n        assert(xb.size() == 0 && xb.contains(0) && !xb.contains(1));\n\
    \        assert(xb.max(5) == 5 && xb.min(5) == 5 && xb.kth_smallest(0, 5) == 5\
    \ && xb.kth_largest(0, 5) == 5);\n    }\n    std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - math/xor_basis.hpp
  isVerificationFile: true
  path: test/unit/xor_basis.test.cpp
  requiredBy: []
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/xor_basis.test.cpp
layout: document
redirect_from:
- /verify/test/unit/xor_basis.test.cpp
- /verify/test/unit/xor_basis.test.cpp.html
title: test/unit/xor_basis.test.cpp
---
