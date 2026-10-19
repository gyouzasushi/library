#define PROBLEM "https://yukicoder.me/problems/1601"

#include <iostream>

#include "datastructure/range_map.hpp"
int main() {
    long long d;
    int q;
    std::cin >> d >> q;
    range_map<long long, bool> mp;
    long long ans = 0;
    while (q--) {
        long long a, b;
        std::cin >> a >> b;
        mp.assign(
            a, b + 1, true,
            [&](long long l, long long r, bool) { ans = std::max(ans, r - l); },
            [](long long, long long, bool) {});
        std::cout << ans << '\n';
    }
}