#pragma once
#include <vector>
template <typename T, class Compare>
std::vector<T> longest_increasing_subsequence(const std::vector<T> &v,
                                              Compare comp) {
    const int n = v.size();
    std::vector<T> dp;
    std::vector<int> id(n);
    for (int i = 0; i < n; i++) {
        typename std::vector<T>::iterator it =
            std::lower_bound(dp.begin(), dp.end(), v[i], comp);
        id[i] = std::distance(dp.begin(), it);
        if (it == dp.end()) {
            dp.push_back(v[i]);
        } else {
            *it = v[i];
        }
    }
    std::vector<T> lis(dp.size());
    for (int i = n - 1, j = lis.size() - 1; i >= 0; i--) {
        if (id[i] == j) {
            lis[j--] = i;
        }
    }
    return lis;
}
template <typename T>
std::vector<T> longest_increasing_subsequence(const std::vector<T> &v) {
    return longest_increasing_subsequence(v, std::less<T>());
}