#pragma once
#include <cassert>
#include <ranges>
#include <vector>

#include "atcoder/convolution"

template <class mint>
mint bostan_mori(long long n, std::vector<mint> p, std::vector<mint> q) {
    assert(n >= 0);
    assert(!q.empty() && q[0] != 0);
    auto even = [](const std::vector<mint>& f) {
        return f | std::views::stride(2) | std::ranges::to<std::vector<mint>>();
    };
    auto odd = [](const std::vector<mint>& f) {
        return f | std::views::drop(1) | std::views::stride(2) |
               std::ranges::to<std::vector<mint>>();
    };
    while (n > 0) {
        std::vector<mint> q_neg = q;
        for (int i = 1; i < int(q_neg.size()); i += 2) q_neg[i] = -q_neg[i];
        std::vector<mint> u = atcoder::convolution(p, q_neg);
        p = n & 1 ? odd(u) : even(u);
        q = even(atcoder::convolution(q, q_neg));
        n >>= 1;
    }
    return p.empty() ? mint(0) : p[0] / q[0];
}
