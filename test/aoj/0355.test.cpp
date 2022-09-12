#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0355"
#include <iostream>

#include "../../string/range_update_range_hash.hpp"
int main() {
    int n;
    std::string u;
    std::cin >> n >> u;
    auto rh = RangeUpdateRangeHash<>::from(u);
    int q;
    std::cin >> q;
    while (q--) {
        std::string t;
        std::cin >> t;
        if (t == "set") {
            int x, y;
            char z;
            std::cin >> x >> y >> z;
            rh.apply(--x, y, z);
        }
        if (t == "comp") {
            int a, b, c, d;
            std::cin >> a >> b >> c >> d;
            int sgn = rh.cmp(--a, b, --c, d);
            std::cout << (sgn == -1 ? 's' : sgn == 0 ? 'e' : 't') << '\n';
        }
    }
}