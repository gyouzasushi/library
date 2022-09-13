#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include <iostream>

#include "datastructure/dynamic_li_chao_tree.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    DynamicLiChaoTree lct;
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
            std::cout << lct.get(p) << '\n';
        }
    }
}