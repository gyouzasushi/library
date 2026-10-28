#pragma once
#include <algorithm>
#include <bit>
#include <cassert>
#include <cstdint>
#include <optional>
#include <type_traits>
#include <vector>

template <class T, class S = void> struct wavelet_matrix {
private:
    using W = std::conditional_t<std::is_void_v<S>, int, S>;
    static constexpr bool weighted = !std::is_void_v<S>;

public:
    wavelet_matrix() {
        build({}, {});
    }
    explicit wavelet_matrix(const std::vector<T>& a)
        requires (!weighted)
    {
        build(a, {});
    }
    wavelet_matrix(const std::vector<T>& a, const std::vector<S>& w)
        requires weighted
    {
        assert(a.size() == w.size());
        build(a, w);
    }

    int size() const {
        return n;
    }
    // #{ i in [l, r) : a[i] < upper }
    int count(int l, int r, T upper) const {
        assert(0 <= l && l <= r && r <= n);
        return count_rank(l, r, rank_of(upper));
    }
    // #{ i in [l, r) : lower <= a[i] < upper }
    int count(int l, int r, T lower, T upper) const {
        assert(0 <= l && l <= r && r <= n);
        int lo = rank_of(lower), hi = rank_of(upper);
        if (lo >= hi) return 0;
        return count_rank(l, r, hi) - count_rank(l, r, lo);
    }
    // k-th smallest (0-indexed) of a[l..r)
    T kth_smallest(int l, int r, int k) const {
        assert(0 <= l && l <= r && r <= n);
        assert(0 <= k && k < r - l);
        int res = 0;
        for (int d = log - 1; d >= 0; d--) {
            int l0 = bv[d].rank0(l), r0 = bv[d].rank0(r);
            if (k < r0 - l0) {
                l = l0, r = r0;
            } else {
                k -= r0 - l0;
                res |= 1 << d;
                l += bv[d].zeros - l0, r += bv[d].zeros - r0;
            }
        }
        return key[res];
    }
    // k-th largest (0-indexed) of a[l..r)
    T kth_largest(int l, int r, int k) const {
        assert(0 <= l && l <= r && r <= n);
        assert(0 <= k && k < r - l);
        return kth_smallest(l, r, r - l - 1 - k);
    }
    // max { a[i] : i in [l, r), a[i] < upper }
    std::optional<T> prev_value(int l, int r, T upper) const {
        assert(0 <= l && l <= r && r <= n);
        int c = count_rank(l, r, rank_of(upper));
        if (c == 0) return std::nullopt;
        return kth_smallest(l, r, c - 1);
    }
    // min { a[i] : i in [l, r), lower <= a[i] }
    std::optional<T> next_value(int l, int r, T lower) const {
        assert(0 <= l && l <= r && r <= n);
        int c = count_rank(l, r, rank_of(lower));
        if (c == r - l) return std::nullopt;
        return kth_smallest(l, r, c);
    }
    // sum of w[i] over i in [l, r) with a[i] < upper
    S sum(int l, int r, T upper) const
        requires weighted
    {
        assert(0 <= l && l <= r && r <= n);
        return sum_rank(l, r, rank_of(upper));
    }
    // sum of w[i] over i in [l, r) with lower <= a[i] < upper
    S sum(int l, int r, T lower, T upper) const
        requires weighted
    {
        assert(0 <= l && l <= r && r <= n);
        int lo = rank_of(lower), hi = rank_of(upper);
        if (lo >= hi) return S();
        return sum_rank(l, r, hi) - sum_rank(l, r, lo);
    }
    // sum of w[i] over the k elements of a[l..r) with the smallest (a[i], i)
    S sum_smallest(int l, int r, int k) const
        requires weighted
    {
        assert(0 <= l && l <= r && r <= n);
        assert(0 <= k && k <= r - l);
        if (k == r - l) return cs[log][r] - cs[log][l];
        S res = S();
        for (int d = log - 1; d >= 0; d--) {
            int l0 = bv[d].rank0(l), r0 = bv[d].rank0(r);
            if (k < r0 - l0) {
                l = l0, r = r0;
            } else {
                k -= r0 - l0;
                res += cs[d][r0] - cs[d][l0];
                l += bv[d].zeros - l0, r += bv[d].zeros - r0;
            }
        }
        return res + cs[0][l + k] - cs[0][l];
    }

private:
    struct bit_vector {
        std::vector<uint64_t> bits;
        std::vector<int> cnt;
        int zeros;
        explicit bit_vector(int n) : bits(n / 64 + 1), cnt(n / 64 + 2), zeros(n) {
        }
        void set(int i) {
            bits[i >> 6] |= uint64_t(1) << (i & 63);
        }
        void build() {
            for (int i = 0; i < int(bits.size()); i++) {
                cnt[i + 1] = cnt[i] + std::popcount(bits[i]);
            }
            zeros -= cnt.back();
        }
        int rank1(int i) const {
            return cnt[i >> 6] +
                   std::popcount(bits[i >> 6] & ((uint64_t(1) << (i & 63)) - 1));
        }
        int rank0(int i) const {
            return i - rank1(i);
        }
    };

    int n, log;
    std::vector<T> key;
    std::vector<bit_vector> bv;
    // cs[d]: prefix sums of weights in the order at level d (cs[log]: original order)
    std::vector<std::vector<W>> cs;

    void build(const std::vector<T>& a, const std::vector<W>& w) {
        n = int(a.size());
        key = a;
        std::ranges::sort(key);
        key.erase(std::ranges::unique(key).begin(), key.end());
        log = key.empty() ? 0 : std::bit_width(unsigned(key.size() - 1));
        std::vector<int> b(n), order(n);
        for (int i = 0; i < n; i++) {
            b[i] = int(std::ranges::lower_bound(key, a[i]) - key.begin());
            order[i] = i;
        }
        bv.assign(log, bit_vector(n));
        if constexpr (weighted) {
            cs.assign(log + 1, std::vector<W>(n + 1));
            for (int i = 0; i < n; i++) cs[log][i + 1] = cs[log][i] + w[i];
        }
        std::vector<int> next(n);
        for (int d = log - 1; d >= 0; d--) {
            int z = 0;
            for (int i = 0; i < n; i++) {
                if (b[order[i]] >> d & 1) {
                    bv[d].set(i);
                } else {
                    next[z++] = order[i];
                }
            }
            for (int i = 0; i < n; i++) {
                if (b[order[i]] >> d & 1) next[z++] = order[i];
            }
            bv[d].build();
            std::swap(order, next);
            if constexpr (weighted) {
                for (int i = 0; i < n; i++) cs[d][i + 1] = cs[d][i] + w[order[i]];
            }
        }
    }
    // #{ v in key : v < x }
    int rank_of(const T& x) const {
        return int(std::ranges::lower_bound(key, x) - key.begin());
    }
    // #{ i in [l, r) : b[i] < u }, 0 <= u <= |key|
    int count_rank(int l, int r, int u) const {
        if (u == 0) return 0;
        if (u >= int(key.size())) return r - l;
        int res = 0;
        for (int d = log - 1; d >= 0; d--) {
            int l0 = bv[d].rank0(l), r0 = bv[d].rank0(r);
            if (u >> d & 1) {
                res += r0 - l0;
                l += bv[d].zeros - l0, r += bv[d].zeros - r0;
            } else {
                l = l0, r = r0;
            }
        }
        return res;
    }
    S sum_rank(int l, int r, int u) const
        requires weighted
    {
        if (u == 0) return S();
        if (u >= int(key.size())) return cs[log][r] - cs[log][l];
        S res = S();
        for (int d = log - 1; d >= 0; d--) {
            int l0 = bv[d].rank0(l), r0 = bv[d].rank0(r);
            if (u >> d & 1) {
                res += cs[d][r0] - cs[d][l0];
                l += bv[d].zeros - l0, r += bv[d].zeros - r0;
            } else {
                l = l0, r = r0;
            }
        }
        return res;
    }
};
