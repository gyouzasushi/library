#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"
#include <iostream>
#include <vector>

#include "geometry/polygon.hpp"
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<geo::point<long long>> ps(n);
        for (auto& p : ps) std::cin >> p;
        geo::polygon<long long> ch = geo::convex_hull(ps);
        std::cout << ch.size() << '\n';
        for (const auto& p : ch) std::cout << p << '\n';
    }
}
