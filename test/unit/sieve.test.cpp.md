---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/factorize.hpp
    title: Factorize
  - icon: ':question:'
    path: math/sieve.hpp
    title: Sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unit/sieve.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \n#line 2 \"math/factorize.hpp\"\n#include <algorithm>\n#line 4 \"math/factorize.hpp\"\
    \n#include <cstdlib>\n#include <numeric>\n#include <utility>\n#line 8 \"math/factorize.hpp\"\
    \n\nnamespace internal {\n\nlong long modmul(long long x, long long y, long long\
    \ mod) {\n    return (long long)((__int128_t)x * y % mod);\n}\n\nlong long modpow(long\
    \ long a, long long n, long long mod) {\n    long long ret = 1;\n    while (n\
    \ > 0) {\n        if (n & 1) ret = modmul(ret, a, mod);\n        a = modmul(a,\
    \ a, mod);\n        n >>= 1;\n    }\n    return ret;\n}\n\nlong long rho(long\
    \ long n) {\n    long long z = 0;\n    auto f = [&](long long x) {\n        long\
    \ long ret = modmul(x, x, n) + z;\n        return ret >= n ? ret - n : ret;\n\
    \    };\n    while (true) {\n        long long x = ++z;\n        long long y =\
    \ f(x);\n        while (true) {\n            long long d = std::gcd(std::abs(x\
    \ - y), n);\n            if (d == n) break;\n            if (d > 1) return d;\n\
    \            x = f(x);\n            y = f(f(y));\n        }\n    }\n}\n\n}  //\
    \ namespace internal\n\nbool is_prime(long long n) {\n    assert(n >= 1);\n  \
    \  if (n == 1) return false;\n    if (n % 2 == 0) return n == 2;\n    long long\
    \ d = n - 1, s = 0;\n    while (~d & 1) d >>= 1, s++;\n    for (long long a :\
    \ {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {\n        if (a >= n) break;\n\
    \        long long x = internal::modpow(a, d, n);\n        if (x == 1) continue;\n\
    \        bool ok = false;\n        for (int i = 0; i < s; i++) {\n           \
    \ if (x == n - 1) {\n                ok = true;\n                break;\n    \
    \        }\n            x = internal::modmul(x, x, n);\n        }\n        if\
    \ (!ok) return false;\n    }\n    return true;\n}\n\nstd::vector<std::pair<long\
    \ long, int>> factorize(long long n) {\n    assert(n >= 1);\n    std::vector<std::pair<long\
    \ long, int>> ret;\n    int c = 0;\n    while (~n & 1) n >>= 1, c++;\n    if (c\
    \ > 0) ret.emplace_back(2, c);\n    std::vector<long long> st = {n};\n    std::vector<long\
    \ long> primes;\n    while (!st.empty()) {\n        long long p = st.back();\n\
    \        st.pop_back();\n        if (p == 1) continue;\n        if (is_prime(p))\
    \ {\n            primes.push_back(p);\n            continue;\n        }\n    \
    \    long long d = internal::rho(p);\n        st.push_back(d);\n        st.push_back(p\
    \ / d);\n    }\n    std::ranges::sort(primes);\n    for (long long p : primes)\
    \ {\n        if (!ret.empty() && ret.back().first == p) {\n            ret.back().second++;\n\
    \        } else {\n            ret.emplace_back(p, 1);\n        }\n    }\n   \
    \ return ret;\n}\n\nstd::vector<long long> divisors(long long n) {\n    assert(n\
    \ >= 1);\n    std::vector<long long> ret = {1};\n    for (auto [p, e] : factorize(n))\
    \ {\n        int sz = int(ret.size());\n        long long q = 1;\n        for\
    \ (int i = 0; i < e; i++) {\n            q *= p;\n            for (int j = 0;\
    \ j < sz; j++) ret.push_back(ret[j] * q);\n        }\n    }\n    std::ranges::sort(ret);\n\
    \    return ret;\n}\n#line 6 \"math/sieve.hpp\"\nstruct sieve {\npublic:\n   \
    \ sieve() : sieve(1) {\n    }\n    explicit sieve(int n) : _n(n), lpf(n + 1, 0)\
    \ {\n        assert(n >= 1);\n        for (int i = 2; i <= n; i++) {\n       \
    \     if (lpf[i] == 0) {\n                lpf[i] = i;\n                _primes.push_back(i);\n\
    \            }\n            for (int p : _primes) {\n                if (p > lpf[i]\
    \ || (long long)p * i > n) break;\n                lpf[p * i] = p;\n         \
    \   }\n        }\n    }\n    bool is_prime(int x) const {\n        assert(0 <=\
    \ x && x <= _n);\n        return x >= 2 && lpf[x] == x;\n    }\n    int smallest_prime_factor(int\
    \ x) const {\n        assert(2 <= x && x <= _n);\n        return lpf[x];\n   \
    \ }\n    const std::vector<int>& primes() const {\n        return _primes;\n \
    \   }\n    std::vector<std::pair<int, int>> factorize(int x) const {\n       \
    \ assert(1 <= x && x <= _n);\n        std::vector<std::pair<int, int>> ret;\n\
    \        while (x > 1) {\n            int p = lpf[x];\n            if (!ret.empty()\
    \ && ret.back().first == p) {\n                ret.back().second++;\n        \
    \    } else {\n                ret.emplace_back(p, 1);\n            }\n      \
    \      x /= p;\n        }\n        return ret;\n    }\n    std::vector<int> divisors(int\
    \ x) const {\n        assert(1 <= x && x <= _n);\n        std::vector<int> ret\
    \ = {1};\n        for (auto [p, e] : factorize(x)) {\n            int sz = int(ret.size());\n\
    \            int q = 1;\n            for (int i = 0; i < e; i++) {\n         \
    \       q *= p;\n                for (int j = 0; j < sz; j++) ret.push_back(ret[j]\
    \ * q);\n            }\n        }\n        std::ranges::sort(ret);\n        return\
    \ ret;\n    }\n\nprivate:\n    int _n;\n    std::vector<int> lpf, _primes;\n};\n\
    #line 9 \"test/unit/sieve.test.cpp\"\n\nstd::vector<std::pair<long long, int>>\
    \ naive_factorize(long long x) {\n    std::vector<std::pair<long long, int>> ret;\n\
    \    for (long long p = 2; p * p <= x; p++) {\n        int e = 0;\n        while\
    \ (x % p == 0) x /= p, e++;\n        if (e) ret.emplace_back(p, e);\n    }\n \
    \   if (x > 1) ret.emplace_back(x, 1);\n    return ret;\n}\nstd::vector<long long>\
    \ naive_divisors(long long x) {\n    std::vector<long long> ret;\n    for (long\
    \ long d = 1; d <= x; d++) {\n        if (x % d == 0) ret.push_back(d);\n    }\n\
    \    return ret;\n}\n\nint main() {\n    const int n = 3000;\n    sieve s(n);\n\
    \    {\n        std::vector<int> ps;\n        for (int x = 0; x <= n; x++) {\n\
    \            bool prime = x >= 2;\n            for (int d = 2; d * d <= x; d++)\
    \ prime &= x % d != 0;\n            assert(s.is_prime(x) == prime);\n        \
    \    if (prime) ps.push_back(x);\n            if (x >= 2) assert(s.smallest_prime_factor(x)\
    \ == naive_factorize(x)[0].first);\n            if (x >= 1) {\n              \
    \  auto f = s.factorize(x);\n                auto g = naive_factorize(x);\n  \
    \              assert(f.size() == g.size());\n                for (size_t i =\
    \ 0; i < f.size(); i++) assert(f[i].first == g[i].first && f[i].second == g[i].second);\n\
    \                auto d = s.divisors(x);\n                auto nd = naive_divisors(x);\n\
    \                assert(d.size() == nd.size());\n                for (size_t i\
    \ = 0; i < d.size(); i++) assert(d[i] == nd[i]);\n            }\n        }\n \
    \       assert(s.primes() == ps);\n    }\n    // sieve(1), sieve(2)\n    {\n \
    \       sieve s1(1);\n        assert(s1.primes().empty() && !s1.is_prime(1) &&\
    \ s1.factorize(1).empty() && s1.divisors(1) == std::vector<int>{1});\n       \
    \ sieve s2(2);\n        assert(s2.primes() == std::vector<int>{2} && s2.is_prime(2));\n\
    \    }\n    // large n: pi(10^7) = 664579\n    {\n        sieve big(10000000);\n\
    \        assert(int(big.primes().size()) == 664579);\n        assert((big.factorize(9999991)\
    \ == std::vector<std::pair<int, int>>{{9999991, 1}}));\n        assert(big.divisors(10000000).size()\
    \ == 8 * 8);\n    }\n    // Pollard-rho factorize / divisors (vector form)\n \
    \   {\n        std::mt19937_64 rng(5);\n        for (long long x = 1; x <= 2000;\
    \ x++) {\n            assert(factorize(x) == naive_factorize(x));\n          \
    \  assert(divisors(x) == naive_divisors(x));\n        }\n        for (int it =\
    \ 0; it < 300; it++) {\n            long long x = 1 + rng() % 1000000000000LL;\n\
    \            assert(factorize(x) == naive_factorize(x));\n            auto d =\
    \ divisors(x);\n            long long cnt = 1;\n            for (auto [p, e] :\
    \ factorize(x)) cnt *= e + 1;\n            assert((long long)d.size() == cnt);\n\
    \            for (size_t i = 0; i < d.size(); i++) {\n                assert(x\
    \ % d[i] == 0);\n                if (i) assert(d[i - 1] < d[i]);\n           \
    \ }\n        }\n        auto d = divisors(897612484786617600LL);  // highly composite,\
    \ 103680 divisors\n        assert(d.size() == 103680);\n    }\n    std::cout <<\
    \ \"Hello World\" << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \n#include \"math/factorize.hpp\"\n#include \"math/sieve.hpp\"\n\nstd::vector<std::pair<long\
    \ long, int>> naive_factorize(long long x) {\n    std::vector<std::pair<long long,\
    \ int>> ret;\n    for (long long p = 2; p * p <= x; p++) {\n        int e = 0;\n\
    \        while (x % p == 0) x /= p, e++;\n        if (e) ret.emplace_back(p, e);\n\
    \    }\n    if (x > 1) ret.emplace_back(x, 1);\n    return ret;\n}\nstd::vector<long\
    \ long> naive_divisors(long long x) {\n    std::vector<long long> ret;\n    for\
    \ (long long d = 1; d <= x; d++) {\n        if (x % d == 0) ret.push_back(d);\n\
    \    }\n    return ret;\n}\n\nint main() {\n    const int n = 3000;\n    sieve\
    \ s(n);\n    {\n        std::vector<int> ps;\n        for (int x = 0; x <= n;\
    \ x++) {\n            bool prime = x >= 2;\n            for (int d = 2; d * d\
    \ <= x; d++) prime &= x % d != 0;\n            assert(s.is_prime(x) == prime);\n\
    \            if (prime) ps.push_back(x);\n            if (x >= 2) assert(s.smallest_prime_factor(x)\
    \ == naive_factorize(x)[0].first);\n            if (x >= 1) {\n              \
    \  auto f = s.factorize(x);\n                auto g = naive_factorize(x);\n  \
    \              assert(f.size() == g.size());\n                for (size_t i =\
    \ 0; i < f.size(); i++) assert(f[i].first == g[i].first && f[i].second == g[i].second);\n\
    \                auto d = s.divisors(x);\n                auto nd = naive_divisors(x);\n\
    \                assert(d.size() == nd.size());\n                for (size_t i\
    \ = 0; i < d.size(); i++) assert(d[i] == nd[i]);\n            }\n        }\n \
    \       assert(s.primes() == ps);\n    }\n    // sieve(1), sieve(2)\n    {\n \
    \       sieve s1(1);\n        assert(s1.primes().empty() && !s1.is_prime(1) &&\
    \ s1.factorize(1).empty() && s1.divisors(1) == std::vector<int>{1});\n       \
    \ sieve s2(2);\n        assert(s2.primes() == std::vector<int>{2} && s2.is_prime(2));\n\
    \    }\n    // large n: pi(10^7) = 664579\n    {\n        sieve big(10000000);\n\
    \        assert(int(big.primes().size()) == 664579);\n        assert((big.factorize(9999991)\
    \ == std::vector<std::pair<int, int>>{{9999991, 1}}));\n        assert(big.divisors(10000000).size()\
    \ == 8 * 8);\n    }\n    // Pollard-rho factorize / divisors (vector form)\n \
    \   {\n        std::mt19937_64 rng(5);\n        for (long long x = 1; x <= 2000;\
    \ x++) {\n            assert(factorize(x) == naive_factorize(x));\n          \
    \  assert(divisors(x) == naive_divisors(x));\n        }\n        for (int it =\
    \ 0; it < 300; it++) {\n            long long x = 1 + rng() % 1000000000000LL;\n\
    \            assert(factorize(x) == naive_factorize(x));\n            auto d =\
    \ divisors(x);\n            long long cnt = 1;\n            for (auto [p, e] :\
    \ factorize(x)) cnt *= e + 1;\n            assert((long long)d.size() == cnt);\n\
    \            for (size_t i = 0; i < d.size(); i++) {\n                assert(x\
    \ % d[i] == 0);\n                if (i) assert(d[i - 1] < d[i]);\n           \
    \ }\n        }\n        auto d = divisors(897612484786617600LL);  // highly composite,\
    \ 103680 divisors\n        assert(d.size() == 103680);\n    }\n    std::cout <<\
    \ \"Hello World\" << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - math/factorize.hpp
  - math/sieve.hpp
  isVerificationFile: true
  path: test/unit/sieve.test.cpp
  requiredBy: []
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unit/sieve.test.cpp
layout: document
redirect_from:
- /verify/test/unit/sieve.test.cpp
- /verify/test/unit/sieve.test.cpp.html
title: test/unit/sieve.test.cpp
---
