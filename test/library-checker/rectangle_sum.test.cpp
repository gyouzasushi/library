#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

#include "datastructure/wavelet_matrix.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::tuple<int, int, long long>> p(n);
    for (auto& [x, y, w] : p) std::cin >> x >> y >> w;
    std::sort(p.begin(), p.end());
    std::vector<int> xs(n), ys(n);
    std::vector<long long> ws(n);
    for (int i = 0; i < n; i++) std::tie(xs[i], ys[i], ws[i]) = p[i];
    wavelet_matrix<int, long long> wm(ys, ws);
    while (q--) {
        int l, d, r, u;
        std::cin >> l >> d >> r >> u;
        int pl = int(std::lower_bound(xs.begin(), xs.end(), l) - xs.begin());
        int pr = int(std::lower_bound(xs.begin(), xs.end(), r) - xs.begin());
        std::cout << wm.sum(pl, pr, d, u) << '\n';
    }
}
