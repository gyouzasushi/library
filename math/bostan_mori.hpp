#pragma once

#include <cassert>
#include <ranges>
#include <vector>

#include "atcoder/convolution"

template <typename mint>
mint bostan_mori(long long N, std::vector<mint> P, std::vector<mint> Q) {
    assert(N >= 0);

    auto odd = [](const std::vector<mint>& f) -> std::vector<mint> {
        return f | std::views::drop(1) | std::views::stride(2) |
               std::ranges::to<std::vector<mint>>();
    };

    auto even = [](const std::vector<mint>& f) -> std::vector<mint> {
        return f | std::views::stride(2) | std::ranges::to<std::vector<mint>>();
    };

    while (N > 0) {
        std::vector Q_alt = Q | std::views::enumerate |
                            std::views::transform([](auto p) {
                                auto [i, x] = p;
                                return (i & 1 ? -x : x);
                            }) |
                            std::ranges::to<std::vector<mint>>();
        std::vector U = atcoder::convolution(P, Q_alt);
        P = std::move(N & 1 ? odd(U) : even(U));
        std::vector V = atcoder::convolution(Q, Q_alt);
        Q = std::move(even(V));
        N >>= 1;
    }

    return P[0] / Q[0];
}