#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"
#include <algorithm>
#include <limits>

#include "datastructure/lazy_segment_tree.hpp"
namespace RangeAddRangeMin {
using T = long long;
using S = T;
S op(S a, S b) {
    return std::min(a, b);
}
S e() {
    return std::numeric_limits<S>::max();
}
using F = T;
S mapping(F f, S x) {
    return x + f;
}
F composition(F f, F g) {
    return f + g;
}
F id() {
    return 0;
}
using segt = LazySegmentTree<S, op, e, F, mapping, composition, id>;
}  // namespace RangeAddRangeMin
#include <iostream>
int main() {
    int n, q;
    std::cin >> n >> q;
    auto segt = RangeAddRangeMin::segt(std::vector(n, 0ll));
    while (q--) {
        int com;
        std::cin >> com;
        if (com == 0) {
            int s, t, x;
            std::cin >> s >> t >> x;
            t++;
            segt.apply(s, t, x);
        }
        if (com == 1) {
            int s, t;
            std::cin >> s >> t;
            t++;
            std::cout << segt.prod(s, t) << '\n';
        }
    }
}