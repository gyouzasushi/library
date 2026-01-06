---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/factorize.hpp
    title: math/factorize.hpp
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
    \n#include <cmath>\n#include <numeric>\nlong long modmul(long long x, long long\
    \ y, long long mod) {\n    using i128 = __int128_t;\n    return (long long)(i128(x)\
    \ * i128(y) % i128(mod));\n}\nlong long modpow(long long a, long long n, long\
    \ long mod) {\n    long long ret = 1;\n    while (n > 0) {\n        if (n & 1)\
    \ ret = modmul(ret, a, mod);\n        a = modmul(a, a, mod);\n        n >>= 1;\n\
    \    }\n    return ret;\n}\nlong long rho(long long n) {\n    long long z = 0;\n\
    \    auto f = [&](long long x) -> long long {\n        long long ret = modmul(x,\
    \ x, n) + z;\n        if (ret == n) return 0;\n        return ret;\n    };\n \
    \   while (true) {\n        long long x = ++z;\n        long long y = f(x);\n\
    \        while (true) {\n            long long d = std::gcd(std::abs(x - y), n);\n\
    \            if (d == n) break;\n            if (d > 1) return d;\n          \
    \  x = f(x);\n            y = f(f(y));\n        }\n    }\n}\n#include <initializer_list>\n\
    bool miller_rabin(long long n) {\n    if (n == 1) return 0;\n    long long d =\
    \ n - 1, s = 0;\n    while (~d & 1) d >>= 1, s++;\n    auto check = [&](long long\
    \ a) -> bool {\n        long long x = modpow(a, d, n);\n        if (x == 1) return\
    \ 1;\n        long long y = n - 1;\n        for (int i = 0; i < s; i++) {\n  \
    \          if (x == y) return true;\n            x = modmul(x, x, n);\n      \
    \  }\n        return false;\n    };\n    for (long long a : {2, 3, 5, 7, 11, 13,\
    \ 17, 19, 23, 29, 31, 37}) {\n        if (a >= n) break;\n        if (!check(a))\
    \ return false;\n    }\n    return true;\n}\n#include <map>\n#include <queue>\n\
    std::map<long long, int> factorize(long long n) {\n    std::map<long long, int>\
    \ ret;\n    while (~n & 1) n >>= 1, ret[2]++;\n    std::queue<long long> q;\n\
    \    q.push(n);\n    while (!q.empty()) {\n        long long p = q.front();\n\
    \        q.pop();\n        if (p == 1) continue;\n        if (miller_rabin(p))\
    \ {\n            ret[p]++;\n            continue;\n        }\n        long long\
    \ d = rho(p);\n        q.push(d);\n        q.push(p / d);\n    }\n    return ret;\n\
    }\n#line 4 \"test/library-checker/factorize.test.cpp\"\n\n#include <iostream>\n\
    \nint main() {\n    int q;\n    std::cin >> q;\n    while (q--) {\n        long\
    \ long a;\n        std::cin >> a;\n        std::vector<long long> ans;\n     \
    \   for (auto [b, c] : factorize(a)) {\n            ans.resize(ans.size() + c,\
    \ b);\n        }\n        int k = ans.size();\n        std::cout << k << ' ';\n\
    \        for (int i = 0; i < k; i++) {\n            std::cout << ans[i] << \"\
    \ \\n\"[i == k - 1];\n        }\n    }\n}\n"
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
  timestamp: '2024-05-30 15:02:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/factorize.test.cpp
- /verify/test/library-checker/factorize.test.cpp.html
title: test/library-checker/factorize.test.cpp
---
