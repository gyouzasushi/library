#pragma once
#include <limits>
template <class T>
struct monoid_argmax {
    struct S {
        T val;
        int id;
    };
    static S op(S a, S b) {
        if (a.val != b.val) return a.val > b.val ? a : b;
        return a.id < b.id ? a : b;
    }
    static S e() {
        return {std::numeric_limits<T>::lowest(), -1};
    }
    static constexpr bool commutative = true;
};
