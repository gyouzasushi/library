#define PROBLEM "https://yukicoder.me/problems/no/2231"
#include <iostream>

#include "string/rolling_hash.hpp"
#include "string/wildcard_matching.hpp"
void solve() {
    int n, m;
    std::string s, t;
    std::cin >> n >> m >> s >> t;
    std::vector<bool> ok = wildcard_matching_lower(s, t);
    for (char &c : s) {
        if (c == '?') c = 'a';
    }
    auto rhs = rolling_hash<>::from(s);
    auto rht = rolling_hash<>::from(t);
    auto gt = [&](int i, int j) {
        if (i == -1) return true;
        if (j - i > m) {
            int cmp1 = rolling_hash<>::cmp(rht, 0, m, rhs, i, i + m);
            if (cmp1 != 0) return cmp1 == 1;
            int cmp2 = rolling_hash<>::cmp(rhs, j, j + m, rht, 0, m);
            return cmp2 == 1;
        }
        int cmp1 = rolling_hash<>::cmp(rht, 0, j - i, rhs, i, j);
        if (cmp1 != 0) return cmp1 == 1;
        int cmp2 = rht.cmp(j - i, m, 0, m - (j - i));
        if (cmp2 != 0) return cmp2 == 1;
        int cmp3 = rolling_hash<>::cmp(rhs, i + m, j + m, rht, m - (j - i), m);
        return cmp3 == 1;
    };
    int ans = -1;
    for (int i = 0; i < n - m + 1; i++) {
        if (ok[i] && gt(ans, i)) {
            ans = i;
        }
    }
    if (ans == -1) {
        std::cout << -1 << '\n';
    } else {
        for (int i = 0; i < m; i++) {
            s[ans + i] = t[i];
        }
        std::cout << s << '\n';
    }
    return;
}
int main() {
    int tt;
    std::cin >> tt;
    while (tt--) solve();
}
