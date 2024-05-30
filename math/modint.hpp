#pragma once
#include <atcoder/modint.hpp>
#include <iostream>
namespace atcoder {
template <typename T, typename std::enable_if_t<internal::is_modint<T>::value,
                                                std::nullptr_t> = nullptr>
std::istream& operator>>(std::istream& is, T& v) {
    long long x;
    is >> x;
    v = x;
    return is;
}
template <typename T, typename std::enable_if_t<internal::is_modint<T>::value,
                                                std::nullptr_t> = nullptr>
std::ostream& operator<<(std::ostream& os, const T& v) {
    os << v.val();
    return os;
}
}  // namespace atcoder