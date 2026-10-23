#pragma once
#include <limits>
template <class T>
struct monoid_argmin {
    struct S {
        T val;
        int id;
    };
    static S op(S a, S b) {
        if (a.val != b.val) return a.val < b.val ? a : b;
        return a.id < b.id ? a : b;
    }
    static S e() {
        return {std::numeric_limits<T>::max(), -1};
    }
};
