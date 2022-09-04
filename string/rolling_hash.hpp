#pragma once
#include <cstdint>
struct modint2305843009213693951 {
    using mint = modint2305843009213693951;

public:
    static constexpr uint64_t mod = 2305843009213693951;
    modint2305843009213693951() : _v(0) {
    }
    modint2305843009213693951(uint64_t v) : _v(fast_mod(v)) {
    }
    static constexpr uint64_t fast_mod(uint64_t v) {
        uint64_t u = v >> 61;
        uint64_t d = v & mod;
        uint64_t x = u + d;
        if (x > mod) x -= mod;
        return x;
    }
    uint64_t val() const {
        return _v;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= mod) _v -= mod;
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= mod) _v += mod;
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        static constexpr uint64_t mask31 = (uint64_t(1) << 31) - 1;
        static constexpr uint64_t mask30 = (uint64_t(1) << 30) - 1;
        uint64_t au = _v >> 31;
        uint64_t ad = _v & mask31;
        uint64_t bu = rhs._v >> 31;
        uint64_t bd = rhs._v & mask31;
        uint64_t m = ad * bu + au * bd;
        uint64_t mu = m >> 30;
        uint64_t md = m & mask30;
        _v = fast_mod((au * bu << 1) + mu + (md << 31) + ad * bd);
        return *this;
    }
    mint operator+() const {
        return *this;
    }
    mint operator-() const {
        return mint() - *this;
    }
    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

private:
    uint64_t _v;
};

#include <vector>
template <typename mint>
struct pow_mods {
    pow_mods() {
    }
    pow_mods(mint base, int n) : base(base) {
        ensure(n);
    }
    const mint& operator[](int i) const {
        ensure(i);
        return pows[i];
    }
    void ensure(int n) const {
        int sz = pows.size();
        if (sz > n) return;
        pows.resize(n + 1);
        for (int i = sz; i <= n; i++) pows[i] = base * pows[i - 1];
    }

private:
    mutable std::vector<mint> pows{1};
    mint base;
    static constexpr int mod = mint::mod;
};

#include <algorithm>
#include <array>
#include <cassert>
#include <random>
template <int base_num = 1, typename mint = modint2305843009213693951>
struct RollingHash {
public:
    RollingHash() {
    }
    RollingHash(const std::vector<int>& a) : n(a.size()) {
        for (int base_id = 0; base_id < base_num; base_id++) {
            hashes[base_id].resize(n + 1);
            hashes[base_id][0] = 0;
            for (int i = 0; i < n; i++) {
                hashes[base_id][i + 1] =
                    hashes[base_id][i] * bases[base_id] + a[i];
            }
        }
    }
    template <typename Iterable>
    static RollingHash from(const Iterable& s) {
        std::vector<int> a;
        for (auto&& e : s) a.push_back(int(e));
        return RollingHash(a);
    }
    std::array<mint, base_num> operator()(int l, int r) {
        assert(0 <= l && l < n);
        assert(0 <= r && r <= n);
        assert(l <= r);
        std::array<mint, base_num> res;
        for (int base_id = 0; base_id < base_num; base_id++) {
            res[base_id] =
                hashes[base_id][r] - hashes[base_id][l] * pows[base_id][r - l];
        }
        return res;
    }
    static std::array<mint, base_num> concat(
        const std::array<mint, base_num>& h1,
        const std::array<mint, base_num>& h2, int h2_len) {
        std::array<mint, base_num> res;
        for (int base_id = 0; base_id < base_num; base_id++) {
            res[base_id] = h1[base_id] * pows[base_id][h2_len] + h2[base_id];
        }
        return res;
    }
    int lcp(int l1, int r1, int l2, int r2) {
        int len = std::min(r1 - l1, r2 - l2);
        int ok = 0, ng = len + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            bool f = (*this)(l1, l1 + mid) == (*this)(l2, l2 + mid);
            (f ? ok : ng) = mid;
        }
        return ok;
    }
    int cmp(int l1, int r1, int l2, int r2) {
        int x = std::min({lcp(l1, r1, l2, r2), r1 - l1, r2 - l2});
        if (l1 + x == r1 && l2 + x != r2) return -1;
        if (l1 + x == r1 || l2 + x == r2) return 0;
        if (l1 + x != r1 && l2 + x == r2) return 1;
        return (*this)(l1 + x, l1 + x + 1)[0].val() <
                       (*this)(l2 + x, l2 + x + 1)[0].val()
                   ? -1
                   : 1;
    }
    static int lcp(RollingHash<base_num, mint>& rh1, int l1, int r1,
                   RollingHash<base_num, mint>& rh2, int l2, int r2) {
        int len = std::min(r1 - l1, r2 - l2);
        int ok = 0, ng = len + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            bool f = rh1(l1, l1 + mid) == rh2(l2, l2 + mid);
            (f ? ok : ng) = mid;
        }
        return ok;
    }
    static int cmp(RollingHash<base_num, mint>& rh1, int l1, int r1,
                   RollingHash<base_num, mint>& rh2, int l2, int r2) {
        int x = std::min({lcp(rh1, l1, r1, rh2, l2, r2), r1 - l1, r2 - l2});
        if (l1 + x == r1 && l2 + x != r2) return -1;
        if (l1 + x == r1 || l2 + x == r2) return 0;
        if (l1 + x != r1 && l2 + x == r2) return 1;
        return rh1(l1 + x, l1 + x + 1)[0].val() <
                       rh2(l2 + x, l2 + x + 1)[0].val()
                   ? -1
                   : 1;
    }

private:
    static inline std::array<mint, base_num> gen_bases() {
        static std::mt19937_64 rng(std::random_device{}());
        std::array<mint, base_num> bases;
        for (int i = 0; i < base_num; i++) {
            bases[i] =
                std::uniform_int_distribution<uint64_t>(1, mint::mod - 1)(rng);
        }
        return bases;
    }
    static inline std::array<pow_mods<mint>, base_num> init_pows(
        const std::array<mint, base_num>& bases) {
        std::array<pow_mods<mint>, base_num> pows;
        for (int i = 0; i < base_num; i++) {
            pows[i] = pow_mods<mint>(bases[i], 0);
        }
        return pows;
    }
    static inline std::array<mint, base_num> bases = gen_bases();
    static inline std::array<pow_mods<mint>, base_num> pows = init_pows(bases);
    int n;
    std::array<std::vector<mint>, base_num> hashes;
};