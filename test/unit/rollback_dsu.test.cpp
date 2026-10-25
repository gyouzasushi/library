#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "atcoder/dsu"
#include "datastructure/rollback_dsu.hpp"

int main() {
    std::mt19937 rng(99);
    for (int it = 0; it < 300; it++) {
        int n = 1 + rng() % 10;
        rollback_dsu d(n);
        std::vector<std::pair<int, int>> merged;  // current edge list
        std::vector<std::pair<int, int>> stack_sizes;
        auto check = [&] {
            atcoder::dsu ref(n);
            for (auto [a, b] : merged) ref.merge(a, b);
            for (int a = 0; a < n; a++) {
                for (int b = 0; b < n; b++) assert(d.same(a, b) == ref.same(a, b));
                assert(d.size(a) == ref.size(a));
            }
            assert(d.groups() == ref.groups());
            assert(d.time() == int(merged.size()));
        };
        for (int q = 0; q < 60; q++) {
            int op = rng() % 3;
            if (op == 0 || merged.empty()) {
                int a = rng() % n, b = rng() % n;
                int l = d.merge(a, b);
                merged.emplace_back(a, b);
                assert(l == d.leader(a) && l == d.leader(b));
            } else if (op == 1) {
                d.undo();
                merged.pop_back();
            } else {
                int t = rng() % (merged.size() + 1);
                d.rollback(t);
                merged.resize(t);
            }
            check();
        }
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
