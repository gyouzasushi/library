#pragma once
#include <cassert>
#include <vector>
template <class T> struct persistent_array {
public:
    explicit persistent_array(int n) : persistent_array(std::vector<T>(n)) {
    }
    explicit persistent_array(const std::vector<T>& v) : _n(int(v.size())) {
        nodes.reserve(2 * _n);
        if (_n > 0) build(v, 0, _n);
    }
    int size() const {
        return _n;
    }
    T get(int root, int p) const {
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
    int set(int root, int p, const T& x) {
        assert(0 <= p && p < _n);
        int res = copy(root);
        int cur = res, l = 0, r = _n;
        while (r - l > 1) {
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
        return res;
    }

private:
    struct node {
        int l, r;
        T val;
    };
    int _n;
    std::vector<node> nodes;
    int copy(int v) {
        nodes.push_back(nodes[v]);
        return int(nodes.size()) - 1;
    }
    int build(const std::vector<T>& v, int l, int r) {
        if (r - l == 1) {
            nodes.push_back({-1, -1, v[l]});
            return int(nodes.size()) - 1;
        }
        int mid = (l + r) / 2;
        int res = int(nodes.size());
        nodes.push_back({-1, -1, T()});
        int lc = build(v, l, mid);
        int rc = build(v, mid, r);
        nodes[res].l = lc, nodes[res].r = rc;
        return res;
    }
};
