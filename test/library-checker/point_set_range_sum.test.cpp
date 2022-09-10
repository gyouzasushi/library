#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <iostream>

#include "../../datastructure/fenwick_tree.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    FenwickTree<long long> ft(n);
    for (int i = 0; i < n; i++) {
        long long a;
        std::cin >> a;
        ft.set(i, a);
    }
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p;
            long long x;
            std::cin >> p >> x;
            long long d = ft.sum(p, p + 1) + x;
            ft.set(p, d);
        }
        if (t == 1) {
            int l, r;
            std::cin >> l >> r;
            std::cout << ft.sum(l, r) << '\n';
        }
    }
}