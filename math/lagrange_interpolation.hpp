#pragma once
#include <cassert>
#include <vector>

#include "math/combinatorics.hpp"
template <class mint> mint lagrange_interpolation(const std::vector<mint>& y, mint c) {
    int n = int(y.size());
    assert(n >= 1);
    long long cv = c.val();
    if (cv < n) return y[cv];
    std::vector<mint> pre(n + 1, 1), suf(n + 1, 1);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] * (c - i);
    for (int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] * (c - i);
    using comb = combinatorics<mint>;
    mint ret = 0;
    for (int i = 0; i < n; i++) {
        mint t = y[i] * pre[i] * suf[i + 1] * comb::fact_inv(i) * comb::fact_inv(n - 1 - i);
        ret += (n - 1 - i) & 1 ? -t : t;
    }
    return ret;
}
template <class mint>
mint lagrange_interpolation(const std::vector<mint>& x, const std::vector<mint>& y, mint c) {
    int n = int(x.size());
    assert(n >= 1 && int(y.size()) == n);
    mint ret = 0;
    for (int i = 0; i < n; i++) {
        mint num = 1, den = 1;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            assert(x[i] != x[j]);
            num *= c - x[j];
            den *= x[i] - x[j];
        }
        ret += y[i] * num / den;
    }
    return ret;
}
