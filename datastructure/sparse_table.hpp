#pragma once
#include <algorithm>
#include <bit>
#include <cassert>
#include <vector>

#include "algebra/concept.hpp"
template <semigroup M> struct sparse_table {
    using S = typename M::S;
    sparse_table() : _n(0) {
    }
    explicit sparse_table(const std::vector<S>& a) : _n(int(a.size())) {
        int log = std::max(1, std::bit_width((unsigned)_n));
        t.resize(log);
        t[0] = a;
        for (int k = 1; k < log; k++) {
            t[k].resize(_n - (1 << k) + 1);
            for (int i = 0; i + (1 << k) <= _n; i++) {
                t[k][i] = M::op(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);
            }
        }
    }
    S prod(int l, int r) const {
        assert(0 <= l && l < r && r <= _n);
        int k = std::bit_width((unsigned)(r - l)) - 1;
        return M::op(t[k][l], t[k][r - (1 << k)]);
    }

private:
    int _n;
    std::vector<std::vector<S>> t;
};
