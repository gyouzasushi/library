#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B"

#include <iostream>
#include <map>

#include "graph/rerooting.hpp"
std::map<std::pair<int, int>, int> w;
using S = int;
S op(S a, S b) {
    return std::max(a, b);
}
S e() {
    return 0;
}
S put_edge(S dp, int u, int v) {
    return dp + w[{u, v}];
}
S put_vertex(S dp, int) {
    return dp;
}
int main() {
    int n;
    std::cin >> n;
    rerooting<S, op, e, put_edge, put_vertex> g(n);
    for (int i = 0; i < n - 1; i++) {
        int s, t;
        std::cin >> s >> t;
        g.add_edge(s, t);
        std::cin >> w[{s, t}];
        w[{t, s}] = w[{s, t}];
    }
    std::vector dp = g.solve();
    for (int i = 0; i < n; i++) {
        std::cout << dp[i] << '\n';
    }
}