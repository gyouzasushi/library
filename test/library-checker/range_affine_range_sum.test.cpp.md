---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/lazy_segment_tree.hpp
    title: datastructure/lazy_segment_tree.hpp
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: math/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/library-checker/range_affine_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n#include\
    \ <iostream>\n\n#line 2 \"datastructure/lazy_segment_tree.hpp\"\n#include <cassert>\n\
    #include <vector>\ntemplate <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F,\
    \ S),\n          F (*composition)(F, F), F (*id)()>\nstruct LazySegmentTree {\n\
    public:\n    LazySegmentTree() : LazySegmentTree(0) {\n    }\n    LazySegmentTree(int\
    \ n) : LazySegmentTree(std::vector<S>(n, e())) {\n    }\n    LazySegmentTree(const\
    \ std::vector<S>& v) : _n(int(v.size())) {\n        log = ceil_pow2(_n);\n   \
    \     size = 1 << log;\n        d = std::vector<S>(2 * size, e());\n        lz\
    \ = std::vector<F>(size, id());\n        for (int i = 0; i < _n; i++) d[size +\
    \ i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n            update(i);\n\
    \        }\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n\
    \        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n \
    \   }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        return d[p];\n\
    \    }\n\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <=\
    \ _n);\n        if (l == r) return e();\n\n        l += size;\n        r += size;\n\
    \n        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
    \ l) push(l >> i);\n            if (((r >> i) << i) != r) push(r >> i);\n    \
    \    }\n\n        S sml = e(), smr = e();\n        while (l < r) {\n         \
    \   if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\n        return\
    \ op(sml, smr);\n    }\n\n    S all_prod() {\n        return d[1];\n    }\n\n\
    \    void apply(int p, F f) {\n        assert(0 <= p && p < _n);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] =\
    \ mapping(f, d[p]);\n        for (int i = 1; i <= log; i++) update(p >> i);\n\
    \    }\n    void apply(int l, int r, F f) {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        if (l == r) return;\n\n        l += size;\n        r += size;\n\
    \n        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
    \ l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \        }\n\n        {\n            int l2 = l, r2 = r;\n            while (l\
    \ < r) {\n                if (l & 1) all_apply(l++, f);\n                if (r\
    \ & 1) all_apply(--r, f);\n                l >>= 1;\n                r >>= 1;\n\
    \            }\n            l = l2;\n            r = r2;\n        }\n\n      \
    \  for (int i = 1; i <= log; i++) {\n            if (((l >> i) << i) != l) update(l\
    \ >> i);\n            if (((r >> i) << i) != r) update((r - 1) >> i);\n      \
    \  }\n    }\n\n    template <bool (*g)(S)>\n    int max_right(int l) {\n     \
    \   return max_right(l, [](S x) { return g(x); });\n    }\n    template <class\
    \ G>\n    int max_right(int l, G g) {\n        assert(0 <= l && l <= _n);\n  \
    \      assert(g(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        for (int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n \
    \       do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (g(op(sm, d[l]))) {\n\
    \                        sm = op(sm, d[l]);\n                        l++;\n  \
    \                  }\n                }\n                return l - size;\n  \
    \          }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*g)(S)>\n\
    \    int min_left(int r) {\n        return min_left(r, [](S x) { return g(x);\
    \ });\n    }\n    template <class G>\n    int min_left(int r, G g) {\n       \
    \ assert(0 <= r && r <= _n);\n        assert(g(e()));\n        if (r == 0) return\
    \ 0;\n        r += size;\n        for (int i = log; i >= 1; i--) push((r - 1)\
    \ >> i);\n        S sm = e();\n        do {\n            r--;\n            while\
    \ (r > 1 && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n         \
    \       while (r < size) {\n                    push(r);\n                   \
    \ r = (2 * r + 1);\n                    if (g(op(d[r], sm))) {\n             \
    \           sm = op(d[r], sm);\n                        r--;\n               \
    \     }\n                }\n                return r + 1 - size;\n           \
    \ }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n      \
    \  return 0;\n    }\n\nprivate:\n    int _n, size, log;\n    std::vector<S> d;\n\
    \    std::vector<F> lz;\n    int ceil_pow2(int n) {\n        int x = 0;\n    \
    \    while ((1U << x) < (unsigned int)(n)) x++;\n        return x;\n    }\n  \
    \  void update(int k) {\n        d[k] = op(d[2 * k], d[2 * k + 1]);\n    }\n \
    \   void all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n        if\
    \ (k < size) lz[k] = composition(f, lz[k]);\n    }\n    void push(int k) {\n \
    \       all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n     \
    \   lz[k] = id();\n    }\n};\n#line 2 \"math/modint.hpp\"\n\n#include <algorithm>\n\
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
    \n}  // namespace internal\n\n}  // namespace modint\n\n#line 617 \"math/modint.hpp\"\
    \n\nnamespace modint {\n\nnamespace internal {\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nvoid butterfly(std::vector<mint>& a) {\n    static constexpr int\
    \ g = internal::primitive_root<mint::mod()>;\n    int n = int(a.size());\n   \
    \ int h = internal::ceil_pow2(n);\n\n    static bool first = true;\n    static\
    \ mint sum_e[30];  // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]\n    if (first)\
    \ {\n        first = false;\n        mint es[30], ies[30];  // es[i]^(2^(2+i))\
    \ == 1\n        int cnt2 = bsf(mint::mod() - 1);\n        mint e = mint(g).pow((mint::mod()\
    \ - 1) >> cnt2), ie = e.inv();\n        for (int i = cnt2; i >= 2; i--) {\n  \
    \          // e^(2^i) == 1\n            es[i - 2] = e;\n            ies[i - 2]\
    \ = ie;\n            e *= e;\n            ie *= ie;\n        }\n        mint now\
    \ = 1;\n        for (int i = 0; i < cnt2 - 2; i++) {\n            sum_e[i] = es[i]\
    \ * now;\n            now *= ies[i];\n        }\n    }\n    for (int ph = 1; ph\
    \ <= h; ph++) {\n        int w = 1 << (ph - 1), p = 1 << (h - ph);\n        mint\
    \ now = 1;\n        for (int s = 0; s < w; s++) {\n            int offset = s\
    \ << (h - ph + 1);\n            for (int i = 0; i < p; i++) {\n              \
    \  auto l = a[i + offset];\n                auto r = a[i + offset + p] * now;\n\
    \                a[i + offset] = l + r;\n                a[i + offset + p] = l\
    \ - r;\n            }\n            now *= sum_e[bsf(~(unsigned int)(s))];\n  \
    \      }\n    }\n}\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nvoid butterfly_inv(std::vector<mint>& a) {\n    static constexpr\
    \ int g = internal::primitive_root<mint::mod()>;\n    int n = int(a.size());\n\
    \    int h = internal::ceil_pow2(n);\n\n    static bool first = true;\n    static\
    \ mint sum_ie[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]\n    if (first)\
    \ {\n        first = false;\n        mint es[30], ies[30];  // es[i]^(2^(2+i))\
    \ == 1\n        int cnt2 = bsf(mint::mod() - 1);\n        mint e = mint(g).pow((mint::mod()\
    \ - 1) >> cnt2), ie = e.inv();\n        for (int i = cnt2; i >= 2; i--) {\n  \
    \          // e^(2^i) == 1\n            es[i - 2] = e;\n            ies[i - 2]\
    \ = ie;\n            e *= e;\n            ie *= ie;\n        }\n        mint now\
    \ = 1;\n        for (int i = 0; i < cnt2 - 2; i++) {\n            sum_ie[i] =\
    \ ies[i] * now;\n            now *= es[i];\n        }\n    }\n\n    for (int ph\
    \ = h; ph >= 1; ph--) {\n        int w = 1 << (ph - 1), p = 1 << (h - ph);\n \
    \       mint inow = 1;\n        for (int s = 0; s < w; s++) {\n            int\
    \ offset = s << (h - ph + 1);\n            for (int i = 0; i < p; i++) {\n   \
    \             auto l = a[i + offset];\n                auto r = a[i + offset +\
    \ p];\n                a[i + offset] = l + r;\n                a[i + offset +\
    \ p] =\n                    (unsigned long long)(mint::mod() + l.val() - r.val())\
    \ *\n                    inow.val();\n            }\n            inow *= sum_ie[bsf(~(unsigned\
    \ int)(s))];\n        }\n    }\n}\n\n}  // namespace internal\n\ntemplate <class\
    \ mint, internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution(std::vector<mint>\
    \ a, std::vector<mint> b) {\n    int n = int(a.size()), m = int(b.size());\n \
    \   if (!n || !m) return {};\n    if (std::min(n, m) <= 60) {\n        if (n <\
    \ m) {\n            std::swap(n, m);\n            std::swap(a, b);\n        }\n\
    \        std::vector<mint> ans(n + m - 1);\n        for (int i = 0; i < n; i++)\
    \ {\n            for (int j = 0; j < m; j++) {\n                ans[i + j] +=\
    \ a[i] * b[j];\n            }\n        }\n        return ans;\n    }\n    int\
    \ z = 1 << internal::ceil_pow2(n + m - 1);\n    a.resize(z);\n    internal::butterfly(a);\n\
    \    b.resize(z);\n    internal::butterfly(b);\n    for (int i = 0; i < z; i++)\
    \ {\n        a[i] *= b[i];\n    }\n    internal::butterfly_inv(a);\n    a.resize(n\
    \ + m - 1);\n    mint iz = mint(z).inv();\n    for (int i = 0; i < n + m - 1;\
    \ i++) a[i] *= iz;\n    return a;\n}\n\ntemplate <unsigned int mod = 998244353,\
    \ class T,\n          std::enable_if_t<internal::is_integral<T>::value>* = nullptr>\n\
    std::vector<T> convolution(const std::vector<T>& a, const std::vector<T>& b) {\n\
    \    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n\
    \n    using mint = static_modint<mod>;\n    std::vector<mint> a2(n), b2(m);\n\
    \    for (int i = 0; i < n; i++) {\n        a2[i] = mint(a[i]);\n    }\n    for\
    \ (int i = 0; i < m; i++) {\n        b2[i] = mint(b[i]);\n    }\n    auto c2 =\
    \ convolution(move(a2), move(b2));\n    std::vector<T> c(n + m - 1);\n    for\
    \ (int i = 0; i < n + m - 1; i++) {\n        c[i] = c2[i].val();\n    }\n    return\
    \ c;\n}\n\nstd::vector<long long> convolution_ll(const std::vector<long long>&\
    \ a,\n                                      const std::vector<long long>& b) {\n\
    \    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n\
    \n    static constexpr unsigned long long MOD1 = 754974721;  // 2^24\n    static\
    \ constexpr unsigned long long MOD2 = 167772161;  // 2^25\n    static constexpr\
    \ unsigned long long MOD3 = 469762049;  // 2^26\n    static constexpr unsigned\
    \ long long M2M3 = MOD2 * MOD3;\n    static constexpr unsigned long long M1M3\
    \ = MOD1 * MOD3;\n    static constexpr unsigned long long M1M2 = MOD1 * MOD2;\n\
    \    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;\n\n    static\
    \ constexpr unsigned long long i1 =\n        internal::inv_gcd(MOD2 * MOD3, MOD1).second;\n\
    \    static constexpr unsigned long long i2 =\n        internal::inv_gcd(MOD1\
    \ * MOD3, MOD2).second;\n    static constexpr unsigned long long i3 =\n      \
    \  internal::inv_gcd(MOD1 * MOD2, MOD3).second;\n\n    auto c1 = convolution<MOD1>(a,\
    \ b);\n    auto c2 = convolution<MOD2>(a, b);\n    auto c3 = convolution<MOD3>(a,\
    \ b);\n\n    std::vector<long long> c(n + m - 1);\n    for (int i = 0; i < n +\
    \ m - 1; i++) {\n        unsigned long long x = 0;\n        x += (c1[i] * i1)\
    \ % MOD1 * M2M3;\n        x += (c2[i] * i2) % MOD2 * M1M3;\n        x += (c3[i]\
    \ * i3) % MOD3 * M1M2;\n        // B = 2^63, -B <= x, r(real value) < B\n    \
    \    // (x, x - M, x - 2M, or x - 3M) = r (mod 2B)\n        // r = c1[i] (mod\
    \ MOD1)\n        // focus on MOD1\n        // r = x, x - M', x - 2M', x - 3M'\
    \ (M' = M % 2^64) (mod 2B)\n        // r = x,\n        //     x - M' + (0 or 2B),\n\
    \        //     x - 2M' + (0, 2B or 4B),\n        //     x - 3M' + (0, 2B, 4B\
    \ or 6B) (without mod!)\n        // (r - x) = 0, (0)\n        //           - M'\
    \ + (0 or 2B), (1)\n        //           -2M' + (0 or 2B or 4B), (2)\n       \
    \ //           -3M' + (0 or 2B or 4B or 6B) (3) (mod MOD1)\n        // we checked\
    \ that\n        //   ((1) mod MOD1) mod 5 = 2\n        //   ((2) mod MOD1) mod\
    \ 5 = 3\n        //   ((3) mod MOD1) mod 5 = 4\n        long long diff =\n   \
    \         c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));\n   \
    \     if (diff < 0) diff += MOD1;\n        static constexpr unsigned long long\
    \ offset[5] = {\n            0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\n        x\
    \ -= offset[diff % 5];\n        c[i] = x;\n    }\n\n    return c;\n}\n\ntemplate\
    \ <typename T, typename std::enable_if_t<internal::is_modint<T>::value,\n    \
    \                                            std::nullptr_t> = nullptr>\nstd::istream&\
    \ operator>>(std::istream& is, T& v) {\n    long long x;\n    is >> x;\n    v\
    \ = x;\n    return is;\n}\ntemplate <typename T, typename std::enable_if_t<internal::is_modint<T>::value,\n\
    \                                                std::nullptr_t> = nullptr>\n\
    std::ostream& operator<<(std::ostream& os, const T& v) {\n    os << v.val();\n\
    \    return os;\n}\n}  // namespace modint\n#line 6 \"test/library-checker/range_affine_range_sum.test.cpp\"\
    \n\nusing mint = modint::modint998244353;\nstruct S {\n    mint val;\n    int\
    \ size;\n};\nS op(S a, S b) {\n    return {a.val + b.val, a.size + b.size};\n\
    }\nS e() {\n    return {0, 0};\n}\nstruct F {\n    mint b, c;\n};\nF id() {\n\
    \    return {1, 0};\n}\nS mapping(F f, S x) {\n    return {f.b * x.val + f.c *\
    \ x.size, x.size};\n}\nF composition(F f, F g) {\n    return {f.b * g.b, f.b *\
    \ g.c + f.c};\n}\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n   \
    \ std::vector<S> a(n);\n    for (int i = 0; i < n; i++) {\n        std::cin >>\
    \ a[i].val;\n        a[i].size = 1;\n    }\n    LazySegmentTree<S, op, e, F, mapping,\
    \ composition, id> segt(a);\n    while (q--) {\n        int t;\n        std::cin\
    \ >> t;\n        if (t == 0) {\n            int l, r, b, c;\n            std::cin\
    \ >> l >> r >> b >> c;\n            segt.apply(l, r, {b, c});\n        }\n   \
    \     if (t == 1) {\n            int l, r;\n            std::cin >> l >> r;\n\
    \            std::cout << segt.prod(l, r).val << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include <iostream>\n\n#include \"../../datastructure/lazy_segment_tree.hpp\"\
    \n#include \"../../math/modint.hpp\"\n\nusing mint = modint::modint998244353;\n\
    struct S {\n    mint val;\n    int size;\n};\nS op(S a, S b) {\n    return {a.val\
    \ + b.val, a.size + b.size};\n}\nS e() {\n    return {0, 0};\n}\nstruct F {\n\
    \    mint b, c;\n};\nF id() {\n    return {1, 0};\n}\nS mapping(F f, S x) {\n\
    \    return {f.b * x.val + f.c * x.size, x.size};\n}\nF composition(F f, F g)\
    \ {\n    return {f.b * g.b, f.b * g.c + f.c};\n}\n\nint main() {\n    int n, q;\n\
    \    std::cin >> n >> q;\n    std::vector<S> a(n);\n    for (int i = 0; i < n;\
    \ i++) {\n        std::cin >> a[i].val;\n        a[i].size = 1;\n    }\n    LazySegmentTree<S,\
    \ op, e, F, mapping, composition, id> segt(a);\n    while (q--) {\n        int\
    \ t;\n        std::cin >> t;\n        if (t == 0) {\n            int l, r, b,\
    \ c;\n            std::cin >> l >> r >> b >> c;\n            segt.apply(l, r,\
    \ {b, c});\n        }\n        if (t == 1) {\n            int l, r;\n        \
    \    std::cin >> l >> r;\n            std::cout << segt.prod(l, r).val << '\\\
    n';\n        }\n    }\n}"
  dependsOn:
  - datastructure/lazy_segment_tree.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/library-checker/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-09-03 00:04:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/range_affine_range_sum.test.cpp
- /verify/test/library-checker/range_affine_range_sum.test.cpp.html
title: test/library-checker/range_affine_range_sum.test.cpp
---
