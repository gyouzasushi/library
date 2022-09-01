---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/modpow.hpp\"\n#include <cmath>\n#include <unordered_map>\n\
    long long ext_gxd(long long a, long long b, long long& x, long long& y) {\n  \
    \  if (b == 0) {\n        x = 1;\n        y = 0;\n        return a;\n    }\n \
    \   long long q = a / b;\n    long long g = ext_gxd(b, a - q * b, x, y);\n   \
    \ long long z = x - q * y;\n    x = y;\n    y = z;\n    return g;\n}\n\nlong long\
    \ modinv(long long a, long long m) {\n    long long x, y;\n    ext_gxd(a, m, x,\
    \ y);\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n}\n\nlong long modpow(long\
    \ long a, long long n, long long m) {\n    long long ret = 1;\n    long long now\
    \ = a;\n    while (n > 0) {\n        if (n & 1) ret = ret * now % m;\n       \
    \ now = now * now % m;\n        n /= 2;\n    }\n    return ret;\n}\n\n// todo!!\
    \ returns the minimum k s.t. x^k == y (mod m)\nlong long modlog(long long x, long\
    \ long y, long long m) {\n    auto modlog_coprime = [](long long x, long long\
    \ y,\n                             long long m) -> long long {\n        if (x\
    \ == 0) {\n            if (y == 1) return 0;\n            if (y == 0) return 1;\n\
    \            return -1;\n        }\n        const long long p = (long long)std::sqrt(x)\
    \ + 2;\n        std::unordered_map<long long, long long> mp;\n        for (long\
    \ long i = 0, e = 1; i < p; i++) {\n            mp[e] = i;\n            (e *=\
    \ x) %= m;\n        }\n    };\n}\n"
  code: "#pragma once\n#include <cmath>\n#include <unordered_map>\nlong long ext_gxd(long\
    \ long a, long long b, long long& x, long long& y) {\n    if (b == 0) {\n    \
    \    x = 1;\n        y = 0;\n        return a;\n    }\n    long long q = a / b;\n\
    \    long long g = ext_gxd(b, a - q * b, x, y);\n    long long z = x - q * y;\n\
    \    x = y;\n    y = z;\n    return g;\n}\n\nlong long modinv(long long a, long\
    \ long m) {\n    long long x, y;\n    ext_gxd(a, m, x, y);\n    x %= m;\n    if\
    \ (x < 0) x += m;\n    return x;\n}\n\nlong long modpow(long long a, long long\
    \ n, long long m) {\n    long long ret = 1;\n    long long now = a;\n    while\
    \ (n > 0) {\n        if (n & 1) ret = ret * now % m;\n        now = now * now\
    \ % m;\n        n /= 2;\n    }\n    return ret;\n}\n\n// todo!! returns the minimum\
    \ k s.t. x^k == y (mod m)\nlong long modlog(long long x, long long y, long long\
    \ m) {\n    auto modlog_coprime = [](long long x, long long y,\n             \
    \                long long m) -> long long {\n        if (x == 0) {\n        \
    \    if (y == 1) return 0;\n            if (y == 0) return 1;\n            return\
    \ -1;\n        }\n        const long long p = (long long)std::sqrt(x) + 2;\n \
    \       std::unordered_map<long long, long long> mp;\n        for (long long i\
    \ = 0, e = 1; i < p; i++) {\n            mp[e] = i;\n            (e *= x) %= m;\n\
    \        }\n    };\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/modpow.hpp
  requiredBy: []
  timestamp: '2022-09-01 13:39:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modpow.hpp
layout: document
redirect_from:
- /library/math/modpow.hpp
- /library/math/modpow.hpp.html
title: math/modpow.hpp
---
