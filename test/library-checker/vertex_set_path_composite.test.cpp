#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include <atcoder/modint>
#include <atcoder/segtree>
#include <iostream>

#include "graph/heavy_light_decomposition.hpp"
using mint = atcoder::modint998244353;
struct S {
    mint a, b;
};
S op(S f, S g) {
    return {g.a * f.a, g.a * f.b + g.b};
}
S e() {
    return {1, 0};
}
int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<S> f(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        f[i] = {mint::raw(a), mint::raw(b)};
    }
    heavy_light_decomposition hld(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        hld.add_edge(u, v);
    }
    hld.build();
    std::vector<S> g(n), rg(n);
    for (int i = 0; i < n; i++) {
        g[hld.index(i)] = f[i];
        rg[n - 1 - hld.index(i)] = f[i];
    }
    atcoder::segtree<S, op, e> seg(g), rseg(rg);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p, c, d;
            std::cin >> p >> c >> d;
            seg.set(hld.index(p), {c, d});
            rseg.set(n - 1 - hld.index(p), {c, d});
        }
        if (t == 1) {
            int u, v, x;
            std::cin >> u >> v >> x;
            S s = e();
            hld.for_each_vertex_noncommutative(u, v, [&](int a, int b) {
                if (a < b) {
                    s = op(s, seg.prod(a, b));
                } else {
                    s = op(s, rseg.prod(n - a, n - b));
                }
            });
            std::cout << (s.a * x + s.b).val() << '\n';
        }
    }
}
