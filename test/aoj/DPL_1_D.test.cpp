#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D"
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
}
