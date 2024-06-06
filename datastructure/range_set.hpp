#pragma once

#include <map>
template <typename T>
struct range_set {
public:
    range_set(bool merge_adjacent = true) : _merge_adjacent(merge_adjacent) {
    }
    typename std::map<T, T>::const_iterator get(T p) const {
        auto it = ranges.upper_bound(p);
        if (it == ranges.begin()) return ranges.end();
        if (std::prev(it)->second < p) return ranges.end();
        return std::prev(it);
    }
    typename std::map<T, T>::const_iterator get(T l, T r) const {
        auto it = get(l);
        if (it == ranges.end()) return ranges.end();
        if (it->second < r) return ranges.end();
        return it;
    }
    void insert(T l, T r) {
        insert(l, r, [](T, T) {}, [](T, T) {});
    }
    template <class op_insert, class op_erase>
    void insert(T l, T r, const op_insert &f, const op_erase &g) {
        auto it_l = ranges.upper_bound(l);
        auto it_r = ranges.upper_bound(r + T(_merge_adjacent));
        if (it_l != ranges.begin() &&
            l - T(_merge_adjacent) <= std::prev(it_l)->second) {
            it_l--;
        }
        for (auto it = it_l; it != it_r; it = ranges.erase(it)) {
            l = std::min(l, it->first);
            r = std::max(r, it->second);
            g(it->first, it->second);
        }
        ranges[l] = r;
        f(l, r);
    }
    void erase(T l, T r) {
        erase(l, r, [](T, T) {}, [](T, T) {});
    }
    template <class op_insert, class op_erase>
    void erase(T l, T r, const op_insert &f, const op_erase &g) {
        auto it_l = ranges.upper_bound(l);
        auto it_r = ranges.upper_bound(r);
        if (it_l != ranges.begin() && l <= std::prev(it_l)->second) {
            it_l--;
        }
        T nl = std::min(l, it_l->first);
        T nr = std::max(r, std::prev(it_r)->second);
        for (auto it = it_l; it != it_r; it = ranges.erase(it)) {
            g(it->first, it->second);
        }
        if (nl < l) {
            ranges[nl] = l - 1;
            f(nl, l - 1);
        }
        if (r < nr) {
            ranges[r + 1] = nr;
            f(r + 1, nr);
        }
    }
    typename std::map<T, T>::const_iterator begin() const {
        return ranges.begin();
    }
    typename std::map<T, T>::const_iterator end() const {
        return ranges.end();
    }

private:
    std::map<T, T> ranges;
    bool _merge_adjacent;
};