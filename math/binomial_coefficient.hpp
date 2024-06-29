#pragma once
#include <vector>
template <typename mint>
struct factorial_table {
    static mint val(int i) {
        ensure(i);
        return facts[i];
    }
    static mint inv(int i) {
        ensure(i);
        return ifacts[i];
    }
    static void ensure(int n) {
        int sz = facts.size();
        if (sz > n) return;
        if (n < sz << 1) n = std::min(mint::mod() - 1, sz << 1);
        facts.resize(n + 1);
        ifacts.resize(n + 1);
        for (int i = sz; i <= n; i++) facts[i] = facts[i - 1] * i;
        ifacts[n] = facts[n].inv();
        for (int i = n; i >= sz; i--) ifacts[i - 1] = ifacts[i] * i;
    }

private:
    static inline std::vector<mint> facts{1};
    static inline std::vector<mint> ifacts{1};
};

template <typename mint>
struct binomial_coefficient {
    using facts = factorial_table<mint>;
    static mint C(int n, int k) {
        if (n < 0 || n < k || k < 0) return 0;
        return facts::val(n) * facts::inv(n - k) * facts::inv(k);
    }
    static mint P(int n, int k) {
        if (n < 0 || n < k || k < 0) return 0;
        return facts::val(n) * facts::inv(n - k);
    }
    static mint H(int n, int k) {
        if (n < 0 || k < 0) return 0;
        if (k == 0) return 1;
        return C(n + k - 1, k);
    }
};

#include "atcoder/math.hpp"
#include "math/factorize.hpp"
struct binomial_coefficient_arbitrary_mod {
    static void set_mod(int mod) {
        assert(1 <= mod);
        m = mod;
        factors = factorize(m);
        f.assign(factors.size(), {});
        inv_f.assign(factors.size(), {});
    }
    static long long C(long long n, long long k) {
        if (m == 1 || n < 0 || n < k || k < 0) return 0;
        ensure(n);
        long long r = n - k;
        std::vector<long long> rems(factors.size()), mods(factors.size());
        int id = 0;
        for (auto [p, q] : factors) {
            long long p_q = pow_ll(p, q);
            mods[id] = p_q;
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
                rem = bt.mul(rem, f[id][(n / p_i) % p_q]);
                rem = bt.mul(rem, inv_f[id][(k / p_i) % p_q]);
                rem = bt.mul(rem, inv_f[id][(r / p_i) % p_q]);
                if (p_i > n / p) break;
                p_i *= p;
            }
            rems[id] = rem;
            id++;
        }
        return atcoder::crt(rems, mods).first;
    }

private:
    static void ensure(long long n) {
        if (max_size > n) return;
        int id = 0;
        for (auto [p, q] : factors) {
            long long p_q = pow_ll(p, q);
            int sz = f[id].size();
            if ((long long)sz > std::min(p_q - 1, n) + 1) continue;
            f[id].resize(std::min(p_q - 1, n) + 1);
            inv_f[id].resize(std::min(p_q - 1, n) + 1);
            max_size = std::max(max_size, std::min(p_q - 1, n) + 1);
            atcoder::internal::barrett bt((unsigned int)(p_q));
            for (int i = sz; i <= std::min(p_q - 1, n); i++) {
                if (i == 0) {
                    f[id][i] = 1;
                } else {
                    if (i % p == 0) {
                        f[id][i] = f[id][i - 1];
                    } else {
                        f[id][i] = bt.mul(f[id][i - 1], i);
                    }
                }
                inv_f[id][i] = atcoder::inv_mod(f[id][i], p_q);
            }
            id++;
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