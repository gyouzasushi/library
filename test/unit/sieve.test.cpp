#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "math/factorize.hpp"
#include "math/sieve.hpp"

std::vector<std::pair<long long, int>> naive_factorize(long long x) {
    std::vector<std::pair<long long, int>> ret;
    for (long long p = 2; p * p <= x; p++) {
        int e = 0;
        while (x % p == 0) x /= p, e++;
        if (e) ret.emplace_back(p, e);
    }
    if (x > 1) ret.emplace_back(x, 1);
    return ret;
}
std::vector<long long> naive_divisors(long long x) {
    std::vector<long long> ret;
    for (long long d = 1; d <= x; d++) {
        if (x % d == 0) ret.push_back(d);
    }
    return ret;
}

int main() {
    const int n = 3000;
    sieve s(n);
    {
        std::vector<int> ps;
        for (int x = 0; x <= n; x++) {
            bool prime = x >= 2;
            for (int d = 2; d * d <= x; d++) prime &= x % d != 0;
            assert(s.is_prime(x) == prime);
            if (prime) ps.push_back(x);
            if (x >= 2) assert(s.smallest_prime_factor(x) == naive_factorize(x)[0].first);
            if (x >= 1) {
                auto f = s.factorize(x);
                auto g = naive_factorize(x);
                assert(f.size() == g.size());
                for (size_t i = 0; i < f.size(); i++) assert(f[i].first == g[i].first && f[i].second == g[i].second);
                auto d = s.divisors(x);
                auto nd = naive_divisors(x);
                assert(d.size() == nd.size());
                for (size_t i = 0; i < d.size(); i++) assert(d[i] == nd[i]);
            }
        }
        assert(s.primes() == ps);
    }
    // sieve(1), sieve(2)
    {
        sieve s1(1);
        assert(s1.primes().empty() && !s1.is_prime(1) && s1.factorize(1).empty() && s1.divisors(1) == std::vector<int>{1});
        sieve s2(2);
        assert(s2.primes() == std::vector<int>{2} && s2.is_prime(2));
    }
    // large n: pi(10^7) = 664579
    {
        sieve big(10000000);
        assert(int(big.primes().size()) == 664579);
        assert((big.factorize(9999991) == std::vector<std::pair<int, int>>{{9999991, 1}}));
        assert(big.divisors(10000000).size() == 8 * 8);
    }
    // Pollard-rho factorize / divisors (vector form)
    {
        std::mt19937_64 rng(5);
        for (long long x = 1; x <= 2000; x++) {
            assert(factorize(x) == naive_factorize(x));
            assert(divisors(x) == naive_divisors(x));
        }
        for (int it = 0; it < 300; it++) {
            long long x = 1 + rng() % 1000000000000LL;
            assert(factorize(x) == naive_factorize(x));
            auto d = divisors(x);
            long long cnt = 1;
            for (auto [p, e] : factorize(x)) cnt *= e + 1;
            assert((long long)d.size() == cnt);
            for (size_t i = 0; i < d.size(); i++) {
                assert(x % d[i] == 0);
                if (i) assert(d[i - 1] < d[i]);
            }
        }
        auto d = divisors(897612484786617600LL);  // highly composite, 103680 divisors
        assert(d.size() == 103680);
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
