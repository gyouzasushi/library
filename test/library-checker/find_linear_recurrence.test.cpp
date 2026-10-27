#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"
#include <atcoder/modint>
#include <iostream>
#include <vector>

#include "math/linear_recurrence.hpp"
using mint = atcoder::modint998244353;
int main() {
    int n;
    std::cin >> n;
    std::vector<mint> a(n);
    for (auto& x : a) {
        int v;
        std::cin >> v;
        x = v;
    }
    std::vector<mint> c = berlekamp_massey(a);
    std::cout << c.size() << '\n';
    for (int i = 0; i < int(c.size()); i++) std::cout << c[i].val() << " \n"[i + 1 == int(c.size())];
    if (c.empty()) std::cout << '\n';
}
