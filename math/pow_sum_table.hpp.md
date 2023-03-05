---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/range_update_range_hash.hpp
    title: Range Update Range Hash
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0355.test.cpp
    title: test/aoj/0355.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/pow_sum_table.hpp\"\ntemplate <typename mint>\nstruct\
    \ pow_mod_sums {\n    pow_mod_sums() {\n    }\n    pow_mod_sums(mint base, int\
    \ n) : base(base) {\n        ensure(n);\n    }\n    // sum(pow[0..i])\n    const\
    \ mint& operator[](int i) const {\n        ensure(i);\n        return pow_sums[i];\n\
    \    }\n    void ensure(int n) const {\n        int sz = pow_sums.size();\n  \
    \      if (sz > n) return;\n        pow_sums.resize(n + 1);\n        pows.resize(n\
    \ + 1);\n        for (int i = sz; i <= n; i++) {\n            pows[i] = base *\
    \ pows[i - 1];\n            pow_sums[i] = pow_sums[i - 1] + pows[i - 1];\n   \
    \     }\n    }\n\nprivate:\n    mutable std::vector<mint> pow_sums{0};\n    mutable\
    \ std::vector<mint> pows{1};\n    mint base;\n    static constexpr int mod = mint::mod;\n\
    };\n"
  code: "#pragma once\ntemplate <typename mint>\nstruct pow_mod_sums {\n    pow_mod_sums()\
    \ {\n    }\n    pow_mod_sums(mint base, int n) : base(base) {\n        ensure(n);\n\
    \    }\n    // sum(pow[0..i])\n    const mint& operator[](int i) const {\n   \
    \     ensure(i);\n        return pow_sums[i];\n    }\n    void ensure(int n) const\
    \ {\n        int sz = pow_sums.size();\n        if (sz > n) return;\n        pow_sums.resize(n\
    \ + 1);\n        pows.resize(n + 1);\n        for (int i = sz; i <= n; i++) {\n\
    \            pows[i] = base * pows[i - 1];\n            pow_sums[i] = pow_sums[i\
    \ - 1] + pows[i - 1];\n        }\n    }\n\nprivate:\n    mutable std::vector<mint>\
    \ pow_sums{0};\n    mutable std::vector<mint> pows{1};\n    mint base;\n    static\
    \ constexpr int mod = mint::mod;\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/pow_sum_table.hpp
  requiredBy:
  - string/range_update_range_hash.hpp
  timestamp: '2022-09-10 18:25:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0355.test.cpp
documentation_of: math/pow_sum_table.hpp
layout: document
redirect_from:
- /library/math/pow_sum_table.hpp
- /library/math/pow_sum_table.hpp.html
title: math/pow_sum_table.hpp
---
