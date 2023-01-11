#define PROBLEM \
    "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include <iostream>

#include "graph/subtree_classify.hpp"
int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        g[p].push_back(i);
    }

    std::vector<int> a = subtree_classify(g);
    int k = *std::max_element(a.begin(), a.end()) + 1;
    std::cout << k << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
}