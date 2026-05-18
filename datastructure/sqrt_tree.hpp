#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
template <class S, S (*op)(S, S)>
struct sqrt_tree {
public:
    sqrt_tree() {
    }
    sqrt_tree(const std::vector<S>& a) : _n(int(a.size())) {
        if (_n == 0) return;
        _lg = 0;
        while ((1 << _lg) < _n) _lg++;
        v = a;

        clz.assign(1 << _lg, 0);
        for (int i = 1; i < (1 << _lg); i++) {
            clz[i] = clz[i >> 1] + 1;
        }

        on_layer.assign(_lg + 1, 0);
        int tlg = _lg;
        while (tlg > 1) {
            on_layer[tlg] = int(layers.size());
            layers.push_back(tlg);
            tlg = (tlg + 1) >> 1;
        }
        for (int i = _lg - 1; i >= 0; i--) {
            on_layer[i] = std::max(on_layer[i], on_layer[i + 1]);
        }

        if (layers.empty()) return;

        int between_layers = std::max(0, int(layers.size()) - 1);
        int b_sz_log = (_lg + 1) >> 1;
        int b_sz = 1 << b_sz_log;
        index_sz = (_n + b_sz - 1) >> b_sz_log;
        v.resize(_n + index_sz);
        pref.assign(layers.size(), std::vector<S>(_n + index_sz));
        suf.assign(layers.size(), std::vector<S>(_n + index_sz));
        between.assign(between_layers, std::vector<S>((1 << _lg) + b_sz));
        build(0, 0, _n, 0);
    }

    S prod(int l, int r) {
        assert(0 <= l && l < r && r <= _n);
        return query(l, r - 1, 0, 0);
    }

private:
    int _n = 0, _lg = 0, index_sz = 0;
    std::vector<S> v;
    std::vector<int> clz, layers, on_layer;
    std::vector<std::vector<S>> pref, suf, between;

    void build_block(int layer, int l, int r) {
        pref[layer][l] = v[l];
        for (int i = l + 1; i < r; i++) {
            pref[layer][i] = op(pref[layer][i - 1], v[i]);
        }
        suf[layer][r - 1] = v[r - 1];
        for (int i = r - 2; i >= l; i--) {
            suf[layer][i] = op(v[i], suf[layer][i + 1]);
        }
    }

    void build_between(int layer, int l_bound, int r_bound, int between_offs) {
        int b_sz_log = (layers[layer] + 1) >> 1;
        int b_cnt_log = layers[layer] >> 1;
        int b_sz = 1 << b_sz_log;
        int b_cnt = (r_bound - l_bound + b_sz - 1) >> b_sz_log;
        for (int i = 0; i < b_cnt; i++) {
            S ans = suf[layer][l_bound + (i << b_sz_log)];
            between[layer - 1][between_offs + l_bound + (i << b_cnt_log) + i] = ans;
            for (int j = i + 1; j < b_cnt; j++) {
                S add = suf[layer][l_bound + (j << b_sz_log)];
                ans = op(ans, add);
                between[layer - 1][between_offs + l_bound + (i << b_cnt_log) + j] = ans;
            }
        }
    }

    void build_between_zero() {
        int b_sz_log = (_lg + 1) >> 1;
        for (int i = 0; i < index_sz; i++) {
            v[_n + i] = suf[0][i << b_sz_log];
        }
        build(1, _n, _n + index_sz, (1 << _lg) - _n);
    }

    void build(int layer, int l_bound, int r_bound, int between_offs) {
        if (layer >= int(layers.size())) return;
        int b_sz = 1 << ((layers[layer] + 1) >> 1);
        for (int l = l_bound; l < r_bound; l += b_sz) {
            int r = std::min(l + b_sz, r_bound);
            build_block(layer, l, r);
            build(layer + 1, l, r, between_offs);
        }
        if (layer == 0) {
            build_between_zero();
        } else {
            build_between(layer, l_bound, r_bound, between_offs);
        }
    }

    S query(int l, int r, int between_offs, int base) {
        if (l == r) return v[l];
        if (l + 1 == r) return op(v[l], v[r]);
        int layer = on_layer[clz[(l - base) ^ (r - base)]];
        int b_sz_log = (layers[layer] + 1) >> 1;
        int b_cnt_log = layers[layer] >> 1;
        int l_bound = (((l - base) >> layers[layer]) << layers[layer]) + base;
        int l_block = ((l - l_bound) >> b_sz_log) + 1;
        int r_block = ((r - l_bound) >> b_sz_log) - 1;
        S ans = suf[layer][l];
        if (l_block <= r_block) {
            S add = (layer == 0)
                        ? query(_n + l_block, _n + r_block, (1 << _lg) - _n, _n)
                        : between[layer - 1][between_offs + l_bound + (l_block << b_cnt_log) + r_block];
            ans = op(ans, add);
        }
        ans = op(ans, pref[layer][r]);
        return ans;
    }
};
