#pragma once
template <class T>
struct monoid_add {
    using S = T;
    static S op(S a, S b) {
        return a + b;
    }
    static S e() {
        return T(0);
    }
    static constexpr bool commutative = true;
};
