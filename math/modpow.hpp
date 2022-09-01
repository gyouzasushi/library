#pragma once
#include <cmath>
#include <unordered_map>
long long ext_gxd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long q = a / b;
    long long g = ext_gxd(b, a - q * b, x, y);
    long long z = x - q * y;
    x = y;
    y = z;
    return g;
}

long long modinv(long long a, long long m) {
    long long x, y;
    ext_gxd(a, m, x, y);
    x %= m;
    if (x < 0) x += m;
    return x;
}

long long modpow(long long a, long long n, long long m) {
    long long ret = 1;
    long long now = a;
    while (n > 0) {
        if (n & 1) ret = ret * now % m;
        now = now * now % m;
        n /= 2;
    }
    return ret;
}

// todo!! returns the minimum k s.t. x^k == y (mod m)
long long modlog(long long x, long long y, long long m) {
    auto modlog_coprime = [](long long x, long long y,
                             long long m) -> long long {
        if (x == 0) {
            if (y == 1) return 0;
            if (y == 0) return 1;
            return -1;
        }
        const long long p = (long long)std::sqrt(x) + 2;
        std::unordered_map<long long, long long> mp;
        for (long long i = 0, e = 1; i < p; i++) {
            mp[e] = i;
            (e *= x) %= m;
        }
    };
}