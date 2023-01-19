#pragma once
#include "range_map.hpp"
template <typename T>
struct range_set : range_map<T, bool> {
    using Base = range_map<T, bool>;
    using Base::range_map;
    void insert(T l, T r) {
        Base::insert(l, r, true);
    }
    template <class op_erase, class op_insert>
    void insert(T l, T r, const op_erase &f, const op_insert &g) {
        Base::insert(l, r, true, f, g);
    }
    std::vector<std::pair<T, T>> ranges() {
        std::vector<std::pair<T, T>> ret;
        for (auto it = Base::mp.begin(); it != Base::mp.end(); it++) {
            ret.emplace_back(it->first, it->second.first);
        }
        return ret;
    }
};