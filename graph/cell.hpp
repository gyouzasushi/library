#pragma once
#include <array>
#include <cassert>
#include <utility>
#include <vector>
struct cell {
public:
    // (dy, dx)
    static constexpr std::array<std::pair<int, int>, 4> delta = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    static constexpr std::array<std::pair<int, int>, 8> delta_8 = {
        {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}}};

    int y, x;
    cell() : y(0), x(0) {
    }
    cell(int y, int x) : y(y), x(x) {
    }
    // 辞書順で i 番目のマス
    explicit cell(int i) {
        assert(_set);
        assert(0 <= i && i < size());
        y = i / width() + _min_y;
        x = i % width() + _min_x;
    }
    static void set_bound(int height, int width) {
        set_bound(0, 0, height - 1, width - 1);
    }
    static void set_bound(int min_y, int min_x, int max_y, int max_x) {
        assert(min_y <= max_y && min_x <= max_x);
        _min_y = min_y;
        _min_x = min_x;
        _max_y = max_y;
        _max_x = max_x;
        _set = true;
    }
    static int height() {
        assert(_set);
        return _max_y - _min_y + 1;
    }
    static int width() {
        assert(_set);
        return _max_x - _min_x + 1;
    }
    static int size() {
        return height() * width();
    }
    static std::vector<cell> cells() {
        assert(_set);
        std::vector<cell> ret;
        ret.reserve(size());
        for (int y = _min_y; y <= _max_y; y++) {
            for (int x = _min_x; x <= _max_x; x++) {
                ret.emplace_back(y, x);
            }
        }
        return ret;
    }
    bool is_valid() const {
        return _min_y <= y && y <= _max_y && _min_x <= x && x <= _max_x;
    }
    operator int() const {
        return (y - _min_y) * width() + (x - _min_x);
    }
    cell operator+(std::pair<int, int> d) const {
        return cell(y + d.first, x + d.second);
    }
    cell operator-(std::pair<int, int> d) const {
        return cell(y - d.first, x - d.second);
    }
    bool operator==(const cell& o) const {
        return y == o.y && x == o.x;
    }
    bool operator!=(const cell& o) const {
        return !(*this == o);
    }

    // 範囲内の近傍を、ヒープを使わずに range-for で回すためのビュー
    template <int K>
    struct neighbor_view {
        std::array<cell, K> a;
        int n;
        const cell* begin() const {
            return a.data();
        }
        const cell* end() const {
            return a.data() + n;
        }
        int size() const {
            return n;
        }
    };
    neighbor_view<4> neighbors() const {
        return collect<4>(delta);
    }
    neighbor_view<8> neighbors_8() const {
        return collect<8>(delta_8);
    }

private:
    static inline bool _set = false;
    static inline int _min_y, _min_x, _max_y, _max_x;
    template <int K>
    neighbor_view<K> collect(const std::array<std::pair<int, int>, K>& ds) const {
        neighbor_view<K> ret;
        ret.n = 0;
        for (auto d : ds) {
            cell v = *this + d;
            if (v.is_valid()) ret.a[ret.n++] = v;
        }
        return ret;
    }
};
