#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "datastructure/binary_trie.hpp"

template <int log> void run(std::mt19937_64& rng, int iters) {
    const long long lim = 1LL << log;
    for (int it = 0; it < iters; it++) {
        binary_trie<log> t;
        std::vector<long long> ms;  // multiset
        int range = log <= 4 ? int(lim) : 50;
        for (int q = 0; q < 200; q++) {
            long long x = log <= 4 ? (long long)(rng() % lim) : (rng() % 3 ? (long long)(rng() % range) : (long long)(rng() % lim));
            int op = rng() % 4;
            if (op == 0) {
                int k = rng() % 3;
                t.insert(x, k);
                for (int i = 0; i < k; i++) ms.push_back(x);
            } else if (op == 1) {
                int c = int(std::count(ms.begin(), ms.end(), x));
                assert(t.count(x) == c);
                if (c > 0) {
                    int k = rng() % (c + 1);
                    t.erase(x, k);
                    for (int i = 0; i < k; i++) ms.erase(std::find(ms.begin(), ms.end(), x));
                }
            }
            assert(t.size() == int(ms.size()));
            long long v = log <= 4 ? (long long)(rng() % lim) : (rng() % 2 ? (long long)(rng() % range) : (long long)(rng() % lim));
            std::vector<long long> xs;
            for (long long a : ms) xs.push_back(a ^ v);
            std::sort(xs.begin(), xs.end());
            long long upper = log <= 4 ? (long long)(rng() % (lim + 2)) - 1 : (long long)(rng() % (range + 2)) - 1;
            assert(t.count_less(upper, v) == int(std::lower_bound(xs.begin(), xs.end(), upper) - xs.begin()));
            assert(t.count_less(lim, v) == int(xs.size()));
            assert(t.count_less(lim + 5, v) == int(xs.size()));
            assert(t.count_less(0, v) == 0);
            if (!xs.empty()) {
                int k = rng() % xs.size();
                assert(t.kth_smallest(k, v) == xs[k]);
                assert(t.kth_largest(k, v) == xs[xs.size() - 1 - k]);
                assert(t.min(v) == xs.front());
                assert(t.max(v) == xs.back());
                assert(t.min() == *std::min_element(ms.begin(), ms.end()));
            }
        }
    }
}

int main() {
    std::mt19937_64 rng(31);
    run<3>(rng, 200);
    run<30>(rng, 100);
    run<62>(rng, 30);
    std::cout << "Hello World" << std::endl;
    return 0;
}
