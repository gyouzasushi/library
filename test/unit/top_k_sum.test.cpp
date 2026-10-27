#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <chrono>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

#include "datastructure/top_k_sum.hpp"
template <class Compare>
void check(std::mt19937_64& rng, int iters, int ops, int vals) {
    for (int iter = 0; iter < iters; iter++) {
        int k = rng() % 6;
        top_k_sum<long long, Compare> s(k);
        std::vector<long long> v;
        for (int t = 0; t < ops; t++) {
            int c = rng() % 4;
            if (c == 0 || v.empty()) {
                long long x = rng() % vals;
                s.insert(x);
                v.push_back(x);
            } else if (c == 1) {
                int i = rng() % v.size();
                s.erase(v[i]);
                v.erase(v.begin() + i);
            } else if (c == 2) {
                k = rng() % 6;
                s.set_k(k);
            }
            std::vector<long long> w = v;
            std::sort(w.begin(), w.end(), Compare());
            long long expect = 0;
            for (int i = 0; i < std::min<int>(k, w.size()); i++) expect += w[i];
            assert(s.size() == int(v.size()));
            assert(s.k() == k);
            assert(s.sum() == expect);
        }
    }
}
int main() {
    std::mt19937_64 rng(20261027);
    check<std::greater<long long>>(rng, 300, 60, 5);
    check<std::greater<long long>>(rng, 300, 60, 1000);
    check<std::less<long long>>(rng, 300, 60, 5);
    check<std::less<long long>>(rng, 300, 60, 1000);
    {
        // k = 0 と k > size
        top_k_sum<int> s(0);
        s.insert(5);
        assert(s.sum() == 0);
        s.set_k(10);
        assert(s.sum() == 5);
        s.erase(5);
        assert(s.sum() == 0 && s.size() == 0);
    }
    {
        int n = 200000;
        auto start = std::chrono::steady_clock::now();
        top_k_sum<long long> s(n / 2);
        std::vector<long long> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = rng() % 1000000000;
            s.insert(v[i]);
        }
        long long acc = 0;
        for (int i = 0; i < n; i++) {
            s.erase(v[i]);
            v[i] = rng() % 1000000000;
            s.insert(v[i]);
            s.set_k(s.k() + (i % 2 ? 1 : -1));
            acc = (acc + s.sum()) % 1000000007;
        }
        std::vector<long long> w = v;
        std::sort(w.begin(), w.end(), std::greater<long long>());
        long long expect = 0;
        for (int i = 0; i < s.k(); i++) expect += w[i];
        assert(s.sum() == expect);
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
        std::cerr << "perf " << n << " ops: " << ms << " ms (" << acc % 1000 << ")\n";
    }
    std::cout << "Hello World\n";
}
