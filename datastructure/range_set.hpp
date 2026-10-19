#pragma once
#include <cassert>
#include <map>
template <class T>
struct range_set {
public:
    using iterator = typename std::map<T, T>::const_iterator;
    range_set() {
    }
    // p を含む区間。無ければ end()
    iterator find(T p) const {
        auto it = ranges.upper_bound(p);
        if (it == ranges.begin()) return ranges.end();
        it--;
        if (it->second <= p) return ranges.end();
        return it;
    }
    bool contains(T p) const {
        return find(p) != ranges.end();
    }
    // [l, r) が 1 つの区間に含まれるか
    bool covers(T l, T r) const {
        assert(l < r);
        auto it = find(l);
        return it != ranges.end() && r <= it->second;
    }
    // x 以上で含まれない最小の値（整数向け）
    T mex(T x) const {
        auto it = find(x);
        return it == ranges.end() ? x : it->second;
    }
    void insert(T l, T r) {
        insert(l, r, [](T, T) {}, [](T, T) {});
    }
    // f: 追加された区間ごとに呼ぶ, g: 削除された区間ごとに呼ぶ
    template <class F, class G>
    void insert(T l, T r, const F& f, const G& g) {
        assert(l < r);
        auto it = ranges.upper_bound(l);
        if (it != ranges.begin() && l <= std::prev(it)->second) it--;
        while (it != ranges.end() && it->first <= r) {
            l = std::min(l, it->first);
            r = std::max(r, it->second);
            g(it->first, it->second);
            it = ranges.erase(it);
        }
        ranges[l] = r;
        f(l, r);
    }
    void erase(T l, T r) {
        erase(l, r, [](T, T) {}, [](T, T) {});
    }
    template <class F, class G>
    void erase(T l, T r, const F& f, const G& g) {
        assert(l < r);
        auto it = ranges.upper_bound(l);
        if (it != ranges.begin() && l < std::prev(it)->second) it--;
        while (it != ranges.end() && it->first < r) {
            T a = it->first, b = it->second;
            g(a, b);
            it = ranges.erase(it);
            if (a < l) {
                ranges[a] = l;
                f(a, l);
            }
            if (r < b) {
                ranges[r] = b;
                f(r, b);
            }
        }
    }
    int size() const {
        return int(ranges.size());
    }
    iterator begin() const {
        return ranges.begin();
    }
    iterator end() const {
        return ranges.end();
    }

private:
    std::map<T, T> ranges;
};
