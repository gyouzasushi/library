#pragma once
#include <cassert>
#include <cstdlib>
#include <map>
#include <numeric>
#include <queue>

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

std::map<long long, int> factorize(long long n) {
    assert(n >= 1);
    std::map<long long, int> ret;
    while (~n & 1) n >>= 1, ret[2]++;
    std::queue<long long> q;
    q.push(n);
    while (!q.empty()) {
        long long p = q.front();
        q.pop();
        if (p == 1) continue;
        if (is_prime(p)) {
            ret[p]++;
            continue;
        }
        long long d = internal::rho(p);
        q.push(d);
        q.push(p / d);
    }
    return ret;
}
