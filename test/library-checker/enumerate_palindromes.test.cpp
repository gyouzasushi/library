#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes";
#include <iostream>

#include "../../string/rolling_hash.hpp"
int main() {
    std::string s;
    std::cin >> s;
    int n = s.size();

    auto rh = RollingHash<>::from(s);
    auto rh_rev = RollingHash<>::from(std::string(s.rbegin(), s.rend()));

    std::vector<int> ans(2 * n - 1);
    for (int i = 0, j = 0; i < n; i++, j += 2) {
        int ok = 0, ng = std::min(i, n - i - 1) + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            bool f = rh(i - mid, i) == rh_rev(n - (i + 1 + mid), n - (i + 1));
            (f ? ok : ng) = mid;
        }
        ans[j] = ok * 2 + 1;
    }
    for (int i = 0, j = 1; i + 1 < n; i++, j += 2) {
        int ok = 0, ng = std::min(i + 1, n - i - 1) + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            bool f = rh(i - mid + 1, i + 1) ==
                     rh_rev(n - (i + 1 + mid), n - (i + 1));
            (f ? ok : ng) = mid;
        }
        ans[j] = ok * 2;
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        std::cout << ans[i] << " \n"[i == 2 * n - 2];
    }
}