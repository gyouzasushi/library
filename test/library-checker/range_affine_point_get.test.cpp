#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"
#include <atcoder/modint>
#include <iostream>
#include <vector>

#include "datastructure/dual_segtree.hpp"
using mint = atcoder::modint998244353;
struct range_affine {
    struct F {
        mint b, c;
    };
    static F composition(F f, F g) { return {f.b * g.b, f.b * g.c + f.c}; }
    static F id() { return {1, 0}; }
    static constexpr bool composition_commutative = false;
};
int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<mint> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a[i] = mint::raw(x);
    }
    dual_segtree<range_affine> seg(n);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r, b, c;
            std::cin >> l >> r >> b >> c;
            seg.apply(l, r, {mint::raw(b), mint::raw(c)});
        } else {
            int i;
            std::cin >> i;
            auto f = seg.get(i);
            std::cout << (f.b * a[i] + f.c).val() << '\n';
        }
    }
}
