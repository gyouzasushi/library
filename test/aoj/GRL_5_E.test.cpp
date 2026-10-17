#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E"
#include <atcoder/lazysegtree>
#include <iostream>

#include "graph/heavy_light_decomposition.hpp"
struct S {
    long long sum;
    int len;
};
S op(S a, S b) {
    return {a.sum + b.sum, a.len + b.len};
}
S e() {
    return {0, 0};
}
S mapping(long long f, S x) {
    return {x.sum + f * x.len, x.len};
}
long long composition(long long f, long long g) {
    return f + g;
}
long long id() {
    return 0;
}
int main() {
    int n;
    std::cin >> n;
    heavy_light_decomposition hld(n);
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        while (k--) {
            int c;
            std::cin >> c;
            hld.add_edge(i, c);
        }
    }
    hld.build();
    atcoder::lazy_segtree<S, op, e, long long, mapping, composition, id> seg(
        std::vector<S>(n, {0, 1}));
    int q;
    std::cin >> q;
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int v;
            long long w;
            std::cin >> v >> w;
            hld.for_each_edge(0, v, [&](int l, int r) { seg.apply(l, r, w); });
        }
        if (t == 1) {
            int u;
            std::cin >> u;
            long long ans = 0;
            hld.for_each_edge(0, u, [&](int l, int r) { ans += seg.prod(l, r).sum; });
            std::cout << ans << '\n';
        }
    }
}
