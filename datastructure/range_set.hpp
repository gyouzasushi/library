#include <cassert>
#include <map>
template <typename T>
struct range_set {
public:
    range_set(bool merge_adjacent_segment = true)
        : merge_adjacent_segment(merge_adjacent_segment) {
    }
    void clear() {
        mp.clear();
    }
    size_t size() {
        return mp.size();
    }
    bool is_covered(T l, T r) {
        assert(l <= r);
        auto it = mp.upper_bound(l);
        return it != mp.begin() && std::prev(it)->first <= l &&
               r <= std::prev(it)->second;
    }
    bool is_covered(T p) {
        return is_covered(p, p);
    }
    std::pair<T, T> covered_by(T l, T r) {
        assert(l <= r);
        assert(is_covered(l, r));
        return *std::prev(mp.upper_bound(l));
    }
    std::pair<T, T> covered_by(T p) {
        return covered_by(p, p);
    }
    void insert(T l, T r) {
        assert(l <= r);
        auto it_l = mp.upper_bound(l);
        auto it_r = mp.upper_bound(r + int(merge_adjacent_segment));
        if (it_l != mp.begin()) {
            if (std::prev(it_l)->second >= l - int(merge_adjacent_segment)) {
                it_l--;
            }
        }
        for (auto it = it_l; it != it_r; it = mp.erase(it)) {
            l = std::min(l, it->first);
            r = std::max(r, it->second);
        }
        mp[l] = r;
    }
    void erase(T l, T r) {
        assert(l <= r);
        auto it_l = mp.upper_bound(l);
        auto it_r = mp.upper_bound(r);
        if (it_l != mp.begin()) {
            if (std::prev(it_l)->second >= l) {
                it_l--;
            }
        }
        int nl = std::min(l, it_l->first);
        int nr = std::max(r, std::prev(it_r)->second);
        mp.erase(it_l, it_r);
        if (nl < l) mp[nl] = l - 1;
        if (r < nr) mp[r + 1] = nr;
    }

private:
    bool merge_adjacent_segment;
    std::map<T, T> mp;
};
