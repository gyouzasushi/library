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
        if (n < sz << 1) n = sz << 1;
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

template <typename mint>
struct binomial_coefficient_arbitrary_mod {};