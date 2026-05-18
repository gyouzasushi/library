#include <vector>
template <class F, F (*composition)(F, F), F (*id)(), bool is_commutative = false>
struct dual_segtree {
public:
    dual_segtree() {
    }
    dual_segtree(int n) {
        size = 1;
        height = 0;
        while (size < n) size <<= 1, height++;
        lz.assign(2 * size, id());
    }
    void set(int p, const F &x) {
        p += size;
        thrust(p);
        lz[p] = x;
    }
    void apply(int l, int r, const F &f) {
        l += size;
        r += size - 1;
        if constexpr (!is_commutative) {
            thrust(l);
            thrust(r);
        }
        r++;
        while (l < r) {
            if (l & 1) lz[l] = composition(f, lz[l]), ++l;
            if (r & 1) --r, lz[r] = composition(f, lz[r]);
            l >>= 1, r >>= 1;
        }
    }
    F get(int p) {
        if constexpr (is_commutative) {
            F ret = id();
            p += size;
            while (p > 0) {
                ret = composition(lz[p], ret);
                p >>= 1;
            }
            return ret;
        } else {
            thrust(p += size);
            return lz[p];
        }
    }

private:
    int size, height;
    std::vector<F> lz;
    inline void propagate(int k) {
        lz[2 * k + 0] = composition(lz[k], lz[2 * k + 0]);
        lz[2 * k + 1] = composition(lz[k], lz[2 * k + 1]);
        lz[k] = id();
    }
    inline void thrust(int k) {
        for (int i = height; i > 0; i--) propagate(k >> i);
    }
};