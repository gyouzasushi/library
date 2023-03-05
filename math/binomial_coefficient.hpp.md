---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/117.test.cpp
    title: test/yukicoder/117.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/binomial_coefficient.hpp\"\n#include <vector>\ntemplate\
    \ <typename mint>\nstruct factorial_table {\n    static mint val(int i) {\n  \
    \      ensure(i);\n        return facts[i];\n    }\n    static mint inv(int i)\
    \ {\n        ensure(i);\n        return ifacts[i];\n    }\n    static void ensure(int\
    \ n) {\n        int sz = facts.size();\n        if (sz > n) return;\n        if\
    \ (n < sz << 1) n = sz << 1;\n        facts.resize(n + 1);\n        ifacts.resize(n\
    \ + 1);\n        for (int i = sz; i <= n; i++) facts[i] = facts[i - 1] * i;\n\
    \        ifacts[n] = facts[n].inv();\n        for (int i = n; i >= sz; i--) ifacts[i\
    \ - 1] = ifacts[i] * i;\n    }\n\nprivate:\n    static inline std::vector<mint>\
    \ facts{1};\n    static inline std::vector<mint> ifacts{1};\n};\n\ntemplate <typename\
    \ mint>\nstruct binomial_coefficient {\n    using facts = factorial_table<mint>;\n\
    \    static mint C(int n, int k) {\n        if (n < 0 || n < k || k < 0) return\
    \ 0;\n        return facts::val(n) * facts::inv(n - k) * facts::inv(k);\n    }\n\
    \    static mint P(int n, int k) {\n        if (n < 0 || n < k || k < 0) return\
    \ 0;\n        return facts::val(n) * facts::inv(n - k);\n    }\n    static mint\
    \ H(int n, int k) {\n        if (n < 0 || k < 0) return 0;\n        if (k == 0)\
    \ return 1;\n        return C(n + k - 1, k);\n    }\n};\n\ntemplate <typename\
    \ mint>\nstruct binomial_coefficient_arbitrary_mod {};\n"
  code: "#pragma once\n#include <vector>\ntemplate <typename mint>\nstruct factorial_table\
    \ {\n    static mint val(int i) {\n        ensure(i);\n        return facts[i];\n\
    \    }\n    static mint inv(int i) {\n        ensure(i);\n        return ifacts[i];\n\
    \    }\n    static void ensure(int n) {\n        int sz = facts.size();\n    \
    \    if (sz > n) return;\n        if (n < sz << 1) n = sz << 1;\n        facts.resize(n\
    \ + 1);\n        ifacts.resize(n + 1);\n        for (int i = sz; i <= n; i++)\
    \ facts[i] = facts[i - 1] * i;\n        ifacts[n] = facts[n].inv();\n        for\
    \ (int i = n; i >= sz; i--) ifacts[i - 1] = ifacts[i] * i;\n    }\n\nprivate:\n\
    \    static inline std::vector<mint> facts{1};\n    static inline std::vector<mint>\
    \ ifacts{1};\n};\n\ntemplate <typename mint>\nstruct binomial_coefficient {\n\
    \    using facts = factorial_table<mint>;\n    static mint C(int n, int k) {\n\
    \        if (n < 0 || n < k || k < 0) return 0;\n        return facts::val(n)\
    \ * facts::inv(n - k) * facts::inv(k);\n    }\n    static mint P(int n, int k)\
    \ {\n        if (n < 0 || n < k || k < 0) return 0;\n        return facts::val(n)\
    \ * facts::inv(n - k);\n    }\n    static mint H(int n, int k) {\n        if (n\
    \ < 0 || k < 0) return 0;\n        if (k == 0) return 1;\n        return C(n +\
    \ k - 1, k);\n    }\n};\n\ntemplate <typename mint>\nstruct binomial_coefficient_arbitrary_mod\
    \ {};"
  dependsOn: []
  isVerificationFile: false
  path: math/binomial_coefficient.hpp
  requiredBy: []
  timestamp: '2023-03-05 15:52:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/117.test.cpp
documentation_of: math/binomial_coefficient.hpp
layout: document
redirect_from:
- /library/math/binomial_coefficient.hpp
- /library/math/binomial_coefficient.hpp.html
title: math/binomial_coefficient.hpp
---
