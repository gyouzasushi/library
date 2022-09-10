#pragma once
#include <algorithm>
#include <array>
#include <random>

#include "../datastructure/lazy_segment_tree.hpp"
#include "../math/modint2305843009213693951.hpp"
#include "../math/pow_sum_table.hpp"
#include "../math/pow_table.hpp"
template <int base_num = 1, typename mint = modint2305843009213693951>
struct RangeUpdateRangeHash {
public:
    RangeUpdateRangeHash() {
    }
    RangeUpdateRangeHash(const std::vector<int>& a) : n(a.size()) {
        std::vector<S> v(n);
        for (int i = 0; i < n; i++) {
            for (int base_id = 0; base_id < base_num; base_id++) {
                v[i].hash[base_id] = a[i];
            }
            v[i].size = 1;
            v[i].is_e = false;
        }
        segt = LazySegmentTree<S, op, e, F, mapping, composition, id>(v);
    }
    template <typename Iterable>
    static RangeUpdateRangeHash from(const Iterable& s) {
        std::vector<int> a;
        for (auto&& e : s) a.push_back(int(e));
        return RangeUpdateRangeHash(a);
    }

    template <typename T>
    void set(int p, T x) {
        segt.set(p, int(x));
    }
    std::array<mint, base_num> get(int p) {
        return segt.get(p).hash;
    }
    std::array<mint, base_num> prod(int l, int r) {
        return segt.prod(l, r).hash;
    }
    std::array<mint, base_num> all_prod() {
        return segt.all_prod();
    }
    template <typename T>
    void apply(int l, int r, T x) {
        segt.apply(l, r, {int(x), false});
    }
    int lcp(int l1, int r1, int l2, int r2) {
        int len = std::min(r1 - l1, r2 - l2);
        int ok = 0, ng = len + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            bool f = prod(l1, l1 + mid) == prod(l2, l2 + mid);
            (f ? ok : ng) = mid;
        }
        return ok;
    }
    int cmp(int l1, int r1, int l2, int r2) {
        int x = std::min({lcp(l1, r1, l2, r2), r1 - l1, r2 - l2});
        if (l1 + x == r1 && l2 + x != r2) return -1;
        if (l1 + x == r1 && l2 + x == r2) return 0;
        if (l1 + x != r1 && l2 + x == r2) return 1;
        return get(l1 + x)[0].val() < get(l2 + x)[0].val() ? -1 : 1;
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
    static inline std::array<pow_mod_sums<mint>, base_num> init_pow_sums(
        const std::array<mint, base_num>& bases) {
        std::array<pow_mod_sums<mint>, base_num> pow_sums;
        for (int i = 0; i < base_num; i++) {
            pow_sums[i] = pow_mod_sums<mint>(bases[i], 0);
        }
        return pow_sums;
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
    static inline std::array<pow_mod_sums<mint>, base_num> pow_sums =
        init_pow_sums(bases);
    static inline std::array<pow_mods<mint>, base_num> pows = init_pows(bases);
    int n;
    static constexpr uint64_t r = 37;
    static constexpr uint64_t A = 2147483647;

    struct S {
        std::array<mint, base_num> hash;
        int size;
        bool is_e;
    };
    static S op(S a, S b) {
        if (a.is_e) return b;
        if (b.is_e) return a;
        for (int base_id = 0; base_id < base_num; base_id++) {
            b.hash[base_id] += a.hash[base_id] * pows[base_id][b.size];
        }
        b.size += a.size;
        return b;
    }
    static S e() {
        return {std::array<mint, base_num>(), 0, true};
    }
    struct F {
        int f;
        bool is_id;
    };
    static S mapping(F f, S x) {
        if (!f.is_id) {
            for (int base_id = 0; base_id < base_num; base_id++) {
                x.hash[base_id] = f.f * pow_sums[base_id][x.size];
            }
        }
        return x;
    }
    static F composition(F f, F g) {
        return (f.is_id ? g : f);
    }
    static F id() {
        return {0, true};
    }
    LazySegmentTree<S, op, e, F, mapping, composition, id> segt;
};