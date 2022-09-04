#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include <iostream>

#include "../../string/rolling_hash.hpp"
int main() {
    std::string s;
    std::cin >> s;
    int n = s.size();

    auto rh = RollingHash<>::from(s);
    for (int i = 0; i < n; i++) {
        std::cout << rh.lcp(0, n, i, n) << " \n"[i == n - 1];
    }
}