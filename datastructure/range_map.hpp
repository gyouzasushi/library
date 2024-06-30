#pragma once
#include <map>
#include <vector>
template <typename T, typename S>
struct range_map {
public:
    range_map(bool merge_adjacent = true) : _merge_adjacent(merge_adjacent) {
    }
    typename std::map<T, std::pair<T, S>>::const_iterator get(T p) const {
        auto it = values.upper_bound(p);
        if (it == values.begin()) return values.end();
        if (std::prev(it)->second.first < p) return values.end();
        return std::prev(it);
    }
    typename std::map<T, std::pair<T, S>>::const_iterator get(
        std::pair<T, T> range) const {
        auto [l, r] = range;
        auto it = get(l);
        if (it == values.end()) return values.end();
        if (it->second.first < r) return values.end();
        return it;
    }
    void set(std::pair<T, T> range, S x) {
        set(range, x, [](T, T, S) {}, [](T, T, S) {});
    }
    template <class op_insert, class op_erase>
    void set(std::pair<T, T> range, S x, const op_insert &f,
             const op_erase &g) {
        auto [l, r] = range;
        auto it_l = values.upper_bound(l);
        if (it_l != values.begin() &&
            l - T(_merge_adjacent) <= std::prev(it_l)->second.first) {
            it_l--;
        }
        auto it_r = values.upper_bound(r + T(_merge_adjacent));
        std::vector<std::tuple<T, T, S>> restore;
        restore.reserve(3);
        if (it_l != values.end() && it_l->first < l) {
            if (it_l->second.second != x) {
                restore.emplace_back(it_l->first, l - 1, it_l->second.second);
            } else {
                l = it_l->first;
            }
        }
        if (it_l != it_r && r < std::prev(it_r)->second.first) {
            if (std::prev(it_r)->second.second != x) {
                restore.emplace_back(r + 1, std::prev(it_r)->second.first,
                                     std::prev(it_r)->second.second);
            } else {
                r = std::prev(it_r)->second.first;
            }
        }
        restore.emplace_back(l, r, x);
        for (auto it = it_l; it != it_r; it = values.erase(it)) {
            g(it->first, it->second.first, it->second.second);
        }
        for (auto [l, r, x] : restore) {
            values[l] = {r, x};
            f(l, r, x);
        }
    }
    typename std::map<std::pair<T, T>, S>::const_iterator begin() const {
        return values.begin();
    }
    typename std::map<std::pair<T, T>, S>::const_iterator end() const {
        return values.end();
    }

protected:
    std::map<T, std::pair<T, S>> values;
    bool _merge_adjacent;
};
