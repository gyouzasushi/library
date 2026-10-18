#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G"
#include <iostream>
#include <vector>

#include "acted_monoid/range_add_range_sum.hpp"
#include "datastructure/lazy_segtree.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    using A = range_add_range_sum<long long>;
    lazy_segtree<A> seg(std::vector<A::S>(n, A::from(0)));
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int s, e;
            long long x;
            std::cin >> s >> e >> x;
            seg.apply(s - 1, e, x);
        } else {
            int s, e;
            std::cin >> s >> e;
            std::cout << seg.prod(s - 1, e).sum << '\n';
        }
    }
}
