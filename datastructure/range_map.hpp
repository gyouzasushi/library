#pragma once
#include <cassert>
#include <iterator>
#include <optional>
#include <set>
template <class T, class S>
struct range_map {
public:
    struct run {
        T l, r;
        S x;
    };

private:
    struct cmp {
        using is_transparent = void;
        bool operator()(const run& a, const run& b) const {
            return a.l < b.l;
        }
        bool operator()(const run& a, const T& b) const {
            return a.l < b;
        }
        bool operator()(const T& a, const run& b) const {
            return a < b.l;
        }
    };

public:
    using iterator = typename std::set<run, cmp>::const_iterator;
    range_map() {
    }
    // p を含む run。無ければ end()
    iterator find(T p) const {
        auto it = runs.upper_bound(p);
        if (it == runs.begin()) return runs.end();
        it--;
        if (it->r <= p) return runs.end();
        return it;
    }
    bool contains(T p) const {
        return find(p) != runs.end();
    }
    void assign(T l, T r, S x) {
        assign(l, r, x, [](T, T, const S&) {}, [](T, T, const S&) {});
    }
    // f: できた run ごとに呼ぶ, g: 消えた run ごとに呼ぶ
    template <class F, class G>
    void assign(T l, T r, S x, const F& f, const G& g) {
        assert(l < r);
        {
            auto it = find(l);
            if (it != runs.end() && r <= it->r && it->x == x) return;
        }
        T nl = l, nr = r;
        std::optional<run> left, right;
        auto first = runs.upper_bound(l);
        if (first != runs.begin()) {
            auto p = std::prev(first);
            if (l < p->r) {
                first = p;
                if (p->l < l) {
                    if (p->x == x) {
                        nl = p->l;
                    } else {
                        left = run{p->l, l, p->x};
                    }
                }
            } else if (p->r == l && p->x == x) {
                first = p;
                nl = p->l;
            }
        }
        if (first != runs.end() && first != runs.begin() && first->l == l) {
            auto p = std::prev(first);
            if (p->r == l && p->x == x) {
                first = p;
                nl = p->l;
            }
        }
        auto last = runs.lower_bound(r);
        if (last != runs.begin()) {
            auto q = std::prev(last);
            if (r < q->r) {
                if (q->x == x) {
                    nr = q->r;
                } else {
                    right = run{r, q->r, q->x};
                }
            }
        }
        if (last != runs.end() && last->l == r && last->x == x) {
            nr = last->r;
            last++;
        }
        for (auto it = first; it != last;) {
            g(it->l, it->r, it->x);
            it = runs.erase(it);
        }
        if (left) {
            runs.insert(*left);
            f(left->l, left->r, left->x);
        }
        runs.insert({nl, nr, x});
        f(nl, nr, x);
        if (right) {
            runs.insert(*right);
            f(right->l, right->r, right->x);
        }
    }
    void erase(T l, T r) {
        erase(l, r, [](T, T, const S&) {}, [](T, T, const S&) {});
    }
    template <class F, class G>
    void erase(T l, T r, const F& f, const G& g) {
        assert(l < r);
        auto it = runs.upper_bound(l);
        if (it != runs.begin() && l < std::prev(it)->r) it--;
        while (it != runs.end() && it->l < r) {
            run cur = *it;
            g(cur.l, cur.r, cur.x);
            it = runs.erase(it);
            if (cur.l < l) {
                runs.insert({cur.l, l, cur.x});
                f(cur.l, l, cur.x);
            }
            if (r < cur.r) {
                runs.insert({r, cur.r, cur.x});
                f(r, cur.r, cur.x);
            }
        }
    }
    int size() const {
        return int(runs.size());
    }
    iterator begin() const {
        return runs.begin();
    }
    iterator end() const {
        return runs.end();
    }

private:
    std::set<run, cmp> runs;
};
