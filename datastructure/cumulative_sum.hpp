#pragma once
#include <vector>
template <typename T>
struct cumulative_sum {
    int n;
    std::vector<T> cumsum;
    cumulative_sum() {
    }
    cumulative_sum(std::vector<T>& d) : n(d.size()), cumsum(n + 1) {
        for (int i = 0; i < n; i++) {
            cumsum[i + 1] = cumsum[i] + d[i];
        }
    }
    T sum(int l, int r) {
        // 0-indexed
        // [l, r)
        assert(0 <= l);
        assert(l <= r);
        assert(r <= n);
        return cumsum[r] - cumsum[l];
    }
};