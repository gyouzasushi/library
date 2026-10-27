#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include <iostream>
#include <vector>

#include "datastructure/persistent_array.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    persistent_array<int> a(std::vector<int>(n, -1));
    auto leader = [&](int root, int v) {
        while (a.get(root, v) >= 0) v = a.get(root, v);
        return v;
    };
    std::vector<int> roots(q + 1);
    roots[0] = 0;
    for (int i = 0; i < q; i++) {
        int t, k, u, v;
        std::cin >> t >> k >> u >> v;
        int root = roots[k + 1];
        if (t == 0) {
            u = leader(root, u), v = leader(root, v);
            if (u != v) {
                int su = -a.get(root, u), sv = -a.get(root, v);
                if (su < sv) std::swap(u, v), std::swap(su, sv);
                root = a.set(root, u, -(su + sv));
                root = a.set(root, v, u);
            }
            roots[i + 1] = root;
        } else {
            roots[i + 1] = root;
            std::cout << (leader(root, u) == leader(root, v) ? 1 : 0) << '\n';
        }
    }
}
