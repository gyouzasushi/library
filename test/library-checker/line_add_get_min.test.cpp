#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include <iostream>

#include "datastructure/li_chao_tree.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    li_chao_tree<long long> lct(-1000000000, 1000000001);
    while (n--) {
        long long a, b;
        std::cin >> a >> b;
        lct.add_line(a, b);
    }
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            long long a, b;
            std::cin >> a >> b;
            lct.add_line(a, b);
        }
        if (t == 1) {
            long long p;
            std::cin >> p;
            std::cout << *lct.min(p) << '\n';
        }
    }
}
