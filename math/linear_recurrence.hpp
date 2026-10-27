#pragma once
#include <cassert>
#include <vector>

#include "atcoder/convolution"
#include "math/bostan_mori.hpp"
template <class mint> std::vector<mint> berlekamp_massey(const std::vector<mint>& a) {
    int n = int(a.size()), l = 0, m = 0;
    std::vector<mint> c(n + 1), b(n + 1), t;
    c[0] = b[0] = 1;
    mint bd = 1;
    for (int i = 0; i < n; i++) {
        m++;
        mint d = a[i];
        for (int j = 1; j <= l; j++) d += c[j] * a[i - j];
        if (d == 0) continue;
        t = c;
        mint coef = d / bd;
        for (int j = m; j <= n; j++) c[j] -= coef * b[j - m];
        if (2 * l > i) continue;
        l = i + 1 - l;
        b = t;
        bd = d;
        m = 0;
    }
    c.resize(l + 1);
    c.erase(c.begin());
    for (auto& x : c) x = -x;
    return c;
}
template <class mint>
mint kth_term_of_linear_recurrence(const std::vector<mint>& a, const std::vector<mint>& c, long long k) {
    int d = int(c.size());
    assert(d <= int(a.size()));
    assert(k >= 0);
    if (k < int(a.size())) return a[k];
    std::vector<mint> q(d + 1), p(a.begin(), a.begin() + d);
    q[0] = 1;
    for (int i = 0; i < d; i++) q[i + 1] = -c[i];
    p = atcoder::convolution(p, q);
    p.resize(d);
    return bostan_mori(k, p, q);
}
