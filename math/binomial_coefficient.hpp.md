---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/binomial_coefficient.test.cpp
    title: test/library-checker/binomial_coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/binomial_coefficient_prime_mod.test.cpp
    title: test/library-checker/binomial_coefficient_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/117.test.cpp
    title: test/yukicoder/117.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/binomial_coefficient.hpp: line 50: unable to process #include in #if /\
    \ #ifdef / #ifndef other than include guards\n"
  code: "#pragma once\n#include <vector>\ntemplate <typename mint>\nstruct factorial_table\
    \ {\n    static mint val(int i) {\n        ensure(i);\n        return facts[i];\n\
    \    }\n    static mint inv(int i) {\n        ensure(i);\n        return ifacts[i];\n\
    \    }\n    static void ensure(int n) {\n        int sz = facts.size();\n    \
    \    if (sz > n) return;\n        if (n < sz << 1) n = std::min(mint::mod() -\
    \ 1, sz << 1);\n        facts.resize(n + 1);\n        ifacts.resize(n + 1);\n\
    \        for (int i = sz; i <= n; i++) facts[i] = facts[i - 1] * i;\n        ifacts[n]\
    \ = facts[n].inv();\n        for (int i = n; i >= sz; i--) ifacts[i - 1] = ifacts[i]\
    \ * i;\n    }\n\nprivate:\n    static inline std::vector<mint> facts{1};\n   \
    \ static inline std::vector<mint> ifacts{1};\n};\n\ntemplate <typename mint>\n\
    struct binomial_coefficient {\n    using facts = factorial_table<mint>;\n    static\
    \ mint C(int n, int k) {\n        if (n < 0 || n < k || k < 0) return 0;\n   \
    \     return facts::val(n) * facts::inv(n - k) * facts::inv(k);\n    }\n    static\
    \ mint P(int n, int k) {\n        if (n < 0 || n < k || k < 0) return 0;\n   \
    \     return facts::val(n) * facts::inv(n - k);\n    }\n    static mint H(int\
    \ n, int k) {\n        if (n < 0 || k < 0) return 0;\n        if (k == 0) return\
    \ 1;\n        return C(n + k - 1, k);\n    }\n};\n\n#if __has_include(<atcoder/math.hpp>)\n\
    #include <atcoder/math.hpp>\n#else\n#include \"atcoder/math.hpp\"\n#endif\n#include\
    \ \"math/factorize.hpp\"\ntemplate <int id = -1>\nstruct binomial_coefficient_arbitrary_mod\
    \ {\n    static void set_mod(int mod) {\n        assert(1 <= mod);\n        m\
    \ = mod;\n        factors = factorize(m);\n        f.assign(factors.size(), {});\n\
    \        inv_f.assign(factors.size(), {});\n        max_size = 0;\n    }\n   \
    \ static long long C(long long n, long long k) {\n        if (m == 1 || n < 0\
    \ || n < k || k < 0) return 0;\n        ensure(n);\n        long long r = n -\
    \ k;\n        std::vector<long long> rems(factors.size()), mods(factors.size());\n\
    \        int idx = 0;\n        for (auto [p, q] : factors) {\n            long\
    \ long p_q = pow_ll(p, q);\n            mods[idx] = p_q;\n            long long\
    \ e1 = 0, e2 = 0;\n            for (long long p_i = p_q;;) {\n               \
    \ e1 += n / p_i - k / p_i - r / p_i;\n                if (p_i > n / p) break;\n\
    \                p_i *= p;\n            }\n            for (long long p_i = p;;)\
    \ {\n                e2 += n / p_i - k / p_i - r / p_i;\n                if (p_i\
    \ > n / p) break;\n                p_i *= p;\n            }\n            atcoder::internal::barrett\
    \ bt((unsigned int)(p_q));\n            long long delta = p == 2 && q >= 3 ? 1\
    \ : -1;\n            long long rem = delta == -1 && e1 & 1 ? p_q - 1 : 1;\n  \
    \          rem = bt.mul(rem, atcoder::pow_mod(p, e2, p_q));\n            for (long\
    \ long p_i = 1;;) {\n                rem = bt.mul(rem, f[idx][(n / p_i) % p_q]);\n\
    \                rem = bt.mul(rem, inv_f[idx][(k / p_i) % p_q]);\n           \
    \     rem = bt.mul(rem, inv_f[idx][(r / p_i) % p_q]);\n                if (p_i\
    \ > n / p) break;\n                p_i *= p;\n            }\n            rems[idx]\
    \ = rem;\n            idx++;\n        }\n        return atcoder::crt(rems, mods).first;\n\
    \    }\n\nprivate:\n    static void ensure(long long n) {\n        if (max_size\
    \ > n) return;\n        int idx = 0;\n        for (auto [p, q] : factors) {\n\
    \            long long p_q = pow_ll(p, q);\n            int sz = f[idx].size();\n\
    \            if ((long long)sz > std::min(p_q - 1, n) + 1) continue;\n       \
    \     f[idx].resize(std::min(p_q - 1, n) + 1);\n            inv_f[idx].resize(std::min(p_q\
    \ - 1, n) + 1);\n            max_size = std::max(max_size, std::min(p_q - 1, n)\
    \ + 1);\n            atcoder::internal::barrett bt((unsigned int)(p_q));\n   \
    \         for (int i = sz; i <= std::min(p_q - 1, n); i++) {\n               \
    \ if (i == 0) {\n                    f[idx][i] = 1;\n                } else {\n\
    \                    if (i % p == 0) {\n                        f[idx][i] = f[idx][i\
    \ - 1];\n                    } else {\n                        f[idx][i] = bt.mul(f[idx][i\
    \ - 1], i);\n                    }\n                }\n                inv_f[idx][i]\
    \ = atcoder::inv_mod(f[idx][i], p_q);\n            }\n            idx++;\n   \
    \     }\n    }\n    static long long pow_ll(long long x, long long n) {\n    \
    \    assert(0 <= n && 1 <= m);\n        long long r = 1, y = x;\n        while\
    \ (n) {\n            if (n & 1) r *= y;\n            n >>= 1;\n            if\
    \ (n) y *= y;\n        }\n        return r;\n    }\n    static inline long long\
    \ m = -1;\n    static inline long long max_size = 0;\n    static inline std::map<long\
    \ long, int> factors{};\n    static inline std::vector<std::vector<long long>>\
    \ f{};\n    static inline std::vector<std::vector<long long>> inv_f{};\n};\n"
  dependsOn:
  - math/factorize.hpp
  isVerificationFile: false
  path: math/binomial_coefficient.hpp
  requiredBy: []
  timestamp: '2026-05-18 11:14:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/117.test.cpp
  - test/library-checker/binomial_coefficient_prime_mod.test.cpp
  - test/library-checker/binomial_coefficient.test.cpp
documentation_of: math/binomial_coefficient.hpp
layout: document
redirect_from:
- /library/math/binomial_coefficient.hpp
- /library/math/binomial_coefficient.hpp.html
title: math/binomial_coefficient.hpp
---
