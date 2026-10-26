#pragma once
#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

#include "atcoder/convolution.hpp"

namespace internal {
// a, b: 0 = wildcard, 1..k = symbols
std::vector<bool> wildcard_matching(const std::vector<long long>& a,
                                    std::vector<long long> b, int k) {
    int n = a.size(), m = b.size();
    if (m > n) return {};
    if (m == 0) return std::vector<bool>(n + 1, true);
    assert((long double)m * k * k * k * k < 9e18L);
    std::reverse(b.begin(), b.end());
    auto pw = [](const std::vector<long long>& v, int e) {
        std::vector<long long> r(v.size());
        for (size_t i = 0; i < v.size(); i++) {
            r[i] = v[i];
            for (int j = 1; j < e; j++) r[i] *= v[i];
        }
        return r;
    };
    auto c1 = atcoder::convolution_ll(pw(a, 3), pw(b, 1));
    auto c2 = atcoder::convolution_ll(pw(a, 2), pw(b, 2));
    auto c3 = atcoder::convolution_ll(pw(a, 1), pw(b, 3));
    std::vector<bool> res(n - m + 1);
    for (int i = 0; i < n - m + 1; i++) {
        res[i] = c1[i + m - 1] - 2 * c2[i + m - 1] + c3[i + m - 1] == 0;
    }
    return res;
}
}  // namespace internal

template <class T>
std::vector<bool> wildcard_matching(const std::vector<T>& s,
                                    const std::vector<T>& t, T wildcard) {
    std::vector<T> v;
    for (const T& x : s) v.push_back(x);
    for (const T& x : t) v.push_back(x);
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    auto id = [&](const T& x) -> long long {
        if (x == wildcard) return 0;
        return std::lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
    };
    std::vector<long long> a(s.size()), b(t.size());
    for (size_t i = 0; i < s.size(); i++) a[i] = id(s[i]);
    for (size_t i = 0; i < t.size(); i++) b[i] = id(t[i]);
    return internal::wildcard_matching(a, b, v.size());
}

std::vector<bool> wildcard_matching(const std::string& s, const std::string& t,
                                    char wildcard = '?') {
    return wildcard_matching(std::vector<char>(s.begin(), s.end()),
                             std::vector<char>(t.begin(), t.end()), wildcard);
}
