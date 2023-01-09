#define PROBLEM "https://judge.yosupo.jp/problem/manhattanmst"
#include <iostream>

#include "datastructure/unionfind.hpp"
#include "graph/manhattan_mst.hpp"
int main() {
    int n;
    std::cin >> n;
    std::vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    UnionFind uf(n);
    long long sum = 0;
    std::vector<std::pair<int, int>> ans;
    for (auto [u, v, w] : manhattan_mst(x, y)) {
        if (uf.unite(u, v)) {
            sum += w;
            ans.emplace_back(u, v);
        }
    }
    std::cout << sum << '\n';
    for (auto [u, v] : ans) {
        std::cout << u << ' ' << v << '\n';
    }
}