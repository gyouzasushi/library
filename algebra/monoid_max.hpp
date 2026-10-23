#pragma once
#include <algorithm>
#include <limits>
template <class T>
struct monoid_max {
    using S = T;
    static S op(S a, S b) {
        return std::max(a, b);
    }
    static S e() {
        return std::numeric_limits<T>::lowest();
    }
};
