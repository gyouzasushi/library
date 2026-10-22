#define PROBLEM "https://judge.yosupo.jp/problem/closest_pair"
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
        auto [i, j] = geo::closest_pair(ps);
        std::cout << i << ' ' << j << '\n';
    }
}
