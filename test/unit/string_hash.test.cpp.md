---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  - icon: ':heavy_check_mark:'
    path: datastructure/lazy_segtree.hpp
    title: Lazy Segment Tree (acted monoid wrapper)
  - icon: ':heavy_check_mark:'
    path: math/modint2305843009213693951.hpp
    title: modint2305843009213693951
  - icon: ':heavy_check_mark:'
    path: string/range_update_range_hash.hpp
    title: Range Update Range Hash
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: Rolling Hash
  - icon: ':heavy_check_mark:'
    path: string/string_hash.hpp
    title: String Hash
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unit/string_hash.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <set>\n#include <string>\n#include <vector>\n\n#line 4 \"string/range_update_range_hash.hpp\"\
    \n\n#line 2 \"datastructure/lazy_segtree.hpp\"\n#include <atcoder/lazysegtree>\n\
    \n#line 2 \"algebra/concept.hpp\"\n#include <concepts>\ntemplate <class M>\nconcept\
    \ semigroup = requires(typename M::S a, typename M::S b) {\n    { M::op(a, b)\
    \ } -> std::same_as<typename M::S>;\n};\ntemplate <class M>\nconcept monoid =\
    \ semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename M::S>;\n\
    };\ntemplate <class G>\nconcept group = monoid<G> && requires(typename G::S a)\
    \ {\n    { G::inv(a) } -> std::same_as<typename G::S>;\n};\ntemplate <class A>\n\
    concept action = requires(typename A::F f, typename A::F g) {\n    { A::composition(f,\
    \ g) } -> std::same_as<typename A::F>;\n    { A::id() } -> std::same_as<typename\
    \ A::F>;\n    { A::composition_commutative } -> std::convertible_to<bool>;\n};\n\
    template <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
    \ A::S x, typename A::F f) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n};\ntemplate <class R>\nconcept semiring = requires(typename R::S a,\
    \ typename R::S b) {\n    { R::add(a, b) } -> std::same_as<typename R::S>;\n \
    \   { R::zero() } -> std::same_as<typename R::S>;\n    { R::mul(a, b) } -> std::same_as<typename\
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\ntemplate <class\
    \ A>\nconcept beats_acted_monoid = acted_monoid<A> && requires(typename A::S x)\
    \ {\n    { x.fail } -> std::convertible_to<bool>;\n};\n#line 5 \"datastructure/lazy_segtree.hpp\"\
    \ntemplate <acted_monoid A>\nusing lazy_segtree = atcoder::lazy_segtree<typename\
    \ A::S, A::op, A::e, typename A::F, A::mapping, A::composition, A::id>;\n#line\
    \ 3 \"string/string_hash.hpp\"\n#include <array>\n#line 5 \"string/string_hash.hpp\"\
    \n#include <cstdint>\n#include <numeric>\n#line 9 \"string/string_hash.hpp\"\n\
    \n#line 5 \"math/modint2305843009213693951.hpp\"\nstruct modint2305843009213693951\
    \ {\n    using mint = modint2305843009213693951;\n    static constexpr uint64_t\
    \ mod() {\n        return m;\n    }\n    static mint raw(uint64_t v) {\n     \
    \   mint x;\n        x._v = v;\n        return x;\n    }\n    modint2305843009213693951()\
    \ : _v(0) {}\n    template <std::unsigned_integral T>\n    modint2305843009213693951(T\
    \ v) : _v(reduce(v)) {}\n    template <std::signed_integral T>\n    modint2305843009213693951(T\
    \ v) {\n        if (v >= 0) {\n            _v = reduce(uint64_t(v));\n       \
    \ } else {\n            uint64_t x = reduce(uint64_t(0) - uint64_t(v));\n    \
    \        _v = x == 0 ? 0 : m - x;\n        }\n    }\n    uint64_t val() const\
    \ {\n        return _v;\n    }\n    mint& operator++() {\n        if (++_v ==\
    \ m) _v = 0;\n        return *this;\n    }\n    mint& operator--() {\n       \
    \ if (_v == 0) _v = m;\n        _v--;\n        return *this;\n    }\n    mint\
    \ operator++(int) {\n        mint r = *this;\n        ++*this;\n        return\
    \ r;\n    }\n    mint operator--(int) {\n        mint r = *this;\n        --*this;\n\
    \        return r;\n    }\n    mint& operator+=(const mint& rhs) {\n        _v\
    \ += rhs._v;\n        if (_v >= m) _v -= m;\n        return *this;\n    }\n  \
    \  mint& operator-=(const mint& rhs) {\n        _v += m - rhs._v;\n        if\
    \ (_v >= m) _v -= m;\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        constexpr uint64_t mask31 = (uint64_t(1) << 31) - 1;\n\
    \        constexpr uint64_t mask30 = (uint64_t(1) << 30) - 1;\n        uint64_t\
    \ au = _v >> 31, ad = _v & mask31;\n        uint64_t bu = rhs._v >> 31, bd = rhs._v\
    \ & mask31;\n        uint64_t mid = ad * bu + au * bd;\n        uint64_t mu =\
    \ mid >> 30, md = mid & mask30;\n        _v = reduce((au * bu << 1) + mu + (md\
    \ << 31) + ad * bd);\n        return *this;\n    }\n    mint& operator/=(const\
    \ mint& rhs) {\n        return *this *= rhs.inv();\n    }\n    mint operator+()\
    \ const {\n        return *this;\n    }\n    mint operator-() const {\n      \
    \  return mint() - *this;\n    }\n    mint pow(long long n) const {\n        assert(0\
    \ <= n);\n        mint x = *this, r = 1;\n        while (n) {\n            if\
    \ (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n    \
    \    return r;\n    }\n    mint inv() const {\n        assert(_v != 0);\n    \
    \    return pow(m - 2);\n    }\n    friend mint operator+(const mint& lhs, const\
    \ mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend mint operator-(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n   \
    \ friend mint operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ *= rhs;\n    }\n    friend mint operator/(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n   \
    \ friend bool operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v\
    \ != rhs._v;\n    }\n\nprivate:\n    static constexpr uint64_t m = (uint64_t(1)\
    \ << 61) - 1;\n    static constexpr uint64_t reduce(uint64_t v) {\n        uint64_t\
    \ x = (v >> 61) + (v & m);\n        if (x >= m) x -= m;\n        return x;\n \
    \   }\n    uint64_t _v;\n};\n#line 11 \"string/string_hash.hpp\"\ntemplate <int\
    \ k = 1, class mint = modint2305843009213693951>\nstruct string_hash {\n    static_assert(k\
    \ >= 1);\n    std::array<mint, k> val;\n    int len;\n    string_hash() : val{},\
    \ len(0) {}\n    explicit string_hash(int c) : len(1) {\n        val.fill(mint(c));\n\
    \    }\n    static string_hash repeat(int c, int n) {\n        assert(0 <= n);\n\
    \        string_hash h;\n        h.len = n;\n        for (int i = 0; i < k; i++)\
    \ h.val[i] = mint(c) * pow_sum(i, n);\n        return h;\n    }\n    friend string_hash\
    \ operator+(const string_hash& a, const string_hash& b) {\n        string_hash\
    \ r;\n        r.len = a.len + b.len;\n        for (int i = 0; i < k; i++) r.val[i]\
    \ = a.val[i] * pow(i, b.len) + b.val[i];\n        return r;\n    }\n    string_hash&\
    \ operator+=(const string_hash& b) {\n        return *this = *this + b;\n    }\n\
    \    friend bool operator==(const string_hash& a, const string_hash& b) {\n  \
    \      return a.len == b.len && a.val == b.val;\n    }\n    friend bool operator<(const\
    \ string_hash& a, const string_hash& b) {\n        if (a.len != b.len) return\
    \ a.len < b.len;\n        for (int i = 0; i < k; i++) {\n            if (a.val[i]\
    \ != b.val[i]) return a.val[i].val() < b.val[i].val();\n        }\n        return\
    \ false;\n    }\n    static mint base(int i) {\n        return bases()[i];\n \
    \   }\n    static mint pow(int i, int n) {\n        ensure(n);\n        return\
    \ pows()[i][n];\n    }\n    static mint pow_sum(int i, int n) {\n        ensure(n);\n\
    \        return pow_sums()[i][n];\n    }\n\nprivate:\n    static std::array<mint,\
    \ k> gen_bases() {\n        std::mt19937_64 rng(std::random_device{}());\n   \
    \     std::array<mint, k> b;\n        for (int i = 0; i < k; i++) {\n        \
    \    while (true) {\n                uint64_t e = std::uniform_int_distribution<uint64_t>(1,\
    \ mint::mod() - 1)(rng);\n                if (std::gcd(e, uint64_t(mint::mod()\
    \ - 1)) != 1) continue;\n                b[i] = mint(37).pow(e);\n           \
    \     break;\n            }\n        }\n        return b;\n    }\n    static std::array<mint,\
    \ k>& bases() {\n        static std::array<mint, k> b = gen_bases();\n       \
    \ return b;\n    }\n    static std::array<std::vector<mint>, k>& pows() {\n  \
    \      static std::array<std::vector<mint>, k> p = [] {\n            std::array<std::vector<mint>,\
    \ k> p;\n            for (auto& v : p) v.assign(1, mint(1));\n            return\
    \ p;\n        }();\n        return p;\n    }\n    static std::array<std::vector<mint>,\
    \ k>& pow_sums() {\n        static std::array<std::vector<mint>, k> s = [] {\n\
    \            std::array<std::vector<mint>, k> s;\n            for (auto& v : s)\
    \ v.assign(1, mint(0));\n            return s;\n        }();\n        return s;\n\
    \    }\n    static void ensure(int n) {\n        auto& p = pows();\n        auto&\
    \ s = pow_sums();\n        int sz = int(p[0].size());\n        if (n < sz) return;\n\
    \        int m = std::max(n + 1, 2 * sz);\n        for (int i = 0; i < k; i++)\
    \ {\n            p[i].resize(m);\n            s[i].resize(m);\n            for\
    \ (int j = sz; j < m; j++) {\n                p[i][j] = p[i][j - 1] * base(i);\n\
    \                s[i][j] = s[i][j - 1] + p[i][j - 1];\n            }\n       \
    \ }\n    }\n};\ntemplate <class A, class B>\nint lcp(A& a, int l1, int r1, B&\
    \ b, int l2, int r2) {\n    int ok = 0, ng = std::min(r1 - l1, r2 - l2) + 1;\n\
    \    while (ng - ok > 1) {\n        int mid = (ok + ng) / 2;\n        (a.prod(l1,\
    \ l1 + mid) == b.prod(l2, l2 + mid) ? ok : ng) = mid;\n    }\n    return ok;\n\
    }\ntemplate <class A, class B>\nint cmp(A& a, int l1, int r1, B& b, int l2, int\
    \ r2) {\n    int x = lcp(a, l1, r1, b, l2, r2);\n    bool ea = l1 + x == r1, eb\
    \ = l2 + x == r2;\n    if (ea && eb) return 0;\n    if (ea) return -1;\n    if\
    \ (eb) return 1;\n    return a.get(l1 + x).val[0].val() < b.get(l2 + x).val[0].val()\
    \ ? -1 : 1;\n}\n#line 7 \"string/range_update_range_hash.hpp\"\ntemplate <int\
    \ k = 1, class mint = modint2305843009213693951>\nstruct range_update_range_hash\
    \ {\n    using H = string_hash<k, mint>;\n    range_update_range_hash() : n(0)\
    \ {}\n    template <class Iterable>\n    explicit range_update_range_hash(const\
    \ Iterable& s) {\n        std::vector<H> v;\n        for (auto&& c : s) v.emplace_back(int(c));\n\
    \        n = int(v.size());\n        seg = lazy_segtree<A>(v);\n    }\n    int\
    \ size() const {\n        return n;\n    }\n    void set(int p, int c) {\n   \
    \     assert(0 <= c);\n        seg.set(p, H(c));\n    }\n    void apply(int l,\
    \ int r, int c) {\n        assert(0 <= c);\n        seg.apply(l, r, c);\n    }\n\
    \    H prod(int l, int r) {\n        return seg.prod(l, r);\n    }\n    H get(int\
    \ p) {\n        return seg.get(p);\n    }\n    H all_prod() {\n        return\
    \ seg.all_prod();\n    }\n\nprivate:\n    struct A {\n        using S = H;\n \
    \       using F = int;\n        static S op(S a, S b) {\n            return a\
    \ + b;\n        }\n        static S e() {\n            return S();\n        }\n\
    \        static S mapping(F f, S x) {\n            return f < 0 ? x : H::repeat(f,\
    \ x.len);\n        }\n        static F composition(F f, F g) {\n            return\
    \ f < 0 ? g : f;\n        }\n        static F id() {\n            return -1;\n\
    \        }\n        static constexpr bool composition_commutative = false;\n \
    \   };\n    int n;\n    lazy_segtree<A> seg;\n};\n#line 5 \"string/rolling_hash.hpp\"\
    \n\n#line 7 \"string/rolling_hash.hpp\"\ntemplate <int k = 1, class mint = modint2305843009213693951>\n\
    struct rolling_hash {\n    using H = string_hash<k, mint>;\n    rolling_hash()\
    \ : n(0) {}\n    template <class Iterable>\n    explicit rolling_hash(const Iterable&\
    \ s) {\n        std::vector<int> a;\n        for (auto&& c : s) a.push_back(int(c));\n\
    \        n = int(a.size());\n        for (int i = 0; i < k; i++) {\n         \
    \   h[i].assign(n + 1, mint(0));\n            for (int j = 0; j < n; j++) h[i][j\
    \ + 1] = h[i][j] * H::base(i) + mint(a[j]);\n        }\n    }\n    int size()\
    \ const {\n        return n;\n    }\n    H prod(int l, int r) const {\n      \
    \  assert(0 <= l && l <= r && r <= n);\n        H res;\n        res.len = r -\
    \ l;\n        for (int i = 0; i < k; i++) res.val[i] = h[i][r] - h[i][l] * H::pow(i,\
    \ r - l);\n        return res;\n    }\n    H get(int p) const {\n        return\
    \ prod(p, p + 1);\n    }\n    H all_prod() const {\n        return prod(0, n);\n\
    \    }\n\nprivate:\n    int n;\n    std::array<std::vector<mint>, k> h;\n};\n\
    #line 13 \"test/unit/string_hash.test.cpp\"\nint brute_cmp(const std::string&\
    \ a, const std::string& b) {\n    return a < b ? -1 : a == b ? 0 : 1;\n}\nint\
    \ brute_lcp(const std::string& a, const std::string& b) {\n    int i = 0;\n  \
    \  while (i < int(a.size()) && i < int(b.size()) && a[i] == b[i]) i++;\n    return\
    \ i;\n}\nint main() {\n    std::mt19937 rng(7959);\n    for (int trial = 0; trial\
    \ < 200; trial++) {\n        int n = 1 + rng() % 12, m = 1 + rng() % 12;\n   \
    \     int sigma = 1 + rng() % 3;\n        std::string s(n, 'a'), t(m, 'a');\n\
    \        for (auto& c : s) c = 'a' + rng() % sigma;\n        for (auto& c : t)\
    \ c = 'a' + rng() % sigma;\n        rolling_hash<> rs(s);\n        range_update_range_hash<>\
    \ rt(t);\n        assert(rs.size() == n && rt.size() == m);\n        for (int\
    \ q = 0; q < 30; q++) {\n            if (rng() % 3 == 0) {\n                int\
    \ l = rng() % (m + 1), r = rng() % (m + 1);\n                if (l > r) std::swap(l,\
    \ r);\n                char c = 'a' + rng() % sigma;\n                rt.apply(l,\
    \ r, c);\n                for (int i = l; i < r; i++) t[i] = c;\n            }\
    \ else if (rng() % 3 == 0) {\n                int p = rng() % m;\n           \
    \     char c = 'a' + rng() % sigma;\n                rt.set(p, c);\n         \
    \       t[p] = c;\n            }\n            int l1 = rng() % (n + 1), r1 = rng()\
    \ % (n + 1);\n            if (l1 > r1) std::swap(l1, r1);\n            int l2\
    \ = rng() % (m + 1), r2 = rng() % (m + 1);\n            if (l2 > r2) std::swap(l2,\
    \ r2);\n            std::string a = s.substr(l1, r1 - l1), b = t.substr(l2, r2\
    \ - l2);\n            assert((rs.prod(l1, r1) == rt.prod(l2, r2)) == (a == b));\n\
    \            assert(lcp(rs, l1, r1, rt, l2, r2) == brute_lcp(a, b));\n       \
    \     assert(cmp(rs, l1, r1, rt, l2, r2) == brute_cmp(a, b));\n            assert(cmp(rt,\
    \ l2, r2, rs, l1, r1) == brute_cmp(b, a));\n            int l3 = rng() % (n +\
    \ 1), r3 = rng() % (n + 1);\n            if (l3 > r3) std::swap(l3, r3);\n   \
    \         std::string c = s.substr(l3, r3 - l3);\n            assert(cmp(rs, l1,\
    \ r1, rs, l3, r3) == brute_cmp(a, c));\n            assert(lcp(rs, l1, r1, rs,\
    \ l3, r3) == brute_lcp(a, c));\n            assert(rs.prod(l1, r1) + rs.prod(l3,\
    \ r3) == rolling_hash<>(a + c).all_prod());\n            assert(rs.prod(l1, r1)\
    \ + rt.prod(l2, r2) == rolling_hash<>(a + b).all_prod());\n            if (l1\
    \ < r1) assert(rs.get(l1) == string_hash<>(s[l1]));\n            assert(rt.all_prod()\
    \ == rolling_hash<>(t).all_prod());\n            assert(rt.prod(l2, r2) == rolling_hash<>(b).all_prod());\n\
    \        }\n        {\n            std::string r(n, 'a');\n            char c\
    \ = 'a' + rng() % sigma;\n            for (auto& x : r) x = c;\n            assert(string_hash<>::repeat(c,\
    \ n) == rolling_hash<>(r).all_prod());\n        }\n        {\n            std::set<string_hash<>>\
    \ hs;\n            std::set<std::string> ss;\n            for (int l = 0; l <=\
    \ n; l++)\n                for (int r = l; r <= n; r++) hs.insert(rs.prod(l, r)),\
    \ ss.insert(s.substr(l, r - l));\n            assert(hs.size() == ss.size());\n\
    \        }\n    }\n    {\n        rolling_hash<2> rh(std::vector<int>{1, 2, 3});\n\
    \        assert(rh.prod(0, 2) + rh.prod(2, 3) == rh.all_prod());\n        assert(rh.prod(0,\
    \ 0) == string_hash<2>());\n        assert(rolling_hash<2>(std::string(\"\")).all_prod()\
    \ == string_hash<2>());\n    }\n    std::cout << \"Hello World\" << std::endl;\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <set>\n#include <string>\n#include <vector>\n\n#include \"string/range_update_range_hash.hpp\"\
    \n#include \"string/rolling_hash.hpp\"\n#include \"string/string_hash.hpp\"\n\
    int brute_cmp(const std::string& a, const std::string& b) {\n    return a < b\
    \ ? -1 : a == b ? 0 : 1;\n}\nint brute_lcp(const std::string& a, const std::string&\
    \ b) {\n    int i = 0;\n    while (i < int(a.size()) && i < int(b.size()) && a[i]\
    \ == b[i]) i++;\n    return i;\n}\nint main() {\n    std::mt19937 rng(7959);\n\
    \    for (int trial = 0; trial < 200; trial++) {\n        int n = 1 + rng() %\
    \ 12, m = 1 + rng() % 12;\n        int sigma = 1 + rng() % 3;\n        std::string\
    \ s(n, 'a'), t(m, 'a');\n        for (auto& c : s) c = 'a' + rng() % sigma;\n\
    \        for (auto& c : t) c = 'a' + rng() % sigma;\n        rolling_hash<> rs(s);\n\
    \        range_update_range_hash<> rt(t);\n        assert(rs.size() == n && rt.size()\
    \ == m);\n        for (int q = 0; q < 30; q++) {\n            if (rng() % 3 ==\
    \ 0) {\n                int l = rng() % (m + 1), r = rng() % (m + 1);\n      \
    \          if (l > r) std::swap(l, r);\n                char c = 'a' + rng() %\
    \ sigma;\n                rt.apply(l, r, c);\n                for (int i = l;\
    \ i < r; i++) t[i] = c;\n            } else if (rng() % 3 == 0) {\n          \
    \      int p = rng() % m;\n                char c = 'a' + rng() % sigma;\n   \
    \             rt.set(p, c);\n                t[p] = c;\n            }\n      \
    \      int l1 = rng() % (n + 1), r1 = rng() % (n + 1);\n            if (l1 > r1)\
    \ std::swap(l1, r1);\n            int l2 = rng() % (m + 1), r2 = rng() % (m +\
    \ 1);\n            if (l2 > r2) std::swap(l2, r2);\n            std::string a\
    \ = s.substr(l1, r1 - l1), b = t.substr(l2, r2 - l2);\n            assert((rs.prod(l1,\
    \ r1) == rt.prod(l2, r2)) == (a == b));\n            assert(lcp(rs, l1, r1, rt,\
    \ l2, r2) == brute_lcp(a, b));\n            assert(cmp(rs, l1, r1, rt, l2, r2)\
    \ == brute_cmp(a, b));\n            assert(cmp(rt, l2, r2, rs, l1, r1) == brute_cmp(b,\
    \ a));\n            int l3 = rng() % (n + 1), r3 = rng() % (n + 1);\n        \
    \    if (l3 > r3) std::swap(l3, r3);\n            std::string c = s.substr(l3,\
    \ r3 - l3);\n            assert(cmp(rs, l1, r1, rs, l3, r3) == brute_cmp(a, c));\n\
    \            assert(lcp(rs, l1, r1, rs, l3, r3) == brute_lcp(a, c));\n       \
    \     assert(rs.prod(l1, r1) + rs.prod(l3, r3) == rolling_hash<>(a + c).all_prod());\n\
    \            assert(rs.prod(l1, r1) + rt.prod(l2, r2) == rolling_hash<>(a + b).all_prod());\n\
    \            if (l1 < r1) assert(rs.get(l1) == string_hash<>(s[l1]));\n      \
    \      assert(rt.all_prod() == rolling_hash<>(t).all_prod());\n            assert(rt.prod(l2,\
    \ r2) == rolling_hash<>(b).all_prod());\n        }\n        {\n            std::string\
    \ r(n, 'a');\n            char c = 'a' + rng() % sigma;\n            for (auto&\
    \ x : r) x = c;\n            assert(string_hash<>::repeat(c, n) == rolling_hash<>(r).all_prod());\n\
    \        }\n        {\n            std::set<string_hash<>> hs;\n            std::set<std::string>\
    \ ss;\n            for (int l = 0; l <= n; l++)\n                for (int r =\
    \ l; r <= n; r++) hs.insert(rs.prod(l, r)), ss.insert(s.substr(l, r - l));\n \
    \           assert(hs.size() == ss.size());\n        }\n    }\n    {\n       \
    \ rolling_hash<2> rh(std::vector<int>{1, 2, 3});\n        assert(rh.prod(0, 2)\
    \ + rh.prod(2, 3) == rh.all_prod());\n        assert(rh.prod(0, 0) == string_hash<2>());\n\
    \        assert(rolling_hash<2>(std::string(\"\")).all_prod() == string_hash<2>());\n\
    \    }\n    std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - string/range_update_range_hash.hpp
  - datastructure/lazy_segtree.hpp
  - algebra/concept.hpp
  - string/string_hash.hpp
  - math/modint2305843009213693951.hpp
  - string/rolling_hash.hpp
  isVerificationFile: true
  path: test/unit/string_hash.test.cpp
  requiredBy: []
  timestamp: '2026-10-29 12:09:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/string_hash.test.cpp
layout: document
redirect_from:
- /verify/test/unit/string_hash.test.cpp
- /verify/test/unit/string_hash.test.cpp.html
title: test/unit/string_hash.test.cpp
---
