#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"
#include <algorithm>
#include <limits>

#include "datastructure/lazy_segment_tree.hpp"
namespace RangeUpdateRangeMin {
using S = int;
S op(S a, S b) {
    return std::min(a, b);
}
S e() {
    return std::numeric_limits<S>::max();
}
struct F {
    int f;
    bool is_id;
};
S mapping(F f, S x) {
    if (!f.is_id) x = f.f;
    return x;
}
F composition(F f, F g) {
    return (f.is_id ? g : f);
}
F id() {
    return {0, true};
}
using segt = LazySegmentTree<S, op, e, F, mapping, composition, id>;
}  // namespace RangeUpdateRangeMin
#include <iostream>
int main() {
    int n, q;
    std::cin >> n >> q;
    auto segt = RangeUpdateRangeMin::segt(n);
    while (q--) {
        int com;
        std::cin >> com;
        if (com == 0) {
            int s, t, x;
            std::cin >> s >> t >> x;
            t++;
            segt.apply(s, t, {x, false});
        }
        if (com == 1) {
            int s, t;
            std::cin >> s >> t;
            t++;
            std::cout << segt.prod(s, t) << '\n';
        }
    }
}