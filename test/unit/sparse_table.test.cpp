#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "datastructure/plus_minus_one_rmq.hpp"
#include "datastructure/sparse_table.hpp"
#include "monoid/argmin.hpp"
#include "monoid/gcd.hpp"
#include "monoid/max.hpp"
#include "monoid/min.hpp"
// band without identity: keep the left operand
struct leftmost {
    using S = int;
    static S op(S a, S) {
        return a;
    }
};
template <class M, class F> void stress(std::mt19937& rng, const F& gen) {
    using S = typename M::S;
    int n = 1 + rng() % 40;
    std::vector<S> a(n);
    for (int i = 0; i < n; i++) a[i] = gen(i);
    sparse_table<M> st(a);
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r <= n; r++) {
            S expect = a[l];
            for (int i = l + 1; i < r; i++) expect = M::op(expect, a[i]);
            assert(st.prod(l, r) == expect);
        }
    }
}
int main() {
    std::mt19937 rng(99);
    for (int it = 0; it < 300; it++) {
        stress<monoid_min<int>>(rng, [&](int) { return int(rng() % 100); });
        stress<monoid_max<long long>>(rng, [&](int) { return (long long)(rng() % 100) - 50; });
        stress<monoid_gcd<int>>(rng, [&](int) { return int(rng() % 60); });
        stress<leftmost>(rng, [&](int i) { return i * 7 % 13; });
        {
            int n = 1 + rng() % 40;
            std::vector<monoid_argmin<int>::S> a(n);
            std::vector<int> v(n);
            for (int i = 0; i < n; i++) v[i] = rng() % 5, a[i] = {v[i], i};
            sparse_table<monoid_argmin<int>> st(a);
            for (int l = 0; l < n; l++) {
                for (int r = l + 1; r <= n; r++) {
                    int best = l;
                    for (int i = l; i < r; i++) {
                        if (v[i] < v[best]) best = i;
                    }
                    assert(st.prod(l, r).id == best && st.prod(l, r).val == v[best]);
                }
            }
        }
        {
            int n = 1 + rng() % 70;
            std::vector<int> v(n);
            v[0] = rng() % 3;
            for (int i = 1; i < n; i++) v[i] = v[i - 1] + (rng() % 2 ? 1 : -1);
            plus_minus_one_rmq rmq(v);
            for (int l = 0; l < n; l++) {
                for (int r = l + 1; r <= n; r++) {
                    int best = l;
                    for (int i = l; i < r; i++) {
                        if (v[i] < v[best]) best = i;
                    }
                    assert(rmq.prod(l, r) == best);
                }
            }
        }
    }
    std::cout << "Hello World" << std::endl;
}
