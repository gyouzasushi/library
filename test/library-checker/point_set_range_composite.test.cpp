#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include <atcoder/modint>
#include <atcoder/segtree>
#include <iostream>
using mint = atcoder::modint998244353;
struct S {
    mint a, b;
    bool e;
    mint val(int x) {
        return a * x + b;
    }
};
S op(S f, S g) {
    if (f.e) return g;
    if (g.e) return f;
    return {g.a * f.a, g.a * f.b + g.b};
}
S e() {
    return {0, 0, true};
}
int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<S> f(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        f[i] = {mint::raw(a), mint::raw(b)};
    }
    atcoder::segtree<S, op, e> segt(f);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p, c, d;
            std::cin >> p >> c >> d;
            segt.set(p, {c, d});
        }
        if (t == 1) {
            int l, r, x;
            std::cin >> l >> r >> x;
            std::cout << segt.prod(l, r).val(x).val() << '\n';
        }
    }
}