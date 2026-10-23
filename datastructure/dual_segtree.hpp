#pragma once
#include <algorithm>
#include <bit>
#include <cassert>
#include <vector>

#include "monoid/concept.hpp"
template <action A>
struct dual_segtree {
    using F = typename A::F;
    dual_segtree() : dual_segtree(0) {}
    explicit dual_segtree(int n) : dual_segtree(std::vector<F>(n, A::id())) {}
    explicit dual_segtree(const std::vector<F>& v) : n(int(v.size())) {
        log = std::bit_width(unsigned(std::max(n - 1, 0)));
        size = 1 << log;
        d.assign(2 * size, A::id());
        for (int i = 0; i < n; i++) d[size + i] = v[i];
    }
    void set(int p, F x) {
        assert(0 <= p && p < n);
        p += size;
        thrust(p);
        d[p] = x;
    }
    F get(int p) {
        assert(0 <= p && p < n);
        p += size;
        if constexpr (A::composition_commutative) {
            F ret = d[p];
            while (p >>= 1) ret = A::composition(d[p], ret);
            return ret;
        } else {
            thrust(p);
            return d[p];
        }
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return;
        l += size;
        r += size;
        if constexpr (!A::composition_commutative) {
            thrust(l);
            thrust(r - 1);
        }
        while (l < r) {
            if (l & 1) d[l] = A::composition(f, d[l]), l++;
            if (r & 1) --r, d[r] = A::composition(f, d[r]);
            l >>= 1, r >>= 1;
        }
    }

private:
    int n, size, log;
    std::vector<F> d;
    void propagate(int k) {
        d[2 * k] = A::composition(d[k], d[2 * k]);
        d[2 * k + 1] = A::composition(d[k], d[2 * k + 1]);
        d[k] = A::id();
    }
    void thrust(int k) {
        for (int i = log; i >= 1; i--) propagate(k >> i);
    }
};
