#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <iostream>

#include "../../datastructure/sparse_table.hpp"
using S = int;
S op(S a, S b) {
    return std::min(a, b);
}
int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<S> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    SparseTable<S, op> s(a);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << s.prod(l, r) << '\n';
    }
}