#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include <iostream>
#include <vector>

#include "datastructure/rollback_dsu.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> t(q), k(q), u(q), v(q);
    // version tree: node q is G_{-1}; type-0 query i is node i with parent k
    std::vector<std::vector<int>> children(q + 1), asks(q + 1);
    for (int i = 0; i < q; i++) {
        std::cin >> t[i] >> k[i] >> u[i] >> v[i];
        int p = k[i] == -1 ? q : k[i];
        if (t[i] == 0) {
            children[p].push_back(i);
        } else {
            asks[p].push_back(i);
        }
    }
    std::vector<int> ans(q, -1);
    rollback_dsu d(n);
    std::vector<std::pair<int, int>> st = {{q, 0}};  // (node, next child index)
    while (!st.empty()) {
        auto& [x, it] = st.back();
        if (it == 0) {
            if (x != q) d.merge(u[x], v[x]);
            for (int i : asks[x]) ans[i] = d.same(u[i], v[i]);
        }
        if (it < int(children[x].size())) {
            int c = children[x][it++];
            st.emplace_back(c, 0);
        } else {
            if (x != q) d.undo();
            st.pop_back();
        }
    }
    for (int i = 0; i < q; i++) {
        if (t[i] == 1) std::cout << ans[i] << '\n';
    }
}
