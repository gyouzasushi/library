#pragma once
#include <algorithm>
#include <cassert>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

#include "datastructure/wavelet_matrix.hpp"
template <class T, class S = void> struct rectangle_sum {
private:
    static constexpr bool weighted = !std::is_void_v<S>;

public:
    rectangle_sum() {
    }
    explicit rectangle_sum(std::vector<std::pair<T, T>> points)
        requires (!weighted)
    {
        std::sort(points.begin(), points.end());
        int n = int(points.size());
        std::vector<T> ys(n);
        xs.resize(n);
        for (int i = 0; i < n; i++) std::tie(xs[i], ys[i]) = points[i];
        wm = wavelet_matrix<T, S>(ys);
    }
    explicit rectangle_sum(std::vector<std::tuple<T, T, S>> points)
        requires weighted
    {
        std::sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return std::get<0>(a) < std::get<0>(b);
        });
        int n = int(points.size());
        std::vector<T> ys(n);
        std::vector<S> ws(n);
        xs.resize(n);
        for (int i = 0; i < n; i++) std::tie(xs[i], ys[i], ws[i]) = points[i];
        wm = wavelet_matrix<T, S>(ys, ws);
    }
    int size() const {
        return int(xs.size());
    }
    int count(T x1, T x2, T y1, T y2) const {
        auto [l, r] = range(x1, x2);
        if (l >= r) return 0;
        return wm.count(l, r, y1, y2);
    }
    S sum(T x1, T x2, T y1, T y2) const
        requires weighted
    {
        auto [l, r] = range(x1, x2);
        if (l >= r) return S();
        return wm.sum(l, r, y1, y2);
    }

private:
    std::vector<T> xs;
    wavelet_matrix<T, S> wm;
    std::pair<int, int> range(T x1, T x2) const {
        int l = int(std::lower_bound(xs.begin(), xs.end(), x1) - xs.begin());
        int r = int(std::lower_bound(xs.begin(), xs.end(), x2) - xs.begin());
        return {l, r};
    }
};
