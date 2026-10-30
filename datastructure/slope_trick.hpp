#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <optional>
#include <utility>
#include <vector>

template <class T> struct slope_trick {
    slope_trick() : min_f(0), add_l(0), add_r(0) {}
    T min() const { return min_f; }
    std::pair<std::optional<T>, std::optional<T>> argmin() const {
        std::optional<T> l, r;
        if (!L.empty()) l = L.front() + add_l;
        if (!R.empty()) r = R.front() + add_r;
        return {l, r};
    }
    void add(T a) { min_f += a; }
    void add_x_minus_a(T a) {
        if (!L.empty()) min_f += std::max<T>(0, L.front() + add_l - a);
        push_l(a);
        push_r(pop_l());
    }
    void add_a_minus_x(T a) {
        if (!R.empty()) min_f += std::max<T>(0, a - (R.front() + add_r));
        push_r(a);
        push_l(pop_r());
    }
    void add_abs(T a) {
        add_x_minus_a(a);
        add_a_minus_x(a);
    }
    void prefix_min() {
        R.clear();
        add_r = 0;
    }
    void suffix_min() {
        L.clear();
        add_l = 0;
    }
    void shift(T a) { shift(a, a); }
    void shift(T a, T b) {
        assert(a <= b);
        add_l += a;
        add_r += b;
    }
    void merge(slope_trick& g) {
        if (L.size() + R.size() < g.L.size() + g.R.size()) std::swap(*this, g);
        min_f += g.min_f;
        for (T l : g.L) add_a_minus_x(l + g.add_l);
        for (T r : g.R) add_x_minus_a(r + g.add_r);
        g = slope_trick();
    }
    T operator()(T x) const {
        T res = min_f;
        for (T l : L) res += std::max<T>(0, l + add_l - x);
        for (T r : R) res += std::max<T>(0, x - (r + add_r));
        return res;
    }

  private:
    T min_f, add_l, add_r;
    std::vector<T> L, R;
    void push_l(T a) {
        L.push_back(a - add_l);
        std::push_heap(L.begin(), L.end());
    }
    void push_r(T a) {
        R.push_back(a - add_r);
        std::push_heap(R.begin(), R.end(), std::greater<T>());
    }
    T pop_l() {
        std::pop_heap(L.begin(), L.end());
        T a = L.back() + add_l;
        L.pop_back();
        return a;
    }
    T pop_r() {
        std::pop_heap(R.begin(), R.end(), std::greater<T>());
        T a = R.back() + add_r;
        R.pop_back();
        return a;
    }
};
