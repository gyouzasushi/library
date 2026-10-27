#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include "datastructure/persistent_array.hpp"
int main() {
    std::mt19937_64 rng(20261027);
    for (int iter = 0; iter < 300; iter++) {
        int n = 1 + rng() % 20;
        std::vector<long long> init(n);
        for (auto& x : init) x = rng() % 100;
        persistent_array<long long> a(init);
        std::vector<std::vector<long long>> versions{init};
        std::vector<int> roots{0};
        assert(a.size() == n);
        for (int t = 0; t < 60; t++) {
            int k = rng() % roots.size();
            int p = rng() % n;
            long long x = rng() % 100;
            roots.push_back(a.set(roots[k], p, x));
            std::vector<long long> v = versions[k];
            v[p] = x;
            versions.push_back(v);
            int c = rng() % roots.size();
            for (int i = 0; i < n; i++) assert(a.get(roots[c], i) == versions[c][i]);
        }
    }
    {
        persistent_array<int> a(5);
        for (int i = 0; i < 5; i++) assert(a.get(0, i) == 0);
        int r1 = a.set(0, 2, 7);
        int r2 = a.set(r1, 2, 9);
        assert(a.get(0, 2) == 0 && a.get(r1, 2) == 7 && a.get(r2, 2) == 9);
    }
    {
        int n = 200000, q = 200000;
        auto start = std::chrono::steady_clock::now();
        persistent_array<int> a(n);
        std::vector<int> roots{0};
        long long acc = 0;
        for (int i = 0; i < q; i++) {
            int k = rng() % roots.size();
            roots.push_back(a.set(roots[k], rng() % n, int(rng() % 1000)));
            acc += a.get(roots[rng() % roots.size()], rng() % n);
        }
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
        std::cerr << "perf n=q=" << n << ": " << ms << " ms (" << acc % 1000 << ")\n";
    }
    std::cout << "Hello World\n";
}
