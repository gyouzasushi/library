#pragma once
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