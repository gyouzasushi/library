#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include "datastructure/cartesian_tree.hpp"

#include <iostream>
int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::vector<int> p = cartesian_tree(a);
    for (int i = 0; i < n; i++) std::cout << p[i] << " \n"[i == n - 1];
}