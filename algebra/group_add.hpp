#pragma once
#include "algebra/monoid_add.hpp"
template <class T>
struct group_add : monoid_add<T> {
    static T inv(T a) {
        return -a;
    }
};
