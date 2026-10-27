#pragma once
#include <limits>
template <class T>
struct range_add_range_max {
    using S = T;
    using F = T;
    static S op(S a, S b) {
        return a < b ? b : a;
    }
    static S e() {
        return std::numeric_limits<T>::lowest();
    }
    static S mapping(F f, S x) {
        return x == e() ? x : x + f;
    }
    static F composition(F f, F g) {
        return f + g;
    }
    static F id() {
        return T(0);
    }
    static constexpr bool composition_commutative = true;
};
