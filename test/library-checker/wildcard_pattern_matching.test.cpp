#define PROBLEM "https://judge.yosupo.jp/problem/wildcard_pattern_matching"
#include <iostream>

#include "string/wildcard_matching.hpp"
int main() {
    std::string s, t;
    std::cin >> s >> t;
    for (char &c : s) {
        if (c == '*') c = '?';
    }
    for (char &c : t) {
        if (c == '*') c = '?';
    }
    for (int ans : wildcard_matching_lower(s, t)) {
        std::cout << ans;
    }
    std::cout << '\n';
}