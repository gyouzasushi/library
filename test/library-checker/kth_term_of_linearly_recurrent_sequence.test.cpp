#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"
#include <atcoder/modint>
#include <iostream>
#include <vector>

#include "math/linear_recurrence.hpp"
using mint = atcoder::modint998244353;
int main() {
    int d;
    long long k;
    std::cin >> d >> k;
    std::vector<mint> a(d), c(d);
    for (auto& x : a) {
        int v;
        std::cin >> v;
        x = v;
    }
    for (auto& x : c) {
        int v;
        std::cin >> v;
        x = v;
    }
    std::cout << kth_term_of_linear_recurrence(a, c, k).val() << '\n';
}
