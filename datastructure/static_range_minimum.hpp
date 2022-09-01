#pragma once
#include <vector>
struct StaticRMQ {
public:
    void init(const std::vector<std::pair<int, int>>& _v) {
        _n = int(_v.size()), d.resize(_n), ceil_log2.resize(_n + 1);
        ceil_log2[0] = 0;
        ceil_log2[1] = 0;
        for (int i = 2; i <= _n; i++) ceil_log2[i] = ceil_log2[i >> 1] + 1;
        for (int i = 0; i < _n; i++) {
            d[i].resize(ceil_log2[_n] + 1);
            d[i][0] = _v[i];
        }
        for (int b = 0; b < ceil_log2[_n]; b++) {
            for (int i = 0; i < _n; i++) {
                if (i + (1 << (b + 1)) > _n) break;
                d[i][b + 1] = std::min(d[i][b], d[i + (1 << b)][b]);
            }
        }
    }
    std::pair<int, int> prod(int l, int r) {
        if (!(l < r)) return PINF;
        int b = ceil_log2[r - l];
        return std::min(d[l][b], d[r - (1 << b)][b]);
    }

private:
    int _n;
    std::vector<std::vector<std::pair<int, int>>> d;
    std::vector<int> ceil_log2;
    const std::pair<int, int> PINF = {1 << 30, 1 << 30};
};
