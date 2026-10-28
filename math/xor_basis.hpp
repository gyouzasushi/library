#pragma once
#include <algorithm>
#include <bit>
#include <cassert>
#include <concepts>
#include <functional>
#include <limits>
#include <type_traits>
#include <vector>
template <std::integral T = long long> struct xor_basis {
    xor_basis() = default;
    int size() const {
        return int(b.size());
    }
    bool insert(T x) {
        x = reduce(x);
        if (x == 0) return false;
        T p = T(1) << (std::bit_width(std::make_unsigned_t<T>(x)) - 1);
        for (T& v : b) {
            if (v & p) v ^= x;
        }
        b.insert(std::ranges::lower_bound(b, x, std::greater<T>()), x);
        return true;
    }
    bool contains(T x) const {
        return reduce(x) == 0;
    }
    T max(T xor_val = 0) const {
        check(xor_val);
        for (T v : b) xor_val = std::max(xor_val, T(xor_val ^ v));
        return xor_val;
    }
    T min(T xor_val = 0) const {
        return reduce(xor_val);
    }
    T kth_smallest(T k, T xor_val = 0) const {
        int r = size();
        assert(0 <= k && (r >= std::numeric_limits<T>::digits || k < (T(1) << r)));
        T x = reduce(xor_val);
        for (int i = 0; i < r; i++) {
            if ((k >> (r - 1 - i)) & 1) x ^= b[i];
        }
        return x;
    }
    T kth_largest(T k, T xor_val = 0) const {
        int r = size();
        T all = r == 0 ? 0 : ((T(1) << (r - 1)) - 1) * 2 + 1;
        assert(0 <= k && k <= all);
        return kth_smallest(all - k, xor_val);
    }

  private:
    std::vector<T> b;
    static void check([[maybe_unused]] T x) {
        if constexpr (std::is_signed_v<T>) assert(x >= 0);
    }
    T reduce(T x) const {
        check(x);
        for (T v : b) x = std::min(x, T(x ^ v));
        return x;
    }
};
