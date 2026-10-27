#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <tuple>
#include <utility>
#include <vector>

#include "datastructure/rectangle_sum.hpp"
int main() {
    std::mt19937_64 rng(20261027);
    for (int iter = 0; iter < 500; iter++) {
        int n = rng() % 30;
        long long range = 1 + rng() % 20;
        std::vector<std::tuple<long long, long long, long long>> pts(n);
        std::vector<std::pair<long long, long long>> pts2(n);
        for (int i = 0; i < n; i++) {
            long long x = (long long)(rng() % range) - range / 2;
            long long y = (long long)(rng() % range) - range / 2;
            long long w = (long long)(rng() % 2001) - 1000;
            pts[i] = {x, y, w};
            pts2[i] = {x, y};
        }
        rectangle_sum<long long, long long> rs(pts);
        rectangle_sum<long long> rc(pts2);
        assert(rs.size() == n && rc.size() == n);
        for (int t = 0; t < 50; t++) {
            long long x1 = (long long)(rng() % (range + 2)) - range / 2 - 1;
            long long x2 = (long long)(rng() % (range + 2)) - range / 2 - 1;
            long long y1 = (long long)(rng() % (range + 2)) - range / 2 - 1;
            long long y2 = (long long)(rng() % (range + 2)) - range / 2 - 1;
            int cnt = 0;
            long long sum = 0;
            for (auto [x, y, w] : pts) {
                if (x1 <= x && x < x2 && y1 <= y && y < y2) cnt++, sum += w;
            }
            assert(rs.count(x1, x2, y1, y2) == cnt);
            assert(rc.count(x1, x2, y1, y2) == cnt);
            assert(rs.sum(x1, x2, y1, y2) == sum);
        }
    }
    {
        int n = 200000, q = 200000;
        auto start = std::chrono::steady_clock::now();
        std::vector<std::tuple<int, int, long long>> pts(n);
        for (auto& [x, y, w] : pts) x = rng() % 1000000000, y = rng() % 1000000000, w = rng() % 1000000000;
        rectangle_sum<int, long long> rs(pts);
        long long acc = 0;
        for (int i = 0; i < q; i++) {
            int x1 = rng() % 1000000000, x2 = rng() % 1000000000;
            int y1 = rng() % 1000000000, y2 = rng() % 1000000000;
            if (x1 > x2) std::swap(x1, x2);
            if (y1 > y2) std::swap(y1, y2);
            acc = (acc + rs.sum(x1, x2, y1, y2)) % 1000000007;
        }
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
        std::cerr << "perf n=q=" << n << ": " << ms << " ms (" << acc % 1000 << ")\n";
    }
    std::cout << "Hello World\n";
}
