#pragma once
#include <optional>
template <class T>
struct range_assign_range_sum {
    struct S {
        T sum;
        int len;
    };
    using F = std::optional<T>;
    static S op(S a, S b) {
        return {a.sum + b.sum, a.len + b.len};
    }
    static S e() {
        return {T(0), 0};
    }
    static S mapping(F f, S x) {
        return f ? S{*f * x.len, x.len} : x;
    }
    static F composition(F f, F g) {
        return f ? f : g;
    }
    static F id() {
        return std::nullopt;
    }
    static constexpr bool composition_commutative = false;
    static S from(T v) {
        return {v, 1};
    }
};
