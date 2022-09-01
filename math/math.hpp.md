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
  bundledCode: "#line 1 \"math/math.hpp\"\nnamespace math {\nnamespace internal {\n\
    constexpr long long safe_mod(long long x, long long m) {\n    x %= m;\n    if\
    \ (x < 0) x += m;\n    return x;\n}\nstruct barrett {\n    unsigned int _m;\n\
    \    unsigned long long im;\n    barrett(unsigned int m) : _m(m), im((unsigned\
    \ long long)(-1) / m + 1) {\n    }\n    unsigned int umod() const {\n        return\
    \ _m;\n    }\n    unsigned int mul(unsigned int a, unsigned int b) const {\n \
    \       unsigned long long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned\
    \ long long x;\n        _umul128(z, im, &x);\n#else\n        unsigned long long\
    \ x =\n            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n\
    #endif\n        unsigned int v = (unsigned int)(z - x * _m);\n        if (_m <=\
    \ v) v += _m;\n        return v;\n    }\n};\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\nconstexpr\
    \ bool is_prime_constexpr(int n) {\n    if (n <= 1) return false;\n    if (n ==\
    \ 2 || n == 7 || n == 61) return true;\n    if (n % 2 == 0) return false;\n  \
    \  long long d = n - 1;\n    while (d % 2 == 0) d /= 2;\n    for (long long a\
    \ : {2, 7, 61}) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    template <int n>\nconstexpr bool is_prime = is_prime_constexpr(n);\n\n// @return\
    \ pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g\nconstexpr std::pair<long\
    \ long, long long> inv_gcd(long long a, long long b) {\n    a = safe_mod(a, b);\n\
    \    if (a == 0) return {b, 0};\n    long long s = b, t = a;\n    long long m0\
    \ = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;\n        auto tmp = s;\n        s = t;\n     \
    \   t = tmp;\n        tmp = m0;\n        m0 = m1;\n        m1 = tmp;\n    }\n\
    \    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\n// @return primitive\
    \ root (and minimum in now)\nconstexpr int primitive_root_constexpr(int m) {\n\
    \    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m>\nconstexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n}  // namespace internal\n\nlong long pow_mod(long\
    \ long x, long long n, int m) {\n    assert(0 <= n && 1 <= m);\n    if (m == 1)\
    \ return 0;\n    internal::barrett bt((unsigned int)(m));\n    unsigned int r\
    \ = 1, y = (unsigned int)(internal::safe_mod(x, m));\n    while (n) {\n      \
    \  if (n & 1) r = bt.mul(r, y);\n        y = bt.mul(y, y);\n        n >>= 1;\n\
    \    }\n    return r;\n}\n\nlong long inv_mod(long long x, long long m) {\n  \
    \  assert(1 <= m);\n    auto z = internal::inv_gcd(x, m);\n    assert(z.first\
    \ == 1);\n    return z.second;\n}\n\n// (rem, mod)\nstd::pair<long long, long\
    \ long> crt(const std::vector<long long>& r,\n                               \
    \     const std::vector<long long>& m) {\n    assert(r.size() == m.size());\n\
    \    int n = int(r.size());\n    long long r0 = 0, m0 = 1;\n    for (int i = 0;\
    \ i < n; i++) {\n        assert(1 <= m[i]);\n        long long r1 = internal::safe_mod(r[i],\
    \ m[i]), m1 = m[i];\n        if (m0 < m1) {\n            std::swap(r0, r1);\n\
    \            std::swap(m0, m1);\n        }\n        if (m0 % m1 == 0) {\n    \
    \        if (r0 % m1 != r1) return {0, 0};\n            continue;\n        }\n\
    \        long long g, im;\n        std::tie(g, im) = internal::inv_gcd(m0, m1);\n\
    \        long long u1 = (m1 / g);\n        if ((r1 - r0) % g) return {0, 0};\n\
    \        long long x = (r1 - r0) / g % u1 * im % u1;\n        r0 += x * m0;\n\
    \        m0 *= u1;\n        if (r0 < 0) r0 += m0;\n    }\n    return {r0, m0};\n\
    }\n\nlong long floor_sum(long long n, long long m, long long a, long long b) {\n\
    \    long long ans = 0;\n    if (a >= m) {\n        ans += (n - 1) * n * (a /\
    \ m) / 2;\n        a %= m;\n    }\n    if (b >= m) {\n        ans += n * (b /\
    \ m);\n        b %= m;\n    }\n\n    long long y_max = (a * n + b) / m, x_max\
    \ = (y_max * m - b);\n    if (y_max == 0) return ans;\n    ans += (n - (x_max\
    \ + a - 1) / a) * y_max;\n    ans += floor_sum(y_max, a, m, (a - x_max % a) %\
    \ a);\n    return ans;\n}\n}  // namespace math\n"
  code: "namespace math {\nnamespace internal {\nconstexpr long long safe_mod(long\
    \ long x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n\
    }\nstruct barrett {\n    unsigned int _m;\n    unsigned long long im;\n    barrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {\n    }\n    unsigned\
    \ int umod() const {\n        return _m;\n    }\n    unsigned int mul(unsigned\
    \ int a, unsigned int b) const {\n        unsigned long long z = a;\n        z\
    \ *= b;\n#ifdef _MSC_VER\n        unsigned long long x;\n        _umul128(z, im,\
    \ &x);\n#else\n        unsigned long long x =\n            (unsigned long long)(((unsigned\
    \ __int128)(z)*im) >> 64);\n#endif\n        unsigned int v = (unsigned int)(z\
    \ - x * _m);\n        if (_m <= v) v += _m;\n        return v;\n    }\n};\nconstexpr\
    \ long long pow_mod_constexpr(long long x, long long n, int m) {\n    if (m ==\
    \ 1) return 0;\n    unsigned int _m = (unsigned int)(m);\n    unsigned long long\
    \ r = 1;\n    unsigned long long y = safe_mod(x, m);\n    while (n) {\n      \
    \  if (n & 1) r = (r * y) % _m;\n        y = (y * y) % _m;\n        n >>= 1;\n\
    \    }\n    return r;\n}\n\nconstexpr bool is_prime_constexpr(int n) {\n    if\
    \ (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return true;\n\
    \    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while (d % 2\
    \ == 0) d /= 2;\n    for (long long a : {2, 7, 61}) {\n        long long t = d;\n\
    \        long long y = pow_mod_constexpr(a, t, n);\n        while (t != n - 1\
    \ && y != 1 && y != n - 1) {\n            y = y * y % n;\n            t <<= 1;\n\
    \        }\n        if (y != n - 1 && t % 2 == 0) {\n            return false;\n\
    \        }\n    }\n    return true;\n}\ntemplate <int n>\nconstexpr bool is_prime\
    \ = is_prime_constexpr(n);\n\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g\
    \ (mod b), 0 <= x < b/g\nconstexpr std::pair<long long, long long> inv_gcd(long\
    \ long a, long long b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b,\
    \ 0};\n    long long s = b, t = a;\n    long long m0 = 0, m1 = 1;\n\n    while\
    \ (t) {\n        long long u = s / t;\n        s -= t * u;\n        m0 -= m1 *\
    \ u;\n        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    if (m0 < 0) m0 += b / s;\n  \
    \  return {s, m0};\n}\n\n// @return primitive root (and minimum in now)\nconstexpr\
    \ int primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n    if (m\
    \ == 167772161) return 3;\n    if (m == 469762049) return 3;\n    if (m == 754974721)\
    \ return 11;\n    if (m == 998244353) return 3;\n    int divs[20] = {};\n    divs[0]\
    \ = 2;\n    int cnt = 1;\n    int x = (m - 1) / 2;\n    while (x % 2 == 0) x /=\
    \ 2;\n    for (int i = 3; (long long)(i)*i <= x; i += 2) {\n        if (x % i\
    \ == 0) {\n            divs[cnt++] = i;\n            while (x % i == 0) {\n  \
    \              x /= i;\n            }\n        }\n    }\n    if (x > 1) {\n  \
    \      divs[cnt++] = x;\n    }\n    for (int g = 2;; g++) {\n        bool ok =\
    \ true;\n        for (int i = 0; i < cnt; i++) {\n            if (pow_mod_constexpr(g,\
    \ (m - 1) / divs[i], m) == 1) {\n                ok = false;\n               \
    \ break;\n            }\n        }\n        if (ok) return g;\n    }\n}\ntemplate\
    \ <int m>\nconstexpr int primitive_root = primitive_root_constexpr(m);\n}  //\
    \ namespace internal\n\nlong long pow_mod(long long x, long long n, int m) {\n\
    \    assert(0 <= n && 1 <= m);\n    if (m == 1) return 0;\n    internal::barrett\
    \ bt((unsigned int)(m));\n    unsigned int r = 1, y = (unsigned int)(internal::safe_mod(x,\
    \ m));\n    while (n) {\n        if (n & 1) r = bt.mul(r, y);\n        y = bt.mul(y,\
    \ y);\n        n >>= 1;\n    }\n    return r;\n}\n\nlong long inv_mod(long long\
    \ x, long long m) {\n    assert(1 <= m);\n    auto z = internal::inv_gcd(x, m);\n\
    \    assert(z.first == 1);\n    return z.second;\n}\n\n// (rem, mod)\nstd::pair<long\
    \ long, long long> crt(const std::vector<long long>& r,\n                    \
    \                const std::vector<long long>& m) {\n    assert(r.size() == m.size());\n\
    \    int n = int(r.size());\n    long long r0 = 0, m0 = 1;\n    for (int i = 0;\
    \ i < n; i++) {\n        assert(1 <= m[i]);\n        long long r1 = internal::safe_mod(r[i],\
    \ m[i]), m1 = m[i];\n        if (m0 < m1) {\n            std::swap(r0, r1);\n\
    \            std::swap(m0, m1);\n        }\n        if (m0 % m1 == 0) {\n    \
    \        if (r0 % m1 != r1) return {0, 0};\n            continue;\n        }\n\
    \        long long g, im;\n        std::tie(g, im) = internal::inv_gcd(m0, m1);\n\
    \        long long u1 = (m1 / g);\n        if ((r1 - r0) % g) return {0, 0};\n\
    \        long long x = (r1 - r0) / g % u1 * im % u1;\n        r0 += x * m0;\n\
    \        m0 *= u1;\n        if (r0 < 0) r0 += m0;\n    }\n    return {r0, m0};\n\
    }\n\nlong long floor_sum(long long n, long long m, long long a, long long b) {\n\
    \    long long ans = 0;\n    if (a >= m) {\n        ans += (n - 1) * n * (a /\
    \ m) / 2;\n        a %= m;\n    }\n    if (b >= m) {\n        ans += n * (b /\
    \ m);\n        b %= m;\n    }\n\n    long long y_max = (a * n + b) / m, x_max\
    \ = (y_max * m - b);\n    if (y_max == 0) return ans;\n    ans += (n - (x_max\
    \ + a - 1) / a) * y_max;\n    ans += floor_sum(y_max, a, m, (a - x_max % a) %\
    \ a);\n    return ans;\n}\n}  // namespace math"
  dependsOn: []
  isVerificationFile: false
  path: math/math.hpp
  requiredBy: []
  timestamp: '2022-09-01 13:39:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math.hpp
layout: document
redirect_from:
- /library/math/math.hpp
- /library/math/math.hpp.html
title: math/math.hpp
---
