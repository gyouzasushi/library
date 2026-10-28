---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: datastructure/rectangle_sum.hpp
    title: Rectangle Sum
  - icon: ':x:'
    path: datastructure/wavelet_matrix.hpp
    title: Wavelet Matrix
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
  bundledCode: "#line 1 \"test/unit/rectangle_sum.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <chrono>\n#include <iostream>\n#include <random>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\n#line 2 \"datastructure/rectangle_sum.hpp\"\
    \n#include <algorithm>\n#line 5 \"datastructure/rectangle_sum.hpp\"\n#include\
    \ <type_traits>\n#line 8 \"datastructure/rectangle_sum.hpp\"\n\n#line 3 \"datastructure/wavelet_matrix.hpp\"\
    \n#include <bit>\n#line 5 \"datastructure/wavelet_matrix.hpp\"\n#include <cstdint>\n\
    #include <optional>\n#line 9 \"datastructure/wavelet_matrix.hpp\"\n\ntemplate\
    \ <class T, class S = void> struct wavelet_matrix {\nprivate:\n    using W = std::conditional_t<std::is_void_v<S>,\
    \ int, S>;\n    static constexpr bool weighted = !std::is_void_v<S>;\n\npublic:\n\
    \    wavelet_matrix() {\n        build({}, {});\n    }\n    explicit wavelet_matrix(const\
    \ std::vector<T>& a)\n        requires (!weighted)\n    {\n        build(a, {});\n\
    \    }\n    wavelet_matrix(const std::vector<T>& a, const std::vector<S>& w)\n\
    \        requires weighted\n    {\n        assert(a.size() == w.size());\n   \
    \     build(a, w);\n    }\n\n    int size() const {\n        return n;\n    }\n\
    \    // #{ i in [l, r) : a[i] < upper }\n    int count(int l, int r, T upper)\
    \ const {\n        assert(0 <= l && l <= r && r <= n);\n        return count_rank(l,\
    \ r, rank_of(upper));\n    }\n    // #{ i in [l, r) : lower <= a[i] < upper }\n\
    \    int count(int l, int r, T lower, T upper) const {\n        assert(0 <= l\
    \ && l <= r && r <= n);\n        int lo = rank_of(lower), hi = rank_of(upper);\n\
    \        if (lo >= hi) return 0;\n        return count_rank(l, r, hi) - count_rank(l,\
    \ r, lo);\n    }\n    // k-th smallest (0-indexed) of a[l..r)\n    T kth_smallest(int\
    \ l, int r, int k) const {\n        assert(0 <= l && l <= r && r <= n);\n    \
    \    assert(0 <= k && k < r - l);\n        int res = 0;\n        for (int d =\
    \ log - 1; d >= 0; d--) {\n            int l0 = bv[d].rank0(l), r0 = bv[d].rank0(r);\n\
    \            if (k < r0 - l0) {\n                l = l0, r = r0;\n           \
    \ } else {\n                k -= r0 - l0;\n                res |= 1 << d;\n  \
    \              l += bv[d].zeros - l0, r += bv[d].zeros - r0;\n            }\n\
    \        }\n        return key[res];\n    }\n    // k-th largest (0-indexed) of\
    \ a[l..r)\n    T kth_largest(int l, int r, int k) const {\n        assert(0 <=\
    \ l && l <= r && r <= n);\n        assert(0 <= k && k < r - l);\n        return\
    \ kth_smallest(l, r, r - l - 1 - k);\n    }\n    // max { a[i] : i in [l, r),\
    \ a[i] < upper }\n    std::optional<T> prev_value(int l, int r, T upper) const\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        int c = count_rank(l,\
    \ r, rank_of(upper));\n        if (c == 0) return std::nullopt;\n        return\
    \ kth_smallest(l, r, c - 1);\n    }\n    // min { a[i] : i in [l, r), lower <=\
    \ a[i] }\n    std::optional<T> next_value(int l, int r, T lower) const {\n   \
    \     assert(0 <= l && l <= r && r <= n);\n        int c = count_rank(l, r, rank_of(lower));\n\
    \        if (c == r - l) return std::nullopt;\n        return kth_smallest(l,\
    \ r, c);\n    }\n    // sum of w[i] over i in [l, r) with a[i] < upper\n    S\
    \ sum(int l, int r, T upper) const\n        requires weighted\n    {\n       \
    \ assert(0 <= l && l <= r && r <= n);\n        return sum_rank(l, r, rank_of(upper));\n\
    \    }\n    // sum of w[i] over i in [l, r) with lower <= a[i] < upper\n    S\
    \ sum(int l, int r, T lower, T upper) const\n        requires weighted\n    {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        int lo = rank_of(lower),\
    \ hi = rank_of(upper);\n        if (lo >= hi) return S();\n        return sum_rank(l,\
    \ r, hi) - sum_rank(l, r, lo);\n    }\n    // sum of w[i] over the k elements\
    \ of a[l..r) with the smallest (a[i], i)\n    S sum_smallest(int l, int r, int\
    \ k) const\n        requires weighted\n    {\n        assert(0 <= l && l <= r\
    \ && r <= n);\n        assert(0 <= k && k <= r - l);\n        if (k == r - l)\
    \ return cs[log][r] - cs[log][l];\n        S res = S();\n        for (int d =\
    \ log - 1; d >= 0; d--) {\n            int l0 = bv[d].rank0(l), r0 = bv[d].rank0(r);\n\
    \            if (k < r0 - l0) {\n                l = l0, r = r0;\n           \
    \ } else {\n                k -= r0 - l0;\n                res += cs[d][r0] -\
    \ cs[d][l0];\n                l += bv[d].zeros - l0, r += bv[d].zeros - r0;\n\
    \            }\n        }\n        return res + cs[0][l + k] - cs[0][l];\n   \
    \ }\n\nprivate:\n    struct bit_vector {\n        std::vector<uint64_t> bits;\n\
    \        std::vector<int> cnt;\n        int zeros;\n        explicit bit_vector(int\
    \ n) : bits(n / 64 + 1), cnt(n / 64 + 2), zeros(n) {\n        }\n        void\
    \ set(int i) {\n            bits[i >> 6] |= uint64_t(1) << (i & 63);\n       \
    \ }\n        void build() {\n            for (int i = 0; i < int(bits.size());\
    \ i++) {\n                cnt[i + 1] = cnt[i] + std::popcount(bits[i]);\n    \
    \        }\n            zeros -= cnt.back();\n        }\n        int rank1(int\
    \ i) const {\n            return cnt[i >> 6] +\n                   std::popcount(bits[i\
    \ >> 6] & ((uint64_t(1) << (i & 63)) - 1));\n        }\n        int rank0(int\
    \ i) const {\n            return i - rank1(i);\n        }\n    };\n\n    int n,\
    \ log;\n    std::vector<T> key;\n    std::vector<bit_vector> bv;\n    // cs[d]:\
    \ prefix sums of weights in the order at level d (cs[log]: original order)\n \
    \   std::vector<std::vector<W>> cs;\n\n    void build(const std::vector<T>& a,\
    \ const std::vector<W>& w) {\n        n = int(a.size());\n        key = a;\n \
    \       std::ranges::sort(key);\n        key.erase(std::ranges::unique(key).begin(),\
    \ key.end());\n        log = key.empty() ? 0 : std::bit_width(unsigned(key.size()\
    \ - 1));\n        std::vector<int> b(n), order(n);\n        for (int i = 0; i\
    \ < n; i++) {\n            b[i] = int(std::ranges::lower_bound(key, a[i]) - key.begin());\n\
    \            order[i] = i;\n        }\n        bv.assign(log, bit_vector(n));\n\
    \        if constexpr (weighted) {\n            cs.assign(log + 1, std::vector<W>(n\
    \ + 1));\n            for (int i = 0; i < n; i++) cs[log][i + 1] = cs[log][i]\
    \ + w[i];\n        }\n        std::vector<int> next(n);\n        for (int d =\
    \ log - 1; d >= 0; d--) {\n            int z = 0;\n            for (int i = 0;\
    \ i < n; i++) {\n                if (b[order[i]] >> d & 1) {\n               \
    \     bv[d].set(i);\n                } else {\n                    next[z++] =\
    \ order[i];\n                }\n            }\n            for (int i = 0; i <\
    \ n; i++) {\n                if (b[order[i]] >> d & 1) next[z++] = order[i];\n\
    \            }\n            bv[d].build();\n            std::swap(order, next);\n\
    \            if constexpr (weighted) {\n                for (int i = 0; i < n;\
    \ i++) cs[d][i + 1] = cs[d][i] + w[order[i]];\n            }\n        }\n    }\n\
    \    // #{ v in key : v < x }\n    int rank_of(const T& x) const {\n        return\
    \ int(std::ranges::lower_bound(key, x) - key.begin());\n    }\n    // #{ i in\
    \ [l, r) : b[i] < u }, 0 <= u <= |key|\n    int count_rank(int l, int r, int u)\
    \ const {\n        if (u == 0) return 0;\n        if (u >= int(key.size())) return\
    \ r - l;\n        int res = 0;\n        for (int d = log - 1; d >= 0; d--) {\n\
    \            int l0 = bv[d].rank0(l), r0 = bv[d].rank0(r);\n            if (u\
    \ >> d & 1) {\n                res += r0 - l0;\n                l += bv[d].zeros\
    \ - l0, r += bv[d].zeros - r0;\n            } else {\n                l = l0,\
    \ r = r0;\n            }\n        }\n        return res;\n    }\n    S sum_rank(int\
    \ l, int r, int u) const\n        requires weighted\n    {\n        if (u == 0)\
    \ return S();\n        if (u >= int(key.size())) return cs[log][r] - cs[log][l];\n\
    \        S res = S();\n        for (int d = log - 1; d >= 0; d--) {\n        \
    \    int l0 = bv[d].rank0(l), r0 = bv[d].rank0(r);\n            if (u >> d & 1)\
    \ {\n                res += cs[d][r0] - cs[d][l0];\n                l += bv[d].zeros\
    \ - l0, r += bv[d].zeros - r0;\n            } else {\n                l = l0,\
    \ r = r0;\n            }\n        }\n        return res;\n    }\n};\n#line 10\
    \ \"datastructure/rectangle_sum.hpp\"\ntemplate <class T, class S = void> struct\
    \ rectangle_sum {\nprivate:\n    static constexpr bool weighted = !std::is_void_v<S>;\n\
    \npublic:\n    rectangle_sum() {\n    }\n    explicit rectangle_sum(std::vector<std::pair<T,\
    \ T>> points)\n        requires (!weighted)\n    {\n        std::ranges::sort(points);\n\
    \        int n = int(points.size());\n        std::vector<T> ys(n);\n        xs.resize(n);\n\
    \        for (int i = 0; i < n; i++) std::tie(xs[i], ys[i]) = points[i];\n   \
    \     wm = wavelet_matrix<T, S>(ys);\n    }\n    explicit rectangle_sum(std::vector<std::tuple<T,\
    \ T, S>> points)\n        requires weighted\n    {\n        std::ranges::sort(points,\
    \ [](const auto& a, const auto& b) {\n            return std::get<0>(a) < std::get<0>(b);\n\
    \        });\n        int n = int(points.size());\n        std::vector<T> ys(n);\n\
    \        std::vector<S> ws(n);\n        xs.resize(n);\n        for (int i = 0;\
    \ i < n; i++) std::tie(xs[i], ys[i], ws[i]) = points[i];\n        wm = wavelet_matrix<T,\
    \ S>(ys, ws);\n    }\n    int size() const {\n        return int(xs.size());\n\
    \    }\n    int count(T x1, T x2, T y1, T y2) const {\n        auto [l, r] = range(x1,\
    \ x2);\n        if (l >= r) return 0;\n        return wm.count(l, r, y1, y2);\n\
    \    }\n    S sum(T x1, T x2, T y1, T y2) const\n        requires weighted\n \
    \   {\n        auto [l, r] = range(x1, x2);\n        if (l >= r) return S();\n\
    \        return wm.sum(l, r, y1, y2);\n    }\n\nprivate:\n    std::vector<T> xs;\n\
    \    wavelet_matrix<T, S> wm;\n    std::pair<int, int> range(T x1, T x2) const\
    \ {\n        int l = int(std::ranges::lower_bound(xs, x1) - xs.begin());\n   \
    \     int r = int(std::ranges::lower_bound(xs, x2) - xs.begin());\n        return\
    \ {l, r};\n    }\n};\n#line 11 \"test/unit/rectangle_sum.test.cpp\"\nint main()\
    \ {\n    std::mt19937_64 rng(20261027);\n    for (int iter = 0; iter < 500; iter++)\
    \ {\n        int n = rng() % 30;\n        long long range = 1 + rng() % 20;\n\
    \        std::vector<std::tuple<long long, long long, long long>> pts(n);\n  \
    \      std::vector<std::pair<long long, long long>> pts2(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            long long x = (long long)(rng() % range) -\
    \ range / 2;\n            long long y = (long long)(rng() % range) - range / 2;\n\
    \            long long w = (long long)(rng() % 2001) - 1000;\n            pts[i]\
    \ = {x, y, w};\n            pts2[i] = {x, y};\n        }\n        rectangle_sum<long\
    \ long, long long> rs(pts);\n        rectangle_sum<long long> rc(pts2);\n    \
    \    assert(rs.size() == n && rc.size() == n);\n        for (int t = 0; t < 50;\
    \ t++) {\n            long long x1 = (long long)(rng() % (range + 2)) - range\
    \ / 2 - 1;\n            long long x2 = (long long)(rng() % (range + 2)) - range\
    \ / 2 - 1;\n            long long y1 = (long long)(rng() % (range + 2)) - range\
    \ / 2 - 1;\n            long long y2 = (long long)(rng() % (range + 2)) - range\
    \ / 2 - 1;\n            int cnt = 0;\n            long long sum = 0;\n       \
    \     for (auto [x, y, w] : pts) {\n                if (x1 <= x && x < x2 && y1\
    \ <= y && y < y2) cnt++, sum += w;\n            }\n            assert(rs.count(x1,\
    \ x2, y1, y2) == cnt);\n            assert(rc.count(x1, x2, y1, y2) == cnt);\n\
    \            assert(rs.sum(x1, x2, y1, y2) == sum);\n        }\n    }\n    {\n\
    \        int n = 200000, q = 200000;\n        auto start = std::chrono::steady_clock::now();\n\
    \        std::vector<std::tuple<int, int, long long>> pts(n);\n        for (auto&\
    \ [x, y, w] : pts) x = rng() % 1000000000, y = rng() % 1000000000, w = rng() %\
    \ 1000000000;\n        rectangle_sum<int, long long> rs(pts);\n        long long\
    \ acc = 0;\n        for (int i = 0; i < q; i++) {\n            int x1 = rng()\
    \ % 1000000000, x2 = rng() % 1000000000;\n            int y1 = rng() % 1000000000,\
    \ y2 = rng() % 1000000000;\n            if (x1 > x2) std::swap(x1, x2);\n    \
    \        if (y1 > y2) std::swap(y1, y2);\n            acc = (acc + rs.sum(x1,\
    \ x2, y1, y2)) % 1000000007;\n        }\n        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()\
    \ - start).count();\n        std::cerr << \"perf n=q=\" << n << \": \" << ms <<\
    \ \" ms (\" << acc % 1000 << \")\\n\";\n    }\n    std::cout << \"Hello World\\\
    n\";\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <chrono>\n#include <iostream>\n#include <random>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\n#include \"datastructure/rectangle_sum.hpp\"\
    \nint main() {\n    std::mt19937_64 rng(20261027);\n    for (int iter = 0; iter\
    \ < 500; iter++) {\n        int n = rng() % 30;\n        long long range = 1 +\
    \ rng() % 20;\n        std::vector<std::tuple<long long, long long, long long>>\
    \ pts(n);\n        std::vector<std::pair<long long, long long>> pts2(n);\n   \
    \     for (int i = 0; i < n; i++) {\n            long long x = (long long)(rng()\
    \ % range) - range / 2;\n            long long y = (long long)(rng() % range)\
    \ - range / 2;\n            long long w = (long long)(rng() % 2001) - 1000;\n\
    \            pts[i] = {x, y, w};\n            pts2[i] = {x, y};\n        }\n \
    \       rectangle_sum<long long, long long> rs(pts);\n        rectangle_sum<long\
    \ long> rc(pts2);\n        assert(rs.size() == n && rc.size() == n);\n       \
    \ for (int t = 0; t < 50; t++) {\n            long long x1 = (long long)(rng()\
    \ % (range + 2)) - range / 2 - 1;\n            long long x2 = (long long)(rng()\
    \ % (range + 2)) - range / 2 - 1;\n            long long y1 = (long long)(rng()\
    \ % (range + 2)) - range / 2 - 1;\n            long long y2 = (long long)(rng()\
    \ % (range + 2)) - range / 2 - 1;\n            int cnt = 0;\n            long\
    \ long sum = 0;\n            for (auto [x, y, w] : pts) {\n                if\
    \ (x1 <= x && x < x2 && y1 <= y && y < y2) cnt++, sum += w;\n            }\n \
    \           assert(rs.count(x1, x2, y1, y2) == cnt);\n            assert(rc.count(x1,\
    \ x2, y1, y2) == cnt);\n            assert(rs.sum(x1, x2, y1, y2) == sum);\n \
    \       }\n    }\n    {\n        int n = 200000, q = 200000;\n        auto start\
    \ = std::chrono::steady_clock::now();\n        std::vector<std::tuple<int, int,\
    \ long long>> pts(n);\n        for (auto& [x, y, w] : pts) x = rng() % 1000000000,\
    \ y = rng() % 1000000000, w = rng() % 1000000000;\n        rectangle_sum<int,\
    \ long long> rs(pts);\n        long long acc = 0;\n        for (int i = 0; i <\
    \ q; i++) {\n            int x1 = rng() % 1000000000, x2 = rng() % 1000000000;\n\
    \            int y1 = rng() % 1000000000, y2 = rng() % 1000000000;\n         \
    \   if (x1 > x2) std::swap(x1, x2);\n            if (y1 > y2) std::swap(y1, y2);\n\
    \            acc = (acc + rs.sum(x1, x2, y1, y2)) % 1000000007;\n        }\n \
    \       auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()\
    \ - start).count();\n        std::cerr << \"perf n=q=\" << n << \": \" << ms <<\
    \ \" ms (\" << acc % 1000 << \")\\n\";\n    }\n    std::cout << \"Hello World\\\
    n\";\n}\n"
  dependsOn:
  - datastructure/rectangle_sum.hpp
  - datastructure/wavelet_matrix.hpp
  isVerificationFile: true
  path: test/unit/rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unit/rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/unit/rectangle_sum.test.cpp
- /verify/test/unit/rectangle_sum.test.cpp.html
title: test/unit/rectangle_sum.test.cpp
---
