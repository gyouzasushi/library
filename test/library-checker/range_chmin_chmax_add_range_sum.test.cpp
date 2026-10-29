#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include <iostream>

#include "algebra/range_chmin_chmax_add_range_sum.hpp"
#include "datastructure/segtree_beats.hpp"
int main() {
    using A = range_chmin_chmax_add_range_sum<long long>;
    int n, q;
    std::cin >> n >> q;
    std::vector<A::S> a(n);
    for (auto& x : a) {
        long long v;
        std::cin >> v;
        x = A::from(v);
    }
    segtree_beats<A> seg(a);
    while (q--) {
        int t, l, r;
        std::cin >> t >> l >> r;
        if (t == 3) {
            std::cout << seg.prod(l, r).sum << '\n';
            continue;
        }
        long long b;
        std::cin >> b;
        if (t == 0) seg.apply(l, r, A::chmin(b));
        if (t == 1) seg.apply(l, r, A::chmax(b));
        if (t == 2) seg.apply(l, r, A::add(b));
    }
}
