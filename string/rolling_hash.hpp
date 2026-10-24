#pragma once
#include <array>
#include <cassert>
#include <vector>

#include "string/string_hash.hpp"
template <int k = 1, class mint = modint2305843009213693951>
struct rolling_hash {
    using H = string_hash<k, mint>;
    rolling_hash() : n(0) {}
    template <class Iterable>
    explicit rolling_hash(const Iterable& s) {
        std::vector<int> a;
        for (auto&& c : s) a.push_back(int(c));
        n = int(a.size());
        for (int i = 0; i < k; i++) {
            h[i].assign(n + 1, mint(0));
            for (int j = 0; j < n; j++) h[i][j + 1] = h[i][j] * H::base(i) + mint(a[j]);
        }
    }
    int size() const {
        return n;
    }
    H prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        H res;
        res.len = r - l;
        for (int i = 0; i < k; i++) res.val[i] = h[i][r] - h[i][l] * H::pow(i, r - l);
        return res;
    }
    H get(int p) const {
        return prod(p, p + 1);
    }
    H all_prod() const {
        return prod(0, n);
    }

private:
    int n;
    std::array<std::vector<mint>, k> h;
};
