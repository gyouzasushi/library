#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558"
#include <iostream>
#include <queue>

#include "graph/grid.hpp"

int main() {
    int h, w, n;
    std::cin >> h >> w >> n;
    grid::set_bound(h, w);
    std::vector<std::string> s(h);
    std::vector<grid> p(n + 1);
    for (int y = 0; y < h; y++) {
        std::cin >> s[y];
        for (int x = 0; x < w; x++) {
            if (s[y][x] == 'S') p[0] = grid(y, x);
            if (std::isdigit(s[y][x])) p[s[y][x] - '0'] = grid(y, x);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        std::vector<int> d(h * w, -1);
        std::queue<grid> q;
        d[p[i]] = 0, q.push(p[i]);
        while (!q.empty()) {
            grid u = q.front();
            q.pop();
            for (grid v : u.neighbors()) {
                if (s[v.y][v.x] == 'X') continue;
                if (d[v] != -1) continue;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        ans += d[p[i + 1]];
    }
    std::cout << ans << '\n';
}