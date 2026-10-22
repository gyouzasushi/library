#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"
#include <algorithm>
#include <iostream>
#include <vector>

#include "geometry/point.hpp"
int main() {
    int n;
    std::cin >> n;
    std::vector<geo::point<long long>> ps(n);
    for (auto& p : ps) std::cin >> p;
    std::sort(ps.begin(), ps.end(), geo::arg_less{});
    for (const auto& p : ps) std::cout << p << '\n';
}
