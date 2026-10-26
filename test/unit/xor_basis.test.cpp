#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <set>
#include <vector>

#include "math/xor_basis.hpp"
int main() {
    std::mt19937_64 rng(20261027);
    for (int iter = 0; iter < 2000; iter++) {
        int n = rng() % 11, bits = 1 + rng() % 10;
        std::set<long long> span{0};
        xor_basis<long long> xb;
        for (int i = 0; i < n; i++) {
            long long x = rng() % (1LL << bits);
            bool in = span.count(x);
            assert(xb.contains(x) == in);
            assert(xb.insert(x) == !in);
            if (!in) {
                std::set<long long> nxt = span;
                for (long long v : span) nxt.insert(v ^ x);
                span = nxt;
            }
        }
        assert((1LL << xb.size()) == (long long)span.size());
        for (long long x = 0; x < (1LL << bits); x++) assert(xb.contains(x) == span.count(x));
        for (int t = 0; t < 5; t++) {
            long long xv = rng() % (1LL << bits);
            std::vector<long long> sorted;
            for (long long v : span) sorted.push_back(v ^ xv);
            std::sort(sorted.begin(), sorted.end());
            assert(xb.min(xv) == sorted.front());
            assert(xb.max(xv) == sorted.back());
            for (int k = 0; k < (int)sorted.size(); k++) {
                assert(xb.kth_smallest(k, xv) == sorted[k]);
                assert(xb.kth_largest(k, xv) == sorted[sorted.size() - 1 - k]);
            }
        }
    }
    {
        // full rank over 63 bits, signed long long
        xor_basis<long long> xb;
        for (int i = 0; i < 63; i++) assert(xb.insert(1LL << i));
        assert(xb.size() == 63);
        assert(!xb.insert(rng() >> 1));
        assert(xb.max() == std::numeric_limits<long long>::max());
        assert(xb.min(12345) == 0);
        assert(xb.kth_smallest(std::numeric_limits<long long>::max()) == std::numeric_limits<long long>::max());
        assert(xb.kth_largest(0) == std::numeric_limits<long long>::max());
        assert(xb.kth_smallest(777, 1000) == 777);
    }
    {
        // unsigned 64-bit, top bit used
        xor_basis<unsigned long long> xb;
        for (int i = 0; i < 64; i++) assert(xb.insert((rng() & ((1ULL << i) - 1)) | (1ULL << i)));
        assert(xb.size() == 64);
        assert(xb.max() == ~0ULL && xb.min() == 0);
        assert(xb.kth_smallest(~0ULL) == ~0ULL);
        assert(xb.kth_largest(~0ULL) == 0);
    }
    {
        // many inserts
        xor_basis<long long> xb;
        int added = 0;
        for (int i = 0; i < 200000; i++) added += xb.insert(rng() % (1LL << 60));
        assert(added == 60 && xb.size() == 60);
    }
    {
        xor_basis<long long> xb;
        assert(xb.size() == 0 && xb.contains(0) && !xb.contains(1));
        assert(xb.max(5) == 5 && xb.min(5) == 5 && xb.kth_smallest(0, 5) == 5 && xb.kth_largest(0, 5) == 5);
    }
    std::cout << "Hello World" << std::endl;
}
