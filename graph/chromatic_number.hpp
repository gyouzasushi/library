#pragma once
#include <cassert>
#include <vector>

#include "atcoder/modint.hpp"

int chromatic_number(const std::vector<std::vector<int>>& g) {
    int n = g.size();
    assert(n <= 30);
    std::vector<int> adj(n);
    for (int u = 0; u < n; u++) {
        for (int v : g[u]) adj[u] |= 1 << v;
    }
    if (n == 0) return 0;
    using mint = atcoder::dynamic_modint<20261026>;
    int ret = n;
    for (int mod : {1000000007, 1000000009, 1000000021}) {
        mint::set_mod(mod);
        std::vector<mint> ind(1 << n), prod(1 << n, 1);
        ind[0] = 1;
        for (int s = 1; s < 1 << n; s++) {
            int u = __builtin_ctz(s);
            ind[s] = ind[s ^ (1 << u)] + ind[(s ^ (1 << u)) & ~adj[u]];
        }
        for (int k = 1; k < ret; k++) {
            mint sum = 0;
            for (int s = 0; s < 1 << n; s++) {
                prod[s] *= ind[s];
                sum += (n - __builtin_popcount(s)) & 1 ? -prod[s] : prod[s];
            }
            if (sum != 0) ret = k;
        }
    }
    return ret;
}
