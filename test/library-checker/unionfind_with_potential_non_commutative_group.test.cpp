#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group"
#include <array>
#include <iostream>

#include "atcoder/modint"
#include "datastructure/weighted_dsu.hpp"

using mint = atcoder::modint998244353;

// 2x2 matrices with determinant 1
struct group_sl2 {
    using S = std::array<mint, 4>;
    static S op(S a, S b) {
        return {a[0] * b[0] + a[1] * b[2], a[0] * b[1] + a[1] * b[3], a[2] * b[0] + a[3] * b[2],
                a[2] * b[1] + a[3] * b[3]};
    }
    static S e() {
        return {1, 0, 0, 1};
    }
    static S inv(S a) {
        return {a[3], -a[1], -a[2], a[0]};
    }
};

int main() {
    int n, q;
    std::cin >> n >> q;
    weighted_dsu<group_sl2> d(n);
    while (q--) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            int x00, x01, x10, x11;
            std::cin >> x00 >> x01 >> x10 >> x11;
            // a_u = a_v X  <=>  a_v^{-1} a_u = X  <=>  diff(v, u) = X
            std::cout << d.merge(v, u, {x00, x01, x10, x11}) << '\n';
        } else {
            if (!d.same(u, v)) {
                std::cout << -1 << '\n';
            } else {
                auto x = d.diff(v, u);  // a_v^{-1} a_u
                std::cout << x[0].val() << ' ' << x[1].val() << ' ' << x[2].val() << ' '
                          << x[3].val() << '\n';
            }
        }
    }
}
