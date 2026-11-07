#pragma once
#include "algebra/monoid_affine.hpp"
template <class T>
struct range_affine_range_sum {
    struct S {
        T sum;
        int len;
    };
    using F = typename monoid_affine<T>::S;
    static S op(S a, S b) {
        return {a.sum + b.sum, a.len + b.len};
    }
    static S e() {
        return {T(0), 0};
    }
    static S mapping(F f, S x) {
        return {f.a * x.sum + f.b * T(x.len), x.len};
    }
    static F composition(F f, F g) {
        return monoid_affine<T>::op(g, f);
    }
    static F id() {
        return monoid_affine<T>::e();
    }
    static constexpr bool composition_commutative = false;
    static S from(T v) {
        return {v, 1};
    }
};
