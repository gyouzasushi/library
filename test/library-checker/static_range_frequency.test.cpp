#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"
#include <iostream>
#include <vector>

#include "datastructure/wavelet_matrix.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    wavelet_matrix<int> wm(a);
    while (q--) {
        int l, r, x;
        std::cin >> l >> r >> x;
        std::cout << wm.count(l, r, x, x + 1) << '\n';
    }
}
