---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/sieve.hpp
    title: Sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/library-checker/enumerate_primes.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n#include <iostream>\n\
    #include <vector>\n\n#line 2 \"math/sieve.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <utility>\n#line 6 \"math/sieve.hpp\"\nstruct sieve {\n\
    public:\n    sieve() : sieve(1) {\n    }\n    explicit sieve(int n) : _n(n), lpf(n\
    \ + 1, 0) {\n        assert(n >= 1);\n        for (int i = 2; i <= n; i++) {\n\
    \            if (lpf[i] == 0) {\n                lpf[i] = i;\n               \
    \ _primes.push_back(i);\n            }\n            for (int p : _primes) {\n\
    \                if (p > lpf[i] || (long long)p * i > n) break;\n            \
    \    lpf[p * i] = p;\n            }\n        }\n    }\n    bool is_prime(int x)\
    \ const {\n        assert(0 <= x && x <= _n);\n        return x >= 2 && lpf[x]\
    \ == x;\n    }\n    int smallest_prime_factor(int x) const {\n        assert(2\
    \ <= x && x <= _n);\n        return lpf[x];\n    }\n    const std::vector<int>&\
    \ primes() const {\n        return _primes;\n    }\n    std::vector<std::pair<int,\
    \ int>> factorize(int x) const {\n        assert(1 <= x && x <= _n);\n       \
    \ std::vector<std::pair<int, int>> ret;\n        while (x > 1) {\n           \
    \ int p = lpf[x];\n            if (!ret.empty() && ret.back().first == p) {\n\
    \                ret.back().second++;\n            } else {\n                ret.emplace_back(p,\
    \ 1);\n            }\n            x /= p;\n        }\n        return ret;\n  \
    \  }\n    std::vector<int> divisors(int x) const {\n        assert(1 <= x && x\
    \ <= _n);\n        std::vector<int> ret = {1};\n        for (auto [p, e] : factorize(x))\
    \ {\n            int sz = int(ret.size());\n            int q = 1;\n         \
    \   for (int i = 0; i < e; i++) {\n                q *= p;\n                for\
    \ (int j = 0; j < sz; j++) ret.push_back(ret[j] * q);\n            }\n       \
    \ }\n        std::ranges::sort(ret);\n        return ret;\n    }\n\nprivate:\n\
    \    int _n;\n    std::vector<int> lpf, _primes;\n};\n#line 6 \"test/library-checker/enumerate_primes.test.cpp\"\
    \n\nint main() {\n    int n, a, b;\n    std::cin >> n >> a >> b;\n    sieve s(n);\n\
    \    const std::vector<int>& p = s.primes();\n    std::vector<int> ans;\n    for\
    \ (int i = b; i < int(p.size()); i += a) ans.push_back(p[i]);\n    std::cout <<\
    \ p.size() << ' ' << ans.size() << '\\n';\n    for (size_t i = 0; i < ans.size();\
    \ i++) std::cout << ans[i] << \" \\n\"[i + 1 == ans.size()];\n    if (ans.empty())\
    \ std::cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"math/sieve.hpp\"\n\nint main() {\n\
    \    int n, a, b;\n    std::cin >> n >> a >> b;\n    sieve s(n);\n    const std::vector<int>&\
    \ p = s.primes();\n    std::vector<int> ans;\n    for (int i = b; i < int(p.size());\
    \ i += a) ans.push_back(p[i]);\n    std::cout << p.size() << ' ' << ans.size()\
    \ << '\\n';\n    for (size_t i = 0; i < ans.size(); i++) std::cout << ans[i] <<\
    \ \" \\n\"[i + 1 == ans.size()];\n    if (ans.empty()) std::cout << '\\n';\n}\n"
  dependsOn:
  - math/sieve.hpp
  isVerificationFile: true
  path: test/library-checker/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/enumerate_primes.test.cpp
- /verify/test/library-checker/enumerate_primes.test.cpp.html
title: test/library-checker/enumerate_primes.test.cpp
---
