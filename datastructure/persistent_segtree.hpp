#pragma once
#include <cassert>
#include <vector>

#include "algebra/concept.hpp"
template <monoid M> struct persistent_segtree {
public:
    using S = typename M::S;
    explicit persistent_segtree(int n) : persistent_segtree(std::vector<S>(n, M::e())) {
    }
    explicit persistent_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        nodes.reserve(2 * _n);
        if (_n > 0) build(v, 0, _n);
    }
    int size() const {
        return _n;
    }
    S get(int root, int p) const {
        assert(0 <= p && p < _n);
        int cur = root, l = 0, r = _n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (p < mid) {
                cur = nodes[cur].l, r = mid;
            } else {
                cur = nodes[cur].r, l = mid;
            }
        }
        return nodes[cur].val;
    }
    int set(int root, int p, const S& x) {
        assert(0 <= p && p < _n);
        int res = copy(root);
        int cur = res, l = 0, r = _n;
        path.clear();
        while (r - l > 1) {
            path.push_back(cur);
            int mid = (l + r) / 2;
            if (p < mid) {
                int nxt = copy(nodes[cur].l);
                nodes[cur].l = nxt;
                cur = nxt, r = mid;
            } else {
                int nxt = copy(nodes[cur].r);
                nodes[cur].r = nxt;
                cur = nxt, l = mid;
            }
        }
        nodes[cur].val = x;
        for (int i = int(path.size()) - 1; i >= 0; i--) {
            node& v = nodes[path[i]];
            v.val = M::op(nodes[v.l].val, nodes[v.r].val);
        }
        return res;
    }
    S prod(int root, int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        return prod(root, 0, _n, l, r);
    }
    S all_prod(int root) const {
        return _n == 0 ? M::e() : nodes[root].val;
    }

private:
    struct node {
        int l, r;
        S val;
    };
    int _n;
    std::vector<node> nodes;
    std::vector<int> path;
    int copy(int v) {
        nodes.push_back(nodes[v]);
        return int(nodes.size()) - 1;
    }
    int build(const std::vector<S>& v, int l, int r) {
        if (r - l == 1) {
            nodes.push_back({-1, -1, v[l]});
            return int(nodes.size()) - 1;
        }
        int mid = (l + r) / 2;
        int res = int(nodes.size());
        nodes.push_back({-1, -1, M::e()});
        int lc = build(v, l, mid);
        int rc = build(v, mid, r);
        nodes[res].l = lc, nodes[res].r = rc;
        nodes[res].val = M::op(nodes[lc].val, nodes[rc].val);
        return res;
    }
    S prod(int cur, int nl, int nr, int l, int r) const {
        if (r <= nl || nr <= l) return M::e();
        if (l <= nl && nr <= r) return nodes[cur].val;
        int mid = (nl + nr) / 2;
        return M::op(prod(nodes[cur].l, nl, mid, l, r), prod(nodes[cur].r, mid, nr, l, r));
    }
};
