#define PROBLEM "https://yukicoder.me/problems/no/665"
#include <atcoder/modint>
#include <iostream>
#include <vector>

#include "math/lagrange_interpolation.hpp"
using mint = atcoder::modint1000000007;
int main() {
    long long n;
    int k;
    std::cin >> n >> k;
    std::vector<mint> y(k + 2);
    for (int i = 1; i <= k + 1; i++) y[i] = y[i - 1] + mint(i).pow(k);
    std::cout << lagrange_interpolation(y, mint(n)).val() << '\n';
}
