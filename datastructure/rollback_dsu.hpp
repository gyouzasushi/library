#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
struct rollback_dsu {
public:
    rollback_dsu() : rollback_dsu(0) {
    }
    explicit rollback_dsu(int n) : _n(n), parent_or_size(n, -1) {
    }
    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) {
            history.emplace_back(-1, -1);
            return x;
        }
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        history.emplace_back(y, parent_or_size[y]);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }
    void undo() {
        assert(!history.empty());
        auto [y, s] = history.back();
        history.pop_back();
        if (y == -1) return;
        parent_or_size[parent_or_size[y]] -= s;
        parent_or_size[y] = s;
    }
    int time() const {
        return int(history.size());
    }
    void rollback(int t) {
        assert(0 <= t && t <= time());
        while (time() > t) undo();
    }
    bool same(int a, int b) const {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }
    int leader(int a) const {
        assert(0 <= a && a < _n);
        while (parent_or_size[a] >= 0) a = parent_or_size[a];
        return a;
    }
    int size(int a) const {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }
    std::vector<std::vector<int>> groups() const {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) result[i].reserve(group_size[i]);
        for (int i = 0; i < _n; i++) result[leader_buf[i]].push_back(i);
        result.erase(std::remove_if(result.begin(), result.end(),
                                    [&](const std::vector<int>& v) { return v.empty(); }),
                     result.end());
        return result;
    }

private:
    int _n;
    std::vector<int> parent_or_size;
    std::vector<std::pair<int, int>> history;  // (attached leader, its old parent_or_size)
};
