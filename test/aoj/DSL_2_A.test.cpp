#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"
#include <iostream>

#include "datastructure/segtree.hpp"
#include "monoid/min.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    segtree<monoid_min<int>> seg(n);
    while (q--) {
        int com, x, y;
        std::cin >> com >> x >> y;
        if (com == 0) {
            seg.set(x, y);
        } else {
            std::cout << seg.prod(x, y + 1) << '\n';
        }
    }
}
