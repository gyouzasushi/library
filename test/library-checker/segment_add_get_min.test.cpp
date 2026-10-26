#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include <iostream>

#include "datastructure/li_chao_tree.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    li_chao_tree<long long> lct(-1000000000, 1000000001);
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
            auto ans = lct.min(p);
            if (ans) {
                std::cout << *ans << '\n';
            } else {
                std::cout << "INFINITY\n";
            }
        }
    }
}
