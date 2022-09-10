#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I"
#include "datastructure/lazy_segment_tree.hpp"
namespace RangeUpdateRangeSum {
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
struct F {
    T f;
    bool is_id;
};
S mapping(F f, S x) {
    if (!f.is_id) x.val = f.f * x.size;
    return x;
}
F composition(F f, F g) {
    return (f.is_id ? g : f);
}
F id() {
    return {0, true};
}
using segt = LazySegmentTree<S, op, e, F, mapping, composition, id>;
}  // namespace RangeUpdateRangeSum
#include <iostream>
int main() {
    int n, q;
    std::cin >> n >> q;
    auto segt =
        RangeUpdateRangeSum::segt(std::vector(n, RangeUpdateRangeSum::S{0, 1}));
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
            std::cout << segt.prod(s, t).val << '\n';
        }
    }
}