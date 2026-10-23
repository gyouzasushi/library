#pragma once
template <class T>
struct semiring_plus_times {
    using S = T;
    static S add(S a, S b) {
        return a + b;
    }
    static S zero() {
        return T(0);
    }
    static S mul(S a, S b) {
        return a * b;
    }
    static S one() {
        return T(1);
    }
};
