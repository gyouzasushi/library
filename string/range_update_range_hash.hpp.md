---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint2305843009213693951.hpp
    title: math/modint2305843009213693951.hpp
  - icon: ':heavy_check_mark:'
    path: math/pow_sum_table.hpp
    title: math/pow_sum_table.hpp
  - icon: ':heavy_check_mark:'
    path: math/pow_table.hpp
    title: math/pow_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0355.test.cpp
    title: test/aoj/0355.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/range_update_range_hash.hpp\"\n#include <algorithm>\n\
    #include <array>\n#include <random>\n\n#line 1 \"atcoder/lazysegtree.hpp\"\n\n\
    \n\n#line 5 \"atcoder/lazysegtree.hpp\"\n#include <cassert>\n#include <iostream>\n\
    #include <vector>\n\n#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n\
    #include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n\
    // @param n `0 <= n`\n// @return minimum non-negative `x` s.t. `n <= 2**x`\nint\
    \ ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n))\
    \ x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return minimum non-negative\
    \ `x` s.t. `(n & (1 << x)) != 0`\nconstexpr int bsf_constexpr(unsigned int n)\
    \ {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n}\n\n//\
    \ @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 << x))\
    \ != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n\
    \    _BitScanForward(&index, n);\n    return index;\n#else\n    return __builtin_ctz(n);\n\
    #endif\n}\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 10\
    \ \"atcoder/lazysegtree.hpp\"\n\nnamespace atcoder {\n\ntemplate <class S,\n \
    \         S (*op)(S, S),\n          S (*e)(),\n          class F,\n          S\
    \ (*mapping)(F, S),\n          F (*composition)(F, F),\n          F (*id)()>\n\
    struct lazy_segtree {\n  public:\n    lazy_segtree() : lazy_segtree(0) {}\n  \
    \  explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}\n  \
    \  explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {\n    \
    \    log = internal::ceil_pow2(_n);\n        size = 1 << log;\n        d = std::vector<S>(2\
    \ * size, e());\n        lz = std::vector<F>(size, id());\n        for (int i\
    \ = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1;\
    \ i--) {\n            update(i);\n        }\n    }\n\n    void set(int p, S x)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n        for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        return d[p];\n    }\n\n    S prod(int l, int r) {\n \
    \       assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return e();\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        S sml = e(),\
    \ smr = e();\n        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n\
    \            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ { return d[1]; }\n\n    void apply(int p, F f) {\n        assert(0 <= p && p\
    \ < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n        d[p] = mapping(f, d[p]);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n    void apply(int l, int r, F f) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if (l == r) return;\n\n        l += size;\n\
    \        r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n\
    \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
    \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n   \
    \             r >>= 1;\n            }\n            l = l2;\n            r = r2;\n\
    \        }\n\n        for (int i = 1; i <= log; i++) {\n            if (((l >>\
    \ i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n\n    template <bool (*g)(S)> int max_right(int\
    \ l) {\n        return max_right(l, [](S x) { return g(x); });\n    }\n    template\
    \ <class G> int max_right(int l, G g) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(g(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        for (int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n \
    \       do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (g(op(sm, d[l]))) {\n\
    \                        sm = op(sm, d[l]);\n                        l++;\n  \
    \                  }\n                }\n                return l - size;\n  \
    \          }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*g)(S)> int\
    \ min_left(int r) {\n        return min_left(r, [](S x) { return g(x); });\n \
    \   }\n    template <class G> int min_left(int r, G g) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(g(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    push(r);\n                    r = (2 * r +\
    \ 1);\n                    if (g(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - size;\n            }\n         \
    \   sm = op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n\n  private:\n    int _n, size, log;\n    std::vector<S> d;\n    std::vector<F>\
    \ lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n    void\
    \ all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n        if (k < size)\
    \ lz[k] = composition(f, lz[k]);\n    }\n    void push(int k) {\n        all_apply(2\
    \ * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n\
    \    }\n};\n\n}  // namespace atcoder\n\n\n#line 2 \"math/modint2305843009213693951.hpp\"\
    \n#include <cstdint>\nstruct modint2305843009213693951 {\n    using mint = modint2305843009213693951;\n\
    \npublic:\n    static constexpr uint64_t mod = 2305843009213693951;\n    modint2305843009213693951()\
    \ : _v(0) {\n    }\n    modint2305843009213693951(uint64_t v) : _v(fast_mod(v))\
    \ {\n    }\n    static constexpr uint64_t fast_mod(uint64_t v) {\n        uint64_t\
    \ u = v >> 61;\n        uint64_t d = v & mod;\n        uint64_t x = u + d;\n \
    \       if (x > mod) x -= mod;\n        return x;\n    }\n    uint64_t val() const\
    \ {\n        return _v;\n    }\n\n    mint& operator+=(const mint& rhs) {\n  \
    \      _v += rhs._v;\n        if (_v >= mod) _v -= mod;\n        return *this;\n\
    \    }\n    mint& operator-=(const mint& rhs) {\n        _v -= rhs._v;\n     \
    \   if (_v >= mod) _v += mod;\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        static constexpr uint64_t mask31 = (uint64_t(1) << 31)\
    \ - 1;\n        static constexpr uint64_t mask30 = (uint64_t(1) << 30) - 1;\n\
    \        uint64_t au = _v >> 31;\n        uint64_t ad = _v & mask31;\n       \
    \ uint64_t bu = rhs._v >> 31;\n        uint64_t bd = rhs._v & mask31;\n      \
    \  uint64_t m = ad * bu + au * bd;\n        uint64_t mu = m >> 30;\n        uint64_t\
    \ md = m & mask30;\n        _v = fast_mod((au * bu << 1) + mu + (md << 31) + ad\
    \ * bd);\n        return *this;\n    }\n    mint operator+() const {\n       \
    \ return *this;\n    }\n    mint operator-() const {\n        return mint() -\
    \ *this;\n    }\n    mint pow(uint64_t n) const {\n        mint x = *this, r =\
    \ 1;\n        while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return r;\n    }\n    friend mint operator+(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n   \
    \ friend mint operator-(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ -= rhs;\n    }\n    friend mint operator*(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) *= rhs;\n    }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n   \
    \ friend bool operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v\
    \ != rhs._v;\n    }\n\nprivate:\n    uint64_t _v;\n};\n#line 2 \"math/pow_sum_table.hpp\"\
    \ntemplate <typename mint>\nstruct pow_mod_sums {\n    pow_mod_sums() {\n    }\n\
    \    pow_mod_sums(mint base, int n) : base(base) {\n        ensure(n);\n    }\n\
    \    // sum(pow[0..i])\n    const mint& operator[](int i) const {\n        ensure(i);\n\
    \        return pow_sums[i];\n    }\n    void ensure(int n) const {\n        int\
    \ sz = pow_sums.size();\n        if (sz > n) return;\n        pow_sums.resize(n\
    \ + 1);\n        pows.resize(n + 1);\n        for (int i = sz; i <= n; i++) {\n\
    \            pows[i] = base * pows[i - 1];\n            pow_sums[i] = pow_sums[i\
    \ - 1] + pows[i - 1];\n        }\n    }\n\nprivate:\n    mutable std::vector<mint>\
    \ pow_sums{0};\n    mutable std::vector<mint> pows{1};\n    mint base;\n    static\
    \ constexpr int mod = mint::mod;\n};\n#line 3 \"math/pow_table.hpp\"\ntemplate\
    \ <typename mint>\nstruct pow_mods {\n    pow_mods() {\n    }\n    pow_mods(mint\
    \ base, int n) : base(base) {\n        ensure(n);\n    }\n    const mint& operator[](int\
    \ i) const {\n        ensure(i);\n        return pows[i];\n    }\n    void ensure(int\
    \ n) const {\n        int sz = pows.size();\n        if (sz > n) return;\n   \
    \     pows.resize(n + 1);\n        for (int i = sz; i <= n; i++) pows[i] = base\
    \ * pows[i - 1];\n    }\n\nprivate:\n    mutable std::vector<mint> pows{1};\n\
    \    mint base;\n    static constexpr int mod = mint::mod;\n};\n#line 10 \"string/range_update_range_hash.hpp\"\
    \ntemplate <int base_num = 1, typename mint = modint2305843009213693951>\nstruct\
    \ range_update_range_hash {\npublic:\n    range_update_range_hash() {\n    }\n\
    \    range_update_range_hash(const std::vector<int>& a) : n(a.size()) {\n    \
    \    std::vector<S> v(n);\n        for (int i = 0; i < n; i++) {\n           \
    \ for (int base_id = 0; base_id < base_num; base_id++) {\n                v[i].hash[base_id]\
    \ = a[i];\n            }\n            v[i].size = 1;\n            v[i].is_e =\
    \ false;\n        }\n        segt = atcoder::lazy_segtree<S, op, e, F, mapping,\
    \ composition, id>(v);\n    }\n    template <typename Iterable>\n    static range_update_range_hash\
    \ from(const Iterable& s) {\n        std::vector<int> a;\n        for (auto&&\
    \ e : s) a.push_back(int(e));\n        return range_update_range_hash(a);\n  \
    \  }\n\n    template <typename T>\n    void set(int p, T x) {\n        segt.set(p,\
    \ int(x));\n    }\n    std::array<mint, base_num> get(int p) {\n        return\
    \ segt.get(p).hash;\n    }\n    std::array<mint, base_num> prod(int l, int r)\
    \ {\n        return segt.prod(l, r).hash;\n    }\n    std::array<mint, base_num>\
    \ all_prod() {\n        return segt.all_prod();\n    }\n    template <typename\
    \ T>\n    void apply(int l, int r, T x) {\n        segt.apply(l, r, {int(x), false});\n\
    \    }\n    int lcp(int l1, int r1, int l2, int r2) {\n        int len = std::min(r1\
    \ - l1, r2 - l2);\n        int ok = 0, ng = len + 1;\n        while (ng - ok >\
    \ 1) {\n            int mid = (ok + ng) / 2;\n            bool f = prod(l1, l1\
    \ + mid) == prod(l2, l2 + mid);\n            (f ? ok : ng) = mid;\n        }\n\
    \        return ok;\n    }\n    int cmp(int l1, int r1, int l2, int r2) {\n  \
    \      int x = std::min({lcp(l1, r1, l2, r2), r1 - l1, r2 - l2});\n        if\
    \ (l1 + x == r1 && l2 + x != r2) return -1;\n        if (l1 + x == r1 && l2 +\
    \ x == r2) return 0;\n        if (l1 + x != r1 && l2 + x == r2) return 1;\n  \
    \      return get(l1 + x)[0].val() < get(l2 + x)[0].val() ? -1 : 1;\n    }\n\n\
    private:\n    static inline std::array<mint, base_num> gen_bases() {\n       \
    \ static std::mt19937_64 rng(std::random_device{}());\n        std::array<mint,\
    \ base_num> bases;\n        for (int i = 0; i < base_num; i++) {\n           \
    \ while (true) {\n                uint64_t k = std::uniform_int_distribution<uint64_t>(\n\
    \                    1, mint::mod - 1)(rng);\n                if (std::gcd(k,\
    \ mint::mod - 1) != 1) continue;\n                uint64_t b = mint(r).pow(k).val();\n\
    \                if (b <= A) continue;\n                bases[i] = b;\n      \
    \          break;\n            }\n        }\n        return bases;\n    }\n  \
    \  static inline std::array<pow_mod_sums<mint>, base_num> init_pow_sums(\n   \
    \     const std::array<mint, base_num>& bases) {\n        std::array<pow_mod_sums<mint>,\
    \ base_num> pow_sums;\n        for (int i = 0; i < base_num; i++) {\n        \
    \    pow_sums[i] = pow_mod_sums<mint>(bases[i], 0);\n        }\n        return\
    \ pow_sums;\n    }\n    static inline std::array<pow_mods<mint>, base_num> init_pows(\n\
    \        const std::array<mint, base_num>& bases) {\n        std::array<pow_mods<mint>,\
    \ base_num> pows;\n        for (int i = 0; i < base_num; i++) {\n            pows[i]\
    \ = pow_mods<mint>(bases[i], 0);\n        }\n        return pows;\n    }\n   \
    \ static inline std::array<mint, base_num> bases = gen_bases();\n    static inline\
    \ std::array<pow_mod_sums<mint>, base_num> pow_sums =\n        init_pow_sums(bases);\n\
    \    static inline std::array<pow_mods<mint>, base_num> pows = init_pows(bases);\n\
    \    int n;\n    static constexpr uint64_t r = 37;\n    static constexpr uint64_t\
    \ A = 2147483647;\n\n    struct S {\n        std::array<mint, base_num> hash;\n\
    \        int size;\n        bool is_e;\n    };\n    static S op(S a, S b) {\n\
    \        if (a.is_e) return b;\n        if (b.is_e) return a;\n        for (int\
    \ base_id = 0; base_id < base_num; base_id++) {\n            b.hash[base_id] +=\
    \ a.hash[base_id] * pows[base_id][b.size];\n        }\n        b.size += a.size;\n\
    \        return b;\n    }\n    static S e() {\n        return {std::array<mint,\
    \ base_num>(), 0, true};\n    }\n    struct F {\n        int f;\n        bool\
    \ is_id;\n    };\n    static S mapping(F f, S x) {\n        if (!f.is_id) {\n\
    \            for (int base_id = 0; base_id < base_num; base_id++) {\n        \
    \        x.hash[base_id] = f.f * pow_sums[base_id][x.size];\n            }\n \
    \       }\n        return x;\n    }\n    static F composition(F f, F g) {\n  \
    \      return (f.is_id ? g : f);\n    }\n    static F id() {\n        return {0,\
    \ true};\n    }\n    atcoder::lazy_segtree<S, op, e, F, mapping, composition,\
    \ id> segt;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <array>\n#include <random>\n\
    \n#include \"atcoder/lazysegtree.hpp\"\n#include \"math/modint2305843009213693951.hpp\"\
    \n#include \"math/pow_sum_table.hpp\"\n#include \"math/pow_table.hpp\"\ntemplate\
    \ <int base_num = 1, typename mint = modint2305843009213693951>\nstruct range_update_range_hash\
    \ {\npublic:\n    range_update_range_hash() {\n    }\n    range_update_range_hash(const\
    \ std::vector<int>& a) : n(a.size()) {\n        std::vector<S> v(n);\n       \
    \ for (int i = 0; i < n; i++) {\n            for (int base_id = 0; base_id < base_num;\
    \ base_id++) {\n                v[i].hash[base_id] = a[i];\n            }\n  \
    \          v[i].size = 1;\n            v[i].is_e = false;\n        }\n       \
    \ segt = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>(v);\n  \
    \  }\n    template <typename Iterable>\n    static range_update_range_hash from(const\
    \ Iterable& s) {\n        std::vector<int> a;\n        for (auto&& e : s) a.push_back(int(e));\n\
    \        return range_update_range_hash(a);\n    }\n\n    template <typename T>\n\
    \    void set(int p, T x) {\n        segt.set(p, int(x));\n    }\n    std::array<mint,\
    \ base_num> get(int p) {\n        return segt.get(p).hash;\n    }\n    std::array<mint,\
    \ base_num> prod(int l, int r) {\n        return segt.prod(l, r).hash;\n    }\n\
    \    std::array<mint, base_num> all_prod() {\n        return segt.all_prod();\n\
    \    }\n    template <typename T>\n    void apply(int l, int r, T x) {\n     \
    \   segt.apply(l, r, {int(x), false});\n    }\n    int lcp(int l1, int r1, int\
    \ l2, int r2) {\n        int len = std::min(r1 - l1, r2 - l2);\n        int ok\
    \ = 0, ng = len + 1;\n        while (ng - ok > 1) {\n            int mid = (ok\
    \ + ng) / 2;\n            bool f = prod(l1, l1 + mid) == prod(l2, l2 + mid);\n\
    \            (f ? ok : ng) = mid;\n        }\n        return ok;\n    }\n    int\
    \ cmp(int l1, int r1, int l2, int r2) {\n        int x = std::min({lcp(l1, r1,\
    \ l2, r2), r1 - l1, r2 - l2});\n        if (l1 + x == r1 && l2 + x != r2) return\
    \ -1;\n        if (l1 + x == r1 && l2 + x == r2) return 0;\n        if (l1 + x\
    \ != r1 && l2 + x == r2) return 1;\n        return get(l1 + x)[0].val() < get(l2\
    \ + x)[0].val() ? -1 : 1;\n    }\n\nprivate:\n    static inline std::array<mint,\
    \ base_num> gen_bases() {\n        static std::mt19937_64 rng(std::random_device{}());\n\
    \        std::array<mint, base_num> bases;\n        for (int i = 0; i < base_num;\
    \ i++) {\n            while (true) {\n                uint64_t k = std::uniform_int_distribution<uint64_t>(\n\
    \                    1, mint::mod - 1)(rng);\n                if (std::gcd(k,\
    \ mint::mod - 1) != 1) continue;\n                uint64_t b = mint(r).pow(k).val();\n\
    \                if (b <= A) continue;\n                bases[i] = b;\n      \
    \          break;\n            }\n        }\n        return bases;\n    }\n  \
    \  static inline std::array<pow_mod_sums<mint>, base_num> init_pow_sums(\n   \
    \     const std::array<mint, base_num>& bases) {\n        std::array<pow_mod_sums<mint>,\
    \ base_num> pow_sums;\n        for (int i = 0; i < base_num; i++) {\n        \
    \    pow_sums[i] = pow_mod_sums<mint>(bases[i], 0);\n        }\n        return\
    \ pow_sums;\n    }\n    static inline std::array<pow_mods<mint>, base_num> init_pows(\n\
    \        const std::array<mint, base_num>& bases) {\n        std::array<pow_mods<mint>,\
    \ base_num> pows;\n        for (int i = 0; i < base_num; i++) {\n            pows[i]\
    \ = pow_mods<mint>(bases[i], 0);\n        }\n        return pows;\n    }\n   \
    \ static inline std::array<mint, base_num> bases = gen_bases();\n    static inline\
    \ std::array<pow_mod_sums<mint>, base_num> pow_sums =\n        init_pow_sums(bases);\n\
    \    static inline std::array<pow_mods<mint>, base_num> pows = init_pows(bases);\n\
    \    int n;\n    static constexpr uint64_t r = 37;\n    static constexpr uint64_t\
    \ A = 2147483647;\n\n    struct S {\n        std::array<mint, base_num> hash;\n\
    \        int size;\n        bool is_e;\n    };\n    static S op(S a, S b) {\n\
    \        if (a.is_e) return b;\n        if (b.is_e) return a;\n        for (int\
    \ base_id = 0; base_id < base_num; base_id++) {\n            b.hash[base_id] +=\
    \ a.hash[base_id] * pows[base_id][b.size];\n        }\n        b.size += a.size;\n\
    \        return b;\n    }\n    static S e() {\n        return {std::array<mint,\
    \ base_num>(), 0, true};\n    }\n    struct F {\n        int f;\n        bool\
    \ is_id;\n    };\n    static S mapping(F f, S x) {\n        if (!f.is_id) {\n\
    \            for (int base_id = 0; base_id < base_num; base_id++) {\n        \
    \        x.hash[base_id] = f.f * pow_sums[base_id][x.size];\n            }\n \
    \       }\n        return x;\n    }\n    static F composition(F f, F g) {\n  \
    \      return (f.is_id ? g : f);\n    }\n    static F id() {\n        return {0,\
    \ true};\n    }\n    atcoder::lazy_segtree<S, op, e, F, mapping, composition,\
    \ id> segt;\n};"
  dependsOn:
  - math/modint2305843009213693951.hpp
  - math/pow_sum_table.hpp
  - math/pow_table.hpp
  isVerificationFile: false
  path: string/range_update_range_hash.hpp
  requiredBy: []
  timestamp: '2023-03-05 19:19:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0355.test.cpp
documentation_of: string/range_update_range_hash.hpp
layout: document
title: Range Update Range Hash
---

### 概要
- 区間更新に対応した Rolling-Hash。
  
### 使い方
- `range_update_range_hash<base_num, mint>::from(s)`: 文字列 `s` を初期値として構築する。`base_num` 個の基数を用いて、`mint` でハッシュを計算する。デフォルトは、`base_num = 1, mint = modint2305843009213693951`。
- `prod(l, r)`: `s[l..r]` のハッシュ値を求める。
- `all_prod()`: `s` のハッシュ値を求める。
- `apply(l, r, x)`: `s[l..r]` を `x` で置き換える。
- `set(p, x)`: `s[p]` を `x` で置き換える。
- `get(p)`: `s[p]` のハッシュ値を求める。
- `lcp(l1, r1, l2, r2)`: `s[l1..r1]` と `s[l2..r2]` の LCP の長さを求める。
- `cmp(l1, r1, l2, r2)`: `s1 = s[l1..r1]` と `s2 = s[l2..r2]` を辞書順で比較する。返り値は、`s1 < s2 ? -1 : s1 == s2 ? 0 : 1`。

### 計算量
- 構築: $\mathcal{O}(N)$
- `prod`: $\mathcal{O}(\log N)$
- `all_prod`: $\mathcal{O}(1)$
- `apply`: $\mathcal{O}(\log N)$
- `set`: $\mathcal{O}(\log N)$
- `get`: $\mathcal{O}(\log N)$
- `lcp`: $\mathcal{O}((\log N)^2)$
- `cmp`: $\mathcal{O}((\log N)^2)$