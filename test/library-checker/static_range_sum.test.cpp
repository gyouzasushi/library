#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <bits/stdc++.h>

#include "../../datastructure/cumulative_sum.hpp"
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    CumulativeSum cs(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << cs.sum(l, r) << '\n';
    }
}