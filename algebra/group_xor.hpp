#pragma once
#include "algebra/monoid_xor.hpp"
template <class T>
struct group_xor : monoid_xor<T> {
    static T inv(T a) {
        return a;
    }
};
