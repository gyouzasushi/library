#pragma once
#include <cassert>
#include <type_traits>
#include <vector>

#include "../math/modint.hpp"
int chromatic_number(std::vector<std::vector<bool>> g) {
    int n = g.size();
    std::vector<int> bit(n);
    for (int i = 0; i < n; i++) {
        assert(int(g[i].size()) == n);
        for (int j = 0; j < n; j++) {
            bit[i] |= g[i][j] << j;
        }
    }
    int ret = n;
    using mint = modint;
    for (int mod : {1e9 + 7, 1e9 + 11, 1e9 + 21}) {
        mint::set_mod(mod);
        std::vector<mint> dp(1 << n), prod(1 << n, 1);
        dp[0] = 1;
        for (int s = 1; s < 1 << n; s++) {
            int u = __builtin_ctz(s);
            dp[s] = dp[s ^ (1 << u)] + dp[(s ^ (1 << u)) & ~bit[u]];
        }
        for (int i = 1; i < ret; i++) {
            mint sum = 0;
            for (int j = 0; j < 1 << n; j++) {
                int s = j ^ (j >> 1);
                prod[s] *= dp[s];
                sum += j & 1 ? prod[s] : -prod[s];
            }
            if (sum.val() != 0) ret = i;
        }
    }
    return ret;
}