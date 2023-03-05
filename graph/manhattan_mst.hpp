#pragma once
#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <vector>

#include "atcoder/segtree.hpp"
template <typename T>
struct manhattan_mst_S {
    T val;
    int id;
};
template <typename T>
manhattan_mst_S<T> manhattan_mst_op(manhattan_mst_S<T> a,
                                    manhattan_mst_S<T> b) {
    return a.val < b.val ? a : b;
}
template <typename T>
manhattan_mst_S<T> manhattan_mst_e() {
    return {std::numeric_limits<T>::max(), -1};
}
template <typename T>
std::vector<std::tuple<int, int, T>> manhattan_mst(std::vector<T> x,
                                                   std::vector<T> y) {
    int n = x.size();
    assert(int(x.size()) == n && int(y.size()) == n);
    std::vector<int> id(n);
    std::iota(id.begin(), id.end(), 0);
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
                std::sort(_y.begin(), _y.end());
                for (int i = 0; i < n; i++) {
                    y_id[i] = std::lower_bound(_y.begin(), _y.end(), y[i]) -
                              _y.begin();
                }
                atcoder::segtree<manhattan_mst_S<T>, manhattan_mst_op<T>,
                                 manhattan_mst_e<T>>
                    segt(n);
                for (int i : id) {
                    manhattan_mst_S<T> p = segt.prod(y_id[i], n);
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