#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <iostream>
#include <vector>

#include "datastructure/sparse_table.hpp"
#include "algebra/monoid_min.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int& x : a) std::cin >> x;
    sparse_table<monoid_min<int>> st(a);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << st.prod(l, r) << '\n';
    }
}
