#pragma once
#include <cassert>
#include <vector>

template <class T> struct cumulative_sum {
    cumulative_sum() = default;
    explicit cumulative_sum(const std::vector<T>& a) : n(a.size()), s(n + 1) {
        for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];
    }
    T sum(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return s[r] - s[l];
    }

  private:
    int n = 0;
    std::vector<T> s;
};
