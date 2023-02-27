#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0378"
#include <iostream>

#include "string/wildcard_matching.hpp"
int main() {
    int aw, ah, bw, bh;
    std::cin >> aw >> ah >> bw >> bh;
    std::string s, t;
    for (int i = 0; i < ah; i++) {
        std::string a;
        std::cin >> a;
        s += a;
    }
    for (int i = 0; i < bh; i++) {
        std::string b;
        std::cin >> b;
        t += b;
        if (i < bh - 1) t += std::string(aw - bw, '?');
    }
    std::vector<bool> ok = wildcard_matching(s, t);
    int ans = 0;
    for (int i = 0; i < ah - bh + 1; i++) {
        for (int j = 0; j < aw - bw + 1; j++) {
            ans += ok[i * aw + j];
        }
    }
    std::cout << ans << '\n';
}