#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include <iostream>

#include "string/rolling_hash.hpp"
int main() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    auto rh = RollingHash<>::from(s);
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 0);
    std::sort(a.begin(), a.end(),
              [&](int i, int j) { return rh.cmp(i, n, j, n) < 0; });
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
}