#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
#include <algorithm>
#include <iostream>
#include <vector>

#include "algorithm/mo.hpp"
#include "atcoder/fenwicktree.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::vector<int> v = a;
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    for (auto& x : a) x = std::lower_bound(v.begin(), v.end(), x) - v.begin();
    int m = v.size();
    mo mo;
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        mo.add(l, r);
    }
    atcoder::fenwick_tree<int> ft(m);
    long long inv = 0;
    int size = 0;
    std::vector<long long> ans(q);
    mo.run([&](int i) { inv += ft.sum(0, a[i]); ft.add(a[i], 1); size++; },
           [&](int i) { inv += size - ft.sum(0, a[i] + 1); ft.add(a[i], 1); size++; },
           [&](int i) { ft.add(a[i], -1); size--; inv -= ft.sum(0, a[i]); },
           [&](int i) { ft.add(a[i], -1); size--; inv -= size - ft.sum(0, a[i] + 1); },
           [&](int k) { ans[k] = inv; });
    for (auto x : ans) std::cout << x << '\n';
}
