#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <iostream>

#include "algebra/monoid_add.hpp"
#include "datastructure/dynamic_segtree.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    dynamic_segtree<monoid_add<long long>> seg;
    for (int i = 0; i < n; i++) {
        long long a;
        std::cin >> a;
        seg.set(i, a);
    }
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p;
            long long x;
            std::cin >> p >> x;
            seg.set(p, seg.get(p) + x);
        }
        if (t == 1) {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.prod(l, r) << '\n';
        }
    }
}
