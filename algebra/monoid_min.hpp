#pragma once
#include <algorithm>
#include <limits>
template <class T>
struct monoid_min {
    using S = T;
    static S op(S a, S b) {
        return std::min(a, b);
    }
    static S e() {
        return std::numeric_limits<T>::max();
    }
};
