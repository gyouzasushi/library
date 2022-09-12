#include <vector>
template <class F, F (*composition)(F, F), F (*id)()>
struct DualSegmentTree {
public:
    DualSegmentTree() {
    }
    DualSegmentTree(int n, bool is_commutative = false)
        : is_commutative(is_commutative) {
        size = 1;
        height = 0;
        while (size < n) size <<= 1, height++;
        lz.assign(2 * size, id());
    }
    void apply(int l, int r, const F &x) {
        l += size;
        r += size - 1;
        if (!is_commutative) thrust(l);
        if (!is_commutative) thrust(r);
        r++;
        while (l < r) {
            if (l & 1) lz[l] = composition(lz[l], x), ++l;
            if (r & 1) --r, lz[r] = composition(lz[r], x);
            l >>= 1, r >>= 1;
        }
    }
    F get(int p) {
        if (is_commutative) {
            F ret = id();
            p += size;
            while (p > 0) {
                ret = composition(ret, lz[p]);
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
    bool is_commutative;
    inline void propagate(int k) {
        if (lz[k] != id()) {
            lz[2 * k + 0] = composition(lz[2 * k + 0], lz[k]);
            lz[2 * k + 1] = composition(lz[2 * k + 1], lz[k]);
            lz[k] = id();
        }
    }
    inline void thrust(int k) {
        for (int i = height; i > 0; i--) propagate(k >> i);
    }
};