#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <iostream>
#include <vector>

#include "algebra/monoid_min.hpp"
#include "datastructure/sqrt_tree.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    sqrt_tree<monoid_min<int>> s(a);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << s.prod(l, r) << '\n';
    }
}
