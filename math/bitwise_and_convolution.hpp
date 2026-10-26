#pragma once
#include "zeta_mobius_transform.hpp"
template <class T>
std::vector<T> bitwise_and_convolution(std::vector<T> a,
                                          std::vector<T> b) {
    superset_zeta(a);
    superset_zeta(b);
    for (int i = 0; i < int(a.size()); i++) {
        a[i] *= b[i];
    }
    superset_mobius(a);
    return a;
}
