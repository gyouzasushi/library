#pragma once
#include <optional>

#include "string/string_hash.hpp"
template <int k = 1, class mint = modint2305843009213693951>
struct range_assign_range_hash {
    using S = string_hash<k, mint>;
    using F = std::optional<int>;
    static S op(S a, S b) {
        return a + b;
    }
    static S e() {
        return S();
    }
    static S mapping(F f, S x) {
        return f ? S::repeat(*f, x.len) : x;
    }
    static F composition(F f, F g) {
        return f ? f : g;
    }
    static F id() {
        return std::nullopt;
    }
    static constexpr bool composition_commutative = false;
    static S from(int c) {
        return S(c);
    }
};
