#pragma once
#include <cmath>
#include <vector>

#include "static_range_minimum.hpp"
struct PlusMinusOneRMQ {
public:
    void init(const std::vector<int>& _v) {
        _n = int(_v.size());
        v = _v;
        s = std::max(1, int(std::log2(_n) / 2));
        B = (_n + s - 1) / s;
        std::vector<std::pair<int, int>> _spt(B);
        pattern.resize(B);
        for (int i = 0; i < _n; i += s) {
            int min_j = i;
            int bit = 0;
            for (int j = i; j < std::min(_n, i + s); j++) {
                if (v[j] < v[min_j]) min_j = j;
                if (j + 1 < std::min(_n, i + s) && v[j] < v[j + 1])
                    bit |= 1 << (j - i);
            }
            _spt[i / s] = {v[min_j], min_j};
            pattern[i / s] = bit;
        }
        sparse_table.init(_spt);

        lookup_table.resize(1 << (s - 1));
        for (int bit = 0; bit < (1 << (s - 1)); bit++) {
            lookup_table[bit].resize(s + 1);
            for (int l = 0; l <= s; l++) {
                lookup_table[bit][l].resize(s + 1, INF);
                int min_ = 0;
                int min_i = l;
                int sum = 0;
                for (int r = l + 1; r <= s; r++) {
                    lookup_table[bit][l][r] = min_i;
                    sum += bit >> (r - 1) & 1 ? 1 : -1;
                    if (sum < min_) {
                        min_ = sum;
                        min_i = r;
                    }
                }
            }
        }
    }
    int prod(int l, int r) {
        int m1 = (l + s - 1) / s;
        int m2 = r / s;
        int l1 = s * m1;
        int r1 = s * m2;
        if (m2 < m1) {
            return lookup_table[pattern[m2]][l - r1][r - r1] + r1;
        }
        int ret = INF;
        if (m1 > 0) {
            ret = argmin(
                ret, lookup_table[pattern[m1 - 1]][s - (l1 - l)][s] + l1 - s);
        }
        ret = argmin(ret, sparse_table.prod(m1, m2).second);
        if (m2 < B) {
            ret = argmin(ret, lookup_table[pattern[m2]][0][r - r1] + r1);
        }
        return ret;
    }

private:
    int _n;
    int s, B;
    StaticRMQ sparse_table;
    std::vector<std::vector<std::vector<int>>> lookup_table;
    std::vector<int> pattern, v;
    const int INF = 1 << 30;
    int argmin(int i, int j) {
        if (i >= INF || j >= INF || v[i] == v[j]) return std::min(i, j);
        return v[i] < v[j] ? i : j;
    }
};
