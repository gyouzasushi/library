#pragma once
#include <algorithm>
#include <bit>
#include <cassert>
#include <vector>

#include "datastructure/sparse_table.hpp"
#include "monoid/argmin.hpp"
struct plus_minus_one_rmq {
public:
    plus_minus_one_rmq() : _n(0), s(1), B(0) {
    }
    explicit plus_minus_one_rmq(const std::vector<int>& a) : _n(int(a.size())), v(a) {
        s = std::max(1, (std::bit_width((unsigned)_n) - 1) / 2);
        B = (_n + s - 1) / s;
        std::vector<monoid_argmin<int>::S> blocks(B);
        pattern.resize(B);
        for (int i = 0; i < _n; i += s) {
            int min_j = i;
            int bit = 0;
            int end = std::min(_n, i + s);
            for (int j = i; j < end; j++) {
                if (v[j] < v[min_j]) min_j = j;
                if (j + 1 < end && v[j] < v[j + 1]) bit |= 1 << (j - i);
            }
            blocks[i / s] = {v[min_j], min_j};
            pattern[i / s] = bit;
        }
        table = sparse_table<monoid_argmin<int>>(blocks);
        lookup.resize(1 << (s - 1));
        for (int bit = 0; bit < (1 << (s - 1)); bit++) {
            lookup[bit].resize(s + 1);
            for (int l = 0; l <= s; l++) {
                lookup[bit][l].assign(s + 1, INF);
                int min_sum = 0, min_i = l, sum = 0;
                for (int r = l + 1; r <= s; r++) {
                    lookup[bit][l][r] = min_i;
                    sum += bit >> (r - 1) & 1 ? 1 : -1;
                    if (sum < min_sum) {
                        min_sum = sum;
                        min_i = r;
                    }
                }
            }
        }
    }
    int prod(int l, int r) const {
        assert(0 <= l && l < r && r <= _n);
        int m1 = (l + s - 1) / s, m2 = r / s;
        int l1 = s * m1, r1 = s * m2;
        if (m2 < m1) return lookup[pattern[m2]][l - r1][r - r1] + r1;
        int ret = INF;
        if (m1 > 0) ret = argmin(ret, lookup[pattern[m1 - 1]][s - (l1 - l)][s] + l1 - s);
        if (m1 < m2) ret = argmin(ret, table.prod(m1, m2).id);
        if (m2 < B) ret = argmin(ret, lookup[pattern[m2]][0][r - r1] + r1);
        return ret;
    }

private:
    static constexpr int INF = 1 << 30;
    int _n, s, B;
    std::vector<int> v, pattern;
    sparse_table<monoid_argmin<int>> table;
    std::vector<std::vector<std::vector<int>>> lookup;
    int argmin(int i, int j) const {
        if (i >= INF) return j;
        if (j >= INF) return i;
        if (v[i] != v[j]) return v[i] < v[j] ? i : j;
        return std::min(i, j);
    }
};
