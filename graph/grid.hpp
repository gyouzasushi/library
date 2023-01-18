#pragma once
#include <vector>
struct grid {
public:
    int y, x;
    grid() {
    }
    grid(int y, int x) : y(y), x(x) {
    }
    static void set_bound(int height, int width) {
        _min_y = 0;
        _min_x = 0;
        _max_y = height - 1;
        _max_x = width - 1;
    }
    static void set_bound(int min_y, int min_x, int max_y, int max_x) {
        _min_y = min_y;
        _min_x = min_x;
        _max_y = max_y;
        _max_x = max_x;
    }
    static std::vector<grid> grids() {
        std::vector<grid> ret;
        for (int y = _min_y; y <= _max_y; y++) {
            for (int x = _min_x; x <= _max_x; x++) {
                ret.emplace_back(y, x);
            }
        }
        return ret;
    }
    static grid from(int i) {
        return grid(i / (_max_x - _min_x + 1) + _min_y,
                    i % (_max_x - _min_x + 1) + _min_x);
    }
    bool is_valid() {
        return _min_y <= y && y <= _max_y && _min_x <= x && x <= _max_x;
    }
    std::vector<grid> neighbors() {
        std::vector<grid> ret;
        for (auto [dy, dx] : grid::delta) {
            if (grid(y + dy, x + dx).is_valid()) {
                ret.emplace_back(y + dy, x + dx);
            }
        }
        return ret;
    }
    std::vector<grid> neighbors_8() {
        std::vector<grid> ret;
        for (auto [dy, dx] : grid::delta_8) {
            if (grid(y + dy, x + dx).is_valid()) {
                ret.emplace_back(y + dy, x + dx);
            }
        }
        return ret;
    }
    operator int() const {
        return (y - _min_y) * (_max_x - _min_x + 1) + (x - _min_x);
    }

private:
    static inline int _min_y, _min_x, _max_y, _max_x;
    static inline const std::vector<std::pair<int, int>> delta = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    static inline const std::vector<std::pair<int, int>> delta_8 = {
        {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
};