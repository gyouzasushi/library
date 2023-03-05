#pragma once
#include <algorithm>
#include <array>
#include <cassert>
#include <random>
#include <vector>

#include "../math/modint2305843009213693951.hpp"
#include "../math/pow_table.hpp"
template <int base_num = 1, typename mint = modint2305843009213693951>
struct rolling_hash {
public:
    rolling_hash() {
    }
    rolling_hash(const std::vector<int>& a) : n(a.size()) {
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
    static rolling_hash from(const Iterable& s) {
        std::vector<int> a;
        for (auto&& e : s) a.push_back(int(e));
        return rolling_hash(a);
    }
    std::array<mint, base_num> operator()(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
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
        if (l1 + x == r1 && l2 + x == r2) return 0;
        if (l1 + x != r1 && l2 + x == r2) return 1;
        return (*this)(l1 + x, l1 + x + 1)[0].val() <
                       (*this)(l2 + x, l2 + x + 1)[0].val()
                   ? -1
                   : 1;
    }
    static int lcp(rolling_hash<base_num, mint>& rh1, int l1, int r1,
                   rolling_hash<base_num, mint>& rh2, int l2, int r2) {
        int len = std::min(r1 - l1, r2 - l2);
        int ok = 0, ng = len + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            bool f = rh1(l1, l1 + mid) == rh2(l2, l2 + mid);
            (f ? ok : ng) = mid;
        }
        return ok;
    }
    static int cmp(rolling_hash<base_num, mint>& rh1, int l1, int r1,
                   rolling_hash<base_num, mint>& rh2, int l2, int r2) {
        int x = std::min({lcp(rh1, l1, r1, rh2, l2, r2), r1 - l1, r2 - l2});
        if (l1 + x == r1 && l2 + x != r2) return -1;
        if (l1 + x == r1 && l2 + x == r2) return 0;
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
            while (true) {
                uint64_t k = std::uniform_int_distribution<uint64_t>(
                    1, mint::mod - 1)(rng);
                if (std::gcd(k, mint::mod - 1) != 1) continue;
                uint64_t b = mint(r).pow(k).val();
                if (b <= A) continue;
                bases[i] = b;
                break;
            }
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
    static constexpr uint64_t r = 37;
    static constexpr uint64_t A = 2147483647;
};