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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_count_distinct
    links:
    - https://judge.yosupo.jp/problem/static_range_count_distinct
  bundledCode: "#line 1 \"test/library-checker/static_range_count_distinct.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_count_distinct\"\
    \n#include <iostream>\n#include <map>\n#include <vector>\n\n#line 2 \"datastructure/wavelet_matrix.hpp\"\
    \n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <cstdint>\n\
    #include <optional>\n#include <type_traits>\n#line 9 \"datastructure/wavelet_matrix.hpp\"\
    \n\ntemplate <class T, class S = void> struct wavelet_matrix {\nprivate:\n   \
    \ using W = std::conditional_t<std::is_void_v<S>, int, S>;\n    static constexpr\
    \ bool weighted = !std::is_void_v<S>;\n\npublic:\n    wavelet_matrix() {\n   \
    \     build({}, {});\n    }\n    explicit wavelet_matrix(const std::vector<T>&\
    \ a)\n        requires (!weighted)\n    {\n        build(a, {});\n    }\n    wavelet_matrix(const\
    \ std::vector<T>& a, const std::vector<S>& w)\n        requires weighted\n   \
    \ {\n        assert(a.size() == w.size());\n        build(a, w);\n    }\n\n  \
    \  int size() const {\n        return n;\n    }\n    // #{ i in [l, r) : a[i]\
    \ < upper }\n    int count(int l, int r, T upper) const {\n        assert(0 <=\
    \ l && l <= r && r <= n);\n        return count_rank(l, r, rank_of(upper));\n\
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
    \ r = r0;\n            }\n        }\n        return res;\n    }\n};\n#line 7 \"\
    test/library-checker/static_range_count_distinct.test.cpp\"\n\nint main() {\n\
    \    int n, q;\n    std::cin >> n >> q;\n    std::vector<int> prev(n);\n    std::map<int,\
    \ int> last;\n    for (int i = 0; i < n; i++) {\n        int a;\n        std::cin\
    \ >> a;\n        auto it = last.find(a);\n        prev[i] = it == last.end() ?\
    \ -1 : it->second;\n        last[a] = i;\n    }\n    wavelet_matrix<int> wm(prev);\n\
    \    while (q--) {\n        int l, r;\n        std::cin >> l >> r;\n        std::cout\
    \ << wm.count(l, r, l) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_count_distinct\"\
    \n#include <iostream>\n#include <map>\n#include <vector>\n\n#include \"datastructure/wavelet_matrix.hpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<int>\
    \ prev(n);\n    std::map<int, int> last;\n    for (int i = 0; i < n; i++) {\n\
    \        int a;\n        std::cin >> a;\n        auto it = last.find(a);\n   \
    \     prev[i] = it == last.end() ? -1 : it->second;\n        last[a] = i;\n  \
    \  }\n    wavelet_matrix<int> wm(prev);\n    while (q--) {\n        int l, r;\n\
    \        std::cin >> l >> r;\n        std::cout << wm.count(l, r, l) << '\\n';\n\
    \    }\n}\n"
  dependsOn:
  - datastructure/wavelet_matrix.hpp
  isVerificationFile: true
  path: test/library-checker/static_range_count_distinct.test.cpp
  requiredBy: []
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/static_range_count_distinct.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/static_range_count_distinct.test.cpp
- /verify/test/library-checker/static_range_count_distinct.test.cpp.html
title: test/library-checker/static_range_count_distinct.test.cpp
---
