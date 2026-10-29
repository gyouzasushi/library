#pragma once
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <vector>

namespace internal {

long long modmul(long long x, long long y, long long mod) {
    return (long long)((__int128_t)x * y % mod);
}

long long modpow(long long a, long long n, long long mod) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = modmul(ret, a, mod);
        a = modmul(a, a, mod);
        n >>= 1;
    }
    return ret;
}

long long rho(long long n) {
    long long z = 0;
    auto f = [&](long long x) {
        long long ret = modmul(x, x, n) + z;
        return ret >= n ? ret - n : ret;
    };
    while (true) {
        long long x = ++z;
        long long y = f(x);
        while (true) {
            long long d = std::gcd(std::abs(x - y), n);
            if (d == n) break;
            if (d > 1) return d;
            x = f(x);
            y = f(f(y));
        }
    }
}

}  // namespace internal

bool is_prime(long long n) {
    assert(n >= 1);
    if (n == 1) return false;
    if (n % 2 == 0) return n == 2;
    long long d = n - 1, s = 0;
    while (~d & 1) d >>= 1, s++;
    for (long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (a >= n) break;
        long long x = internal::modpow(a, d, n);
        if (x == 1) continue;
        bool ok = false;
        for (int i = 0; i < s; i++) {
            if (x == n - 1) {
                ok = true;
                break;
            }
            x = internal::modmul(x, x, n);
        }
        if (!ok) return false;
    }
    return true;
}

std::vector<std::pair<long long, int>> factorize(long long n) {
    assert(n >= 1);
    std::vector<std::pair<long long, int>> ret;
    int c = 0;
    while (~n & 1) n >>= 1, c++;
    if (c > 0) ret.emplace_back(2, c);
    std::vector<long long> st = {n};
    std::vector<long long> primes;
    while (!st.empty()) {
        long long p = st.back();
        st.pop_back();
        if (p == 1) continue;
        if (is_prime(p)) {
            primes.push_back(p);
            continue;
        }
        long long d = internal::rho(p);
        st.push_back(d);
        st.push_back(p / d);
    }
    std::ranges::sort(primes);
    for (long long p : primes) {
        if (!ret.empty() && ret.back().first == p) {
            ret.back().second++;
        } else {
            ret.emplace_back(p, 1);
        }
    }
    return ret;
}

