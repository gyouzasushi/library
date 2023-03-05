#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include <iostream>

#include "atcoder/lazysegtree.hpp"
#include "math/modint.hpp"
using mint = modint998244353;
struct S {
    mint val;
    int size;
};
S op(S a, S b) {
    return {a.val + b.val, a.size + b.size};
}
S e() {
    return {0, 0};
}
struct F {
    mint b, c;
};
F id() {
    return {1, 0};
}
S mapping(F f, S x) {
    return {f.b * x.val + f.c * x.size, x.size};
}
F composition(F f, F g) {
    return {f.b * g.b, f.b * g.c + f.c};
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<S> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].val;
        a[i].size = 1;
    }
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> segt(a);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r, b, c;
            std::cin >> l >> r >> b >> c;
            segt.apply(l, r, {b, c});
        }
        if (t == 1) {
            int l, r;
            std::cin >> l >> r;
            std::cout << segt.prod(l, r).val << '\n';
        }
    }
}