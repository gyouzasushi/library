---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/bitwise_or_convolution.hpp
    title: Bitwise Or Convolution
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: math/zeta_mobius_transform.hpp
    title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB\u30FB\u9AD8\u901F\u30E1\u30D3\
      \u30A6\u30B9\u5909\u63DB"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"test/library-checker/bitwise_or_convolution.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n\
    #line 2 \"math/zeta_mobius_transform.hpp\"\n#include <cassert>\n#include <vector>\n\
    template <typename mint>\nvoid superset_zeta(std::vector<mint>& f) {\n    int\
    \ n = f.size();\n    assert((n & -n) == n);\n    for (int i = 1; i < n; i <<=\
    \ 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j & i) == 0) {\n\
    \                f[j] += f[j | i];\n            }\n        }\n    }\n}\ntemplate\
    \ <typename mint>\nvoid superset_mobius(std::vector<mint>& f) {\n    int n = f.size();\n\
    \    assert((n & -n) == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; j++) {\n            if ((j & i) == 0) {\n               \
    \ f[j] -= f[j | i];\n            }\n        }\n    }\n}\ntemplate <typename mint>\n\
    void subset_zeta(std::vector<mint>& f) {\n    int n = f.size();\n    assert((n\
    \ & -n) == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0;\
    \ j < n; j++) {\n            if ((j & i) == 0) {\n                f[j | i] +=\
    \ f[j];\n            }\n        }\n    }\n}\ntemplate <typename mint>\nvoid subset_mobius(std::vector<mint>&\
    \ f) {\n    int n = f.size();\n    assert((n & -n) == n);\n    for (int i = 1;\
    \ i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j\
    \ & i) == 0) {\n                f[j | i] -= f[j];\n            }\n        }\n\
    \    }\n}\n#line 3 \"math/bitwise_or_convolution.hpp\"\ntemplate <typename mint>\n\
    std::vector<mint> bitwise_or_convolution(std::vector<mint> a,\n              \
    \                           std::vector<mint> b) {\n    subset_zeta(a);\n    subset_zeta(b);\n\
    \    for (int i = 0; i < int(a.size()); i++) {\n        a[i] *= b[i];\n    }\n\
    \    subset_mobius(a);\n    return a;\n}\n#line 3 \"test/library-checker/bitwise_or_convolution.test.cpp\"\
    \n\n#include <iostream>\n\n#line 2 \"math/modint.hpp\"\n\n#include <algorithm>\n\
    #include <array>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace\
    \ modint {\n\nnamespace internal {\n\n// @param n `0 <= n`\n// @return minimum\
    \ non-negative `x` s.t. `n <= 2**x`\nint ceil_pow2(int n) {\n    int x = 0;\n\
    \    while ((1U << x) < (unsigned int)(n)) x++;\n    return x;\n}\n\n// @param\
    \ n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\n\
    int bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index,\
    \ n);\n    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n\n}\
    \  // namespace internal\n\n}  // namespace modint\n\n#include <utility>\n\nnamespace\
    \ modint {\n\nnamespace internal {\n\n// @param m `1 <= m`\n// @return x mod m\n\
    constexpr long long safe_mod(long long x, long long m) {\n    x %= m;\n    if\
    \ (x < 0) x += m;\n    return x;\n}\n\n// Fast moduler by barrett reduction\n\
    // Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n// NOTE: reconsider\
    \ after Ice Lake\nstruct barrett {\n    unsigned int _m;\n    unsigned long long\
    \ im;\n\n    // @param m `1 <= m`\n    barrett(unsigned int m) : _m(m), im((unsigned\
    \ long long)(-1) / m + 1) {\n    }\n\n    // @return m\n    unsigned int umod()\
    \ const {\n        return _m;\n    }\n\n    // @param a `0 <= a < m`\n    // @param\
    \ b `0 <= b < m`\n    // @return `a * b % m`\n    unsigned int mul(unsigned int\
    \ a, unsigned int b) const {\n        // [1] m = 1\n        // a = b = im = 0,\
    \ so okay\n\n        // [2] m >= 2\n        // im = ceil(2^64 / m)\n        //\
    \ -> im * m = 2^64 + r (0 <= r < m)\n        // let z = a*b = c*m + d (0 <= c,\
    \ d < m)\n        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r\
    \ + d*im\n        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 +\
    \ m * (m + 1)\n        // < 2^64 * 2\n        // ((ab * im) >> 64) == c or c +\
    \ 1\n        unsigned long long z = a;\n        z *= b;\n#ifdef _MSC_VER\n   \
    \     unsigned long long x;\n        _umul128(z, im, &x);\n#else\n        unsigned\
    \ long long x =\n            (unsigned long long)(((unsigned __int128)(z)*im)\
    \ >> 64);\n#endif\n        unsigned int v = (unsigned int)(z - x * _m);\n    \
    \    if (_m <= v) v += _m;\n        return v;\n    }\n};\n\n// @param n `0 <=\
    \ n`\n// @param m `1 <= m`\n// @return `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n// Reference:\n\
    // M. Forisek and J. Jancina,\n// Fast Primality Testing for Integers That Fit\
    \ into a Machine Word\n// @param n `0 <= n`\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    for (long long a : {2, 7, 61}) {\n        long long\
    \ t = d;\n        long long y = pow_mod_constexpr(a, t, n);\n        while (t\
    \ != n - 1 && y != 1 && y != n - 1) {\n            y = y * y % n;\n          \
    \  t <<= 1;\n        }\n        if (y != n - 1 && t % 2 == 0) {\n            return\
    \ false;\n        }\n    }\n    return true;\n}\ntemplate <int n>\nconstexpr bool\
    \ is_prime = is_prime_constexpr(n);\n\n// @param b `1 <= b`\n// @return pair(g,\
    \ x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g\nconstexpr std::pair<long\
    \ long, long long> inv_gcd(long long a, long long b) {\n    a = safe_mod(a, b);\n\
    \    if (a == 0) return {b, 0};\n\n    // Contracts:\n    // [1] s - m0 * a =\
    \ 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    // [3] s * |m1| + t * |m0|\
    \ <= b\n    long long s = b, t = a;\n    long long m0 = 0, m1 = 1;\n\n    while\
    \ (t) {\n        long long u = s / t;\n        s -= t * u;\n        m0 -= m1 *\
    \ u;  // |m1 * u| <= |m1| * s <= b\n\n        // [3]:\n        // (s - t * u)\
    \ * |m1| + t * |m0 - m1 * u|\n        // <= s * |m1| - t * u * |m1| + t * (|m0|\
    \ + |m1| * u)\n        // = s * |m1| + t * |m0| <= b\n\n        auto tmp = s;\n\
    \        s = t;\n        t = tmp;\n        tmp = m0;\n        m0 = m1;\n     \
    \   m1 = tmp;\n    }\n    // by [3]: |m0| <= b/g\n    // by g != b: |m0| < b/g\n\
    \    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\n// Compile time primitive\
    \ root\n// @param m must be prime\n// @return primitive root (and minimum in now)\n\
    constexpr int primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n \
    \   if (m == 167772161) return 3;\n    if (m == 469762049) return 3;\n    if (m\
    \ == 754974721) return 11;\n    if (m == 998244353) return 3;\n    int divs[20]\
    \ = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x = (m - 1) / 2;\n    while\
    \ (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i <= x; i += 2) {\n\
    \        if (x % i == 0) {\n            divs[cnt++] = i;\n            while (x\
    \ % i == 0) {\n                x /= i;\n            }\n        }\n    }\n    if\
    \ (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int g = 2;; g++) {\n  \
    \      bool ok = true;\n        for (int i = 0; i < cnt; i++) {\n            if\
    \ (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n                ok = false;\n\
    \                break;\n            }\n        }\n        if (ok) return g;\n\
    \    }\n}\ntemplate <int m>\nconstexpr int primitive_root = primitive_root_constexpr(m);\n\
    \n}  // namespace internal\n\n}  // namespace modint\n\n#line 220 \"math/modint.hpp\"\
    \n#include <numeric>\n#include <type_traits>\n\nnamespace modint {\n\nnamespace\
    \ internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128 =\n\
    \    typename std::conditional<std::is_same<T, __int128_t>::value ||\n       \
    \                           std::is_same<T, __int128>::value,\n              \
    \                std::true_type, std::false_type>::type;\n\ntemplate <class T>\n\
    using is_unsigned_int128 =\n    typename std::conditional<std::is_same<T, __uint128_t>::value\
    \ ||\n                                  std::is_same<T, unsigned __int128>::value,\n\
    \                              std::true_type, std::false_type>::type;\n\ntemplate\
    \ <class T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value, __uint128_t,\n                              unsigned __int128>;\n\
    \ntemplate <class T>\nusing is_integral =\n    typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                  is_signed_int128<T>::value ||\n      \
    \                            is_unsigned_int128<T>::value,\n                 \
    \             std::true_type, std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int =\n    typename std::conditional<(is_integral<T>::value &&\n\
    \                               std::is_signed<T>::value) ||\n               \
    \                   is_signed_int128<T>::value,\n                            \
    \  std::true_type, std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int\
    \ =\n    typename std::conditional<(is_integral<T>::value &&\n               \
    \                std::is_unsigned<T>::value) ||\n                            \
    \      is_unsigned_int128<T>::value,\n                              std::true_type,\
    \ std::false_type>::type;\n\ntemplate <class T>\nusing to_unsigned = typename\
    \ std::conditional<\n    is_signed_int128<T>::value, make_unsigned_int128<T>,\n\
    \    typename std::conditional<std::is_signed<T>::value, std::make_unsigned<T>,\n\
    \                              std::common_type<T>>::type>::type;\n\n#else\n\n\
    template <class T>\nusing is_integral = typename std::is_integral<T>;\n\ntemplate\
    \ <class T>\nusing is_signed_int =\n    typename std::conditional<is_integral<T>::value\
    \ && std::is_signed<T>::value,\n                              std::true_type,\
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\
    \ std::false_type>::type;\n\ntemplate <class T>\nusing to_unsigned =\n    typename\
    \ std::conditional<is_signed_int<T>::value, std::make_unsigned<T>,\n         \
    \                     std::common_type<T>>::type;\n\n#endif\n\ntemplate <class\
    \ T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\ntemplate\
    \ <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T>\nusing to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace modint\n\n#line 311 \"math/modint.hpp\"\
    \n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace modint {\n\nnamespace\
    \ internal {\n\nstruct modint_base {};\nstruct static_modint_base : modint_base\
    \ {};\n\ntemplate <class T>\nusing is_modint = std::is_base_of<modint_base, T>;\n\
    template <class T>\nusing is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace internal\n\ntemplate <int m, std::enable_if_t<(1 <= m)>* = nullptr>\n\
    struct static_modint : internal::static_modint_base {\n    using mint = static_modint;\n\
    \npublic:\n    static constexpr int mod() {\n        return m;\n    }\n    static\
    \ mint raw(int v) {\n        mint x;\n        x._v = v;\n        return x;\n \
    \   }\n\n    static_modint() : _v(0) {\n    }\n    template <class T, internal::is_signed_int_t<T>*\
    \ = nullptr>\n    static_modint(T v) {\n        long long x = (long long)(v %\
    \ (long long)(umod()));\n        if (x < 0) x += umod();\n        _v = (unsigned\
    \ int)(x);\n    }\n    template <class T, internal::is_unsigned_int_t<T>* = nullptr>\n\
    \    static_modint(T v) {\n        _v = (unsigned int)(v % umod());\n    }\n \
    \   static_modint(bool v) {\n        _v = ((unsigned int)(v) % umod());\n    }\n\
    \n    unsigned int val() const {\n        return _v;\n    }\n\n    mint& operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint&\
    \ operator-=(const mint& rhs) {\n        _v -= rhs._v;\n        if (_v >= umod())\
    \ _v += umod();\n        return *this;\n    }\n    mint& operator*=(const mint&\
    \ rhs) {\n        unsigned long long z = _v;\n        z *= rhs._v;\n        _v\
    \ = (unsigned int)(z % umod());\n        return *this;\n    }\n    mint& operator/=(const\
    \ mint& rhs) {\n        return *this = *this * rhs.inv();\n    }\n\n    mint operator+()\
    \ const {\n        return *this;\n    }\n    mint operator-() const {\n      \
    \  return mint() - *this;\n    }\n\n    mint pow(long long n) const {\n      \
    \  assert(0 <= n);\n        mint x = *this, r = 1;\n        while (n) {\n    \
    \        if (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n     \
    \   }\n        return r;\n    }\n    mint inv() const {\n        if (prime) {\n\
    \            assert(_v);\n            return pow(umod() - 2);\n        } else\
    \ {\n            auto eg = internal::inv_gcd(_v, m);\n            assert(eg.first\
    \ == 1);\n            return eg.second;\n        }\n    }\n\n    friend mint operator+(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n   \
    \ friend mint operator-(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ -= rhs;\n    }\n    friend mint operator*(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) *= rhs;\n    }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) /= rhs;\n    }\n   \
    \ friend bool operator==(const mint& lhs, const mint& rhs) {\n        return lhs._v\
    \ == rhs._v;\n    }\n    friend bool operator!=(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v != rhs._v;\n    }\n\nprivate:\n    unsigned int _v;\n\
    \    static constexpr unsigned int umod() {\n        return m;\n    }\n    static\
    \ constexpr bool prime = internal::is_prime<m>;\n};\n\ntemplate <int id>\nstruct\
    \ dynamic_modint : internal::modint_base {\n    using mint = dynamic_modint;\n\
    \npublic:\n    static int mod() {\n        return (int)(bt.umod());\n    }\n \
    \   static void set_mod(int m) {\n        assert(1 <= m);\n        bt = internal::barrett(m);\n\
    \    }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n\n    dynamic_modint() : _v(0) {\n    }\n    template\
    \ <class T, internal::is_signed_int_t<T>* = nullptr>\n    dynamic_modint(T v)\
    \ {\n        long long x = (long long)(v % (long long)(mod()));\n        if (x\
    \ < 0) x += mod();\n        _v = (unsigned int)(x);\n    }\n    template <class\
    \ T, internal::is_unsigned_int_t<T>* = nullptr>\n    dynamic_modint(T v) {\n \
    \       _v = (unsigned int)(v % mod());\n    }\n    dynamic_modint(bool v) {\n\
    \        _v = ((unsigned int)(v) % mod());\n    }\n\n    unsigned int val() const\
    \ {\n        return _v;\n    }\n\n    mint& operator++() {\n        _v++;\n  \
    \      if (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v += mod() - rhs._v;\n        if (_v >= umod()) _v -= umod();\n        return\
    \ *this;\n    }\n    mint& operator*=(const mint& rhs) {\n        _v = bt.mul(_v,\
    \ rhs._v);\n        return *this;\n    }\n    mint& operator/=(const mint& rhs)\
    \ {\n        return *this = *this * rhs.inv();\n    }\n\n    mint operator+()\
    \ const {\n        return *this;\n    }\n    mint operator-() const {\n      \
    \  return mint() - *this;\n    }\n\n    mint pow(long long n) const {\n      \
    \  assert(0 <= n);\n        mint x = *this, r = 1;\n        while (n) {\n    \
    \        if (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n     \
    \   }\n        return r;\n    }\n    mint inv() const {\n        auto eg = internal::inv_gcd(_v,\
    \ mod());\n        assert(eg.first == 1);\n        return eg.second;\n    }\n\n\
    \    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n\nprivate:\n\
    \    unsigned int _v;\n    static internal::barrett bt;\n    static unsigned int\
    \ umod() {\n        return bt.umod();\n    }\n};\n\ntemplate <int id>\ninternal::barrett\
    \ dynamic_modint<id>::bt = 998244353;\n\nusing modint998244353 = static_modint<998244353>;\n\
    using modint1000000007 = static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\
    \nnamespace internal {\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \ntemplate <class>\nstruct is_dynamic_modint : public std::false_type {};\ntemplate\
    \ <int id>\nstruct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\n\ntemplate <class T>\nusing is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    \n}  // namespace internal\n\n#line 613 \"math/modint.hpp\"\ntemplate <typename\
    \ T, typename std::enable_if_t<internal::is_modint<T>::value,\n              \
    \                                  std::nullptr_t> = nullptr>\nstd::istream& operator>>(std::istream&\
    \ is, T& v) {\n    long long x;\n    is >> x;\n    v = x;\n    return is;\n}\n\
    template <typename T, typename std::enable_if_t<internal::is_modint<T>::value,\n\
    \                                                std::nullptr_t> = nullptr>\n\
    std::ostream& operator<<(std::ostream& os, const T& v) {\n    os << v.val();\n\
    \    return os;\n}\n}  // namespace modint\n#line 7 \"test/library-checker/bitwise_or_convolution.test.cpp\"\
    \n\nusing mint = modint::modint998244353;\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n    int mask = (1 << n) - 1;\n    std::vector<mint> a(1 << n), b(1 <<\
    \ n);\n    for (int i = 0; i < (1 << n); i++) std::cin >> a[i ^ mask];\n    for\
    \ (int i = 0; i < (1 << n); i++) std::cin >> b[i ^ mask];\n\n    std::vector<mint>\
    \ c = bitwise_or_convolution(a, b);\n    for (int i = 0; i < (1 << n); i++) {\n\
    \        std::cout << c[i ^ mask] << \" \\n\"[i == (1 << n) - 1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n#include \"../../math/bitwise_or_convolution.hpp\"\n\n#include <iostream>\n\n\
    #include \"../../math/modint.hpp\"\n\nusing mint = modint::modint998244353;\n\
    int main() {\n    int n;\n    std::cin >> n;\n    int mask = (1 << n) - 1;\n \
    \   std::vector<mint> a(1 << n), b(1 << n);\n    for (int i = 0; i < (1 << n);\
    \ i++) std::cin >> a[i ^ mask];\n    for (int i = 0; i < (1 << n); i++) std::cin\
    \ >> b[i ^ mask];\n\n    std::vector<mint> c = bitwise_or_convolution(a, b);\n\
    \    for (int i = 0; i < (1 << n); i++) {\n        std::cout << c[i ^ mask] <<\
    \ \" \\n\"[i == (1 << n) - 1];\n    }\n}"
  dependsOn:
  - math/bitwise_or_convolution.hpp
  - math/zeta_mobius_transform.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/library-checker/bitwise_or_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-09-17 18:19:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/bitwise_or_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/bitwise_or_convolution.test.cpp
- /verify/test/library-checker/bitwise_or_convolution.test.cpp.html
title: test/library-checker/bitwise_or_convolution.test.cpp
---