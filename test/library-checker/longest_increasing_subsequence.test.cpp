#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"
#include <iostream>
#include <vector>

#include "algorithm/longest_increasing_subsequence.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    longest_increasing_subsequence lis(a);
    std::cout << lis.length() << '\n';
    for (int i : lis.indices()) std::cout << i << ' ';
    std::cout << '\n';
}
