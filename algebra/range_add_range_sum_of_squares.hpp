#pragma once
template <class T>
struct range_add_range_sum_of_squares {
    struct S {
        T sum, sum_of_squares;
        int len;
    };
    using F = T;
    static S op(S a, S b) {
        return {a.sum + b.sum, a.sum_of_squares + b.sum_of_squares, a.len + b.len};
    }
    static S e() {
        return {T(0), T(0), 0};
    }
    static S mapping(F f, S x) {
        return {x.sum + f * x.len, x.sum_of_squares + f * x.sum * 2 + f * f * x.len, x.len};
    }
    static F composition(F f, F g) {
        return f + g;
    }
    static F id() {
        return T(0);
    }
    static constexpr bool composition_commutative = true;
    static S from(T v) {
        return {v, v * v, 1};
    }
};
