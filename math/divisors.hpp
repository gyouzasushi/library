#pragma once
#include <algorithm>
#include <utility>
#include <vector>
template <class T>
std::vector<T> divisors(const std::vector<std::pair<T, int>>& factors) {
    std::vector<T> ret = {1};
    for (auto [p, e] : factors) {
        int sz = int(ret.size());
        T q = 1;
        for (int i = 0; i < e; i++) {
            q *= p;
            for (int j = 0; j < sz; j++) ret.push_back(ret[j] * q);
        }
    }
    std::ranges::sort(ret);
    return ret;
}
