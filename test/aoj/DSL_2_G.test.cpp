#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"
#include "datastructure/lazy_segment_tree.hpp"
namespace RangeAddRangeSum {
using T = long long;
struct S {
    T val;
    int size;
};
S op(S a, S b) {
    return {a.val + b.val, a.size + b.size};
}
S e() {
    return {0, 0};
}
using F = T;
S mapping(F f, S x) {
    return {x.val + f * x.size, x.size};
}
F composition(F f, F g) {
    return f + g;
}
F id() {
    return 0;
}
using segt = LazySegmentTree<S, op, e, F, mapping, composition, id>;
}  // namespace RangeAddRangeSum
#include <iostream>
int main() {
    int n, q;
    std::cin >> n >> q;
    auto segt =
        RangeAddRangeSum::segt(std::vector<RangeAddRangeSum::S>(n, {0, 1}));
    while (q--) {
        int com;
        std::cin >> com;
        if (com == 0) {
            int s, t, x;
            std::cin >> s >> t >> x;
            s--;
            segt.apply(s, t, x);
        }
        if (com == 1) {
            int s, t;
            std::cin >> s >> t;
            s--;
            std::cout << segt.prod(s, t).val << '\n';
        }
    }
}