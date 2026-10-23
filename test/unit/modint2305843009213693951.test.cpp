#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>
#include <random>

#include "math/modint2305843009213693951.hpp"
using mint = modint2305843009213693951;
using i128 = __int128;
constexpr uint64_t P = (uint64_t(1) << 61) - 1;
uint64_t norm(i128 x) {
    x %= i128(P);
    if (x < 0) x += P;
    return uint64_t(x);
}
int main() {
    static_assert(mint::mod() == P);
    std::mt19937_64 rng(7959);
    auto gen = [&]() -> uint64_t {
        switch (rng() % 6) {
            case 0: return 0;
            case 1: return P - 1;
            case 2: return 1;
            case 3: return rng() % 1000;
            default: return rng() % P;
        }
    };
    for (int t = 0; t < 100000; t++) {
        uint64_t a = gen(), b = gen();
        mint x = a, y = b;
        assert(x.val() == a && y.val() == b);
        assert((x + y).val() == norm(i128(a) + b));
        assert((x - y).val() == norm(i128(a) - b));
        assert((x * y).val() == norm(i128(a) * b));
        assert((-x).val() == norm(-i128(a)));
        if (b != 0) {
            mint q = x / y;
            assert(q * y == x);
            assert((y.inv() * y).val() == 1);
        }
        assert((x == y) == (a == b));
        assert((x != y) == (a != b));
    }
    for (int t = 0; t < 2000; t++) {
        uint64_t a = gen();
        long long n = rng() % 50;
        mint x = a, p = 1;
        for (int i = 0; i < n; i++) p *= x;
        assert(x.pow(n) == p);
    }
    assert(mint(P).val() == 0);
    assert(mint(P) == mint(0));
    assert(mint(P + 1).val() == 1);
    assert(mint(std::numeric_limits<uint64_t>::max()).val() == norm(i128(std::numeric_limits<uint64_t>::max())));
    assert(mint(-1).val() == P - 1);
    assert(mint(-1LL).val() == P - 1);
    assert(mint(std::numeric_limits<long long>::min()).val() == norm(i128(std::numeric_limits<long long>::min())));
    assert(mint(std::numeric_limits<long long>::max()).val() == norm(i128(std::numeric_limits<long long>::max())));
    assert(mint(int(-5)).val() == P - 5);
    assert(mint::raw(3).val() == 3);
    {
        mint x = P - 1;
        x++;
        assert(x.val() == 0);
        x--;
        assert(x.val() == P - 1);
        assert((++x).val() == 0);
        assert((--x).val() == P - 1);
    }
    {
        uint64_t a = P - 1;
        mint x = a;
        assert((x * x).val() == norm(i128(a) * a));
        mint y = uint64_t(1) << 60;
        assert((y * y).val() == norm(i128(uint64_t(1) << 60) * (uint64_t(1) << 60)));
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
