#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../../datastructure/unionfind.hpp"

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            uf.unite(u, v);
        }
        if (t == 1) {
            cout << int(uf.find(u, v)) << '\n';
        }
    }
}