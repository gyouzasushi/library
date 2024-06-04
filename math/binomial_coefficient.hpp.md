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
    \ return 1;\n        return C(n + k - 1, k);\n    }\n};\n\n#include <atcoder/math.hpp>\n\
    \n#line 2 \"math/factorize.hpp\"\n#include <cmath>\n#include <numeric>\nlong long\
    \ modmul(long long x, long long y, long long mod) {\n    using i128 = __int128_t;\n\
    \    return (long long)(i128(x) * i128(y) % i128(mod));\n}\nlong long modpow(long\
    \ long a, long long n, long long mod) {\n    long long ret = 1;\n    while (n\
    \ > 0) {\n        if (n & 1) ret = modmul(ret, a, mod);\n        a = modmul(a,\
    \ a, mod);\n        n >>= 1;\n    }\n    return ret;\n}\nlong long rho(long long\
    \ n) {\n    long long z = 0;\n    auto f = [&](long long x) -> long long {\n \
    \       long long ret = modmul(x, x, n) + z;\n        if (ret == n) return 0;\n\
    \        return ret;\n    };\n    while (true) {\n        long long x = ++z;\n\
    \        long long y = f(x);\n        while (true) {\n            long long d\
    \ = std::gcd(std::abs(x - y), n);\n            if (d == n) break;\n          \
    \  if (d > 1) return d;\n            x = f(x);\n            y = f(f(y));\n   \
    \     }\n    }\n}\n#include <initializer_list>\nbool miller_rabin(long long n)\
    \ {\n    if (n == 1) return 0;\n    long long d = n - 1, s = 0;\n    while (~d\
    \ & 1) d >>= 1, s++;\n    auto check = [&](long long a) -> bool {\n        long\
    \ long x = modpow(a, d, n);\n        if (x == 1) return 1;\n        long long\
    \ y = n - 1;\n        for (int i = 0; i < s; i++) {\n            if (x == y) return\
    \ true;\n            x = modmul(x, x, n);\n        }\n        return false;\n\
    \    };\n    for (long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})\
    \ {\n        if (a >= n) break;\n        if (!check(a)) return false;\n    }\n\
    \    return true;\n}\n#include <map>\n#include <queue>\nstd::map<long long, int>\
    \ factorize(long long n) {\n    std::map<long long, int> ret;\n    while (~n &\
    \ 1) n >>= 1, ret[2]++;\n    std::queue<long long> q;\n    q.push(n);\n    while\
    \ (!q.empty()) {\n        long long p = q.front();\n        q.pop();\n       \
    \ if (p == 1) continue;\n        if (miller_rabin(p)) {\n            ret[p]++;\n\
    \            continue;\n        }\n        long long d = rho(p);\n        q.push(d);\n\
    \        q.push(p / d);\n    }\n    return ret;\n}\n#line 50 \"math/binomial_coefficient.hpp\"\
    \nstruct binomial_coefficient_arbitrary_mod {\n    static void set_mod(int mod)\
    \ {\n        assert(1 <= mod);\n        m = mod;\n        factors = factorize(m);\n\
    \        f.assign(factors.size(), {});\n        inv_f.assign(factors.size(), {});\n\
    \    }\n    static long long C(long long n, long long k) {\n        if (m == 1\
    \ || n < 0 || n < k || k < 0) return 0;\n        ensure(n);\n        long long\
    \ r = n - k;\n        std::vector<long long> rems(factors.size()), mods(factors.size());\n\
    \        int id = 0;\n        for (auto [p, q] : factors) {\n            long\
    \ long p_q = pow_ll(p, q);\n            mods[id] = p_q;\n            long long\
    \ e1 = 0, e2 = 0;\n            for (long long p_i = p_q;;) {\n               \
    \ e1 += n / p_i - k / p_i - r / p_i;\n                if (p_i > n / p) break;\n\
    \                p_i *= p;\n            }\n            for (long long p_i = p;;)\
    \ {\n                e2 += n / p_i - k / p_i - r / p_i;\n                if (p_i\
    \ > n / p) break;\n                p_i *= p;\n            }\n            atcoder::internal::barrett\
    \ bt((unsigned int)(p_q));\n            long long delta = p == 2 && q >= 3 ? 1\
    \ : -1;\n            long long rem = delta == -1 && e1 & 1 ? p_q - 1 : 1;\n  \
    \          rem = bt.mul(rem, atcoder::pow_mod(p, e2, p_q));\n            for (long\
    \ long p_i = 1;;) {\n                rem = bt.mul(rem, f[id][(n / p_i) % p_q]);\n\
    \                rem = bt.mul(rem, inv_f[id][(k / p_i) % p_q]);\n            \
    \    rem = bt.mul(rem, inv_f[id][(r / p_i) % p_q]);\n                if (p_i >\
    \ n / p) break;\n                p_i *= p;\n            }\n            rems[id]\
    \ = rem;\n            id++;\n        }\n        return atcoder::crt(rems, mods).first;\n\
    \    }\n\nprivate:\n    static void ensure(long long n) {\n        if (max_size\
    \ > n) return;\n        int id = 0;\n        for (auto [p, q] : factors) {\n \
    \           long long p_q = pow_ll(p, q);\n            int sz = f[id].size();\n\
    \            if ((long long)sz > std::min(p_q - 1, n) + 1) continue;\n       \
    \     f[id].resize(std::min(p_q - 1, n) + 1);\n            inv_f[id].resize(std::min(p_q\
    \ - 1, n) + 1);\n            max_size = std::max(max_size, std::min(p_q - 1, n)\
    \ + 1);\n            atcoder::internal::barrett bt((unsigned int)(p_q));\n   \
    \         for (int i = sz; i <= std::min(p_q - 1, n); i++) {\n               \
    \ if (i == 0) {\n                    f[id][i] = 1;\n                } else {\n\
    \                    if (i % p == 0) {\n                        f[id][i] = f[id][i\
    \ - 1];\n                    } else {\n                        f[id][i] = bt.mul(f[id][i\
    \ - 1], i);\n                    }\n                }\n                inv_f[id][i]\
    \ = atcoder::inv_mod(f[id][i], p_q);\n            }\n            id++;\n     \
    \   }\n    }\n    static long long pow_ll(long long x, long long n) {\n      \
    \  assert(0 <= n && 1 <= m);\n        long long r = 1, y = x;\n        while (n)\
    \ {\n            if (n & 1) r *= y;\n            n >>= 1;\n            if (n)\
    \ y *= y;\n        }\n        return r;\n    }\n    static inline long long m\
    \ = -1;\n    static inline long long max_size = 0;\n    static inline std::map<long\
    \ long, int> factors{};\n    static inline std::vector<std::vector<long long>>\
    \ f{};\n    static inline std::vector<std::vector<long long>> inv_f{};\n};\n"
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
    \ k - 1, k);\n    }\n};\n\n#include <atcoder/math.hpp>\n\n#include \"math/factorize.hpp\"\
    \nstruct binomial_coefficient_arbitrary_mod {\n    static void set_mod(int mod)\
    \ {\n        assert(1 <= mod);\n        m = mod;\n        factors = factorize(m);\n\
    \        f.assign(factors.size(), {});\n        inv_f.assign(factors.size(), {});\n\
    \    }\n    static long long C(long long n, long long k) {\n        if (m == 1\
    \ || n < 0 || n < k || k < 0) return 0;\n        ensure(n);\n        long long\
    \ r = n - k;\n        std::vector<long long> rems(factors.size()), mods(factors.size());\n\
    \        int id = 0;\n        for (auto [p, q] : factors) {\n            long\
    \ long p_q = pow_ll(p, q);\n            mods[id] = p_q;\n            long long\
    \ e1 = 0, e2 = 0;\n            for (long long p_i = p_q;;) {\n               \
    \ e1 += n / p_i - k / p_i - r / p_i;\n                if (p_i > n / p) break;\n\
    \                p_i *= p;\n            }\n            for (long long p_i = p;;)\
    \ {\n                e2 += n / p_i - k / p_i - r / p_i;\n                if (p_i\
    \ > n / p) break;\n                p_i *= p;\n            }\n            atcoder::internal::barrett\
    \ bt((unsigned int)(p_q));\n            long long delta = p == 2 && q >= 3 ? 1\
    \ : -1;\n            long long rem = delta == -1 && e1 & 1 ? p_q - 1 : 1;\n  \
    \          rem = bt.mul(rem, atcoder::pow_mod(p, e2, p_q));\n            for (long\
    \ long p_i = 1;;) {\n                rem = bt.mul(rem, f[id][(n / p_i) % p_q]);\n\
    \                rem = bt.mul(rem, inv_f[id][(k / p_i) % p_q]);\n            \
    \    rem = bt.mul(rem, inv_f[id][(r / p_i) % p_q]);\n                if (p_i >\
    \ n / p) break;\n                p_i *= p;\n            }\n            rems[id]\
    \ = rem;\n            id++;\n        }\n        return atcoder::crt(rems, mods).first;\n\
    \    }\n\nprivate:\n    static void ensure(long long n) {\n        if (max_size\
    \ > n) return;\n        int id = 0;\n        for (auto [p, q] : factors) {\n \
    \           long long p_q = pow_ll(p, q);\n            int sz = f[id].size();\n\
    \            if ((long long)sz > std::min(p_q - 1, n) + 1) continue;\n       \
    \     f[id].resize(std::min(p_q - 1, n) + 1);\n            inv_f[id].resize(std::min(p_q\
    \ - 1, n) + 1);\n            max_size = std::max(max_size, std::min(p_q - 1, n)\
    \ + 1);\n            atcoder::internal::barrett bt((unsigned int)(p_q));\n   \
    \         for (int i = sz; i <= std::min(p_q - 1, n); i++) {\n               \
    \ if (i == 0) {\n                    f[id][i] = 1;\n                } else {\n\
    \                    if (i % p == 0) {\n                        f[id][i] = f[id][i\
    \ - 1];\n                    } else {\n                        f[id][i] = bt.mul(f[id][i\
    \ - 1], i);\n                    }\n                }\n                inv_f[id][i]\
    \ = atcoder::inv_mod(f[id][i], p_q);\n            }\n            id++;\n     \
    \   }\n    }\n    static long long pow_ll(long long x, long long n) {\n      \
    \  assert(0 <= n && 1 <= m);\n        long long r = 1, y = x;\n        while (n)\
    \ {\n            if (n & 1) r *= y;\n            n >>= 1;\n            if (n)\
    \ y *= y;\n        }\n        return r;\n    }\n    static inline long long m\
    \ = -1;\n    static inline long long max_size = 0;\n    static inline std::map<long\
    \ long, int> factors{};\n    static inline std::vector<std::vector<long long>>\
    \ f{};\n    static inline std::vector<std::vector<long long>> inv_f{};\n};"
  dependsOn:
  - math/factorize.hpp
  isVerificationFile: false
  path: math/binomial_coefficient.hpp
  requiredBy: []
  timestamp: '2024-05-30 15:02:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/binomial_coefficient.test.cpp
  - test/yukicoder/117.test.cpp
documentation_of: math/binomial_coefficient.hpp
layout: document
redirect_from:
- /library/math/binomial_coefficient.hpp
- /library/math/binomial_coefficient.hpp.html
title: math/binomial_coefficient.hpp
---
