#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1160"
#include <iostream>

#include <atcoder/dsu>

#include "graph/cell.hpp"
int main() {
    while (true) {
        int w, h;
        std::cin >> w >> h;
        if (h == 0 && w == 0) break;
        cell::set_bound(h, w);
        std::vector c(h, std::vector<int>(w));
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                std::cin >> c[y][x];
            }
        }
        atcoder::dsu uf(h * w);
        for (cell u : cell::cells()) {
            if (c[u.y][u.x] != 1) continue;
            for (cell v : u.neighbors_8()) {
                if (c[v.y][v.x] != 1) continue;
                uf.merge(u, v);
            }
        }
        int ans = 0;
        for (cell u : cell::cells()) {
            if (c[u.y][u.x] == 1 && uf.leader(u) == int(u)) {
                ans++;
            }
        }
        std::cout << ans << '\n';
    }
}