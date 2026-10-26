#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <optional>
#include <random>
#include <vector>

#include "datastructure/li_chao_tree.hpp"

int main() {
    std::mt19937 rng(5);
    for (int it = 0; it < 3000; it++) {
        long long lo = (long long)(rng() % 41) - 20;
        long long hi = lo + 1 + rng() % 40;
        li_chao_tree<long long> t(lo, hi);
        std::vector<std::array<long long, 4>> segs;
        int ops = rng() % 8;
        for (int k = 0; k < ops; k++) {
            long long a = (long long)(rng() % 21) - 10, b = (long long)(rng() % 201) - 100;
            if (rng() % 2) {
                t.add_line(a, b);
                segs.push_back({a, b, lo, hi});
            } else {
                long long l = lo + rng() % (hi - lo + 1), r = lo + rng() % (hi - lo + 1);
                if (l > r) std::swap(l, r);
                t.add_segment(a, b, l, r);
                segs.push_back({a, b, l, r});
            }
        }
        for (long long x = lo; x < hi; x++) {
            std::optional<long long> best;
            for (auto [a, b, l, r] : segs)
                if (l <= x && x < r && (!best || a * x + b < *best)) best = a * x + b;
            assert(t.min(x) == best);
        }
    }
    // the case the old implementation got wrong
    {
        li_chao_tree<long long> t(-20, 21);
        for (auto [a, b] : {std::pair{5, -62}, {-8, 49}, {-1, -50}, {-4, 8}, {-7, 16}, {-1, -22}}) t.add_line(a, b);
        assert(t.min(10) == -60);
    }
    // large coordinates, double values
    {
        li_chao_tree<double> t(-1000000000, 1000000001);
        t.add_line(0.5, 1.0);
        t.add_segment(-0.5, 2.0, 0, 10);
        assert(*t.min(4) == 0.0);
        assert(*t.min(100) == 51.0);
        assert(!li_chao_tree<long long>(0, 10).min(3));
    }
    std::cout << "Hello World" << std::endl;
}
