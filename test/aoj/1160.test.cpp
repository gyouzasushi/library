#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1160"
#include <iostream>

#include "datastructure/unionfind.hpp"
#include "graph/grid.hpp"
int main() {
    while (true) {
        int w, h;
        std::cin >> w >> h;
        if (h == 0 && w == 0) break;
        grid::set_bound(h, w);
        std::vector c(h, std::vector<int>(w));
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                std::cin >> c[y][x];
            }
        }
        UnionFind uf(h * w);
        for (grid u : grid::grids()) {
            if (c[u.y][u.x] != 1) continue;
            for (grid v : u.neighbors_8()) {
                if (c[v.y][v.x] != 1) continue;
                uf.unite(u, v);
            }
        }
        int ans = 0;
        for (grid u : grid::grids()) {
            if (c[u.y][u.x] == 1 && uf.root(u) == int(u)) {
                ans++;
            }
        }
        std::cout << ans << '\n';
    }
}