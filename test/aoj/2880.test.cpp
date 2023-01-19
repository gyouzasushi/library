#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2880"
#include <algorithm>
#include <iostream>
#include <vector>

#include "datastructure/range_set.hpp"
int main() {
    int n, m, q;
    std::cin >> n >> m >> q;
    struct Q {
        int day, id, l, r;
    };
    std::vector<Q> query(m + q);
    for (int i = 0; i < m + q; i++) {
        int d, a, b;
        std::cin >> d >> a >> b;
        query[i] = {d, i, a, b};
    }
    std::sort(query.begin(), query.end(), [](Q a, Q b) {
        if (a.day == b.day) return a.id > b.id;
        return a.day < b.day;
    });
    range_set<int> st(false);
    std::vector<bool> ans(q);
    for (auto [_, id, l, r] : query) {
        if (id < m) {
            st.insert(l, r);
        } else {
            if (l < r) {
                ans[id - m] = st.contains(l, r).has_value();
            } else {
                ans[id - m] = true;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        if (ans[i]) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
}