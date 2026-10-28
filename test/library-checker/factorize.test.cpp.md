---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/factorize.hpp
    title: Factorize
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/library-checker/factorize.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/factorize\"\n\n#line 2 \"math/factorize.hpp\"\
    \n#include <algorithm>\n#include <cassert>\n#include <cstdlib>\n#include <numeric>\n\
    #include <utility>\n#include <vector>\n\nnamespace internal {\n\nlong long modmul(long\
    \ long x, long long y, long long mod) {\n    return (long long)((__int128_t)x\
    \ * y % mod);\n}\n\nlong long modpow(long long a, long long n, long long mod)\
    \ {\n    long long ret = 1;\n    while (n > 0) {\n        if (n & 1) ret = modmul(ret,\
    \ a, mod);\n        a = modmul(a, a, mod);\n        n >>= 1;\n    }\n    return\
    \ ret;\n}\n\nlong long rho(long long n) {\n    long long z = 0;\n    auto f =\
    \ [&](long long x) {\n        long long ret = modmul(x, x, n) + z;\n        return\
    \ ret >= n ? ret - n : ret;\n    };\n    while (true) {\n        long long x =\
    \ ++z;\n        long long y = f(x);\n        while (true) {\n            long\
    \ long d = std::gcd(std::abs(x - y), n);\n            if (d == n) break;\n   \
    \         if (d > 1) return d;\n            x = f(x);\n            y = f(f(y));\n\
    \        }\n    }\n}\n\n}  // namespace internal\n\nbool is_prime(long long n)\
    \ {\n    assert(n >= 1);\n    if (n == 1) return false;\n    if (n % 2 == 0) return\
    \ n == 2;\n    long long d = n - 1, s = 0;\n    while (~d & 1) d >>= 1, s++;\n\
    \    for (long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {\n    \
    \    if (a >= n) break;\n        long long x = internal::modpow(a, d, n);\n  \
    \      if (x == 1) continue;\n        bool ok = false;\n        for (int i = 0;\
    \ i < s; i++) {\n            if (x == n - 1) {\n                ok = true;\n \
    \               break;\n            }\n            x = internal::modmul(x, x,\
    \ n);\n        }\n        if (!ok) return false;\n    }\n    return true;\n}\n\
    \nstd::vector<std::pair<long long, int>> factorize(long long n) {\n    assert(n\
    \ >= 1);\n    std::vector<std::pair<long long, int>> ret;\n    int c = 0;\n  \
    \  while (~n & 1) n >>= 1, c++;\n    if (c > 0) ret.emplace_back(2, c);\n    std::vector<long\
    \ long> st = {n};\n    std::vector<long long> primes;\n    while (!st.empty())\
    \ {\n        long long p = st.back();\n        st.pop_back();\n        if (p ==\
    \ 1) continue;\n        if (is_prime(p)) {\n            primes.push_back(p);\n\
    \            continue;\n        }\n        long long d = internal::rho(p);\n \
    \       st.push_back(d);\n        st.push_back(p / d);\n    }\n    std::ranges::sort(primes);\n\
    \    for (long long p : primes) {\n        if (!ret.empty() && ret.back().first\
    \ == p) {\n            ret.back().second++;\n        } else {\n            ret.emplace_back(p,\
    \ 1);\n        }\n    }\n    return ret;\n}\n\nstd::vector<long long> divisors(long\
    \ long n) {\n    assert(n >= 1);\n    std::vector<long long> ret = {1};\n    for\
    \ (auto [p, e] : factorize(n)) {\n        int sz = int(ret.size());\n        long\
    \ long q = 1;\n        for (int i = 0; i < e; i++) {\n            q *= p;\n  \
    \          for (int j = 0; j < sz; j++) ret.push_back(ret[j] * q);\n        }\n\
    \    }\n    std::ranges::sort(ret);\n    return ret;\n}\n#line 4 \"test/library-checker/factorize.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    int q;\n    std::cin >> q;\n    while\
    \ (q--) {\n        long long a;\n        std::cin >> a;\n        std::vector<long\
    \ long> ans;\n        for (auto [b, c] : factorize(a)) {\n            ans.resize(ans.size()\
    \ + c, b);\n        }\n        int k = ans.size();\n        std::cout << k <<\
    \ ' ';\n        for (int i = 0; i < k; i++) {\n            std::cout << ans[i]\
    \ << \" \\n\"[i == k - 1];\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n#include\
    \ \"math/factorize.hpp\"\n\n#include <iostream>\n\nint main() {\n    int q;\n\
    \    std::cin >> q;\n    while (q--) {\n        long long a;\n        std::cin\
    \ >> a;\n        std::vector<long long> ans;\n        for (auto [b, c] : factorize(a))\
    \ {\n            ans.resize(ans.size() + c, b);\n        }\n        int k = ans.size();\n\
    \        std::cout << k << ' ';\n        for (int i = 0; i < k; i++) {\n     \
    \       std::cout << ans[i] << \" \\n\"[i == k - 1];\n        }\n    }\n}"
  dependsOn:
  - math/factorize.hpp
  isVerificationFile: true
  path: test/library-checker/factorize.test.cpp
  requiredBy: []
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/factorize.test.cpp
- /verify/test/library-checker/factorize.test.cpp.html
title: test/library-checker/factorize.test.cpp
---
