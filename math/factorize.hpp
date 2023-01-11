#pragma once
#include <random>

long long modmul(long long x, long long y, long long mod) {
    using i128 = __int128_t;
    return (long long)(i128(x) * i128(y) % i128(mod));
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
    std::random_device seed_gen;
    std::mt19937_64 rnd(seed_gen());
    auto f = [&](long long x) -> long long {
        long long ret = modmul(x, x, n) + 1;
        if (ret == n) return 0;
        return ret;
    };
    while (true) {
        long long x = std::uniform_int_distribution<long long>(0, 1000)(rnd);
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
bool miller_rabin(long long n) {
    if (n == 1) return 0;
    long long d = n - 1, s = 0;
    while (~d & 1) d >>= 1, s++;
    auto check = [&](long long a) -> bool {
        long long x = modpow(a, d, n);
        if (x == 1) return 1;
        long long y = n - 1;
        for (int i = 0; i < s; i++) {
            if (x == y) return true;
            x = modmul(x, x, n);
        }
        return false;
    };
    for (long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (a >= n) break;
        if (!check(a)) return false;
    }
    return true;
}
#include <map>
#include <queue>
std::map<long long, int> factorize(long long n) {
    std::map<long long, int> ret;
    while (~n & 1) n >>= 1, ret[2]++;
    std::queue<long long> q;
    q.push(n);
    while (!q.empty()) {
        long long p = q.front();
        q.pop();
        if (p == 1) continue;
        if (miller_rabin(p)) {
            ret[p]++;
            continue;
        }
        long long d = rho(p);
        q.push(d);
        q.push(p / d);
    }
    return ret;
}