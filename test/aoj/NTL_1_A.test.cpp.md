---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/sieve.hpp
    title: Sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_A
  bundledCode: "#line 1 \"test/aoj/NTL_1_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_A\"\
    \n#include <iostream>\n\n#line 2 \"math/sieve.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\nstruct sieve {\npublic:\n\
    \    sieve() : sieve(1) {\n    }\n    explicit sieve(int n) : _n(n), lpf(n + 1,\
    \ 0) {\n        assert(n >= 1);\n        for (int i = 2; i <= n; i++) {\n    \
    \        if (lpf[i] == 0) {\n                lpf[i] = i;\n                _primes.push_back(i);\n\
    \            }\n            for (int p : _primes) {\n                if (p > lpf[i]\
    \ || (long long)p * i > n) break;\n                lpf[p * i] = p;\n         \
    \   }\n        }\n    }\n    bool is_prime(int x) const {\n        assert(0 <=\
    \ x && x <= _n);\n        return x >= 2 && lpf[x] == x;\n    }\n    int smallest_prime_factor(int\
    \ x) const {\n        assert(2 <= x && x <= _n);\n        return lpf[x];\n   \
    \ }\n    const std::vector<int>& primes() const {\n        return _primes;\n \
    \   }\n    std::vector<std::pair<int, int>> factorize(int x) const {\n       \
    \ assert(1 <= x && x <= _n);\n        std::vector<std::pair<int, int>> ret;\n\
    \        while (x > 1) {\n            int p = lpf[x];\n            if (!ret.empty()\
    \ && ret.back().first == p) {\n                ret.back().second++;\n        \
    \    } else {\n                ret.emplace_back(p, 1);\n            }\n      \
    \      x /= p;\n        }\n        return ret;\n    }\n    std::vector<int> divisors(int\
    \ x) const {\n        assert(1 <= x && x <= _n);\n        std::vector<int> ret\
    \ = {1};\n        for (auto [p, e] : factorize(x)) {\n            int sz = int(ret.size());\n\
    \            int q = 1;\n            for (int i = 0; i < e; i++) {\n         \
    \       q *= p;\n                for (int j = 0; j < sz; j++) ret.push_back(ret[j]\
    \ * q);\n            }\n        }\n        std::sort(ret.begin(), ret.end());\n\
    \        return ret;\n    }\n\nprivate:\n    int _n;\n    std::vector<int> lpf,\
    \ _primes;\n};\n#line 5 \"test/aoj/NTL_1_A.test.cpp\"\n\nint main() {\n    int\
    \ n;\n    std::cin >> n;\n    sieve s(n);\n    std::cout << n << ':';\n    for\
    \ (auto [p, e] : s.factorize(n)) {\n        for (int i = 0; i < e; i++) std::cout\
    \ << ' ' << p;\n    }\n    std::cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_A\"\n#include\
    \ <iostream>\n\n#include \"math/sieve.hpp\"\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n    sieve s(n);\n    std::cout << n << ':';\n    for (auto [p, e] : s.factorize(n))\
    \ {\n        for (int i = 0; i < e; i++) std::cout << ' ' << p;\n    }\n    std::cout\
    \ << '\\n';\n}\n"
  dependsOn:
  - math/sieve.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_A.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 01:59:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_A.test.cpp
- /verify/test/aoj/NTL_1_A.test.cpp.html
title: test/aoj/NTL_1_A.test.cpp
---
