#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"
#include <atcoder/modint>
#include <iostream>

#include "datastructure/dual_segtree.hpp"
using mint = atcoder::modint998244353;
struct F {
    mint b, c;
    mint val(mint x) {
        return b * x + c;
    }
};
F compostition(F f, F g) {
    return {f.b * g.b, f.b * g.c + f.c};
}
F id() {
    return {1, 0};
}
int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<mint> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a[i] = mint::raw(x);
    }
    dual_segtree<F, compostition, id> segt(n);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r;
            int b, c;
            std::cin >> l >> r >> b >> c;
            segt.apply(l, r, {mint::raw(b), mint::raw(c)});
        }
        if (t == 1) {
            int i;
            std::cin >> i;
            std::cout << segt.get(i).val(a[i]).val() << '\n';
        }
    }
}