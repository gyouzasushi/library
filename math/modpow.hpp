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