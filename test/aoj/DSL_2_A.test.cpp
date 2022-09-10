#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"
#include <algorithm>
#include <limits>

#include "datastructure/segment_tree.hpp"
namespace PointUpdateRangeMin {
using S = int;
S op(S a, S b) {
    return std::min(a, b);
}
S e() {
    return std::numeric_limits<S>::max();
}
using segt = SegmentTree<S, op, e>;
}  // namespace PointUpdateRangeMin
#include <iostream>
int main() {
    int n, q;
    std::cin >> n >> q;

    auto segt = PointUpdateRangeMin::segt(n);
    while (q--) {
        int com;
        std::cin >> com;
        if (com == 0) {
            int i, x;
            std::cin >> i >> x;
            segt.set(i, x);
        }
        if (com == 1) {
            int s, t;
            std::cin >> s >> t;
            std::cout << segt.prod(s, ++t) << '\n';
        }
    }
}