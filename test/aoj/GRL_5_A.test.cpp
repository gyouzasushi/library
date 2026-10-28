#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A"
#include <iostream>

#include "graph/tree_diameter.hpp"
int main() {
    int n;
    std::cin >> n;
    tree_diameter<long long> d(n);
    for (int i = 0; i < n - 1; i++) {
        int s, t;
        long long w;
        std::cin >> s >> t >> w;
        d.add_edge(s, t, w);
    }
    d.build();
    std::cout << d.length() << '\n';
}
