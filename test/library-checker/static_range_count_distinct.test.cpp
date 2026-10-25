#define PROBLEM "https://judge.yosupo.jp/problem/static_range_count_distinct"
#include <iostream>
#include <map>
#include <vector>

#include "datastructure/wavelet_matrix.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> prev(n);
    std::map<int, int> last;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        auto it = last.find(a);
        prev[i] = it == last.end() ? -1 : it->second;
        last[a] = i;
    }
    wavelet_matrix<int> wm(prev);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << wm.count(l, r, l) << '\n';
    }
}
