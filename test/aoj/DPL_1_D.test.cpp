#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D"
#include <bits/stdc++.h>

#include "../../algorithm/longest_increasing_subsequence.hpp"
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = longest_increasing_subsequence(a).size();
    cout << ans << '\n';
}