#pragma once
#include <cassert>
#include <map>
#include <vector>
#if __has_include(<atcoder/math.hpp>)
#include <atcoder/math.hpp>
#else
#include "atcoder/math.hpp"
#endif
#include "math/factorize.hpp"
template <int id = -1>
struct binomial_coefficient_arbitrary_mod {
    static void set_mod(int mod) {
        assert(1 <= mod);
        m = mod;
        factors = factorize(m);
        f.assign(factors.size(), {});
        inv_f.assign(factors.size(), {});
        max_size = 0;
    }
    static long long C(long long n, long long k) {
        if (m == 1 || n < 0 || n < k || k < 0) return 0;
        ensure(n);
        long long r = n - k;
        std::vector<long long> rems(factors.size()), mods(factors.size());
        int idx = 0;
        for (auto [p, q] : factors) {
            long long p_q = pow_ll(p, q);
            mods[idx] = p_q;
            long long e1 = 0, e2 = 0;
            for (long long p_i = p_q;;) {
                e1 += n / p_i - k / p_i - r / p_i;
                if (p_i > n / p) break;
                p_i *= p;
            }
            for (long long p_i = p;;) {
                e2 += n / p_i - k / p_i - r / p_i;
                if (p_i > n / p) break;
                p_i *= p;
            }
            atcoder::internal::barrett bt((unsigned int)(p_q));
            long long delta = p == 2 && q >= 3 ? 1 : -1;
            long long rem = delta == -1 && e1 & 1 ? p_q - 1 : 1;
            rem = bt.mul(rem, atcoder::pow_mod(p, e2, p_q));
            for (long long p_i = 1;;) {
                rem = bt.mul(rem, f[idx][(n / p_i) % p_q]);
                rem = bt.mul(rem, inv_f[idx][(k / p_i) % p_q]);
                rem = bt.mul(rem, inv_f[idx][(r / p_i) % p_q]);
                if (p_i > n / p) break;
                p_i *= p;
            }
            rems[idx] = rem;
            idx++;
        }
        return atcoder::crt(rems, mods).first;
    }

private:
    static void ensure(long long n) {
        if (max_size > n) return;
        int idx = 0;
        for (auto [p, q] : factors) {
            long long p_q = pow_ll(p, q);
            int sz = f[idx].size();
            if ((long long)sz > std::min(p_q - 1, n) + 1) continue;
            f[idx].resize(std::min(p_q - 1, n) + 1);
            inv_f[idx].resize(std::min(p_q - 1, n) + 1);
            max_size = std::max(max_size, std::min(p_q - 1, n) + 1);
            atcoder::internal::barrett bt((unsigned int)(p_q));
            for (int i = sz; i <= std::min(p_q - 1, n); i++) {
                if (i == 0) {
                    f[idx][i] = 1;
                } else {
                    if (i % p == 0) {
                        f[idx][i] = f[idx][i - 1];
                    } else {
                        f[idx][i] = bt.mul(f[idx][i - 1], i);
                    }
                }
                inv_f[idx][i] = atcoder::inv_mod(f[idx][i], p_q);
            }
            idx++;
        }
    }
    static long long pow_ll(long long x, long long n) {
        assert(0 <= n && 1 <= m);
        long long r = 1, y = x;
        while (n) {
            if (n & 1) r *= y;
            n >>= 1;
            if (n) y *= y;
        }
        return r;
    }
    static inline long long m = -1;
    static inline long long max_size = 0;
    static inline std::map<long long, int> factors{};
    static inline std::vector<std::vector<long long>> f{};
    static inline std::vector<std::vector<long long>> inv_f{};
};
