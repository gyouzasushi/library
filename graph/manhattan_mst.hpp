#pragma once
#include <algorithm>
#include <cassert>
#include <numeric>
#include <tuple>
#include <vector>

#include "datastructure/segtree.hpp"
#include "algebra/monoid_argmin.hpp"
template <typename T>
std::vector<std::tuple<int, int, T>> manhattan_mst(std::vector<T> x,
                                                   std::vector<T> y) {
    int n = x.size();
    assert(int(y.size()) == n);
    std::vector<int> id(n);
    std::ranges::iota(id, 0);
    std::vector<int> y_id(n);
    std::vector<std::tuple<int, int, T>> ret;
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            for (int c = 0; c < 2; c++) {
                sort(id.begin(), id.end(), [&](int i, int j) {
                    if (y[i] - x[i] == y[j] - x[j] && y[i] == y[j])
                        return i < j;
                    if (y[i] - x[i] == y[j] - x[j]) return y[i] > y[j];
                    return y[i] - x[i] < y[j] - x[j];
                });
                std::vector<T> _y = y;
                std::ranges::sort(_y);
                for (int i = 0; i < n; i++) {
                    y_id[i] = std::ranges::lower_bound(_y, y[i]) - _y.begin();
                }
                segtree<monoid_argmin<T>> segt(n);
                for (int i : id) {
                    auto p = segt.prod(y_id[i], n);
                    if (p.id != -1) {
                        ret.emplace_back(i, p.id, p.val - (x[i] + y[i]));
                    }
                    segt.set(y_id[i], {x[i] + y[i], i});
                }
                std::swap(x, y);
            }
            for (T &x : x) x = -x;
        }
        for (T &y : y) y = -y;
    }
    sort(ret.begin(), ret.end(),
         [](auto a, auto b) { return std::get<2>(a) < std::get<2>(b); });
    return ret;
}