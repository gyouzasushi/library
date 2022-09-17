#pragma once
#include "zeta_mobius_transform.hpp"
template <typename mint>
std::vector<mint> bitwise_and_convolution(std::vector<mint> a,
                                          std::vector<mint> b) {
    superset_zeta(a);
    superset_zeta(b);
    for (int i = 0; i < int(a.size()); i++) {
        a[i] *= b[i];
    }
    superset_mobius(a);
    return a;
}
