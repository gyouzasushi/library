#define PROBLEM "https://yukicoder.me/problems/1601"

#include <iostream>

#include "datastructure/range_set.hpp"
int main() {
    long long d;
    int q;
    std::cin >> d >> q;
    range_set<long long> st;
    long long ans = 0;
    while (q--) {
        long long a, b;
        std::cin >> a >> b;
        st.insert(
            a, b, [](long long l, long long r, bool x) {},
            [&](long long l, long long r, bool x) {
                ans = std::max(ans, r - l + 1);
            });
        std::cout << ans << '\n';
    }
}