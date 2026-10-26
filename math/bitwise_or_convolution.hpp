#pragma once
#include "zeta_mobius_transform.hpp"
template <class T>
std::vector<T> bitwise_or_convolution(std::vector<T> a,
                                         std::vector<T> b) {
    subset_zeta(a);
    subset_zeta(b);
    for (int i = 0; i < int(a.size()); i++) {
        a[i] *= b[i];
    }
    subset_mobius(a);
    return a;
}
