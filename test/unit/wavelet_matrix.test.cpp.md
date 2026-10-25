---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/wavelet_matrix.hpp
    title: Wavelet Matrix
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
  bundledCode: "#line 1 \"test/unit/wavelet_matrix.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n#include\
    \ <vector>\n\n#line 3 \"datastructure/wavelet_matrix.hpp\"\n#include <bit>\n#line\
    \ 5 \"datastructure/wavelet_matrix.hpp\"\n#include <cstdint>\n#include <optional>\n\
    #include <type_traits>\n#line 9 \"datastructure/wavelet_matrix.hpp\"\n\ntemplate\
    \ <class T, class S = void> struct wavelet_matrix {\nprivate:\n    using W = std::conditional_t<std::is_void_v<S>,\
    \ int, S>;\n    static constexpr bool weighted = !std::is_void_v<S>;\n\npublic:\n\
    \    wavelet_matrix() : wavelet_matrix(std::vector<T>{}) {\n    }\n    explicit\
    \ wavelet_matrix(const std::vector<T>& a) {\n        std::vector<W> w;\n     \
    \   if constexpr (weighted) {\n            w.reserve(a.size());\n            for\
    \ (const T& x : a) w.push_back(W(x));\n        }\n        build(a, w);\n    }\n\
    \    wavelet_matrix(const std::vector<T>& a, const std::vector<S>& w)\n      \
    \  requires weighted\n    {\n        assert(a.size() == w.size());\n        build(a,\
    \ w);\n    }\n\n    int size() const {\n        return n;\n    }\n    // #{ i\
    \ in [l, r) : a[i] < upper }\n    int count(int l, int r, T upper) const {\n \
    \       assert(0 <= l && l <= r && r <= n);\n        return count_rank(l, r, rank_of(upper));\n\
    \    }\n    // #{ i in [l, r) : lower <= a[i] < upper }\n    int count(int l,\
    \ int r, T lower, T upper) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        int lo = rank_of(lower), hi = rank_of(upper);\n        if (lo >= hi)\
    \ return 0;\n        return count_rank(l, r, hi) - count_rank(l, r, lo);\n   \
    \ }\n    // k-th smallest (0-indexed) of a[l..r)\n    T kth_smallest(int l, int\
    \ r, int k) const {\n        assert(0 <= l && l <= r && r <= n);\n        assert(0\
    \ <= k && k < r - l);\n        int res = 0;\n        for (int d = log - 1; d >=\
    \ 0; d--) {\n            int l0 = bv[d].rank0(l), r0 = bv[d].rank0(r);\n     \
    \       if (k < r0 - l0) {\n                l = l0, r = r0;\n            } else\
    \ {\n                k -= r0 - l0;\n                res |= 1 << d;\n         \
    \       l += bv[d].zeros - l0, r += bv[d].zeros - r0;\n            }\n       \
    \ }\n        return key[res];\n    }\n    // k-th largest (0-indexed) of a[l..r)\n\
    \    T kth_largest(int l, int r, int k) const {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        assert(0 <= k && k < r - l);\n        return kth_smallest(l,\
    \ r, r - l - 1 - k);\n    }\n    // max { a[i] : i in [l, r), a[i] < upper }\n\
    \    std::optional<T> prev_value(int l, int r, T upper) const {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        int c = count_rank(l, r, rank_of(upper));\n\
    \        if (c == 0) return std::nullopt;\n        return kth_smallest(l, r, c\
    \ - 1);\n    }\n    // min { a[i] : i in [l, r), lower <= a[i] }\n    std::optional<T>\
    \ next_value(int l, int r, T lower) const {\n        assert(0 <= l && l <= r &&\
    \ r <= n);\n        int c = count_rank(l, r, rank_of(lower));\n        if (c ==\
    \ r - l) return std::nullopt;\n        return kth_smallest(l, r, c);\n    }\n\
    \    // sum of w[i] over i in [l, r) with a[i] < upper\n    S sum(int l, int r,\
    \ T upper) const\n        requires weighted\n    {\n        assert(0 <= l && l\
    \ <= r && r <= n);\n        return sum_rank(l, r, rank_of(upper));\n    }\n  \
    \  // sum of w[i] over i in [l, r) with lower <= a[i] < upper\n    S sum(int l,\
    \ int r, T lower, T upper) const\n        requires weighted\n    {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        int lo = rank_of(lower), hi = rank_of(upper);\n\
    \        if (lo >= hi) return S();\n        return sum_rank(l, r, hi) - sum_rank(l,\
    \ r, lo);\n    }\n    // sum of w[i] over the k elements of a[l..r) with the smallest\
    \ (a[i], i)\n    S sum_smallest(int l, int r, int k) const\n        requires weighted\n\
    \    {\n        assert(0 <= l && l <= r && r <= n);\n        assert(0 <= k &&\
    \ k <= r - l);\n        if (k == r - l) return cs[log][r] - cs[log][l];\n    \
    \    S res = S();\n        for (int d = log - 1; d >= 0; d--) {\n            int\
    \ l0 = bv[d].rank0(l), r0 = bv[d].rank0(r);\n            if (k < r0 - l0) {\n\
    \                l = l0, r = r0;\n            } else {\n                k -= r0\
    \ - l0;\n                res += cs[d][r0] - cs[d][l0];\n                l += bv[d].zeros\
    \ - l0, r += bv[d].zeros - r0;\n            }\n        }\n        return res +\
    \ cs[0][l + k] - cs[0][l];\n    }\n\nprivate:\n    struct bit_vector {\n     \
    \   std::vector<uint64_t> bits;\n        std::vector<int> cnt;\n        int zeros;\n\
    \        explicit bit_vector(int n) : bits(n / 64 + 1), cnt(n / 64 + 2), zeros(n)\
    \ {\n        }\n        void set(int i) {\n            bits[i >> 6] |= uint64_t(1)\
    \ << (i & 63);\n        }\n        void build() {\n            for (int i = 0;\
    \ i < int(bits.size()); i++) {\n                cnt[i + 1] = cnt[i] + std::popcount(bits[i]);\n\
    \            }\n            zeros -= cnt.back();\n        }\n        int rank1(int\
    \ i) const {\n            return cnt[i >> 6] +\n                   std::popcount(bits[i\
    \ >> 6] & ((uint64_t(1) << (i & 63)) - 1));\n        }\n        int rank0(int\
    \ i) const {\n            return i - rank1(i);\n        }\n    };\n\n    int n,\
    \ log;\n    std::vector<T> key;\n    std::vector<bit_vector> bv;\n    // cs[d]:\
    \ prefix sums of weights in the order at level d (cs[log]: original order)\n \
    \   std::vector<std::vector<W>> cs;\n\n    void build(const std::vector<T>& a,\
    \ const std::vector<W>& w) {\n        n = int(a.size());\n        key = a;\n \
    \       std::sort(key.begin(), key.end());\n        key.erase(std::unique(key.begin(),\
    \ key.end()), key.end());\n        log = key.empty() ? 0 : std::bit_width(unsigned(key.size()\
    \ - 1));\n        std::vector<int> b(n), order(n);\n        for (int i = 0; i\
    \ < n; i++) {\n            b[i] = int(std::lower_bound(key.begin(), key.end(),\
    \ a[i]) - key.begin());\n            order[i] = i;\n        }\n        bv.assign(log,\
    \ bit_vector(n));\n        if constexpr (weighted) {\n            cs.assign(log\
    \ + 1, std::vector<W>(n + 1));\n            for (int i = 0; i < n; i++) cs[log][i\
    \ + 1] = cs[log][i] + w[i];\n        }\n        std::vector<int> next(n);\n  \
    \      for (int d = log - 1; d >= 0; d--) {\n            int z = 0;\n        \
    \    for (int i = 0; i < n; i++) {\n                if (b[order[i]] >> d & 1)\
    \ {\n                    bv[d].set(i);\n                } else {\n           \
    \         next[z++] = order[i];\n                }\n            }\n          \
    \  for (int i = 0; i < n; i++) {\n                if (b[order[i]] >> d & 1) next[z++]\
    \ = order[i];\n            }\n            bv[d].build();\n            std::swap(order,\
    \ next);\n            if constexpr (weighted) {\n                for (int i =\
    \ 0; i < n; i++) cs[d][i + 1] = cs[d][i] + w[order[i]];\n            }\n     \
    \   }\n    }\n    // #{ v in key : v < x }\n    int rank_of(const T& x) const\
    \ {\n        return int(std::lower_bound(key.begin(), key.end(), x) - key.begin());\n\
    \    }\n    // #{ i in [l, r) : b[i] < u }, 0 <= u <= |key|\n    int count_rank(int\
    \ l, int r, int u) const {\n        if (u == 0) return 0;\n        if (u >= int(key.size()))\
    \ return r - l;\n        int res = 0;\n        for (int d = log - 1; d >= 0; d--)\
    \ {\n            int l0 = bv[d].rank0(l), r0 = bv[d].rank0(r);\n            if\
    \ (u >> d & 1) {\n                res += r0 - l0;\n                l += bv[d].zeros\
    \ - l0, r += bv[d].zeros - r0;\n            } else {\n                l = l0,\
    \ r = r0;\n            }\n        }\n        return res;\n    }\n    S sum_rank(int\
    \ l, int r, int u) const\n        requires weighted\n    {\n        if (u == 0)\
    \ return S();\n        if (u >= int(key.size())) return cs[log][r] - cs[log][l];\n\
    \        S res = S();\n        for (int d = log - 1; d >= 0; d--) {\n        \
    \    int l0 = bv[d].rank0(l), r0 = bv[d].rank0(r);\n            if (u >> d & 1)\
    \ {\n                res += cs[d][r0] - cs[d][l0];\n                l += bv[d].zeros\
    \ - l0, r += bv[d].zeros - r0;\n            } else {\n                l = l0,\
    \ r = r0;\n            }\n        }\n        return res;\n    }\n};\n#line 9 \"\
    test/unit/wavelet_matrix.test.cpp\"\n\ntemplate <class T, class S>\nvoid check(const\
    \ std::vector<T>& a, const std::vector<S>& w, std::mt19937& rng, T lo_v, T hi_v)\
    \ {\n    int n = int(a.size());\n    wavelet_matrix<T, S> wm(a, w);\n    wavelet_matrix<T>\
    \ wc(a);\n    assert(wm.size() == n && wc.size() == n);\n    auto rnd_v = [&](T\
    \ lo, T hi) { return T(lo + (long long)(rng() % (unsigned long long)(hi - lo +\
    \ 1))); };\n    for (int it = 0; it < 300; it++) {\n        int l = rng() % (n\
    \ + 1), r = rng() % (n + 1);\n        if (l > r) std::swap(l, r);\n        T x\
    \ = rnd_v(lo_v - 2, hi_v + 2), y = rnd_v(lo_v - 2, hi_v + 2);\n        // count\
    \ / sum\n        int c1 = 0, c2 = 0;\n        S s1 = S(), s2 = S();\n        for\
    \ (int i = l; i < r; i++) {\n            if (a[i] < x) c1++, s1 += w[i];\n   \
    \         if (x <= a[i] && a[i] < y) c2++, s2 += w[i];\n        }\n        assert(wm.count(l,\
    \ r, x) == c1 && wc.count(l, r, x) == c1);\n        assert(wm.count(l, r, x, y)\
    \ == c2 && wc.count(l, r, x, y) == c2);\n        assert(wm.sum(l, r, x) == s1);\n\
    \        assert(wm.sum(l, r, x, y) == s2);\n        // prev / next\n        std::optional<T>\
    \ pv, nv;\n        for (int i = l; i < r; i++) {\n            if (a[i] < x &&\
    \ (!pv || *pv < a[i])) pv = a[i];\n            if (x <= a[i] && (!nv || a[i] <\
    \ *nv)) nv = a[i];\n        }\n        assert(wm.prev_value(l, r, x) == pv &&\
    \ wc.prev_value(l, r, x) == pv);\n        assert(wm.next_value(l, r, x) == nv\
    \ && wc.next_value(l, r, x) == nv);\n        // kth / sum_smallest\n        std::vector<int>\
    \ idx(r - l);\n        for (int i = l; i < r; i++) idx[i - l] = i;\n        std::sort(idx.begin(),\
    \ idx.end(), [&](int i, int j) { return a[i] != a[j] ? a[i] < a[j] : i < j; });\n\
    \        S acc = S();\n        assert(wm.sum_smallest(l, r, 0) == acc);\n    \
    \    for (int k = 0; k < r - l; k++) {\n            assert(wm.kth_smallest(l,\
    \ r, k) == a[idx[k]]);\n            assert(wc.kth_smallest(l, r, k) == a[idx[k]]);\n\
    \            assert(wm.kth_largest(l, r, k) == a[idx[r - l - 1 - k]]);\n     \
    \       acc += w[idx[k]];\n            assert(wm.sum_smallest(l, r, k + 1) ==\
    \ acc);\n        }\n    }\n}\n\nint main() {\n    std::mt19937 rng(12345);\n \
    \   for (int it = 0; it < 200; it++) {\n        int n = rng() % 30;\n        int\
    \ range = 1 + rng() % 20;\n        std::vector<int> a(n);\n        std::vector<long\
    \ long> w(n);\n        for (int i = 0; i < n; i++) {\n            a[i] = int(rng()\
    \ % range) - range / 2;\n            w[i] = (long long)(rng() % 1000) - 500;\n\
    \        }\n        check<int, long long>(a, w, rng, -range / 2, range - range\
    \ / 2);\n    }\n    // long long keys with large magnitude, few distinct values\n\
    \    for (int it = 0; it < 50; it++) {\n        int n = 1 + rng() % 40;\n    \
    \    std::vector<long long> a(n), w(n);\n        std::vector<long long> pool =\
    \ {-(1LL << 60), -7, 0, 3, 1LL << 62};\n        int k = 1 + rng() % 5;\n     \
    \   for (int i = 0; i < n; i++) {\n            a[i] = pool[rng() % k];\n     \
    \       w[i] = (long long)(rng() % 100);\n        }\n        wavelet_matrix<long\
    \ long, long long> wm(a, w);\n        for (int q = 0; q < 100; q++) {\n      \
    \      int l = rng() % (n + 1), r = rng() % (n + 1);\n            if (l > r) std::swap(l,\
    \ r);\n            long long x = pool[rng() % 5] + (long long)(rng() % 3) - 1;\n\
    \            int c = 0;\n            long long s = 0;\n            for (int i\
    \ = l; i < r; i++) if (a[i] < x) c++, s += w[i];\n            assert(wm.count(l,\
    \ r, x) == c && wm.sum(l, r, x) == s);\n            if (r > l) {\n           \
    \     std::vector<long long> b(a.begin() + l, a.begin() + r);\n              \
    \  std::sort(b.begin(), b.end());\n                int kk = rng() % (r - l);\n\
    \                assert(wm.kth_smallest(l, r, kk) == b[kk]);\n            }\n\
    \        }\n    }\n    // weights default to the values\n    {\n        std::vector<int>\
    \ a = {5, 1, 4, 1, 3};\n        wavelet_matrix<int, long long> wm(a);\n      \
    \  assert(wm.sum_smallest(0, 5, 3) == 5);\n        assert(wm.sum(0, 5, 1, 4) ==\
    \ 5);\n        assert(wm.kth_smallest(0, 5, 2) == 3);\n        assert(wm.kth_largest(0,\
    \ 5, 0) == 5);\n        assert(!wm.prev_value(0, 5, 1));\n        assert(*wm.next_value(0,\
    \ 5, 4) == 4);\n        assert(!wm.next_value(0, 5, 6));\n    }\n    // empty\n\
    \    {\n        wavelet_matrix<int, long long> wm(std::vector<int>{});\n     \
    \   assert(wm.size() == 0);\n        assert(wm.count(0, 0, 10) == 0);\n      \
    \  assert(wm.sum(0, 0, 10) == 0);\n        assert(wm.sum_smallest(0, 0, 0) ==\
    \ 0);\n        assert(!wm.prev_value(0, 0, 10));\n        wavelet_matrix<int>\
    \ e;\n        assert(e.size() == 0);\n    }\n    std::cout << \"Hello World\"\
    \ << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\n#include \"datastructure/wavelet_matrix.hpp\"\n\ntemplate\
    \ <class T, class S>\nvoid check(const std::vector<T>& a, const std::vector<S>&\
    \ w, std::mt19937& rng, T lo_v, T hi_v) {\n    int n = int(a.size());\n    wavelet_matrix<T,\
    \ S> wm(a, w);\n    wavelet_matrix<T> wc(a);\n    assert(wm.size() == n && wc.size()\
    \ == n);\n    auto rnd_v = [&](T lo, T hi) { return T(lo + (long long)(rng() %\
    \ (unsigned long long)(hi - lo + 1))); };\n    for (int it = 0; it < 300; it++)\
    \ {\n        int l = rng() % (n + 1), r = rng() % (n + 1);\n        if (l > r)\
    \ std::swap(l, r);\n        T x = rnd_v(lo_v - 2, hi_v + 2), y = rnd_v(lo_v -\
    \ 2, hi_v + 2);\n        // count / sum\n        int c1 = 0, c2 = 0;\n       \
    \ S s1 = S(), s2 = S();\n        for (int i = l; i < r; i++) {\n            if\
    \ (a[i] < x) c1++, s1 += w[i];\n            if (x <= a[i] && a[i] < y) c2++, s2\
    \ += w[i];\n        }\n        assert(wm.count(l, r, x) == c1 && wc.count(l, r,\
    \ x) == c1);\n        assert(wm.count(l, r, x, y) == c2 && wc.count(l, r, x, y)\
    \ == c2);\n        assert(wm.sum(l, r, x) == s1);\n        assert(wm.sum(l, r,\
    \ x, y) == s2);\n        // prev / next\n        std::optional<T> pv, nv;\n  \
    \      for (int i = l; i < r; i++) {\n            if (a[i] < x && (!pv || *pv\
    \ < a[i])) pv = a[i];\n            if (x <= a[i] && (!nv || a[i] < *nv)) nv =\
    \ a[i];\n        }\n        assert(wm.prev_value(l, r, x) == pv && wc.prev_value(l,\
    \ r, x) == pv);\n        assert(wm.next_value(l, r, x) == nv && wc.next_value(l,\
    \ r, x) == nv);\n        // kth / sum_smallest\n        std::vector<int> idx(r\
    \ - l);\n        for (int i = l; i < r; i++) idx[i - l] = i;\n        std::sort(idx.begin(),\
    \ idx.end(), [&](int i, int j) { return a[i] != a[j] ? a[i] < a[j] : i < j; });\n\
    \        S acc = S();\n        assert(wm.sum_smallest(l, r, 0) == acc);\n    \
    \    for (int k = 0; k < r - l; k++) {\n            assert(wm.kth_smallest(l,\
    \ r, k) == a[idx[k]]);\n            assert(wc.kth_smallest(l, r, k) == a[idx[k]]);\n\
    \            assert(wm.kth_largest(l, r, k) == a[idx[r - l - 1 - k]]);\n     \
    \       acc += w[idx[k]];\n            assert(wm.sum_smallest(l, r, k + 1) ==\
    \ acc);\n        }\n    }\n}\n\nint main() {\n    std::mt19937 rng(12345);\n \
    \   for (int it = 0; it < 200; it++) {\n        int n = rng() % 30;\n        int\
    \ range = 1 + rng() % 20;\n        std::vector<int> a(n);\n        std::vector<long\
    \ long> w(n);\n        for (int i = 0; i < n; i++) {\n            a[i] = int(rng()\
    \ % range) - range / 2;\n            w[i] = (long long)(rng() % 1000) - 500;\n\
    \        }\n        check<int, long long>(a, w, rng, -range / 2, range - range\
    \ / 2);\n    }\n    // long long keys with large magnitude, few distinct values\n\
    \    for (int it = 0; it < 50; it++) {\n        int n = 1 + rng() % 40;\n    \
    \    std::vector<long long> a(n), w(n);\n        std::vector<long long> pool =\
    \ {-(1LL << 60), -7, 0, 3, 1LL << 62};\n        int k = 1 + rng() % 5;\n     \
    \   for (int i = 0; i < n; i++) {\n            a[i] = pool[rng() % k];\n     \
    \       w[i] = (long long)(rng() % 100);\n        }\n        wavelet_matrix<long\
    \ long, long long> wm(a, w);\n        for (int q = 0; q < 100; q++) {\n      \
    \      int l = rng() % (n + 1), r = rng() % (n + 1);\n            if (l > r) std::swap(l,\
    \ r);\n            long long x = pool[rng() % 5] + (long long)(rng() % 3) - 1;\n\
    \            int c = 0;\n            long long s = 0;\n            for (int i\
    \ = l; i < r; i++) if (a[i] < x) c++, s += w[i];\n            assert(wm.count(l,\
    \ r, x) == c && wm.sum(l, r, x) == s);\n            if (r > l) {\n           \
    \     std::vector<long long> b(a.begin() + l, a.begin() + r);\n              \
    \  std::sort(b.begin(), b.end());\n                int kk = rng() % (r - l);\n\
    \                assert(wm.kth_smallest(l, r, kk) == b[kk]);\n            }\n\
    \        }\n    }\n    // weights default to the values\n    {\n        std::vector<int>\
    \ a = {5, 1, 4, 1, 3};\n        wavelet_matrix<int, long long> wm(a);\n      \
    \  assert(wm.sum_smallest(0, 5, 3) == 5);\n        assert(wm.sum(0, 5, 1, 4) ==\
    \ 5);\n        assert(wm.kth_smallest(0, 5, 2) == 3);\n        assert(wm.kth_largest(0,\
    \ 5, 0) == 5);\n        assert(!wm.prev_value(0, 5, 1));\n        assert(*wm.next_value(0,\
    \ 5, 4) == 4);\n        assert(!wm.next_value(0, 5, 6));\n    }\n    // empty\n\
    \    {\n        wavelet_matrix<int, long long> wm(std::vector<int>{});\n     \
    \   assert(wm.size() == 0);\n        assert(wm.count(0, 0, 10) == 0);\n      \
    \  assert(wm.sum(0, 0, 10) == 0);\n        assert(wm.sum_smallest(0, 0, 0) ==\
    \ 0);\n        assert(!wm.prev_value(0, 0, 10));\n        wavelet_matrix<int>\
    \ e;\n        assert(e.size() == 0);\n    }\n    std::cout << \"Hello World\"\
    \ << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - datastructure/wavelet_matrix.hpp
  isVerificationFile: true
  path: test/unit/wavelet_matrix.test.cpp
  requiredBy: []
  timestamp: '2026-10-25 21:24:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/wavelet_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/unit/wavelet_matrix.test.cpp
- /verify/test/unit/wavelet_matrix.test.cpp.html
title: test/unit/wavelet_matrix.test.cpp
---
