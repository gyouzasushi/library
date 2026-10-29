#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0355"
#include <iostream>

#include "algebra/range_assign_range_hash.hpp"
#include "datastructure/lazy_segtree.hpp"
int main() {
    int n;
    std::string u;
    std::cin >> n >> u;
    using A = range_assign_range_hash<>;
    std::vector<A::S> init;
    for (char c : u) init.push_back(A::from(c));
    lazy_segtree<A> rh(init);
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
            int sgn = compare(rh, --a, b, rh, --c, d);
            std::cout << (sgn == -1 ? 's' : sgn == 0 ? 'e' : 't') << '\n';
        }
    }
}