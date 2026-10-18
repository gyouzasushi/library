#pragma once
#include <numeric>
template <class T>
struct monoid_gcd {
    using S = T;
    static S op(S a, S b) {
        return std::gcd(a, b);
    }
    static S e() {
        return T(0);
    }
    static constexpr bool commutative = true;
};
