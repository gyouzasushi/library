#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"
#include <iostream>

#include "algebra/group_add.hpp"
#include "atcoder/modint"
#include "datastructure/weighted_dsu.hpp"

using mint = atcoder::modint998244353;

int main() {
    int n, q;
    std::cin >> n >> q;
    weighted_dsu<group_add<mint>> d(n);
    while (q--) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            int x;
            std::cin >> x;
            // a_u = a_v + x  <=>  diff(v, u) = x
            std::cout << d.merge(v, u, mint(x)) << '\n';
        } else {
            if (!d.same(u, v)) {
                std::cout << -1 << '\n';
            } else {
                std::cout << d.diff(v, u).val() << '\n';
            }
        }
    }
}
