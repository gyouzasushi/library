#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

#include "math/quotient_blocks.hpp"
void check(long long n) {
    auto bs = quotient_blocks(n);
    long long expect_l = 1;
    for (auto [l, r, q] : bs) {
        assert(l == expect_l && l < r && r <= n + 1);
        assert(n / l == q && n / (r - 1) == q);
        assert(r == n + 1 || n / r < q);
        expect_l = r;
    }
    assert(expect_l == n + 1);
}
int main() {
    for (long long n = 0; n <= 2000; n++) check(n);
    for (long long n : {1000000000000LL, 999999999999LL, 1000003LL * 999983LL, (1LL << 40)}) {
        check(n);
        assert((long long)quotient_blocks(n).size() <= 2 * (long long)std::sqrt((double)n) + 2);
    }
    assert(quotient_blocks(0).empty());
    assert(quotient_blocks(1).size() == 1);
    // Σ_{i=1}^{n} floor(n / i) via blocks equals direct sum
    for (long long n : {1LL, 10LL, 12345LL, 100000LL}) {
        long long direct = 0;
        for (long long i = 1; i <= n; i++) direct += n / i;
        long long blocks = 0;
        for (auto [l, r, q] : quotient_blocks(n)) blocks += (r - l) * q;
        assert(direct == blocks);
    }
    std::cout << "Hello World" << std::endl;
}
