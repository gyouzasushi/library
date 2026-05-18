#pragma once
#include <vector>
template <typename mint>
struct combinatorics {
    static mint val(int i) {
        ensure(i);
        return facts[i];
    }
    static mint inv(int i) {
        ensure(i);
        return ifacts[i];
    }
    static mint C(int n, int k) {
        if (n < 0 || n < k || k < 0) return 0;
        return val(n) * inv(n - k) * inv(k);
    }
    static mint P(int n, int k) {
        if (n < 0 || n < k || k < 0) return 0;
        return val(n) * inv(n - k);
    }
    static mint H(int n, int k) {
        if (n < 0 || k < 0) return 0;
        if (k == 0) return 1;
        return C(n + k - 1, k);
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
