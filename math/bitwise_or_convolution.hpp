#pragma once
#include "zeta_mobius_transform.hpp"
template <typename mint>
std::vector<mint> bitwise_or_convolution(std::vector<mint> a,
                                         std::vector<mint> b) {
    subset_zeta(a);
    subset_zeta(b);
    for (int i = 0; i < int(a.size()); i++) {
        a[i] *= b[i];
    }
    subset_mobius(a);
    return a;
}
