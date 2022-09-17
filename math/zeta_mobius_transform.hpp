#pragma once
#include <cassert>
#include <vector>
template <typename mint>
void superset_zeta(std::vector<mint>& f) {
    int n = f.size();
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                f[j] += f[j | i];
            }
        }
    }
}
template <typename mint>
void superset_mobius(std::vector<mint>& f) {
    int n = f.size();
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                f[j] -= f[j | i];
            }
        }
    }
}
template <typename mint>
void subset_zeta(std::vector<mint>& f) {
    int n = f.size();
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                f[j | i] += f[j];
            }
        }
    }
}
template <typename mint>
void subset_mobius(std::vector<mint>& f) {
    int n = f.size();
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                f[j | i] -= f[j];
            }
        }
    }
}