#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <bits/stdc++.h>

#include "datastructure/cumulative_sum.hpp"
int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    cumulative_sum cs(a);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << cs.sum(l, r) << '\n';
    }
}