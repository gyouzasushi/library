#pragma once
#include <cassert>
#include <vector>
template <typename mint>
struct combinatorics {
    static mint fact(int n) {
        ensure(n);
        return facts[n];
    }
    static mint fact_inv(int n) {
        ensure(n);
        return ifacts[n];
    }
    static mint inv(int n) {
        assert(1 <= n);
        ensure(n);
        return ifacts[n] * facts[n - 1];
    }
    static mint C(int n, int k) {
        if (n < 0 || n < k || k < 0) return 0;
        return fact(n) * fact_inv(n - k) * fact_inv(k);
    }
    static mint P(int n, int k) {
        if (n < 0 || n < k || k < 0) return 0;
        return fact(n) * fact_inv(n - k);
    }
    static mint H(int n, int k) {
        if (n < 0 || k < 0) return 0;
        if (k == 0) return 1;
        return C(n + k - 1, k);
    }
    static void ensure(int n) {
        assert(n < mint::mod());
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
