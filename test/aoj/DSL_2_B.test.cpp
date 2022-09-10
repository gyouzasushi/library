#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"
#include "datastructure/segment_tree.hpp"
namespace PointUpdateRangeSum {
using S = long long;
S op(S a, S b) {
    return a + b;
}
S e() {
    return 0;
}
using segt = SegmentTree<S, op, e>;
}  // namespace PointUpdateRangeSum
#include <iostream>
int main() {
    int n, q;
    std::cin >> n >> q;
    auto segt = PointUpdateRangeSum::segt(n);
    while (q--) {
        int com;
        std::cin >> com;
        if (com == 0) {
            int i, x;
            std::cin >> i >> x;
            i--;
            segt.set(i, x + segt.get(i));
        }
        if (com == 1) {
            int s, t;
            std::cin >> s >> t;
            s--;
            std::cout << segt.prod(s, t) << '\n';
        }
    }
}