#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D"

#include <iostream>

#include "datastructure/dual_segment_tree.hpp"

using F = int;
F composition(F a, F b) {
    return a + b;
}
F id() {
    return 0;
}
int main() {
    int n, q;
    std::cin >> n >> q;
    DualSegmentTree<F, composition, id> segt(n, true);
    while (q--) {
        int type;
        std::cin >> type;
        if (type == 0) {
            int l, r, x;
            std::cin >> l >> r >> x;
            segt.apply(--l, r, x);
        }
        if (type == 1) {
            int i;
            std::cin >> i;
            std::cout << segt.get(--i) << '\n';
        }
    }
}