#pragma once
#include <algorithm>
#include <cassert>
#include <map>
#include <numeric>
#include <vector>
template <typename T>
std::vector<std::tuple<int, int, T>> manhattan_mst(std::vector<T> x,
                                                   std::vector<T> y) {
    int n = x.size();
    assert(int(x.size()) == n && int(y.size()) == n);
    std::vector<int> id(n);
    std::iota(id.begin(), id.end(), 0);

    std::vector<std::tuple<int, int, T>> ret;
    for (int gyouza = 0; gyouza < 2; gyouza++) {
        for (int sushi = 0; sushi < 2; sushi++) {
            std::sort(id.begin(), id.end(), [&](int i, int j) {
                if (y[i] == y[j]) {
                    return x[i] < x[j];
                }
                return y[i] < y[j];
            });
            std::map<T, int> mp;
            for (int i : id) {
                if (auto it = mp.upper_bound(x[i]); it != mp.begin()) {
                    int j = prev(it)->second;
                    ret.emplace_back(i, j, abs(x[i] - x[j]) + abs(y[i] - y[j]));
                }
                for (auto it = mp.lower_bound(x[i]); it != mp.end();
                     it = mp.erase(it)) {
                    int j = it->second;
                    if (x[i] + y[i] <= x[j] + y[j]) break;
                }
                mp[x[i]] = i;
            }
            for (T &x : x) x = -x;
        }
        for (T &y : y) y = -y;
    }
    sort(ret.begin(), ret.end(),
         [](auto a, auto b) { return std::get<2>(a) < std::get<2>(b); });
    return ret;
}