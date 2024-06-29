---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/range_update_range_hash.hpp
    title: Range Update Range Hash
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: Rolling Hash
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0355.test.cpp
    title: test/aoj/0355.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/enumerate_palindromes.test.cpp
    title: test/library-checker/enumerate_palindromes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/suffix_array_rolling_hash.test.cpp
    title: test/library-checker/suffix_array_rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/zalgorithm_rolling_hash.test.cpp
    title: test/library-checker/zalgorithm_rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2231.test.cpp
    title: test/yukicoder/2231.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/pow_table.hpp\"\n#include <vector>\ntemplate <typename\
    \ mint>\nstruct pow_mods {\n    pow_mods() {\n    }\n    pow_mods(mint base, int\
    \ n) : base(base) {\n        ensure(n);\n    }\n    const mint& operator[](int\
    \ i) const {\n        ensure(i);\n        return pows[i];\n    }\n    void ensure(int\
    \ n) const {\n        int sz = pows.size();\n        if (sz > n) return;\n   \
    \     pows.resize(n + 1);\n        for (int i = sz; i <= n; i++) pows[i] = base\
    \ * pows[i - 1];\n    }\n\nprivate:\n    mutable std::vector<mint> pows{1};\n\
    \    mint base;\n    static constexpr int mod = mint::mod;\n};\n"
  code: "#pragma once\n#include <vector>\ntemplate <typename mint>\nstruct pow_mods\
    \ {\n    pow_mods() {\n    }\n    pow_mods(mint base, int n) : base(base) {\n\
    \        ensure(n);\n    }\n    const mint& operator[](int i) const {\n      \
    \  ensure(i);\n        return pows[i];\n    }\n    void ensure(int n) const {\n\
    \        int sz = pows.size();\n        if (sz > n) return;\n        pows.resize(n\
    \ + 1);\n        for (int i = sz; i <= n; i++) pows[i] = base * pows[i - 1];\n\
    \    }\n\nprivate:\n    mutable std::vector<mint> pows{1};\n    mint base;\n \
    \   static constexpr int mod = mint::mod;\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/pow_table.hpp
  requiredBy:
  - string/rolling_hash.hpp
  - string/range_update_range_hash.hpp
  timestamp: '2022-09-10 18:25:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2231.test.cpp
  - test/aoj/0355.test.cpp
  - test/library-checker/enumerate_palindromes.test.cpp
  - test/library-checker/zalgorithm_rolling_hash.test.cpp
  - test/library-checker/suffix_array_rolling_hash.test.cpp
documentation_of: math/pow_table.hpp
layout: document
redirect_from:
- /library/math/pow_table.hpp
- /library/math/pow_table.hpp.html
title: math/pow_table.hpp
---
