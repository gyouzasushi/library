#pragma once
#include <bit>
#include <cassert>
#include <vector>

#include "algebra/concept.hpp"
template <beats_acted_monoid A> struct segtree_beats {
public:
    using S = typename A::S;
    using F = typename A::F;
    segtree_beats() : segtree_beats(0) {
    }
    explicit segtree_beats(int n) : segtree_beats(std::vector<S>(n, A::e())) {
    }
    explicit segtree_beats(const std::vector<S>& v) : _n(int(v.size())) {
        size = int(std::bit_ceil(unsigned(_n)));
        log = std::countr_zero(unsigned(size));
        d = std::vector<S>(2 * size, A::e());
        lz = std::vector<F>(size, A::id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) update(i);
    }
    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return A::e();
        l += size;
        r += size;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        S sml = A::e(), smr = A::e();
        while (l < r) {
            if (l & 1) sml = A::op(sml, d[l++]);
            if (r & 1) smr = A::op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return A::op(sml, smr);
    }
    S all_prod() const {
        return d[1];
    }
    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = A::mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;
        l += size;
        r += size;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }
        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }
    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(A::e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = A::e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(A::op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(A::op(sm, d[l]))) {
                        sm = A::op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = A::op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }
    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(A::e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = A::e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(A::op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(A::op(d[r], sm))) {
                        sm = A::op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = A::op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;
    void update(int k) {
        d[k] = A::op(d[2 * k], d[2 * k + 1]);
    }
    void all_apply(int k, F f) {
        d[k] = A::mapping(f, d[k]);
        if (k < size) {
            lz[k] = A::composition(f, lz[k]);
            if (d[k].fail) {
                push(k);
                update(k);
            }
        }
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = A::id();
    }
};
