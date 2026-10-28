#pragma once
#include <cassert>
#include <utility>
#include <vector>

#include "algebra/concept.hpp"
template <monoid M> struct dynamic_segtree {
public:
    using S = typename M::S;
    explicit dynamic_segtree(long long lo = -(1LL << 62), long long hi = 1LL << 62) : lo(lo), hi(hi) {
        assert(lo < hi);
    }
    void set(long long p, S x) {
        assert(lo <= p && p < hi);
        root = set(root, lo, hi, p, x);
    }
    S get(long long p) const {
        assert(lo <= p && p < hi);
        int t = root;
        long long a = lo, b = hi;
        while (t != -1) {
            if (nodes[t].idx == p) return nodes[t].val;
            long long c = mid(a, b);
            if (p < c) {
                t = nodes[t].l, b = c;
            } else {
                t = nodes[t].r, a = c;
            }
        }
        return M::e();
    }
    S prod(long long l, long long r) const {
        assert(lo <= l && l <= r && r <= hi);
        return prod(root, lo, hi, l, r);
    }
    S all_prod() const {
        return root == -1 ? M::e() : nodes[root].prod;
    }
    template <bool (*f)(S)> long long max_right(long long l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> long long max_right(long long l, F f) const {
        assert(lo <= l && l <= hi);
        S product = M::e();
        assert(f(product));
        return max_right(root, lo, hi, l, f, product);
    }
    template <bool (*f)(S)> long long min_left(long long r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> long long min_left(long long r, F f) const {
        assert(lo <= r && r <= hi);
        S product = M::e();
        assert(f(product));
        return min_left(root, lo, hi, r, f, product);
    }

private:
    struct node {
        long long idx;
        S val, prod;
        int l = -1, r = -1;
    };
    long long lo, hi;
    int root = -1;
    std::vector<node> nodes;
    static long long mid(long long a, long long b) {
        return a + (long long)(((unsigned long long)b - (unsigned long long)a) / 2);
    }
    void update(int t) {
        node& v = nodes[t];
        S res = v.l == -1 ? v.val : M::op(nodes[v.l].prod, v.val);
        v.prod = v.r == -1 ? res : M::op(res, nodes[v.r].prod);
    }
    int set(int t, long long a, long long b, long long p, S x) {
        if (t == -1) {
            nodes.push_back({p, x, x});
            return int(nodes.size()) - 1;
        }
        if (nodes[t].idx == p) {
            nodes[t].val = x;
            update(t);
            return t;
        }
        long long c = mid(a, b);
        if (p < c) {
            if (nodes[t].idx < p) std::swap(nodes[t].idx, p), std::swap(nodes[t].val, x);
            int child = set(nodes[t].l, a, c, p, x);
            nodes[t].l = child;
        } else {
            if (p < nodes[t].idx) std::swap(nodes[t].idx, p), std::swap(nodes[t].val, x);
            int child = set(nodes[t].r, c, b, p, x);
            nodes[t].r = child;
        }
        update(t);
        return t;
    }
    S prod(int t, long long a, long long b, long long l, long long r) const {
        if (t == -1 || b <= l || r <= a) return M::e();
        const node& v = nodes[t];
        if (l <= a && b <= r) return v.prod;
        long long c = mid(a, b);
        S res = prod(v.l, a, c, l, r);
        if (l <= v.idx && v.idx < r) res = M::op(res, v.val);
        return M::op(res, prod(v.r, c, b, l, r));
    }
    template <class F>
    long long max_right(int t, long long a, long long b, long long l, const F& f, S& product) const {
        if (t == -1 || b <= l) return hi;
        const node& v = nodes[t];
        if (l <= a && f(M::op(product, v.prod))) {
            product = M::op(product, v.prod);
            return hi;
        }
        long long c = mid(a, b);
        long long res = max_right(v.l, a, c, l, f, product);
        if (res != hi) return res;
        if (l <= v.idx) {
            product = M::op(product, v.val);
            if (!f(product)) return v.idx;
        }
        return max_right(v.r, c, b, l, f, product);
    }
    template <class F>
    long long min_left(int t, long long a, long long b, long long r, const F& f, S& product) const {
        if (t == -1 || r <= a) return lo;
        const node& v = nodes[t];
        if (b <= r && f(M::op(v.prod, product))) {
            product = M::op(v.prod, product);
            return lo;
        }
        long long c = mid(a, b);
        long long res = min_left(v.r, c, b, r, f, product);
        if (res != lo) return res;
        if (v.idx < r) {
            product = M::op(v.val, product);
            if (!f(product)) return v.idx + 1;
        }
        return min_left(v.l, a, c, r, f, product);
    }
};
