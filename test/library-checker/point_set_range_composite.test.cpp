#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include <atcoder/modint>
#include <iostream>
#include <vector>

#include "datastructure/segtree.hpp"
#include "algebra/monoid_affine.hpp"
using mint = atcoder::modint998244353;
using M = monoid_affine<mint>;
int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<M::S> f(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        f[i] = {mint::raw(a), mint::raw(b)};
    }
    segtree<M> seg(f);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p, c, d;
            std::cin >> p >> c >> d;
            seg.set(p, {mint::raw(c), mint::raw(d)});
        }
        if (t == 1) {
            int l, r, x;
            std::cin >> l >> r >> x;
            std::cout << M::eval(seg.prod(l, r), mint::raw(x)).val() << '\n';
        }
    }
}
