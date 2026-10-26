#pragma once
#include <cassert>
#include <vector>
template <class T>
void superset_zeta(std::vector<T>& f) {
    int n = int(f.size());
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                f[j] += f[j | i];
            }
        }
    }
}
template <class T>
void superset_mobius(std::vector<T>& f) {
    int n = int(f.size());
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                f[j] -= f[j | i];
            }
        }
    }
}
template <class T>
void subset_zeta(std::vector<T>& f) {
    int n = int(f.size());
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                f[j | i] += f[j];
            }
        }
    }
}
template <class T>
void subset_mobius(std::vector<T>& f) {
    int n = int(f.size());
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                f[j | i] -= f[j];
            }
        }
    }
}