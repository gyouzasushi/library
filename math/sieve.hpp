#pragma once
#include <cassert>
#include <utility>
#include <vector>
struct sieve {
public:
    sieve() : sieve(1) {
    }
    explicit sieve(int n) : _n(n), lpf(n + 1, 0) {
        assert(n >= 1);
        for (int i = 2; i <= n; i++) {
            if (lpf[i] == 0) {
                lpf[i] = i;
                _primes.push_back(i);
            }
            for (int p : _primes) {
                if (p > lpf[i] || (long long)p * i > n) break;
                lpf[p * i] = p;
            }
        }
    }
    bool is_prime(int x) const {
        assert(0 <= x && x <= _n);
        return x >= 2 && lpf[x] == x;
    }
    int smallest_prime_factor(int x) const {
        assert(2 <= x && x <= _n);
        return lpf[x];
    }
    const std::vector<int>& primes() const {
        return _primes;
    }
    std::vector<std::pair<int, int>> factorize(int x) const {
        assert(1 <= x && x <= _n);
        std::vector<std::pair<int, int>> ret;
        while (x > 1) {
            int p = lpf[x];
            if (!ret.empty() && ret.back().first == p) {
                ret.back().second++;
            } else {
                ret.emplace_back(p, 1);
            }
            x /= p;
        }
        return ret;
    }

private:
    int _n;
    std::vector<int> lpf, _primes;
};
