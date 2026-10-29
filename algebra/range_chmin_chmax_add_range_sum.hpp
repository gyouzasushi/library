#pragma once
#include <algorithm>
#include <limits>
template <class T>
struct range_chmin_chmax_add_range_sum {
    struct S {
        T sum, min, max, min2, max2;
        int minc, maxc, len;
        bool fail;
    };
    struct F {
        T add, chmin, chmax;
    };
    static S op(S a, S b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;
        S c;
        c.sum = a.sum + b.sum;
        c.len = a.len + b.len;
        c.fail = false;
        if (a.max > b.max) {
            c.max = a.max;
            c.maxc = a.maxc;
            c.max2 = std::max(a.max2, b.max);
        } else if (a.max < b.max) {
            c.max = b.max;
            c.maxc = b.maxc;
            c.max2 = std::max(a.max, b.max2);
        } else {
            c.max = a.max;
            c.maxc = a.maxc + b.maxc;
            c.max2 = std::max(a.max2, b.max2);
        }
        if (a.min < b.min) {
            c.min = a.min;
            c.minc = a.minc;
            c.min2 = std::min(a.min2, b.min);
        } else if (a.min > b.min) {
            c.min = b.min;
            c.minc = b.minc;
            c.min2 = std::min(a.min, b.min2);
        } else {
            c.min = a.min;
            c.minc = a.minc + b.minc;
            c.min2 = std::min(a.min2, b.min2);
        }
        return c;
    }
    static S e() {
        return {T(0), inf, ninf, inf, ninf, 0, 0, 0, false};
    }
    static S mapping(F f, S x) {
        if (x.len == 0) return x;
        if (f.add != T(0)) {
            x.sum += f.add * x.len;
            x.min += f.add;
            x.max += f.add;
            if (x.min2 != inf) x.min2 += f.add;
            if (x.max2 != ninf) x.max2 += f.add;
        }
        if (f.chmin < x.max) {
            if (f.chmin <= x.min) {
                fill(x, f.chmin);
            } else if (x.max2 < f.chmin) {
                x.sum += (f.chmin - x.max) * x.maxc;
                if (x.min2 == x.max) x.min2 = f.chmin;
                x.max = f.chmin;
            } else {
                x.fail = true;
                return x;
            }
        }
        if (f.chmax > x.min) {
            if (f.chmax >= x.max) {
                fill(x, f.chmax);
            } else if (f.chmax < x.min2) {
                x.sum += (f.chmax - x.min) * x.minc;
                if (x.max2 == x.min) x.max2 = f.chmax;
                x.min = f.chmax;
            } else {
                x.fail = true;
            }
        }
        return x;
    }
    static F composition(F f, F g) {
        T chmin = g.chmin == inf ? inf : g.chmin + f.add;
        T chmax = g.chmax == ninf ? ninf : g.chmax + f.add;
        return {f.add + g.add, std::min(chmin, f.chmin), std::max(std::min(chmax, f.chmin), f.chmax)};
    }
    static F id() {
        return {T(0), inf, ninf};
    }
    static constexpr bool composition_commutative = false;
    static S from(T v) {
        return {v, v, v, inf, ninf, 1, 1, 1, false};
    }
    static F chmin(T x) {
        return {T(0), x, ninf};
    }
    static F chmax(T x) {
        return {T(0), inf, x};
    }
    static F add(T x) {
        return {x, inf, ninf};
    }
    static F assign(T x) {
        return {T(0), x, x};
    }

private:
    static constexpr T inf = std::numeric_limits<T>::max();
    static constexpr T ninf = std::numeric_limits<T>::lowest();
    static void fill(S& x, T v) {
        x.sum = v * x.len;
        x.min = x.max = v;
        x.min2 = inf;
        x.max2 = ninf;
        x.minc = x.maxc = x.len;
    }
};
