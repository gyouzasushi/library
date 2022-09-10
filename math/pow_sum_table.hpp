#pragma once
template <typename mint>
struct pow_mod_sums {
    pow_mod_sums() {
    }
    pow_mod_sums(mint base, int n) : base(base) {
        ensure(n);
    }
    // sum(pow[0..i])
    const mint& operator[](int i) const {
        ensure(i);
        return pow_sums[i];
    }
    void ensure(int n) const {
        int sz = pow_sums.size();
        if (sz > n) return;
        pow_sums.resize(n + 1);
        pows.resize(n + 1);
        for (int i = sz; i <= n; i++) {
            pows[i] = base * pows[i - 1];
            pow_sums[i] = pow_sums[i - 1] + pows[i - 1];
        }
    }

private:
    mutable std::vector<mint> pow_sums{0};
    mutable std::vector<mint> pows{1};
    mint base;
    static constexpr int mod = mint::mod;
};