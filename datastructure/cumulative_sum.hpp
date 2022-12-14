#pragma once
#include<vector>
template <typename T>
struct CumulativeSum {
    int n;
    std::vector<T> cumsum;
    CumulativeSum() {
    }
    CumulativeSum(std::vector<T>& d) : n(d.size()), cumsum(n + 1) {
        for (int i = 0; i < n; i++) {
            cumsum[i + 1] = cumsum[i] + d[i];
        }
    }
    T sum(int l, int r) {
        // 0-indexed
        // [l, r)
        return cumsum[r] - cumsum[l];
    }
};