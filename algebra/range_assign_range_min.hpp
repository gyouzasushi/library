#pragma once
#include <limits>
#include <optional>
template <class T>
struct range_assign_range_min {
    using S = T;
    using F = std::optional<T>;
    static S op(S a, S b) {
        return a < b ? a : b;
    }
    static S e() {
        return std::numeric_limits<T>::max();
    }
    static S mapping(F f, S x) {
        return f ? *f : x;
    }
    static F composition(F f, F g) {
        return f ? f : g;
    }
    static F id() {
        return std::nullopt;
    }
    static constexpr bool composition_commutative = false;
};
