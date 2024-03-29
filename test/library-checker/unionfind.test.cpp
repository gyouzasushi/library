#include <bits/stdc++.h>

#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../../datastructure/unionfind.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    unionfind uf(n);
    while (q--) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            uf.unite(u, v);
        }
        if (t == 1) {
            std::cout << int(uf.find(u, v)) << '\n';
        }
    }
}