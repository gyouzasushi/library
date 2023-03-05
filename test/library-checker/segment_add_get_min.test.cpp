#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include <iostream>

#include "datastructure/dynamic_li_chao_tree.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    dynamic_li_chao_tree lct;
    while (n--) {
        long long l, r, a, b;
        std::cin >> l >> r >> a >> b;
        lct.add_segment(a, b, l, r);
    }
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            long long l, r, a, b;
            std::cin >> l >> r >> a >> b;
            lct.add_segment(a, b, l, r);
        }
        if (t == 1) {
            long long p;
            std::cin >> p;
            long long ans = lct.get(p);
            if (ans == std::numeric_limits<long long>::max()) {
                std::cout << "INFINITY\n";
            } else {
                std::cout << ans << '\n';
            }
        }
    }
}