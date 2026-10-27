#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include <iostream>
#include <tuple>
#include <vector>

#include "datastructure/rectangle_sum.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::tuple<int, int, long long>> pts(n);
    for (auto& [x, y, w] : pts) std::cin >> x >> y >> w;
    rectangle_sum<int, long long> rs(pts);
    while (q--) {
        int l, d, r, u;
        std::cin >> l >> d >> r >> u;
        std::cout << rs.sum(l, r, d, u) << '\n';
    }
}
