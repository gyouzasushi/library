#pragma once
#include <algorithm>
#include <cassert>
#include <map>
#include <optional>
#include <vector>
template <typename T, typename U>
struct range_map {
public:
    range_map(bool merge_adjacent_segment = true)
        : merge_adjacent_segment(merge_adjacent_segment) {
    }
    void clear() {
        mp.clear();
    }
    size_t size() {
        return mp.size();
    }
    std::optional<std::pair<T, T>> contains(T l, T r) {
        assert(l <= r);
        auto it = mp.upper_bound(l);
        if (it == mp.begin()) return std::nullopt;
        it--;
        if (it->first > l) return std::nullopt;
        if (r > it->second.first) return std::nullopt;
        return std::make_pair(it->first, it->second.first);
    }
    std::optional<std::pair<T, T>> contains(T p) {
        return is_covered(p, p);
    }
    void insert(T l, T r, U x) {
        assert(l <= r);
        auto it_l = mp.upper_bound(l);
        auto it_r = mp.upper_bound(r + int(merge_adjacent_segment));
        if (it_l != mp.begin()) {
            if (std::prev(it_l)->second.first >=
                l - int(merge_adjacent_segment)) {
                it_l--;
            }
        };
        bool has_value_0 = false, has_value_1 = false;
        T l_0, l_1, r_1, r_2;
        U x_0, x_1, x_2;
        if (it_l != mp.end()) {
            has_value_0 = true;
            l_0 = it_l->first;
            x_0 = it_l->second.second;
        }
        {
            l_1 = l, r_1 = r;
            x_1 = x;
        }
        if (it_r != mp.begin()) {
            has_value_1 = true;
            r_2 = std::prev(it_r)->second.first;
            x_2 = std::prev(it_r)->second.second;
        }
        for (auto it = it_l; it != it_r; it = mp.erase(it)) {
        }
        if (has_value_0 && x_0 == x_1) {
            l_1 = std::min(l_0, l_1);
        } else if (has_value_0 && l_0 < l_1) {
            mp[l_0] = {l_1 - 1, x_0};
        }
        if (has_value_1 && x_1 == x_2) {
            r_1 = std::max(r_1, r_2);
        } else if (has_value_1 && r_1 < r_2) {
            mp[r_1 + 1] = {r_2, x_2};
        }
        mp[l_1] = {r_1, x_1};
    }
    template <class op_erase, class op_insert>
    void insert(T l, T r, U x, const op_erase &f, const op_insert &g) {
        assert(l <= r);
        auto it_l = mp.upper_bound(l);
        auto it_r = mp.upper_bound(r + int(merge_adjacent_segment));
        if (it_l != mp.begin()) {
            if (std::prev(it_l)->second.first >=
                l - int(merge_adjacent_segment)) {
                it_l--;
            }
        };
        bool has_value_0 = false, has_value_1 = false;
        T l_0, l_1, r_1, r_2;
        U x_0, x_1, x_2;
        if (it_l != mp.end()) {
            has_value_0 = true;
            l_0 = it_l->first;
            x_0 = it_l->second.second;
        }
        {
            l_1 = l, r_1 = r;
            x_1 = x;
        }
        if (it_r != mp.begin()) {
            has_value_1 = true;
            r_2 = std::prev(it_r)->second.first;
            x_2 = std::prev(it_r)->second.second;
        }
        for (auto it = it_l; it != it_r; it = mp.erase(it)) {
            f(it->first, it->second.first, it->second.second);
        }
        if (has_value_0 && x_0 == x_1) {
            l_1 = std::min(l_0, l_1);
        } else if (has_value_0 && l_0 < l_1) {
            mp[l_0] = {l_1 - 1, x_0};
            g(l_0, l_1 - 1, x_0);
        }
        if (has_value_1 && x_1 == x_2) {
            r_1 = std::max(r_1, r_2);
        } else if (has_value_1 && r_1 < r_2) {
            mp[r_1 + 1] = {r_2, x_2};
            g(r_1 + 1, r_2, x_2);
        }
        mp[l_1] = {r_1, x_1};
        g(l_1, r_1, x_1);
    }
    void erase(T l, T r) {
        assert(l <= r);
        auto it_l = mp.upper_bound(l);
        auto it_r = mp.upper_bound(r);
        if (it_l != mp.begin()) {
            if (std::prev(it_l)->second.first >= l) {
                it_l--;
            }
        }
        bool has_value_0 = false, has_value_1 = false;
        T l_0, l_1, r_1, r_2;
        U x_0, x_2;
        if (it_l != mp.end()) {
            has_value_0 = true;
            l_0 = it_l->first;
            x_0 = it_l->second.second;
        }
        {
            l_1 = l;
            r_1 = r;
        }
        if (it_r != mp.begin()) {
            has_value_1 = true;
            r_2 = std::prev(it_r)->second.first;
            x_2 = std::prev(it_r)->second.second;
        }
        for (auto it = it_l; it != it_r; it = mp.erase(it)) {
        }
        if (has_value_0 && l_0 < l_1) {
            mp[l_0] = {l_1 - 1, x_0};
        }
        if (has_value_1 && r_1 < r_2) {
            mp[r_1 + 1] = {r_2, x_2};
        }
    }
    template <class op_erase, class op_insert>
    void erase(T l, T r, const op_erase &f, const op_insert &g) {
        assert(l <= r);
        auto it_l = mp.upper_bound(l);
        auto it_r = mp.upper_bound(r);
        if (it_l != mp.begin()) {
            if (std::prev(it_l)->second.first >= l) {
                it_l--;
            }
        }
        bool has_value_0 = false, has_value_1 = false;
        T l_0, l_1, r_1, r_2;
        U x_0, x_2;
        if (it_l != mp.end()) {
            has_value_0 = true;
            l_0 = it_l->first;
            x_0 = it_l->second.second;
        }
        {
            l_1 = l;
            r_1 = r;
        }
        if (it_r != mp.begin()) {
            has_value_1 = true;
            r_2 = std::prev(it_r)->second.first;
            x_2 = std::prev(it_r)->second.second;
        }
        for (auto it = it_l; it != it_r; it = mp.erase(it)) {
            f(it->first, it->second.first, it->second.second);
        }
        if (has_value_0 && l_0 < l_1) {
            mp[l_0] = {l_1 - 1, x_0};
            g(l_0, l_1 - 1, x_0);
        }
        if (has_value_1 && r_1 < r_2) {
            mp[r_1 + 1] = {r_2, x_2};
            g(r_1 + 1, r_2, x_2);
        }
    }
    std::vector<std::tuple<T, T, U>> ranges() {
        std::vector<std::tuple<T, T, U>> ret;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            ret.emplace_back(it->first, it->second.first, it->second.second);
        }
        return ret;
    }

protected:
    bool merge_adjacent_segment;
    std::map<T, std::pair<T, U>> mp;
};
