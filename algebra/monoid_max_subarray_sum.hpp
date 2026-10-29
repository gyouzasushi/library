#pragma once
#include <algorithm>
#include <limits>
template <class T>
struct monoid_max_subarray_sum {
    struct S {
        T sum, max_prefix, max_suffix, max_subarray;
    };
    static S op(S a, S b) {
        if (a.max_subarray == ninf) return b;
        if (b.max_subarray == ninf) return a;
        return {a.sum + b.sum, std::max(a.max_prefix, a.sum + b.max_prefix), std::max(b.max_suffix, a.max_suffix + b.sum),
                std::max({a.max_subarray, b.max_subarray, a.max_suffix + b.max_prefix})};
    }
    static S e() {
        return {T(0), ninf, ninf, ninf};
    }
    static S from(T v) {
        return {v, v, v, v};
    }

private:
    static constexpr T ninf = std::numeric_limits<T>::lowest();
};
