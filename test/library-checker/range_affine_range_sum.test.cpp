#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include <atcoder/modint>
#include <iostream>
#include <vector>

#include "algebra/range_affine_range_sum.hpp"
#include "datastructure/lazy_segtree.hpp"
using mint = atcoder::modint998244353;
int main() {
    int n, q;
    std::cin >> n >> q;
    using A = range_affine_range_sum<mint>;
    std::vector<A::S> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a[i] = A::from(mint::raw(x));
    }
    lazy_segtree<A> seg(a);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r, b, c;
            std::cin >> l >> r >> b >> c;
            seg.apply(l, r, {mint::raw(b), mint::raw(c)});
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.prod(l, r).sum.val() << '\n';
        }
    }
}
