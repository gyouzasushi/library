#pragma once
#include <cassert>
#include <vector>
template <class S, S (*op)(S, S)>
struct SparseTable {
public:
    SparseTable() {
    }
    SparseTable(const std::vector<S>& v)
        : _n(int(v.size())), d(_n), ceil_log2(_n + 1) {
        ceil_log2[0] = 0;
        ceil_log2[1] = 0;
        for (int i = 2; i <= _n; i++) ceil_log2[i] = ceil_log2[i >> 1] + 1;
        for (int i = 0; i < _n; i++) {
            d[i].resize(ceil_log2[_n] + 1);
            d[i][0] = v[i];
        }
        for (int b = 0; b < ceil_log2[_n]; b++) {
            for (int i = 0; i < _n; i++) {
                if (i + (1 << (b + 1)) > _n) break;
                d[i][b + 1] = op(d[i][b], d[i + (1 << b)][b]);
            }
        }
    }
    S prod(int l, int r) {
        assert(r - l > 0);
        int b = ceil_log2[r - l];
        return op(d[l][b], d[r - (1 << b)][b]);
    }

private:
    int _n;
    std::vector<std::vector<S>> d;
    std::vector<int> ceil_log2;
};
