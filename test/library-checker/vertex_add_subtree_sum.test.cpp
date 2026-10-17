#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include <atcoder/fenwicktree>
#include <iostream>

#include "graph/heavy_light_decomposition.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    heavy_light_decomposition hld(n);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        hld.add_edge(i, p);
    }
    hld.build();
    atcoder::fenwick_tree<long long> ft(n);
    for (int i = 0; i < n; i++) ft.add(hld.index(i), a[i]);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p;
            long long x;
            std::cin >> p >> x;
            ft.add(hld.index(p), x);
        }
        if (t == 1) {
            int u;
            std::cin >> u;
            long long ans = 0;
            hld.for_each_vertex_in_subtree(u, [&](int l, int r) { ans += ft.sum(l, r); });
            std::cout << ans << '\n';
        }
    }
}
