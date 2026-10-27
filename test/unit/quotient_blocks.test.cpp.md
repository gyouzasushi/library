---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/quotient_blocks.hpp
    title: Quotient Blocks
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
  bundledCode: "#line 1 \"test/unit/quotient_blocks.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <cassert>\n#include <cmath>\n#include <iostream>\n#include <vector>\n\n#line\
    \ 4 \"math/quotient_blocks.hpp\"\nstruct quotient_block {\n    long long l, r,\
    \ q;\n};\nstd::vector<quotient_block> quotient_blocks(long long n) {\n    assert(n\
    \ >= 0);\n    std::vector<quotient_block> ret;\n    for (long long l = 1; l <=\
    \ n;) {\n        long long q = n / l, r = n / q + 1;\n        ret.push_back({l,\
    \ r, q});\n        l = r;\n    }\n    return ret;\n}\n#line 8 \"test/unit/quotient_blocks.test.cpp\"\
    \nvoid check(long long n) {\n    auto bs = quotient_blocks(n);\n    long long\
    \ expect_l = 1;\n    for (auto [l, r, q] : bs) {\n        assert(l == expect_l\
    \ && l < r && r <= n + 1);\n        assert(n / l == q && n / (r - 1) == q);\n\
    \        assert(r == n + 1 || n / r < q);\n        expect_l = r;\n    }\n    assert(expect_l\
    \ == n + 1);\n}\nint main() {\n    for (long long n = 0; n <= 2000; n++) check(n);\n\
    \    for (long long n : {1000000000000LL, 999999999999LL, 1000003LL * 999983LL,\
    \ (1LL << 40)}) {\n        check(n);\n        assert((long long)quotient_blocks(n).size()\
    \ <= 2 * (long long)std::sqrt((double)n) + 2);\n    }\n    assert(quotient_blocks(0).empty());\n\
    \    assert(quotient_blocks(1).size() == 1);\n    // \u03A3_{i=1}^{n} floor(n\
    \ / i) via blocks equals direct sum\n    for (long long n : {1LL, 10LL, 12345LL,\
    \ 100000LL}) {\n        long long direct = 0;\n        for (long long i = 1; i\
    \ <= n; i++) direct += n / i;\n        long long blocks = 0;\n        for (auto\
    \ [l, r, q] : quotient_blocks(n)) blocks += (r - l) * q;\n        assert(direct\
    \ == blocks);\n    }\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <cmath>\n#include <iostream>\n#include <vector>\n\
    \n#include \"math/quotient_blocks.hpp\"\nvoid check(long long n) {\n    auto bs\
    \ = quotient_blocks(n);\n    long long expect_l = 1;\n    for (auto [l, r, q]\
    \ : bs) {\n        assert(l == expect_l && l < r && r <= n + 1);\n        assert(n\
    \ / l == q && n / (r - 1) == q);\n        assert(r == n + 1 || n / r < q);\n \
    \       expect_l = r;\n    }\n    assert(expect_l == n + 1);\n}\nint main() {\n\
    \    for (long long n = 0; n <= 2000; n++) check(n);\n    for (long long n : {1000000000000LL,\
    \ 999999999999LL, 1000003LL * 999983LL, (1LL << 40)}) {\n        check(n);\n \
    \       assert((long long)quotient_blocks(n).size() <= 2 * (long long)std::sqrt((double)n)\
    \ + 2);\n    }\n    assert(quotient_blocks(0).empty());\n    assert(quotient_blocks(1).size()\
    \ == 1);\n    // \u03A3_{i=1}^{n} floor(n / i) via blocks equals direct sum\n\
    \    for (long long n : {1LL, 10LL, 12345LL, 100000LL}) {\n        long long direct\
    \ = 0;\n        for (long long i = 1; i <= n; i++) direct += n / i;\n        long\
    \ long blocks = 0;\n        for (auto [l, r, q] : quotient_blocks(n)) blocks +=\
    \ (r - l) * q;\n        assert(direct == blocks);\n    }\n    std::cout << \"\
    Hello World\" << std::endl;\n}\n"
  dependsOn:
  - math/quotient_blocks.hpp
  isVerificationFile: true
  path: test/unit/quotient_blocks.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 12:15:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/quotient_blocks.test.cpp
layout: document
redirect_from:
- /verify/test/unit/quotient_blocks.test.cpp
- /verify/test/unit/quotient_blocks.test.cpp.html
title: test/unit/quotient_blocks.test.cpp
---
