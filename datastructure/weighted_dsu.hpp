#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

#include "algebra/concept.hpp"

// potential p[v] of each vertex; diff(a, b) = op(inv(p[a]), p[b])
template <group G> struct weighted_dsu {
public:
    using S = typename G::S;
    weighted_dsu() : weighted_dsu(0) {
    }
    explicit weighted_dsu(int n) : _n(n), parent_or_size(n, -1), pot(n, G::e()) {
    }
    // make diff(a, b) == w; returns false if it contradicts the existing constraints
    bool merge(int a, int b, S w) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return diff(a, b) == w;
        // p[y] relative to x: op(inv(p[a]), op(p[y], p[b])) == w
        S py = G::op(G::op(pot[a], w), G::inv(pot[b]));
        if (-parent_or_size[x] < -parent_or_size[y]) {
            std::swap(x, y);
            py = G::inv(py);
        }
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        pot[y] = py;
        return true;
    }
    S diff(int a, int b) {
        assert(same(a, b));
        return G::op(G::inv(pot[a]), pot[b]);
    }
    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }
    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        int p = parent_or_size[a];
        int r = leader(p);
        if (p != r) pot[a] = G::op(pot[p], pot[a]);
        return parent_or_size[a] = r;
    }
    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }
    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) result[i].reserve(group_size[i]);
        for (int i = 0; i < _n; i++) result[leader_buf[i]].push_back(i);
        result.erase(std::ranges::remove_if(result, [](const std::vector<int>& v) { return v.empty(); }).begin(),
                     result.end());
        return result;
    }

private:
    int _n;
    std::vector<int> parent_or_size;
    std::vector<S> pot;  // relative to parent
};
