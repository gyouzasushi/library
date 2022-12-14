#pragma once

#include <cassert>
#include <numeric>
#include <type_traits>
namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value, __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral =
    typename std::conditional<std::is_integral<T>::value ||
                                  is_signed_int128<T>::value ||
                                  is_unsigned_int128<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using is_signed_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_signed<T>::value) ||
                                  is_signed_int128<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value, make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value, std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T>
using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using to_unsigned =
    typename std::conditional<is_signed_int<T>::value, std::make_unsigned<T>,
                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T>
using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

#include <cassert>
#include <vector>

// Reference: https://en.wikipedia.org/wiki/Fenwick_tree
template <class T>
struct FenwickTree {
    using U = internal::to_unsigned_t<T>;

public:
    FenwickTree() : _n(0) {
    }
    FenwickTree(int n) : _n(n), data(n) {
    }

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    void set(int p, T x) {
        assert(0 <= p && p < _n);
        T d = x - sum(p, p + 1);
        add(p, d);
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

    int lower_bound(T x) {
        int i = 0;
        for (int k = 1 << (std::__lg(_n) + 1); k > 0; k >>= 1) {
            if (i + k - 1 < _n && data[i + k - 1] < U(x)) {
                x -= data[i + k - 1];
                i += k;
            }
        }
        return i;
    }

    int upper_bound(T x) {
        int i = 0;
        for (int k = 1 << (std::__lg(_n) + 1); k > 0; k >>= 1) {
            if (i + k - 1 < _n && data[i + k - 1] <= U(x)) {
                x -= data[i + k - 1];
                i += k;
            }
        }
        return i;
    }

private:
    int _n;
    std::vector<U> data;
    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};
