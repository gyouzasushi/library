#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include <iostream>
#include <vector>

#include "math/sieve.hpp"

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    sieve s(n);
    const std::vector<int>& p = s.primes();
    std::vector<int> ans;
    for (int i = b; i < int(p.size()); i += a) ans.push_back(p[i]);
    std::cout << p.size() << ' ' << ans.size() << '\n';
    for (size_t i = 0; i < ans.size(); i++) std::cout << ans[i] << " \n"[i + 1 == ans.size()];
    if (ans.empty()) std::cout << '\n';
}
