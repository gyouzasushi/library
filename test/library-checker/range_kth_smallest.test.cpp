#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
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
        int l, r, k;
        std::cin >> l >> r >> k;
        std::cout << wm.kth_smallest(l, r, k) << '\n';
    }
}
