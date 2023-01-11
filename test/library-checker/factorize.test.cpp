#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../../math/factorize.hpp"

#include <iostream>

int main() {
    int q;
    std::cin >> q;
    while (q--) {
        long long a;
        std::cin >> a;
        std::vector<long long> ans;
        for (auto [b, c] : factorize(a)) {
            ans.resize(ans.size() + c, b);
        }
        int k = ans.size();
        std::cout << k << ' ';
        for (int i = 0; i < k; i++) {
            std::cout << ans[i] << " \n"[i == k - 1];
        }
    }
}