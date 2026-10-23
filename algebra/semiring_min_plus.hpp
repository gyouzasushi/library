#pragma once
#include <algorithm>
#include <limits>
template <class T>
struct semiring_min_plus {
    using S = T;
    static S add(S a, S b) {
        return std::min(a, b);
    }
    static S zero() {
        return std::numeric_limits<T>::max();
    }
    static S mul(S a, S b) {
        if (a == zero() || b == zero()) return zero();
        return a + b;
    }
    static S one() {
        return T(0);
    }
};
