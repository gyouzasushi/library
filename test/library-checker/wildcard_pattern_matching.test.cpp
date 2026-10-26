#define PROBLEM "https://judge.yosupo.jp/problem/wildcard_pattern_matching"
#include <iostream>
#include <string>

#include "string/wildcard_matching.hpp"
int main() {
    std::string s, t;
    std::cin >> s >> t;
    for (bool ok : wildcard_matching(s, t, '*')) std::cout << ok;
    std::cout << '\n';
}
