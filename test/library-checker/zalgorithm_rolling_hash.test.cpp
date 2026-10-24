#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include <iostream>

#include "string/rolling_hash.hpp"
int main() {
    std::string s;
    std::cin >> s;
    int n = s.size();

    rolling_hash<> rh(s);
    for (int i = 0; i < n; i++) {
        std::cout << lcp(rh, 0, n, rh, i, n) << " \n"[i == n - 1];
    }
}