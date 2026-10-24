#pragma once
#include <cassert>
#include <vector>

#include "datastructure/lazy_segtree.hpp"
#include "string/string_hash.hpp"
template <int k = 1, class mint = modint2305843009213693951>
struct range_update_range_hash {
    using H = string_hash<k, mint>;
    range_update_range_hash() : n(0) {}
    template <class Iterable>
    explicit range_update_range_hash(const Iterable& s) {
        std::vector<H> v;
        for (auto&& c : s) v.emplace_back(int(c));
        n = int(v.size());
        seg = lazy_segtree<A>(v);
    }
    int size() const {
        return n;
    }
    void set(int p, int c) {
        assert(0 <= c);
        seg.set(p, H(c));
    }
    void apply(int l, int r, int c) {
        assert(0 <= c);
        seg.apply(l, r, c);
    }
    H prod(int l, int r) {
        return seg.prod(l, r);
    }
    H get(int p) {
        return seg.get(p);
    }
    H all_prod() {
        return seg.all_prod();
    }

private:
    struct A {
        using S = H;
        using F = int;
        static S op(S a, S b) {
            return a + b;
        }
        static S e() {
            return S();
        }
        static S mapping(F f, S x) {
            return f < 0 ? x : H::repeat(f, x.len);
        }
        static F composition(F f, F g) {
            return f < 0 ? g : f;
        }
        static F id() {
            return -1;
        }
        static constexpr bool composition_commutative = false;
    };
    int n;
    lazy_segtree<A> seg;
};
