#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include <atcoder/fenwicktree>
#include <iostream>

#include "graph/heavy_light_decomposition.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    heavy_light_decomposition hld(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        hld.add_edge(u, v);
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
            int u, v;
            std::cin >> u >> v;
            long long ans = 0;
            hld.for_each_vertex(u, v, [&](int l, int r) { ans += ft.sum(l, r); });
            std::cout << ans << '\n';
        }
    }
}
