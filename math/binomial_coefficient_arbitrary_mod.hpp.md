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
    \ math/binomial_coefficient_arbitrary_mod.hpp: line 8: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "#pragma once\n#include <cassert>\n#include <map>\n#include <vector>\n#if\
    \ __has_include(<atcoder/math.hpp>)\n#include <atcoder/math.hpp>\n#else\n#include\
    \ \"atcoder/math.hpp\"\n#endif\n#include \"math/factorize.hpp\"\ntemplate <int\
    \ id = -1>\nstruct binomial_coefficient_arbitrary_mod {\n    static void set_mod(int\
    \ mod) {\n        assert(1 <= mod);\n        m = mod;\n        factors = factorize(m);\n\
    \        f.assign(factors.size(), {});\n        inv_f.assign(factors.size(), {});\n\
    \        max_size = 0;\n    }\n    static long long C(long long n, long long k)\
    \ {\n        if (m == 1 || n < 0 || n < k || k < 0) return 0;\n        ensure(n);\n\
    \        long long r = n - k;\n        std::vector<long long> rems(factors.size()),\
    \ mods(factors.size());\n        int idx = 0;\n        for (auto [p, q] : factors)\
    \ {\n            long long p_q = pow_ll(p, q);\n            mods[idx] = p_q;\n\
    \            long long e1 = 0, e2 = 0;\n            for (long long p_i = p_q;;)\
    \ {\n                e1 += n / p_i - k / p_i - r / p_i;\n                if (p_i\
    \ > n / p) break;\n                p_i *= p;\n            }\n            for (long\
    \ long p_i = p;;) {\n                e2 += n / p_i - k / p_i - r / p_i;\n    \
    \            if (p_i > n / p) break;\n                p_i *= p;\n            }\n\
    \            atcoder::internal::barrett bt((unsigned int)(p_q));\n           \
    \ long long delta = p == 2 && q >= 3 ? 1 : -1;\n            long long rem = delta\
    \ == -1 && e1 & 1 ? p_q - 1 : 1;\n            rem = bt.mul(rem, atcoder::pow_mod(p,\
    \ e2, p_q));\n            for (long long p_i = 1;;) {\n                rem = bt.mul(rem,\
    \ f[idx][(n / p_i) % p_q]);\n                rem = bt.mul(rem, inv_f[idx][(k /\
    \ p_i) % p_q]);\n                rem = bt.mul(rem, inv_f[idx][(r / p_i) % p_q]);\n\
    \                if (p_i > n / p) break;\n                p_i *= p;\n        \
    \    }\n            rems[idx] = rem;\n            idx++;\n        }\n        return\
    \ atcoder::crt(rems, mods).first;\n    }\n\nprivate:\n    static void ensure(long\
    \ long n) {\n        if (max_size > n) return;\n        int idx = 0;\n       \
    \ for (auto [p, q] : factors) {\n            long long p_q = pow_ll(p, q);\n \
    \           int sz = f[idx].size();\n            if ((long long)sz > std::min(p_q\
    \ - 1, n) + 1) continue;\n            f[idx].resize(std::min(p_q - 1, n) + 1);\n\
    \            inv_f[idx].resize(std::min(p_q - 1, n) + 1);\n            max_size\
    \ = std::max(max_size, std::min(p_q - 1, n) + 1);\n            atcoder::internal::barrett\
    \ bt((unsigned int)(p_q));\n            for (int i = sz; i <= std::min(p_q - 1,\
    \ n); i++) {\n                if (i == 0) {\n                    f[idx][i] = 1;\n\
    \                } else {\n                    if (i % p == 0) {\n           \
    \             f[idx][i] = f[idx][i - 1];\n                    } else {\n     \
    \                   f[idx][i] = bt.mul(f[idx][i - 1], i);\n                  \
    \  }\n                }\n                inv_f[idx][i] = atcoder::inv_mod(f[idx][i],\
    \ p_q);\n            }\n            idx++;\n        }\n    }\n    static long\
    \ long pow_ll(long long x, long long n) {\n        assert(0 <= n && 1 <= m);\n\
    \        long long r = 1, y = x;\n        while (n) {\n            if (n & 1)\
    \ r *= y;\n            n >>= 1;\n            if (n) y *= y;\n        }\n     \
    \   return r;\n    }\n    static inline long long m = -1;\n    static inline long\
    \ long max_size = 0;\n    static inline std::map<long long, int> factors{};\n\
    \    static inline std::vector<std::vector<long long>> f{};\n    static inline\
    \ std::vector<std::vector<long long>> inv_f{};\n};\n"
  dependsOn:
  - math/factorize.hpp
  isVerificationFile: false
  path: math/binomial_coefficient_arbitrary_mod.hpp
  requiredBy: []
  timestamp: '2026-05-18 11:48:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/binomial_coefficient.test.cpp
documentation_of: math/binomial_coefficient_arbitrary_mod.hpp
layout: document
title: Binomial Coefficient (Arbitrary Mod)
---

### 概要
- 任意 mod（合成数 OK）に対する二項係数 $\binom{n}{k} \bmod m$ を計算する。
- mod を素因数分解し、各素数べきに対して Lucas の定理（の一般化）で計算したものを CRT で合成する。

### 使い方
- `binomial_coefficient_arbitrary_mod<id = -1>`: mod を実行時に切り替える。`id` を変えれば独立した静的状態を持てる（`atcoder::dynamic_modint` と同じ流儀）。
- `set_mod(mod)`: mod を設定する。キャッシュもリセットされる。
- `C(n, k)`: $\binom{n}{k} \bmod m$ を `long long` で返す。

### 注意
- 同じ `id` に対して `set_mod` を呼び直すと過去のキャッシュは無効化される。複数 mod を同時に扱いたい場合は `id` を分けてインスタンス化する。
