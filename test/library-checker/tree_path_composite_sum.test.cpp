#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"
#include <atcoder/modint>
#include <iostream>
#include <utility>
#include <vector>

#include "graph/rerooting.hpp"
using mint = atcoder::modint998244353;
struct R {
    struct T {
        mint sum;
        int cnt;
    };
    using M = T;
    using E = std::pair<mint, mint>;  // f(x) = b x + c
    using V = mint;
    static M put_edge(const T& x, const E& f, int, int) {
        return {f.first * x.sum + f.second * x.cnt, x.cnt};
    }
    static M merge(const M& a, const M& b) {
        return {a.sum + b.sum, a.cnt + b.cnt};
    }
    static M e() {
        return {0, 0};
    }
    static T put_vertex(const M& acc, const V& a, int) {
        return {acc.sum + a, acc.cnt + 1};
    }
};
int main() {
    int n;
    std::cin >> n;
    std::vector<mint> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a[i] = mint::raw(x);
    }
    rerooting<R> rr(a);
    for (int i = 0; i < n - 1; i++) {
        int u, v, b, c;
        std::cin >> u >> v >> b >> c;
        rr.add_edge(u, v, {mint::raw(b), mint::raw(c)});
    }
    rr.solve();
    for (int i = 0; i < n; i++) {
        std::cout << rr.dp[i].sum.val() << (i + 1 < n ? ' ' : '\n');
    }
}
